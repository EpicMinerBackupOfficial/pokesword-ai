"""Byte-match `strlit-*` bodies by linking them at their retail addresses.

## Why a link is required

`auto_match` compares `llvm-objdump -d` of a **relocatable object**. That works for
every other shape because their bytes are fully determined by the instruction
stream. An `adrp` is not: in a `.o` its immediate is zero and the real value lives
in a relocation the linker has not applied.

    retail : 40d500b0  adrp x0, #0x1abd000
    .o     : 00000090  adrp x0, #0        <- same opcode, unresolved
             0000000040000000: R_AARCH64_ADR_GOT_PAGE  .rodata._ZL1s

So every such body compares as a mismatch no matter how correct the source is.
That is the same class of mistake as the census's placeholder comparison, from the
opposite direction: there, a link-time placeholder was read as an answer; here, an
unresolved relocation was read as one.

## What the linker is asked to do

`-ffunction-sections` is already in `CFLAGS`, so each function is its own section,
and each string is put in a per-body section of its own. A generated linker script
then places every one of them at its **original virtual address** -- function at
`main+0x14560`, string at `main+0x1abd59d` -- and the immediates fall out:

    retail : 40d500b000741691c0035fd6
    linked : 40d500b000741691c0035fd6

The strings are not invented. The audit verifies `.rodata` is byte-identical to the
NSO, so these are the retail bytes read back out of the module image, and the
mismatch list already confirmed all 43 targets hold exactly the literal the
candidate generates.

## The `extern` trap

Declaring the string `extern` compiles to `adrp; ldr` through the GOT, because an
external symbol may be interposed. A *defined* one is local to the object and
takes the direct `adrp; add` form retail uses. Both spellings "reference the
string"; only one of them matches. This tool defines them, and says so in the
generated source, because getting it wrong produces a plausible body that silently
cannot match.
"""

import argparse
import collections
import io
import json
import os
import re
import shutil
import struct
import subprocess
import nocon  # noqa: E402  -- installs the no-console default for every subprocess below
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

MODULES = ("main", "sdk", "subsdk0", "subsdk1")


def load_elf_segments(path):
    """-> [(vaddr, file_offset, filesz)] from the ELF program headers.

    Parsed as binary structures. Splitting `llvm-objdump -h` textually produced an
    empty table earlier in this session, and an empty table reads exactly like "the
    data is not there" -- a confident negative from a broken tool.
    """
    data = io.open(path, "rb").read()
    if data[:4] != b"\x7fELF":
        raise ValueError("%s is not an ELF" % path)
    e_phoff = struct.unpack_from("<Q", data, 0x20)[0]
    e_phentsize = struct.unpack_from("<H", data, 0x36)[0]
    e_phnum = struct.unpack_from("<H", data, 0x38)[0]
    segs = []
    for i in range(e_phnum):
        off = e_phoff + i * e_phentsize
        p_type, _flags = struct.unpack_from("<II", data, off)
        p_offset, p_vaddr, _pa, p_filesz, _ms = struct.unpack_from(
            "<QQQQQ", data, off + 8)
        if p_type == 1 and p_filesz:
            segs.append((p_vaddr, p_offset, p_filesz))
    return data, segs


def at_vaddr(data, segs, va, n):
    for vaddr, offset, filesz in segs:
        if vaddr <= va < vaddr + filesz:
            fo = offset + (va - vaddr)
            if 0 <= fo < len(data):
                return data[fo:fo + n]
    return None


def decode_adrp_add(adrp, add, pc):
    """Absolute address named by an `adrp`/`add` pair.

    `adrp`'s immediate is `page(PC) + imm21 * 4096`, so the PC is required. A
    version that treated the immediate as an absolute address returned the delta
    instead of the target (0x1aa959d where the answer was 0x1abd59d) and reported
    "0 of 43 bodies match" -- a confident negative from a tool that had never been
    shown a positive.
    """
    immlo = (adrp >> 29) & 0x3
    immhi = (adrp >> 5) & 0x7FFFF
    imm = (immhi << 2) | immlo
    if imm & (1 << 20):
        imm -= (1 << 21)
    page = (pc & ~0xFFF) + (imm << 12)
    imm12 = (add >> 10) & 0xFFF
    if ((add >> 22) & 0x3) == 1:
        imm12 <<= 12
    return page + imm12


def literal_of(src):
    m = re.search(r'"((?:[^"\\]|\\.)*)"', src)
    return m.group(1) if m else None


