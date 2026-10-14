# The FP bodies: a scheduling difference, and four causes already eliminated

`sdk@0x5a310` translates correctly and does not match. The difference is not
semantic:

    retail  stp ; mov x29,sp ; mov x2,x1 ; fmov w1,s0 ; add x0,x0,#8 ;
            mov w3,#3 ; bl ; and x0,x0,#0xffffffff ; ldp ; ret

    ours    stp ; mov x8,x1 ; add x0,x0,#8 ; fmov w1,s0 ; orr w3,wzr,#3 ;
            mov x2,x8 ; mov x29,sp ; bl ; and x0,x0,#0xffffffff ; ldp ; ret

Two real differences, one non-difference:

| | |
|---|---|
| `mov x8,x1` + `mov x2,x8` vs `mov x2,x1` | a copy Clang chose |
| `mov x29, sp` after the call, not in the prologue | |
| `orr w3, wzr, #3` vs `mov w3, #3` | **same encoding**, printed as an alias — not a difference |

That last one is worth not chasing: it looks like a mismatch in a diff and is not
one.

## Four causes tried and eliminated

Each is a complete C function, compiled at `-O3`, disassembled and compared.

1. **Frame barrier position.** `asm volatile("")` at the top, at the bottom, and
   at both. All three produced **byte-identical** output. The translator emits the
   barrier after the call and it was a reasonable suspect for moving
   `mov x29, sp`; it is not moving anything.
2. **Argument evaluation order.** Computing the third argument into a local first.
   No change.
3. **The pun as a named local.** Binding the union to a variable before the call
   instead of using a compound literal inline. No change.
4. **Direct call versus cast.** A properly prototyped `gd(a,b,c,d)` versus the same
   call through a `uintptr_t(*)(...)` cast — which is what the translator emits.
   The two are byte-identical to each other and neither matches retail.

So the call mechanism is not the cause and neither is the barrier.

## What that leaves

Clang 5.0.1, given any of these spellings, schedules the frame pointer late and
copies `x1` through `x8`. The retail binary does neither. Since four source-level
explanations are dead, the remaining candidates are:

- **A compiler flag difference.** `decomp/docs/flag_fidelity.md` records 26 bodies
  registered on the strength of the wrong flag set, and `tools/audit.py` enforces
  harness flags == build flags. If those ever drift, a frame could land early in
  one and late in the other. This is the cheaper hypothesis and it has precedent.
- **A source construct that forces a real frame** — a scoped local, or anything
  that keeps the frame pointer live from the prologue, which is what makes Clang
  emit `mov x29, sp` in the prologue rather than at the point of use.

## Reachability, which is the part that did move

    fmov 480 -> 0        fneg 160 -> 0
    non-void prototypes reachable   490 -> 506 of 560

The FP population is fully open. It is *not* matching because of one scheduling
decision, and that is a much narrower problem than "nothing in the translator
understands floating point", which is where this started two beats ago.

## What to do instead of a fifth spelling

The remaining blockers are untouched populations rather than scheduling questions:

    SIMD operands `v0.16b`   160
    pre-index stores         80
    stp xzr, xzr, [x0]       78
    fcvt                     64

Those are the better use of the next beat.