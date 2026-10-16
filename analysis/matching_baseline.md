# Matching Baseline — pokesword-ai (own ELF)

First verified-match sweep against this fork's own `data/main.elf` (US v0):
**1,296 byte-identical matches** with the WSL clang 5.0.1 toolchain.

| shape | tried | matched | rate |
|---|---:|---:|---:|
| ret_only | 1226 | 1226 | 100% |
| setter | 254 | 6 | 2% |
| ptr_add | 45 | 9 | 20% |
| tailcall | 753 | 31 | 4% |
| mov_ret | 27 | 23 | 85% |
| getter | 109 | 1 | 1% |
| **total** | | **1,296** | |

## Working
- WSL clang 5.0.1 + stdint shim + match_harness fixes
- auto_match byte-verification against our ELF
- ret_only shape: 100% (1226/1226)

## Known gap
Getter/setter/copy generators mis-model the `x8` base register:
`orig ('ldr','x0,[x8,#8]') vs new ('ldr','x8,[sp]')` — parameter layout
guesses are wrong. Fixing these raises the mechanical shapes toward 100%.

## Next
- Wire the 97k Ghidra bodies (real signatures + C) through the same verifier
- Fix getter/setter x8 modeling
- Update progress numbers from the emitted body registry

## x8-declined bodies = human-level, not a mechanical gap

The getter/setter candidates declined by the x8 guard (bases/values in x8+,
the AArch64 indirect-result/IP0 register) turn out to be real middleweight
functions, not simple accessors:
- stack-frame zeroing bodies using `unaff_x29` (frame pointer)
- no-return panic thunks into `thunk_FUN_017e8ef0`
- hidden-`this` helpers reached by tail call

These need per-function understanding (the AI-assisted path), not generator
fixes. The guard prevents wrong answers; it does not hide matches.
