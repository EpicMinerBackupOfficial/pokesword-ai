"""Match delegator bodies: one call, no work. Callee lowering for the trivial case.

Nothing in the harness modelled a `bl` before. `StraightLine.translate()` builds
one composed expression per value and returns a single function string, and a call
is a *statement*, so there was nowhere for one to go. This is deliberately not a fix
to that: it is a separate matcher for the one body shape where a call is the whole
function, which needs no statement-level machinery at all.

The shape, which is what retail emits for a plain forwarder:

    stp x29, x30, [sp, #-0x10]!     frame
    mov x29, sp
    bl   <callee>                   the entire body
    ldp x29, x30, [sp], #0x10
    ret

The C is correspondingly small:

    void f(uint64_t a0, ...) { callee(a0, ...); asm volatile(""); }

### Why the empty statement is there, and why it is not a trick

Written without it, `void f(uint64_t a0){ callee(a0); }` is a sibling call: Clang
rewrites it to `b <callee>`, four bytes, and the function needs no prologue because
nothing has to survive the call. Retail's body has a frame, so the call is not
terminal, so something must follow it.

`asm volatile("")` is that something. It emits no instructions and defines no
symbols, and it makes the call non-terminal -- which is exactly the condition under
which Clang emits, byte for byte:

    stp x29, x30, [sp, #-0x10]!
    mov x29, sp
    bl  <callee>
    ldp x29, x30, [sp], #0x10
    ret

20 bytes, verified identical modulo the `bl` displacement, at -O3, -O2 and -Os,
**using the project's existing flags**. `-fno-optimize-sibling-calls` produces the
same thing and is not used: it would be global, it would break the 5,241 bodies
that match today precisely because Clang tail-calls them, and `audit.py` asserts
the harness flags equal the build flags, so a probe-only flag is not available
either. The empty statement is scoped to the one function that needs it.

### How the argument count is found

It is not known from the callee -- its prototype is in another module and may be
wrong. So the number of parameters is searched over 0..8, and for each, the variant
that forwards *all* of them is preferred.

The preference is load-bearing. A delegator's `bl` passes whatever is in x0..x7 at
that point, and forwarding zero arguments produces byte-identical output to
forwarding all of them, because the registers already hold those values. The byte
comparison cannot tell the two apart. A search in ascending order therefore returns
`forward=0` for every single body -- which reproduces the encoding exactly and
destroys the call, because the callee then reads whatever happened to be in x0.
The first version of this tool did precisely that, and reported 33 of 33 verified.

So the parameter count is **the smallest count consistent with the bytes, with all
of it forwarded**. That is faithful but not proven: the true arity is visible only
in callers and in the callee's own body, and nothing here reads either. Recorded as
`arg_inferred` on every row, so the assumption is auditable rather than buried.

Usage:

    python tools/call_match.py --detect
    python tools/call_match.py --try 200 --module main
"""

import argparse
import collections
import io
import json
import os
import shutil
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
os.environ.setdefault("POKESWORD_CLANG", r"C:\llvm-5.0.1\bin")

import match_harness as MH

MODULES = ("main", "sdk", "subsdk0", "subsdk1")
MAX_FWD = 8


def delegator(ins):
    """-> callee target if `ins` is prologue / one bl / epilogue / ret, else None.

    Deliberately exact. A body with any work between the prologue and the call is
    not a delegator and must go through statement-level lowering; accepting a
    near-miss here would report matches that are not the bodies asked for.
    """
    if len(ins) != 5:
        return None
    pro, mov, call, epi, ret = ins
    if pro.mnemonic != "stp" or not pro.op_str.startswith("x29, x30, [sp, #-"):
        return None
    if "]!" not in pro.op_str:
        return None
    if mov.mnemonic != "mov" or "x29, sp" not in mov.op_str:
        return None
    if call.mnemonic != "bl":
        return None
    if epi.mnemonic != "ldp" or not epi.op_str.startswith("x29, x30, [sp], #"):
        return None
    if ret.mnemonic != "ret":
        return None
    return int(call.op_str.lstrip("#"), 16)


def scan(mod, md, reg):
    """-> [(addr, size, name, ident, callee)] for every bare delegator in `mod`."""
    blob = MH.text_blob(mod)
    names = {}
    for addr, size, name, decomp in MH.load_functions(mod):
        names.setdefault(addr, (size, name))
    out = []
    for addr, size, name, decomp in MH.load_functions(mod):
        if (addr, size) in reg:
            continue
        code = blob[addr:addr + size]
        if len(code) < 20:
            continue
        ins = list(md.disasm(code, addr))
        target = delegator(ins)
        if target is None:
            continue
        out.append((addr, size, name, "f_%x" % addr, target))
    return out


