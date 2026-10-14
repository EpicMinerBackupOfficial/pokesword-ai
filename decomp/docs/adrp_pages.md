# What is actually in the `adrp` pages: 1,295 of them, not 105

The `adrp` population has been described as "105 pages" in several notes. That
number is wrong, or rather it is the count for one *subset* — the pages reachable
from the bodies `adrp_register.py` currently considers. The whole `main` module
references far more.

Directly, from `data/main.elf`:

    distinct adrp pages referenced from .text   1,295
    total adrp instructions                    191,343

## Getting the addresses right first

The section headers are **not** a usable address map in this file:

    section      sh_addr      sh_offset
    .text        0x0          0x1000        <- sh_addr is ZERO
    .rodata      0x17ed000    0x17ee000
    .data        0x236d000    0x236e000

`.text` has `sh_addr == 0` while the program headers put it at `p_vaddr 0`,
`p_offset 0x1000`. Anything that trusts `sh_addr` reads the ELF header instead of
code and reports "no `adrp` found" — which is exactly what happened on the first
attempt at this measurement. The program headers are the authority:

    PT_LOAD  vaddr 0x0000000000  off 0x000001000  filesz 25084512  R--
    PT_LOAD  vaddr 0x00017ed000  off 0x00017ee000  filesz 12057832  R--
    PT_LOAD  vaddr 0x000236d000  off 0x000236e000  filesz  1362704  RW

## What the pages contain

    mixed / structured        921
    pointer array             149
    text / string table       109
    unmapped (.bss, no file)   69
    all zeros                  40
    mostly zero (sparse)        7

Most-referenced pages:

    0x2496000  x25126  pointer array     ~.......~.......~...
    0x249b000  x12957  all zeros
    0x249d000  x9221   all zeros
    0x1b14000  x4762   mixed / structured
    0x1aa1000  x3330   mixed / structured   oseAccessPointEv._ZN2nn3ldn16Set

## Three things this changes

**1. The zeros are `.data`, and zeros are what folds.**
The 40 all-zero pages sit in `.data`, and a zero-initialised object is exactly the
case `tools/adrp_register.py` had to fight: a page whose contents the optimiser
can see is a page whose load can be deleted. That is why the declaration had to
drop `const` and why the page had to be sized — not a stylistic choice, a response
to what these pages actually contain.

**2. The string pages are RTTI, and that is a naming source.**
`0x1aa1000` holds mangled C++ type names (`...oseAccessPointEv._ZN2nn3ldn16Set`).
The ELF's own symbol table recovers a few thousand such names into function
symbols, but the `.rodata` copy is where the rest of the type information lives.
This is the only route to real class and method names in this module, and it is
in data the project currently treats as anonymous.

**3. The dominant page is a pointer array.**
`0x2496000`, referenced 25,126 times, is a table of pointers. A `uint64_t*` is the
correct declaration for it, and declaring it as `char[]` is what forces a byte-wise
access that costs an extra shift.

## Method note

The classifier reads bytes and counts: zero ratio, printable ratio, and how many
8-byte words land inside the module's own address range. No disassembler is needed
to learn that a page is a string table — Ghidra is needed only to name the fields
*inside* a structure, which is a later problem than knowing the page is structured.

Reproduce with `work/pageclass.py` (gitignored; the logic is 60 lines).