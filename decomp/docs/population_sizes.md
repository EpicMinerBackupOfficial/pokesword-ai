# Population sizes: attempts are not bodies

Every "N bodies blocked" number reported by `work/reach.py` and
`tools/call_register.py` is a count of **prototype attempts**, not a count of
bodies. One body is tried against every prototype `prototype_order` produces, and
each attempt that `Bail`s is counted again.

Measured 2026-10-15 by keying the bail on `(module, addr)` instead of counting:

    blocker                                attempts   BODIES
    v0.16b operand                             240       10
    unsupported fcvt                            96        4
    unsupported smulh                           69        3
    empty body / > MAX_INSNS                    24        1
    other operand: 'v0.s[0]'                    24        1
    mov source 'x0' is neither imm nor ...      24        1
    mov source 'x4' is neither imm nor ...      24        1
    empty body / > MAX_INSNS                    24        1
    lsl shift 'w8' is not a literal             24        1
    unsupported bics                            21        1
    unsupported bfxil                          21        1
    call argument x0 is not a known value        9        1
    TOTAL DISTINCT BODIES BLOCKED              28

## Why the inflation is so large

`prototype_order` returns up to 40 entries for a body, and most of them produce
the SAME C SIGNATURE. Six of the attempts for `sdk+0x4cc7d0` compile to the same
`uint64_t f_4cc7d0(void *a0)`:

    error: redefinition of 'f_4cc7d0'

so a body with one signature that `Bail`s is counted six to sixteen times
depending on how many arities the order happens to enumerate. The largest
classes are inflated by roughly 24x.

## What this means for the arc

The four "converged blockers" of the previous three beats -- `v0.16b` 160, `fcvt`
64, `smulh` 46, vector-memory-operand 42 -- were 240/96/69 attempts. As bodies
they are **10, 4 and 3**. All ten `.16b` bodies are one shape: a NEON register
swap through a temporary,

    bl ; fneg d1,d1 ; mov v2.16b,v0.16b ; mov v0.16b,v1.16b ; mov v1.16b,v2.16b ; ret

which is why a single missing handler looked like a large population for two
beats. It was never large.

## The call-body generator is exhausted

`reach.py` reports 556 unmatched CALL BODIES, of which 528 translate a non-void
prototype and 28 are blocked. So:

  * 28 bodies are blocked by a missing handler -- all of them, measured above
  * 528 bodies translate cleanly and still do not verify

The blocked 28 are a rounding error: every one of them at once would move the
figure by 28/152,062, from 21.39% to 21.41%. The 528 are where the mass is, and
the documented cause for those is Clang scheduling (`fp_scheduling.md`, seven
causes eliminated and measured).

Straight-line is the same story: 3,154 candidates translate, 0 verify, measured
twice.

## How to read a reach figure from now on

Do not report an attempt count as a population. Key the bail on the body:

    bodies = {(mod, addr) for each (mod, addr, ...) whose prototype attempts all Bail}

`work/../bdist.py` in the work directory is that measurement; it is worth
promoting to a tool, because every future population estimate depends on it.