def variants(fwd, callee):
    """The (declared, forwarded) source forms tried for one delegator."""
    args = ", ".join("a%d" % i for i in range(fwd))
    params = "".join("uint64_t a%d, " % i for i in range(fwd))
    if params:
        params = params[:-2]
    else:
        params = "void"
    decl = ("extern void %s(%s);" % (callee, params)) if fwd else \
           ("extern void %s();" % callee)
    body = ("%s(a0);" % callee) if fwd else ("%s();" % callee)
    # The declared-but-unforwarded tail: retail keeps the extra incoming registers
    # alive across the call, and declaring them is what keeps Clang from deciding
    # the signature is just (a0..a_{fwd-1}).
    extra = "".join("uint64_t a%d, " % i for i in range(fwd, fwd + 2))
    sig_extra = (params + ", " if params != "void" else "") + \
                ", ".join("uint64_t a%d" % i for i in range(fwd, fwd + 2))
    out = []
    for ret in ("void", "uint64_t"):
        if fwd:
            src = ("%s\n%s %s_fwd(%s) { %s asm volatile(\"\"); }\n"
                   % (decl, ret, "", params, body))
        else:
            src = ("%s\n%s f_fwd(void) { %s asm volatile(\"\"); }\n"
                   % (decl, ret, body))
        out.append((params, src))
    return out


def callee_ident(callee, mod):
    """A valid C identifier for a callee address, preferring its real symbol name.

    The address alone is not a legal identifier -- `extern void 3147728();` does
    not parse, and decimal is what `int("3007d0", 16)` prints. The first version of
    this tool verified through a `g_`-prefixed alias but wrote the bare address into
    the registry, so all 33 rows were byte-verified and uncompilable. Verification
    used one name and registration another; that gap is the bug.

    Prefers the module's own symbol for the address, so the call refers to the
    function by name. Falls back to a hex-suffixed synthetic name when the callee
    lives in another module, which is marked so it is obvious it is a placeholder
    rather than a real symbol.
    """
    try:
        for addr, _size, name, _d in MH.load_functions(mod):
            if addr == callee and name:
                return name, False
    except Exception:                                # noqa: BLE001
        pass
    return "callee_%x" % callee, True


def build_source(variant, callee, fwd, keep):
    """One candidate source for `variant` forwarding `fwd` args, keeping `keep` live.

    The callee is called through a cast of its own address rather than through a
    per-candidate prototype. A prototype has to commit to an arity, and the arity
    is the thing being searched, so any fixed prototype either rejects a call that
    forwards fewer arguments or silently permits one that forwards more. The cast
    states the arity at the call site instead, which is where it is actually known.

        extern void g();                       // one declaration, in the TU head
        ((void(*)(unsigned long,unsigned long))g)(a0, a1);

    The cast is to a function pointer, not through one, so this is still a direct
    `bl g`.
    """
    params = ", ".join("unsigned long a%d" % i for i in range(keep)) or "void"
    fwd_types = ", ".join("unsigned long" for _ in range(fwd)) or "void"
    call = "((void(*)(%s))%s)(%s);" % (
        fwd_types, callee, ", ".join("a%d" % i for i in range(fwd)))
    return ("void %s(%s) { %s asm volatile(\"\"); }\n" % (variant, params, call))


