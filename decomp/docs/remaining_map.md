# Where the remaining 119,530 unmatched functions are

Measured 2026-10-15 over every unmatched row in `data/functions.csv`, keyed by
`(module, addr)`. No sampling except where noted. The CSV has no `shape` column
for unmatched rows -- shapes are only recorded for functions that already
verified -- so this classifies by disassembly.

## First cut: control flow

    has bl                              53.4%
    tailcall (b is the last insn)       27.6%
    has a conditional branch            11.7%
    straight-line, no call               5.8%
    undecodable                          1.4%

## The real breakdown

    ends-in-ret x has-bl       bodies   share
    ret=True  bl=True          2936    45.6%
    ret=False bl=True          1860    28.9%
    ret=True  bl=False         1041    16.2%
    ret=False bl=False          599     9.3%

45.6% of unmatched functions end in `ret` and contain a `bl` -- the exact shape
`call_register` handles. That is roughly 54,500 bodies, and `candidates()`
surfaces **555** of them. So the question was always "what is `candidates()`
throwing away", and the answer is not what it looks like.

## Rejection reasons inside candidates()

    119,492 unmatched bodies, 555 accepted (0.5%)

    frame_of None                      101,906   85.3%
    <24 bytes                           14,535   12.2%
    bl count = 3                         1,566    1.3%
    bl count = 0 (none)                    331    0.3%
    has adrp/adr/blr                       277    0.2%
    bl count = 2                           160    0.1%

`frame_of` is the gate, at 24x the next filter. That looked like a 100,000-body
missed population. It is not, and the reason matters.

## Why frame_of is not a missed population

`frame_of` is all-or-nothing: it demands `stp x29,x30,[sp,#-N]!` + `mov x29,sp`
at the front and the post-indexed `ldp` at the back, and returns None otherwise.
For a body with NO frame at all it should arguably return `(0, 0)`. Breaking the
101,906 rejections down:

    NO FRAME AT ALL, ends in ret          62,248   61.1%
    no frame push, does not end in ret    37,591   36.9%
    frame push, no matching ldp             1,971    1.9%
    other                                      96    0.1%

62,248 frameless bodies ending in `ret` is 41% of the entire unmatched
population, so this was worth the check. It survives none of it:

    of the 62,248 frameless bodies, 0 pass the remaining filters

      bl count = 0                            20,063   <- leaves, no call at all
      has a BRANCH                            10,396
      bl count = 2                             8,196
      bl count = 3                             6,709
      bl count = 4                             3,419
      bl count = 5                             2,211

A frameless function that still calls something needs no callee-saved registers,
and retail's compiler still gives it the standard frame because the call forces
one. So "frameless AND exactly one call AND no branches" is close to
contradictory. The 8,196 two-call frameless bodies are real, but when passed to
the translator with every callee in the `calls` dict, **zero translate and zero
bail** -- they are excluded by the branch and adrp filters, not by the call count.

`len(bls) != 1` therefore looks like a cheap win and is not. Relaxing it to
`>= 1` changes nothing measurable.

## What is actually uncovered

  * 20,063 leaf bodies, no call. This IS the straight-line population:
    `sl_register` reports 3,154 candidates and 0 verified, measured twice.
  * 10,396 bodies with conditional branches. The translator is straight-line by
    construction and `BRANCH` includes `b.eq`, `cbz`, `tbz` and friends, so every
    one of these is declined by design. This is the largest genuinely uncovered
    shape and it needs CONTROL FLOW, not a filter change.
  * ~20,500 frameless bodies with 2+ calls, nearly all of which also branch.
  * 37,591 bodies that do not end in `ret` -- mostly the 27.6% tailcall
    population, which `decomp_project` does have a `tailcall` shape for, so part
    of this is reachable and part is not.

## So the honest summary of the remaining figure

21.39% is not 21.39% plus "a filter I have not relaxed". The reachable
populations are:

    straight-line, no control flow   ~3,154   0 verified, re-measured
    single-call, retail frame           555   28 blocked, rest translate and miss
    tailcall                            ?     partly covered by decomp_project

and the largest block -- conditional control flow, 10,396 sampled and
proportionally far more of the real 119,530 -- is a different kind of work
entirely. A control-flow extension to `straight_line.py` is the next structural
decision, not another handler.
