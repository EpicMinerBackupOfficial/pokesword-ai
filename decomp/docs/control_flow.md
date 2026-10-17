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


## The C now IS the recipe; the codegen still is not

Three changes this beat, each from a named cause:

**1. The guard's value gets a NAMED LOCAL.** Rendered inline it appeared twice --
in the condition and as the callee's argument -- and as an expression Clang may
leave in a scratch register. Only an unsigned 64-bit load is eligible, because
anything else is a value whose type the guard did not establish.

**2. The REGISTER is redefined, not just the condition.** The first attempt
created the local for the `if` but the call argument still rendered the original
load, because the argument is resolved from `state` when the walk reaches the
`bl`:

    void *p0 = (void *)(*(uint64_t *)((char *)(a0) + 80));
    if (p0) { g((uintptr_t)(*(uint64_t *)((char *)(a0) + 80))); }   <- load twice

Redefining `state` dropped the translatable variants from 99 to 33, which is the
cost: a body whose later reads now resolve to a `void *` local is no longer
expressible under every prototype, and those prototypes correctly drop out.

**3. FRAME_ASM no longer lands inside the block.** It is `asm volatile("")`, it
sits after a `return` so it is dead, and a side-effecting statement stops Clang
merging the two return paths.

The generated C is now, line for line:

    uint32_t f_2c1470(void* a0) {
        void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 80));
        if (p0) {
            ((void (*)(uintptr_t))&g_2c5fb0)(p0);
            return 1;
        }
        return 0;
    }

which is the recipe that measured byte-identical:

    void *p = *(void **)((char *)a0 + 0x50);
    if (p) { g(p); return 1; }
    return 0;

**and it still does not match.** The two differences left are the same two:

    retail  ldr x0, [x0, #0x50] ; cbz x0 -> +24 ; ... ; mov w0,#1 ; ldp ; ret
    ours    ldr x8, [x0, #0x50] ; cbz x8 -> +28 ; ... ; mov w0,#1 ; ldp
                                               ; mov w0, wzr ; ret

So the C being right is not sufficient, and that is the finding worth having:
three separate C-level defects, each with a named cause, each fixed, and the
candidate still does not match. The remaining difference is a register CHOICE
(x8 against x0) and a tail Clang is not merging, neither of which is visible in
the source any more.

Remaining suspects, in the order I would test them:

  * `(void*)(expr)` versus `*(void **)addr`. A cast of a loaded value and a
    dereference of a `void *` are the same value, but they are not the same
    expression, and the register allocator does not have to agree.
  * the call is cast through a function pointer, `((void (*)(uintptr_t))&g)(p0)`,
    where the recipe calls `g(p)` directly. A direct call was byte-identical to
    the cast in the FP case (`fp_scheduling.md`), but that was without a guard.
  * `return 0;` materialises `mov w0, wzr` here and did not in the measurement,
    which suggests the compiler is not tracking `p0 == 0` into the return
    register. The measurement's local is `*(void **)(...)`; ours is
    `(void *)(*(uint64_t *)(...))`. If the first is the answer, the fix is to
    emit the dereference form rather than the cast form.


## The cast was never the problem: two suspects eliminated, and the real bug

### Suspect 1, the cast form: ELIMINATED

Three spellings of the local, compiled side by side:

    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 80));   the generated one
    void *p = *(void **)((char *)a0 + 80);                 the recipe

All three produce `ldr x0, [x0, #80]` -- retail's register, not x8. A cast of a
loaded value and a dereference of a `void *` are the same value, and Clang
allocates them the same way.

### Suspect 2, the call form: ELIMINATED

Direct call, function-pointer cast with a `uintptr_t` argument, and cast with a
`void *` argument. All three byte-identical to retail. Direct-vs-cast was already
known equivalent in the FP case; it holds here too.

### What the emitted source actually compiles to

