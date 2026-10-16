# AI Contribution Disclosure — pokesword-ai

This repository is an **AI-assisted decompilation fork** of
[`charlieduzstuf/pokesword`](https://github.com/charlieduzstuf/pokesword),
which is itself a decomp.dev-style project for **Pokemon Sword (US, v0)** built
on Game Freak's **"orion"** engine.

## What this fork does differently

The upstream project verifies every decompiled body by compiling C++ and
comparing against the original AArch64 bytes. **This fork does not claim that
standard.**

- Function bodies and analysis here are produced with the assistance of an
  automated agent (LLM) driving Ghidra's decompiler.
- Names, subsystem maps and pseudocode in `analysis/` are **AI-generated
  hypotheses**, not human-verified matches.
- Nothing here should be treated as a verified decompilation until it has been
  checked with the upstream tools (`tools/verify_matches.py`, `tools/audit.py`)
  and a human.

## Separation from upstream

- Our AI-produced artifacts live under `analysis/` and `docs/`.
- All raw Ghidra decompiler output stays in `work/` (gitignored) and is never
  published.
- We intentionally keep our AI-claimed work **separate from the upstream's
  verified match corpus** so nothing AI-produced can taint their verified
  results if we ever get something wrong.

## Legal note

No Nintendo firmware, game dump, console keys or raw decompiled binary bodies
are committed to this repository. See `.gitignore` — anything matching
`*.xci`, `*.nca`, `*.nsp`, `*.keys`, `*.elf`, `*.zip` or extracted firmware
trees is excluded by policy and verified by dry-run before every push.
