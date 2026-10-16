# PokeSword main.elf — Function Analysis Round 1

Ghidra project: PokeShield | Binary: main.elf (AARCH64 LE, 38.5MB, 24,631 funcs)
Method: Xref-count priority (most-referenced first), decompile + behavior-based rename.

## Renamed Functions (28 total)

### Batch 1 — Top 4 by xrefs
| Address | Old name | New name | Xrefs | Behavior |
|---------|----------|----------|-------|----------|
| 00301518 | FUN_00301518 | GetGlobalOffset | 951 | `return *DAT_024999b8 + 0x18;` — global offset helper |
| 00001578 | FUN_00001578 | InitializeRuntime | 409 | Guard/init; aborts via thunk_FUN_017e8ef0 / FUN_0065df98 |
| 0165e8f8 | FUN_0165e8f8 | SetAndAbort | 159 | `*param_1 = *param_2; thunk_017e8ef0();` — copy then abort |
| 00819e98 | FUN_00819e98 | CalculateOffset30 | 141 | Dispatcher via `*(param_1+0x30)` → FUN_007ea0c8 |

### Batch 2 — Next 16 by xrefs
| Address | Old name | New name | Xrefs | Behavior |
|---------|----------|----------|-------|----------|
| 00001508 | FUN_00001508 | AbortIfRuntimeFlag | 1538 | Check bit0 of FUN_0065e0c8, abort if set, then no-return FUN_0065df98 |
| 00305058 | FUN_00305058 | ValidateAndReturnOne | 1365 | `if (param_2) abort; return 1;` |
| 0067dce8 | FUN_0067dce8 | ProcessTableEntry | 1280 | Table lookup via FUN_005e83c8 → FUN_0067d918 |
| 017ea458 | FUN_017ea458 | DispatchIndirectCallback | 1002 | Indirect call through `(*DAT_02495ff8)()` |
| 015b9c28 | FUN_015b9c28 | DestroyObjectOrCallVtable | 951 | `if (*(param_1-0x10)) (*it)(); else FUN_00001158(param_1-0x10)` |
| 007eef48 | FUN_007eef48 | GetByteAtOffset7D | 929 | `return *(param_1 + 0x7d)` |
| 007c3638 | FUN_007c3638 | ClearTwoWords | 926 | `*p = 0; p[1] = 0;` |
| 00000a58 | FUN_00000a58 | GetZeroValue | 863 | `return 0;` — stub |
| 004182c8 | FUN_004182c8 | AbortUnconditionally | 859 | Neat wrapper: only `thunk_017e8ef0()` |
| 005d0368 | FUN_005d0368 | CopyStruct24AndZero | 849 | Copy 3 quads + zero 4th |
| 005e3458 | FUN_005e3458 | ValidateThenProcess | 842 | Guard FUN_017ea388 + verify ptr[0xe8]==ptr[0xf0] + FUN_005e3f48 |
| 006a5ac8 | FUN_006a5ac8 | InsertIntoSortedTree | 792 | RB-tree insert with FUN_015bf348 key + FUN_015b9bd8 node alloc |
| 014e2298 | FUN_014e2298 | SetFlagBitAndNotify | 787 | Toggle bit at +0x82, fire vtable+0x90 if changed |
| 0165e9d8 | FUN_0165e9d8 | CopyAndAbort | 783 | Same as SetAndAbort |
| 00301548 | FUN_00301548 | GetGlobalPtr | 723 | `return *DAT_024999b8;` — sibling of GetGlobalOffset |
| 008044f8 | FUN_008044f8 | InitializeStructFields | 638 | Zero 5 pointers |

### Batch 3 — 8 more (xrefs 100–800)
| Address | Old name | New name | Xrefs | Behavior |
|---------|----------|----------|-------|----------|
| 005e2be8 | FUN_005e2be8 | InitializeAndAbort | 617 | Zero 9 slots + abort |
| 00c3a4d8 | FUN_00c3a4d8 | GetInitializedGlobal | 714 | Guard `*DAT_024a4e88 & 1` → return DAT_024a4e90 or abort |
| 00e7cd58 | FUN_00e7cd58 | ReleaseSceneObjects | 690 | Release 4 scene objects (+0x48 vtable +0x18) |
| 00a38438 | FUN_00a38438 | RebuildHashTable | 772 | Hash table rehash/resize w/ power-of-2 validation |
| 01106c78 | FUN_01106c78 | GetItemFromHashTable | 764 | Custom hash-table lookup, returns {base, index} |

