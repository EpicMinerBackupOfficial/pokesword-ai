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


## The tailcall population: 8,193 bodies with a straight-line prefix

The largest untouched class, and the first one that is not a control-flow problem.

    35,609 unverified tailcall bodies (the last instruction is `b <target>`)

But the `tailcall` shape only reaches 5,241 of them, all ALREADY REGISTERED:

    auto_match --shape tailcall
      main      5083 / 5083 = 100.0%
      sdk         72 /   72 = 100.0%
      subsdk0     28 /   28 = 100.0%
      subsdk1     58 /   58 = 100.0%
      registry +0 on every module

100% and nothing new, because the CLASSIFIER only claims a body when the whole
body is one `b`:

    if n == 1 and mn[0] == "b":
        return "tailcall"

Everything else that ends in `b` lands in the `branchy` bucket -- 61,774 bodies in
main alone, 76.8% of that module's unmatched. A straight-line argument setup
followed by a jump is not "branchy"; it is a tailcall that computes its arguments
first.

### Measured, and the prefix is the part that is already solved

    1,047  pure `b` thunks, already registered
  8,193  WITH a straight-line prefix

        sub                4,526
        ldr                  766
        add                  695
        mov                  456
        mov,mov              325
        mov,mov,mov          150

    main sub_12160@0x12160        main sub_12170@0x12170
      add  x2, x0, #0xec            ldr  w8, [x0, #0xb4]
      add  x3, x0, #0xe8            add  x8, x0, x8, lsl #4
      mov  w4, #1                  add  x1, x8, #0x18
      b    <target>                mov  w4, #1
                                    mov  x2, xzr
                                    mov  x3, xzr
                                    b    <target>

The C is

    uint64_t f(void *a0, ...) { return target(<prefix expressions>); }

and **the prefix expressions are what the general translator already computes** --
loads, adds, moves, all of it. The two things that are new are small:

  1. the classifier: a body ending in `b <target>` with a straight-line prefix is
     a tailcall, not `branchy`
  2. `gen_tailcall` forwards `a0..an` UNCHANGED, so it cannot express a prefix.
     It has to render the prefix and pass those expressions as the argument list.

Neither is a control-flow problem, which is what makes this the right next piece
after nine beats in one that was. 8,193 bodies is 5.4% of the figure -- more than
the last ten beats banked between them.


## The tail-call prefix, PROVEN byte-identical

The translator now has a `tail` mode. `translate(ident, tail=(name, arity))` takes a
body that ends in `b <target>` instead of `ret`, walks the prefix, and emits the
branch as the return:

    add  x2, x0, #0xec
    add  x3, x0, #0xe8
    mov  w4, #1
    b    target

becomes

    uint64_t f(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
        return g(((uintptr_t)(a0)), ((uintptr_t)(a1)),
                 ((uintptr_t)((char*)(a0) + 236)),
                 ((uintptr_t)((char*)(a0) + 232)), ((uintptr_t)(1)));
    }

and Clang's tail-call optimisation turns that `return` back into a branch:

    0:  add  x2, x0, #236
    4:  add  x3, x0, #232
    8:  orr  w4, wzr, #0x1
    c:  b    #0

Retail's four instructions, encodings included. The `b` is not a call -- it is
the RETURN, and the compiler produces it from the `return` alone.

### Four things that had to be right, and each was a silent failure

**1. The tail branch has to come BEFORE the `ret_val is None` early return.** A
tailcall whose prefix only sets up arguments has no stores and no call, so
`all_txt` is empty, and the early return produced `void f() {}` -- the body
silently dropped, with no error anywhere. The branch also has to come before the
`not all_txt` return. Two early returns, two times.

**2. The arity defines the parameters.** x0 and x1 are never READ by the prefix,
so the walk never marked them used and the signature came out with no parameters
for them:

    tail call argument x1 is neither written nor an incoming argument

A tail call FORWARDS argument registers, whether or not the body read them.

**3. The arguments are spelled like call arguments.** The prefix's pointer
arithmetic renders as `(char *)(a0) + 236` -- a `char *`, which does not convert
to `uintptr_t` in C++. `call_arg` already knows how to spell one; the tail path
has to use it.

**4. `b` is a terminator, not an instruction.** The body's last instruction is
the branch, so it is excluded from the walk, and the function has no `ret`.

### What is still needed, in auto_match

The translator is done and proven. Two things remain in `auto_match.py`:

  * the classifier: a body ending in `b <target>` with a straight-line prefix is
    a tailcall, not `branchy`
  * `gen_tailcall`: it forwards `a0..an` unchanged, so it has to render the
    prefix with the translator and pass those expressions as the argument list --
    and it needs the target's arity, which is the target's own signature

Neither is a control-flow problem, which is why this is the piece to pick after a
run of beats that were entirely about control flow and mostly about proving
things unreachable.


## The tail-call prefix: REACHED, generating, not yet verifying

