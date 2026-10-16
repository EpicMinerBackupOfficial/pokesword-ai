# Decompile Status — main module (pokesword-ai)

## Bulk decompile complete: `main` module

**97,043 function bodies** decompiled via the parallel Ghidra + AI loop
(`work/ghidra_out/main.c.txt`, 144 MB) plus 23,529 already-matched (skipped).

### Method
- All 104,004 recovered boundaries from `data/functions_main.csv` created as
  functions in the live Ghidra session (107,659 total with aliases).
- `SliceDecompile` (resumable via `.done` sidecar) ran the decompiler over
  every non-matched function in budgeted slices.
- Throughput ~80-200 fn/s on the heavy control-flow bodies; failures <0.1%.

### Result
- Every non-matched `main` function now has a real signature + C-like body.
- This is **raw material for the matching pipeline**, not verified matches.

### Next
- Feed the bodies through `tools/auto_match.py` / `tools/call_match.py` to
  convert them into byte-identical matches (the actual progress metric).
- Repeat the pipeline for `sdk` / `subsdk0` / `subsdk1`.

### How to reproduce
```
# (in a Ghidra session holding data/main.elf with functions created from csv)
# run SliceDecompile with the .done sidecar until new=0
```