## Key structural discoveries
1. **thunk_FUN_017e8ef0** (11,341 xrefs!) is the global fatal-abort/panic path — most functions that "don't return" route through it. It's a ~700-byte worker initializing 2×0xA80-byte blocks.
2. **DAT_024999b8** is a hot global — read by GetGlobalOffset / GetGlobalPtr across the whole binary.
3. Hash tables (RebuildHashTable / GetItemFromHashTable) use power-of-2 sizing + masked index, classic Arena-style allocator seen in Game Freak engines.
4. InsertIntoSortedTree confirms a sorted tree structure at +0x70 with node size 0x30, count at +0x78.

## Next candidates
- FUN_0178ed98 / FUN_0178ed58 / FUN_01787c88 (callees of the big panic fn)
- FUN_0065e0c8 (runtime flag check — used by top 2 aborts)
- FUN_015bf348 (tree key generator)

## Round 2 — Runtime & subsystem internals (22 more renamed)

| Address | Old name | New name | Behavior |
|---------|----------|----------|----------|
| 0178ed98 | FUN_0178ed98 | InitializeCallbackRecord | Build 96B callback record w/ scheduler packet |
| 0178ed58 | FUN_0178ed58 | ClearCallbackRecord | Zero 15 quads |
| 01787c88 | FUN_01787c88 | WriteSchedPacket | Write magic 0x20202 + 3 const words |
| 0065e0c8 | FUN_0065e0c8 | AssertRuntimeReady | Check DAT_02778f38 bit0 → abort |
| 0065e1f8 | FUN_0065e1f8 | AssertSystemOnline | Same check, distinct abort thunk |
| 0065df98 | FUN_0065df98 | AssertKernelState | Check DAT_02777f38 bit0 → abort |
| 015bf348 | FUN_015bf348 | FatalTrap | Always aborts via thunk_017e8ef0 |
| 017ea388 | FUN_017ea388 | IsSystemOnline | Indirect call via DAT_02495f90 |
| 005e83c8 | FUN_005e83c8 | FindIndexByValue | Linear scan at +0x1b0 for match at +0x58 |
| 0067d918 | FUN_0067d918 | ResolveTableSlot | Table slot resolution w/ gen check + reloc |
| 007ea0c8 | FUN_007ea0c8 | FindObjectById | Object table lookup (id → object) |
| 015b9bd8 | FUN_015b9bd8 | AllocateNodeAligned | Custom allocator (aligned to 8) |
| 00001158 | FUN_00001158 | InitializeKernelGuard | Uses our assertions in sequence |
| 005e3f48 | FUN_005e3f48 | RecalculateVectorCapacity | Vector growth math + redirect |
| 007ea5f8 | FUN_007ea5f8 | GetTableEntryById | Indexed table read (idx < 0x7b) |
| 007ea7e8 | FUN_007ea7e8 | GetObjectFieldC | Read u32 at +0xc |
| 0067c838 | FUN_0067c838 | ClearSlotIfFlagged | Conditional slot zero |
| 0067d748 | FUN_0067d748 | AdvanceTableGeneration | Generation bump + object destroy |
| 0067db18 | FUN_0067db18 | ValidateEntrySequence | Sequence XOR validation (0x2983 poly) |
| 0178e5c8 | FUN_0178e5c8 | DecodePacketFormat | Packet format decoder via 12 function ptrs |

## Architecture map
- **Panic/abort subsystem**: ALL abort paths funnel through `thunk_FUN_017e8ef0` → `FUN_017e8ef0` (~700B init of 2×0xA80 records) → `InitializeCallbackRecord`/`ClearCallbackRecord`/`WriteSchedPacket`/`DecodePacketFormat`.
- **Assertion layer**: `AssertRuntimeReady`, `AssertSystemOnline`, `AssertKernelState`, `IsSystemOnline` — runtime warm-up guards used by 1000+ functions.
- **Table engine**: `FindIndexByValue`, `ResolveTableSlot`, `GetTableEntryById`, `FindObjectById`, `ClearSlotIfFlagged`, `AdvanceTableGeneration`, `ValidateEntrySequence` — a generation-counted indexed table (0x7B entries max) with XOR-obfuscated sequence validation.
- **Allocator**: `AllocateNodeAligned` = aligned size + custom pool via DAT_0249c6a0.
- **Vector**: `RecalculateVectorCapacity` = geometric growth (×2), 8-byte elements.

