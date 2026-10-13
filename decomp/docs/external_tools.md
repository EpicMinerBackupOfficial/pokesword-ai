# External reverse-engineering tools, and why they are not on the critical path

Three external options were evaluated against the actual work, rather than by
their descriptions. Recorded so the question does not get re-derived.

## REA (`morluto/rea`) -- installed, registered, opens the target, cannot analyse it

REA is an MCP server wrapping Ghidra, Hopper and IDA. Version 6.4.0 installed
cleanly and the MCP server starts (`node .../rea.mjs --mcp`). 170 tools are
offered to the agent.

**Correction (measured, supersedes an earlier note here).** This section previously
said REA "cannot analyse these binaries on this host". That conflated two different
things, and the distinction matters because it is easy to re-derive the wrong
answer from the wrong field.

`binary_session` returns `tool_availability`, an array of 170 entries each carrying
a `reason` and a **`remediation`**. The remediation for the ELF operations reads
"Call open_binary with a supported local target." Following it:

    open_binary  data/main.elf
      ->  format=elf  kind=executable  architecture=arm64
          sha256=b7e98932e007572239c3076b84a52399ea9118a5c656cc3a21c01f77de8b22a9

**REA opens the ROM-derived AArch64 ELF and independently confirms it.** The earlier
"pwntools artifact profile supports Linux x64 only" is an *analysis* restriction, not
an opening restriction -- opening is host-independent and succeeded. So REA is usable
here as an independent digest and format witness, which is worth having.

Analysis remains blocked, and the provider table says precisely why:

    ghidra:  not_configured            needs GHIDRA_INSTALL_DIR
    ghidra:  target_format_unsupported "Windows Ghidra P0 accepts PE targets only."
    hopper:  unsupported_host          macOS only
    ida:     not_configured            needs REA_IDA_MCP_CONFIG

The retail modules are **ELF / aarch64**. The Windows Ghidra build accepts PE
targets only, so installing Ghidra would not help: the rejection is the target
format, not the missing install. Hopper is macOS-only. IDA is the only provider
blocked on configuration rather than on capability, and it needs a separate licence
plus an upstream MCP registration.

This closes the Ghidra question with evidence rather than inference. Ghidra would
emit C that Clang 5.0.1 must then recompile, and every gap this project has hit is
decided by Clang's addressing and linkage choices, not by whoever read the bytes:

  * `adrp` -- reachable from a *defined* symbol, not from `base + offset`
  * a `char[1]` global goes through the GOT; a `const` one does not
  * an indexed load is `ldr` or `add` purely by how the C is spelled

None of those is a question about reading the binary correctly.

## The ROM-derived ELF has no data symbols -- the `adrp` pages cannot be named

Read directly from `data/main.elf` (40 MB, 8 sections, gitignored; rebuild with
`tools/nso_to_elf.py`), by parsing the section and symbol tables:

    .text    0x000000  25,084,512
    .rodata  0x17ed000 12,057,832
    .data    0x236d000  1,362,704
    .bss     0x24b9ff8  3,423,048
    .symtab            104,008 entries, 104,008 named, 104,007 with a size
    .strtab            1,256,048

Every one of those 104,008 symbols is `STT_FUNC` (kind 2); the file also holds one
`STT_FILE` and three `STT_SECTION`. 8,252 of the names are not `sub_*` -- they are
recovered RTTI/string residue such as `gflib3_signal_template_hpp_394_15_name_T`
and `static_const_char_boost_detail_core_typeid__void_const_v`.

**Not one symbol has a data address.** Filtering to symbols at or above `.rodata`
yields exactly two, both synthesised by the ELF writer:

    _rodata_start  0x17ed000  12,057,832
    _data_start    0x236d000   1,362,704

So `.rodata` and `.data` are 13.4 MB of anonymous bytes. The 105 distinct `adrp`
pages the bodies reference have no names, no sizes and no section-level
attribution finer than "rodata" or "data". This is a property of the shipped
modules, not of the tooling, and it holds for every provider REA could bind. Any
plan that assumes the data pages can be given real symbols -- from REA, from the
NSO, or from the ELF -- is assuming something that is not there. They have to be
synthesised, which is what `adrp_register.py` does, and why its declaration form is
load-bearing (see `register_offset.md`).

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

