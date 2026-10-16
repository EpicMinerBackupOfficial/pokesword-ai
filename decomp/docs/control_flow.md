# Control flow: the guarded tailcall, measured byte-identical

This is the first extension to `straight_line.py` that is not a single missing
mnemonic, and the population it opens is the largest one left.

## Why an `if` is needed at all

`BRANCH` in `call_register.py` is

    ('b','b.eq','b.ne','b.lt','b.le','b.gt','b.ge','b.hi','b.hs','b.lo','b.ls',
     'cbz','cbnz','tbz','tbnz','br','ret')

so any body containing one of those is declined by `candidates()`. Measured over
the unmatched population, **10,396 of a 6,436-body sample -- 11.7% -- are declined
for a conditional branch and nothing else.** That is the largest genuinely
uncovered shape; everything else is exhausted.

## The target shape: a guarded tailcall

The simplest bodies in that class, 821 of them with exactly one call, one
conditional branch, a `ret` and no `adrp`/`adr`/`blr`, all share one shape:

    main sub_2c1470@0x2c1470   (8 instructions)
      ldr   x0, [x0, #0x50]
      cbz   x0, #0x2c148c          <- the ret
      stp   x29, x30, [sp, #-0x10]!
      mov   x29, sp
      bl    #0x2c5fb0
      mov   w0, #1
      ldp   x29, x30, [sp], #0x10
      ret

The branch target is the `ret`, so the null case skips the call, the result
move AND the frame teardown. The frame is pushed *inside* the branch, which is
not how a function prologue normally reads -- that is the signature of a guarded
tailcall rather than an `if` around a call.

## The C that produces it, measured clang 5.0.1 -O3

    typedef unsigned int u32;
    void g(void *);
    u32 A(void *a0) {
      void *p = *(void **)((char *)a0 + 0x50);
      if (p) { g(p); return 1; }
      return 0;
    }

compiles to

    00 28 40 f9  ldr  x0, [x0, #80]
    c0 00 00 b4  cbz  x0, #24
    fd 7b bf a9  stp  x29, x30, [sp, #-16]!
    fd 03 00 91  mov  x29, sp
    00 00 00 94  bl   #0
    e0 03 00 32  orr  w0, wzr, #0x1
    fd 7b c1 a8  ldp  x29, x30, [sp], #16
    c0 03 5f d6  ret

which is retail's sequence instruction for instruction, encodings included. The
branch displacement 24 is the same 0x18 in both. `orr w0, wzr, #0x1` is the
encoding `mov w0, #1` disassembles to -- the same alias question that came up
with `orr w3, wzr, #3` in `fp_scheduling.md`, and again not a difference.

The second target reproduces too:

    u32 B(void *a0) {
      void *p = *(void **)((char *)a0 + 0x5e0);
      if (p) { return (u32)((u64) g2(p) >> 32); }
      return 0;
    }

    -> ldr x0,[x0,#1504] ; cbz x0,+8 ; stp ; mov ; bl ; lsr x0,x0,#32 ; ldp ; ret

matching `sub_ba8de0@0xba8de0` exactly.

## Two spellings measured first, and rejected

`if` is not the only route to a branch, and the wrong ones do not need the
control-flow machinery at all -- so they were measured before writing any of it.

    u32 A(u32 a0) { if (a0 == 0) return 1; return 0; }
        -> cmp w0,#0 ; cset w0,eq ; ret          NO BRANCH AT ALL

Clang turns a conditional whose arms are both constants into `cset`/`csel`, so a
`cbz` only appears when at least one arm does real work. Testing a synthesised
trivial conditional would have concluded "C cannot express this", which is why
the target had to be a real body rather than an invented one.

## What implementing it needs

`translate()` walks instructions linearly into one flat `stmts` list and
`_emit()` renders it. A guarded block needs a NESTED statement list, and the
condition has to be rendered from the branch itself.

The pieces that already exist:

  * `COND_OPS` (straight_line.py:135) -- the compare-to-flag table
  * `_render`'s `cond` kind -- already emits `((test) ? (a) : (b))`
  * `state` -- the branch's register is already a known value at that point

So the work is structural, not lexical: a block boundary in the walk, a nested
list threaded through `_emit`, and a wrapper emitted at the join. The `if (p)`
condition comes from the register the `cbz` tests, which for this shape is always
a value the walk has already loaded.

## Size -- and a correction

The first count of this shape was 821, and it was wrong in the same way the
blocker counts were: it was a FILTER CLASS, not a population. 821 is every
unmatched body with one call, one conditional branch, a `ret` and no
`adrp`/`adr`/`blr`. Only 123 of those branch to the `ret`:

    branch target
      targets the ret            123
      targets insn 9             112
      targets insn 10             60
      targets insn 8              50
      targets insn 12             49
      targets insn 7              49

The other 698 branch INTO THE MIDDLE, so the guarded block is followed by more
code rather than the epilogue. That is a different shape and the minimal
implementation does not reach it.

Of the 123:

      cbz     81     \
      tbz      6      >  88 test a single register, no `cmp` needed
      tbnz     1     /
      b.ne    21     \
      b.hi     7      >  35 branch on a flag, so the C needs a `cmp` and
      b.lt     3       >    COND_OPS coverage
      b.eq     2      /
      b.ls     2      /

So the first implementation is worth **88 bodies**, and 35 more follow once the
compare family is handled. All 88 are the `sub_2c1470` shape measured above.

## The mistake, recorded

I quoted 821 as "this shape" one beat after establishing that quoting a counter
without looking at what it counts is how the blocker populations were wrong
twice already. The habit is the defect, not the number: a count is not a
population until you have checked what the counted things have in common.
Measured the same day, in the same session, and still wrong.

88 bodies is 0.06% of the figure. That is worth having and it is not worth a
risky structural change to a translator holding 32,532 matches. The right order
is: measure the C, bank the recipe, then change the walk.


## The 88 are not one template either

Checked before implementing, having just been burned for quoting a filter class
as a population. Sampling the first four of the 88 they all looked like
`sub_2c1470` -- `ldr x0,[x0,#off]` / `cbz x0, ret` / frame / `bl` / `mov w0,#1` /
frame / `ret` -- differing only in the offset and the callee. That was three
bodies that agreed and it would have been enough to design against.

    the 88: final block instruction
       ldp x29, x30, [sp, #0x10]   70
       cset w0, eq                  4
       mov w0, #1                   3
       cset w0, ne                  3
       bl #0x2ed320                 2
       lsr x0, x0, #0x20            1

    the 88: the pre-branch instruction
       ldr [x0                     27
       ldrb [x0                    10
       ldr [x0]                     3
       mov #1                       2
       tbz #0                       2
       ldr [x1                      2

Three findings, and the first is the important one:

**1. 70 of the 88 have `ldp x29, x30, [sp, #0x10]` as the third-from-last
instruction -- NOT the standard `ldp x29, x30, [sp], #N` epilogue.** It is
non-writeback, so `frame_of` rejects these bodies for a second reason
independent of the branch, and the frame form differs from the one `sub_2c1470`
uses. Clang emits that form when the callee-saved pair is reloaded from a known
slot rather than popped.

**2. Only 3 of the 88 end the block with `mov w0, #1`.** Seven end with `cset`,
which is a flag-derived result and means the block's return is a comparison, not
a constant. The rest end with the call itself or a shift of its result. So "the
block returns 1" -- the assumption the single measured body suggested -- holds
for 3 of 88.

**3. The pre-branch instruction is not always a pointer load.** 27 are
`ldr [x0, ...]`, 10 are `ldrb` (a byte, so the guard is a byte being zero or
non-zero and the C type is `unsigned char *`), and the rest are a bare
register or a `mov`.

So the implementation is a template with a parameterised return expression, a
parameterised guard type, and two frame forms -- not one body with two
constants. That is the difference between a change that would have worked on
`sub_2c1470` and a change that works on 88, and it is only visible by counting
the variants rather than reading the first example.


## The 70 are not a template, and that corrects the design

    main sub_67bf70@0x67bf70   (12 instructions, the dominant-70 frame form)
      ldrb  w8, [x0, #0x7c]
      cbz   w8, #0x67bf9c            <- the ret
      str   x19, [sp, #-0x20]!
      stp   x29, x30, [sp, #0x10]
      add   x29, sp, #0x10
      mov   x19, x0
      ldr   x0, [x0, #0x58]
      bl    #0x67bfc0
      strh  w0, [x19, #0x7a]
      ldp   x29, x30, [sp, #0x10]
      ldr   x19, [sp], #0x20
      ret

    main sub_7b4bb0@0x7b4bb0   (17 instructions)
      ldr   x8, [x0, #0x5e0]
      ldrb  w9, [x8, #0x58]
      bfxil w9, w1, #0, #1
      strb  w9, [x8, #0x58]
      tbz   w1, #0, #0x7b4bf0        <- the ret
      sub   sp, sp, #0x20
      stp   x29, x30, [sp, #0x10]
      add   x29, sp, #0x10
      ldr   x0, [x0, #0x5e8]
      add   x1, sp, #8                <- a stack SLOT
      mov   w2, #1
      mov   w3, wzr
      str   xzr, [sp, #8]
      bl    #0x14e6550
      ldp   x29, x30, [sp, #0x10]
      add   sp, sp, #0x20

### Why the "four axes" framing was wrong, and what replaces it

Last beat I concluded the 88 need "a template with a parameterised return
expression, a parameterised guard type and two frame forms". Read as a design
that says: hard-code the return, hard-code the guard type, handle two frames.
That would have been the wrong implementation, and the reason is visible above.

These are not bodies of one shape. They are **arbitrary straight-line function
bodies with a guard branch at the top**, and the body is the part the translator
already handles:

  * the block's return is the CALL'S result (`bl` then `strh`, falling through
    with x0), not a constant. So the "return expression" is not an axis to
    hard-code -- it is `state["x0"]` at the end of the block, which the existing
    walk has already computed.
  * the guard is `ldrb` (a byte) in both examples, so the C type follows from
    the load the walk already modelled, not from a hard-coded `void *`.
  * the frame differs -- `str x19,[sp,#-0x20]!` / `stp x29,x30,[sp,#0x10]` /
    `add x29,sp,#0x10` / `ldp x29,x30,[sp,#0x10]` / `ldr x19,[sp],#0x20` -- but
    the translator does not emit frames at all. Clang does, from the C. So the
    frame is not an axis either; it is an output to be allowed to come out
    right.
  * `mov x19, x0` is just Clang keeping a0 live across the call. The C needs
    nothing for it.
  * `add x1, sp, #8` and `str xzr, [sp, #8]` is a stack SLOT for an out
    parameter. That is a real requirement, but it is a pre-existing one --
    `frame_of` and the `sp` refusal already handle or decline it.

So there is **one mechanism, not four axes**: reuse the existing walk for the
block, wrap its rendered source in `if (<guard>) { ... }`, and emit the
fallthrough return from `state["x0"]` as it stood before the block.

What remains is plumbing, not semantics:

  1. a `guard` argument to `translate()` -- default None, so every existing
     caller is byte-identical
  2. split the instruction list at the guard, walk both halves with shared
     `state`/`used_args`
  3. a second return value in `_emit`

The default-None guard is the whole safety story: the 32,532 matched bodies
never pass a guard, so they cannot be disturbed by any of it.


## The population is now a tool, not a hand-derived number

    python tools/call_register.py --guard

    guarded population: 123 bodies
      main         63
      sdk          30
      subsdk0      20
      subsdk1      10
      by guard mnemonic:
        cbz        81
        b.ne       21
        b.hi        7
        tbz         6
        b.lt        3
        b.eq        2
        b.ls        2
        tbnz        1

`candidates_guarded()` is a SEPARATE enumerator, not a flag on `candidates()`.
`candidates()` rejects any body with a `BRANCH` mnemonic; relaxing that in place
would change what the existing generator hands the translator, and the
translator has no branch handler at all, so every one would arrive as

    unsupported mnemonic 'cbz'

(`COND_MNEMONICS` is the SELECT family -- `csel`/`cset` -- not the branch family.)
A separate enumerator means the existing generator is provably untouched, which
is checkable: the register sweep after adding it returned the same counts and
`audit.py` stayed green.

It also reproduces 123 and the same mnemonic split as the hand count, which is
the useful part: the figure no longer has to be re-derived each beat, and a
future change to the filters that moves the number will be visible rather than
buried in a commit message.

## Where the implementation stands

Blocked on `translate()` and `_emit()`, both of which hold every verified body.
The design is settled and the minimum change is small -- record a snapshot of
`state` and the two list lengths when the walk reaches the guard, then let
`_emit` partition and nest -- but it cannot be verified safely inside a beat
where the machine is paging, because a half-working translator is only
distinguishable from a good one by a full register sweep, and that is the thing
too slow to run twice.

So the order stays: enumerate, measure the C, then change the walk. The first
two are done.


## LANDED: the guarded walk, and what it still gets wrong

The path is built end to end and it compiles. `translate()` takes a `guard`
(index of the branch in `body`, default `None`), the pre-filter lets that one
instruction through, the walk snapshots `state` and the two list lengths when it
reaches it, and `_emit` partitions on those into

    <decls> <outer calls> <outer stores>
    if (<cond>) { <inner calls> <inner stores> return <inner>; }
    return <outer>;

`candidates_guarded()` strips the frame from the block first -- only pure frame
bookkeeping: the x29/x30 pair, a callee-saved push/pop, and the `sub/add sp`.
Nothing that passes a stack slot to a callee is stripped, because that is a real
out-parameter and those bodies keep bailing on `sp`, correctly.

### 123 bodies, and where they go

    13  translate
    68  bail: memory base is sp -- a genuine stack slot, correctly declined
    29  bail: guard 'b.ne'/'b.hi'/'b.eq' is not a single-register test
     5  bail: fsub, bfxil -- unrelated

97 variants compiled across the 13, **0 verify**. Both blockers below are in the
C, not in the structure.

### Defect 1: the fallthrough return re-loads instead of returning the constant

    retail  ldr x0, [x0, #0x50] ; cbz x0 -> +24 ; ... ; mov w0,#1 ; ldp ; ret
    ours    ldr x8, [x0, #0x50] ; cbz x8 -> +28 ; ... ; mov w0,#1 ; ldp
                                               ; mov w0, wzr ; ret

Two differences, one cause. The walk renders the fallthrough return as
`return (uint32_t)(*(uint64_t*)((char*)(a0) + 80));` -- re-evaluating the load --
so Clang materialises `mov w0, wzr` before `ret`. Retail's null path simply
leaves x0 alone, because the load already put 0 there.

The measured recipe that DOES work is the one from the top of this file:

    void *p = *(void **)((char *)a0 + 0x50);
    if (p) { g(p); return 1; }
    return 0;

A named local, and a CONSTANT fallthrough. `cbz` asserts the value is zero, so
the fallthrough return is literally `0` and needs no load at all. The translator
re-derives the load because it renders the return expression from `state` without
consulting what the guard proved about it.

### Defect 2: the load lands in x8, not x0

    retail  ldr x0, [x0, #0x50]
    ours    ldr x8, [x0, #0x50]

The walk allocates a scratch register for the loaded value instead of letting it
land in x0, which retail does because the load overwrites the incoming argument.
This one is about register choice rather than semantics, and fixing defect 1
removes the need for the value twice over -- with the local named and the
fallthrough a constant, there is one load and Clang puts it where retail does.

Defect 1 is the one to fix, and both point at the same place: the guard is
treated as a branch to be skipped rather than as a fact about the value it tests.


## Defect 1 fixed; what is left is the NAMED LOCAL

`cbz` proves the tested value is zero on the fallthrough, so the fallthrough
return is now the constant rather than a re-evaluation of the load:

    if (*(uint64_t*)((char*)(a0) + 80)) { ... return 1; }
    return 0;

Measured against the recipe at the top of this file, the generated C is now the
right shape. It still does not match, and the remaining difference is one token:

    MINE (now)                       RECIPE (byte-identical)
    if (*(uint64_t*)((char*)(a0)+80))  void *p = *(void**)((char*)a0 + 0x50);
    { ... return 1; }                   if (p) { g(p); return 1; }
    return 0;                            return 0;

Two consequences of the missing `p`, and they are the whole gap:

1. **The callee never receives the pointer.** The generated call is
   `g_2c5fb0()` with no argument, because the only prototypes `prototype_order`
   offers for this body have `nargs = 0`. The recipe's `g(p)` needs a one-argument
   prototype, and `callee_arg_floor` is not producing one here. So even with the
   right shape there is nothing to pass.
2. **The load is an expression, not a register.** With the value used once in the
   condition Clang is free to put it in `x8`, which is what it does; with a named
   local it is live in `x0` and that is what retail has.

So the two remaining instructions -- `ldr x8` instead of `ldr x0`, and the
`mov w0, wzr ; ret` tail -- are one cause: the guard's value is an inline
expression, so it is neither passed to the callee nor pinned in a register.

The fix is to synthesise a local for the guard's value at the guard point, the
way the `synth` mechanism already does for displaced addresses, and use that
local in the condition. Whether the callee then receives it depends on
`prototype_order` offering an arity that matches, which it currently does not for
this body -- so the two have to land together, and the arity floor is the
narrower of the two problems.