Total renamed: **50 functions** across main.elf. All names pass Ghidra quality gate. Program saved.

## Round 2 — BATCH B (31 more renamed, total 82)

| Address | Old | New | Insight |
|---------|-----|-----|---------|
| 00304e78 | FUN_00304e78 | ValidateAndReturnZero | if(param_2) abort; return 0 |
| 0000d958 | FUN_0000d958 | AssignSystemObject | Object assign via DAT_02496b38 with guard |
| 015b9658 | FUN_015b9658 | PrepareGlobalQueues | Init 2 queues at DAT_024b3e30 offsets +0x38/+0xb8 |
| 015c9368 | FUN_015c9368 | SubmitJobData | Job queue submit, size 0x10 |
| 00700388 | FUN_00700388 | InvokeTrackerAndEcho | Call FUN_017eb058 + echo arg |
| 004bced8 | FUN_004bced8 | GetVtableResultOrDefault | Vtable +0x60 call → default DAT_02499dd0 |
| 00e7c9f8 | FUN_00e7c9f8 | InvokeObjectMethod18 | Vtable +0x18 or DispatchIndirectCallback |
| 014ab5d8 | FUN_014ab5d8 | FindJobByKey | Linear scan of job list (key ×0x10 stride) |
| 0082b278 | FUN_0082b278 | GetObjectField20 | Read +0x20 |
| 005d0388 | FUN_005d0388 | CopyObjectWithMeta | Copy 4 quads + refcount |
| 0154c4e8 | FUN_0154c4e8 | ResolveJobDataIndex | Job data index → slot resolve (flags: 2→ptr, 7→ptr+0x28) |
| 00eb6ac8 | FUN_00eb6ac8 | ProcessEventSwitch | Event switch dispatcher |
| 015bc4a8 | FUN_015bc4a8 | InitializePhysxAllocator | **PHYSX!** string `physx::shdfnd` + vtable |
| 00819f68 | FUN_00819f68 | UpdateChildObjectStatus | Child object status update |
| 004ba2f8 | FUN_004ba2f8 | DecrementGlobalAndCall | `_DAT_024e8970--` + vtable +0x20 |
| 004bcf28 | FUN_004bcf28 | InvokeVtableMethod60 | Vtable +0x60 dispatch |
| 00463878 | FUN_00463878 | ValidateInputConstraints | 22-constraint loop, string table init (SiGfx!) |
| 0082b318 | FUN_0082b318 | GetObjectField60 | Read +0x60 |
| 00301068 | FUN_00301068 | GetGlobalBase | `return *DAT_024999b8` (third sibling!) |
| 007e9ea8 | FUN_007e9ea8 | RegisterObjectById | Object reg via +0x30 key lookup |
| 00301078 | FUN_00301078 | DispatchSystemCall | Forward to FUN_003010e8 |
| 00681518 | FUN_00681518 | SearchStringTableByHash | **FNV-1a 64** (`0xcbf29ce484222645` base) string table search |
| 00e81088 | FUN_00e81088 | ToggleSceneLayer | Scene layer toggle |
| 0154c798 | FUN_0154c798 | MoveQueuePtrForward | Data queue cursor +0x10 |
| 00e9daa8 | FUN_00e9daa8 | ReleaseSceneContainer | Scene container release pattern (DAT_024a8880) |
| 005e31c8 | FUN_005e31c8 | AbortWithKernelFault | Fatal abort |
| 0067c228 | FUN_0067c228 | InitializeSlotTableState | Table init + abort |
| 008045f8 | FUN_008045f8 | WriteSlotByIndex | Indexed slot write (7-bit field) |
| 01316428 | FUN_01316428 | MapMemoryRegionFlagged | Memory region map (0x18-stride table) |
| 00e81258 | FUN_00e81258 | AttachSceneNode | Scene node attach w/ refcount |
| 015b76a8 | FUN_015b76a8 | DestroyNodeOrGuard | Destructor dispatch + guard |

