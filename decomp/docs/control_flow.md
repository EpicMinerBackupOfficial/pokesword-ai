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

821 bodies for this shape alone, and the same mechanism extends to the wider
10,396-body conditional population.