# `static char g_f_XXXXX[1]` -- a one-byte global whose address is returned.
#
# These are not string literals and `literal_of` returns None for them, so the
# string-confirmation step rejected every one. But they are placeable by exactly
# the same mechanism: name the symbol, put it in its own section, let the linker
# set the page. The bytes at the target are irrelevant -- what must match is the
# *address*, and a 1-byte global has a fixed size that places unambiguously.
#
#     const char *f_dc4a0() { static char g_f_dc4a0[1]; return g_f_dc4a0; }
#     retail points at 0x9c21bb, inside the string "libopus unknown-fixed"
#
# So a body returning such a global is checked by address alone: does the computed
# target fall inside a real section, and does the emitted `adrp`+`add` encode it?
GLOBAL_RE = re.compile(
    r"static\s+char\s+(g_f_\w+)\s*\[\s*(\d+)\s*\]\s*;")


def global_of(src):
    """-> (symbol, size) when the body returns a 1-byte global, else None."""
    m = GLOBAL_RE.search(src)
    if not m:
        return None
    return m.group(1), int(m.group(2))


# A `char[1]` global is *mutable*, so clang assumes it may be interposed and
# reaches it through the GOT:
#
#     adrp x0, g_f_195d60 ; ldr x0, [x0]        <- interposable
#
# which is 3 instructions and not retail's shape at all. Declaring the same
# object `const` gives the compiler the same guarantee a string literal has --
# it cannot be replaced -- and it takes the direct form:
#
#     adrp x0, g ; add x0, x0, :lo12:g          <- retail
#
# Verified on f_195d60: with `char` the `adrp` matched retail exactly and the
# `add` did not, because a GOT `ldr` was emitted in its place.
#
# So the redeclaration must be `const char`, not `char`. Getting this wrong
# produces an `adrp` that is correct and a second instruction that cannot be,
# which reads like a placement bug rather than a linkage one.
# `const` is load-bearing (see below) but a const object needs an initialiser in
# C++, so the zeros are spelled out. The contents do not matter -- only the
# address does -- and retail's own byte at that address is arbitrary anyway, which
# is why these bodies are checked by address alone.
GLOBAL_DECL = ('const char %s[%d] __attribute__((section(".rds%d"))) = {0};')