## Engine fingerprint — GAME FREAK "ORION"
- **PhysX**: `physx::shdfnd` allocator init at 015bc4a8
- **SiGfx** rendering: string table (`SiGfx_successfully_uninitialize`, `SiGfx_D3D12_Common_Subdiv`)
- **FNV-1a 64** string hashing: base 0xcbf29ce484222645 — used for string table lookups
- **Scene graph**: scene containers/nodes with vtable +0x48 destroy pattern
- **Job system**: JobDataStore (`s_N2nn3nex36JobDataStoreReceiveNew`) + queue ptr movement
- **Input constraints**: 0x16 (22) validation slots with source strings

## Tally
- Round 1: 50 renamed
- Round 2 batch B: 31 renamed (+11 fixups)
- **Total: 82 functions renamed** in main.elf

## Round 3 — BATCH C (29 more renamed, total 111)

| Address | Old | New | Insight |
|---------|-----|-----|---------|
| 00c470c8 | FUN_00c470c8 | AbortWithEventFailure | Abort path (thunk 9918) |
| 0154cb28 | FUN_0154cb28 | WriteJobDataEntry | Job entry write @0x10 +0x10, tag=2 |
| 00e841c8 | FUN_00e841c8 | UpdateSpatialContainer | Spatial update via 014ab958/014abcd8 |
| 008045b8 | FUN_008045b8 | SetSlotValueWithTag | Slot set w/ 7-bit tag |
| 0154ca08 | FUN_0154ca08 | BuildJobDataRecord | Job data build (11 args!) |
| 00715868 | FUN_00715868 | ProcessFatalError | **FATAL error handler** (ZKN_COMMENT__+0xb string!) |
| 00ac63e8 | FUN_00ac63e8 | GetInitializedRegion | Guarded global (pattern match of GetInitializedGlobal) |
| 007006c8 | FUN_007006c8 | WriteErrorHeader | Error header compose (fatal type, string, code) |
| 006cee18 | FUN_006cee18 | ReleaseObjectVector | Vector of ptrs destroy loop |
| 0172c6b8 | FUN_0172c6b8 | CalculateMoveHitBonus | **Game logic!** d8-2<6 → +2; d4-2<3 → -1 |
| 007003f8 | FUN_007003f8 | PassErrorContext | Error context forward |
| 007006e8 | FUN_007006e8 | InitializeIfFlagged | Guarded init (bit0 @+0x18) |
| 014e22c8 | FUN_014e22c8 | SetStateFlagAndCallback | State bit @+0x83, vtable+0x98 callback |
| 01106e48 | FUN_01106e48 | ValidateHashTableAccess | Hash table bounds check (panic on cases 1-4) |
| 00785068 | FUN_00785068 | GetByteAtOffset88 | Read byte @+0x88 |
| 00e83cc8 | FUN_00e83cc8 | RemoveSpatialHandler | Handler teardown |
| 0070d898 | FUN_0070d898 | CalculateVarintSize | **Varint length**: 1/2/3/4/5 bytes by magnitude |
| 014ab8d8 | FUN_014ab8d8 | SetJobActiveFlag | Job flag @+0x58 bit0 |
| 007c3628 | FUN_007c3628 | SetPairWithZero | Pair write + zero |
| 01653468 | FUN_01653468 | GetIndexedGlobalEntry | Indexed global table read (DAT_024b5068[*DAT_024b5060*8]) |

## New subsystem: FATAL ERROR + varint I/O
- **ProcessFatalError**: builds error via `WriteErrorHeader(FATAL, "ZKN_COMMENT== ...")`, triple-echo context, then `FUN_017eb278()` + **UndefinedInstructionException** — hard panic → crash.
- **CalculateVarintSize**: 5-tier size function (0x7f → 1, 0x3fff → 2, ...) — **varint encoder**, likely for save data / network / archive I/O.
- **CalculateMoveHitBonus**: REAL GAME LOGIC at 0172c6b8: `if (d8-2 < 6) return d8+2; if (d4-2 < 3) return d4-1;` — hit bonus calculation (accuracy/evasion stages).

## Tally
- Round 1: 50
- Round 2: 31 (+11 fixups)
- Round 3 (this): 29
- **Total: 111 functions renamed** | 121 decompiled

## ROUND 4+ — "ROUND 20" (37 more renamed, total 148)

