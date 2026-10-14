# Why 594 call bodies fail: the dead half of a pair load

Arity was not the cause. Pinning a hard arity floor for the 28 `main` callees that
have one — up to 8× narrower, 3 of 24 variants in the worst case — converted zero
bodies. So the failure is downstream of the prototype.

## The body

`main@0x2aa630`, 32 bytes, callee `0x2a9a50`:

    ldr  x0, [x0, #0x50]
    bl   #0x2a9a50
    ldp  x8, x1, [x0]      <-- two general registers, one instruction
    mov  x0, x8
    ldp  x29, x30, [sp], #0x10
    ret

`x1` is written and never read again. That is the whole problem.

## The search cannot even express the body

    7 variants translatable out of 21 ordered
    (nargs, ret) reachable: (1,'void') (2,'void') (3,'void') (4,'void')
                             (5,'void') (6,'void') (7,'void')

**Every translatable variant is `ret=void`.** The body returns the call's result,
so it needs a non-void prototype — and every non-void variant `Bail`s. A
`void`-returning render is the only one that survives translation, and it is wrong
by construction.

## `ldp` IS modelled — the dead half is deleted by Clang

Worth correcting a wrong turn: `ldp` is not missing. `straight_line.py:1082` is a
dedicated handler that sets two `load` values at `off` and `off + width`, and it
takes the element width from `access_width` so a 32-bit pair steps by 4.

The problem is downstream. With both halves rendered as separate expressions and
the second one dead, Clang deletes that load:

    A: u64 a=*(u64*)p; u64 b=*(u64*)((char*)p+8); return a;
         ->  ldr x0, [x0]            <-- no ldp; the dead half is gone
    C: ... __asm__ volatile("" : "+r"(b)); return a;
         ->  ldp x8, x9, [x0]        <-- retail's shape
    D: both halves used
         ->  ldp x8, x9, [x0]

Measured on clang 5.0.1 `-O3`. **Case C is byte-identical to retail's instruction.**

So this is the *same* problem as the `adrp` displacement, and it has the same fix:
an empty `asm` with a `"+r"` read-write operand pins the value so the load cannot
be elided. The `adrp` pin is already in `straight_line.py`; this one is not.

## Why the implementation is not one line

The barrier has to be emitted **as a statement**, positioned like the `adrp` pin
was — after any call, before the use. But the dead half never reaches the emitter
at all: nothing reads `x1`, so no statement is rendered for it, so a barrier
placed with it would never appear. The `stmts` list cannot express "materialise
this value and pin it" without also giving it somewhere to live, and parking it in
a stack slot would change the frame that the comparison is checking.

The options, in order of preference:

1. **Bind the second half to a pinned local in the handler** and add it to the same
   `pins` list the `adrp` path uses, emitting it in the `pre + _call_txt + pins +
   body_txt` position that was already established. Cleanest, and the position is
   already known to be correct.
2. Render the pair as a single two-field struct load and pin the unused field.
   Same barrier requirement.
3. Accept `ldr` and stop matching bodies whose retail has `ldp` with a dead half.
   Honest, but it forfeits exactly the population this targets.

## What it is worth

594 bodies. Not all of them have a dead half — but any that has an `ldp` whose
second destination is unused and whose return value is live is currently
*unmatchable*, because the only translatable render is the `void` one. That is a
structural ceiling, not a search width, and it is why narrowing the search changed
nothing.

## Method note

The same technique that opened the `adrp` population — write the minimal C, compile
it, read the instructions — opened this one. Four spellings of a pair load, one
compile, and the answer was exact. No amount of reading the translator would have
shown that the instruction is present in the handler and still absent from the
output.