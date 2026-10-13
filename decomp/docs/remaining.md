"""The remaining framed population, and what blocks each part of it.

`ceiling.md` records the four reversals that opened up this project. This is the
state after them: what is left, and -- more usefully -- for each remaining block,
whether the obstacle is a missing capability, a missing name, or something that
does not exist to be recovered at all.

The distinction matters because the three need different work and only one of them
is a translator change:

  * a missing capability is a feature to build;
  * a missing name is an address to recover from the binary;
  * a missing callee is not missing at all -- `blr` has no callee to name, and
    treating it like the other two is a category error that will not converge.

Every figure here is measured with `work/blocked.py`, `work/adrp.py` and
`work/adrpgap.py`, which are scratch and untracked; this file is the record.

## The framed population, by obstacle

    adrp blocked          277    a modelling error, not a naming one -- see below
    ready, mismatching   ~680    register allocation around calls
    indirect call (blr)  379    no callee name exists
    branch               122    needs control flow, not one composed expression

The earlier count of 1,909 adrp-blocked bodies included branched ones. Stripped of
those it is 277, and all 277 already contain a call.

## adrp: one modelling error, worth about 246 bodies

277 bodies reference 105 distinct addresses, and only 4 of the 350 references have
a name anywhere in the repo. That looks like a naming problem -- 346 references
needing an address recovered from the binary.

It is not. Substituting each `adrp` with an equivalent `mov` of the same page
constant leaves the translator's job unchanged and isolates the real obstacle:

    translates once adrp is a plain constant       139  (50%)
    still declines                                 138  (50%)

        memory base 'x8' holds a imm, not a pointer            66
        memory base 'x0' holds a local, not a pointer          34
        ... and 38 more

The two largest decline classes are the *same* error as the thing being substituted
for. `adrp x8, #page` then `add x8, x8, #off` leaves x8 holding an integer, and
the load path requires a memory base to be a pointer. 107 of the 138 are that, not
a second missing capability.

So modelling `adrp` as an *address* rather than an integer constant is worth about
**246 of 277**, not the 139 the headline suggests. It is also a new producer for an
existing value kind rather than a new kind: `addr` already renders as a `char *`
expression and is already accepted as a memory base, which 546 matched bodies
depend on.

`strlit_match.py` already solved the link-time half for 239 bodies at 239/239 --
`GLOBAL_DECL` must be `const` or Clang emits a GOT `ldr` instead of `adrp`+`add`.
That mechanism needs no new work; it needs feeding.

## blr is a different kind of problem

379 bodies call through a register. The target is a runtime value, so there is no
address to recover and no name to look up. These need the call to be expressed as
something like `((fn)(p))(...)` with the pointer's provenance reconstructed, which
is a different translator capability from either of the above and cannot be reached
by naming anything.

## branch needs statements, not expressions

`StraightLine.translate()` composes one expression per value and returns a single
function string. A conditional means control flow, which that shape cannot express.
This is the same structural limit that call lowering had, and calls got past it
because a call turned out to be a *statement* that could be emitted unconditionally
rather than composed into a value. Branches need the same treatment at a larger
scale: a statement list, and an `if` whose arms are themselves statement lists.

## What is not here

`multi-call` bodies were expected to be large and are not: only 58 once branched
bodies are excluded. The frame census's "3+ calls" bucket of 3,377 was counting
bodies that need branch lowering and have nothing to do with call arity.