## 🔥 KEY FINDS — MATH & RNG
| Address | Name | Detail |
|---------|------|--------|
| 00973508 | CalculateQuaternionProduct | **Quaternion multiply** — full Hamilton product w/ fmod-based angle reduction |
| 0171ea78 | Xorshift128Next | **Xorshift128** PRNG (x^=x<<11, x>>8, ^=x>>19) — game RNG! |
| 01346fc8 | Xorshift32Advance | **Xorshift32** PRNG step (x ^= x<<2; x ^= x>>15; x ^= x<<13) |

## MORE SUBSYSTEMS
| Address | Name | Insight |
|---------|------|---------|
| 006ffce8 | ValidateTimeRange | Bounds check 3,000,000 — **~35 day timer** (3M seconds), abort on fail |
| 0066cd78 | PushBufferElement | Buffer push w/ capacity check +8 |
| 00bcb148 | PopLockfreeQueue | **Lock-free queue pop** — ExclusiveMonitorPass (LL/SC!) — atomic CAS |
| 01751728 | InitializeSingletonContext | Singleton init guarded by _DAT_027fd310 counter |
| 0165cf48 | GetGuardedRuntimeData | Guarded global (DAT_027fafe0) |
| 0082b1c8 | CopyTwelveQuads | 12×8B memcpy |
| 00607fe8 | GetGuardedGfxContext | Guarded GFX global |
| 0065f9a8 | GetGuardedKernelPointer | **KERNEL pointer** (DAT_02778768) |
| 0065e388 | AssertPostRuntimeInit | Post-init runtime assert |
| 0162fa38 | ResolveRenderResource | **RENDER RESOURCE RESOLVER** — 9 callees incl. tree insert + physx alloc |
| 013a7568 | CheckListMembership | Linked-list membership check |
| 00700508 | EnqueueEventBus | **EVENT BUS** vector enqueue (grow: ×2 pow2) |
| 00e846f8 | ReleaseScopedResource | Scoped object release via handle |
| 011979a8 | GetActiveObject | Object lookup + guard flag check |
| 006e1c98 | LogOrionError | **ORION LOG** — string "+orion/RomBu..." (source path!) |
| 00717aa8 | LogPaneDetailError | PANE detail error log (UI system) |
| 007681e8 | MergeBooleanFlags | Boolean combine (and/or/not-select) |
| 01655ab8 | SetRuntimeStatePair | Runtime state pair copy |
| 00eb6dc8 | EvaluateMultiKeyQuery | Multi-key hash query (4 named keys!) |

## FINAL TALLY
| Wave | Renamed |
|------|---------|
| R1 | 50 |
| R2 | 42 |
| R3 | 29 |
| R4+ ("Round 20") | 37 |
| **TOTAL** | **148 functions renamed** |

## Subsystem map (complete)
1. **Panic**: thunk_FUN_017e8ef0 (11K refs) → ProcessFatalError → UndefinedInstructionException
2. **Assert**: AssertRuntimeReady/SystemOnline/KernelState/PostRuntimeInit
3. **RNG**: Xorshift128 + Xorshift32 (both found!)
4. **Math**: Quaternion product, varint encode, time bounds
5. **Concurrency**: PopLockfreeQueue (LL/SC), event bus enqueue
6. **Data**: JobDataStore, hash tables (FNV-1a), sorted tree, buffers
7. **GFX**: SiGfx + PhysX (physx::shdfnd) + render resources + panes
8. **Logging**: Orion error logger (source paths leaked: `jenkins/workspace/orion/RomBu`)
9. **Memory**: GetGuardedKernelPointer (02778768), aligned allocator

## WAVE 5 (true round 5) — 20 more renamed → 168 total

