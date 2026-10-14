# `adrp` bodies: the page has to be a symbol, unknown in address AND contents

Three defects, all of which made a body that *translates* emit the wrong
instructions. None of them showed up as a diagnostic -- the source looked
plausible and the bytes were simply different, which is why this population read
as "close" for so long.

The failing body throughout is `main@0x1108c50`, retail 32 bytes:

    stp x29,x30,[sp,#-0x10]! ; mov x29,sp ; bl #0x1108740
    adrp x8,#0x1b15000 ; add x8,x8,#0xfc0 ; ldr w0,[x8,w0,sxtw #2]
    ldp x29,x30,[sp],#0x10 ; ret

## 1. `resolve_base` discarded the displacement

The `add` handler was correct -- `add x8, x8, #0xfc0` on an `("addr", key, 0)`
value produces `("addr", key, 0xfc0)`. The loss was downstream, in `resolve_base`:

    if v[0] == "addr":
        return v[1], False          # <-- v[2], the offset, discarded

The comment there said "reuse its id rather than inventing a second local for the
same address", which holds only at offset zero. Every access through a displaced
`adrp` was a load from the wrong address. A non-zero offset now gets its own local,
so the address survives into the emitted code:

    void* p0 = (void*)(&adrp_1b15000);
    void* p1 = (void*)((char*)(p0) + 4032);

## 2. The page object was one byte

    const char adrp_X[1] __attribute__((used, section(".adrpgN"))) = {0};

A load at `page + 0xfc0` reads out of bounds. Out of bounds is undefined behaviour,
so Clang is entitled to answer however it likes, and at `-O3` it answered by
deleting the access:

    ours  stp ; mov ; bl ; mov w0, wzr ; ldp ; ret      (the adrp and ldr are gone)

The `mov w0, wzr` is the signature of this defect -- a 32-bit result of zero from a
body whose retail counterpart is a table lookup.

## 3. And its contents were known to be zero

Resizing alone changed nothing, because `const ... = {0}` means the object is all
zeros and LLVM constant-folds a GEP into a global whose initializer it can see. The
page has to be *unknowable*, not merely not-a-constant-address:

    char adrp_X[0x1000] __attribute__((used, section(".adrpgN"))) = {0};

Dropping `const` is what does it. A writable object may be changed by anything, so
the load must be performed. The `adrp` and the `ldr` come straight back:

    ours    adrp x8, #0x1b16000 ; ldr x8,[x8] ; ldr w0,[x8,#0xfc0]
    retail  adrp x8, #0x1b15000 ; add x8,x8,#0xfc0 ; ldr w0,[x8,w0,sxtw #2]

One page covers every offset an `adrp` can address, and each page already has its
own section, so the extra bytes cannot collide with another page's.

## 4. And the callee's stub was in the same TU, so LLVM deleted the argument

This was never a constant fold. A non-volatile load whose result is unused *can* be
deleted, and the result was unused as far as the optimiser could see — because the
stub that received it was **defined in the same translation unit** and ignored its
parameter.

`-deadargelim` is an IPO pass that runs per-module at `-O3`. For a function the
module defines, it replaces each unused parameter in its callers with poison and
then deletes whatever fed it (`RecursivelyDeleteTriviallyDeadInstructions`). Upstream
states the condition exactly:

> We cannot change the arguments if **this TU does not define the function** or if
> the linker may choose a function body from another TU
> — `DeadArgumentElimination.cpp`, `removeDeadArgumentsFromCallers`

So a page load that exists only to become a call argument is dead code:

    retail  adrp x8,#0x714000 ; ldr x0,[x8,#0x68] ; bl #0x372200 ; mov w0,wzr
    ours    bl #0x269890 ; mov w0,wzr

Measured, three callees over one source, differing *only* in whether the body is
visible to the caller:

| callee | result |
|---|---|
| defined here, parameter ignored | `adrp` and `ldr` **deleted** |
| declared only, defined elsewhere | `adrp` and `ldr` **survive** |
| defined here, parameter used | `adrp` and `ldr` **survive** |

The stubs now live in their own translation unit (`stubs.cpp`, compiled with the
same CFLAGS so the ABI agrees) and the body TU only declares them. That is not a
workaround — it is the truth: we do not know what the real callee does with its
arguments, and the whole point is that the optimiser must not know either.

## Ordering matters here

Fixing (3) without (4) changed nothing observable for the argument case, because
the load was already being deleted before any folding question arose. Two fixes in
the wrong order look like one fix that did not work. The sequence that actually
produced a surviving load was: displace the offset → size the object → drop
`const` → move the callee out of the TU.

## The shape that survives, and why it is this specific

An `adrp` needs all four of:

| requirement | why |
|---|---|
| a **defined** symbol at the page | `adrp` is page-relative; `base + offset` will not produce it |
| **not** `extern` | an undefined symbol goes through the GOT, giving `adrp; ldr` |
| **not** `const` with a visible initializer | contents become compile-time known and the load folds away |
| **in bounds** | `[1]` makes every access past offset 0 undefined |

These pull in opposite directions and that is the whole difficulty: `const` is what
avoids the GOT, and `const` with an initializer is also what lets the optimiser
answer the load without doing it. There is no declaration that is both GOT-free and
opaque in one attribute -- the section attribute plus non-`const` is the working
combination, found by measurement rather than by reasoning about it.

The `0x1000` size also has to cover the *maximum* offset any access in the body
uses, not just the offsets seen in one sample. A page is 4096 bytes and `adrp` can
address all of it.

## How this was found, since the method is the point

Four consecutive beats of confident wrong conclusions came from this population,
all because the matcher was reporting something other than what it seemed to. The
tool slices its pool *before* translation, `limit=0` returns one item instead of
unlimited, and the diff printed once per prototype variant rather than once per
body -- so the reading was always variant 0 of 16, where Clang correctly deletes
argument setup, on a body chosen by a broken slice.

Every one of those was a reporting bug rather than a translator failure. The
translator defects above were real but were never visible until the diff printed
the body that was actually being linked, at the variant actually being compiled.

The rule that follows: **assert the tool's output before believing it.** Print the
source, not the byte count; name the variant; confirm the body count independently.
A mismatch count is not evidence about the translator.