"""Match `adrp` + frame + call bodies by linking them at their retail addresses.

Reuses `strlit_match.build()`'s mechanism rather than inventing one, because that
mechanism is measured at 239/239 and the only thing new here is the input shape.

The three things that mechanism contributes, all of which matter and none of which
can be done in a relocatable object:

  1. `MH.compare` normalises the `adrp` page, so the harness can compare an object
     file -- but only if Clang emitted `adrp`+`add` in the first place. Under `-fPIC`
     an `extern` global is interposable and goes through the GOT (`adrp` then
     `ldr`), and a plain local is constant-folded away. A `const` object in its own
     section is the form that survives, and that is `strlit_match`'s GLOBAL_DECL.

  2. Each body gets its own `.text.<mangled>` placement. One shared `.text` block
     puts the second body onward at the wrong address, and since an `adrp` encodes
     its target page-relative while an `add` encodes a page-relative offset, the
     result is a body whose `add` is right and whose `adrp` is wrong -- which is
     exactly the pattern seen before that fix.

  3. Sections are named after the **mangled** symbol, and placements are emitted in
     ascending address order: `ld.lld` 5.0.1 hard-crashes writing a .dmp on a
     SECTIONS script whose `. = addr` assignments go backwards.

## What is placed where

An `adrp x9, #0x2498000` names a *page*. The body then adds its own displacement
(`ldr x9, [x9, #0xb40]`), so the data it actually reaches is page+0xb40. Placing the
symbol at the page address is therefore what makes the encoded immediate correct,
and it is the only choice consistent with the instruction: the linker cannot know
what offset the body will add.

    . = 0x2498000;  .adrpg3 : { *(.adrpg3) }      <- the page the adrp encodes
    . = 0x33ff90;   .text._Z... : { *(.text._Z...) }

Order is ascending, so page 0x2498000 precedes body 0x33ff90.

    python tools/adrp_register.py --limit 40 --dry-run
    python tools/adrp_register.py --limit 100000 --write
"""

import argparse
import collections
import io
import json
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
os.environ.setdefault("POKESWORD_CLANG", r"C:\llvm-5.0.1\bin")

import call_register as CR
import match_harness as MH
import straight_line as SL

MODULES = ("main", "sdk", "subsdk0", "subsdk1")
PAGE_RE = re.compile(r"#(-?0x[0-9a-fA-F]+)")
GLOBAL_SEC = ".adrpg%d"

# `const` so it is not interposed and needs no GOT; in its own section so the
# address is not a compile-time constant and cannot be folded away; `used` so the
# reference is not the only thing keeping it alive.
GLOBAL_DECL = ('const char %s[1] __attribute__((used, section("%s"))) = {0};')


def reg_set(mod):
    p = os.path.join(ROOT, "data", "matched_%s.json" % mod)
    out = set()
    if os.path.exists(p):
        for r in json.load(io.open(p, encoding="utf-8"))["matched"]:
            out.add((r["addr"], r["size"]))
    return out


def pool(mod, md, blob, limit):
    """Bodies with a frame, an adrp and a call, and no branch or indirect call."""
    reg = reg_set(mod)
    out = []
    for addr, size, name, _d in MH.load_functions(mod):
        if (addr, size) in reg:
            continue
        code = blob[addr:addr + size]
        if len(code) < 20:
            continue
        ins = list(md.disasm(code, addr))
        f = CR.frame_of(ins)
        if f is None:
            continue
        work = ins[f[0]:len(ins) - f[1]]
        pages = [PAGE_RE.search(x.op_str).group(1) for x in work
                 if x.mnemonic in ("adrp", "adr") and PAGE_RE.search(x.op_str)]
        if not pages:
            continue
        if any(x.mnemonic in CR.BRANCH or x.mnemonic == "blr" for x in work):
            continue
        bls = [x for x in work if x.mnemonic == "bl"]
        if len(bls) != 1:
            continue
        out.append((addr, size, name, "f_%x" % addr,
                    int(bls[0].op_str.lstrip("#"), 16),
                    list(work) + [CR._ret_insn(md)], len(ins),
                    sorted({int(p, 16) for p in pages})))
        if limit and len(out) >= limit:
            break
    return out


