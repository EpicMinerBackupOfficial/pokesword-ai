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

## Measured, not predicted

The spellings above were checked rather than assumed — clang 5.0.1 `-O3`, four
cases, one compile:

    union { double d; u64 u; } v; v.d = x; return v.u;   ->  fmov x0, d0
    memcpy(&r, &x, 8)                                    ->  fmov x0, d0
    the same pun reversed (u64 in, double out)           ->  fmov d0, x0
    -x on a double                                       ->  fneg d0, d0

The first is byte-identical to the instruction in `main@0x66f480`, and the last is
exactly the shape the ten `fneg` bodies need. The recipes are correct; what is
missing is the translator side.

## What implementing it actually requires

Not a mnemonic handler. The FP register file itself.

`fmov x0, d0` moves bits between two register files that the model currently
treats as one. On AArch64 `d0` and `x0` are the same storage, so the *right*
model is an alias rather than a new value kind — but that only works if the
parameter is **typed**. `u64 f(double x)` and `u64 f(u64 x)` receive their
argument in the same register and differ only in what Clang emits to convert it,
so the translator has to know the declared type, and the type maps
(`used_args` / `ptr_args` / `idx_args`) have no floating-point entry at all.

Concretely, in order:

1. An `f64`/`f32` entry in the argument type maps, set when an FP register is
   written. This is the load-bearing change; without it a double parameter is
   declared `u64` and no pun is ever emitted.
2. `fneg <Dd>, <Dn>` as unary minus on that typed argument.
3. `fmov <Xd>, <Dn>` / `fmov <Dd>, <Xd>` as the union pun, in both directions.
4. Only then `fcvt`, which additionally needs correct rounding intrinsics.

1 and 2 together are the ten `fneg` bodies. 1 and 3 are the thirty `fmov` bodies.
None of them needs a real value kind — `d0`/`x0` aliasing covers all of it.

## The sdk bodies are a different shape: a float punned into a call argument