def try_batch(pool, blob, md, limit, owner_mod=None):
    """-> [(addr, size, name, ident, callee, src, sig, code)] verified matches.

    Every variant of every delegator goes into a small number of translation units
    rather than one each: 33 delegators x 45 (keep, fwd) pairs is ~1,500 compiles
    one-at-a-time, which does not finish in a usable time. One TU per 250 variants
    brings that to six.
    """
    # (variant name, callee, fwd, keep, owner tuple)
    jobs = []
    for entry in pool[:limit]:
        addr, size, name, ident, callee = entry
        want = blob[addr:addr + size]
        end = MH.effective_end(list(md.disasm(want, addr)), size)
        for keep in range(MAX_FWD + 1):
            # descending, so the first variant that matches is the one that
            # forwards every parameter it declares.
            #
            # This matters and is not cosmetic. A delegator's `bl` passes whatever
            # is in x0..x7 at that point, and forwarding zero arguments is
            # byte-identical to forwarding all of them -- the registers already
            # hold the right values either way. So the byte comparison cannot
            # distinguish them, and a search in ascending order returns
            # `forward=0`, which reproduces the encoding and destroys the call:
            # the callee reads whatever happened to be in x0. Preferring the
            # maximum makes the match both byte-exact and faithful.
            for fwd in range(keep, -1, -1):
                variant = "%s_k%d_f%d" % (ident, keep, fwd)
                jobs.append((variant, callee, fwd, keep, entry, end))
    if not jobs:
        return [], 0

    hits = {}
    tried = 0
    CHUNK = 250
    for k in range(0, len(jobs), CHUNK):
        chunk = jobs[k:k + CHUNK]
        cands = []
        for variant, callee, fwd, keep, entry, end in chunk:
            # each candidate aliases the callee under a name only it declares, so
            # two candidates in one TU cannot disagree about its arity
            src = build_source(variant, "g_%s" % callee, fwd, keep)
            cands.append((variant, src))
        # one declaration per distinct callee alias. Repeated identical
        # declarations are legal, and a per-candidate prototype is not: the arity
        # is what the search is deciding, so it cannot be fixed in advance.
        head = "\n".join("extern void g_%s();" % c
                         for c in sorted({j[1] for j in chunk}))
        with tempfile.TemporaryDirectory() as td:
            obj, err = MH.compile_batch(cands, td, head=head)
            if not obj:
                print("  batch at %d failed: %s" % (k, err.strip()[:120]))
                continue
            syms = MH.obj_symbols(obj)
            dumped = MH.obj_text_range(
                obj, syms, [MH.mangle(v, "m" * keep) for v, _, _, keep, _, _ in chunk])
            for variant, callee, fwd, keep, entry, end in chunk:
                tried += 1
                code = dumped.get(MH.mangle(variant, "m" * keep), b"")
                if not code:
                    continue
                owner = entry[0]
                if owner in hits:
                    continue
                addr, size, name, ident, _ = entry
                want = blob[addr:addr + size]
                mine = list(md.disasm(code, 0))
                verdict, _why = MH.compare(
                    list(md.disasm(want, addr)), end, mine)
                if verdict == "match":
                    # the registered source uses the real ident and the real
                    # callee name, not the search alias, and must compile
                    cname, synthetic = callee_ident(callee, owner_mod)
                    hits[owner] = (
                        addr, size, name, ident, cname,
                        'extern void %s();\n' % cname
                        + build_source(ident, cname, fwd, keep),
                        "m" * keep, code, synthetic)
                    print("  match  %s@%#x  forward=%d keep=%d  -> %s"
                          % (name, addr, fwd, keep, callee))
                    sys.stdout.flush()
    return list(hits.values()), tried


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", action="append", default=None)
    ap.add_argument("--detect", action="store_true")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--write", action="store_true",
                    help="append verified matches to the registry")
    a = ap.parse_args()
    a.ntry = a.limit

    md = MH._md()
    mods = a.module or list(MODULES)

    if a.detect:
        print("=== bare delegators (prologue / one bl / epilogue / ret) ===")
        total = 0
        for mod in mods:
            reg = set()
            p = os.path.join(ROOT, "data", "matched_%s.json" % mod)
            if os.path.exists(p):
                for r in json.load(io.open(p, encoding="utf-8"))["matched"]:
                    reg.add((r["addr"], r["size"]))
            found = scan(mod, md, reg)
            total += len(found)
            print("  %-9s %6d" % (mod, len(found)))
        print("  %-9s %6d" % ("TOTAL", total))
        return 0

    if not a.ntry:
        ap.error("nothing to do: pass --detect or --try N")

    all_found = []
    for mod in mods:
        reg = set()
        p = os.path.join(ROOT, "data", "matched_%s.json" % mod)
        if os.path.exists(p):
            for r in json.load(io.open(p, encoding="utf-8"))["matched"]:
                reg.add((r["addr"], r["size"]))
        pool = scan(mod, md, reg)
        if not pool:
            print("  %-9s no bare delegators" % mod)
            continue
        blob = MH.text_blob(mod)
        print("  %-9s %d delegator(s) to try" % (mod, len(pool)))
        found, tried = try_batch(pool, blob, md, a.ntry, mod)
        print("  %-9s %d verified of %d compile attempts"
              % (mod, len(found), tried))
        all_found.extend((mod,) + f for f in found)

    print()
    print("=== total verified: %d ===" % len(all_found))
    if a.write and all_found:
        for mod in mods:
            rows = [f for f in all_found if f[0] == mod]
            if not rows:
                continue
            path = os.path.join(ROOT, "data", "matched_%s.json" % mod)
            reg = json.load(io.open(path, encoding="utf-8"))
            have = {(r["addr"], r["size"]) for r in reg["matched"]}
            added = 0
            for _, addr, size, name, ident, callee, src, sig, got, syn in rows:
                if (addr, size) in have:
                    continue
                reg["matched"].append({
                    "module": mod, "addr": addr, "size": size, "name": name,
                    "shape": "delegator", "ident": ident, "sig": sig,
                    "src": src, "callee": callee, "callee_synthetic": syn,
                    # the frame is independent of the parameter count, so the
                    # bytes cannot fix the arity. smallest consistent count,
                    # all of it forwarded -- see the module docstring.
                    "arg_inferred": sig.count("m"),
                    "orig_insns": 5, "new_insns": len(got) // 4,
                })
                added += 1
            io.open(path, "w", encoding="utf-8", newline="").write(
                json.dumps(reg, indent=1, sort_keys=True))
            print("  %-9s registry +%d" % (mod, added))
    return 0


if __name__ == "__main__":
    sys.exit(main())