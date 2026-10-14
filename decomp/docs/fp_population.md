# The floating-point population, and what `fmov x0, d0` actually is

After the call-result fixes, **468 of 574** unmatched call bodies translate a
non-void prototype (490 after allowing `add/sub` on a call result, up from
effectively zero). Those compile but do not match, and the blockers are now
dominated by one thing:

    unsupported mnemonic 'fmov'      480
    unsupported mnemonic 'fneg'      160
    unsupported mnemonic 'fcvt'       64

44 distinct bodies bail purely on floating point:

    fmov   30
    fneg   10
    fcvt    4

## `fmov x0, d0` is not arithmetic

The first body, `main@0x66f480`, is 28 bytes and contains exactly two
instructions past the frame:

    mov   x29, sp
    fmov  x0, d0

`fmov` between an integer and an FP register moves the **bits** — it converts
nothing. The AArch64 form `fmov <Xd>, <Dn>` is a reinterpret, and the only C that
produces it is a bit-level pun:

    union { double d; uint64_t u; } v;
    v.d = x;
    return v.u;          /* or memcpy(&x, &d, 8) */

So these bodies need a **union / bit-cast**, not an FP type. That is a different
value kind from anything the translator has: there is no "float" in the state
model at all, because `ldp`/`ldr` into `d0` and the integer view of the same
register have to be the same storage.

## Why it is worth doing

44 bodies directly, and this is only the call-body population. The FP mnemonics
appear across the module wherever the code touches a `double` or a `float`, and
none of that is modelled. It is also the only remaining blocker class large
enough to matter on its own — the next two after it are pre-index stores
(`str x8, [x0], #8`, 80) and `stp xzr, xzr, [x0]` (78).

## The shapes to support, in order of frequency

1. **`fmov <Xd>, <Dn>` / `fmov <Dd>, <Dn>`** — bit pun, union-backed. 30 bodies.
2. **`fneg <Dd>, <Dn>`** — genuine single-instruction negation of a double. In C
   that is `-x` on a `double`, but the FP argument arrives in a register that the
   integer model does not track, so the *whole* FP register file has to exist
   before `fneg` can be written at all. 10 bodies.
3. **`fcvt`** — int↔float conversion, `scvtf`/`fcvtzs`/`fcvtzu`. Needs real FP
   types and correct rounding intrinsics. 4 bodies.

(2) and (3) cannot be done without (1): they all require an FP register file, and
the `fmov` case is the cheapest thing that establishes it.

## Method

The same one that opened `adrp` and the pair-load half: take the body, read the
instructions, work out what C produces them from, compile that C, compare. Four
spellings and one compile per shape, rather than reasoning about what the
translator ought to do.

## A note on the `local` fix from the same beat

`add/sub on a 'local' value` was 168 bodies and is now zero: a call result is an
ordinary integer value, and refusing arithmetic on one for the sake of a missing
list entry was costing the whole population. `local` is now accepted in both the
two-operand and three-operand forms.