def translate_all(items):
    """-> [(item, src, sig, pages)] for every body that translates at any prototype."""
    got = []
    for addr, size, name, ident, target, work, n_ins, pages in items:
        cname = "g_%x_%x" % (target, addr)
        nth = 0
        while True:
            v = CR.variant(work, ident, target, cname, nth)
            if v is None:
                break
            nargs, ret, src, sig = v
            got.append((addr, size, name, ident, target, src, sig,
                        n_ins, nargs, ret, pages, nth))
            nth += 1
    return got


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", action="append", default=None)
    ap.add_argument("--limit", type=int, default=100000)
    ap.add_argument("--per-module", type=int, default=60,
                    help="bodies linked per link invocation")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--quiet", action="store_true", help="suppress the per-body diff")
    ap.add_argument("--diff-nth", type=int, default=None,
                    help="print the diff only for this variant index; one link "
                         "pass per variant means the diff otherwise prints once "
                         "per variant rather than once per body")
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    md = MH._md()
    mods = a.module or list(MODULES)
    work = os.path.join(ROOT, "work", "adrpreg")
    all_rows = []
    tally = collections.Counter()

    try:
        for mod in mods:
            blob = MH.text_blob(mod)
            # The limit is applied AFTER translation, not before.
            #
            # Slicing the pool first picked bodies that translate into nothing:
            # `--limit 1` on `main` selected a body with zero candidate variants
            # and printed four lines of nothing. The number the caller cares about
            # is bodies *tested*, so that is what the limit counts.
            items = pool(mod, md, blob, 0)
            print("  %-9s %5d adrp body(s)" % (mod, len(items)))
            if not items:
                continue
            cands = translate_all(items)
            if a.limit and items:
                keep = sorted({c[3] for c in cands})[:a.limit]
                kset = set(keep)
                cands = [c for c in cands if c[3] in kset]
                items = [i for i in items if i[3] in kset]
            print("  %-9s %5d candidate variant(s) from %d that translate"
                  % (mod, len(cands), len({c[3] for c in cands})))
            sys.stdout.flush()
            if not cands:
                continue

            # Group by body; only the first body of a group can be the winner.
            # Group by VARIANT INDEX: one link pass per index, each covering
            # every body that has a candidate at that index.
            #
            # All of a body's variants must be placed at that body's own retail
            # address -- an `adrp` encodes its target page-relative, so a body
            # compared anywhere else emits the wrong immediate. That also means
            # only one variant can occupy the address, so putting all sixteen in
            # one link let the linker keep variant 0 (`nargs=0`) and leave the
            # rest unreachable. Every body then reported "differs" with its
            # argument setup deleted, which reads like a translator defect.
            by_nth = collections.defaultdict(list)
            for c in cands:
                by_nth[c[11]].append(c)
            byident = collections.OrderedDict()
            for nth_i in sorted(by_nth):
                for c in by_nth[nth_i]:
                    byident["%s#%d" % (c[3], nth_i)] = [c]

            done = set()
            for base in range(0, len(byident), a.per_module):
                group = list(byident.items())[base:base + a.per_module]
                parts = []
                placements = []
                # Stubs are per (callee, body) and several variants of one body
                # share a callee, so they must be emitted once per link group.
                stubs = set()
                # One declaration and one placement per DISTINCT page in the group.
                #
                # 52 of the sdk bodies share page 0x27ee000, so declaring per body
                # defines `adrp_27ee000` repeatedly in one translation unit and the
                # whole group fails to compile -- one duplicate taking down the
                # other 19 with it. Pages are deduped across the group and the
                # section index is recorded, so the registered source can name the
                # same section it was compiled against.
                page_sec = {}
                for ident, lst in group:
                    for pg in lst[0][10]:
                        if pg not in page_sec:
                            sec = GLOBAL_SEC % len(page_sec)
                            page_sec[pg] = sec
                            parts.append(GLOBAL_DECL % ("adrp_%x" % pg, sec))
                            placements.append((pg, sec, "*(%s)" % sec))
                    c = lst[0]
                    addr, size, name, _id, target, src, sig, n_ins, nargs, ret, \
                        pages, nth = c
                    if (target, addr) not in stubs:
                        stubs.add((target, addr))
                        parts.append(
                            "extern void g_%x_%x();" % (target, addr))
                    # A definition, because this path actually links.
                    # `call_register` never links, so an undefined callee was
                    # harmless there; `ld.lld` refuses. The stub's body and address
                    # do not matter -- `MH.compare` normalises branch targets to
                    # `<target>` -- but it must not be inlined, or Clang sees an
                    # empty function and deletes the `bl` along with the argument
                    # setup that the comparison is there to check.
                        parts.append(
                            "void g_%x_%x() __attribute__((noinline));"
                            % (target, addr))
                        parts.append(
                            "void g_%x_%x() { __asm__ volatile(\"\"); }"
                            % (target, addr))
                    # EVERY variant gets its own function and its own placement.
                    #
                    # Emitting only variant 0 and then "trying" the rest compares
                    # the same bytes sixteen times: every variant shares one ident,
                    # so `_at` finds one symbol and returns the same image for all
                    # of them. The prototype search looked like it was running and
                    # was not -- which is how fourteen bodies came out as
                    # "linked but differs" with no variant of any of them tried.
                    for v in lst:
                        vaddr, vsize, vname, vident, vtgt, vsrc, vsig, vn, \
                            vnargs, vret, vpages, vnth = v
                        # The candidate's own ident. NOT the group key: the key
                        # carries a "#<index>" suffix for dictionary uniqueness
                        # and "#" is not valid in a C identifier, which made every
                        # candidate a syntax error.
                        vid = "%s_v%d" % (vident, vnth)
                        vsrc2 = vsrc.replace(vident, vid)
                        parts.append(vsrc2)
                        placements.append(
                            (vaddr, ".text.%s" % MH.mangle(vid, vsig),
                             "*(.text.%s)" % MH.mangle(vid, vsig)))

                shutil.rmtree(work, ignore_errors=True)
                os.makedirs(work)
                srcp = os.path.join(work, "u.cpp")
                io.open(srcp, "w", encoding="utf-8").write(
                    MH.PREAMBLE + "\n".join(parts) + "\n")
                obj = os.path.join(work, "batch.o")
                r = subprocess.run(
                    [MH.tool("clang++")] + MH.CFLAGS + ["-c", srcp, "-o", obj],
                    capture_output=True, text=True)
                if r.returncode:
                    tally["compile failed"] += len(group)
                    continue
                placements.sort(key=lambda t: t[0])
                lines = ["SECTIONS {"]
                for addr, sec, pat in placements:
                    lines.append("  . = 0x%x;" % addr)
                    lines.append("  %s : { %s }" % (sec, pat))
                lines.append("}")
                script = os.path.join(work, "link.ld")
                io.open(script, "w", encoding="utf-8").write(
                    "\n".join(lines) + "\n")
                elf = os.path.join(work, "linked.elf")
                r = subprocess.run([MH.tool("ld.lld"), "-T", script, obj,
                                    "-o", elf], capture_output=True, text=True)
                if r.returncode:
                    first = tally["link failed"] == 0
                    tally["link failed"] += len(group)
                    if first:
                        print("  first link error: %s" % r.stderr.strip()[:700])
                if not os.path.exists(elf):
                    continue
                linked = io.open(elf, "rb").read()
                blobm = blob
                for ident, lst in group:
                    c = lst[0]
                    addr, size, name, _id, target, src, sig, n_ins, nargs, ret, \
                        pages, nth = c
                    code = _at(linked, "%s_v%d" % (c[3], c[11]), sig, size)
                    if not code:
                        tally["no bytes at the placed address"] += 1
                        continue
                    want = blobm[addr:addr + size]
                    w = list(md.disasm(want, addr))
                    end = MH.effective_end(w, size)
                    hit = False
                    for c2 in lst:
                        code2 = _at(linked, "%s_v%d" % (c2[3], c2[11]), c2[6], size)
                        if not code2:
                            continue
                        v, _ = MH.compare(w, end, list(md.disasm(code2, 0)))
                        if v == "match":
                            hit = True
                            c = c2
                            break
                    if not hit:
                        tally["linked but differs"] += 1
                        best2, code3, bestlen = None, b"", -1
                        for c3 in lst:
                            t3 = _at(linked, "%s_v%d" % (c3[3], c3[11]),
                                     c3[6], size)
                            if len(t3) > bestlen:
                                best2, code3, bestlen = c3, t3, len(t3)
                        if not a.quiet and best2 is not None and (
                                a.diff_nth is None or best2[11] == a.diff_nth):
                            # Report the LONGEST emission, not lst[0]: that is
                            # `nargs=0`, where Clang deletes the setup for
                            # arguments it is not forwarding and so removes the
                            # whole adrp chain. The diff would then show a body
                            # with everything stripped out and say nothing about
                            # the prototypes that do forward. The widest variant
                            # is the one carrying the setup under test.
                            want3 = blobm[addr:addr + size]
                            print("  --- %s@%#x nargs=%s ret=%s ---"
                                  % (name, addr, best2[8], best2[9]))
                            print("    --- generated source ---")
                            for ln in best2[5].rstrip().splitlines():
                                print("      S %s" % ln)
                            print("    retail (%d bytes): %s"
                                  % (len(want3), want3.hex()))
                            print("    ours   (%d bytes): %s"
                                  % (len(code3), code3.hex()))
                            for i in md.disasm(want3, addr):
                                print("      R %-8s %s" % (i.mnemonic, i.op_str))
                            for i in md.disasm(code3, addr):
                                print("      O %-8s %s" % (i.mnemonic, i.op_str))
                        continue
                    addr2, size2, name2, _id2, target2, src2, sig2, n_ins2, \
                        nargs2, ret2, pages2, nth2 = c
                    alias = "g_%x_%x" % (target2, addr2)
                    body = src2.replace(alias, "callee_%x" % target2)
                    glob = "\n".join(
                        GLOBAL_DECL % ("adrp_%x" % pg, page_sec[pg])
                        for pg in pages2)
                    all_rows.append({
                        "module": mod, "addr": addr2, "size": size2,
                        "name": name2, "shape": "adrp-call",
                        "ident": "adrp_%x" % addr2, "sig": sig2,
                        "callee": "callee_%x" % target2,
                        "callee_synthetic": True,
                        "call_args": nargs2, "call_ret": ret2,
                        "adrp_pages": pages2,
                        "orig_insns": n_ins2, "new_insns": size2 // 4,
                        "src": glob + "\nextern void callee_%x();\n%s"
                               % (target2, body),
                    })
                    tally["MATCH"] += 1
                    print("  match %s@%#x nargs=%d ret=%s pages=%s"
                          % (name2, addr2, nargs2, ret2,
                             ["%#x" % p for p in pages2]))
                    sys.stdout.flush()
                sys.stdout.flush()
    finally:
        shutil.rmtree(work, ignore_errors=True)

    print()
    print("=== totals ===")
    for k, v in tally.most_common():
        print("  %-38s %5d" % (k, v))
    print("  %-38s %5d" % ("verified matches", len(all_rows)))

    if a.write and all_rows:
        for mod in mods:
            rows = [r for r in all_rows if r["module"] == mod]
            if not rows:
                continue
            path = os.path.join(ROOT, "data", "matched_%s.json" % mod)
            data = json.load(io.open(path, encoding="utf-8"))
            have = {(x["addr"], x["size"]) for x in data["matched"]}
            added = 0
            for r in rows:
                if (r["addr"], r["size"]) in have:
                    continue
                data["matched"].append(r)
                added += 1
            io.open(path, "w", encoding="utf-8", newline="").write(
                json.dumps(data, indent=1, sort_keys=True))
            print("  %-9s registry +%d" % (mod, added))
    elif all_rows:
        print("  (dry run -- pass --write to register)")
    return 0