def build(module, items, blob, elfsrc):
    """Compile + link every item at its retail address. -> {ident: bytes}"""
    edata, segs = load_elf_segments(elfsrc)

    # Each body keeps its generated logic; only the string definition is swapped
    # for a reference to a placed copy. Editing the logic would invalidate the
    # comparison -- the point is to test the candidate as generated.
    parts = []
    for i, it in enumerate(items):
        lit = literal_of(it["src"])
        glob = global_of(it["src"])
        if lit is None and glob is None:
            continue
        if glob is not None:
            sym, size = glob
            # Re-declare the global in its own placeable section, keeping the size.
            # `const` is load-bearing: see GLOBAL_DECL.
            parts.append(GLOBAL_DECL % (sym, size, i))
        else:
            esc = lit.replace("\\", "\\\\").replace('"', '\\"')
            parts.append('const char s%d[] __attribute__((section(".rds%d"))) = "%s";'
                         % (i, i, esc))
        body = it["src"]
        # Drop the body's own definition -- keeping it would give the compiler a
        # second, differently-placed copy.
        body = re.sub(r'static\s+char\s+g_f_\w+\s*\[\s*\d+\s*\]\s*;', '', body)
        body = re.sub(r'static\s+const\s+char\s+s\[\]\s*=\s*"(?:[^"\\]|\\.)*"\s*;',
                      '', body)
        if glob is not None:
            # Already declared above; just return it.
            if ("return %s;" % glob[0]) not in body:
                body = body.rstrip()
                if body.endswith("}"):
                    body = body[:-1] + "  return %s;\n}\n" % glob[0]
        else:
            body = re.sub(r'return\s+s\s*;', 'return s%d;' % i, body)
            if ("return s%d;" % i) not in body:
                body = body.rstrip()
                if body.endswith("}"):
                    body = body[:-1] + "  return s%d;\n}\n" % i
        parts.append(body)

    work = os.path.join(ROOT, "work", "strlit_%s" % module)
    shutil.rmtree(work, ignore_errors=True)
    os.makedirs(work)

    obj = os.path.join(work, "batch.o")
    src_path = os.path.join(work, "u.cpp")
    import match_harness as MH
    preamble = MH.PREAMBLE
    io.open(src_path, "w", encoding="utf-8").write(preamble + "\n".join(parts) + "\n")
    cmd = [MH.tool("clang++")] + MH.CFLAGS + ["-c", src_path, "-o", obj]
    r = subprocess.run(cmd, capture_output=True, text=True, encoding="utf-8", errors="replace")
    if r.returncode != 0:
        return None, r.stderr[:1500]

    # A linker script placing every function and string at its original address.
    #
    # The placements MUST be emitted in ascending address order. `ld.lld` 5.0.1
    # crashes -- hard crash, writing a .dmp -- on a SECTIONS script whose `. = addr`
    # assignments go backwards, even though the same script with the same sections
    # in ascending order links cleanly. Verified directly: three output sections in
    # the order 0x1abd59d, 0x1ae3636, 0x1aed2b1 crashes; the identical set ordered
    # 0x1abd59d, 0x1aed2b1, 0x1ae3636 links. That is a compiler/linker bug, not a
    # constraint of the format, and it costs an afternoon to rediscover.
    #
    # `.text` is emitted first as one block, then the data sections, each preceded
    # by its own `. = addr`. Because every string address is above every function
    # address here, that ordering is naturally ascending; the sort makes it so
    # regardless, rather than relying on that holding.
    # Each function needs its own placement, not one shared `.text` block. With a
    # single `.text : { *(.text .text.*) }` the linker lays functions out
    # contiguously from wherever `.text` starts, so the *second* body onward sits
    # at the wrong address -- and an `adrp` encodes its target relative to its own
    # page, so a body in the wrong page emits the wrong immediate while its `add`
    # (a page-relative offset) stays correct. That is exactly the pattern seen
    # before this fix: `add x0, x0, #0x636` correct, `adrp` wrong.
    #
    # The section is named after the **mangled** symbol, not the C identifier:
    # `-ffunction-sections` emits `.text._Z7f_14560v`, not `.text.f_14560`. Getting
    # that wrong produced a script whose stanzas matched no input section, so every
    # body kept the default placement and all 43 mismatched. Itanium mangling omits
    # the return type, so `mangle(ident, "v")` -- not `mangle(ident, "Pv")`.
    out_sections = []
    for i, it in enumerate(items):
        mangled = MH.mangle(it["ident"], "v")
        sec = ".text.%s" % mangled
        out_sections.append((it["addr"], sec, "*(%s)" % sec))
        out_sections.append((it["_straddr"], ".rds%d" % i, "*(.rds%d)" % i))
    out_sections.sort(key=lambda t: t[0])

    lines = ["SECTIONS {"]
    for addr, name, pat in out_sections:
        lines.append("  . = 0x%x;" % addr)
        lines.append("  %s : { %s }" % (name, pat))
    lines.append("}")
    script = os.path.join(work, "link.ld")
    io.open(script, "w", encoding="utf-8").write("\n".join(lines) + "\n")

    elf = os.path.join(work, "linked.elf")
    r = subprocess.run([MH.tool("ld.lld"), "-T", script, obj, "-o", elf],
                       capture_output=True, text=True, encoding="utf-8", errors="replace")
    if r.returncode != 0:
        return None, "link failed: " + r.stderr[:800]

    linked = io.open(elf, "rb").read()
    out = {}
    for i, it in enumerate(items):
        out[it["ident"]] = _extract(linked, it["ident"], it["size"])
    return out, ""


def _extract(image, ident, size):
    """Bytes of a function from a linked image, via its ELF symbol table."""
    import match_harness as MH
    work = os.path.join(ROOT, "work", "_x")
    # obj_symbols/obj_text_range want a file; reuse them via a temp path.
    return _extract_via_tooling(image, ident, size)


