# Ghidra Corpus Assessment — pokesword-ai

97,043 decompiled bodies in `work/ghidra_out/main.c.txt` (gitignored, 144MB).

| Category | Count | Use |
|---|---:|---|
| Reference globals (`pbRam`/`puRam`/`UNK_`/`DAT_`) | 30,172 | human-level (need extern decls) |
| Direct calls (need callee decls) | 983 | human-level |
| Failed decompiles | 218 | none |
| Goto / jumptable / indirect | ~65k | complex, AI-assisted per-function |
| Leaf compile-ready | 0 | — |

## Verdict
The Ghidra bodies are **the raw material for per-function AI-assisted
translation** — not a bulk auto-match source. The cheap verified matches come
from `auto_match.py`'s mechanical shapes, which we already swept
(1,296 verified vs our ELF).

## Current mechanical-shape gap (highest-value fix)
`auto_match` getter/setter generators mis-model the `x8` base register:
```
orig ('ldr','x0,[x8,#8]') vs new ('ldr','x8,[sp]')
```
Fixing this lifts: setter 6/254 → ~250, getter 1/109 → ~100, ptr_add 9/45 → ~40.
≈ +370 verified matches.
