#!/usr/bin/env python3
"""Verify banked bodies straight from the built ELF, without match_harness.

Why this exists: every large gain in this project was at some point measured by a
tool that could not see its own failure. `match_harness` is the authority for
MATCHING, but it is also a large piece of machinery, and a defect in it reads
identically to a defect in the decomp. This instrument shares no code with it. It
reads:

  * the retail bytes out of `work/<mod>/text.bin`
  * the address and size out of the ELF symbol table
  * the rebuilt bytes out of the disassembly of `build/<mod>.elf`

and compares them. If this agrees with the harness, the bank is real; if it
disagrees, the harness is the suspect.

THE BRANCH IMMEDIATIVE IS MASKED, and that is the whole subtlety. A tail call's
last word is a branch, and a branch immediate encodes a BYTE OFFSET -- so it can
never match between two images laid out differently:

    retail  00 40 0c 91  2b 0c 00 14      add x0, x0, #0x310 ; b 0x16ff0
    built   00 40 0c 91  fb 51 fb 17      add x0, x0, #0x310 ; b 0x5a0220

Retail branches to the original function; the rebuild branches to the overload
stub emitted for it. The PREFIX -- the part the tail-call work was about -- is
byte-identical, and a raw byte comparison calls that a difference on every body.

Usage:
    python tools/verify_elf_bank.py --module main
    python tools/verify_elf_bank.py --module main --limit 40
    python tools/verify_elf_bank.py --module main --addr 0x13f40
"""

import argparse
import bisect
import csv
import io
import json
import os
import subprocess
import nocon  # noqa: E402  -- installs the no-console default for every subprocess below
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOL = os.environ.get("POKESWORD_OBJDUMP",
                      r"C:\llvm-5.0.1\bin\llvm-objdump.exe")

# AArch64 unconditional branch: the top 6 bits of the word are 000101.
BR_TOP6 = 0b000101


def _run(*args):
    r = subprocess.run([TOOL] + list(args), capture_output=True, text=True,
                       encoding="utf-8", errors="replace")
    return r.stdout


def sym_addr_size(elf, sym):
    """(address, size) from the symbol table.

    The row is [addr, bind, type, section, size, name] -- the SIZE is field 4.
    Field 2 is the `F` type letter, and reading the size from there yields 15 for
    every symbol, which silently compares three instructions instead of two.
    """
    for line in _run("-t", elf).splitlines():
        p = line.split()
        if len(p) >= 6 and p[-1] == sym:
            return int(p[0], 16), int(p[4], 16)
    return None, None


def code_at(elf, addr, size):
    """`size` bytes of .text at `addr`, read out of the disassembly.

    Two dialects, both learned the hard way:
      * the disassembly prints UNPADDED addresses (`6cba30:`), so the field width
        varies and cannot be compared against a fixed length
      * a line is `addr:\\t<bytes>\\t<mnemonic>\\t<operands>`, so the part after
        the first colon STARTS with a tab; splitting on tab and taking index 0
        gives the empty string, every byte conversion then raises, and the result
        is no bytes at all -- which reads as "the build is empty" rather than
        "this probe is broken"
    """
    want = size // 4
    out = bytearray()
    for line in _run("-d", elf).splitlines():
        s = line.strip()
        if ":" not in s:
            continue
        head, rest = s.split(":", 1)
        head = head.strip()
        if not (1 <= len(head) <= 16):
            continue
        if not all(c in "0123456789abcdef" for c in head):
            continue
        if int(head, 16) < addr:
            continue
        fld = next((x for x in rest.split("\t") if x.strip()), "")
        try:
            out += bytes(int(b, 16) for b in fld.strip().split()[:4])
        except ValueError:
            break
        if len(out) // 4 >= want:
            break
    return bytes(out[:size])


def mask_branch(b):
    """Drop a trailing branch word. Returns (bytes, was_a_branch)."""
    if len(b) >= 4 and (int.from_bytes(b[-4:], "little") >> 26) == BR_TOP6:
        return b[:-4], True
    return b, False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", default="main")
    ap.add_argument("--limit", type=int, default=12)
    ap.add_argument("--addr", type=lambda s: int(s, 0), default=None)
    args = ap.parse_args()

    mod = args.module
    elf = os.path.join(ROOT, "build", "%s.elf" % mod)
    retail_path = os.path.join(ROOT, "work", mod, "text.bin")
    for p in (elf, retail_path):
        if not os.path.exists(p):
            print("  missing %s -- run tools/build_nx64.py first" % p)
            return 2

    retail = open(retail_path, "rb").read()
    reg_path = os.path.join(ROOT, "data", "matched_%s.json" % mod)
    if not os.path.exists(reg_path):
        print("  missing %s" % reg_path)
        return 2
    d = json.load(io.open(reg_path, encoding="utf-8"))
    recs = d["matched"] if isinstance(d, dict) else d

    csv_path = os.path.join(ROOT, "data", "functions.csv")
    decomp_of = {}
    if os.path.exists(csv_path):
        for r in csv.DictReader(io.open(csv_path, encoding="utf-8")):
            if r["module"] == mod and r["decomp_name"]:
                decomp_of[int(r["addr"], 16)] = r["decomp_name"]

    pool = sorted((r for r in recs
                   if r.get("shape") == "tailcall"
                   and int(r.get("tail_nargs") or 0) > 0),
                  key=lambda r: r["addr"])
    if args.addr is not None:
        pool = [r for r in pool if r["addr"] == args.addr]
    elif args.limit and len(pool) > args.limit:
        # Sample across the address space, not the first N: the first N of a
        # sorted list are one cluster, and a cluster is not a sample.
        step = len(pool) // args.limit
        pool = pool[::step][:args.limit]

    ok = bad = miss = 0
    for rec in pool:
        a = rec["addr"]
        sym = decomp_of.get(a)
        if not sym:
            miss += 1
            print("  NOSYM @%#-12x no decomp_name in the CSV" % a)
            continue
        sa, ss = sym_addr_size(elf, sym)
        if sa is None or ss <= 0:
            miss += 1
            print("  NOELF @%#-12x %s is not in the ELF" % (a, sym))
            continue
        want = retail[a:a + ss]
        got = code_at(elf, sa, ss)
        wm, wbr = mask_branch(want)
        gm, _ = mask_branch(got)
        same = len(want) == ss == len(got) and wm == gm
        print("  %s @%#-12x %-28s retail %s  built %s%s" %
              ("OK  " if same else "DIFF", a, sym,
               want.hex(" ") or "<none>", got.hex(" ") or "<none>",
               "   (branch immediate masked)" if wbr else ""))
        ok += same
        bad += not same

    print("")
    print("  %d sampled: %d identical, %d differing, %d unresolvable"
          % (ok + bad + miss, ok, bad, miss))
    return 0 if bad == 0 and miss == 0 else 1


if __name__ == "__main__":
    sys.exit(main())