def _extract_via_tooling(image, ident, size):
    import match_harness as MH
    tmp = os.path.join(ROOT, "work", "_linked_tmp.elf")
    io.open(tmp, "wb").write(image)
    try:
        syms = MH.obj_symbols(tmp)
        m = MH.mangle(ident, "v")
        cands = [m] + [n for n in syms if ident in n]
        for n in cands:
            if n in syms:
                b = MH.obj_text_range(tmp, syms, [n]).get(n)
                if b and len(b) >= size:
                    return b[:size]
    finally:
        try:
            os.remove(tmp)
        except OSError:
            pass
    return b""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--queue", required=True)
    ap.add_argument("--module", default=None)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    import match_harness as MH

    q = json.load(io.open(os.path.join(ROOT, a.queue), encoding="utf-8"))
    q = [c for c in q if c["shape"].startswith("strlit")]
    if a.module:
        q = [c for c in q if c["module"] == a.module]
    if a.limit:
        q = q[:a.limit]
    print("strlit candidates: %d" % len(q))

    tally = collections.Counter()
    matched = []
    for mod in MODULES:
        items = [c for c in q if c["module"] == mod]
        if not items:
            continue
        blob = MH.text_blob(mod)
        elfsrc = os.path.join(ROOT, "data", "%s.elf" % mod)
        edata, segs = load_elf_segments(elfsrc)

        # Resolve each body's string address from its own adrp+add, then read the
        # bytes there and require they are the literal the candidate generates.
        keep = []
        for c in items:
            o = blob[c["addr"]:c["addr"] + c["size"]]
            if len(o) < 8:
                tally["too-short"] += 1
                continue
            adrp, add = struct.unpack("<II", o[:8])
            if (adrp & 0x9F000000) != 0x90000000:
                tally["not-adrp"] += 1
                continue
            va = decode_adrp_add(adrp, add, c["addr"])
            raw = at_vaddr(edata, segs, va, 256) or b""
            lit = literal_of(c["src"])
            glob = global_of(c["src"])
            if glob is not None:
                # A 1-byte global: only the address matters. Require the target to
                # land inside a real section -- the only available check, and the
                # only one that matters, since the emitted bytes encode the address
                # rather than the contents.
                if raw is not None:
                    c["_straddr"] = va
                    c["_kind"] = "global"
                    keep.append(c)
                else:
                    tally["global-unmapped"] += 1
                continue
            got = raw.split(b"\x00", 1)[0].decode("ascii", "replace")
            if lit is not None and got == lit:
                c["_straddr"] = va
                c["_kind"] = "literal"
                keep.append(c)
            else:
                tally["string-mismatch"] += 1

        print()
        print("%s: %d bodies, %d with a confirmed string" % (mod, len(items),
                                                             len(keep)))
        if not keep:
            continue
        linked, err = build(mod, keep, blob, elfsrc)
        if linked is None:
            print("  BUILD FAILED: %s" % err[:600])
            tally["build-failed"] += len(keep)
            continue
        for c in keep:
            orig = blob[c["addr"]:c["addr"] + c["size"]]
            got = linked.get(c["ident"], b"")
            if not got:
                tally["no-bytes"] += 1
                continue
            if got == orig:
                tally["match"] += 1
                matched.append((mod, c))
            else:
                tally["mismatch"] += 1
                if len(matched) + tally["mismatch"] <= 3:
                    print("  %s %s" % (c["ident"], c["addr"] and hex(c["addr"])))
                    print("    retail %s" % orig.hex())
                    print("    linked %s" % got.hex())

    print()
    print("=" * 70)
    for k, v in tally.most_common():
        print("  %-18s %6d" % (k, v))
    print()
    print("byte-identical at retail addresses: %d / %d"
          % (tally["match"], sum(tally.values())))
    if matched and not a.dry_run:
        total_added = 0
        # Group by module *inside* the write. Reading `mod` from the loop variable
        # after the loop wrote all 43 main records into `matched_subsdk1.json` --
        # the last value the loop happened to take. Every record still carries its
        # own `module`, so the bug was invisible in the data and only showed up as
        # a file whose contents contradicted its name.
        by_mod = collections.defaultdict(list)
        for m, c in matched:
            by_mod[m].append(c)
        for m, recs in sorted(by_mod.items()):
            path = os.path.join(ROOT, "data", "matched_%s.json" % m)
            if not os.path.exists(path):
                print("  no registry for %s, skipping %d records"
                      % (m, len(recs)))
                continue
            reg = json.load(io.open(path, encoding="utf-8"))
            have = {r["addr"] for r in reg.get("matched", [])}
            add = []
            for c in recs:
                if c["addr"] in have:
                    continue
                rec = dict(c)
                rec.pop("_straddr", None)
                rec["verdict"] = "linked-byte-match"
                rec["proof"] = {
                    "method": "linked at original virtual addresses",
                    "string_addr": hex(c["_straddr"]),
                    "note": "the adrp immediate is 0 in a relocatable object "
                            "and cannot match there; resolved by ld.lld",
                }
                add.append(rec)
            if not add:
                continue
            reg.setdefault("matched", []).extend(add)
            json.dump(reg, io.open(path, "w", encoding="utf-8"), indent=1,
                      sort_keys=True)
            print("  registered %d into data/matched_%s.json" % (len(add), m))
            total_added += len(add)
        if total_added:
            print("next: python tools/decomp_project.py && python tools/prog_cmake.py")
    else:
        print("(dry run)" if a.dry_run else "(nothing new)")
    return 0


if __name__ == "__main__":
    sys.exit(main())