The 30 `fmov` bodies are not all the double pun. 13 of the 14 sampled are
byte-identical in form, and it is a tail-call setup:

    sdk@0x5a310 (40 bytes)
      stp  x29, x30, [sp, #-0x10]!
      mov  x29, sp
      mov  x2, x1               <- 3rd call argument
      fmov w1, s0               <- float parameter punned to uint32
      add  x0, x0, #8           <- 1st argument
      mov  w3, #3               <- 4th argument
      bl   #0x512170
      and  x0, x0, #0xffffffff  <- call result truncated to 32 bits
      ldp  x29, x30, [sp], #0x10
      ret

The C that produces most of it, measured:

    u64 g(u64, u32, u64, u32);
    u32 f(void *a0, void *a1, float a2) {
      return (u32)g((u64)a0 + 8, ((union { float f; u32 u; }){ .f = a2 }).u,
                    (u64)a1, 3);
    }

gives `fmov w1, s0` exactly. Three remaining differences, and only one is real:

| retail | this spelling | |
|---|---|---|
| `mov x2, x1` | `mov x8, x1` … `mov x2, x8` | a copy Clang chose for scheduling |
| `mov w3, #3` | `orr w3, wzr, #3` | the same encoding, printed as an alias |
| `and x0, x0, #0xffffffff` | *absent* | **the real one** |

The mask is missing because under AAPCS64 a `u32` return arrives in `w0` with the
upper half undefined, so `(u32)` on a `u64`-returning call needs no mask and Clang
drops it. Retail has the mask, so retail computes the result in 64 bits and
truncates it as a distinct step rather than by the ABI.

So these bodies need an **explicit truncation modelled as its own operation**,
which is a small change sitting in front of 13+ bodies.

## Two shapes, one mechanism

    fmov x0, d0    double parameter punned to u64   -- main@0x66f480, +1 verified
    fmov w1, s0    float parameter punned to u32    -- 13 of 14 sampled sdk bodies

Both are puns and differ only in width. The translator handles the double case;
the float case needs `{ float f; uint32_t u; }` plus the truncation above.

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
## movi: a NEON vector initialiser, not a zero constant

226 distinct `movi` forms exist; the dominant ones are zeroes, and overwhelmingly
SIMD:

    v0.2d, #0000000000000000   x595
    v1.2d, #0000000000000000    x84
    d0,   #0000000000000000      42

A plain zero constant does NOT produce it. Measured, clang 5.0.1 -O3:

    f64 z = 0.0;  asm volatile("" : "+w"(z));  return z;
        ->  fmov d0, xzr          NOT movi d0, #0
    struct V v = {0,0}; ... return v;
        ->  mov x0, xzr           NOT movi v0.2d, #0

A NEON vector does:

    #include <arm_neon.h>
    uint64x2_t v = {0, 0};   ->  movi v0.2d, #0000000000000000    (exact)

So `movi` on a vector register needs a NEON type in the generated source, which is
a bigger change than the other three blockers: it is a new type in the declaration
path rather than a new value kind in the walk. 48 call bodies.

## Where the remaining blockers stand

    SIMD operands v0.16b   160    NEON type + a vector-typed operand
    fcvt                    64    int<->float, needs rounding intrinsics
    movi                    48    NEON type (above)
    extend asr #31          46    one more entry in the extend table

All four need either a NEON type or a floating-point conversion. None is a missing
mnemonic handler, and each is now scoped by measurement rather than guesswork.

## `stp q0, q0, [x0]`: the vector form, and why a zero vector will not hold it

The 16-byte pair store needs the vector TYPE, and arm_neon.h is already in the
preamble, so the type is available. The blocker is that Clang will not emit the
register form for a known-zero vector:

    sub_507450 (32 bytes)
      movi  v0.2d, #0000000000000000
      stp   q0, q0, [x0]
      bl    #0x510410
      mov   w0, wzr
      ret

Measured, clang 5.0.1 with the harness flags:

    uint64x2_t v = {0,0};  asm volatile("");  g(a0);
        ->  the vector is unused and is deleted entirely; no stp at all
    uint64x2_t v = {0,0};  asm volatile("");  *(uint64x2_t*)a0 = v;  g(a0);
        ->  stp xzr, xzr, [x0]      NOT stp q0, q0, [x0]

So the zero vector folds to a pair of zero REGISTERS, and the `movi` that
materialises it in the vector file disappears with it.

This is the SAME defect as the dead half of an `ldp` and the fix is the same
shape -- an empty `asm` with a `"+w"` constraint on the vector, which cannot be
folded because Clang does not know what the barrier did to it. The "+w" form is
the NEON register constraint; "+r" would be the general-purpose file and is a
different register entirely.

Two spellings already tried and rejected:

  * `asm volatile("" : "+w"(v))` -- "inline asm not supported yet: don't know how
    to handle tied indirect register inputs". The constraint is right; Clang 5.0.1
    cannot express a tied vector operand in inline asm.
  * making the vector non-constant -- changes the instruction, so it is not a
    solution to a body whose value really is zero.

That leaves forcing it from the C side -- an `asm volatile` with an output vector
and no input, or a store through a pointer Clang cannot see through. Both are
worth one measurement each, and neither has been tried.

## The straight-line population is genuinely exhausted

    sl_register --limit 100000
      main 2118, sdk 589, subsdk0 212, subsdk1 212 candidates
      TOTAL 0 verified of 3131

The earlier work widened what translates from 1941 candidates to 3131. All 1190
new bodies translate and none match. That is a real widening of the reachable set
and it produced nothing, which is worth stating plainly rather than quoting the
candidate count as progress.

## The q-pair-store recipe, measured

The recipe for `movi v0.2d, #0 ; stp q0, q0, [x0]`, found this beat:

    struct Q2 { uint64x2_t a, b; };
    uint64x2_t v = {0, 0};
    *(struct Q2*)sink = (struct Q2){v, v};      <-- forces v into a register
    *(struct Q2*)a0  = (struct Q2){v, v};
    g(a0);

compiles to exactly:

    adrp x8 ; ldr x8,[x8] ; movi v0.2d, #0 ; stp q0,q0,[x8] ; stp q0,q0,[x0] ; bl

Three things were each necessary, and each was found by removing it:

  * **A 32-byte struct, not a 16-byte store.** `*(uint64x2_t*)a0 = v` gives
    `str q0, [x0]`. `stp q0, q0` is the SAME register stored twice, 32 bytes, so
    the C has to be a two-field struct.
  * **The vector forced into a register.** With only `*(struct Q2*)a0 = ...`,
    Clang folds the zero to `stp xzr, xzr`. Storing the same struct through a
    GLOBAL first is what survives, because then the value cannot be folded away.
  * **Both stores are needed for the right register.** `+w` on a tied operand is
    rejected outright by Clang 5.0.1 ("don't know how to handle tied indirect
    register inputs"), and `=w` output-only alone produced `str q0, [x0]` with no
    `movi` at all -- the barrier was not enough on its own.

So the pin is a real store to a global, not an asm constraint. That is a different
mechanism from the dead-`ldp`-half fix, which used a `+r` barrier successfully --
because `+w` cannot be tied in this Clang, and a store to memory can.

## What implementing it needs

1. A `struct Q2 { uint64x2_t a, b; }` typedef in MH.PREAMBLE, next to the
   existing `#include <arm_neon.h>` that is already there.
2. A global to pin through -- but a global store is an extra instruction, so it
   cannot be part of the body. It has to be emitted outside the compared region,
   which means the pinning store belongs in the harness's batch head, not in the
   generated function. That is a structural change to how candidates are compiled,
   not a change to the translator.
3. The pair-store handler gains a q-register case that stores a Q2 rather than two
   scalars.

Step 2 is the one that matters and it is not small. The pin has to exist in the TU
without appearing in the compared function, which is what the `+r` barriers avoid
by being free-standing statements rather than stores.

## The q-pair store, implemented -- and two bugs it uncovered

`struct Q2` is in the preamble and the handler has a q-register case. Four bugs,
in the order they surfaced:

**1. A stub shadowed the real handler.** `_render` had

    if kind == "neon":
        return val[1]

sitting ABOVE the branch that renders a NEON zero. It returned a bare string --
the type name -- so unpacking it into `(ct, expr)` raised

    ValueError: too many values to unpack (expected 2)

which is what 12 characters in a two-slot unpack looks like. The branch below it
had therefore **never run**: no value had ever reached it. A stub that returns
the wrong shape does not look like a stub when it is unreachable.

**2. The NEON type name was built from the scalar type.**

    "%sx%s_t" % ("uint64_t", "2")   ->   uint64_tx2_t

No header declares that. It has to be the STEM: `"%sx%s_t" % ("uint64", "2")`.

**3. `reg_num` does not accept `q`.** Its pattern is `[xw](\d+)`, so `reg_num("q0")`
is None and the lookup for the `movi` that wrote the vector always missed. The
two spellings of one register -- `q0` in the store, `v0.2d` in the movi -- were
never connected.

**4. The preamble existed in TWO copies.** `match_harness.PREAMBLE` and the
header `decomp_project.py` writes were independent copies of the same text. Q2
went into the harness, every candidate compiled and **verified against retail**,
and then the prog build failed:

    error: variable has incomplete type 'struct Q2'

Nothing in the matching path could have caught this, because the matching path is
where the type was added. `decomp_project` now imports `MH.PREAMBLE`; there is
one preamble.

## Calls are hoisted, so the store has to go in `pre`

`_emit` assembles

    all_txt = pre + _call_txt + pins + body_txt

Every call is emitted ABOVE every other statement, whatever the original did. So a
body that stores and *then* calls cannot match unless its store is in `pre`. The
q-store now records `not call_stmts` at walk time -- `call_stmts` fills in walk
order, so that is the question "had the call happened yet" -- and emits into
`pre` or `body_txt` accordingly.

That is the difference between

    mov x0,xzr ; bl ; movi v0.2d,#0 ; stp q0,q0,[x19]      not matching

and retail's

    movi v0.2d,#0 ; stp q0,q0,[x0] ; bl ; mov w0,wzr

and it is what turned 0 verified into 1.

## Reach

    non-void prototypes reachable   526 -> 528
    16-byte pair store not modelled  32 -> 0
    16-byte single store not modelled -> 0

Both vector-store blockers are gone. Of the bodies this reaches, 2 are store-
before-call, which is why the ordering fix was worth making on its own: the
population is small but the fix is general, and it will carry the `v0.16b`
population when that arrives.


## The NEON register swap, measured byte-identical

The `v0.16b` blocker is 10 bodies, and all ten are one shape -- a swap of two
NEON registers through a temporary:

    bl   #0x52c880
    fneg d1, d1
    mov  v2.16b, v0.16b
    mov  v0.16b, v1.16b
    mov  v1.16b, v2.16b
    ret

### The C, measured

    struct V2 { uint8x16_t a, b; };
    struct V2 g(void);
    struct V2 A(void) {
      struct V2 s = g();
      struct V2 t;
      t.a = s.b;
      t.b = s.a;
      return t;
    }

compiles to

    stp  x29, x30, [sp, #-16]!
    mov  x29, sp
    bl
    mov  v2.16b, v0.16b
    mov  v0.16b, v1.16b
    mov  v1.16b, v2.16b
    ldp  x29, x30, [sp], #16
    ret

Retail's three `mov`s, exactly, with no memory traffic. A struct of two vectors
RETURNED BY VALUE is what puts the swap in registers: the two halves come back in
v0 and v1 per the vector return convention, and exchanging them is three register
moves.

### Two measurements that were wrong first, and what they fixed

**A proxy with two calls spills.** The first attempt called `g()` twice into two
locals and read elements out of them:

    bl ; str q0, [sp] ; bl ; umov w8, v0.b[0] ; ldr q0, [sp] ; ...

which shares nothing with retail. The struct return is not decoration in the
recipe -- it is the whole reason the swap stays in registers.

**A scalar return folds the swap away.** The real body negates a `double` view and
then swaps, so the negated half lands in v0. Written with a scalar return:

    bl ; fneg d0, d1 ; umov w0, v0.b[3]

Clang folds the exchange into the negation and emits `fneg d0, d1` where retail
has `fneg d1, d1`. The difference between the two is precisely the swap, and it
survives only if the struct is the return value.

### What implementing it needs

  1. `mov vd.16b, vn.16b` as a vector copy. The `movi` handler already writes
     `("neon", ct, lanes)` values and `arm_neon.h` is in the preamble, so the
     type and the local machinery exist -- what is missing is the copy.
  2. A callee that returns a STRUCT. `prototype_order` only offers scalar return
     types, and a 32-byte struct is returned in v0 and v1 rather than in x0. That
     is the larger of the two, and it is the same shape the guarded work needed
     and did not have.

So this is not one handler. It is a handler plus a return-convention change, for
10 bodies -- and worth re-measuring against the real bodies before starting,
since the proxy above already caught two things a smaller test would not have.
