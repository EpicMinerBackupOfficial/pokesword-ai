"""Register call bodies: the `1 call + memory` class, which is the largest one.

`StraightLine` can now lower a body that contains a `bl`: the call's arguments are
the current values of x0..x{n-1}, which the register `state` has been tracking all
along, so no separate liveness pass was needed. What it cannot know is the callee's
prototype -- AAPCS64 says the arguments are in x0..x7 and nothing about how many
there are or whether a result comes back. So the prototype is searched here, where
it can be measured, and the search stops at the first variant that reproduces
retail's bytes.

Three decisions here are worth stating, because each of them was wrong first:

  * **The callee is called through a cast, not a prototype.** Two bodies in one
    generated unit call the same callee with different argument counts, and two
    `extern` lines disagreeing about arity is a redefinition that kills the whole
    unit rather than the two bodies. The cast states the arity at the call site.

  * **A failed batch is bisected, not retried.** `compile_batch` puts ~200
    candidates in one TU, so a single ill-formed candidate -- and the translator
    does emit those, `Bail("... is ill-formed")` exists for the case -- costs the
    other 199. Bisecting pays that cost once, on the batches that fail.

  * **The search order matters more than the search size.** nargs is tried
    outermost so the common cases (a few arguments) are reached first, and the
    whole thing stops at the first match.

What is *not* modelled: callees in another module. A `bl` to an address outside
this module is registered under the module's own name if it has one, and flagged
`callee_synthetic` when it does not -- the bytes are identical either way, but the
name is a placeholder and the row says so.

    python tools/call_register.py --module main --limit 400 --dry-run
    python tools/call_register.py --limit 2000 --write
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
import straight_line as SL

MODULES = ("main", "sdk", "subsdk0", "subsdk1")
RETS = ("uint64_t", "void", "uint32_t")
MAXNARGS = 7
BATCH = 200

RET_INSN = None


def _ret_insn(md):
    global RET_INSN
    if RET_INSN is None:
        RET_INSN = next(iter(md.disasm(b"\xc0\x03\x5f\xd6", 0x1000)))
    return RET_INSN


BRANCH = ("b", "b.eq", "b.ne", "b.lt", "b.le", "b.gt", "b.ge", "b.hi", "b.hs",
          "b.lo", "b.ls", "cbz", "cbnz", "tbz", "tbnz", "br", "ret")


def frame_of(ins):
    """-> (prefix_len, suffix_len) if this is retail's frame, else None.

    Retail frames unconditionally: `stp x29, x30, [sp, #-N]!` then `mov x29, sp`
    at the front, and the matching post-indexed `ldp x29, x30, [sp], #N` at the
    back. Clang produces that itself once the call is non-terminal, so the
    translator must never be handed it -- the pair handler reads `sp` as a base
    and declines with "a stack slot is not modelled", which is a correct refusal
    of the wrong input.
    """
    n = len(ins)
    if n < 6:
        return None
    if not (ins[0].mnemonic == "stp"
            and ins[0].op_str.startswith("x29, x30, [sp, #-")
            and "]!" in ins[0].op_str):
        return None
    if not (ins[1].mnemonic == "mov" and "x29, sp" in ins[1].op_str):
        return None
    if not (ins[-1].mnemonic == "ret"):
        return None
    if not (ins[-2].mnemonic == "ldp"
            and ins[-2].op_str.startswith("x29, x30, [sp], #")):
        return None
    return 2, 2


def candidates(mod, reg, md, limit):
    """-> [(addr, size, name, ident, target, work_insns, n_insns)]"""
    blob = MH.text_blob(mod)
    out = []
    for addr, size, name, decomp in MH.load_functions(mod):
        if (addr, size) in reg:
            continue
        code = blob[addr:addr + size]
        if len(code) < 24:
            continue
        ins = list(md.disasm(code, addr))
        f = frame_of(ins)
        if f is None:
            continue
        pre, suf = f
        work = ins[pre:len(ins) - suf]
        bls = [i for i, x in enumerate(work) if x.mnemonic == "bl"]
        if len(bls) != 1:
            continue
        if any(x.mnemonic in BRANCH for x in work):
            continue
        if any(x.mnemonic in ("adrp", "adr", "blr") for x in work):
            continue
        target = int(work[bls[0]].op_str.lstrip("#"), 16)
        out.append((addr, size, name, "f_%x" % addr, target,
                    list(work) + [_ret_insn(md)], len(ins)))
        # `limit <= 0` means UNLIMITED, not "one".
        #
        # `len(out) >= 0` is true on the very first append, so asking for
        # "no limit" returned exactly one body -- and reported it as a
        # complete answer. A caller scripting this module got 1 candidate per
        # module where the tool itself reports 90/474/14/16. Silent, and in
        # the direction that looks like "nothing left to try".
        if limit and limit > 0 and len(out) >= limit:
            break
    return out


REG_RE = None


def arg_reg_cap(work):
    r"""Highest x0..x7 index the body touches before its `bl`, plus one.

    An upper bound on the argument count: to pass n arguments, x0..x{n-1} have to be
    arranged, and retail does not write a register it never uses as an argument.

    Every register token in the whole operand string counts, not just the first of
    each comma-separated field. Splitting on commas and taking field[0] reads
    `ldr x8, [x0, #8]` as "ldr" and "x0", so it never sees the *destination* x8 --
    and since destinations are what a body writes to set up its arguments, the cap
    came out almost always 1. Measured: 211 of 300 `sdk` bodies capped at 1, and
    the search that descends from the cap could then never reach the arity that
    actually matched. Taking every `\b[wx]\d+\b` fixes it; `w` registers are
    included because a `w` write is an `x` write, zero-extended.
    """
    global REG_RE
    if REG_RE is None:
        import re
        REG_RE = re.compile(r"\b([wx])(\d+)\b")
    bl = next((i for i, x in enumerate(work) if x.mnemonic == "bl"), None)
    if bl is None:
        return MAXNARGS
    hi = -1
    for x in work[:bl]:
        for _w, d in REG_RE.findall(x.op_str):
            i = int(d)
            if i <= 7 and i > hi:
                hi = i
    return min(MAXNARGS, max(0, hi + 1))


# Arity bounds derived from the CALLEE's body, not the caller's.
#
# `arg_reg_cap` bounds the CALLER -- the most arguments it can set up. It says
# nothing about what the callee accepts, so the search was trying arities the
# callee provably cannot have.
#
# Under AAPCS64 the first eight integer/pointer arguments arrive in x0..x7, so a
# callee that READS xN before WRITING it must have been passed at least N+1
# arguments. That is a hard LOWER bound: a callee may accept eight and touch only
# x0, so this yields no upper bound and must not be used as one.
#
# Ghidra was asked for these signatures first and correctly declined: AArch64
# encodes no parameter count, and nothing in the module calls these callees with a
# known type, so every one came back "0 undefined sub_XXXX ()".
#
# work/callee_nargs.json comes from work/calleenargs.py. If it is absent or
# malformed the search degrades to exactly the previous behaviour rather than
# failing -- a missing bound must never mean a body stops being tried.

def _load_callee_nargs():
    try:
        import json as _json
        p = os.path.join(ROOT, "work", "callee_nargs.json")
        if not os.path.exists(p):
            return {}
        raw = _json.load(io.open(p, encoding="utf-8"))
        return {m: {(int(a, 16) if isinstance(a, str) else a): v
                    for a, v in (rows or [])}
                for m, rows in raw.items()}
    except Exception:                                     # noqa: BLE001
        return {}


CALLEE_NARGS = _load_callee_nargs()


def callee_arg_floor(mod, target):
    """Lowest arity the callee can possibly have, or None when unknown."""
    return (CALLEE_NARGS.get(mod) or {}).get(target)


def prototype_order(work, mod=None, target=None):
    """-> [(nargs, ret)] in the order they are worth trying.

    Ascending nargs, over the full 0..MAXNARGS range.

    Both of these were wrong at first and each looked harmless:

      * **Descending from a cap.** The cap (highest argument register the body
        touches before its `bl`) is not an upper bound. A body that receives an
        argument in x1 and passes it straight on never *writes* x1, so the cap
        undercounts -- and searching downward from a too-low cap never reaches the
        arity that matches. Measured: 8 matches out of 300 against 255 for the
        plain ascending search over the same bodies with the same comparison.

      * **Descending from MAXNARGS.** Ascending is right because most of these
        bodies pass few arguments -- a pointer, or nothing -- and the prototype
        that wins is usually a low one. Putting the widest first burns a compile
        per body on a guess that is usually wrong.
    """
    floor = callee_arg_floor(mod, target)
    if floor:
        # An arity below the floor cannot match, and skipping it is worth more
        # than the compile time it saves: Clang DELETES the argument setup for a
        # prototype whose parameters the callee's body never reads, so such a
        # variant does not merely differ in the arguments -- it loses the whole
        # setup. Removing it takes a decoy out of the comparison.
        return [(n, r) for n in range(floor, MAXNARGS + 1) for r in RETS]
    return [(n, r) for n in range(0, MAXNARGS + 1) for r in RETS]


def variant(work, ident, target, cname, nth, mod=None):
    """The `nth` *translatable* prototype for one body, or None if there are fewer.

    "nth translatable", not "nth in the order". A prototype that `Bail`s is not a
    prototype the body does not have -- it is one this translator cannot express,
    and the next one still deserves a turn.

    Counting every entry of the order instead made a single untranslatable variant
    end the body's search. `(3, 'void')` bails for almost every body, so after
    pass 0 nearly the whole population looked exhausted and the run reported 8
    matches out of 300 where the flat search reports 255 -- same prototypes, same
    comparison, one body's search cut short by a prototype it was never going to
    use.
    """
    seen = 0
    for nargs, ret in prototype_order(work, mod, target):
        calls = {target: {"name": cname, "nargs": nargs, "ret": ret}}
        try:
            src, sig = SL.StraightLine(work).translate(ident, calls=calls)
        except SL.Bail:
            continue
        if seen == nth:
            return (nargs, ret, src, sig)
        seen += 1
    return None


def compile_chunk(cands, head):
    """Compile one TU. Returns [(candidate_row, code), ...], or None on TU failure.

    `cands` rows are `(ident, src, sig, addr, size, name, target, nargs, ret,
    n_ins)`, so the name and source are `c[0]` and `c[1]`. Indexing `c[3]` for the
    name compiles the *address* as if it were source text, and the harness's own
    check for "does this look like source" raises `TypeError: argument of type
    'int' is not iterable` rather than saying which candidate was wrong.

    The result is a **list of pairs, not a dict keyed by ident**. Several prototypes
    for one body produce the same `ident` with different signatures, so a dict
    collapses them and keeps only the last -- which is the widest, least likely
    prototype. That silently reports 0 matches on a population where some of them
    do match: the `nargs=4` hit was overwritten by the `nargs=7` miss before any
    comparison ran.
    """
    obj, err = MH.compile_batch([(c[0], c[1]) for c in cands],
                                _work_dir, head=head)
    if not obj:
        return None
    syms = MH.obj_symbols(obj)
    keys = [MH.mangle(c[0], c[2]) for c in cands]
    dumped = MH.obj_text_range(obj, syms, keys)
    return [(c, dumped.get(MH.mangle(c[0], c[2]), b"")) for c in cands]


def compile_resilient(cands, head):
    """Compile a batch; bisect on failure so one bad candidate costs one, not 200."""
    got = compile_chunk(cands, head)
    if got is not None:
        return got
    if len(cands) == 1:
        return []
    mid = len(cands) // 2
    out = []
    for part in (cands[:mid], cands[mid:]):
        out.extend(compile_resilient(part, head))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", action="append", default=None)
    ap.add_argument("--limit", type=int, default=1000)
    ap.add_argument("--batch", type=int, default=BATCH)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    global _work_dir
    _work_dir = tempfile.mkdtemp(prefix="callreg_")
    md = MH._md()
    mods = a.module or list(MODULES)
    all_rows = []

    try:
        for mod in mods:
            reg = set()
            p = os.path.join(ROOT, "data", "matched_%s.json" % mod)
            if os.path.exists(p):
                for r in json.load(io.open(p, encoding="utf-8"))["matched"]:
                    reg.add((r["addr"], r["size"]))
            pool = candidates(mod, reg, md, a.limit)
            print("  %-9s %5d call body(s) to try" % (mod, len(pool)))
            sys.stdout.flush()
            if not pool:
                continue
            syms = {addr: name for addr, _s, name, _d in MH.load_functions(mod)}
            blob = MH.text_blob(mod)
            found = []
            # One prototype per body per pass.
            #
            # The first attempt generated every prototype for every body, compiled
            # them all, and only then compared -- so a body that matched on its
            # first prototype still cost 24 compiles. Measured at 60 bodies in ten
            # minutes on `main`, which puts sdk's 3,175-body pool at nine hours.
            #
            # Passes invert that: pass 0 tries each body's most likely prototype and
            # nothing else, and a body that matched drops out of every later pass.
            # With most bodies landing early the total falls to about 2-3 compiles
            # per body rather than 24, for the same answer.
            remaining = list(pool)
            # Idents already recorded as matched, updated the moment a match is
            # recorded rather than re-derived from `found` at the end of the pass.
            # Re-deriving it produced 371 rows for 91 distinct bodies -- four
            # duplicate records for nearly every body, because a body that matched
            # was still offered to later passes. The registry write deduplicates on
            # (addr, size), so those would have been silently dropped, and the
            # headline would have been the row count rather than the body count.
            done = set()
            for nth in range(0, 40):
                if not remaining:
                    break
                nxt = []
                got_n = 0
                for k in range(0, len(remaining), a.batch):
                    chunk = remaining[k:k + a.batch]
                    flat = []
                    for addr, size, name, ident, target, work, n_ins in chunk:
                        v = variant(work, ident, target,
                                    "g_%x_%x" % (target, addr), nth, mod)
                        if v is None:
                            continue
                        nargs, ret, src, sig = v
                        flat.append((ident, src, sig, addr, size, name,
                                     target, nargs, ret, n_ins))
                    if not flat:
                        continue
                    head = "\n".join("extern void g_%x_%x();"
                                     % (c[6], c[3]) for c in flat)
                    got = compile_resilient(flat, head)
                    seen_here = set()
                    for cand, code in got:
                        # `ident` is taken from the candidate, deliberately
                        # shadowing the enclosing chunk loop's variable.
                        #
                        # It used to be read as `_i` and then `done.add(ident)` and
                        # `"ident": ident` used the *enclosing* name, which by then
                        # was the last body in the chunk. Every row recorded one
                        # body's address under another's name, `done` accumulated
                        # only the last chunk body's name, and nothing was ever
                        # removed from `remaining`: 371 rows for 91 bodies, all of
                        # them duplicates of the same 91.
                        c_ident, src, sig, addr, size, name, target, nargs, ret, \
                            n_ins = cand
                        ident = c_ident
                        if not code or cand[0] in seen_here:
                            continue
                        seen_here.add(cand[0])
                        want = blob[addr:addr + size]
                        w = list(md.disasm(want, addr))
                        end = MH.effective_end(w, size)
                        verdict, _ = MH.compare(w, end,
                                                list(md.disasm(code, 0)))
                        if verdict != "match":
                            continue
                        real = syms.get(target)
                        synth = real is None
                        real = real or ("callee_%x" % target)
                        # The compiled source carries the per-body search alias,
                        # which exists only in the probe TU. Renaming it here
                        # rather than discovering it at build time: the alias is
                        # unique per body, so the substitution is unambiguous.
                        # Leaving it in put
                        #   error: use of undeclared identifier 'g_512700_18b690'
                        # into every emitted prog/matched source, and all 2,856 of
                        # them failed to build -- every one of them verified first,
                        # because verification and building never used one name.
                        _alias = "g_%x_%x" % (target, addr)
                        found.append({
                            "module": mod, "addr": addr, "size": size,
                            "name": name, "shape": "call",
                            "ident": ident, "sig": sig,
                            "callee": real, "callee_synthetic": synth,
                            "call_args": nargs, "call_ret": ret,
                            "orig_insns": n_ins,
                            "new_insns": len(code) // 4,
                            "src": "extern void %s();\n%s" % (
                                real, src.replace(_alias, real)),
                        })
                        got_n += 1
                        done.add(ident)
                        sys.stdout.flush()
                        # No `break` here. A chunk holds one candidate per body,
                        # so breaking out on the first match ends the whole chunk
                        # and the run records exactly one match per chunk per pass.
                        # Measured: 3 per pass on a 120-body run in three chunks of
                        # 40, against 95 for the same bodies in the flat search --
                        # the burst pattern was the chunk size, not the population.
                    print("  %-9s pass %2d  %5d/%5d bodies done, %5d matched"
                          % (mod, nth, min(len(remaining), k + a.batch),
                             len(remaining), len(found)))
                    sys.stdout.flush()
                # Anything still unmatched after this pass gets another prototype:
                # it must both have another translatable prototype and not have
                # been recorded already.
                remaining = [e for e in remaining
                             if e[3] not in done
                             and variant(e[5], e[3], e[4], "x", nth + 1) is not None]
                print("  %-9s pass %2d done: +%d this pass, %d left"
                      % (mod, nth, got_n, len(remaining)))
                sys.stdout.flush()
            all_rows.extend(found)
            print("  %-9s %5d new match(es)" % (mod, len(found)))
    finally:
        shutil.rmtree(_work_dir, ignore_errors=True)

    print()
    uniq = {(r["module"], r["addr"], r["size"]) for r in all_rows}
    print("=== total verified: %d (%d distinct bodies) ==="
          % (len(all_rows), len(uniq)))
    if len(all_rows) != len(uniq):
        # A duplicate here means a body was matched in more than one pass, which
        # means it was not removed from `remaining` when it should have been. The
        # number reported would then be an overcount, and the registry write would
        # skip the duplicates and quietly not match it.
        import collections as _c
        dup = _c.Counter((r["module"], r["addr"]) for r in all_rows)
        worst = [k for k, n in dup.items() if n > 1][:5]
        print("  WARNING: %d duplicate row(s); e.g. %s"
              % (len(all_rows) - len(uniq), worst))
    by_mod = collections.Counter(r["module"] for r in uniq and all_rows
                                 or all_rows)
    for m, n in by_mod.most_common():
        print("    %-9s %5d" % (m, n))

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
                key = (r["addr"], r["size"])
                if key in have:
                    continue
                data["matched"].append({k: v for k, v in r.items()})
                added += 1
            io.open(path, "w", encoding="utf-8", newline="").write(
                json.dumps(data, indent=1, sort_keys=True))
            print("  %-9s registry +%d" % (mod, added))
    elif all_rows and not a.write:
        print("  (dry run -- pass --write to register)")
    return 0


if __name__ == "__main__":
    sys.exit(main())