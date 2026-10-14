# Ghidra, REA, and why the module has no data names

## Ghidra installed and working on the ELF

`REA`'s provider table says:

    ghidra: target_format_unsupported  "Windows Ghidra P0 accepts PE targets only."

That is a **REA provider profile** restriction, not a Ghidra limitation. Ghidra
imports ELF natively on every platform, so it runs directly on Windows with Zulu
JDK 25 — no WSL needed.

    ghidra_12.1.4_PUBLIC
    analyzeHeadless <proj> pokesword -import data/main.elf -postScript DumpData.java

Import and post-analysis both succeed. The project's `-import` wrote a real Ghidra
database, so analysis is now a repeatable, scriptable step rather than a one-off.

Script errors are worth recording because both cost a run:

  * `ClassNotFoundException: DumpData not found` — the script did not compile.
    The real error is above it in the log (`cannot find symbol: class Listing`);
    the exception is the *symptom*. Look for `ERROR <Script>.java:` lines first.
  * `FileNotFoundException: Directory not found` — the **project directory** must
    already exist; `analyzeHeadless` creates the project file, not the directory.

After import succeeds, re-run scripts with `-process main.elf -noanalysis` rather
than re-importing. The analysis is the expensive part.

## What Ghidra independently confirms

    total symbols                     104,013
    functions                         104,004
    symbols inside .rodata                    1

That third line is the important one, and it is a **second, independent
confirmation** of the finding in `external_tools.md`: `.rodata` is 12 MB with one
symbol on it. Two unrelated readers of the same file — my own ELF parser and
Ghidra — agree.

    .text    0x0000000000-0x00017ec25f  25084512  r-
    .rodata  0x00017ed000-0x000236cce7  12057832  r-
    .data    0x000236d000-0x00024b9b0f   1362704  rw
    .bss     0x00024b9ff8-0x00027fdb3f   3423048  rw

Ghidra found **14,702 defined data items in `.rodata`, all of them strings.**

## What the strings reveal

    c:/projects/env/NintendoSDK/NintendoSDK/Libraries/NX-NXFP2-a64/Release//multimedia.nss
    c:/projects/env/NintendoSDK/NintendoSDK/Libraries/NX-NXFP2-a64/Release//glslc.nss
    __nnDetailNintendoSDKRuntimeObjectFile
    __nnmusl_fini_dso        __nnmusl_init_dso
    __rel_dyn_start         __rel_dyn_end
    __rel_plt_start         __rel_plt_end
    nndetailRoGetRoDataStart  nndetailRoGetRoDataEnd
    nnMain                  nninitStartup
    malloc calloc realloc abort memset memmove aligned_alloc
    __cxa_guard_acquire __cxa_pure_virtual

Build path confirms **Nintendo SDK NX-NXFP2-a64**, statically linked against a
musl variant, with dynamic-link bookkeeping symbols retained.

547 of these demangle to real C++ (`decomp/data/rodata_names.txt`): `nn::os`,
`nn::hid`, `nn::socket`, `nn::audio`, `nn::vi`, `nn::account`, `nn::bcat`,
`nn::prepo`, `nn::crypto`, `nn::fs`, `movie`, `nv`, and API-level names down to
`nn::os::LockMutex`, `nn::os::SignalEvent`,
`nn::audio::AcquireAudioDeviceNotificationForOutput`.

## Why they still cannot be attached to an address

None of those names is in `.symtab`. Checked directly:

    malloc, calloc, abort, memset, memmove, realloc, aligned_alloc,
    __cxa_guard_acquire, __cxa_pure_virtual, nnMain, nninitStartup,
    __nnmusl_init_dso, __rel_plt_start, nndetailRoGetRoDataStart   -- all absent
    _ZN2nn* / _ZNK2nn* / _ZN4nn* in .symtab: 0

**Root cause: `tools/nso_to_elf.py` discards the dynamic symbol table.** It writes
eight sections — `.text`, `.rodata`, `.data`, `.bss`, `.symtab`, `.strtab`,
`.shstrtab` — and rebuilds `.symtab` itself from `functions_eh.txt` (compiler
`-ffunction-sections` names), which are `sub_<addr>` or RTTI residue. There is no
`.dynsym`, no `.dynstr`, no `.rela.dyn`, no `.rela.plt` in the output.

So the names survive as a *string table* in `.rodata` — the linker kept the names
for its own bookkeeping — but with no `.dynsym` to map a name to an address, the
string is a name and nothing more.

The NSO files themselves would have `.dynsym` with names *and* addresses. They are
not on disk: `exefs/` holds only extracted `text.bin` / `rodata.bin`, and
`RecompSwordC.zip` (568 MB) is the C recomp source, not ROM data. **The
`.dynsym` route is therefore blocked on re-dumping the NSOs from the game**, which
is a data-acquisition problem, not a tooling one.

## What is unblocked without any of that

The mangled names encode **full signatures**, and those are usable now:

    _ZN2nn2os15QueryMemoryInfoEPNS0_10MemoryInfoE
        ->  nn::os::QueryMemoryInfo(nn::os::MemoryInfo*)
    _ZN2nn2os16GetCurrentThreadEv
        ->  nn::os::GetCurrentThread()

Return type, class, parameter count and parameter types are all in the mangling.
The prototype search in `call_register.py` has been *guessing* among `nargs`/`ret`
variants for every callee; for anything that resolves to one of these 515 `nn::*`
entries the guess is unnecessary. That is the concrete use, and it needs no
provider, no Ghidra database and no NSO.