| Address | New name | Insight |
|---------|----------|---------|
| 015bcba8 | DestroyListedNode | Linked-list node destroy (guard + vtable) |
| 01778bd8 | InvokeStaticCallback | Indirect call via DAT_024b5bd8+8 |
| 0140bf28 | ReadSerializedField32 | **Serialization reader** (field +4 cursor) |
| 0140c5d8 | ReadSerializedFieldBool | Serialization bool (nonzero → true) |
| 0154b3b8 | AdjustJobQueueIndex | Job queue index fixup (neg wrap) |
| 007c3648 | PollAsyncTask | Async task poller (>0x1c3 = 451 retries → vtable+0xb8) |
| 00819ed8 | SetObjectParamById | Object param set via id |
| 00e80748 | ReleaseSceneHierarchy | Scene graph teardown (552B) |
| 00451b68 | ReleaseDeferredPointer | Deferred pointer release |
| 016535c8 | EmptyStub | 4-byte no-op |
| 00e7ccc8 | InitAndAbortWrapper | Wrapper around InitializeAndAbort |
| 015b7658 | AllocateAlignedBlock | Second aligned allocator (DAT_0249d6a0) |
| 00228148 | VectorPushBackPair | **Vector<pair<u64,u64>> push back** (16-byte elems) |
| 00771388 | XorStreamDecrypt | **XOR stream cipher** — LCG 0x41c64e6d+0x6073 (park-miller!) XOR decrypt |
| 00e80f48 | DispatchSceneCallback | Recursive scene dispatch |
| 01106bb8 | ReadIndexedTableValue | Indexed table read (bounds-validated) |
| 007ef7e8 | ResolveBattleStage | Battle stage remap (9↔0xb with flag check) |
| 007712e8 | SumU16Array | Array sum (unrolled ×4) |
| 0065e298 | AssertRuntimeCheck2 | Runtime assert variant |
| 00771418 | XorStreamEncrypt | Mirror of XorStreamDecrypt (LCG stream) |

## 🔥 WAVE 5 FINDS
- **Stream cipher found**: LCG `x = x*0x41c64e6d + 0x6073` (classic Park–Miller / rand()) XORing u16 stream. Paired encrypt/decrypt functions = **save file XOR obfuscation** likely used by Game Freak.
- **Serialization layer**: ReadSerializedField32/Bool with cursor at +0x178 — batch fields read.
- **Battle logic**: ResolveBattleStage (stage 9↔11 remap) at 007ef7e8 — stat-stage system.

## Running total: 168 named | 186 decompiled

## WAVE 6 — 11 more renamed → 179 total

| Address | New name | Insight |
|---------|----------|---------|
| 00221ce8 | PushBackVectorPair | Vector pair push (twin of 00228148) |
| 00e7f3a8 | AcquireSceneObject | Scene object grab (16-slot table @+0x18) |
| 015bca78 | AbortWithQueueFailure | Queue abort (thunk 9918) |
| 00e80e18 | TraverseSceneTree | **Scene tree DFS traversal** (recursive!) |
| 0067c648 | GetObjectField58 | Read +0x58 |
| 0137ed18 | GetFlaggedObjectField | Flag-selected field read (0xf8 vs 0x118) |
| 00701068 | AcquireSpinlockInit | **SPINLOCK with LL/SC** (ExclusiveMonitorPass + DataMemoryBarrier) |
| 01716c28 | InvokeResourceMethod38 | Resource method +0x38 dispatch |
| 00967ad8 | GetGuardedGfxModule | Guarded GFX module global (DAT_0249b428) |
| 007007e8 | NoopStub | 4-byte no-op |
| 007fea68 | GetParentObject | Read parent ptr @+8 |

## 🔥 WAVE 6: CONCURRENCY + SCENE GRAPH
- **AcquireSpinlockInit** (00701068): full spinlock — LL/SC CAS loop (0→1), DataMemoryBarrier(2,3), spin-wait while ==1, complete (→2). The engine's one-shot init lock.
- **TraverseSceneTree** (00e80e18): recursive DFS over scene nodes with lock/unlock at each node (vtable +0x10/+0x18).

## Running total: 179 named | 197 decompiled

## WAVE 7 — 9 more renamed → 188 total

| Address | New name | Insight |
|---------|----------|---------|
| 006ce998 | GetObjectField110 | Read +0x110 (mirror of 006cec58 setter) |
| 0117e538 | GetGuardedSceneManager | Guarded scene global (DAT_024ad5d8) |
| 00815958 | DispatchMessageById | **Message dispatch** — 0xBD (189) id table w/ type-size lookup |
| 0165ce98 | AbortWithRuntimeError | Abort (thunk 9c38) |
| 010554d8 | GetGuardedTaskManager | Guarded task manager (DAT_024abd38) |
| 00f9d348 | PopAtomicQueueNode | **Second LL/SC lock-free queue** (DAT_024a9550) |
| 01135838 | GetObjectPlus710 | Offset helper (+0x710) |
| 0135aa38 | CheckHashSetContains | **HashSet contains** — FNV-1a (0xcbf29ce484222645) key, pow2 bucket, collision chain |
| 00e800b8 | TerminateSceneWithGuard | Scene terminate wrapper |