Two beats ago the translator gained a `tail` mode and it was measured byte-identical
on one body. This beat the remaining plumbing is in and the population is counted:

    main         unmatched  80470   prefix tailcall  6487   pure thunk   8
    sdk           unmatched  20277   prefix tailcall   163   pure thunk   1
    subsdk0       unmatched   8794   prefix tailcall    28
    subsdk1       unmatched   9955   prefix tailcall   117
    TOTAL prefix tailcalls 6795, plus 1963 with a branch target that is not a
    recovered function (a further population, untouched)

`work/tail_why.py main` says where the 6,487 go in main:

    6467  GENERATED
      20  generator returned None
     108  target is not a recovered function

So the population is reachable and the generator expresses it. **Zero of them
verify yet**, and the reason is now named rather than guessed:

    MISS tailcall 0x1527c10  branch 0 goes to None, expected _Z15t_main_e7c4c0_1m

The expected symbol is right -- `t_main_e7c4c0` with arity 1, mangled with the
forwarded parameter. The relocation lookup on the compiled object misses, so the
candidate's branch list is empty and the comparison fails on the branch alone.
That is the last mile and it is a lookup question, not a codegen one.

### The per-arity target name

The target is declared in the batch head, and in C++ `uint64_t t_x();` means ZERO
parameters -- so a five-argument call is ill-formed. Two bodies tail-calling one
destination with different arities would also be two disagreeing declarations,
which is a redefinition and kills the whole translation unit. So the arity goes
into the symbol:

    t_<module>_<addr>        arity 0, the bare thunk, unchanged
    t_<module>_<addr>_<n>    arity n, declared `uint64_t t_x_n(uintptr_t, ...);`

`work/tail_population.py` shows the arity distribution: 1 dominates at 5,509,
then 2 (523), 3 (422), 4 (180), 5 (87), down to 8 (24). A one-argument tail call
is usually `add x0, x0, #imm ; b target` -- the single most common shape in the
whole unmatched set.

### The arity is a MENTION, not a write

`tail_arity` counts the highest argument register the prefix *mentions*, read or
written:

    add x2, x0, #0xec ; add x3, x0, #0xe8 ; mov w4, #1 ; b target

writes x2, x3, x4 and reads x0, so the call takes five. Counting only the written
registers would give three, and the incoming arguments would have nowhere to go --
which is the `tail call argument x1 is neither written nor an incoming argument`
bail, with no other explanation visible.


## The tail-call prefix: VERIFIED at 91%, blocked at the emit, not the codegen

The last mile was a single wrong index. `obj_relocations` is keyed by **offset
within the function**, and the lookup asked for offset 0 -- right for a bare thunk
whose whole body is one `b`, wrong for a prefix where the `b` is the last of
several instructions:

    mine_t = [relocs.get(mangled, {}).get(0)]              # wrong
    mine_t = [relocs.get(mangled, {}).get(4 * max(0, end - 1))]   # the branch

The expected symbol had been right all along. With the offset fixed:

    generated 11550 candidates
    MATCH 10543 / 11550 = 91.28%
    NOT already in registry: 5460

So 5,460 bodies in main are **verified byte-identical** by the harness. They are
also **not emitted**, and that is the gate working rather than a failure.

### Why they are not emitted

`retype_thunk` does not rewrite the verified source. It SYNTHESISES a bare thunk
and throws the argument setup away:

    verified   uint64_t main_f_13f40(void* a0) { return main::sub_16ff0((char*)a0 + 784); }
    emitted    void      main_f_13f40()             { main::sub_16ff0(); }

And the destination is a namespaced stub, declared by `proto_for` as
`namespace main { void sub_16ff0(); }` -- no parameters, void return. So a thunk
cannot forward one argument to it, and `return <void expr>` is ill-formed besides.

Letting them through anyway put **5,345 rows in the CSV whose decomp_name does not
exist in the built ELF**: the CSV recorded the verified signature
`_Z12main_f_13f40Pv` while the emitted body mangles to `_Z12main_f_13f40v`. The
audit caught it; that is what it is for.

### The figure went DOWN by 7, and that is the gate catching a real error

32,538 -> 32,531. Seven bodies were previously emitted as bare thunks while retail
had a prefix in front of the branch -- so the emitted body was one instruction
short of retail and was being counted as matching. `tail_target_ok` now declines
every record with `tail_nargs > 0` and those seven came out. A gate that only ever
goes up is not a gate.

### What unblocks 5,460 bodies, precisely

Not codegen. Three things, all in `decomp_project`:

  1. `retype_thunk` must REWRITE the verified source for a prefixed tail call --
     substitute the placeholder for the real definition name -- instead of
     synthesising a bare thunk.
  2. The destination stub needs a **per-arity signature**, so `proto_for` emits
     `namespace main { uint64_t sub_16ff0(uintptr_t); }` and `build_prog` emits a
     definition that agrees. Two thunks to one destination with different arities
     are the reason the arity has to be in the name.
  3. The thunk's arguments have to be spelled in the destination's parameter
     types, not `uintptr_t`. `((uintptr_t)(...))` does not convert to `void *` in
     C++, so a pointer-typed destination parameter needs the pointer spelling.

The verification already exists. Only the shipping path is missing.
