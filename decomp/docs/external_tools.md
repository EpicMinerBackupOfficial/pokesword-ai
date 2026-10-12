# External reverse-engineering tools, and why they are not on the critical path

Three external options were evaluated against the actual work, rather than by
their descriptions. Recorded so the question does not get re-derived.

## REA (`morluto/rea`) -- installed, registered, and blocked by target format

REA is an MCP server wrapping Ghidra, Hopper and IDA. Version 6.4.0 installed
cleanly and the MCP server starts (`node .../rea.mjs --mcp`). 170 tools are
offered to the agent.

It cannot analyse these binaries on this host, and the reason is not
configuration:

    ghidra:  not_configured            needs GHIDRA_INSTALL_DIR
    ghidra:  target_format_unsupported "Windows Ghidra P0 accepts PE targets only."
    hopper:  unsupported_host          macOS only
    ida:     not_configured            needs REA_IDA_MCP_CONFIG

The retail modules are **ELF / aarch64**. The Windows Ghidra build accepts PE
targets only, so installing Ghidra would not help: the rejection is the target
format, not the missing install. Hopper is macOS-only. IDA would need a separate
licence and an upstream MCP registration.

This closes the Ghidra question with evidence rather than inference. Ghidra would
emit C that Clang 5.0.1 must then recompile, and every gap this project has hit is
decided by Clang's addressing and linkage choices, not by whoever read the bytes:

  * `adrp` -- reachable from a *defined* symbol, not from `base + offset`
  * a `char[1]` global goes through the GOT; a `const` one does not
  * an indexed load is `ldr` or `add` purely by how the C is spelled

None of those is a question about reading the binary correctly.

## project-arceus (`nicoruedaa/project-arceus`) -- different game

Reported to have recently reached 100% function naming. It is Legends: Arceus.

    their range  0x190 .. 0x32a5680     68,330 functions
    our main     0x30  .. 0x17e8ee0   104,004 functions

813 shared addresses, of which **0.9%** agree on size. Its own function table
carries only Ghidra default names (`FUN_00000190`), so no names transfer. Its
comparison report concludes the two games share no engine classes, only Nintendo
SDK libraries.

What it did surface was that this repo already held `data/rtti_classes.csv` (1,873
class symbols with addresses) and `data/name_propagation.csv` (6,076 function
names), neither of which any tool read. Both are now used; see `apply_names.py`.

## Manual decompilation

Not applicable, and the census says why rather than it being a preference. Of the
corrected 1,707 mismatches, 6,433 of the original 7,158 had the *correct
instruction count* -- right length, wrong encoding. There is nothing to correct by
hand. The bodies that do differ are addressed by fixing the generator, which is
faster than transcribing and does not drift.

## Kept

REA stays installed and registered. It costs nothing, it will pick up new targets,
and `tools/register_rea_mcp.py` makes the registration reproducible. It is simply
not on the critical path for ELF/aarch64 on Windows.

    python tools/register_rea_mcp.py