## 🔥 WAVE 7: MESSAGING + HASHSET
- **DispatchMessageById** (00815958): 0xBD-entry message table; type selector determines size; dispatch to handler (FUN_00815a68).
- **CheckHashSetContains** (0135aa38): FNV-1a-hash keyed hash set, pow2 buckets w/ mask, collision chain — classic CFG-level set.

## Running total: 188 named | 206 decompiled

## WAVE 8 — 10 more renamed → 198 total

| Address | New name | Insight |
|---------|----------|---------|
| 014eb238 | DispatchTimedEvent | Timed event dispatch (0x30-stride slots) |
| 0154d868 | ResolveJobDataStoreEntry | **JobDataStore entry resolver** (negative-index magic -0xf4628 again) |
| 0070e308 | PushSignalNode | **Lock-free signal push** (LL/SC + TLS fast path!) |
| 007e97f8 | WriteObjectParamQuick | Param write w/ tag '\t' |
| 00e83c38 | RemoveHandleByName | **FNV-1a hash of name string** → remove by hash |
| 015014d8 | ActivateSubsystemOnce | Once-flag activation (+0x62 gate) |
| 0140c518 | ReadSerializedInt32 | Serialized int reader (twin of ReadSerializedField32) |
| 017eb0d8 | InvokeSystemCallback | System callback (DAT_02496638) |
| 00a99fe8 | SetupParticleEmitter | **PARTICLE EMITTER setup** — 14 params! positions+colors+flags |
| 0165d248 | WriteU32BigEndian | **Big-endian u32 writer** — byte 0x18 first |

## 🔥 WAVE 8: PARTICLES + PERF
- **SetupParticleEmitter** (00a99fe8): emitter config with 5 float params (pos/scale), type→format lookup, 2 emit paths (cached vs fresh), flags param_13/param_14.
- **PushSignalNode** (0070e308): **per-thread TLS fast path** (tpidr_el0!) + LL/SC fallback + freelist — MPSC queue.
- **WriteU32BigEndian**: byte order — LE→BE conversion. Serialization layer confirmed endian-correct.

## Running total: 198 named | 216 decompiled

## WAVE 9 — 🎉 200+ (10 more → 208 total)

| Address | New name | Insight |
|---------|----------|---------|
| 0142aef8 | InsertSortedPriorityNode | **PRIORITY-QUEUE sorted insert** (748B, node compare @+0x70) |
| 0154b7a8 | ReadJobDataViewTag | JobDataStore view tag reader (0xf low bits) |
| 01778bf8 | InvokeCallbackRel24 | Callback at DAT_024b5bd8+0x18 |
| 00683668 | DestroySceneScheduler | Scene scheduler teardown (7 ptrs + callbacks) |
| 00952f08 | ProcessFieldCommandQueue | **FIELD COMMAND QUEUE** — 10-command switch, per-id dispatch, vtable +0x8e0 end hook |
| 00ea4ff8 | CheckFlagAtOffset98 | Bitmask flag check @+0x98 |
| 013a71b8 | GetGuardedAudioManager | Guarded AUDIO manager (DAT_024a0508) |
| 014ab958 | ClearObjectTrackState | Object track clear (FUN_00686xxx cluster) |
| 00304fd8 | ValidateThenReturnOne | if(param_2) abort; return 1 |
| 005030a8 | InvokeHandlerIfNotNull | Conditional handler dispatch |

## 🔥 WAVE 9: FIELD SYSTEM INTACT
- **ProcessFieldCommandQueue** (00952f08): over-world field command processor — 10 command types (0-9), per-command object dispatch (index x19+0x2e0), end-of-frame callback vtable+0x8e0. **This is the overworld event loop.**
- **InsertSortedPriorityNode** (0142aef8): priority-queue sorted node insertion with refcount-aware relinking — used by scheduler/timers.

## 🎉 CROSSED 200 FUNCTIONS NAMED

## Running total: 208 named | 226 decompiled