## Kept, and now actually scoped

`tools/rea_caps.py` asks REA itself what it can do on this host, rather than
restating a conclusion. The answer is a partition, and it is worth having exactly:

    18 capabilities reported
     8 available   decode_interface_builder, extract_artifact,
                   inspect_artifact, inspect_keyed_archive,
                   inspect_managed_artifact, inspect_managed_members,
                   inspect_managed_native_boundaries, trace_dylib_resolution
    10 blocked     9 need macOS ("Native macOS utilities require macOS")
                   1 needs macOS assetutil

**None of the 8 available capabilities reads ELF code, names, or symbols.** The one
ELF provider is `pwntools-elf`, and calling `inspect_binary_layout` on the retail
image returns it verbatim:

    capability_unavailable / unsupported_provider
    "The initial real-verified pwntools artifact profile supports Linux x64 only."

So the earlier conclusion stands, but it is now scoped to a specific refusal rather
than a general impression -- and it is a **host and target-format** limit, not a
configuration one. Installing more providers on this machine would not produce an
AArch64 ELF analyzer.

### Where REA does earn its place

`open_binary` works on the retail images and reports format, kind, architecture and
a SHA-256. That makes it usable as an **independent provenance check**: every other
integrity check in this repo is written by the same project that produced the
files, so agreement between REA's hash and a local hash is outside confirmation that
`data/<mod>.elf` is still the retail extraction and `build/<mod>.elf` is our rebuild.

    python tools/rea_provenance.py

    data/main.elf        elf  arm64  AGREE  b7e98932e0075722
    data/rtld.elf        elf  arm64  AGREE  e1c8b6b3f4477fa8
    data/sdk.elf         elf  arm64  AGREE  8812301264a7006a
    data/subsdk0.elf     elf  arm64  AGREE  f555ffa5ee08cf76
    data/subsdk1.elf     elf  arm64  AGREE  4cecfa889766bc8b
    build/main.elf       elf  arm64  AGREE  6a141534938bc4b5
    build/prog.elf       elf  arm64  AGREE  e807167502a06a76
    build/rtld.elf       elf  arm64  AGREE  ccc9a5adaa72332a
    build/sdk.elf        elf  arm64  AGREE  70e249e46fafe554
    build/subsdk0.elf    elf  arm64  AGREE  baa633cdbb88f190
    build/subsdk1.elf    elf  arm64  AGREE  80cac89b66fbb03d

    11/11 agree. Recorded in data/rea_provenance.json.

That is a small result and it is stated as one. REA does not decompile anything
here.

### Driving it, given the catalogue problem

Two of the three ways of asking REA about itself disagree:

    claude mcp list      ->  "Failed to connect"   (health check, short timeout)
    claude mcp get rea   ->  "Connected"           (reads config, connects nothing)
    real handshake       ->  rea 6.4.0, 170 tools  (newline-delimited JSON)

and the host MCP catalogue is documented as partial and no longer lists the `rea`
namespace at all, so `search` returns nothing for it and `tools.rea.*` is not
callable from a code session. Hence two small clients rather than a dependency on
either:

    python tools/rea_handshake.py     # prove it is alive; dumps all 170 tool schemas
    python tools/rea_call.py list     # call any REA tool directly over stdio
    python tools/rea_call.py call open_binary '{"path":"C:\\...\\data\\sdk.elf"}'

Registration is in both hosts: opencode via `tools/register_rea_mcp.py`, and Claude
at user scope, which had **no MCP servers configured at all** until now:

    claude mcp add --scope user rea -- \
      "C:\Program Files\nodejs\node.exe" \
      "C:\Users\charl\AppData\Roaming\npm\node_modules\rea-agents\scripts\rea.mjs" --mcp

Absolute paths are required. `rea mcp add` fails on this machine with
`spawn npx ENOENT`, which is the same reason `npx`-based entries do not resolve.
