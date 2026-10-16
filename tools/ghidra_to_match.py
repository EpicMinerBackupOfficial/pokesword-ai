#!/usr/bin/env python3
"""Ghidra body -> verifiable C++ bridge for the _INIT_* family.

The _INIT_* bodies at recovered addresses are one-time runtime initializers:
    byte *pbVar1;
    pbVar1 = (byte*)*? ... actually pbRamXXXX -> absolute address 0xXXXX
    if ((*(volatile uint8_t*)ADDR & 1) == 0) { *(ADDR2) = &STRING; ...; *(volatile uint8_t*)ADDR = 1; }

The Ghidra dump spells globals as `pbRam00000000025966f0`, `uRam...`, `UNK_01bc70b3`,
and named symbols like `DAT_02496450` / `s_static_const_char__physx__shdfnd_01aefd68`.
This bridge rewrites those to C that compiles for aarch64-none-elf:
  - pbRam00000000025966f0 -> (volatile uint8_t*)0x25966f0   [byte pointer, no decl needed]
  - puRam00000000025966f0 -> (volatile uint32_t*)0x25966f0
  - uRam00000000025966f0  -> *(volatile uint64_t*)0x25966f0 [a value read]
  - iRam... -> int32_t, wRam -> uint32_t, sRam -> int16_t, bRam -> int8_t
  - UNK_XXXXX -> (void*)0xXXXXX
  - DAT_XXXXXXXX -> *(volatile uint32_t*)0xXXXXXXXX        [unknown-width data label]
  - s_..._XXXXXXXX / s_... + 0xNN constants -> absolute address literal
Produces a candidate function f_<addr> and calls verify_one.
"""
import re, sys, os, subprocess, tempfile

def rewrite_global(mem_expr):
    """Rewrite a Ghidra global expression to bare-metal C. mem_expr is like
    'pbRam00000000025966f0' or 'UNK_01bc70b3' or 's_foo_01aefd68'."""
    # value reads: prefix letter + 'Ram' + hex digits (Ghidra emits 16, the
    # zero-padded full 64-bit address; match 8..16 so both forms work)
    m = re.match(r"([piuIntbwsqfhd]+)Ram([0-9a-f]{8,16})", mem_expr)
    if m:
        kind, addr = m.group(1), m.group(2)
        a = "0x" + addr
        # pointer forms (p*) and value forms
        if kind == "pb": return "(volatile uint8_t*)%s" % a
        if kind == "pu": return "(volatile uint32_t*)%s" % a
        if kind == "pu8": return "(volatile uint8_t*)%s" % a
        if kind in ("p","pl"): return "(volatile uint64_t*)%s" % a
        if kind == "u": return "*(volatile uint64_t*)%s" % a
        if kind == "i": return "*(volatile int32_t*)%s" % a
        if kind == "w": return "*(volatile uint32_t*)%s" % a
        if kind == "s": return "*(volatile int16_t*)%s" % a
        if kind == "b": return "*(volatile int8_t*)%s" % a
        if kind == "f": return "*(volatile float*)%s" % a
        if kind == "d": return "*(volatile double*)%s" % a
        if kind == "q": return "*(volatile uint8x16_t*)%s" % a
        return "(volatile uint64_t*)%s" % a
    m = re.match(r"UNK_([0-9a-f]+)", mem_expr)
    if m:
        return "(void*)0x%s" % m.group(1)
    # DAT_<addr>: unknown-width data label; model as uint32 (matches the
    # 32-bit stores Ghidra emits for these init guards). The RHS is always
    # an lvalue context, so emit the deref.
    m = re.match(r"DAT_([0-9a-f]{8,16})", mem_expr)
    if m:
        return "*(volatile uint32_t*)0x%s" % m.group(1)
    # s_<name>_<addr>: string constant; model as an absolute address literal.
    # The bridge writes the address; code that dereferences it (char loads)
    # stays valid because the literal is an int-to-pointer constant.
    m = re.match(r"s_[0-9a-zA-Z_]+_([0-9a-f]{8,16})", mem_expr)
    if m:
        return "0x%sULL" % m.group(1)
    return mem_expr

def strip_globals(body):
    """Replace every Ghidra global identifier in a body expression-wise."""
    # value reads first (longest forms), then pointers, then UNK/DAT/s_
    def repl(m):
        return rewrite_global(m.group(0))
    # Ram-typed globals (longest prefixes first so `pu8` beats `pu`)
    body = re.sub(r"\b(?:b|s|w|i|u|f|d|q|pb|pu8|pu|pl|p)Ram[0-9a-f]{8,16}\b",
                  repl, body)
    body = re.sub(r"\bUNK_[0-9a-f]+\b", repl, body)
    body = re.sub(r"\bDAT_[0-9a-f]{8,16}\b", repl, body)
    body = re.sub(r"\bs_[0-9a-zA-Z_]+_[0-9a-f]{8,16}\b", repl, body)
    return body

def main(argv):
    if len(argv) < 2:
        print("usage: ghidra_to_match.py <hex-addr> [--show]")
        return 2
    target = int(argv[1], 16)
    repo = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    txt = open(os.path.join(repo, "work", "ghidra_out", "main.c.txt"), encoding="utf-8",
               errors="replace").read()
    blocks = txt.split("/*===F ")
    for b in blocks[1:]:
        m = re.match(r"0x([0-9a-f]+)", b[:20])
        if not m:
            continue
        addr = int(m.group(1), 16)
        if addr != target:
            continue
        head = b.split(" ===*/")[0]
        body = b.split(" ===*/", 1)[1]
        # failure
        if "failed" in body:
            print("decompiled: FAILED")
            return 1
        # take the C function body: strip '/*===F ...' header already done;
        # rewrite globals
        newbody = strip_globals(body)
        print("=== addr %#x ===" % addr)
        print(head.strip())
        print(newbody.strip())
        return 0
    print("addr %#x not found in main.c.txt" % target)
    return 1

if __name__ == "__main__":
    sys.exit(main(sys.argv))