def _at(linked, ident, sig, size):
    """Bytes of one placed function from the linked image.

    Through the ELF **symbol table**, not `image[addr:addr+size]`.

    A linked image is an ELF: the retail address is a *virtual* address, and
    virtual address != file offset. Slicing the file at the virtual address reads
    whatever happens to live there -- the program headers, or nothing -- so every
    body "differs" and nothing is learnable from the comparison. `strlit_match`
    has the same constraint and extracts by symbol for exactly this reason.

    `strlit_match`'s helper mangles with "v"; here the real signature is known, so
    the exact mangled name is tried first and the fuzzy `[ident in name]` match is
    the fallback.
    """
    tmp = os.path.join(ROOT, "work", "_adrpreg_linked.elf")
    os.makedirs(os.path.dirname(tmp), exist_ok=True)
    io.open(tmp, "wb").write(linked)
    try:
        syms = MH.obj_symbols(tmp)
        exact = MH.mangle(ident, sig)
        for n in [exact] + sorted(x for x in syms if ident in x):
            if n in syms:
                got = MH.obj_text_range(tmp, syms, [n]).get(n, b"")
                if got:
                    return got
        return b""
    finally:
        try:
            os.remove(tmp)
        except OSError:
            pass


if __name__ == "__main__":
    sys.exit(main())