Taking the translator's exact output, the harness preamble, and the harness's
K&R `extern void g_2c5fb0_2c1470();` head, and compiling it alone:

    00 28 40 f9  ldr  x0, [x0, #80]
    c0 00 00 b4  cbz  x0, #24
    fd 7b bf a9  stp  x29, x30, [sp, #-16]!
    fd 03 00 91  mov  x29, sp
    00 00 00 94  bl   #0
    e0 03 00 32  orr  w0, wzr, #0x1
    fd 7b c1 a8  ldp  x29, x30, [sp], #16
    c0 03 5f d6  ret

**Retail's sequence, encodings included.** The C was right for four beats and the
harness was reporting it as a mismatch.

### The actual bug: a type claim the declaration does not back

    error: cannot initialize a parameter of type 'uintptr_t' (aka 'unsigned long')
           with an lvalue of type 'void *'
        ((void (*)(uintptr_t))&g_2c5fb0_2c1470)(p0);

C++ has no implicit `void *` -> integer, so the WHOLE translation unit failed.
`compile_resilient` returns `[]` for a failed single-candidate TU, so the body
simply produced nothing -- and "produced nothing" is exactly what "0 verified"
looks like.

The cause is a type claim the declaration does not back. A synth local is emitted
as `void* <name> = ...;`, and the guard was registering it with the value tuple
`("local", name, "uintptr_t")`. `call_arg` only adds a cast when the rendered
type is not already `uintptr_t`, so it trusted the claim, omitted the cast, and
produced ill-formed C++.

Registering it as `void*` -- what the declaration actually says -- takes the
translatable variants from **33 to 90**.

### Why this is the most expensive bug of the arc, and it was not a codegen bug

It is invisible from the C. The source looks correct to a reader and to a diff;
it is the DECLARED type and the CLAIMED type that disagree, and only a compiler
says so. Every measurement of the generated code was taken from a batch that had
silently failed, so each round produced a plausible-looking instruction diff and
a plausible-looking conclusion, and the conclusions were all wrong because the
bytes were not the candidate's.

The general lesson is the one this arc keeps arriving at from different
directions: **a measurement taken from a pipeline that can fail silently is not a
measurement.** `compile_resilient` returning `[]` for "TU did not compile" and
for "candidate matched nothing" is the same shape as the health check reading
progress as liveness, and as the watchdog stamping once at spawn.


## IT MATCHES. The last false negative was my own comparison harness.

`MH.compare` takes Capstone objects. My scratch comparison script was passing it
the output of `MH.normalise`, which is TUPLES. `compare` therefore could not read
the operands and returned False for every candidate -- including ones that are
byte-identical:

        ('ldr', 'x0, [x0, #0x50]')          ==  ('ldr', 'x0, [x0, #0x50]')
        ('cbz', 'x0 -> +24')                ==  ('cbz', 'x0 -> +24')
        ('stp', 'x29, x30, [sp, #-0x10]!')  ==  ('stp', 'x29, x30, [sp, #-0x10]!')
        ('mov', 'x29, sp')                  ==  ('mov', 'x29, sp')
        ('bl', '<target>')                  ==  ('bl', '<target>')
        ('mov', 'w0, #1')                   ==  ('mov', 'w0, #1')
        ('ldp', 'x29, x30, [sp], #0x10')    ==  ('ldp', 'x29, x30, [sp], #0x10')
        ('ret', '')                         ==  ('ret', '')

8 against 8, every instruction, the branch displacement included. Re-run through
the harness's own `compare` on raw disassembly:

    main: 28 variants compiled
    subsdk1: 4 variants compiled
    TOTAL 32 variants, 32 MATCH

    MATCH main sub_2c1470@0x2c1470  nargs=0 ret=uint64_t
    MATCH main sub_2c1470@0x2c1470  nargs=2 ret=uint64_t
    MATCH main sub_2c1470@0x2c1470  nargs=3 ret=uint64_t
    MATCH main sub_675720@0x675720  nargs=0 ret=uint64_t

So five beats of "0 verified" were two harness bugs, neither in the translator:
a TU that failed to compile silently, and a comparison that could not read its
own input. The translator was correct from the moment the guarded walk landed.

`sdk` and `subsdk0` contributed 0 compiled variants -- their guarded bodies bail
on a genuine stack slot -- so the population that can be registered is main plus
subsdk1 for now.

**Not yet registered.** Wiring the guarded population into `call_register` is the
next step and it is a separate piece of work from making it match; the figure has
not moved yet and will not until the full chain runs.


## Registration: verified, and one generator defect still open

`register_guarded()` + `--register-guard` verifies 5 bodies in main end to end --
enumerate, translate, compile, `MH.compare` on raw disassembly, match. Three
defects were found and fixed while landing it, all in the harness:

  * one row per MATCHING PROTOTYPE rather than per body. `main+0x2c1470` matches
    at nargs 0, 2 and 3 -- the call is fire-and-forget, so the extra arguments
    are dead and Clang drops them.
  * the body marked `registered` BEFORE the comparison, so the first variant in
    compile order marked it and every later one was skipped. 10 verified matches
    became 0 in the tool while the same loop written out by hand found all 10.
  * the probe alias `g_<target>_<addr>` surviving into `prog/`, which produces
    `error: use of undeclared identifier`. The call path had been bitten by
    exactly this -- verification and building never used one name.

### decl_of now scans

`decl_of()` read only the first line of a row's `src`. A guarded `src` opens with
`extern void callee_2c5fb0();`, which is not a definition, so `DECL_RE` did not
match, `decl_of` returned None, and the row was emitted a second time as a plain
stub. It now scans for the first line that matches, which is the right shape for
the function: it asks what a line means, not where it is written.

### The extra definition is still not explained

The count did not move after that fix, so `decl_of` was not the cause. Measured
twice, both recorded:

  * **It is not duplication.** Scanning every main chunk source for the guarded
    functions finds each defined exactly once -- `main_f_2c1470 @ main_4.cpp x1`,
    `main_f_ba8de0 @ main_7.cpp x1`, `main_f_e43c70 @ main_8.cpp x1`,
    `main_f_e83850 @ main_8.cpp x1`. A fifth, `main_f_e83430`, is not found at
    all.
  * **It is not the `extern`.** The audit explicitly skips lines starting with
    `extern`, and the call path emits one `extern` per call body -- thousands of
    them -- without the count ever moving.

The delta is still exactly one per guarded row, and no candidate found accounts
for it. Guessing a third explanation without a measurement would be the pattern
this arc has been correcting all along, so the four bodies stay held back: an
audit that fails is not a state to commit, and 4 bodies is 0.003% of the figure.

One of the five does land -- 32,533 against a 32,532 baseline, audit green, with
the guarded rows out of the registry. Whatever the counting defect is, it does
not apply to that one, and the figure is measured by `match_progress` against the
linked image rather than asserted here.


## LANDED: 5 guarded bodies, and the bug was in the AUDIT

32,533 -> 32,538, 21.39% -> 21.40%. `152,062 definitions vs 152,062 rows`.

### The measurement that found it

Two explanations had been measured and rejected first -- duplicate emission
(each guarded function is defined exactly once) and the callee `extern` (the
audit skips `extern`, and the call path emits one per call body without the count
ever moving). The third was to diff the definition SET with and without the rows
in, which names the extras instead of counting them:

    with guarded: 32,539 definitions (+6)
    NEW:  if
          main_f_2c1470
          main_f_ba8de0
          main_f_e43c70
          main_f_e83430
          main_f_e83850

**`if`.** A guarded body is the first thing in this project whose generated C
contains control flow, and the audit's definition pattern is deliberately
permissive -- three narrower ones each undercounted -- so it is
`name ( params ) {` with a keyword where the return type goes. `if (p0) {`
matched, once per guarded body, which is exactly the +5.

So the generator was never emitting a second definition. The audit was counting
a control-flow statement as one, and the two only diverge on bodies this project
had not produced until now.

The permissive pattern stays -- it is right, and the alternative is the
undercounting this file's own history records. What changed is that the captured
name is now rejected when it is a C keyword; a function cannot be named `if`.

### What the arc cost to get here

Five beats from "the C is one cast away" to banked, and four of the five defects
were in the measurement rather than in the translator:

  1. a TU that failed to compile, reported as `[]`
  2. a comparison handed `normalise()` tuples by a function expecting Capstone
  3. one row per matching prototype rather than per body
  4. a body marked `registered` before its comparison, so 10 matches became 0
  5. and finally the audit counting `if (...) {` as a definition

Each was found by a measurement, and each was reported as a property of the
decomp when it was a property of the harness. The standing lesson is now in this
file four times from four directions: **a measurement from a pipeline that can
fail silently, or succeed wrongly, is not a measurement.**


## The guard condition, completed

Three classes of guard the `_guard_test` stub did not cover, all of them the same
kind of mistake -- an assumption about the shape of the operand that the body did
not honour.

**1. A compare on the flags.** 29 of the 123 branch on flags rather than testing
one register, and every one is an FP compare:

    ldr  s1, [x0, #0x14]
    ldr  s0, [x0, #0xc]
    fcmp s0, s1
    b.lt ret

The condition is a direct comparison of two values the walk already holds, and
the existing `expr` value kind renders it as `(a) < (b)`. The branch SKIPS the
block, so the C is the NEGATION, and that inversion is the whole table:

    b.eq  taken when ==   ->  if (a != b)
    b.ne  taken when !=   ->  if (a == b)
    b.lt  taken when <    ->  if (a >= b)
    b.hi  taken when >    ->  if (a <= b)

**2. `state` is keyed by the WIDENED register.** `orr w8, w1, #2 ; cmp w8, #2 ;
b.ne` writes `x8`, and the lookup used the raw spelling `w8`, missed, and fell
through to `arg_reg("w8")` -- "operand 'w8' is not an argument register (x0-x7)",
17 bodies. A message about an argument register for a register the body had
already written.

**3. The other operand can be an immediate.** `cmp x2, #0x168 ; b.hi` is the most
common shape in the whole set, and both operands were assumed to be registers, so
the literal reached `arg_reg("#0x168")` -- an argument-register error about a
constant that is not a register. 14 bodies.

All three produced the same misleading message, which is what made them look like
one defect. They were three, and the message named the wrong thing in each case.

## Where the guarded population stands

    123 guarded bodies
     10  translate
     95  memory base is sp -- a stack slot is not modelled
      2  fsub
      2  bfxil
      2  sbfiz
      1  guard 'b.eq' is not preceded by a compare
      1  add/sub on an 'argval' value

`sp` is now 95 of the 110 blocked, and it is the same refusal that gates much of
the wider conditional population -- `resolve_base` raises "memory base is sp: a
stack slot is not modelled" on any sp-relative access, which is a CORRECT refusal
of an input the translator cannot yet express. The C for it is a local variable
whose address is taken and passed:

    uint64_t slot;
    g(&slot);
    use(slot);

and Clang places it at a fixed sp offset by itself. So the next piece is not a
handler but a new kind of synthetic local -- the address of a stack slot, which
is the one local whose offset the original fixes rather than chooses. That is a
bigger change than anything left in this file, and it is the last big class here.

The three small ones (fsub, bfxil, sbfiz, two bodies each) are ordinary missing
mnemonics and are worth 6 bodies between them.


## 0 verify, and the two differences are now both LAYOUT

With the frame stripper fixed, 69 of the 123 translate and the rest are almost
entirely `sp` (35) and three missing mnemonics. None of the 69 matches, and the
instruction-level diff for the two smallest is short enough to read whole:

    sub_67bf70@0x67bf70 : 12 against 15
      retail                                        ours
      ldrb  w8, [x0, #0x7c]                        str  x19, [sp, #-0x20]!
      cbz   w8, <ret>                               stp  x29, x30, [sp, #0x10]
      str  x19, [sp, #-0x20]!                       add  x29, sp, #0x10
      stp  x29, x30, [sp, #0x10]                    mov  x19, x0
      add  x29, sp, #0x10                           ldrb w8, [x19, #0x7c]
      mov  x19, x0                                  cbz  w8, <ret>
      ldr  x0, [x0, #0x58]                          bl
      bl                                           strh w0, [x19, #0x7a]
      strh w0, [x19, #0x7a]                        ldp  x29, x30, [sp, #0x10]
      ldp  x29, x30, [sp, #0x10]                    ldr  x19, [sp], #0x20
      ldr  x19, [sp], #0x20                         ret
      ret                                          mov  x0, xzr
                                                   ldp  x29, x30, [sp, #0x10]
                                                   ldr  x19, [sp], #0x20
                                                   ret

The instruction SEQUENCE is retail's. What differs is where the frame is set up
and that there are two return paths.

### The two-return question is settled, and not by guessing

Measured both shapes for the callee-saved case, one `return` and two:

    u32 A(void *a0) { void* p = ...; u32 r = 0;
                      if (p) { ...; r = 1; } return r; }
    u32 B(void *a0) { void* p = ...;
                      if (p) { ...; return 1; } return 0; }

Both compile to twelve instructions with ONE epilogue and ONE `ret`. So the
guarded wrapper's two returns are not what produces the duplicated epilogue, and
rewriting it to a single return would be a change with no measured effect -- the
third hypothesis this file has now killed, and the first one where the simple
case and the guarded case gave the same answer.

### What is left is frame placement, which is layout

Retail pushes the frame INSIDE the branch; Clang puts it at the top with
`mov x19, x0` in front of the load. Both keep a0 live across the guard -- retail
copies x0 to x19 after the branch and ours before it -- so the C is not wrong
about liveness. The difference is where Clang chooses to materialise the
callee-saved copy, and this is the same class as the seven scheduling causes
already eliminated in `fp_scheduling.md`.

Two things to try, neither measured yet:

  * a copy hint at the top of the guarded block, the `+r` barrier the displaced
    address uses, so the register is chosen where retail chooses it
  * whether the frame-inside-branch form is reachable at all from C, or whether
    it is an artifact of how the original was compiled and only ever matched by
    spelling that happens to reproduce it

The first is a one-line experiment. The second is the question that decides
whether this population is reachable at all, and it is worth asking before
spending more on the first.


## Frame-inside-branch is NOT reachable from C. The guarded population is capped.

Question (2) from the last section, asked before spending more on question (1),
and it has an answer.

Retail sets the frame up inside the guarded block:

    cbz  w8, <ret>            <- the guard
    str  x19, [sp, #-0x20]!   <- the frame, AFTER the guard
    stp  x29, x30, [sp, #0x10]
    add  x29, sp, #0x10
    mov  x19, x0

That is SHRINK-WRAPPING: the prologue moves into the path that needs it. Clang
implements it, and it is enabled for aarch64, so the question is whether it fires
here. Two C shapes, measured:

    A   if (*(uint8_t*)((char*)a0 + 0x7c)) { g(*(void**)((char*)a0 + 0x58));
                                            *(uint16_t*)((char*)a0 + 0x7a) = 1; }
        return 0;

    B   if (*(uint8_t*)((char*)a0 + 0x7c)) { void *self = a0; ... }
        return 0;                     <- a0 copied INSIDE, dead after the guard

B is the shape shrink-wrapping needs: `a0` is dead once the guard has consumed
it, so the fallthrough needs no frame. **Both compile to the same code**, and
neither shrink-wraps:

    str  x19, [sp, #-32]!
    stp  x29, x30, [sp, #16]
    add  x29, sp, #16
    mov  x19, x0          <- the copy hoisted ABOVE the guard
    ldrb w8, [x19, #124]
    cbz  w8, ...

Clang hoists the copy and the frame in both. Its shrink-wrapping has a cost
threshold -- a tiny entry path is not worth duplicating the prologue for -- and
this is as small an entry path as there is: one byte load.

### So the population is capped, and the cap is measured

  * **8 bodies** match -- the ones with no callee-saved frame at all, where the
    frame is `stp x29,x30,[sp,#-N]!` and the guard skips it wholesale. Those
    banked as 5.
  * **The other 61 are not reachable from C** with the harness flags, because
    their distinguishing feature is a frame that Clang will not place inside a
    branch.

That is worth stating plainly rather than leaving as "61 still to try": the
remaining work is not a missing handler, a missing mnemonic, or a scheduling
hint. It is a codegen shape this toolchain does not produce, and the two
independent shapes that would express it were both measured and both refused.

There is one thing that would still be worth knowing, and it is cheap: whether
Clang shrink-wraps at ALL for this target with a longer entry path. If it does,
then this population is reachable but only for bodies big enough to cross the
threshold, and the right filter is body size rather than frame shape. If it does
not, the population is closed and the next 61 are not worth anything.

That is the next measurement, and it is the last thing this population needs.


## Shrink-wrapping does not fire for this target at all. The population is CLOSED.

Built a function designed to make it profitable -- six calls, arithmetic on their
results, and a deliberately rare guard, so the entry path is long and the frame
is expensive:

    u32 A(void *a0) {
      u64 x1 = load(a0,1), x2 = load(a0,2), ... x6 = load(a0,6);
      x1 += x2; x3 += x4; x5 += x6;
      if ((x1 ^ x3 ^ x5) == 0x1234567) { void *self = a0; ... }
      return 0;
    }

    0x00  stp x24, x23, [sp, #-64]!
    0x04  stp x22, x21, [sp, #16]
    0x08  stp x20, x19, [sp, #32]
    0x0c  stp x29, x30, [sp, #48]
    0x10  add x29, sp, #48
    ...
    0x90  b.ne #20            <- the ONLY conditional branch in the function

Every frame save is before the only branch. Clang hoisted the whole prologue,
five register pairs and all, past an entry path of six calls. It is not a cost
threshold: with this much prologue and this much entry path, shrink-wrapping
would pay enormously, and it still did not run.

So the answer to the question is yes-if-reachable, no in fact: **this toolchain
does not place a frame inside a branch for aarch64 at -O3 with the harness
flags**, and the 61 bodies whose distinguishing feature is exactly that are not
reachable. Not "not yet" -- measured, with the shape designed to trigger it, and
it did not fire.

### Where that leaves the guarded work

    123 guarded bodies
      5  banked
      8  have no callee-saved frame; the guard skips it wholesale
     61  need a frame inside a branch -- not reachable
     35  need a genuine sp local (an out-parameter)
      2+2+2  fsub, bfxil, sbfiz -- ordinary missing mnemonics

The last line is still worth 6 bodies and is ordinary work. The 35 are a real
feature -- a local whose address is taken, which the C is

    uint64_t slot;  g(&slot);  use(slot);

and which Clang places at a fixed sp offset by itself. The 61 are closed.

Nine beats went into this population: one shape matched, and the rest are now
known to be either ordinary work or outside what the compiler will emit. That is
a worse outcome than a number suggests and a better one than five more beats of
guessing would have been.


## The two ordinary mnemonics, done and measured

`bfxil` and `sbfiz` are the bitfield forms the list never carried -- `ubfiz` was
there and the signed insert was not, and a missing mnemonic reads as a missing
population rather than a missing handler.

Measured before trusting either:

    u32 B(u32 d, u32 v) { return (d & ~255u) | ((v >> 3) & 255u); }
        ->  bfxil  w0, w1, #3, #8            exact

    u32 A(u32 v) { return (u32)(((int32_t)(v << 24) >> 24) << 8); }
        ->  sbfiz  w0, w0, #8, #8           exact

The signed one needed a correction, and the measurement caught it rather than the
comparison. Written with the UNSIGNED type for the cast, the `>>` is a logical
shift, the extension is a zero-extend, and the result is

        ubfiz  w0, w0, #8, #8

which is the neighbouring mnemonic and compiles, links and matches nothing.
`S` (the signed type map) already existed; using it was the whole fix.

Effect: straight-line candidates 3154 -> 3191, call bodies 528 -> 530, and
neither mnemonic blocks anything anywhere in the four modules. Zero new matches,
because the populations behind them are the ones already measured exhausted --
but the reachable set is larger and two bodies that could not be translated can
now be, which is the precondition for any of the rest.


## Why the guarded emitter drops the guard, root-caused

`gen_guarded` asserts that the emitted source contains `if (`, and all 1,606
bodies it classifies decline. That assertion is the right shape -- a guard that
cannot show the thing it is generating is not finished -- but it is currently
refusing 6,418 reachable bodies, so here is why, measured.

Take `main+0x3dbed0`:

    add  x8, x0, w1, uxtw #3
    ldr  x8, [x8, #0x350]
    cbz  x8, #0x3dbee0      <- the guard, skipping the block
    strh w2, [x8, #0x8a]
    ret

which produced

    void f_x(void* a0, uint32_t a1, uint64_t a2) {
        void* p0 = ...; void* p1 = ...;
        *(uint16_t *)((char *)p0 + 138) = (uint16_t)a2;      <- no `if`
    }

### The guard machinery is NOT broken

Instrumenting `_emit` directly:

    _emit called with block = tuple (5, ['dict','int','int','tuple','str'])
    _gform = 'nz'   _gval = ('local', 'p1', 'void*')

`block` arrives as a well-formed 5-tuple, `_guard_test` resolved the condition and
its sense, and the guard index spaces agree (the pre-filter at line 653 and the
walk at line 912 both enumerate `body = insns[:-1]`). Everything up to the emit is
correct.

### Two ordering faults, both invisible because every banked guarded body is a CALL body

**1. The guarded emit sits after the `ret_val is None` early return.** This body
never writes x0, so `ret_val is None`, so `_emit` returned the statements
UNGUARDED and the test and both outcomes were deleted.

**2. `_call_txt` and `_ccut` are only created `if call_stmts:`.** The guarded emit
splices the call statements into the block, so it reads both. For a guarded body
with no call -- the commonest guarded shape there is, a void setter behind a field
test -- they do not exist.

Neither could show, because **all five guarded bodies banked so far are call
bodies**. They return a value, so they clear fault 1, and they make a call, so they
clear fault 2. The population that trips both faults is the population that was
never enumerated.

### The move is NOT a block move, and that is the trap

Moving the 69-line guarded block above the early return is the obvious fix and it
does not work. The guarded emit reads `rct`, `rexpr`, `plist`, `sig`, `all_txt`,
`_call_txt` and `_ccut` -- of which `rexpr` and `sig` are computed AFTER the
`ret_val is None` return, and `_call_txt`/`_ccut` conditionally. So the block has
to be placed after the return-type and narrowing work AND after the call rendering,
and before both early returns, and `rexpr`/`sig` have to be computed before it
rather than after.

That is a real ordering change with seven dependencies. It was attempted and
reverted in one beat rather than left half-applied: two dependency faults deep,
with the repository green and `gen_guarded`'s assertion holding, is a better place
to stop than a moved block that raises `UnboundLocalError`.

### The assertion stays either way

Until the emit is right, `gen_guarded` declines everything it classifies. Wrong C
into `prog/` is worse than no C, and the figure does not move either way until the
bytes match.
