/* sdk -- 2000 functions verified to match the original.
 *
 * These bodies were synthesised from the instruction stream by
 * tools/auto_match.py and confirmed by compiling them for
 * aarch64-none-elf and comparing against data/sdk.elf with
 * tools/match_harness.py. Signatures are recovered, not invented:
 * changing a parameter type changes the codegen and the mangled
 * name, so edit with care.
 *
 * Tail-call thunks were verified strictly: the branch
 * destination was checked against the relocation record the
 * compiler emitted, not ignored.
 *
 * Generated file -- re-run tools/decomp_project.py to regenerate.
 */

/* Self-contained: a bare-metal aarch64-none-elf target has no
 * <stdint.h> under -nostdinc++. */
#include <arm_neon.h>
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int64_t;
typedef unsigned long uintptr_t;

// sub_173970  (orig 0x173970, ret_only)
void sdk_f_173970() {}

// sub_173a70  (orig 0x173a70, straight-line)
void sdk_f_173a70(void* a0, uint64_t a1, uint32_t a2) {
    *(uint64_t*)((char*)(a0)) = a1;
    *(uint64_t*)((char*)(a0) + 16) = (uint64_t)(((int64_t)(((int32_t)(((uint32_t)a2))))));
}

// sub_179b50  (orig 0x179b50, ret_only)
void sdk_f_179b50() {}

// sub_179ea0  (orig 0x179ea0, ret_only)
void sdk_f_179ea0() {}

// sub_17a220  (orig 0x17a220, ret_only)
void sdk_f_17a220() {}

// sub_17df70  (orig 0x17df70, ptr_add)
void* sdk_f_17df70(void* a0) { return (char*)a0 + 16; }

// sub_17df80  (orig 0x17df80, mov_ret)
uint64_t sdk_f_17df80() { return 0; }

// sub_17dfc0  (orig 0x17dfc0, ptr_add)
void* sdk_f_17dfc0(void* a0) { return (char*)a0 + 8; }

// sub_17dfd0  (orig 0x17dfd0, straight)
void* sdk_f_17dfd0(void* a0) { return (char*)(a0) - 8; }

// sub_17ebb0  (orig 0x17ebb0, call)
extern void callee_5188b0();
uint32_t sdk_f_17ebb0() {
    uint32_t r0 = ((((uint32_t (*)(void))&callee_5188b0)() == 0) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_17ec10  (orig 0x17ec10, call)
extern void callee_5188b0();
uint32_t sdk_f_17ec10() {
    uint32_t r0 = ((((uint32_t (*)(void))&callee_5188b0)() == 1) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_17f0f0  (orig 0x17f0f0, straight)
uint32_t sdk_f_17f0f0(uint32_t a0) { return (((((uint32_t)a0) < 3)) ? (((uint32_t)a0)) : (3)); }

// sub_17f100  (orig 0x17f100, mov_ret)
uint32_t sdk_f_17f100() { return 0; }

// sub_17f250  (orig 0x17f250, call)
extern void callee_518940();
int64_t sdk_f_17f250() {
    int64_t r0 = ((int64_t)(((int32_t)(((uint64_t (*)(void))&callee_518940)()))));
    asm volatile("");
    return r0;
}

// sub_17f7d0  (orig 0x17f7d0, setter-chain)
void sdk_f_17f7d0(void* a0, uint64_t a1, uint64_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint8_t*)((char*)(a0) + 16) = 0; *(uint64_t*)((char*)(a0) + 24) = a2; }

// sub_17fb80  (orig 0x17fb80, ret_only)
void sdk_f_17fb80() {}

// sub_17fb90  (orig 0x17fb90, ret_only)
void sdk_f_17fb90() {}

// sub_17fba0  (orig 0x17fba0, ret_only)
void sdk_f_17fba0() {}

// sub_17fbb0  (orig 0x17fbb0, ret_only)
void sdk_f_17fbb0() {}

// sub_17fbc0  (orig 0x17fbc0, ret_only)
void sdk_f_17fbc0() {}

// sub_17fd30  (orig 0x17fd30, compare)
bool sdk_f_17fd30(uint64_t a0) { return (uint64_t)(a0) != (uint64_t)(0); }

// sub_17fd70  (orig 0x17fd70, ret_only)
void sdk_f_17fd70() {}

// sub_17fe60  (orig 0x17fe60, setter-chain)
void sdk_f_17fe60(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint8_t*)((char*)(a0) + 16) = 0; }

// sub_17ff90  (orig 0x17ff90, setter-chain)
void sdk_f_17ff90(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint8_t*)((char*)(a0) + 16) = 0; }

// sub_180980  (orig 0x180980, setter-chain)
void sdk_f_180980(void* a0) { *(uint64_t*)((char*)(a0)) = 0; *(uint8_t*)((char*)(a0) + 8) = 0; *(uint8_t*)((char*)(a0) + 24) = 0; }

// sub_180a60  (orig 0x180a60, ptr_add)
void* sdk_f_180a60(void* a0) { return (char*)a0 + 32; }

// sub_180f10  (orig 0x180f10, ptr_add)
void* sdk_f_180f10(void* a0) { return (char*)a0 + 72; }

// sub_1813b0  (orig 0x1813b0, setter)
void sdk_f_1813b0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 28) = a1; }

// sub_1813c0  (orig 0x1813c0, getter)
uint32_t sdk_f_1813c0(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_1813d0  (orig 0x1813d0, getter)
uint32_t sdk_f_1813d0(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_181400  (orig 0x181400, straight-line)
uint64_t sdk_f_181400(void* a0) {
    void* p0 = (void*)((uintptr_t)((*(uint64_t*)((char*)(a0))) + ((*(int32_t*)((char*)(a0) + 28)) * (24))));
    return *(uint64_t*)((char*)(p0) + 16);
}

// sub_181440  (orig 0x181440, straight-line)
uint8_t sdk_f_181440(void* a0) {
    void* p0 = (void*)((uintptr_t)((*(uint64_t*)((char*)(a0))) + ((*(int32_t*)((char*)(a0) + 28)) * (24))));
    return (*(uint8_t*)((char*)(p0) + 4)) & (15);
}

// sub_181460  (orig 0x181460, ret_only)
void sdk_f_181460() {}

// sub_181470  (orig 0x181470, ret_only)
void sdk_f_181470() {}

// sub_181480  (orig 0x181480, ret_only)
void sdk_f_181480() {}

// sub_181490  (orig 0x181490, ret_only)
void sdk_f_181490() {}

// sub_1814a0  (orig 0x1814a0, ret_only)
void sdk_f_1814a0() {}

// sub_1814b0  (orig 0x1814b0, ret_only)
void sdk_f_1814b0() {}

// sub_181920  (orig 0x181920, getter)
uint8_t sdk_f_181920(void* a0) { return *(uint8_t*)((char*)(a0)); }

// sub_181960  (orig 0x181960, compare)
bool sdk_f_181960(void* a0) { return (uint32_t)(*(uint32_t*)((char*)(a0) + 120)) == (uint64_t)(1); }

// sub_181970  (orig 0x181970, compare)
bool sdk_f_181970(void* a0) { return (uint32_t)(*(uint32_t*)((char*)(a0) + 120)) == (uint64_t)(2); }

// sub_181ac0  (orig 0x181ac0, straight)
void sdk_f_181ac0(void* a0) {
    *(uint32_t*)((char*)(a0) + 120) = 1;
}

// sub_181ad0  (orig 0x181ad0, straight-line)
uint64_t sdk_f_181ad0(void* a0) { return (8) + ((*(int32_t*)((char*)(a0) + 16)) * (104)); }

// sub_181af0  (orig 0x181af0, straight-line)
int64_t sdk_f_181af0(uint64_t unused0, uint32_t a1) { return ((((int64_t)(((int32_t)(((uint32_t)a1)))))) * (((int64_t)(((int32_t)(104)))))) + (8); }

// sub_182260  (orig 0x182260, getter)
uint32_t sdk_f_182260(void* a0) { return *(uint32_t*)((char*)(a0) + 16); }

// sub_182270  (orig 0x182270, getter)
uint64_t sdk_f_182270(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_1822c0  (orig 0x1822c0, mov_ret)
uint32_t sdk_f_1822c0() { return 100; }

// sub_1822d0  (orig 0x1822d0, ptr_add)
void* sdk_f_1822d0(void* a0) { return (char*)a0 + 24; }

// sub_182920  (orig 0x182920, straight)
void sdk_f_182920(void* a0) {
    *(uint32_t*)((char*)(a0) + 120) = 2;
}

// sub_182930  (orig 0x182930, setter)
void sdk_f_182930(void* a0) { *(uint32_t*)((char*)(a0) + 120) = 0; }

// sub_182940  (orig 0x182940, setter)
void sdk_f_182940(void* a0) { *(uint32_t*)((char*)(a0) + 120) = 0; }

// sub_1829d0  (orig 0x1829d0, call)
extern void callee_518cc0();
uint64_t sdk_f_1829d0(void* a0) {
    uint64_t r0 = ((uint64_t (*)(uintptr_t))&callee_518cc0)(((uintptr_t)((char*)(a0) + 32)));
    asm volatile("");
    return r0;
}

// sub_182a00  (orig 0x182a00, call)
extern void callee_518ce0();
uint64_t sdk_f_182a00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_518ce0)(((uintptr_t)((char*)(a0) + 32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_182a20  (orig 0x182a20, call)
extern void callee_518cf0();
uint64_t sdk_f_182a20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_518cf0)(((uintptr_t)((char*)(a0) + 32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_182a40  (orig 0x182a40, getter)
uint64_t sdk_f_182a40(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_182a50  (orig 0x182a50, getter)
uint64_t sdk_f_182a50(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_182a60  (orig 0x182a60, pair-ret)
struct pair16_f_182a60_ { uint64_t f[2]; }; pair16_f_182a60_ sdk_f_182a60(void* a0) { return *(struct pair16_f_182a60_ *)((char*)(a0) + 16); }

// sub_182a70  (orig 0x182a70, ptr_add)
void* sdk_f_182a70(void* a0) { return (char*)a0 + 32; }

// sub_182a80  (orig 0x182a80, getter)
uint8_t sdk_f_182a80(void* a0) { return *(uint8_t*)((char*)(a0) + 112); }

// sub_185470  (orig 0x185470, ret_only)
void sdk_f_185470() {}

// sub_188450  (orig 0x188450, compare)
bool sdk_f_188450(void* a0) { return (uint8_t)(*(uint8_t*)((char*)(a0))) != (uint64_t)(0); }

// sub_1888e0  (orig 0x1888e0, getter)
uint8_t sdk_f_1888e0(void* a0) { return *(uint8_t*)((char*)(a0) + 55); }

// sub_188db0  (orig 0x188db0, strlit-ret)
const char *sdk_f_188db0() { static char g_f_188db0[1]; __asm__ volatile("" ::: "memory"); return g_f_188db0; }

// sub_188fa0  (orig 0x188fa0, ret_only)
void sdk_f_188fa0() {}

// sub_189cb0  (orig 0x189cb0, call)
extern void callee_518f90();
uint64_t sdk_f_189cb0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_518f90)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_18a410  (orig 0x18a410, setter-chain)
void sdk_f_18a410(void* a0) { *(void**)((char*)(a0)) = a0; *(void**)((char*)(a0) + 8) = a0; *(uint8_t*)((char*)(a0) + 72) = 0; *(uint64_t*)((char*)(a0) + 16) = 0; *(uint64_t*)((char*)(a0) + 24) = 0; }

// sub_18a9e0  (orig 0x18a9e0, ptr_add)
void* sdk_f_18a9e0(void* a0) { return (char*)a0 + 32; }

// sub_18ac90  (orig 0x18ac90, straight)
void* sdk_f_18ac90(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 144));
    return (char*)(p0) + 144;
}

// sub_18af90  (orig 0x18af90, straight)
void* sdk_f_18af90(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 144));
    return (char*)(p0) + 144;
}

// sub_18afa0  (orig 0x18afa0, ret_only)
void sdk_f_18afa0() {}

// sub_18b5c0  (orig 0x18b5c0, ptr_add)
void* sdk_f_18b5c0(void* a0) { return (char*)a0 + 16; }

// sub_18b690  (orig 0x18b690, call)
extern void callee_512700();
uint64_t sdk_f_18b690(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_18b6b0  (orig 0x18b6b0, call)
extern void callee_512700();
uint64_t sdk_f_18b6b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_18b720  (orig 0x18b720, ptr_add)
void* sdk_f_18b720(void* a0) { return (char*)a0 + 8; }

// sub_18b730  (orig 0x18b730, straight)
void* sdk_f_18b730(void* a0) { return (char*)(a0) - 8; }

// sub_18ba90  (orig 0x18ba90, ptr_add)
void* sdk_f_18ba90(void* a0) { return (char*)a0 + 16; }

// sub_18bb50  (orig 0x18bb50, ptr_add)
void* sdk_f_18bb50(void* a0) { return (char*)a0 + 8; }

// sub_18bb60  (orig 0x18bb60, straight)
void* sdk_f_18bb60(void* a0) { return (char*)(a0) - 8; }

// sub_18be80  (orig 0x18be80, ptr_add)
void* sdk_f_18be80(void* a0) { return (char*)a0 + 16; }

// sub_18bf40  (orig 0x18bf40, ptr_add)
void* sdk_f_18bf40(void* a0) { return (char*)a0 + 8; }

// sub_18bf50  (orig 0x18bf50, straight)
void* sdk_f_18bf50(void* a0) { return (char*)(a0) - 8; }

// sub_18c2a0  (orig 0x18c2a0, ptr_add)
void* sdk_f_18c2a0(void* a0) { return (char*)a0 + 16; }

// sub_18c2d0  (orig 0x18c2d0, call)
extern void callee_5127d0();
uint64_t sdk_f_18c2d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_18c2f0  (orig 0x18c2f0, call)
extern void callee_519140();
uint64_t sdk_f_18c2f0(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_519140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_18c320  (orig 0x18c320, call)
extern void callee_5126f0();
uint64_t sdk_f_18c320(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_18c340  (orig 0x18c340, call)
extern void callee_512700();
uint64_t sdk_f_18c340(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_18c360  (orig 0x18c360, call)
extern void callee_519150();
uint64_t sdk_f_18c360(void* a0, void* a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_519150)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_18c390  (orig 0x18c390, ptr_add)
void* sdk_f_18c390(void* a0) { return (char*)a0 + 8; }

// sub_18c3a0  (orig 0x18c3a0, straight)
void* sdk_f_18c3a0(void* a0) { return (char*)(a0) - 8; }

// sub_18c9b0  (orig 0x18c9b0, strlit-ret)
const char *sdk_f_18c9b0() { static char g_f_18c9b0[1]; __asm__ volatile("" ::: "memory"); return g_f_18c9b0; }

// sub_18f560  (orig 0x18f560, getter)
uint64_t sdk_f_18f560(void* a0) { return *(uint64_t*)((char*)(a0) + 40); }

// sub_18f970  (orig 0x18f970, setter)
void sdk_f_18f970(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0)) = a1; }

// sub_18fbb0  (orig 0x18fbb0, ret_only)
void sdk_f_18fbb0() {}

// sub_18fc80  (orig 0x18fc80, ptr_add)
void* sdk_f_18fc80(void* a0) { return (char*)a0 + 16; }

// sub_18fcc0  (orig 0x18fcc0, call)
extern void callee_519270();
uint64_t sdk_f_18fcc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_18fce0  (orig 0x18fce0, ptr_add)
void* sdk_f_18fce0(void* a0) { return (char*)a0 + 8; }

// sub_18fcf0  (orig 0x18fcf0, straight)
void* sdk_f_18fcf0(void* a0) { return (char*)(a0) - 8; }

// sub_190810  (orig 0x190810, getter)
uint32_t sdk_f_190810(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_190820  (orig 0x190820, ptr_add)
void* sdk_f_190820(void* a0) { return (char*)a0 + 8; }

// sub_190830  (orig 0x190830, getter)
uint64_t sdk_f_190830(void* a0) { return *(uint64_t*)((char*)(a0) + 4104L); }

// sub_192610  (orig 0x192610, mov_ret)
uint64_t sdk_f_192610() { return 0; }

// sub_192620  (orig 0x192620, mov_ret)
uint64_t sdk_f_192620() { return 0; }

// sub_192630  (orig 0x192630, mov_ret)
uint64_t sdk_f_192630() { return 0; }

// sub_192640  (orig 0x192640, mov_ret)
uint64_t sdk_f_192640() { return 0; }

// sub_192840  (orig 0x192840, mov_ret)
uint32_t sdk_f_192840() { return 0; }

// sub_192850  (orig 0x192850, mov_ret)
uint32_t sdk_f_192850() { return 0; }

// sub_192860  (orig 0x192860, mov_ret)
uint64_t sdk_f_192860() { return 0; }

// sub_192870  (orig 0x192870, mov_ret)
uint32_t sdk_f_192870() { return 0; }

// sub_192de0  (orig 0x192de0, ret_only)
void sdk_f_192de0() {}

// sub_192fb0  (orig 0x192fb0, ret_only)
void sdk_f_192fb0() {}

// sub_193290  (orig 0x193290, straight)
uint32_t sdk_f_193290(uint32_t a0) { return ((((uint32_t)a0)) >> (6)) & (1); }

// sub_1932a0  (orig 0x1932a0, straight)
uint32_t sdk_f_1932a0(uint32_t a0) { return ((((uint32_t)a0)) >> (5)) & (1); }

// sub_1932b0  (orig 0x1932b0, straight)
uint32_t sdk_f_1932b0(uint32_t a0) { return ((((uint32_t)a0)) >> (2)) & (1); }

// sub_1932c0  (orig 0x1932c0, straight)
uint32_t sdk_f_1932c0(uint32_t a0) { return (((uint32_t)a0)) & (1); }

// sub_193f50  (orig 0x193f50, getter)
uint16_t sdk_f_193f50(void* a0) { return *(uint16_t*)((char*)(a0)); }

// sub_193f60  (orig 0x193f60, getter)
uint32_t sdk_f_193f60(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_194e00  (orig 0x194e00, compare)
bool sdk_f_194e00(void* a0) { return (uint32_t)(*(uint32_t*)((char*)(a0))) != (uint64_t)(0); }

// sub_194e10  (orig 0x194e10, mov_ret)
uint64_t sdk_f_194e10() { return 0; }

// sub_194e20  (orig 0x194e20, copy-chain-store)
void sdk_f_194e20(void* a0, void* a1) {
    uint32_t t0 = *(uint32_t*)(char*)a1;
    *(uint32_t*)((char*)a0 + 16) = (uint32_t)(t0);
    __asm__ __volatile__("" ::: "memory");
    *(uint8_t*)((char*)a0 + 6) = 0;
}

// sub_194e30  (orig 0x194e30, straight)
void sdk_f_194e30(void* a0, void* a1) {
    uint32_t k0 = 1;
    *(uint64_t*)((char*)(a0) + 8) = *(uint64_t*)((char*)(a1));
    *(uint8_t*)((char*)(a0) + 6) = (uint8_t)k0;
}

// sub_195840  (orig 0x195840, call)
extern void callee_519560();
uint64_t sdk_f_195840() {
    callee_519560();
    uint64_t r0 = 0;
    asm volatile("");
    return r0;
}

// sub_195860  (orig 0x195860, ret_only)
void sdk_f_195860() {}

// sub_195f20  (orig 0x195f20, straight)
void sdk_f_195f20(void* a0) {
    uint32_t k0 = 258;
    uint32_t k1 = 0;
    uint32_t k2 = 0;
    *(uint16_t*)((char*)(a0)) = (uint16_t)k0;
    *(uint32_t*)((char*)(a0) + 8) = 0;
    *(uint8_t*)((char*)(a0) + 20) = (uint8_t)k1;
    *(uint8_t*)((char*)(a0) + 2068) = (uint8_t)k2;
}

// sub_196170  (orig 0x196170, setter)
void sdk_f_196170(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 8) = a1; }

// sub_1963c0  (orig 0x1963c0, getter)
uint32_t sdk_f_1963c0(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_1963d0  (orig 0x1963d0, ptr_add)
void* sdk_f_1963d0(void* a0) { return (char*)a0 + 20; }

// sub_1963e0  (orig 0x1963e0, ptr_add)
void* sdk_f_1963e0(void* a0) { return (char*)a0 + 2068; }

// sub_1963f0  (orig 0x1963f0, getter)
uint64_t sdk_f_1963f0(void* a0) { return *(uint64_t*)((char*)(a0) + 12); }

// sub_196400  (orig 0x196400, setter)
void sdk_f_196400(void* a0) { *(uint32_t*)((char*)(a0)) = 0; }

// sub_196410  (orig 0x196410, straight)
void sdk_f_196410(void* a0, void* a1) {
    *(uint32_t*)((char*)(a0)) = 1;
    *(uint32_t*)((char*)(a0) + 4) = *(uint32_t*)((char*)(a1));
}

// sub_196430  (orig 0x196430, straight)
void sdk_f_196430(void* a0, void* a1) {
    *(uint32_t*)((char*)(a0)) = 2;
    *(uint64_t*)((char*)(a0) + 4) = *(uint64_t*)((char*)(a1));
}

// sub_196450  (orig 0x196450, straight)
void sdk_f_196450(void* a0, void* a1) {
    *(uint32_t*)((char*)(a0)) = 1;
    *(uint32_t*)((char*)(a0) + 4) = *(uint32_t*)((char*)(a1));
}

// sub_196470  (orig 0x196470, straight)
void sdk_f_196470(void* a0, void* a1) {
    *(uint32_t*)((char*)(a0)) = 2;
    *(uint64_t*)((char*)(a0) + 4) = *(uint64_t*)((char*)(a1));
}

// sub_196490  (orig 0x196490, getter)
uint32_t sdk_f_196490(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_1964a0  (orig 0x1964a0, getter)
uint64_t sdk_f_1964a0(void* a0) { return *(uint64_t*)((char*)(a0) + 4); }

// sub_1964b0  (orig 0x1964b0, getter)
uint32_t sdk_f_1964b0(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_196530  (orig 0x196530, straight)
void sdk_f_196530(void* a0) {
    uint16_t k0 = 0;
    uint32_t k1 = 1;
    uint16_t k2 = 0;
    uint16_t k3 = 0;
    uint16_t k4 = 0;
    *(uint16_t*)((char*)(a0) + 6) = 0;
    *(uint32_t*)((char*)(a0) + 2) = (uint32_t)k0;
    *(uint64_t*)((char*)(a0) + 4120L) = 0;
    *(uint16_t*)((char*)(a0)) = (uint16_t)k1;
    *(uint64_t*)((char*)(a0) + 8) = 0;
    *(uint8_t*)((char*)(a0) + 24) = (uint8_t)k2;
    *(uint8_t*)((char*)(a0) + 2072) = (uint8_t)k3;
    *(uint8_t*)((char*)(a0) + 16) = (uint8_t)k4;
}

// sub_1967a0  (orig 0x1967a0, setter)
void sdk_f_1967a0(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 8) = a1; }

// sub_1969f0  (orig 0x1969f0, getter)
uint64_t sdk_f_1969f0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_196a00  (orig 0x196a00, ptr_add)
void* sdk_f_196a00(void* a0) { return (char*)a0 + 24; }

// sub_196a10  (orig 0x196a10, ptr_add)
void* sdk_f_196a10(void* a0) { return (char*)a0 + 2072; }

// sub_196a20  (orig 0x196a20, getter)
uint64_t sdk_f_196a20(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_196a30  (orig 0x196a30, ret_only)
void sdk_f_196a30() {}

// sub_196a40  (orig 0x196a40, straight)
void sdk_f_196a40(void* a0, uint64_t a1) {
    uint32_t k0 = 1;
    *(uint64_t*)((char*)(a0) + 4120L) = (uint64_t)(a1);
    *(uint8_t*)((char*)(a0) + 5) = (uint8_t)k0;
}

// sub_196a50  (orig 0x196a50, setter-chain)
void sdk_f_196a50(void* a0) { *(uint64_t*)((char*)(a0) + 4120L) = 0; *(uint8_t*)((char*)(a0) + 5) = 0; }

// sub_196a60  (orig 0x196a60, getter)
uint64_t sdk_f_196a60(void* a0) { return *(uint64_t*)((char*)(a0) + 4120L); }

// sub_199c60  (orig 0x199c60, setter-chain-zero)
void sdk_f_199c60(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 168) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 152) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 136) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 120) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 104) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 88) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 72) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 56) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 40) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_199ca0  (orig 0x199ca0, ret_only)
void sdk_f_199ca0() {}

// sub_199d20  (orig 0x199d20, mov_ret)
uint64_t sdk_f_199d20() { return 0; }

// sub_199d30  (orig 0x199d30, mov_ret)
uint32_t sdk_f_199d30() { return 0; }

// sub_199d40  (orig 0x199d40, mov_ret)
uint64_t sdk_f_199d40() { return 0; }

// sub_199d50  (orig 0x199d50, mov_ret)
uint32_t sdk_f_199d50() { return 0; }

// sub_199d60  (orig 0x199d60, mov_ret)
uint32_t sdk_f_199d60() { return 0; }

// sub_199d70  (orig 0x199d70, mov_ret)
uint32_t sdk_f_199d70() { return 0; }

// sub_199d90  (orig 0x199d90, getter)
uint64_t sdk_f_199d90(void* a0) { return *(uint64_t*)((char*)(a0) + 176); }

// sub_19a6c0  (orig 0x19a6c0, call)
extern void callee_519890();
uint32_t sdk_f_19a6c0() {
    uint32_t r0 = ((((uint32_t (*)(void))&callee_519890)() & (uint64_t)(65535)) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_19ded0  (orig 0x19ded0, getter)
uint32_t sdk_f_19ded0(void* a0) { return *(uint32_t*)((char*)(a0) + 72); }

// sub_19e520  (orig 0x19e520, straight)
uint32_t sdk_f_19e520(void* a0, void* a1, void* a2) {
    *(uint16_t*)((char*)(a1)) = *(uint16_t*)((char*)(a0) + 64);
    *(uint16_t*)((char*)(a2)) = *(uint16_t*)((char*)(a0) + 66);
    *(uint32_t*)((char*)(a0) + 72) = 0;
    return 0;
}

// sub_19e540  (orig 0x19e540, straight)
uint32_t sdk_f_19e540(void* a0, uint64_t a1, uint64_t a2) {
    *(uint16_t*)((char*)(a0) + 68) = (uint16_t)(a1);
    *(uint16_t*)((char*)(a0) + 70) = (uint16_t)(a2);
    *(uint32_t*)((char*)(a0) + 72) = 0;
    return 0;
}

// sub_19e560  (orig 0x19e560, straight)
uint32_t sdk_f_19e560(void* a0, void* a1, void* a2) {
    *(uint16_t*)((char*)(a1)) = *(uint16_t*)((char*)(a0) + 68);
    *(uint16_t*)((char*)(a2)) = *(uint16_t*)((char*)(a0) + 70);
    *(uint32_t*)((char*)(a0) + 72) = 0;
    return 0;
}

// sub_19e580  (orig 0x19e580, getter)
uint32_t sdk_f_19e580(void* a0) { return *(uint32_t*)((char*)(a0) + 76); }

// sub_19e5c0  (orig 0x19e5c0, straight)
uint32_t sdk_f_19e5c0(void* a0) {
    *(uint32_t*)((char*)(a0) + 72) = 432;
    return 432;
}

// sub_19e930  (orig 0x19e930, straight)
uint64_t sdk_f_19e930(void* a0) {
    *(uint32_t*)((char*)(a0) + 72) = 435;
    return 0;
}

// sub_19f1b0  (orig 0x19f1b0, straight)
uint32_t sdk_f_19f1b0(void* a0) {
    *(uint32_t*)((char*)(a0) + 72) = 0;
    return 0;
}

// sub_1a35f0  (orig 0x1a35f0, straight)
uint32_t sdk_f_1a35f0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 128));
    return *(uint32_t*)((char*)(p0) + 16832L);
}

// sub_1a3d70  (orig 0x1a3d70, straight)
uint32_t sdk_f_1a3d70(void* a0) {
    *(uint32_t*)((char*)(a0) + 72) = 0;
    return 0;
}

// sub_1b1f20  (orig 0x1b1f20, straight)
void sdk_f_1b1f20(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    void* p1 = (void*)(*(uint64_t *)((char*)(a0) + 64));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 4);
    *(uint32_t*)((char*)(p1) + 132) = *(uint32_t*)((char*)(p0) - 4);
}

// sub_1b2020  (orig 0x1b2020, straight-line)
void sdk_f_1b2020(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 4);
    *(uint64_t*)((char*)(a0) + 48) = ((*(uint64_t*)((char*)(a0) + 48)) + (*(int32_t*)((char*)(p0) - 4))) - (1);
}

// sub_1b2040  (orig 0x1b2040, straight)
void sdk_f_1b2040(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    void* p1 = (void*)(*(uint64_t *)((char*)(a0) + 64));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 4);
    *(uint32_t*)((char*)(p1) + 112) = *(uint32_t*)((char*)(p0) - 4);
}

// sub_1b2060  (orig 0x1b2060, straight)
void sdk_f_1b2060(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    void* p1 = (void*)(*(uint64_t *)((char*)(a0) + 64));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 4);
    *(uint32_t*)((char*)(p1) + 116) = *(uint32_t*)((char*)(p0) - 4);
}

// sub_1b20d0  (orig 0x1b20d0, straight)
void sdk_f_1b20d0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) + 4);
    *(uint32_t*)((char*)(p0)) = *(uint32_t*)((char*)(p0) - 4);
}

// sub_1b20f0  (orig 0x1b20f0, copy-chain-store)
void sdk_f_1b20f0(void* a0) {
    uint64_t t0 = *(uint64_t*)((char*)a0 + 64);
    uint64_t t1 = *(uint64_t*)((char*)(t0) + 8);
    *(uint64_t*)((char*)a0 + 40) = (uint64_t)(t1);
}

// sub_1b2140  (orig 0x1b2140, straight)
void sdk_f_1b2140(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    void* p1 = (void*)((uintptr_t)(((*(uint64_t*)((char*)(a0) + 40)) - (((*(int32_t*)((char*)(p0) - 4)) << 2))) - (0)));
    *(uint32_t*)((char*)(p0)) = *(uint32_t*)((char*)(p1));
}

// sub_1b3ab0  (orig 0x1b3ab0, straight)
void sdk_f_1b3ab0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    void* p1 = (void*)(*(uint64_t *)((char*)(a0) + 64));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) + 4);
    *(uint32_t*)((char*)(p0)) = (uint32_t)(*(uint16_t*)((char*)(p1) + 36));
}

// sub_1b3ad0  (orig 0x1b3ad0, const-field-set-store)
void sdk_f_1b3ad0(void* a0) {
    uint64_t t0 = *(uint64_t*)((char*)a0 + 64);
    uint32_t t1 = 1;
    *(uint8_t*)((char*)(t0) + 162) = (uint8_t)(t1);
}

// sub_1b3ae0  (orig 0x1b3ae0, copy2)
void sdk_f_1b3ae0(void* a0) { (*(uint8_t *)((char *)(*(void **)((char*)(a0) + 64)) + 162)) = 0; }

// sub_1b3af0  (orig 0x1b3af0, straight)
void sdk_f_1b3af0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 4);
}

// sub_1b3dd0  (orig 0x1b3dd0, ret_only)
void sdk_f_1b3dd0() {}

// sub_1b3e00  (orig 0x1b3e00, straight)
void sdk_f_1b3e00(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    void* p1 = (void*)(*(uint64_t *)((char*)(a0) + 64));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 4);
    *(uint16_t*)((char*)(p1) + 154) = (uint16_t)(*(uint32_t*)((char*)(p0) - 4));
}

// sub_1b3e20  (orig 0x1b3e20, straight)
void sdk_f_1b3e20(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    void* p1 = (void*)(*(uint64_t *)((char*)(a0) + 64));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 4);
    *(uint16_t*)((char*)(p1) + 156) = (uint16_t)(*(uint32_t*)((char*)(p0) - 4));
}

// sub_1b4260  (orig 0x1b4260, straight)
void sdk_f_1b4260(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    void* p1 = (void*)(*(uint64_t *)((char*)(a0) + 64));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 4);
    *(uint16_t*)((char*)(p1) + 158) = (uint16_t)(*(uint32_t*)((char*)(p0) - 4));
}

// sub_1b54a0  (orig 0x1b54a0, straight)
void sdk_f_1b54a0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 12);
}

// sub_1b54b0  (orig 0x1b54b0, straight)
void sdk_f_1b54b0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    *(uint64_t*)((char*)(a0) + 40) = (uint64_t)((char*)(p0) - 12);
}

// sub_1b6140  (orig 0x1b6140, mov_ret)
uint32_t sdk_f_1b6140(uint32_t a0, uint32_t a1) { return a1; }

// sub_1b6150  (orig 0x1b6150, getter-chain)
uint32_t sdk_f_1b6150(void* a0, int32_t a1) {
    uint64_t t0 = *(uint64_t*)((char*)a0 + 64);
    uint64_t t1 = *(uint64_t*)((char*)(t0) + 24);
    return *(uint32_t*)((char*)(t1) + (uintptr_t)(a1) * 4);
}

// sub_1b6160  (orig 0x1b6160, getter-chain)
uint32_t sdk_f_1b6160(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 64))) + 120); }

// sub_1b6850  (orig 0x1b6850, mov_ret)
uint32_t sdk_f_1b6850(uint32_t a0, uint32_t a1, uint32_t a2) { return a2; }

// sub_1c3e50  (orig 0x1c3e50, straight)
uint8_t sdk_f_1c3e50(void* a0, void* a1) {
    *(uint32_t*)((char*)(a1)) = *(uint32_t*)((char*)(a0) + 72);
    return *(uint8_t*)((char*)(a0) + 68);
}

// sub_1c3e60  (orig 0x1c3e60, straight)
uint8_t sdk_f_1c3e60(void* a0, void* a1) {
    *(uint32_t*)((char*)(a1)) = *(uint32_t*)((char*)(a0) + 80);
    return *(uint8_t*)((char*)(a0) + 76);
}

// sub_1c3e70  (orig 0x1c3e70, getter)
uint16_t sdk_f_1c3e70(void* a0) { return *(uint16_t*)((char*)(a0) + 112); }

// sub_1c4130  (orig 0x1c4130, getter)
uint64_t sdk_f_1c4130(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_1c4160  (orig 0x1c4160, getter)
uint64_t sdk_f_1c4160(void* a0) { return *(uint64_t*)((char*)(a0) + 32); }

// sub_1c4170  (orig 0x1c4170, getter)
uint16_t sdk_f_1c4170(void* a0) { return *(uint16_t*)((char*)(a0) + 40); }

// sub_1c41b0  (orig 0x1c41b0, getter)
uint16_t sdk_f_1c41b0(void* a0) { return *(uint16_t*)((char*)(a0) + 42); }

// sub_1d1950  (orig 0x1d1950, straight)
uint32_t sdk_f_1d1950(uint64_t unused0, void* a1, void* a2) {
    *(uint32_t*)((char*)(a2)) = 0;
    *(uint32_t*)((char*)(a1) + 72) = 0;
    return 0;
}

// sub_1d2400  (orig 0x1d2400, ret_only)
void sdk_f_1d2400() {}

// sub_1d6050  (orig 0x1d6050, mov_ret)
uint32_t sdk_f_1d6050() { return 0; }

// sub_1db0f0  (orig 0x1db0f0, getter)
uint64_t sdk_f_1db0f0(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_1db100  (orig 0x1db100, ptr_add)
void* sdk_f_1db100(void* a0) { return (char*)a0 + 24; }

// sub_1db1b0  (orig 0x1db1b0, getter)
uint32_t sdk_f_1db1b0(void* a0) { return *(uint32_t*)((char*)(a0) + 224); }

// sub_1db1c0  (orig 0x1db1c0, ptr_add)
void* sdk_f_1db1c0(void* a0) { return (char*)a0 + 232; }

// sub_1db1d0  (orig 0x1db1d0, getter)
uint8_t sdk_f_1db1d0(void* a0) { return *(uint8_t*)((char*)(a0) + 328); }

// sub_1db1e0  (orig 0x1db1e0, setter)
void sdk_f_1db1e0(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_1db250  (orig 0x1db250, getter)
uint64_t sdk_f_1db250(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_1db260  (orig 0x1db260, ptr_add)
void* sdk_f_1db260(void* a0) { return (char*)a0 + 24; }

// sub_1db350  (orig 0x1db350, ptr_add)
void* sdk_f_1db350(void* a0) { return (char*)a0 + 64; }

// sub_1db360  (orig 0x1db360, getter)
uint8_t sdk_f_1db360(void* a0) { return *(uint8_t*)((char*)(a0) + 288); }

// sub_1db370  (orig 0x1db370, getter)
uint8_t sdk_f_1db370(void* a0) { return *(uint8_t*)((char*)(a0) + 289); }

// sub_1db3b0  (orig 0x1db3b0, getter)
uint8_t sdk_f_1db3b0(void* a0) { return *(uint8_t*)((char*)(a0) + 296); }

// sub_1db3c0  (orig 0x1db3c0, setter-chain-zero)
void sdk_f_1db3c0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 240) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 224) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 208) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 192) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 176) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 160) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 144) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 128) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 112) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 96) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1db410  (orig 0x1db410, getter)
uint64_t sdk_f_1db410(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_1db420  (orig 0x1db420, getter)
uint32_t sdk_f_1db420(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_1db430  (orig 0x1db430, ptr_add)
void* sdk_f_1db430(void* a0) { return (char*)a0 + 16; }

// sub_1db440  (orig 0x1db440, ptr_add)
void* sdk_f_1db440(void* a0) { return (char*)a0 + 32; }

// sub_1db450  (orig 0x1db450, getter)
uint8_t sdk_f_1db450(void* a0) { return *(uint8_t*)((char*)(a0) + 200); }

// sub_1db470  (orig 0x1db470, getter)
uint64_t sdk_f_1db470(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_1db480  (orig 0x1db480, ptr_add)
void* sdk_f_1db480(void* a0) { return (char*)a0 + 1040; }

// sub_1db490  (orig 0x1db490, getter)
uint32_t sdk_f_1db490(void* a0) { return *(uint32_t*)((char*)(a0) + 1208); }

// sub_1db4a0  (orig 0x1db4a0, ptr_add)
void* sdk_f_1db4a0(void* a0) { return (char*)a0 + 1216; }

// sub_1db4b0  (orig 0x1db4b0, ptr_add)
void* sdk_f_1db4b0(void* a0) { return (char*)a0 + 1320; }

// sub_1db4c0  (orig 0x1db4c0, ptr_add)
void* sdk_f_1db4c0(void* a0) { return (char*)a0 + 1320; }

// sub_1db4d0  (orig 0x1db4d0, ptr_add)
void* sdk_f_1db4d0(void* a0) { return (char*)a0 + 1352; }

// sub_1db530  (orig 0x1db530, ptr_add)
void* sdk_f_1db530(void* a0) { return (char*)a0 + 16; }

// sub_1db540  (orig 0x1db540, getter)
uint8_t sdk_f_1db540(void* a0) { return *(uint8_t*)((char*)(a0) + 1312); }

// sub_1db560  (orig 0x1db560, getter)
uint64_t sdk_f_1db560(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_1db570  (orig 0x1db570, getter)
uint64_t sdk_f_1db570(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_1db580  (orig 0x1db580, ptr_add)
void* sdk_f_1db580(void* a0) { return (char*)a0 + 32; }

// sub_1db660  (orig 0x1db660, getter)
uint32_t sdk_f_1db660(void* a0) { return *(uint32_t*)((char*)(a0) + 236); }

// sub_1db670  (orig 0x1db670, getter)
uint32_t sdk_f_1db670(void* a0) { return *(uint32_t*)((char*)(a0) + 240); }

// sub_1db680  (orig 0x1db680, ptr_add)
void* sdk_f_1db680(void* a0) { return (char*)a0 + 248; }

// sub_1db690  (orig 0x1db690, ptr_add)
void* sdk_f_1db690(void* a0) { return (char*)a0 + 352; }

// sub_1db6a0  (orig 0x1db6a0, ptr_add)
void* sdk_f_1db6a0(void* a0) { return (char*)a0 + 352; }

// sub_1db6b0  (orig 0x1db6b0, ptr_add)
void* sdk_f_1db6b0(void* a0) { return (char*)a0 + 384; }

// sub_1db740  (orig 0x1db740, getter)
uint8_t sdk_f_1db740(void* a0) { return *(uint8_t*)((char*)(a0) + 345); }

// sub_1db750  (orig 0x1db750, setter-chain-zero)
void sdk_f_1db750(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 240) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 224) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 208) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 192) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 176) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 160) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 144) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 128) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 112) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 96) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1db7a0  (orig 0x1db7a0, getter)
uint64_t sdk_f_1db7a0(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_1db7b0  (orig 0x1db7b0, ptr_add)
void* sdk_f_1db7b0(void* a0) { return (char*)a0 + 8; }

// sub_1db7c0  (orig 0x1db7c0, ptr_add)
void* sdk_f_1db7c0(void* a0) { return (char*)a0 + 40; }

// sub_1db800  (orig 0x1db800, getter)
uint8_t sdk_f_1db800(void* a0) { return *(uint8_t*)((char*)(a0) + 56); }

// sub_1dbbd0  (orig 0x1dbbd0, setter-chain-zero)
void sdk_f_1dbbd0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 240) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 224) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 208) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 192) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 176) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 160) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 144) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 128) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 112) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 96) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1dbc20  (orig 0x1dbc20, getter)
uint64_t sdk_f_1dbc20(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_1dbc30  (orig 0x1dbc30, ptr_add)
void* sdk_f_1dbc30(void* a0) { return (char*)a0 + 8; }

// sub_1dbc40  (orig 0x1dbc40, getter)
uint8_t sdk_f_1dbc40(void* a0) { return *(uint8_t*)((char*)(a0) + 176); }

// sub_1dbc50  (orig 0x1dbc50, getter)
uint8_t sdk_f_1dbc50(void* a0) { return *(uint8_t*)((char*)(a0) + 177); }

// sub_1dbc60  (orig 0x1dbc60, getter)
uint8_t sdk_f_1dbc60(void* a0) { return *(uint8_t*)((char*)(a0) + 184); }

// sub_1dbc70  (orig 0x1dbc70, setter-chain-zero)
void sdk_f_1dbc70(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 208) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 192) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 176) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 160) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 144) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 128) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 112) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 96) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1dbd30  (orig 0x1dbd30, setter-chain-zero)
void sdk_f_1dbd30(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 208) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint8_t*)((char*)a0 + 24) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 192) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 176) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 160) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 144) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 128) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 112) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 96) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
}

// sub_1dbea0  (orig 0x1dbea0, straight)
void sdk_f_1dbea0(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 24) = (uint8_t)k0;
}

// sub_1dbeb0  (orig 0x1dbeb0, straight)
void sdk_f_1dbeb0(void* a0) {
    uint32_t k0 = 2;
    *(uint8_t*)((char*)(a0) + 24) = (uint8_t)k0;
}

// sub_1dbf70  (orig 0x1dbf70, setter-chain-zero)
void sdk_f_1dbf70(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 208) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 192) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 176) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 160) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 144) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 128) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 112) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 96) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1dbfb0  (orig 0x1dbfb0, getter)
uint32_t sdk_f_1dbfb0(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_1dbfc0  (orig 0x1dbfc0, ret_only)
void sdk_f_1dbfc0() {}

// sub_1dbfd0  (orig 0x1dbfd0, ptr_add)
void* sdk_f_1dbfd0(void* a0) { return (char*)a0 + 16; }

// sub_1dbfe0  (orig 0x1dbfe0, ptr_add)
void* sdk_f_1dbfe0(void* a0) { return (char*)a0 + 16; }

// sub_1dc070  (orig 0x1dc070, getter)
uint8_t sdk_f_1dc070(void* a0) { return *(uint8_t*)((char*)(a0) + 28); }

// sub_1dc080  (orig 0x1dc080, setter-chain-zero)
void sdk_f_1dc080(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 208) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 192) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 176) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 160) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 144) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 128) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 112) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 96) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1dc0c0  (orig 0x1dc0c0, getter)
uint32_t sdk_f_1dc0c0(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_1dc0d0  (orig 0x1dc0d0, ret_only)
void sdk_f_1dc0d0() {}

// sub_1dc0e0  (orig 0x1dc0e0, ptr_add)
void* sdk_f_1dc0e0(void* a0) { return (char*)a0 + 16; }

// sub_1dc0f0  (orig 0x1dc0f0, ptr_add)
void* sdk_f_1dc0f0(void* a0) { return (char*)a0 + 16; }

// sub_1dc140  (orig 0x1dc140, setter-chain-zero)
void sdk_f_1dc140(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 240) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 224) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 208) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 192) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 176) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 160) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 144) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 128) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 112) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 96) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1dc190  (orig 0x1dc190, getter)
uint64_t sdk_f_1dc190(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_1dc1a0  (orig 0x1dc1a0, ptr_add)
void* sdk_f_1dc1a0(void* a0) { return (char*)a0 + 8; }

// sub_1dc250  (orig 0x1dc250, getter)
uint8_t sdk_f_1dc250(void* a0) { return *(uint8_t*)((char*)(a0) + 208); }

// sub_1dc270  (orig 0x1dc270, getter)
uint64_t sdk_f_1dc270(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_1dc280  (orig 0x1dc280, ptr_add)
void* sdk_f_1dc280(void* a0) { return (char*)a0 + 8; }

// sub_1dc330  (orig 0x1dc330, straight-line)
uint64_t sdk_f_1dc330(uint64_t a0, uint32_t a1) { return ((((uint64_t)a0)) + ((((int64_t)(((int32_t)(((uint32_t)a1)))))) * (((int64_t)(((int32_t)(40))))))) + (208); }

// sub_1dc340  (orig 0x1dc340, getter)
uint8_t sdk_f_1dc340(void* a0) { return *(uint8_t*)((char*)(a0) + 1008); }

// sub_1dc410  (orig 0x1dc410, getter)
uint32_t sdk_f_1dc410(void* a0) { return *(uint32_t*)((char*)(a0) + 16); }

// sub_1dc4f0  (orig 0x1dc4f0, getter)
uint8_t sdk_f_1dc4f0(void* a0) { return *(uint8_t*)((char*)(a0) + 24); }

// sub_1dc5d0  (orig 0x1dc5d0, ptr_add)
void* sdk_f_1dc5d0(void* a0) { return (char*)a0 + 32; }

// sub_1dc5e0  (orig 0x1dc5e0, ptr_add)
void* sdk_f_1dc5e0(void* a0) { return (char*)a0 + 64; }

// sub_1dc6b0  (orig 0x1dc6b0, ptr_add)
void* sdk_f_1dc6b0(void* a0) { return (char*)a0 + 72; }

// sub_1dc6c0  (orig 0x1dc6c0, getter)
uint32_t sdk_f_1dc6c0(void* a0) { return *(uint32_t*)((char*)(a0) + 20); }

// sub_1dc860  (orig 0x1dc860, setter-chain-zero)
void sdk_f_1dc860(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1dc930  (orig 0x1dc930, getter)
uint8_t sdk_f_1dc930(void* a0) { return *(uint8_t*)((char*)(a0) + 25); }

// sub_1dca20  (orig 0x1dca20, getter)
uint8_t sdk_f_1dca20(void* a0) { return *(uint8_t*)((char*)(a0) + 24); }

// sub_1dcb00  (orig 0x1dcb00, getter)
uint8_t sdk_f_1dcb00(void* a0) { return *(uint8_t*)((char*)(a0) + 26); }

// sub_1dcf90  (orig 0x1dcf90, getter)
uint64_t sdk_f_1dcf90(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_1dcfa0  (orig 0x1dcfa0, getter)
uint32_t sdk_f_1dcfa0(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_1dcfb0  (orig 0x1dcfb0, ptr_add)
void* sdk_f_1dcfb0(void* a0) { return (char*)a0 + 16; }

// sub_1dcfc0  (orig 0x1dcfc0, getter)
uint8_t sdk_f_1dcfc0(void* a0) { return *(uint8_t*)((char*)(a0) + 912); }

// sub_1debb0  (orig 0x1debb0, ptr_add)
void* sdk_f_1debb0(void* a0) { return (char*)a0 + 32; }

// sub_1dedb0  (orig 0x1dedb0, ptr_add)
void* sdk_f_1dedb0(void* a0) { return (char*)a0 + 8; }

// sub_1dedc0  (orig 0x1dedc0, straight)
void* sdk_f_1dedc0(void* a0) { return (char*)(a0) - 24; }

// sub_1deef0  (orig 0x1deef0, ptr_add)
void* sdk_f_1deef0(void* a0) { return (char*)a0 + 32; }

// sub_1def20  (orig 0x1def20, call)
extern void callee_511510();
uint64_t sdk_f_1def20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df020  (orig 0x1df020, call)
extern void callee_51a5d0();
uint64_t sdk_f_1df020(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, void* a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a5d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(*(uint64_t*)((char*)(a4)))), ((uintptr_t)(*(uint64_t*)((char*)(a4) + 8))), ((uintptr_t)(10110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df0e0  (orig 0x1df0e0, call)
extern void callee_51a600();
uint64_t sdk_f_1df0e0(void* a0, uint64_t a1, void* a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a600)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (3))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(10400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df120  (orig 0x1df120, call)
extern void callee_51a610();
uint64_t sdk_f_1df120(void* a0, void* a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a610)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (8))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (3))), ((uintptr_t)(10500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df160  (orig 0x1df160, call)
extern void callee_511480();
uint64_t sdk_f_1df160(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10600)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df180  (orig 0x1df180, call)
extern void callee_511480();
uint64_t sdk_f_1df180(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10601)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df1d0  (orig 0x1df1d0, call)
extern void callee_51a630();
uint64_t sdk_f_1df1d0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a630)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(64)), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(10700)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df200  (orig 0x1df200, call)
extern void callee_51a640();
uint64_t sdk_f_1df200(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a640)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(64)), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(10701)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df280  (orig 0x1df280, call)
extern void callee_51a660();
uint64_t sdk_f_1df280(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a660)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(11000)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df2b0  (orig 0x1df2b0, call)
extern void callee_51a670();
uint64_t sdk_f_1df2b0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(20100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df2d0  (orig 0x1df2d0, call)
extern void callee_51a680();
uint64_t sdk_f_1df2d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a680)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(20101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df320  (orig 0x1df320, call)
extern void callee_511480();
uint64_t sdk_f_1df320(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(20103)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df340  (orig 0x1df340, call)
extern void callee_511480();
uint64_t sdk_f_1df340(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(20104)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df390  (orig 0x1df390, call)
extern void callee_51a6b0();
uint64_t sdk_f_1df390(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a6b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(20200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df3f0  (orig 0x1df3f0, call)
extern void callee_51a6d0();
uint64_t sdk_f_1df3f0(void* a0, uint64_t a1, void* a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a6d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (8))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(20300)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df480  (orig 0x1df480, call)
extern void callee_51a6f0();
uint64_t sdk_f_1df480(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a6f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(20302)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df4e0  (orig 0x1df4e0, call)
extern void callee_51a6d0();
uint64_t sdk_f_1df4e0(void* a0, uint64_t a1, void* a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a6d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (10))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(20304)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df520  (orig 0x1df520, call)
extern void callee_51a6d0();
uint64_t sdk_f_1df520(void* a0, uint64_t a1, void* a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a6d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (9))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(20400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df560  (orig 0x1df560, call)
extern void callee_511480();
uint64_t sdk_f_1df560(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(20401)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df580  (orig 0x1df580, call)
extern void callee_51a610();
uint64_t sdk_f_1df580(void* a0, void* a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a610)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (10))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (3))), ((uintptr_t)(20500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df5c0  (orig 0x1df5c0, call)
extern void callee_51a710();
uint64_t sdk_f_1df5c0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(20501)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df610  (orig 0x1df610, call)
extern void callee_51a6d0();
uint64_t sdk_f_1df610(void* a0, uint64_t a1, void* a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a6d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (8))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(20700)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df650  (orig 0x1df650, call)
extern void callee_51a730();
uint64_t sdk_f_1df650(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a730)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(20701)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df6a0  (orig 0x1df6a0, call)
extern void callee_511480();
uint64_t sdk_f_1df6a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(20801)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df6c0  (orig 0x1df6c0, call)
extern void callee_511510();
uint64_t sdk_f_1df6c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20900)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df710  (orig 0x1df710, call)
extern void callee_511480();
uint64_t sdk_f_1df710(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df730  (orig 0x1df730, call)
extern void callee_5115f0();
uint64_t sdk_f_1df730(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df750  (orig 0x1df750, call)
extern void callee_5115f0();
uint64_t sdk_f_1df750(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df770  (orig 0x1df770, call)
extern void callee_51a760();
uint64_t sdk_f_1df770(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(30120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df7a0  (orig 0x1df7a0, call)
extern void callee_51a760();
uint64_t sdk_f_1df7a0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(30121)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df7d0  (orig 0x1df7d0, call)
extern void callee_51a770();
uint64_t sdk_f_1df7d0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a770)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(30200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df840  (orig 0x1df840, call)
extern void callee_5115f0();
uint64_t sdk_f_1df840(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30202)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df860  (orig 0x1df860, call)
extern void callee_5115f0();
uint64_t sdk_f_1df860(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30203)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df880  (orig 0x1df880, call)
extern void callee_5115f0();
uint64_t sdk_f_1df880(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30204)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df8a0  (orig 0x1df8a0, call)
extern void callee_5115f0();
uint64_t sdk_f_1df8a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30205)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df8c0  (orig 0x1df8c0, call)
extern void callee_51a790();
uint64_t sdk_f_1df8c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a790)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30210)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df8e0  (orig 0x1df8e0, call)
extern void callee_51a7a0();
uint64_t sdk_f_1df8e0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, void* a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a7a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(*(uint64_t*)((char*)(a4)))), ((uintptr_t)(*(uint64_t*)((char*)(a4) + 8))), ((uintptr_t)(30211)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df910  (orig 0x1df910, call)
extern void callee_5115f0();
uint64_t sdk_f_1df910(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30212)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df930  (orig 0x1df930, call)
extern void callee_51a5d0();
uint64_t sdk_f_1df930(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, void* a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a5d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(*(uint64_t*)((char*)(a4)))), ((uintptr_t)(*(uint64_t*)((char*)(a4) + 8))), ((uintptr_t)(30213)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df960  (orig 0x1df960, call)
extern void callee_51a7b0();
uint64_t sdk_f_1df960(void* a0, uint64_t a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a7b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(30214)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1df9d0  (orig 0x1df9d0, call)
extern void callee_5115f0();
uint64_t sdk_f_1df9d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30216)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfa20  (orig 0x1dfa20, call)
extern void callee_51a7d0();
uint64_t sdk_f_1dfa20(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a7d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4096)), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(30300)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfa50  (orig 0x1dfa50, call)
extern void callee_5116d0();
uint64_t sdk_f_1dfa50(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5116d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(30301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfa80  (orig 0x1dfa80, call)
extern void callee_51a770();
uint64_t sdk_f_1dfa80(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a770)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(30400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfae0  (orig 0x1dfae0, call)
extern void callee_5115f0();
uint64_t sdk_f_1dfae0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(30402)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfb30  (orig 0x1dfb30, call)
extern void callee_511480();
uint64_t sdk_f_1dfb30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30700)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfb50  (orig 0x1dfb50, call)
extern void callee_5116d0();
uint64_t sdk_f_1dfb50(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5116d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(30810)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfb80  (orig 0x1dfb80, call)
extern void callee_51a800();
uint64_t sdk_f_1dfb80(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51a800)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(30811)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfbb0  (orig 0x1dfbb0, call)
extern void callee_5116d0();
uint64_t sdk_f_1dfbb0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5116d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(30812)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfbe0  (orig 0x1dfbe0, call)
extern void callee_511480();
uint64_t sdk_f_1dfbe0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30820)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfc00  (orig 0x1dfc00, call)
extern void callee_511480();
uint64_t sdk_f_1dfc00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30830)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfc20  (orig 0x1dfc20, call)
extern void callee_511480();
uint64_t sdk_f_1dfc20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(49900)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1dfc40  (orig 0x1dfc40, ptr_add)
void* sdk_f_1dfc40(void* a0) { return (char*)a0 + 8; }

// sub_1dfc50  (orig 0x1dfc50, straight)
void* sdk_f_1dfc50(void* a0) { return (char*)(a0) - 24; }

// sub_1e49b0  (orig 0x1e49b0, ptr_add)
void* sdk_f_1e49b0(void* a0) { return (char*)a0 + 32; }

// sub_1e49e0  (orig 0x1e49e0, call)
extern void callee_511510();
uint64_t sdk_f_1e49e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1e4a00  (orig 0x1e4a00, call)
extern void callee_5113c0();
uint64_t sdk_f_1e4a00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1e4a20  (orig 0x1e4a20, ptr_add)
void* sdk_f_1e4a20(void* a0) { return (char*)a0 + 8; }

// sub_1e4a30  (orig 0x1e4a30, straight)
void* sdk_f_1e4a30(void* a0) { return (char*)(a0) - 24; }

// sub_1e4b60  (orig 0x1e4b60, ptr_add)
void* sdk_f_1e4b60(void* a0) { return (char*)a0 + 32; }

// sub_1e4b70  (orig 0x1e4b70, ptr_add)
void* sdk_f_1e4b70(void* a0) { return (char*)a0 + 8; }

// sub_1e4b80  (orig 0x1e4b80, straight)
void* sdk_f_1e4b80(void* a0) { return (char*)(a0) - 24; }

// sub_1e6670  (orig 0x1e6670, mov_ret)
uint32_t sdk_f_1e6670() { return 1; }

// sub_1e6680  (orig 0x1e6680, compare)
bool sdk_f_1e6680(uint64_t a0) { return (uint64_t)(a0) == (uint64_t)(0); }

// sub_1e6890  (orig 0x1e6890, mov_ret)
uint32_t sdk_f_1e6890() { return 2; }

// sub_1e6a90  (orig 0x1e6a90, straight)
uint64_t sdk_f_1e6a90(uint64_t a0) { return (((uint64_t)a0)) << (2); }

// sub_1e6aa0  (orig 0x1e6aa0, straight)
uint64_t sdk_f_1e6aa0(uint64_t a0) { return (((uint64_t)a0)) << (2); }

// sub_1e6d80  (orig 0x1e6d80, setter-chain-zero)
void sdk_f_1e6d80(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint8_t*)((char*)a0 + 40) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a0 + 16) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint8_t*)((char*)a0 + 96) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a0 + 72) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint8_t*)((char*)a0 + 176) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a0 + 152) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a0 + 136) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint8_t*)((char*)a0 + 232) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a0 + 208) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 160) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 216) = (struct u64x2){ 0, 0 };
}

// sub_1e8540  (orig 0x1e8540, straight)
uint64_t sdk_f_1e8540(void* a0, void* a1, void* a2) {
    *(uint64_t*)((char*)(a1)) = *(uint64_t*)((char*)(a0) + 120);
    *(uint64_t*)((char*)(a2)) = *(uint64_t*)((char*)(a0) + 256);
    return 0;
}

// sub_1e9d10  (orig 0x1e9d10, setter-chain-zero)
void sdk_f_1e9d10(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint8_t*)((char*)a0 + 24) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
}

// sub_1e9d70  (orig 0x1e9d70, setter-chain-zero)
void sdk_f_1e9d70(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint8_t*)((char*)a0 + 24) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
}

// sub_1e9d80  (orig 0x1e9d80, getter)
uint8_t sdk_f_1e9d80(void* a0) { return *(uint8_t*)((char*)(a0) + 24); }

// sub_1eaad0  (orig 0x1eaad0, call)
extern void callee_51aa10();
uint64_t sdk_f_1eaad0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_51aa10)(((uintptr_t)(*(uint64_t*)((char*)(a0) + 8))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1ec370  (orig 0x1ec370, ret_only)
void sdk_f_1ec370() {}

// sub_1ec6c0  (orig 0x1ec6c0, getter)
uint64_t sdk_f_1ec6c0(void* a0) { return *(uint64_t*)((char*)(a0) + 280); }

// sub_1ec6d0  (orig 0x1ec6d0, ptr_add)
void* sdk_f_1ec6d0(void* a0) { return (char*)a0 + 8; }

// sub_1ed0b0  (orig 0x1ed0b0, const-ret)
uint32_t sdk_f_1ed0b0() { return 3258370u; }

// sub_1ed0c0  (orig 0x1ed0c0, const-ret)
uint32_t sdk_f_1ed0c0() { return 3258370u; }

// sub_1ed0d0  (orig 0x1ed0d0, const-ret)
uint32_t sdk_f_1ed0d0() { return 3258370u; }

// sub_1ed0e0  (orig 0x1ed0e0, const-ret)
uint32_t sdk_f_1ed0e0() { return 3258370u; }

// sub_1ed0f0  (orig 0x1ed0f0, const-ret)
uint32_t sdk_f_1ed0f0() { return 3258370u; }

// sub_1ed100  (orig 0x1ed100, const-ret)
uint32_t sdk_f_1ed100() { return 3258370u; }

// sub_1ed110  (orig 0x1ed110, const-ret)
uint32_t sdk_f_1ed110() { return 3258370u; }

// sub_1ed120  (orig 0x1ed120, const-ret)
uint32_t sdk_f_1ed120() { return 3258370u; }

// sub_1ed130  (orig 0x1ed130, mov_ret)
uint64_t sdk_f_1ed130() { return 0; }

// sub_1ed140  (orig 0x1ed140, const-ret)
uint32_t sdk_f_1ed140() { return 3258882u; }

// sub_1ed150  (orig 0x1ed150, mov_ret)
uint64_t sdk_f_1ed150() { return 0; }

// sub_1ed160  (orig 0x1ed160, const-ret)
uint32_t sdk_f_1ed160() { return 3259394u; }

// sub_1ed170  (orig 0x1ed170, const-ret)
uint32_t sdk_f_1ed170() { return 3259394u; }

// sub_1ed4a0  (orig 0x1ed4a0, const-ret)
uint32_t sdk_f_1ed4a0() { return 1536514u; }

// sub_1ed4b0  (orig 0x1ed4b0, const-ret)
uint32_t sdk_f_1ed4b0() { return 1536514u; }

// sub_1ed4c0  (orig 0x1ed4c0, const-ret)
uint32_t sdk_f_1ed4c0() { return 1536514u; }

// sub_1ed7f0  (orig 0x1ed7f0, mov_ret)
uint64_t sdk_f_1ed7f0() { return 0; }

// sub_1ed800  (orig 0x1ed800, const-ret)
uint32_t sdk_f_1ed800() { return 3227650u; }

// sub_1ed810  (orig 0x1ed810, straight)
uint64_t sdk_f_1ed810(void* a0, void* a1) {
    *(uint64_t*)((char*)(a1)) = *(uint64_t*)((char*)(a0) + 16);
    return 0;
}

// sub_1ed880  (orig 0x1ed880, ret_only)
void sdk_f_1ed880() {}

// sub_1ed960  (orig 0x1ed960, const-ret)
uint32_t sdk_f_1ed960() { return 3175938u; }

// sub_1ed970  (orig 0x1ed970, mov_ret)
uint64_t sdk_f_1ed970() { return 0; }

// sub_1ed980  (orig 0x1ed980, const-ret)
uint32_t sdk_f_1ed980() { return 3175938u; }

// sub_1ed990  (orig 0x1ed990, straight-line)
uint64_t sdk_f_1ed990(void* a0, void* a1) {
    *(uint64_t*)((char*)(a1)) = (*(uint64_t*)((char*)(a0) + 24)) - (*(uint64_t*)((char*)(a0) + 16));
    return 0;
}

// sub_1eda30  (orig 0x1eda30, ret_only)
void sdk_f_1eda30() {}

// sub_1edac0  (orig 0x1edac0, ret_only)
void sdk_f_1edac0() {}

// sub_1ee5c0  (orig 0x1ee5c0, getter)
uint32_t sdk_f_1ee5c0(void* a0) { return *(uint32_t*)((char*)(a0) + 40); }

// sub_1eeb90  (orig 0x1eeb90, getter)
uint32_t sdk_f_1eeb90(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_1f0270  (orig 0x1f0270, compare)
bool sdk_f_1f0270(void* a0) { return (uint8_t)(*(uint8_t*)((char*)(a0))) == (uint64_t)(64); }

// sub_1f4310  (orig 0x1f4310, ret_only)
void sdk_f_1f4310() {}

// sub_1f56f0  (orig 0x1f56f0, call)
extern void callee_51b040();
uint64_t sdk_f_1f56f0(uint64_t a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b040)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(0)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f5ae0  (orig 0x1f5ae0, ret_only)
void sdk_f_1f5ae0() {}

// sub_1f7b20  (orig 0x1f7b20, setter)
void sdk_f_1f7b20(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0)) = a1; }

// sub_1f7bb0  (orig 0x1f7bb0, ret_only)
void sdk_f_1f7bb0() {}

// sub_1f8ec0  (orig 0x1f8ec0, ret_only)
void sdk_f_1f8ec0() {}

// sub_1f8f60  (orig 0x1f8f60, ptr_add)
void* sdk_f_1f8f60(void* a0) { return (char*)a0 + 32; }

// sub_1f8f70  (orig 0x1f8f70, call)
extern void callee_511440();
uint64_t sdk_f_1f8f70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f9380  (orig 0x1f9380, call)
extern void callee_511510();
uint64_t sdk_f_1f9380(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f94d0  (orig 0x1f94d0, call)
extern void callee_511510();
uint64_t sdk_f_1f94d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f94f0  (orig 0x1f94f0, call)
extern void callee_511670();
uint64_t sdk_f_1f94f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f9510  (orig 0x1f9510, call)
extern void callee_51b120();
uint64_t sdk_f_1f9510(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b120)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f9530  (orig 0x1f9530, call)
extern void callee_51b130();
uint64_t sdk_f_1f9530(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b130)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f9550  (orig 0x1f9550, call)
extern void callee_51b140();
uint64_t sdk_f_1f9550(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f9580  (orig 0x1f9580, call)
extern void callee_51b150();
uint64_t sdk_f_1f9580(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b150)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f95b0  (orig 0x1f95b0, call)
extern void callee_511510();
uint64_t sdk_f_1f95b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(26)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f95d0  (orig 0x1f95d0, call)
extern void callee_5114b0();
uint64_t sdk_f_1f95d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(27)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f95f0  (orig 0x1f95f0, call)
extern void callee_51b160();
uint64_t sdk_f_1f95f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b160)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(28)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f9780  (orig 0x1f9780, call)
extern void callee_51b170();
uint64_t sdk_f_1f9780(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b170)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f97b0  (orig 0x1f97b0, call)
extern void callee_51b180();
uint64_t sdk_f_1f97b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (65535))), ((uintptr_t)(33)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f97e0  (orig 0x1f97e0, call)
extern void callee_51b190();
uint64_t sdk_f_1f97e0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b190)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (65535))), ((uintptr_t)(34)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f9810  (orig 0x1f9810, call)
extern void callee_51b1a0();
uint64_t sdk_f_1f9810(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b1a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(35)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f9ab0  (orig 0x1f9ab0, call)
extern void callee_51b1e0();
uint64_t sdk_f_1f9ab0(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b1e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(59)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1f9d50  (orig 0x1f9d50, call)
extern void callee_51b150();
uint64_t sdk_f_1f9d50(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b150)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fa9d0  (orig 0x1fa9d0, call)
extern void callee_511510();
uint64_t sdk_f_1fa9d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(511)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fa9f0  (orig 0x1fa9f0, call)
extern void callee_51b270();
uint64_t sdk_f_1fa9f0(void* a0, uint32_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(520)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faa20  (orig 0x1faa20, call)
extern void callee_51b280();
uint64_t sdk_f_1faa20(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(601)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faa40  (orig 0x1faa40, call)
extern void callee_51b290();
uint64_t sdk_f_1faa40(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b290)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(602)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faa70  (orig 0x1faa70, call)
extern void callee_511670();
uint64_t sdk_f_1faa70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(603)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faa90  (orig 0x1faa90, call)
extern void callee_511670();
uint64_t sdk_f_1faa90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(604)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faab0  (orig 0x1faab0, call)
extern void callee_511510();
uint64_t sdk_f_1faab0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(605)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faad0  (orig 0x1faad0, call)
extern void callee_51b2a0();
uint64_t sdk_f_1faad0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b2a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (255))), ((uintptr_t)(606)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fab00  (orig 0x1fab00, call)
extern void callee_51b2b0();
uint64_t sdk_f_1fab00(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b2b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(607)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fab20  (orig 0x1fab20, call)
extern void callee_511510();
uint64_t sdk_f_1fab20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(608)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fab40  (orig 0x1fab40, call)
extern void callee_51b2c0();
uint64_t sdk_f_1fab40(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b2c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(769)), ((uintptr_t)(609)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fab70  (orig 0x1fab70, call)
extern void callee_51b2d0();
uint64_t sdk_f_1fab70(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b2d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(769)), ((uintptr_t)(610)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faba0  (orig 0x1faba0, call)
extern void callee_5151b0();
uint64_t sdk_f_1faba0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5151b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(611)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fabd0  (orig 0x1fabd0, call)
extern void callee_51b2e0();
uint64_t sdk_f_1fabd0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b2e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)(612)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fac00  (orig 0x1fac00, call)
extern void callee_51b2f0();
uint64_t sdk_f_1fac00(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b2f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(613)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fac30  (orig 0x1fac30, call)
extern void callee_51b150();
uint64_t sdk_f_1fac30(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b150)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(614)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fac60  (orig 0x1fac60, call)
extern void callee_51b300();
uint64_t sdk_f_1fac60(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b300)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(615)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fac90  (orig 0x1fac90, call)
extern void callee_51b300();
uint64_t sdk_f_1fac90(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b300)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(616)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1facc0  (orig 0x1facc0, call)
extern void callee_511480();
uint64_t sdk_f_1facc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(617)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1face0  (orig 0x1face0, call)
extern void callee_51b310();
uint64_t sdk_f_1face0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b310)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(620)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fad00  (orig 0x1fad00, call)
extern void callee_512050();
uint64_t sdk_f_1fad00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(630)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fad30  (orig 0x1fad30, call)
extern void callee_5114b0();
uint64_t sdk_f_1fad30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(631)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fad50  (orig 0x1fad50, call)
extern void callee_5114b0();
uint64_t sdk_f_1fad50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(640)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fae10  (orig 0x1fae10, call)
extern void callee_511570();
uint64_t sdk_f_1fae10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(701)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fae30  (orig 0x1fae30, call)
extern void callee_511770();
uint64_t sdk_f_1fae30(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511770)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(702)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fae50  (orig 0x1fae50, call)
extern void callee_511670();
uint64_t sdk_f_1fae50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(710)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fae70  (orig 0x1fae70, call)
extern void callee_511670();
uint64_t sdk_f_1fae70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(720)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fae90  (orig 0x1fae90, call)
extern void callee_51b320();
uint64_t sdk_f_1fae90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b320)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(800)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faeb0  (orig 0x1faeb0, call)
extern void callee_51b330();
uint64_t sdk_f_1faeb0(void* a0, void* a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b330)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(810)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faee0  (orig 0x1faee0, call)
extern void callee_51b340();
uint64_t sdk_f_1faee0(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b340)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(769)), ((uintptr_t)(1000)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faf10  (orig 0x1faf10, call)
extern void callee_51b350();
uint64_t sdk_f_1faf10(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b350)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faf30  (orig 0x1faf30, call)
extern void callee_51b360();
uint64_t sdk_f_1faf30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b360)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(769)), ((uintptr_t)(1002)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faf60  (orig 0x1faf60, call)
extern void callee_511510();
uint64_t sdk_f_1faf60(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1003)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1faf80  (orig 0x1faf80, call)
extern void callee_511780();
uint64_t sdk_f_1faf80(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(1004)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fafb0  (orig 0x1fafb0, call)
extern void callee_511390();
uint64_t sdk_f_1fafb0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1005)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fafd0  (orig 0x1fafd0, call)
extern void callee_51b140();
uint64_t sdk_f_1fafd0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(1006)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fb000  (orig 0x1fb000, call)
extern void callee_511510();
uint64_t sdk_f_1fb000(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1007)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fb0b0  (orig 0x1fb0b0, call)
extern void callee_51b370();
uint64_t sdk_f_1fb0b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1009)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fb0d0  (orig 0x1fb0d0, call)
extern void callee_512060();
uint64_t sdk_f_1fb0d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512060)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1011)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fb0f0  (orig 0x1fb0f0, call)
extern void callee_51b140();
uint64_t sdk_f_1fb0f0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(1100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fb120  (orig 0x1fb120, call)
extern void callee_51b380();
uint64_t sdk_f_1fb120(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b380)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(1110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fb1e0  (orig 0x1fb1e0, ptr_add)
void* sdk_f_1fb1e0(void* a0) { return (char*)a0 + 8; }

// sub_1fb1f0  (orig 0x1fb1f0, straight)
void* sdk_f_1fb1f0(void* a0) { return (char*)(a0) - 24; }

// sub_1fc120  (orig 0x1fc120, ptr_add)
void* sdk_f_1fc120(void* a0) { return (char*)a0 + 32; }

// sub_1fc180  (orig 0x1fc180, call)
extern void callee_51b360();
uint64_t sdk_f_1fc180(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b360)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(769)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc1b0  (orig 0x1fc1b0, call)
extern void callee_51b360();
uint64_t sdk_f_1fc1b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b360)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(769)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc1e0  (orig 0x1fc1e0, call)
extern void callee_51b360();
uint64_t sdk_f_1fc1e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b360)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(769)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc210  (orig 0x1fc210, call)
extern void callee_51b360();
uint64_t sdk_f_1fc210(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b360)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(769)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc2a0  (orig 0x1fc2a0, call)
extern void callee_51b3c0();
uint64_t sdk_f_1fc2a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b3c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(769)), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc430  (orig 0x1fc430, call)
extern void callee_511510();
uint64_t sdk_f_1fc430(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc450  (orig 0x1fc450, call)
extern void callee_51b3d0();
uint64_t sdk_f_1fc450(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b3d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(769)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc480  (orig 0x1fc480, call)
extern void callee_51b3d0();
uint64_t sdk_f_1fc480(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b3d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(769)), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc4b0  (orig 0x1fc4b0, call)
extern void callee_51b360();
uint64_t sdk_f_1fc4b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b360)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(769)), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc4e0  (orig 0x1fc4e0, call)
extern void callee_51b3e0();
uint64_t sdk_f_1fc4e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b3e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(769)), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fc560  (orig 0x1fc560, ptr_add)
void* sdk_f_1fc560(void* a0) { return (char*)a0 + 8; }

// sub_1fc570  (orig 0x1fc570, straight)
void* sdk_f_1fc570(void* a0) { return (char*)(a0) - 24; }

// sub_1fd1c0  (orig 0x1fd1c0, ptr_add)
void* sdk_f_1fd1c0(void* a0) { return (char*)a0 + 32; }

// sub_1fd210  (orig 0x1fd210, call)
extern void callee_51b410();
uint64_t sdk_f_1fd210(void* a0, uint64_t a1, void* a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b410)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)((((uint64_t)a4)) & (4294967295))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fd250  (orig 0x1fd250, call)
extern void callee_511510();
uint64_t sdk_f_1fd250(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fd270  (orig 0x1fd270, call)
extern void callee_511670();
uint64_t sdk_f_1fd270(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fd290  (orig 0x1fd290, call)
extern void callee_511520();
uint64_t sdk_f_1fd290(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fd2b0  (orig 0x1fd2b0, call)
extern void callee_51b420();
uint64_t sdk_f_1fd2b0(void* a0, uint64_t a1, uint32_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b420)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fd2e0  (orig 0x1fd2e0, ptr_add)
void* sdk_f_1fd2e0(void* a0) { return (char*)a0 + 8; }

// sub_1fd2f0  (orig 0x1fd2f0, straight)
void* sdk_f_1fd2f0(void* a0) { return (char*)(a0) - 24; }

// sub_1fde10  (orig 0x1fde10, ptr_add)
void* sdk_f_1fde10(void* a0) { return (char*)a0 + 32; }

// sub_1fde50  (orig 0x1fde50, call)
extern void callee_511520();
uint64_t sdk_f_1fde50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1fde70  (orig 0x1fde70, ptr_add)
void* sdk_f_1fde70(void* a0) { return (char*)a0 + 8; }

// sub_1fde80  (orig 0x1fde80, straight)
void* sdk_f_1fde80(void* a0) { return (char*)(a0) - 24; }

// sub_1ff0c0  (orig 0x1ff0c0, ptr_add)
void* sdk_f_1ff0c0(void* a0) { return (char*)a0 + 32; }

// sub_1ff130  (orig 0x1ff130, call)
extern void callee_511510();
uint64_t sdk_f_1ff130(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1ff150  (orig 0x1ff150, call)
extern void callee_511670();
uint64_t sdk_f_1ff150(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1ff170  (orig 0x1ff170, call)
extern void callee_511520();
uint64_t sdk_f_1ff170(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1ff190  (orig 0x1ff190, call)
extern void callee_51b420();
uint64_t sdk_f_1ff190(void* a0, uint64_t a1, uint32_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b420)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_1ff1c0  (orig 0x1ff1c0, ptr_add)
void* sdk_f_1ff1c0(void* a0) { return (char*)a0 + 8; }

// sub_1ff1d0  (orig 0x1ff1d0, straight)
void* sdk_f_1ff1d0(void* a0) { return (char*)(a0) - 24; }

// sub_201370  (orig 0x201370, ptr_add)
void* sdk_f_201370(void* a0) { return (char*)a0 + 32; }

// sub_2013b0  (orig 0x2013b0, ptr_add)
void* sdk_f_2013b0(void* a0) { return (char*)a0 + 8; }

// sub_2013c0  (orig 0x2013c0, straight)
void* sdk_f_2013c0(void* a0) { return (char*)(a0) - 24; }

// sub_2021d0  (orig 0x2021d0, ptr_add)
void* sdk_f_2021d0(void* a0) { return (char*)a0 + 32; }

// sub_202210  (orig 0x202210, call)
extern void callee_51b140();
uint64_t sdk_f_202210(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2023b0  (orig 0x2023b0, ptr_add)
void* sdk_f_2023b0(void* a0) { return (char*)a0 + 8; }

// sub_2023c0  (orig 0x2023c0, straight)
void* sdk_f_2023c0(void* a0) { return (char*)(a0) - 24; }

// sub_202730  (orig 0x202730, ptr_add)
void* sdk_f_202730(void* a0) { return (char*)a0 + 32; }

// sub_202770  (orig 0x202770, call)
extern void callee_511520();
uint64_t sdk_f_202770(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_202790  (orig 0x202790, call)
extern void callee_51b430();
uint64_t sdk_f_202790(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b430)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2027c0  (orig 0x2027c0, call)
extern void callee_512180();
uint64_t sdk_f_2027c0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2027f0  (orig 0x2027f0, ptr_add)
void* sdk_f_2027f0(void* a0) { return (char*)a0 + 8; }

// sub_202800  (orig 0x202800, straight)
void* sdk_f_202800(void* a0) { return (char*)(a0) - 24; }

// sub_202e20  (orig 0x202e20, ptr_add)
void* sdk_f_202e20(void* a0) { return (char*)a0 + 32; }

// sub_202e60  (orig 0x202e60, call)
extern void callee_511520();
uint64_t sdk_f_202e60(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_202e80  (orig 0x202e80, call)
extern void callee_51b140();
uint64_t sdk_f_202e80(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_202eb0  (orig 0x202eb0, call)
extern void callee_511510();
uint64_t sdk_f_202eb0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_202ed0  (orig 0x202ed0, ptr_add)
void* sdk_f_202ed0(void* a0) { return (char*)a0 + 8; }

// sub_202ee0  (orig 0x202ee0, straight)
void* sdk_f_202ee0(void* a0) { return (char*)(a0) - 24; }

// sub_203050  (orig 0x203050, ptr_add)
void* sdk_f_203050(void* a0) { return (char*)a0 + 32; }

// sub_203090  (orig 0x203090, call)
extern void callee_51b140();
uint64_t sdk_f_203090(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203630  (orig 0x203630, call)
extern void callee_51b4c0();
uint64_t sdk_f_203630(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b4c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(69)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203650  (orig 0x203650, ptr_add)
void* sdk_f_203650(void* a0) { return (char*)a0 + 8; }

// sub_203660  (orig 0x203660, straight)
void* sdk_f_203660(void* a0) { return (char*)(a0) - 24; }

// sub_2037d0  (orig 0x2037d0, ptr_add)
void* sdk_f_2037d0(void* a0) { return (char*)a0 + 32; }

// sub_203810  (orig 0x203810, call)
extern void callee_512180();
uint64_t sdk_f_203810(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203970  (orig 0x203970, call)
extern void callee_51b4d0();
uint64_t sdk_f_203970(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b4d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(64)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203990  (orig 0x203990, call)
extern void callee_5123e0();
uint64_t sdk_f_203990(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5123e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2039b0  (orig 0x2039b0, call)
extern void callee_511510();
uint64_t sdk_f_2039b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(66)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2039d0  (orig 0x2039d0, call)
extern void callee_512180();
uint64_t sdk_f_2039d0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(67)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203a00  (orig 0x203a00, call)
extern void callee_5123e0();
uint64_t sdk_f_203a00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5123e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(70)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203a20  (orig 0x203a20, call)
extern void callee_5123e0();
uint64_t sdk_f_203a20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5123e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(71)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203a40  (orig 0x203a40, call)
extern void callee_511510();
uint64_t sdk_f_203a40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(72)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203a60  (orig 0x203a60, call)
extern void callee_51b4e0();
uint64_t sdk_f_203a60(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b4e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203a80  (orig 0x203a80, call)
extern void callee_515220();
uint64_t sdk_f_203a80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(81)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203aa0  (orig 0x203aa0, call)
extern void callee_51b4e0();
uint64_t sdk_f_203aa0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b4e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(96)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203ac0  (orig 0x203ac0, ptr_add)
void* sdk_f_203ac0(void* a0) { return (char*)a0 + 8; }

// sub_203ad0  (orig 0x203ad0, straight)
void* sdk_f_203ad0(void* a0) { return (char*)(a0) - 24; }

// sub_203d90  (orig 0x203d90, ptr_add)
void* sdk_f_203d90(void* a0) { return (char*)a0 + 32; }

// sub_203dc0  (orig 0x203dc0, call)
extern void callee_5114b0();
uint64_t sdk_f_203dc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203de0  (orig 0x203de0, call)
extern void callee_511390();
uint64_t sdk_f_203de0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_203e00  (orig 0x203e00, ptr_add)
void* sdk_f_203e00(void* a0) { return (char*)a0 + 8; }

// sub_203e10  (orig 0x203e10, straight)
void* sdk_f_203e10(void* a0) { return (char*)(a0) - 24; }

// sub_2040d0  (orig 0x2040d0, ptr_add)
void* sdk_f_2040d0(void* a0) { return (char*)a0 + 32; }

// sub_204110  (orig 0x204110, call)
extern void callee_511520();
uint64_t sdk_f_204110(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_204130  (orig 0x204130, ptr_add)
void* sdk_f_204130(void* a0) { return (char*)a0 + 8; }

// sub_204140  (orig 0x204140, straight)
void* sdk_f_204140(void* a0) { return (char*)(a0) - 24; }

// sub_205210  (orig 0x205210, ptr_add)
void* sdk_f_205210(void* a0) { return (char*)a0 + 32; }

// sub_2052e0  (orig 0x2052e0, call)
extern void callee_51b4f0();
uint64_t sdk_f_2052e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b4f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_205300  (orig 0x205300, call)
extern void callee_511510();
uint64_t sdk_f_205300(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(33)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_205320  (orig 0x205320, call)
extern void callee_511510();
uint64_t sdk_f_205320(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(34)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_205340  (orig 0x205340, call)
extern void callee_512180();
uint64_t sdk_f_205340(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(35)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_205370  (orig 0x205370, call)
extern void callee_511510();
uint64_t sdk_f_205370(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(36)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_205430  (orig 0x205430, call)
extern void callee_51b4e0();
uint64_t sdk_f_205430(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b4e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(64)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_205450  (orig 0x205450, call)
extern void callee_51b4e0();
uint64_t sdk_f_205450(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b4e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_205470  (orig 0x205470, ptr_add)
void* sdk_f_205470(void* a0) { return (char*)a0 + 8; }

// sub_205480  (orig 0x205480, straight)
void* sdk_f_205480(void* a0) { return (char*)(a0) - 24; }

// sub_205750  (orig 0x205750, ptr_add)
void* sdk_f_205750(void* a0) { return (char*)a0 + 32; }

// sub_205790  (orig 0x205790, ptr_add)
void* sdk_f_205790(void* a0) { return (char*)a0 + 8; }

// sub_2057a0  (orig 0x2057a0, straight)
void* sdk_f_2057a0(void* a0) { return (char*)(a0) - 24; }

// sub_205f20  (orig 0x205f20, ptr_add)
void* sdk_f_205f20(void* a0) { return (char*)a0 + 32; }

// sub_205f30  (orig 0x205f30, ptr_add)
void* sdk_f_205f30(void* a0) { return (char*)a0 + 8; }

// sub_205f40  (orig 0x205f40, straight)
void* sdk_f_205f40(void* a0) { return (char*)(a0) - 24; }

// sub_2064c0  (orig 0x2064c0, ptr_add)
void* sdk_f_2064c0(void* a0) { return (char*)a0 + 32; }

// sub_2064f0  (orig 0x2064f0, call)
extern void callee_511520();
uint64_t sdk_f_2064f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206540  (orig 0x206540, call)
extern void callee_511520();
uint64_t sdk_f_206540(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206560  (orig 0x206560, call)
extern void callee_511520();
uint64_t sdk_f_206560(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2065e0  (orig 0x2065e0, call)
extern void callee_511520();
uint64_t sdk_f_2065e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206600  (orig 0x206600, call)
extern void callee_511780();
uint64_t sdk_f_206600(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206630  (orig 0x206630, call)
extern void callee_51b520();
uint64_t sdk_f_206630(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206660  (orig 0x206660, call)
extern void callee_511390();
uint64_t sdk_f_206660(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(112)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2066e0  (orig 0x2066e0, call)
extern void callee_511510();
uint64_t sdk_f_2066e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(115)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206700  (orig 0x206700, call)
extern void callee_511510();
uint64_t sdk_f_206700(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(116)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206720  (orig 0x206720, call)
extern void callee_5114b0();
uint64_t sdk_f_206720(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206740  (orig 0x206740, call)
extern void callee_512170();
uint64_t sdk_f_206740(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512170)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(201)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206770  (orig 0x206770, call)
extern void callee_511390();
uint64_t sdk_f_206770(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(202)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206790  (orig 0x206790, call)
extern void callee_51b530();
uint64_t sdk_f_206790(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b530)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(203)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2067c0  (orig 0x2067c0, call)
extern void callee_511510();
uint64_t sdk_f_2067c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(204)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2067e0  (orig 0x2067e0, call)
extern void callee_51b540();
uint64_t sdk_f_2067e0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b540)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(205)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206810  (orig 0x206810, call)
extern void callee_51b550();
uint64_t sdk_f_206810(void* a0, void* a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b550)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(206)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2068f0  (orig 0x2068f0, call)
extern void callee_512050();
uint64_t sdk_f_2068f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(210)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206920  (orig 0x206920, call)
extern void callee_51b550();
uint64_t sdk_f_206920(void* a0, void* a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b550)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(211)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206a00  (orig 0x206a00, call)
extern void callee_511510();
uint64_t sdk_f_206a00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(215)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206a20  (orig 0x206a20, call)
extern void callee_51b580();
uint64_t sdk_f_206a20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b580)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(216)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206a40  (orig 0x206a40, call)
extern void callee_51b590();
uint64_t sdk_f_206a40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b590)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(217)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206a90  (orig 0x206a90, call)
extern void callee_511780();
uint64_t sdk_f_206a90(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(300)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206ac0  (orig 0x206ac0, call)
extern void callee_511390();
uint64_t sdk_f_206ac0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206ae0  (orig 0x206ae0, call)
extern void callee_511510();
uint64_t sdk_f_206ae0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206b00  (orig 0x206b00, call)
extern void callee_511510();
uint64_t sdk_f_206b00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(401)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206b20  (orig 0x206b20, call)
extern void callee_51b5a0();
uint64_t sdk_f_206b20(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b5a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(402)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206b50  (orig 0x206b50, call)
extern void callee_51b5b0();
uint64_t sdk_f_206b50(void* a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b5b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)((((uint64_t)a5)) & (1))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206b90  (orig 0x206b90, call)
extern void callee_511780();
uint64_t sdk_f_206b90(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(501)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_206bc0  (orig 0x206bc0, ptr_add)
void* sdk_f_206bc0(void* a0) { return (char*)a0 + 8; }

// sub_206bd0  (orig 0x206bd0, straight)
void* sdk_f_206bd0(void* a0) { return (char*)(a0) - 24; }

// sub_208210  (orig 0x208210, ptr_add)
void* sdk_f_208210(void* a0) { return (char*)a0 + 32; }

// sub_208240  (orig 0x208240, ptr_add)
void* sdk_f_208240(void* a0) { return (char*)a0 + 8; }

// sub_208250  (orig 0x208250, straight)
void* sdk_f_208250(void* a0) { return (char*)(a0) - 24; }

// sub_20a680  (orig 0x20a680, ptr_add)
void* sdk_f_20a680(void* a0) { return (char*)a0 + 32; }

// sub_20a6e0  (orig 0x20a6e0, call)
extern void callee_511510();
uint64_t sdk_f_20a6e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_20a700  (orig 0x20a700, ptr_add)
void* sdk_f_20a700(void* a0) { return (char*)a0 + 8; }

// sub_20a710  (orig 0x20a710, straight)
void* sdk_f_20a710(void* a0) { return (char*)(a0) - 24; }

// sub_20afa0  (orig 0x20afa0, ptr_add)
void* sdk_f_20afa0(void* a0) { return (char*)a0 + 32; }

// sub_20b060  (orig 0x20b060, call)
extern void callee_511770();
uint64_t sdk_f_20b060(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511770)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_20b080  (orig 0x20b080, call)
extern void callee_511440();
uint64_t sdk_f_20b080(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_20b0a0  (orig 0x20b0a0, ptr_add)
void* sdk_f_20b0a0(void* a0) { return (char*)a0 + 8; }

// sub_20b0b0  (orig 0x20b0b0, straight)
void* sdk_f_20b0b0(void* a0) { return (char*)(a0) - 24; }

// sub_20b3f0  (orig 0x20b3f0, ptr_add)
void* sdk_f_20b3f0(void* a0) { return (char*)a0 + 32; }

// sub_20b450  (orig 0x20b450, call)
extern void callee_511670();
uint64_t sdk_f_20b450(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_20b470  (orig 0x20b470, call)
extern void callee_511440();
uint64_t sdk_f_20b470(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_20b490  (orig 0x20b490, call)
extern void callee_512050();
uint64_t sdk_f_20b490(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(256)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_20b4c0  (orig 0x20b4c0, ptr_add)
void* sdk_f_20b4c0(void* a0) { return (char*)a0 + 8; }

// sub_20b4d0  (orig 0x20b4d0, straight)
void* sdk_f_20b4d0(void* a0) { return (char*)(a0) - 24; }

// sub_20b790  (orig 0x20b790, call)
extern void sub_20aac0();
uint64_t sdk_f_20b790(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&sub_20aac0)(((uintptr_t)((char*)(a0) + 16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_20cba0  (orig 0x20cba0, const-ret)
uint32_t sdk_f_20cba0() { return 1536514u; }

// sub_20cbb0  (orig 0x20cbb0, const-ret)
uint32_t sdk_f_20cbb0() { return 1536514u; }

// sub_20fea0  (orig 0x20fea0, ret_only)
void sdk_f_20fea0() {}

// sub_210120  (orig 0x210120, strlit-ret)
const char *sdk_f_210120() { static char g_f_210120[1]; __asm__ volatile("" ::: "memory"); return g_f_210120; }

// sub_210230  (orig 0x210230, compare)
bool sdk_f_210230(uint64_t a0, uint64_t a1) { return (uint64_t)(a0) == (uint64_t)(a1); }

// sub_2147c0  (orig 0x2147c0, call)
extern void callee_51b6c0();
uint64_t sdk_f_2147c0(uint64_t a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b6c0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(0)), ((uintptr_t)(0)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_21a720  (orig 0x21a720, call)
extern void callee_51b790();
uint64_t sdk_f_21a720() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51b790)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_21c950  (orig 0x21c950, call)
extern void callee_51b7d0();
uint64_t sdk_f_21c950(uint64_t a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b7d0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(0)), ((uintptr_t)(0)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_21d580  (orig 0x21d580, ptr_add)
void* sdk_f_21d580(void* a0) { return (char*)a0 + 8; }

// sub_21d890  (orig 0x21d890, ptr_add)
void* sdk_f_21d890(void* a0) { return (char*)a0 + 8; }

// sub_223490  (orig 0x223490, straight-line)
void* sdk_f_223490(void* a0, uint32_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    return ((char *)(char*)(p0) + (uintptr_t)(((int64_t)(((int32_t)(((uint32_t)a1)))))) * 16384);
}

// sub_2236d0  (orig 0x2236d0, straight)
void* sdk_f_2236d0(void* a0, int32_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 8));
    return ((char *)(char*)(p0) + (uintptr_t)(((int32_t)a1)) * 16);
}

// sub_2236e0  (orig 0x2236e0, straight)
uint64_t sdk_f_2236e0(void* a0, uint64_t a1) { return ((((uint64_t)a1)) - (*(uint64_t*)((char*)(a0)))) >> (14); }

// sub_223e70  (orig 0x223e70, straight)
uint64_t sdk_f_223e70(void* a0, uint64_t a1) { return ((((uint64_t)a1)) - (*(uint64_t*)((char*)(a0) + 8))) >> (4); }

// sub_224d70  (orig 0x224d70, setter)
void sdk_f_224d70(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 64) = a1; }

// sub_229700  (orig 0x229700, pair-ret)
struct pair16_f_229700_ { uint64_t f[2]; }; pair16_f_229700_ sdk_f_229700(void* a0) { return *(struct pair16_f_229700_ *)((char*)(a0)); }

// sub_22a710  (orig 0x22a710, ret_only)
void sdk_f_22a710() {}

// sub_22c4c0  (orig 0x22c4c0, const-ret)
uint32_t sdk_f_22c4c0() { return 545482u; }

// sub_22c4d0  (orig 0x22c4d0, const-ret)
uint32_t sdk_f_22c4d0() { return 545482u; }

// sub_22d2a0  (orig 0x22d2a0, getter)
uint32_t sdk_f_22d2a0(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_230f80  (orig 0x230f80, const-ret)
uint32_t sdk_f_230f80() { return 139466u; }

// sub_230f90  (orig 0x230f90, const-ret)
uint32_t sdk_f_230f90() { return 139978u; }

// sub_230fa0  (orig 0x230fa0, const-ret)
uint32_t sdk_f_230fa0() { return 142026u; }

// sub_230fb0  (orig 0x230fb0, call)
extern void callee_51bd80();
uint64_t sdk_f_230fb0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_51bd80)(((uintptr_t)((char*)(a0) + 48)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2310d0  (orig 0x2310d0, compare)
bool sdk_f_2310d0(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 136)) != (uint64_t)(0); }

// sub_2317b0  (orig 0x2317b0, compare)
bool sdk_f_2317b0(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 136)) != (uint64_t)(0); }

// sub_231850  (orig 0x231850, mov_ret)
uint32_t sdk_f_231850() { return 52426; }

// sub_231860  (orig 0x231860, const-ret)
uint32_t sdk_f_231860() { return 139978u; }

// sub_231870  (orig 0x231870, const-ret)
uint32_t sdk_f_231870() { return 142026u; }

// sub_231880  (orig 0x231880, call)
extern void callee_51bd80();
uint64_t sdk_f_231880(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_51bd80)(((uintptr_t)((char*)(a0) + 48)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_239fb0  (orig 0x239fb0, setter)
void sdk_f_239fb0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 48) = a1; }

// sub_239fc0  (orig 0x239fc0, setter)
void sdk_f_239fc0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 52) = a1; }

// sub_23a7c0  (orig 0x23a7c0, getter)
uint8_t sdk_f_23a7c0(void* a0) { return *(uint8_t*)((char*)(a0) + 2); }

// sub_23a8f0  (orig 0x23a8f0, getter)
uint64_t sdk_f_23a8f0(void* a0) { return *(uint64_t*)((char*)(a0) + 72); }

// sub_23a910  (orig 0x23a910, getter)
uint32_t sdk_f_23a910(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_23a930  (orig 0x23a930, getter)
uint8_t sdk_f_23a930(void* a0) { return *(uint8_t*)((char*)(a0) + 1); }

// sub_23a940  (orig 0x23a940, getter)
uint8_t sdk_f_23a940(void* a0) { return *(uint8_t*)((char*)(a0) + 1); }

// sub_23a950  (orig 0x23a950, getter)
uint8_t sdk_f_23a950(void* a0) { return *(uint8_t*)((char*)(a0) + 2); }

// sub_23b1c0  (orig 0x23b1c0, compare)
bool sdk_f_23b1c0(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 136)) != (uint64_t)(0); }

// sub_23b260  (orig 0x23b260, mov_ret)
uint32_t sdk_f_23b260() { return 52426; }

// sub_23b270  (orig 0x23b270, mov_ret)
uint32_t sdk_f_23b270() { return 52938; }

// sub_23b280  (orig 0x23b280, mov_ret)
uint32_t sdk_f_23b280() { return 54474; }

// sub_23b290  (orig 0x23b290, call)
extern void callee_51bd80();
uint64_t sdk_f_23b290(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_51bd80)(((uintptr_t)((char*)(a0) + 48)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_242870  (orig 0x242870, getter)
uint32_t sdk_f_242870(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_242880  (orig 0x242880, getter)
uint8_t sdk_f_242880(void* a0) { return *(uint8_t*)((char*)(a0) + 1); }

// sub_242890  (orig 0x242890, getter)
uint8_t sdk_f_242890(void* a0) { return *(uint8_t*)((char*)(a0) + 2); }

// sub_242e60  (orig 0x242e60, straight-line)
int32_t sdk_f_242e60(uint32_t a0) { return ((int32_t)(((int8_t)(((uint32_t)a0))))); }

// sub_242e70  (orig 0x242e70, straight-line)
int32_t sdk_f_242e70(uint32_t a0) { return ((int32_t)(((int8_t)(((uint32_t)a0))))); }

// sub_242fc0  (orig 0x242fc0, call)
extern void callee_51c0b0();
uint64_t sdk_f_242fc0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c0b0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_242fe0  (orig 0x242fe0, call)
extern void callee_51c0c0();
uint64_t sdk_f_242fe0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c0c0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_243000  (orig 0x243000, call)
extern void callee_51c0d0();
uint64_t sdk_f_243000() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c0d0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_243020  (orig 0x243020, call)
extern void callee_51c0e0();
uint64_t sdk_f_243020() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c0e0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_243040  (orig 0x243040, call)
extern void callee_51c0f0();
uint64_t sdk_f_243040() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c0f0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_243060  (orig 0x243060, call)
extern void callee_51c100();
uint64_t sdk_f_243060() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c100)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_243a10  (orig 0x243a10, call)
extern void callee_51c2f0();
uint64_t sdk_f_243a10() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c2f0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_243c20  (orig 0x243c20, call)
extern void callee_51c360();
uint64_t sdk_f_243c20() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c360)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_243c40  (orig 0x243c40, call)
extern void callee_51c370();
uint64_t sdk_f_243c40() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c370)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2440a0  (orig 0x2440a0, call)
extern void callee_51c440();
uint64_t sdk_f_2440a0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c440)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2440c0  (orig 0x2440c0, call)
extern void callee_51c450();
uint64_t sdk_f_2440c0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c450)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2440e0  (orig 0x2440e0, call)
extern void callee_51c460();
uint64_t sdk_f_2440e0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c460)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244130  (orig 0x244130, call)
extern void callee_51c470();
uint64_t sdk_f_244130(uint64_t a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51c470)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244150  (orig 0x244150, call)
extern void callee_51c480();
uint64_t sdk_f_244150() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c480)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244170  (orig 0x244170, call)
extern void callee_51c490();
uint64_t sdk_f_244170(uint64_t a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51c490)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244190  (orig 0x244190, call)
extern void callee_51c4a0();
uint64_t sdk_f_244190() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c4a0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2441b0  (orig 0x2441b0, call)
extern void callee_51c4b0();
uint64_t sdk_f_2441b0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c4b0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244240  (orig 0x244240, call)
extern void callee_51c4f0();
uint64_t sdk_f_244240() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c4f0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244270  (orig 0x244270, call)
extern void callee_51c510();
uint64_t sdk_f_244270() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c510)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244290  (orig 0x244290, call)
extern void callee_51c520();
uint64_t sdk_f_244290() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c520)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2442b0  (orig 0x2442b0, call)
extern void callee_51c530();
uint64_t sdk_f_2442b0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c530)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2442d0  (orig 0x2442d0, call)
extern void callee_51c540();
uint64_t sdk_f_2442d0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c540)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2442f0  (orig 0x2442f0, call)
extern void callee_51c550();
uint64_t sdk_f_2442f0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c550)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244400  (orig 0x244400, call)
extern void callee_51c590();
uint64_t sdk_f_244400() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c590)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244420  (orig 0x244420, call)
extern void callee_51c5a0();
uint64_t sdk_f_244420() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c5a0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_244440  (orig 0x244440, call)
extern void callee_51c5b0();
uint64_t sdk_f_244440() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51c5b0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_245900  (orig 0x245900, setter-chain-zero)
void sdk_f_245900(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_245940  (orig 0x245940, straight)
uint32_t sdk_f_245940(void* a0) { return (*(uint32_t*)((char*)(a0) + 12)) & (1); }

// sub_2459a0  (orig 0x2459a0, straight)
uint8_t sdk_f_2459a0(void* a0) { return ((*(uint8_t*)((char*)(a0) + 12)) >> (1)) & (1); }

// sub_2459e0  (orig 0x2459e0, straight)
uint8_t sdk_f_2459e0(void* a0) { return ((*(uint8_t*)((char*)(a0) + 12)) >> (2)) & (1); }

// sub_245a60  (orig 0x245a60, getter)
uint32_t sdk_f_245a60(void* a0) { return *(uint32_t*)((char*)(a0) + 16); }

// sub_246c20  (orig 0x246c20, mov_ret)
uint32_t sdk_f_246c20() { return 0; }

// sub_2473f0  (orig 0x2473f0, mov_ret)
uint32_t sdk_f_2473f0() { return 0; }

// sub_247400  (orig 0x247400, mov_ret)
uint32_t sdk_f_247400() { return 4; }

// sub_247410  (orig 0x247410, ret_only)
void sdk_f_247410() {}

// sub_247420  (orig 0x247420, ret_only)
void sdk_f_247420() {}

// sub_24b360  (orig 0x24b360, call)
extern void callee_51d580();
uint64_t sdk_f_24b360() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51d580)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_24b380  (orig 0x24b380, call)
extern void callee_51d590();
uint64_t sdk_f_24b380() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51d590)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_24b530  (orig 0x24b530, call)
extern void callee_51d5f0();
uint64_t sdk_f_24b530(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_51d5f0)(((uintptr_t)(*(uint32_t*)((char*)(a0)))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_24b550  (orig 0x24b550, call)
extern void callee_51d600();
uint64_t sdk_f_24b550(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_51d600)(((uintptr_t)(*(uint32_t*)((char*)(a0)))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_24b570  (orig 0x24b570, call)
extern void callee_51d610();
uint64_t sdk_f_24b570(uint64_t a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_51d610)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(*(uint32_t*)((char*)(a1)))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_24b640  (orig 0x24b640, call)
extern void callee_51d640();
uint64_t sdk_f_24b640() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51d640)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_24b6b0  (orig 0x24b6b0, call)
extern void callee_51d660();
uint64_t sdk_f_24b6b0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51d660)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_24c270  (orig 0x24c270, ret_only)
void sdk_f_24c270() {}

// sub_24ca50  (orig 0x24ca50, getter)
uint32_t sdk_f_24ca50(void* a0) { return *(uint32_t*)((char*)(a0) + 60); }

// sub_24d100  (orig 0x24d100, getter)
uint64_t sdk_f_24d100(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_24d760  (orig 0x24d760, getter)
uint64_t sdk_f_24d760(void* a0) { return *(uint64_t*)((char*)(a0) + 32); }

// sub_24d8b0  (orig 0x24d8b0, setter)
void sdk_f_24d8b0(void* a0) { *(uint8_t*)((char*)(a0) + 57) = 0; }

// sub_24d8c0  (orig 0x24d8c0, getter)
uint8_t sdk_f_24d8c0(void* a0) { return *(uint8_t*)((char*)(a0) + 57); }

// sub_24d9d0  (orig 0x24d9d0, getter)
uint8_t sdk_f_24d9d0(void* a0) { return *(uint8_t*)((char*)(a0) + 58); }

// sub_24da50  (orig 0x24da50, getter)
uint32_t sdk_f_24da50(void* a0) { return *(uint32_t*)((char*)(a0) + 60); }

// sub_24dab0  (orig 0x24dab0, getter)
uint8_t sdk_f_24dab0(void* a0) { return *(uint8_t*)((char*)(a0) + 59); }

// sub_24db50  (orig 0x24db50, getter)
uint32_t sdk_f_24db50(void* a0) { return *(uint32_t*)((char*)(a0) + 68); }

// sub_24dba0  (orig 0x24dba0, getter)
uint32_t sdk_f_24dba0(void* a0) { return *(uint32_t*)((char*)(a0) + 72); }

// sub_24dbf0  (orig 0x24dbf0, getter)
uint32_t sdk_f_24dbf0(void* a0) { return *(uint32_t*)((char*)(a0) + 76); }

// sub_24e150  (orig 0x24e150, ret_only)
void sdk_f_24e150() {}

// sub_251890  (orig 0x251890, ptr_add)
void* sdk_f_251890(void* a0) { return (char*)a0 + 16; }

// sub_2518c0  (orig 0x2518c0, call)
extern void callee_51db70();
uint64_t sdk_f_2518c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51db70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2518e0  (orig 0x2518e0, call)
extern void callee_512700();
uint64_t sdk_f_2518e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251900  (orig 0x251900, call)
extern void callee_512700();
uint64_t sdk_f_251900(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251920  (orig 0x251920, call)
extern void callee_516f00();
uint64_t sdk_f_251920(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_516f00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(((*(uint64_t*)((char*)(a1) + 8)) + (((*(uint64_t*)((char*)(a1) + 8)) << 2))) << (3))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251950  (orig 0x251950, call)
extern void callee_512700();
uint64_t sdk_f_251950(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251970  (orig 0x251970, call)
extern void callee_512700();
uint64_t sdk_f_251970(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251990  (orig 0x251990, call)
extern void callee_51db80();
uint64_t sdk_f_251990(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51db80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2519b0  (orig 0x2519b0, call)
extern void callee_512700();
uint64_t sdk_f_2519b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2519d0  (orig 0x2519d0, call)
extern void callee_512700();
uint64_t sdk_f_2519d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2519f0  (orig 0x2519f0, call)
extern void callee_51db90();
uint64_t sdk_f_2519f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51db90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(31)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251a10  (orig 0x251a10, call)
extern void callee_512700();
uint64_t sdk_f_251a10(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251a30  (orig 0x251a30, call)
extern void callee_512780();
uint64_t sdk_f_251a30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251a60  (orig 0x251a60, call)
extern void callee_51dba0();
uint64_t sdk_f_251a60(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dba0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251a90  (orig 0x251a90, call)
extern void callee_512780();
uint64_t sdk_f_251a90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(52)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251ac0  (orig 0x251ac0, call)
extern void callee_512780();
uint64_t sdk_f_251ac0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251af0  (orig 0x251af0, call)
extern void callee_512700();
uint64_t sdk_f_251af0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(91)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251b10  (orig 0x251b10, call)
extern void callee_512700();
uint64_t sdk_f_251b10(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251b30  (orig 0x251b30, call)
extern void callee_5128a0();
uint64_t sdk_f_251b30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251b50  (orig 0x251b50, call)
extern void callee_512700();
uint64_t sdk_f_251b50(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(112)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251b70  (orig 0x251b70, call)
extern void callee_512700();
uint64_t sdk_f_251b70(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251b90  (orig 0x251b90, call)
extern void callee_5128a0();
uint64_t sdk_f_251b90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(121)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251bb0  (orig 0x251bb0, call)
extern void callee_512700();
uint64_t sdk_f_251bb0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(122)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251bd0  (orig 0x251bd0, call)
extern void callee_512700();
uint64_t sdk_f_251bd0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(123)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251bf0  (orig 0x251bf0, call)
extern void callee_512700();
uint64_t sdk_f_251bf0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(130)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251c10  (orig 0x251c10, call)
extern void callee_5128a0();
uint64_t sdk_f_251c10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(131)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251c30  (orig 0x251c30, call)
extern void callee_512700();
uint64_t sdk_f_251c30(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(132)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251c80  (orig 0x251c80, call)
extern void callee_51dbc0();
uint64_t sdk_f_251c80(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbc0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(134)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251ce0  (orig 0x251ce0, call)
extern void callee_51dbc0();
uint64_t sdk_f_251ce0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbc0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(136)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251d10  (orig 0x251d10, call)
extern void callee_512700();
uint64_t sdk_f_251d10(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(140)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251d30  (orig 0x251d30, call)
extern void callee_5129e0();
uint64_t sdk_f_251d30(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5129e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(141)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251d50  (orig 0x251d50, call)
extern void callee_512700();
uint64_t sdk_f_251d50(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(142)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251db0  (orig 0x251db0, call)
extern void callee_512700();
uint64_t sdk_f_251db0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(201)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251dd0  (orig 0x251dd0, call)
extern void callee_512700();
uint64_t sdk_f_251dd0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(202)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251df0  (orig 0x251df0, call)
extern void callee_5128a0();
uint64_t sdk_f_251df0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(203)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251e10  (orig 0x251e10, call)
extern void callee_5127e0();
uint64_t sdk_f_251e10(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5127e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(204)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251e30  (orig 0x251e30, call)
extern void callee_51dbe0();
uint64_t sdk_f_251e30(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbe0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(205)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251e60  (orig 0x251e60, call)
extern void callee_51dbe0();
uint64_t sdk_f_251e60(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbe0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(206)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251e90  (orig 0x251e90, call)
extern void callee_512700();
uint64_t sdk_f_251e90(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(207)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251eb0  (orig 0x251eb0, call)
extern void callee_5128a0();
uint64_t sdk_f_251eb0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(208)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251ed0  (orig 0x251ed0, call)
extern void callee_51dbf0();
uint64_t sdk_f_251ed0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(209)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251ef0  (orig 0x251ef0, call)
extern void callee_51dc00();
uint64_t sdk_f_251ef0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(210)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251f10  (orig 0x251f10, call)
extern void callee_51dc10();
uint64_t sdk_f_251f10(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(211)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251f30  (orig 0x251f30, call)
extern void callee_512760();
uint64_t sdk_f_251f30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(215)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251f60  (orig 0x251f60, call)
extern void callee_512700();
uint64_t sdk_f_251f60(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(216)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251f80  (orig 0x251f80, call)
extern void callee_51dc20();
uint64_t sdk_f_251f80(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(221)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251fb0  (orig 0x251fb0, call)
extern void callee_512700();
uint64_t sdk_f_251fb0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(222)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_251fd0  (orig 0x251fd0, call)
extern void callee_512700();
uint64_t sdk_f_251fd0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(223)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252030  (orig 0x252030, call)
extern void callee_51dc40();
uint64_t sdk_f_252030(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(225)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252080  (orig 0x252080, call)
extern void callee_51dc60();
uint64_t sdk_f_252080(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc60)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(227)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2520a0  (orig 0x2520a0, call)
extern void callee_512c10();
uint64_t sdk_f_2520a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(228)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2520c0  (orig 0x2520c0, call)
extern void callee_51dc70();
uint64_t sdk_f_2520c0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(229)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2520f0  (orig 0x2520f0, call)
extern void callee_51dc80();
uint64_t sdk_f_2520f0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(230)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252120  (orig 0x252120, call)
extern void callee_5128a0();
uint64_t sdk_f_252120(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(231)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252140  (orig 0x252140, call)
extern void callee_5128a0();
uint64_t sdk_f_252140(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(232)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252160  (orig 0x252160, call)
extern void callee_5128a0();
uint64_t sdk_f_252160(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(233)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252180  (orig 0x252180, call)
extern void callee_512c50();
uint64_t sdk_f_252180(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(234)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2521a0  (orig 0x2521a0, call)
extern void callee_51dc90();
uint64_t sdk_f_2521a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(235)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2521d0  (orig 0x2521d0, call)
extern void callee_5152b0();
uint64_t sdk_f_2521d0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (3))), ((uintptr_t)(301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252200  (orig 0x252200, call)
extern void callee_51dca0();
uint64_t sdk_f_252200(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dca0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(302)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252220  (orig 0x252220, call)
extern void callee_51dcb0();
uint64_t sdk_f_252220(void* a0, uint64_t a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dcb0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (3))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) * (152))), ((uintptr_t)(303)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252260  (orig 0x252260, call)
extern void callee_51dcc0();
uint64_t sdk_f_252260(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dcc0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(321)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252290  (orig 0x252290, call)
extern void callee_512760();
uint64_t sdk_f_252290(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(322)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2522c0  (orig 0x2522c0, call)
extern void callee_512700();
uint64_t sdk_f_2522c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(323)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2522e0  (orig 0x2522e0, call)
extern void callee_512bc0();
uint64_t sdk_f_2522e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512bc0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(324)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252300  (orig 0x252300, call)
extern void callee_512700();
uint64_t sdk_f_252300(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(325)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252320  (orig 0x252320, call)
extern void callee_512700();
uint64_t sdk_f_252320(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(326)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252340  (orig 0x252340, call)
extern void callee_512700();
uint64_t sdk_f_252340(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(327)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252360  (orig 0x252360, call)
extern void callee_512760();
uint64_t sdk_f_252360(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(328)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252390  (orig 0x252390, call)
extern void callee_512700();
uint64_t sdk_f_252390(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(329)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2523b0  (orig 0x2523b0, call)
extern void callee_51dcd0();
uint64_t sdk_f_2523b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dcd0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(330)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2523d0  (orig 0x2523d0, call)
extern void callee_5128a0();
uint64_t sdk_f_2523d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(331)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2523f0  (orig 0x2523f0, call)
extern void callee_51dce0();
uint64_t sdk_f_2523f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dce0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(332)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252410  (orig 0x252410, call)
extern void callee_51dcf0();
uint64_t sdk_f_252410(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51dcf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(350)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252430  (orig 0x252430, call)
extern void callee_512760();
uint64_t sdk_f_252430(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252460  (orig 0x252460, call)
extern void callee_512760();
uint64_t sdk_f_252460(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(401)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_252490  (orig 0x252490, ptr_add)
void* sdk_f_252490(void* a0) { return (char*)a0 + 8; }

// sub_2524a0  (orig 0x2524a0, straight)
void* sdk_f_2524a0(void* a0) { return (char*)(a0) - 8; }

// sub_2546b0  (orig 0x2546b0, ptr_add)
void* sdk_f_2546b0(void* a0) { return (char*)a0 + 16; }

// sub_254760  (orig 0x254760, call)
extern void callee_519270();
uint64_t sdk_f_254760(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254780  (orig 0x254780, call)
extern void callee_519270();
uint64_t sdk_f_254780(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2547a0  (orig 0x2547a0, call)
extern void callee_519270();
uint64_t sdk_f_2547a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2547c0  (orig 0x2547c0, call)
extern void callee_519270();
uint64_t sdk_f_2547c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(31)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2547e0  (orig 0x2547e0, call)
extern void callee_51dd20();
uint64_t sdk_f_2547e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254810  (orig 0x254810, call)
extern void callee_512c10();
uint64_t sdk_f_254810(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254830  (orig 0x254830, call)
extern void callee_5128a0();
uint64_t sdk_f_254830(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(41)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254850  (orig 0x254850, call)
extern void callee_51dd20();
uint64_t sdk_f_254850(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254880  (orig 0x254880, call)
extern void callee_51dd30();
uint64_t sdk_f_254880(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (2))), ((uintptr_t)(55)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2548b0  (orig 0x2548b0, call)
extern void callee_512780();
uint64_t sdk_f_2548b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(56)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2548e0  (orig 0x2548e0, call)
extern void callee_512e00();
uint64_t sdk_f_2548e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512e00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(58)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254910  (orig 0x254910, call)
extern void callee_51dd30();
uint64_t sdk_f_254910(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (2))), ((uintptr_t)(59)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254940  (orig 0x254940, call)
extern void callee_512780();
uint64_t sdk_f_254940(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254970  (orig 0x254970, call)
extern void callee_512780();
uint64_t sdk_f_254970(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(61)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2549a0  (orig 0x2549a0, call)
extern void callee_512e00();
uint64_t sdk_f_2549a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512e00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(62)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2549d0  (orig 0x2549d0, call)
extern void callee_512780();
uint64_t sdk_f_2549d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(63)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254a00  (orig 0x254a00, call)
extern void callee_512780();
uint64_t sdk_f_254a00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(64)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254a30  (orig 0x254a30, call)
extern void callee_512e00();
uint64_t sdk_f_254a30(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512e00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254a60  (orig 0x254a60, call)
extern void callee_51dd20();
uint64_t sdk_f_254a60(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(66)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254a90  (orig 0x254a90, call)
extern void callee_51dd20();
uint64_t sdk_f_254a90(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(67)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254ac0  (orig 0x254ac0, call)
extern void callee_51dd40();
uint64_t sdk_f_254ac0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(68)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254af0  (orig 0x254af0, call)
extern void callee_51dd50();
uint64_t sdk_f_254af0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(69)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254b50  (orig 0x254b50, call)
extern void callee_51dd70();
uint64_t sdk_f_254b50(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)((((uint64_t)a4)) & (4294967295))), ((uintptr_t)(71)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254b80  (orig 0x254b80, call)
extern void callee_51dd20();
uint64_t sdk_f_254b80(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(72)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254be0  (orig 0x254be0, call)
extern void callee_51dd70();
uint64_t sdk_f_254be0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)((((uint64_t)a4)) & (4294967295))), ((uintptr_t)(74)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254c10  (orig 0x254c10, call)
extern void callee_51dd20();
uint64_t sdk_f_254c10(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(75)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254c40  (orig 0x254c40, call)
extern void callee_51dd80();
uint64_t sdk_f_254c40(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(76)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254c70  (orig 0x254c70, call)
extern void callee_51dd90();
uint64_t sdk_f_254c70(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(77)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254ca0  (orig 0x254ca0, call)
extern void callee_51dd20();
uint64_t sdk_f_254ca0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(78)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254cd0  (orig 0x254cd0, call)
extern void callee_51dd80();
uint64_t sdk_f_254cd0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(79)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254d00  (orig 0x254d00, call)
extern void callee_51dd90();
uint64_t sdk_f_254d00(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254d30  (orig 0x254d30, call)
extern void callee_51dd20();
uint64_t sdk_f_254d30(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(81)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254d60  (orig 0x254d60, call)
extern void callee_51dd40();
uint64_t sdk_f_254d60(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(82)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254d90  (orig 0x254d90, call)
extern void callee_51dd40();
uint64_t sdk_f_254d90(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(83)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254dc0  (orig 0x254dc0, call)
extern void callee_51dd20();
uint64_t sdk_f_254dc0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(91)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254df0  (orig 0x254df0, call)
extern void callee_51dd20();
uint64_t sdk_f_254df0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254e20  (orig 0x254e20, call)
extern void callee_51dda0();
uint64_t sdk_f_254e20(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dda0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254e40  (orig 0x254e40, call)
extern void callee_51ddb0();
uint64_t sdk_f_254e40(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ddb0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (2))), ((uintptr_t)(102)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254e70  (orig 0x254e70, call)
extern void callee_519270();
uint64_t sdk_f_254e70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(103)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254e90  (orig 0x254e90, call)
extern void callee_519270();
uint64_t sdk_f_254e90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(104)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254eb0  (orig 0x254eb0, call)
extern void callee_51ddc0();
uint64_t sdk_f_254eb0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ddc0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(106)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254ee0  (orig 0x254ee0, call)
extern void callee_51dd20();
uint64_t sdk_f_254ee0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(107)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254f10  (orig 0x254f10, call)
extern void callee_51ddd0();
uint64_t sdk_f_254f10(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ddd0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(108)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254f40  (orig 0x254f40, call)
extern void callee_51dd20();
uint64_t sdk_f_254f40(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(109)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254f70  (orig 0x254f70, call)
extern void callee_515b10();
uint64_t sdk_f_254f70(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254f90  (orig 0x254f90, call)
extern void callee_51dde0();
uint64_t sdk_f_254f90(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dde0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(121)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254fb0  (orig 0x254fb0, call)
extern void callee_51dd20();
uint64_t sdk_f_254fb0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(122)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_254fe0  (orig 0x254fe0, call)
extern void callee_51ddf0();
uint64_t sdk_f_254fe0(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ddf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(123)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255010  (orig 0x255010, call)
extern void callee_51dd20();
uint64_t sdk_f_255010(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(124)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255040  (orig 0x255040, call)
extern void callee_51dd80();
uint64_t sdk_f_255040(void* a0, uint64_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(125)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255070  (orig 0x255070, call)
extern void callee_519270();
uint64_t sdk_f_255070(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(126)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255090  (orig 0x255090, call)
extern void callee_519270();
uint64_t sdk_f_255090(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(127)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2550b0  (orig 0x2550b0, call)
extern void callee_515b10();
uint64_t sdk_f_2550b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(128)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2550d0  (orig 0x2550d0, call)
extern void callee_51dde0();
uint64_t sdk_f_2550d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dde0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(129)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2550f0  (orig 0x2550f0, call)
extern void callee_51dd80();
uint64_t sdk_f_2550f0(void* a0, uint64_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(130)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255120  (orig 0x255120, call)
extern void callee_51dd40();
uint64_t sdk_f_255120(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(131)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255150  (orig 0x255150, call)
extern void callee_51dd50();
uint64_t sdk_f_255150(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(132)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255180  (orig 0x255180, call)
extern void callee_51de00();
uint64_t sdk_f_255180(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint32_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(133)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2551b0  (orig 0x2551b0, call)
extern void callee_51de10();
uint64_t sdk_f_2551b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(134)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2551e0  (orig 0x2551e0, call)
extern void callee_51de20();
uint64_t sdk_f_2551e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255210  (orig 0x255210, call)
extern void callee_51de30();
uint64_t sdk_f_255210(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(201)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255240  (orig 0x255240, call)
extern void callee_51de40();
uint64_t sdk_f_255240(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(202)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255300  (orig 0x255300, call)
extern void callee_512760();
uint64_t sdk_f_255300(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(204)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255330  (orig 0x255330, call)
extern void callee_512710();
uint64_t sdk_f_255330(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(205)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255350  (orig 0x255350, call)
extern void callee_51de60();
uint64_t sdk_f_255350(void* a0, uint64_t a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de60)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (4))), ((uintptr_t)(206)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255390  (orig 0x255390, call)
extern void callee_51ddf0();
uint64_t sdk_f_255390(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ddf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(207)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2553c0  (orig 0x2553c0, call)
extern void callee_51de70();
uint64_t sdk_f_2553c0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(208)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2553f0  (orig 0x2553f0, call)
extern void callee_5128a0();
uint64_t sdk_f_2553f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(209)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255410  (orig 0x255410, call)
extern void callee_512700();
uint64_t sdk_f_255410(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(210)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255430  (orig 0x255430, call)
extern void callee_51dd40();
uint64_t sdk_f_255430(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(211)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255460  (orig 0x255460, call)
extern void callee_519270();
uint64_t sdk_f_255460(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(300)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255480  (orig 0x255480, call)
extern void callee_51dd20();
uint64_t sdk_f_255480(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2554b0  (orig 0x2554b0, call)
extern void callee_51dd20();
uint64_t sdk_f_2554b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(302)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2554e0  (orig 0x2554e0, call)
extern void callee_519270();
uint64_t sdk_f_2554e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(303)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255500  (orig 0x255500, call)
extern void callee_519270();
uint64_t sdk_f_255500(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(304)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255520  (orig 0x255520, call)
extern void callee_519270();
uint64_t sdk_f_255520(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(305)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255540  (orig 0x255540, call)
extern void callee_51de80();
uint64_t sdk_f_255540(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(306)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255560  (orig 0x255560, call)
extern void callee_519270();
uint64_t sdk_f_255560(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(307)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2555b0  (orig 0x2555b0, call)
extern void callee_512d30();
uint64_t sdk_f_2555b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512d30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(309)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2555d0  (orig 0x2555d0, call)
extern void callee_519270();
uint64_t sdk_f_2555d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(310)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2555f0  (orig 0x2555f0, call)
extern void callee_512710();
uint64_t sdk_f_2555f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255610  (orig 0x255610, call)
extern void callee_512760();
uint64_t sdk_f_255610(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(401)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255640  (orig 0x255640, call)
extern void callee_51de90();
uint64_t sdk_f_255640(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(402)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255670  (orig 0x255670, call)
extern void callee_51de90();
uint64_t sdk_f_255670(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(403)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2556a0  (orig 0x2556a0, call)
extern void callee_51dea0();
uint64_t sdk_f_2556a0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dea0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(404)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2556d0  (orig 0x2556d0, call)
extern void callee_51de90();
uint64_t sdk_f_2556d0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(405)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255700  (orig 0x255700, call)
extern void callee_51dea0();
uint64_t sdk_f_255700(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dea0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(406)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255730  (orig 0x255730, call)
extern void callee_51deb0();
uint64_t sdk_f_255730(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51deb0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255760  (orig 0x255760, call)
extern void callee_5128a0();
uint64_t sdk_f_255760(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(501)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255780  (orig 0x255780, call)
extern void callee_512c10();
uint64_t sdk_f_255780(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(502)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2557d0  (orig 0x2557d0, call)
extern void callee_513970();
uint64_t sdk_f_2557d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(504)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2557f0  (orig 0x2557f0, call)
extern void callee_513970();
uint64_t sdk_f_2557f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(505)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255810  (orig 0x255810, call)
extern void callee_5128a0();
uint64_t sdk_f_255810(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(506)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255830  (orig 0x255830, call)
extern void callee_51ded0();
uint64_t sdk_f_255830(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(507)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255860  (orig 0x255860, call)
extern void callee_5128a0();
uint64_t sdk_f_255860(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(508)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255880  (orig 0x255880, call)
extern void callee_51dee0();
uint64_t sdk_f_255880(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dee0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(509)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2558a0  (orig 0x2558a0, call)
extern void callee_51def0();
uint64_t sdk_f_2558a0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51def0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(256)), ((uintptr_t)(510)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2558d0  (orig 0x2558d0, call)
extern void callee_5128a0();
uint64_t sdk_f_2558d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(511)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2558f0  (orig 0x2558f0, call)
extern void callee_5128a0();
uint64_t sdk_f_2558f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(512)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255910  (orig 0x255910, call)
extern void callee_51df00();
uint64_t sdk_f_255910(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(513)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255930  (orig 0x255930, call)
extern void callee_51df10();
uint64_t sdk_f_255930(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(514)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255980  (orig 0x255980, call)
extern void callee_51df30();
uint64_t sdk_f_255980(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(516)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2559b0  (orig 0x2559b0, call)
extern void callee_5128a0();
uint64_t sdk_f_2559b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(517)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2559d0  (orig 0x2559d0, call)
extern void callee_51df30();
uint64_t sdk_f_2559d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(518)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255a00  (orig 0x255a00, call)
extern void callee_5128a0();
uint64_t sdk_f_255a00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(519)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255a20  (orig 0x255a20, call)
extern void callee_51df40();
uint64_t sdk_f_255a20(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (65535))), ((uintptr_t)(520)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255a50  (orig 0x255a50, call)
extern void callee_51df40();
uint64_t sdk_f_255a50(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (65535))), ((uintptr_t)(521)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255a80  (orig 0x255a80, call)
extern void callee_51de10();
uint64_t sdk_f_255a80(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(522)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255ab0  (orig 0x255ab0, call)
extern void callee_51de10();
uint64_t sdk_f_255ab0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(523)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255ae0  (orig 0x255ae0, call)
extern void callee_5128a0();
uint64_t sdk_f_255ae0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(524)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255b00  (orig 0x255b00, call)
extern void callee_512760();
uint64_t sdk_f_255b00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(525)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255b30  (orig 0x255b30, call)
extern void callee_5128a0();
uint64_t sdk_f_255b30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(526)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255b50  (orig 0x255b50, call)
extern void callee_515b10();
uint64_t sdk_f_255b50(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1000)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255b70  (orig 0x255b70, call)
extern void callee_5127d0();
uint64_t sdk_f_255b70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_255b90  (orig 0x255b90, ptr_add)
void* sdk_f_255b90(void* a0) { return (char*)a0 + 8; }

// sub_255ba0  (orig 0x255ba0, straight)
void* sdk_f_255ba0(void* a0) { return (char*)(a0) - 8; }

// sub_255d60  (orig 0x255d60, ptr_add)
void* sdk_f_255d60(void* a0) { return (char*)a0 + 16; }

// sub_255d90  (orig 0x255d90, ptr_add)
void* sdk_f_255d90(void* a0) { return (char*)a0 + 8; }

// sub_255da0  (orig 0x255da0, straight)
void* sdk_f_255da0(void* a0) { return (char*)(a0) - 8; }

// sub_2572b0  (orig 0x2572b0, ptr_add)
void* sdk_f_2572b0(void* a0) { return (char*)a0 + 16; }

// sub_2572f0  (orig 0x2572f0, ptr_add)
void* sdk_f_2572f0(void* a0) { return (char*)a0 + 8; }

// sub_257300  (orig 0x257300, straight)
void* sdk_f_257300(void* a0) { return (char*)(a0) - 8; }

// sub_258600  (orig 0x258600, ptr_add)
void* sdk_f_258600(void* a0) { return (char*)a0 + 16; }

// sub_258610  (orig 0x258610, call)
extern void callee_512780();
uint64_t sdk_f_258610(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(31)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258640  (orig 0x258640, call)
extern void callee_5155d0();
uint64_t sdk_f_258640(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258660  (orig 0x258660, call)
extern void callee_519270();
uint64_t sdk_f_258660(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258680  (orig 0x258680, call)
extern void callee_5155d0();
uint64_t sdk_f_258680(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(121)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2586a0  (orig 0x2586a0, call)
extern void callee_519270();
uint64_t sdk_f_2586a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(131)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2586c0  (orig 0x2586c0, call)
extern void callee_5155d0();
uint64_t sdk_f_2586c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(141)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2586e0  (orig 0x2586e0, call)
extern void callee_519270();
uint64_t sdk_f_2586e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(151)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258700  (orig 0x258700, call)
extern void callee_5126e0();
uint64_t sdk_f_258700(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(161)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258720  (orig 0x258720, call)
extern void callee_5126d0();
uint64_t sdk_f_258720(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(210)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258740  (orig 0x258740, call)
extern void callee_51dd30();
uint64_t sdk_f_258740(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (2))), ((uintptr_t)(211)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258770  (orig 0x258770, call)
extern void callee_512e00();
uint64_t sdk_f_258770(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512e00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(212)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2587a0  (orig 0x2587a0, call)
extern void callee_51df80();
uint64_t sdk_f_2587a0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(213)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2587d0  (orig 0x2587d0, call)
extern void callee_51df90();
uint64_t sdk_f_2587d0(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(214)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258800  (orig 0x258800, call)
extern void callee_51de90();
uint64_t sdk_f_258800(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(215)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258830  (orig 0x258830, call)
extern void callee_512e00();
uint64_t sdk_f_258830(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512e00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(230)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258860  (orig 0x258860, call)
extern void callee_51df80();
uint64_t sdk_f_258860(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(231)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258890  (orig 0x258890, call)
extern void callee_512780();
uint64_t sdk_f_258890(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2588c0  (orig 0x2588c0, call)
extern void callee_519270();
uint64_t sdk_f_2588c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(303)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2588e0  (orig 0x2588e0, call)
extern void callee_519270();
uint64_t sdk_f_2588e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(304)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258900  (orig 0x258900, call)
extern void callee_519270();
uint64_t sdk_f_258900(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(305)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258920  (orig 0x258920, call)
extern void callee_5126e0();
uint64_t sdk_f_258920(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(306)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258940  (orig 0x258940, call)
extern void callee_51dfa0();
uint64_t sdk_f_258940(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfa0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(307)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258970  (orig 0x258970, call)
extern void callee_519270();
uint64_t sdk_f_258970(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(308)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258990  (orig 0x258990, call)
extern void callee_51dfb0();
uint64_t sdk_f_258990(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfb0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(309)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2589c0  (orig 0x2589c0, call)
extern void callee_512c50();
uint64_t sdk_f_2589c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(310)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2589e0  (orig 0x2589e0, call)
extern void callee_51dd80();
uint64_t sdk_f_2589e0(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(311)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258a10  (orig 0x258a10, call)
extern void callee_519270();
uint64_t sdk_f_258a10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(312)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258a30  (orig 0x258a30, call)
extern void callee_51dfc0();
uint64_t sdk_f_258a30(void* a0, uint64_t a1, void* a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfc0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (3))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(321)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258a70  (orig 0x258a70, call)
extern void callee_51dfd0();
uint64_t sdk_f_258a70(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfd0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(322)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258aa0  (orig 0x258aa0, call)
extern void callee_51dfe0();
uint64_t sdk_f_258aa0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfe0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(323)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258ad0  (orig 0x258ad0, call)
extern void callee_5128a0();
uint64_t sdk_f_258ad0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258af0  (orig 0x258af0, call)
extern void callee_51ded0();
uint64_t sdk_f_258af0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(501)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258b20  (orig 0x258b20, call)
extern void callee_5128a0();
uint64_t sdk_f_258b20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(502)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258b40  (orig 0x258b40, call)
extern void callee_51ded0();
uint64_t sdk_f_258b40(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(503)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258b70  (orig 0x258b70, call)
extern void callee_51ded0();
uint64_t sdk_f_258b70(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(504)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258ba0  (orig 0x258ba0, call)
extern void callee_51ded0();
uint64_t sdk_f_258ba0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(505)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258c00  (orig 0x258c00, call)
extern void callee_5126e0();
uint64_t sdk_f_258c00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(511)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258c20  (orig 0x258c20, call)
extern void callee_5128a0();
uint64_t sdk_f_258c20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(512)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258c40  (orig 0x258c40, call)
extern void callee_512700();
uint64_t sdk_f_258c40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(513)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258c60  (orig 0x258c60, call)
extern void callee_512700();
uint64_t sdk_f_258c60(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(520)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258c80  (orig 0x258c80, call)
extern void callee_512700();
uint64_t sdk_f_258c80(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(521)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258ca0  (orig 0x258ca0, call)
extern void callee_5126d0();
uint64_t sdk_f_258ca0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(540)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258cc0  (orig 0x258cc0, call)
extern void callee_51dd30();
uint64_t sdk_f_258cc0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 2))) << (2))), ((uintptr_t)(541)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258cf0  (orig 0x258cf0, call)
extern void callee_5126d0();
uint64_t sdk_f_258cf0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(542)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258d10  (orig 0x258d10, call)
extern void callee_51dd30();
uint64_t sdk_f_258d10(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 1))) << (4))), ((uintptr_t)(543)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258d40  (orig 0x258d40, call)
extern void callee_5126d0();
uint64_t sdk_f_258d40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(544)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258d60  (orig 0x258d60, call)
extern void callee_515280();
uint64_t sdk_f_258d60(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(545)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258d90  (orig 0x258d90, call)
extern void callee_5126d0();
uint64_t sdk_f_258d90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(546)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258db0  (orig 0x258db0, call)
extern void callee_5127d0();
uint64_t sdk_f_258db0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(547)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258dd0  (orig 0x258dd0, call)
extern void callee_51dff0();
uint64_t sdk_f_258dd0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dff0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) * (104))), ((uintptr_t)(548)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258e00  (orig 0x258e00, call)
extern void callee_51dff0();
uint64_t sdk_f_258e00(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dff0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) * (104))), ((uintptr_t)(549)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258e30  (orig 0x258e30, call)
extern void callee_515b10();
uint64_t sdk_f_258e30(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(700)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258e50  (orig 0x258e50, call)
extern void callee_5126d0();
uint64_t sdk_f_258e50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(702)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258e70  (orig 0x258e70, call)
extern void callee_51dd30();
uint64_t sdk_f_258e70(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (3))), ((uintptr_t)(703)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258ea0  (orig 0x258ea0, call)
extern void callee_5155d0();
uint64_t sdk_f_258ea0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(751)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258ef0  (orig 0x258ef0, call)
extern void callee_51de90();
uint64_t sdk_f_258ef0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(801)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258f20  (orig 0x258f20, call)
extern void callee_512780();
uint64_t sdk_f_258f20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(802)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258f50  (orig 0x258f50, call)
extern void callee_512780();
uint64_t sdk_f_258f50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(803)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258f80  (orig 0x258f80, call)
extern void callee_512780();
uint64_t sdk_f_258f80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(804)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258fb0  (orig 0x258fb0, call)
extern void callee_51e000();
uint64_t sdk_f_258fb0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e000)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(805)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258fd0  (orig 0x258fd0, call)
extern void callee_5128a0();
uint64_t sdk_f_258fd0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(806)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_258ff0  (orig 0x258ff0, call)
extern void callee_515c00();
uint64_t sdk_f_258ff0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(807)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259010  (orig 0x259010, call)
extern void callee_515c00();
uint64_t sdk_f_259010(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(808)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259030  (orig 0x259030, call)
extern void callee_51dbf0();
uint64_t sdk_f_259030(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(809)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259050  (orig 0x259050, call)
extern void callee_515c00();
uint64_t sdk_f_259050(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(810)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259070  (orig 0x259070, call)
extern void callee_51ddd0();
uint64_t sdk_f_259070(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ddd0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(811)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2590a0  (orig 0x2590a0, call)
extern void callee_513970();
uint64_t sdk_f_2590a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(821)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2590c0  (orig 0x2590c0, call)
extern void callee_513970();
uint64_t sdk_f_2590c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(822)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2590e0  (orig 0x2590e0, call)
extern void callee_513970();
uint64_t sdk_f_2590e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(823)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259100  (orig 0x259100, call)
extern void callee_513970();
uint64_t sdk_f_259100(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(824)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259120  (orig 0x259120, call)
extern void callee_51e010();
uint64_t sdk_f_259120(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e010)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(825)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259140  (orig 0x259140, call)
extern void callee_51e020();
uint64_t sdk_f_259140(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e020)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(826)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259160  (orig 0x259160, call)
extern void callee_51e030();
uint64_t sdk_f_259160(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e030)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(827)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259180  (orig 0x259180, call)
extern void callee_51e030();
uint64_t sdk_f_259180(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e030)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(828)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2591a0  (orig 0x2591a0, call)
extern void callee_51e030();
uint64_t sdk_f_2591a0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e030)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(829)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2591c0  (orig 0x2591c0, call)
extern void callee_51e040();
uint64_t sdk_f_2591c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e040)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(830)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2591e0  (orig 0x2591e0, call)
extern void callee_512710();
uint64_t sdk_f_2591e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(850)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259200  (orig 0x259200, call)
extern void callee_512760();
uint64_t sdk_f_259200(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(851)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259230  (orig 0x259230, call)
extern void callee_51dc00();
uint64_t sdk_f_259230(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(852)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259250  (orig 0x259250, call)
extern void callee_512710();
uint64_t sdk_f_259250(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(870)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259270  (orig 0x259270, call)
extern void callee_519270();
uint64_t sdk_f_259270(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(900)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259290  (orig 0x259290, call)
extern void callee_512780();
uint64_t sdk_f_259290(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(901)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2592c0  (orig 0x2592c0, call)
extern void callee_512700();
uint64_t sdk_f_2592c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1000)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2592e0  (orig 0x2592e0, call)
extern void callee_51dbf0();
uint64_t sdk_f_2592e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259300  (orig 0x259300, call)
extern void callee_51dbf0();
uint64_t sdk_f_259300(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1002)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259320  (orig 0x259320, call)
extern void callee_51dc00();
uint64_t sdk_f_259320(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1003)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259340  (orig 0x259340, call)
extern void callee_515c00();
uint64_t sdk_f_259340(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1004)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259360  (orig 0x259360, call)
extern void callee_515c00();
uint64_t sdk_f_259360(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1005)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259380  (orig 0x259380, call)
extern void callee_512700();
uint64_t sdk_f_259380(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1006)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2593a0  (orig 0x2593a0, call)
extern void callee_51e050();
uint64_t sdk_f_2593a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1007)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2593c0  (orig 0x2593c0, call)
extern void callee_512700();
uint64_t sdk_f_2593c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1008)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2593e0  (orig 0x2593e0, call)
extern void callee_5126d0();
uint64_t sdk_f_2593e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1009)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259400  (orig 0x259400, call)
extern void callee_51dd30();
uint64_t sdk_f_259400(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (4))), ((uintptr_t)(1010)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259430  (orig 0x259430, call)
extern void callee_512700();
uint64_t sdk_f_259430(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1011)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259450  (orig 0x259450, call)
extern void callee_51e060();
uint64_t sdk_f_259450(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e060)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(1050)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259480  (orig 0x259480, call)
extern void callee_512d50();
uint64_t sdk_f_259480(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512d50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1051)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2594b0  (orig 0x2594b0, call)
extern void callee_512d50();
uint64_t sdk_f_2594b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512d50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1052)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2594e0  (orig 0x2594e0, call)
extern void callee_51e070();
uint64_t sdk_f_2594e0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e070)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(1053)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2595a0  (orig 0x2595a0, call)
extern void callee_512760();
uint64_t sdk_f_2595a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(1120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2595d0  (orig 0x2595d0, call)
extern void callee_51e090();
uint64_t sdk_f_2595d0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e090)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(1130)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2595f0  (orig 0x2595f0, call)
extern void callee_519270();
uint64_t sdk_f_2595f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1131)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259610  (orig 0x259610, call)
extern void callee_51dde0();
uint64_t sdk_f_259610(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dde0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1132)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259630  (orig 0x259630, call)
extern void callee_519270();
uint64_t sdk_f_259630(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1133)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259650  (orig 0x259650, call)
extern void callee_51e0a0();
uint64_t sdk_f_259650(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e0a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(1134)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_259670  (orig 0x259670, ptr_add)
void* sdk_f_259670(void* a0) { return (char*)a0 + 8; }

// sub_259680  (orig 0x259680, straight)
void* sdk_f_259680(void* a0) { return (char*)(a0) - 8; }

// sub_25a8f0  (orig 0x25a8f0, ptr_add)
void* sdk_f_25a8f0(void* a0) { return (char*)a0 + 16; }

// sub_25a900  (orig 0x25a900, call)
extern void callee_5128a0();
uint64_t sdk_f_25a900(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25a920  (orig 0x25a920, call)
extern void callee_51df30();
uint64_t sdk_f_25a920(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(501)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25a950  (orig 0x25a950, call)
extern void callee_5128a0();
uint64_t sdk_f_25a950(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(502)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25a970  (orig 0x25a970, ptr_add)
void* sdk_f_25a970(void* a0) { return (char*)a0 + 8; }

// sub_25a980  (orig 0x25a980, straight)
void* sdk_f_25a980(void* a0) { return (char*)(a0) - 8; }

// sub_25af50  (orig 0x25af50, ptr_add)
void* sdk_f_25af50(void* a0) { return (char*)a0 + 16; }

// sub_25af90  (orig 0x25af90, ptr_add)
void* sdk_f_25af90(void* a0) { return (char*)a0 + 8; }

// sub_25afa0  (orig 0x25afa0, straight)
void* sdk_f_25afa0(void* a0) { return (char*)(a0) - 8; }

// sub_25b7d0  (orig 0x25b7d0, call)
extern void callee_51e130();
uint64_t sdk_f_25b7d0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51e130)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25b800  (orig 0x25b800, call)
extern void callee_51e150();
uint64_t sdk_f_25b800(uint32_t a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_51e150)(((uintptr_t)((((uint32_t)a0)) & (1))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25b820  (orig 0x25b820, call)
extern void callee_51e160();
uint64_t sdk_f_25b820() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51e160)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25b840  (orig 0x25b840, call)
extern void callee_51e170();
uint64_t sdk_f_25b840() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51e170)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25b860  (orig 0x25b860, call)
extern void callee_51e180();
uint64_t sdk_f_25b860() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51e180)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25b880  (orig 0x25b880, call)
extern void callee_51e190();
uint64_t sdk_f_25b880() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51e190)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25b8a0  (orig 0x25b8a0, call)
extern void callee_51e1a0();
uint64_t sdk_f_25b8a0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51e1a0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d090  (orig 0x25d090, ret_only)
void sdk_f_25d090() {}

// sub_25d250  (orig 0x25d250, straight)
void sdk_f_25d250(void* a0, uint64_t a1, int32_t a2) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((int32_t)a2)) * 8)));
    *(uint64_t*)((char*)(p0) + 72) = (uint64_t)(a1);
}

// sub_25d640  (orig 0x25d640, ptr_add)
void* sdk_f_25d640(void* a0) { return (char*)a0 + 16; }

// sub_25d650  (orig 0x25d650, call)
extern void callee_51e2d0();
uint64_t sdk_f_25d650(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e2d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d680  (orig 0x25d680, call)
extern void callee_51dc00();
uint64_t sdk_f_25d680(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d6a0  (orig 0x25d6a0, call)
extern void callee_513970();
uint64_t sdk_f_25d6a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d6c0  (orig 0x25d6c0, call)
extern void callee_513970();
uint64_t sdk_f_25d6c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d6e0  (orig 0x25d6e0, call)
extern void callee_51e2e0();
uint64_t sdk_f_25d6e0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e2e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d710  (orig 0x25d710, call)
extern void callee_512c50();
uint64_t sdk_f_25d710(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d790  (orig 0x25d790, call)
extern void callee_512c10();
uint64_t sdk_f_25d790(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d7b0  (orig 0x25d7b0, call)
extern void callee_5126d0();
uint64_t sdk_f_25d7b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d810  (orig 0x25d810, call)
extern void callee_5128a0();
uint64_t sdk_f_25d810(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d830  (orig 0x25d830, call)
extern void callee_512780();
uint64_t sdk_f_25d830(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25d860  (orig 0x25d860, ptr_add)
void* sdk_f_25d860(void* a0) { return (char*)a0 + 8; }

// sub_25d870  (orig 0x25d870, straight)
void* sdk_f_25d870(void* a0) { return (char*)(a0) - 8; }

// sub_25e330  (orig 0x25e330, ptr_add)
void* sdk_f_25e330(void* a0) { return (char*)a0 + 16; }

// sub_25e340  (orig 0x25e340, call)
extern void callee_512780();
uint64_t sdk_f_25e340(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(31)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e370  (orig 0x25e370, call)
extern void callee_5155d0();
uint64_t sdk_f_25e370(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e390  (orig 0x25e390, call)
extern void callee_519270();
uint64_t sdk_f_25e390(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e3b0  (orig 0x25e3b0, call)
extern void callee_5155d0();
uint64_t sdk_f_25e3b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(121)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e3d0  (orig 0x25e3d0, call)
extern void callee_519270();
uint64_t sdk_f_25e3d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(131)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e3f0  (orig 0x25e3f0, call)
extern void callee_5155d0();
uint64_t sdk_f_25e3f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(141)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e410  (orig 0x25e410, call)
extern void callee_519270();
uint64_t sdk_f_25e410(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(151)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e430  (orig 0x25e430, call)
extern void callee_5126e0();
uint64_t sdk_f_25e430(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(161)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e450  (orig 0x25e450, call)
extern void callee_5126d0();
uint64_t sdk_f_25e450(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(210)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e470  (orig 0x25e470, call)
extern void callee_51dd30();
uint64_t sdk_f_25e470(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (2))), ((uintptr_t)(211)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e4a0  (orig 0x25e4a0, call)
extern void callee_512e00();
uint64_t sdk_f_25e4a0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512e00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(212)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e4d0  (orig 0x25e4d0, call)
extern void callee_51df80();
uint64_t sdk_f_25e4d0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(213)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e500  (orig 0x25e500, call)
extern void callee_51df90();
uint64_t sdk_f_25e500(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(214)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e530  (orig 0x25e530, call)
extern void callee_51de90();
uint64_t sdk_f_25e530(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(215)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e560  (orig 0x25e560, call)
extern void callee_512e00();
uint64_t sdk_f_25e560(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512e00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(230)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e590  (orig 0x25e590, call)
extern void callee_51df80();
uint64_t sdk_f_25e590(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(231)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e5c0  (orig 0x25e5c0, call)
extern void callee_512780();
uint64_t sdk_f_25e5c0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e5f0  (orig 0x25e5f0, call)
extern void callee_519270();
uint64_t sdk_f_25e5f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(303)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e610  (orig 0x25e610, call)
extern void callee_519270();
uint64_t sdk_f_25e610(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(304)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e630  (orig 0x25e630, call)
extern void callee_519270();
uint64_t sdk_f_25e630(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(305)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e650  (orig 0x25e650, call)
extern void callee_5126e0();
uint64_t sdk_f_25e650(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(306)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e670  (orig 0x25e670, call)
extern void callee_51dfa0();
uint64_t sdk_f_25e670(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfa0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(307)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e6a0  (orig 0x25e6a0, call)
extern void callee_519270();
uint64_t sdk_f_25e6a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(308)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e6c0  (orig 0x25e6c0, call)
extern void callee_51dfb0();
uint64_t sdk_f_25e6c0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfb0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(309)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e6f0  (orig 0x25e6f0, call)
extern void callee_512c50();
uint64_t sdk_f_25e6f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(310)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e710  (orig 0x25e710, call)
extern void callee_51dd80();
uint64_t sdk_f_25e710(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(311)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e740  (orig 0x25e740, call)
extern void callee_519270();
uint64_t sdk_f_25e740(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(312)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e760  (orig 0x25e760, call)
extern void callee_51dfc0();
uint64_t sdk_f_25e760(void* a0, uint64_t a1, void* a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfc0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (3))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(321)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e7a0  (orig 0x25e7a0, call)
extern void callee_51dfd0();
uint64_t sdk_f_25e7a0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfd0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(322)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e7d0  (orig 0x25e7d0, call)
extern void callee_51dfe0();
uint64_t sdk_f_25e7d0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dfe0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(323)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e800  (orig 0x25e800, call)
extern void callee_5128a0();
uint64_t sdk_f_25e800(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e820  (orig 0x25e820, call)
extern void callee_51ded0();
uint64_t sdk_f_25e820(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(501)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e850  (orig 0x25e850, call)
extern void callee_5128a0();
uint64_t sdk_f_25e850(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(502)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e870  (orig 0x25e870, call)
extern void callee_51ded0();
uint64_t sdk_f_25e870(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(503)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e8a0  (orig 0x25e8a0, call)
extern void callee_51ded0();
uint64_t sdk_f_25e8a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(504)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e8d0  (orig 0x25e8d0, call)
extern void callee_51ded0();
uint64_t sdk_f_25e8d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(505)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e930  (orig 0x25e930, call)
extern void callee_5126e0();
uint64_t sdk_f_25e930(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(511)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e950  (orig 0x25e950, call)
extern void callee_5128a0();
uint64_t sdk_f_25e950(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(512)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e970  (orig 0x25e970, call)
extern void callee_512700();
uint64_t sdk_f_25e970(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(513)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e990  (orig 0x25e990, call)
extern void callee_512700();
uint64_t sdk_f_25e990(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(520)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e9b0  (orig 0x25e9b0, call)
extern void callee_512700();
uint64_t sdk_f_25e9b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(521)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e9d0  (orig 0x25e9d0, call)
extern void callee_5126d0();
uint64_t sdk_f_25e9d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(540)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25e9f0  (orig 0x25e9f0, call)
extern void callee_51dd30();
uint64_t sdk_f_25e9f0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 2))) << (2))), ((uintptr_t)(541)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ea20  (orig 0x25ea20, call)
extern void callee_5126d0();
uint64_t sdk_f_25ea20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(542)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ea40  (orig 0x25ea40, call)
extern void callee_51dd30();
uint64_t sdk_f_25ea40(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 1))) << (4))), ((uintptr_t)(543)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ea70  (orig 0x25ea70, call)
extern void callee_5126d0();
uint64_t sdk_f_25ea70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(544)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ea90  (orig 0x25ea90, call)
extern void callee_515280();
uint64_t sdk_f_25ea90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(545)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eac0  (orig 0x25eac0, call)
extern void callee_5126d0();
uint64_t sdk_f_25eac0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(546)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eae0  (orig 0x25eae0, call)
extern void callee_5127d0();
uint64_t sdk_f_25eae0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(547)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eb00  (orig 0x25eb00, call)
extern void callee_51dff0();
uint64_t sdk_f_25eb00(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dff0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) * (104))), ((uintptr_t)(548)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eb30  (orig 0x25eb30, call)
extern void callee_51dff0();
uint64_t sdk_f_25eb30(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dff0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) * (104))), ((uintptr_t)(549)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eb60  (orig 0x25eb60, call)
extern void callee_515b10();
uint64_t sdk_f_25eb60(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(700)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eb80  (orig 0x25eb80, call)
extern void callee_5126d0();
uint64_t sdk_f_25eb80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(702)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eba0  (orig 0x25eba0, call)
extern void callee_51dd30();
uint64_t sdk_f_25eba0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (3))), ((uintptr_t)(703)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ebd0  (orig 0x25ebd0, call)
extern void callee_5155d0();
uint64_t sdk_f_25ebd0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(751)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ec20  (orig 0x25ec20, call)
extern void callee_51de90();
uint64_t sdk_f_25ec20(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51de90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(801)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ec50  (orig 0x25ec50, call)
extern void callee_512780();
uint64_t sdk_f_25ec50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(802)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ec80  (orig 0x25ec80, call)
extern void callee_512780();
uint64_t sdk_f_25ec80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(803)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ecb0  (orig 0x25ecb0, call)
extern void callee_512780();
uint64_t sdk_f_25ecb0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(804)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ece0  (orig 0x25ece0, call)
extern void callee_51e000();
uint64_t sdk_f_25ece0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e000)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(805)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ed00  (orig 0x25ed00, call)
extern void callee_5128a0();
uint64_t sdk_f_25ed00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(806)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ed20  (orig 0x25ed20, call)
extern void callee_515c00();
uint64_t sdk_f_25ed20(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(807)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ed40  (orig 0x25ed40, call)
extern void callee_515c00();
uint64_t sdk_f_25ed40(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(808)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ed60  (orig 0x25ed60, call)
extern void callee_51dbf0();
uint64_t sdk_f_25ed60(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(809)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ed80  (orig 0x25ed80, call)
extern void callee_515c00();
uint64_t sdk_f_25ed80(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(810)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eda0  (orig 0x25eda0, call)
extern void callee_51ddd0();
uint64_t sdk_f_25eda0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ddd0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(811)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25edd0  (orig 0x25edd0, call)
extern void callee_513970();
uint64_t sdk_f_25edd0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(821)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25edf0  (orig 0x25edf0, call)
extern void callee_513970();
uint64_t sdk_f_25edf0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(822)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ee10  (orig 0x25ee10, call)
extern void callee_513970();
uint64_t sdk_f_25ee10(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(823)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ee30  (orig 0x25ee30, call)
extern void callee_513970();
uint64_t sdk_f_25ee30(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(824)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ee50  (orig 0x25ee50, call)
extern void callee_51e010();
uint64_t sdk_f_25ee50(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e010)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(825)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ee70  (orig 0x25ee70, call)
extern void callee_51e020();
uint64_t sdk_f_25ee70(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e020)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(826)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ee90  (orig 0x25ee90, call)
extern void callee_51e030();
uint64_t sdk_f_25ee90(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e030)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(827)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eeb0  (orig 0x25eeb0, call)
extern void callee_51e030();
uint64_t sdk_f_25eeb0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e030)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(828)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eed0  (orig 0x25eed0, call)
extern void callee_51e030();
uint64_t sdk_f_25eed0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e030)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(829)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eef0  (orig 0x25eef0, call)
extern void callee_51e040();
uint64_t sdk_f_25eef0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e040)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(830)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ef10  (orig 0x25ef10, call)
extern void callee_512710();
uint64_t sdk_f_25ef10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(850)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ef30  (orig 0x25ef30, call)
extern void callee_512760();
uint64_t sdk_f_25ef30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(851)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ef60  (orig 0x25ef60, call)
extern void callee_51dc00();
uint64_t sdk_f_25ef60(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(852)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25ef80  (orig 0x25ef80, call)
extern void callee_512710();
uint64_t sdk_f_25ef80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(870)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25efa0  (orig 0x25efa0, call)
extern void callee_519270();
uint64_t sdk_f_25efa0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(900)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25efc0  (orig 0x25efc0, call)
extern void callee_512780();
uint64_t sdk_f_25efc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(901)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25eff0  (orig 0x25eff0, call)
extern void callee_512700();
uint64_t sdk_f_25eff0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1000)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f010  (orig 0x25f010, call)
extern void callee_51dbf0();
uint64_t sdk_f_25f010(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f030  (orig 0x25f030, call)
extern void callee_51dbf0();
uint64_t sdk_f_25f030(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dbf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1002)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f050  (orig 0x25f050, call)
extern void callee_51dc00();
uint64_t sdk_f_25f050(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dc00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1003)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f070  (orig 0x25f070, call)
extern void callee_515c00();
uint64_t sdk_f_25f070(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1004)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f090  (orig 0x25f090, call)
extern void callee_515c00();
uint64_t sdk_f_25f090(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1005)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f0b0  (orig 0x25f0b0, call)
extern void callee_512700();
uint64_t sdk_f_25f0b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1006)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f0d0  (orig 0x25f0d0, call)
extern void callee_51e050();
uint64_t sdk_f_25f0d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1007)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f0f0  (orig 0x25f0f0, call)
extern void callee_512700();
uint64_t sdk_f_25f0f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1008)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f110  (orig 0x25f110, call)
extern void callee_5126d0();
uint64_t sdk_f_25f110(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1009)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f130  (orig 0x25f130, call)
extern void callee_51dd30();
uint64_t sdk_f_25f130(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (4))), ((uintptr_t)(1010)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f160  (orig 0x25f160, call)
extern void callee_512700();
uint64_t sdk_f_25f160(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1011)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f180  (orig 0x25f180, call)
extern void callee_51e060();
uint64_t sdk_f_25f180(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e060)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(1050)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f1b0  (orig 0x25f1b0, call)
extern void callee_512d50();
uint64_t sdk_f_25f1b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512d50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1051)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f1e0  (orig 0x25f1e0, call)
extern void callee_512d50();
uint64_t sdk_f_25f1e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512d50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1052)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f210  (orig 0x25f210, call)
extern void callee_51e070();
uint64_t sdk_f_25f210(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e070)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(1053)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f2e0  (orig 0x25f2e0, call)
extern void callee_512760();
uint64_t sdk_f_25f2e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(1120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f310  (orig 0x25f310, call)
extern void callee_51e090();
uint64_t sdk_f_25f310(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e090)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(1130)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f330  (orig 0x25f330, call)
extern void callee_519270();
uint64_t sdk_f_25f330(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1131)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f350  (orig 0x25f350, call)
extern void callee_51dde0();
uint64_t sdk_f_25f350(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dde0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1132)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f370  (orig 0x25f370, call)
extern void callee_519270();
uint64_t sdk_f_25f370(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1133)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f390  (orig 0x25f390, call)
extern void callee_51e0a0();
uint64_t sdk_f_25f390(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e0a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(1134)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f3b0  (orig 0x25f3b0, ptr_add)
void* sdk_f_25f3b0(void* a0) { return (char*)a0 + 8; }

// sub_25f3c0  (orig 0x25f3c0, straight)
void* sdk_f_25f3c0(void* a0) { return (char*)(a0) - 8; }

// sub_25f540  (orig 0x25f540, ptr_add)
void* sdk_f_25f540(void* a0) { return (char*)a0 + 16; }

// sub_25f550  (orig 0x25f550, call)
extern void callee_5128a0();
uint64_t sdk_f_25f550(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f570  (orig 0x25f570, call)
extern void callee_51df30();
uint64_t sdk_f_25f570(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51df30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(501)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f5a0  (orig 0x25f5a0, call)
extern void callee_5128a0();
uint64_t sdk_f_25f5a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(502)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_25f5c0  (orig 0x25f5c0, ptr_add)
void* sdk_f_25f5c0(void* a0) { return (char*)a0 + 8; }

// sub_25f5d0  (orig 0x25f5d0, straight)
void* sdk_f_25f5d0(void* a0) { return (char*)(a0) - 8; }

// sub_2601d0  (orig 0x2601d0, ptr_add)
void* sdk_f_2601d0(void* a0) { return (char*)a0 + 16; }

// sub_260210  (orig 0x260210, call)
extern void callee_513a40();
uint64_t sdk_f_260210(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513a40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_260240  (orig 0x260240, call)
extern void callee_5126d0();
uint64_t sdk_f_260240(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_260260  (orig 0x260260, call)
extern void callee_5126d0();
uint64_t sdk_f_260260(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_260280  (orig 0x260280, call)
extern void callee_5126d0();
uint64_t sdk_f_260280(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2602a0  (orig 0x2602a0, call)
extern void callee_5126d0();
uint64_t sdk_f_2602a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2602c0  (orig 0x2602c0, call)
extern void callee_5128d0();
uint64_t sdk_f_2602c0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2602f0  (orig 0x2602f0, call)
extern void callee_5128d0();
uint64_t sdk_f_2602f0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_260320  (orig 0x260320, call)
extern void callee_512760();
uint64_t sdk_f_260320(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_260350  (orig 0x260350, call)
extern void callee_5128d0();
uint64_t sdk_f_260350(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_260380  (orig 0x260380, call)
extern void callee_5128d0();
uint64_t sdk_f_260380(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2603b0  (orig 0x2603b0, call)
extern void callee_51e330();
uint64_t sdk_f_2603b0(void* a0, void* a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e330)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2603e0  (orig 0x2603e0, call)
extern void callee_5126e0();
uint64_t sdk_f_2603e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_260400  (orig 0x260400, call)
extern void callee_51e340();
uint64_t sdk_f_260400(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e340)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_260430  (orig 0x260430, call)
extern void callee_512de0();
uint64_t sdk_f_260430(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512de0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_260460  (orig 0x260460, ptr_add)
void* sdk_f_260460(void* a0) { return (char*)a0 + 8; }

// sub_260470  (orig 0x260470, straight)
void* sdk_f_260470(void* a0) { return (char*)(a0) - 8; }

// sub_261890  (orig 0x261890, ptr_add)
void* sdk_f_261890(void* a0) { return (char*)a0 + 32; }

// sub_261940  (orig 0x261940, ptr_add)
void* sdk_f_261940(void* a0) { return (char*)a0 + 8; }

// sub_261950  (orig 0x261950, straight)
void* sdk_f_261950(void* a0) { return (char*)(a0) - 24; }

// sub_261c70  (orig 0x261c70, ptr_add)
void* sdk_f_261c70(void* a0) { return (char*)a0 + 32; }

// sub_261cb0  (orig 0x261cb0, call)
extern void callee_51e360();
uint64_t sdk_f_261cb0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e360)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_261cd0  (orig 0x261cd0, call)
extern void callee_511670();
uint64_t sdk_f_261cd0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_261cf0  (orig 0x261cf0, ptr_add)
void* sdk_f_261cf0(void* a0) { return (char*)a0 + 8; }

// sub_261d00  (orig 0x261d00, straight)
void* sdk_f_261d00(void* a0) { return (char*)(a0) - 24; }

// sub_262440  (orig 0x262440, ptr_add)
void* sdk_f_262440(void* a0) { return (char*)a0 + 16; }

// sub_262470  (orig 0x262470, call)
extern void callee_51e370();
uint64_t sdk_f_262470(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2624a0  (orig 0x2624a0, call)
extern void callee_51e380();
uint64_t sdk_f_2624a0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e380)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2624d0  (orig 0x2624d0, call)
extern void callee_51e380();
uint64_t sdk_f_2624d0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e380)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_262500  (orig 0x262500, call)
extern void callee_51e390();
uint64_t sdk_f_262500(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_262530  (orig 0x262530, call)
extern void callee_51e3a0();
uint64_t sdk_f_262530(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e3a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2625e0  (orig 0x2625e0, call)
extern void callee_51e390();
uint64_t sdk_f_2625e0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_262610  (orig 0x262610, call)
extern void callee_51e3d0();
uint64_t sdk_f_262610(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4, uint32_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e3d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(((uint32_t)a5))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_262640  (orig 0x262640, call)
extern void callee_51e3e0();
uint64_t sdk_f_262640(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51e3e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_262660  (orig 0x262660, call)
extern void callee_51e3e0();
uint64_t sdk_f_262660(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51e3e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2627d0  (orig 0x2627d0, call)
extern void callee_519270();
uint64_t sdk_f_2627d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2627f0  (orig 0x2627f0, call)
extern void callee_519270();
uint64_t sdk_f_2627f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_262810  (orig 0x262810, ptr_add)
void* sdk_f_262810(void* a0) { return (char*)a0 + 8; }

// sub_262820  (orig 0x262820, straight)
void* sdk_f_262820(void* a0) { return (char*)(a0) - 8; }

// sub_2632f0  (orig 0x2632f0, ptr_add)
void* sdk_f_2632f0(void* a0) { return (char*)a0 + 16; }

// sub_263320  (orig 0x263320, call)
extern void callee_51e410();
uint64_t sdk_f_263320(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e410)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263340  (orig 0x263340, call)
extern void callee_51e410();
uint64_t sdk_f_263340(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e410)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263360  (orig 0x263360, call)
extern void callee_51e370();
uint64_t sdk_f_263360(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263440  (orig 0x263440, call)
extern void callee_51e430();
uint64_t sdk_f_263440(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e430)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263470  (orig 0x263470, call)
extern void callee_51e440();
uint64_t sdk_f_263470(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2634a0  (orig 0x2634a0, call)
extern void callee_51e370();
uint64_t sdk_f_2634a0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2634d0  (orig 0x2634d0, call)
extern void callee_51e390();
uint64_t sdk_f_2634d0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263500  (orig 0x263500, call)
extern void callee_51e450();
uint64_t sdk_f_263500(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e450)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2635d0  (orig 0x2635d0, call)
extern void callee_51e470();
uint64_t sdk_f_2635d0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e470)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263600  (orig 0x263600, call)
extern void callee_51e430();
uint64_t sdk_f_263600(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e430)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263670  (orig 0x263670, call)
extern void callee_51e490();
uint64_t sdk_f_263670(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e490)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2636f0  (orig 0x2636f0, call)
extern void callee_51e4b0();
uint64_t sdk_f_2636f0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e4b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263720  (orig 0x263720, call)
extern void callee_51e4c0();
uint64_t sdk_f_263720(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint32_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e4c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint32_t)a5))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263750  (orig 0x263750, call)
extern void callee_51e4d0();
uint64_t sdk_f_263750(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e4d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263780  (orig 0x263780, call)
extern void callee_51e4b0();
uint64_t sdk_f_263780(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e4b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2637b0  (orig 0x2637b0, call)
extern void callee_51e4e0();
uint64_t sdk_f_2637b0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e4e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2637e0  (orig 0x2637e0, call)
extern void callee_51e430();
uint64_t sdk_f_2637e0(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e430)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_263810  (orig 0x263810, ptr_add)
void* sdk_f_263810(void* a0) { return (char*)a0 + 8; }

// sub_263820  (orig 0x263820, straight)
void* sdk_f_263820(void* a0) { return (char*)(a0) - 8; }

// sub_265320  (orig 0x265320, ptr_add)
void* sdk_f_265320(void* a0) { return (char*)a0 + 32; }

// sub_265350  (orig 0x265350, call)
extern void callee_51b5a0();
uint64_t sdk_f_265350(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b5a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_265380  (orig 0x265380, call)
extern void callee_51e4f0();
uint64_t sdk_f_265380(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e4f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2653b0  (orig 0x2653b0, call)
extern void callee_51e4f0();
uint64_t sdk_f_2653b0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e4f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2653e0  (orig 0x2653e0, call)
extern void callee_51e500();
uint64_t sdk_f_2653e0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_265410  (orig 0x265410, call)
extern void callee_51e510();
uint64_t sdk_f_265410(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2654c0  (orig 0x2654c0, call)
extern void callee_51e500();
uint64_t sdk_f_2654c0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2654f0  (orig 0x2654f0, call)
extern void callee_51e540();
uint64_t sdk_f_2654f0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4, uint32_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e540)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(((uint32_t)a5))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_265520  (orig 0x265520, call)
extern void callee_51b4e0();
uint64_t sdk_f_265520(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b4e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_265540  (orig 0x265540, call)
extern void callee_51b4e0();
uint64_t sdk_f_265540(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b4e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2656b0  (orig 0x2656b0, call)
extern void callee_511440();
uint64_t sdk_f_2656b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2656d0  (orig 0x2656d0, call)
extern void callee_511440();
uint64_t sdk_f_2656d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2656f0  (orig 0x2656f0, ptr_add)
void* sdk_f_2656f0(void* a0) { return (char*)a0 + 8; }

// sub_265700  (orig 0x265700, straight)
void* sdk_f_265700(void* a0) { return (char*)(a0) - 24; }

// sub_2661e0  (orig 0x2661e0, ptr_add)
void* sdk_f_2661e0(void* a0) { return (char*)a0 + 32; }

// sub_266210  (orig 0x266210, call)
extern void callee_51e570();
uint64_t sdk_f_266210(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266230  (orig 0x266230, call)
extern void callee_51e570();
uint64_t sdk_f_266230(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266250  (orig 0x266250, call)
extern void callee_51b5a0();
uint64_t sdk_f_266250(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b5a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266330  (orig 0x266330, call)
extern void callee_51e590();
uint64_t sdk_f_266330(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e590)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266360  (orig 0x266360, call)
extern void callee_51e5a0();
uint64_t sdk_f_266360(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e5a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266390  (orig 0x266390, call)
extern void callee_51b5a0();
uint64_t sdk_f_266390(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b5a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2663c0  (orig 0x2663c0, call)
extern void callee_51e500();
uint64_t sdk_f_2663c0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2663f0  (orig 0x2663f0, call)
extern void callee_51e5b0();
uint64_t sdk_f_2663f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e5b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2664c0  (orig 0x2664c0, call)
extern void callee_51e5d0();
uint64_t sdk_f_2664c0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e5d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2664f0  (orig 0x2664f0, call)
extern void callee_51e590();
uint64_t sdk_f_2664f0(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e590)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266560  (orig 0x266560, call)
extern void callee_51e5f0();
uint64_t sdk_f_266560(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e5f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2665e0  (orig 0x2665e0, call)
extern void callee_51b530();
uint64_t sdk_f_2665e0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b530)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266610  (orig 0x266610, call)
extern void callee_51e610();
uint64_t sdk_f_266610(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint32_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e610)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint32_t)a5))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266640  (orig 0x266640, call)
extern void callee_51e620();
uint64_t sdk_f_266640(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e620)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266670  (orig 0x266670, call)
extern void callee_51b530();
uint64_t sdk_f_266670(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b530)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2666a0  (orig 0x2666a0, call)
extern void callee_51e630();
uint64_t sdk_f_2666a0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e630)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2666d0  (orig 0x2666d0, call)
extern void callee_51e590();
uint64_t sdk_f_2666d0(void* a0, uint64_t a1, uint64_t a2, void* a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51e590)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_266700  (orig 0x266700, ptr_add)
void* sdk_f_266700(void* a0) { return (char*)a0 + 8; }

// sub_266710  (orig 0x266710, straight)
void* sdk_f_266710(void* a0) { return (char*)(a0) - 24; }

// sub_2685c0  (orig 0x2685c0, call)
extern void callee_51e640();
uint64_t sdk_f_2685c0() {
    uint64_t f_2685c0__r0 = ((uint64_t (*)(void))&callee_51e640)();
    uint64_t r0 = (f_2685c0__r0) + (72);
    asm volatile("");
    return r0;
}

// sub_26a550  (orig 0x26a550, straight-line)
int64_t sdk_f_26a550(uint32_t a0) { return (((int64_t)(((int32_t)(((uint32_t)a0)))))) * (((int64_t)(((int32_t)(104))))); }

// sub_26aac0  (orig 0x26aac0, ret_only)
void sdk_f_26aac0() {}

// sub_26c480  (orig 0x26c480, ret_only)
void sdk_f_26c480() {}

// sub_26f730  (orig 0x26f730, ret_only)
void sdk_f_26f730() {}

// sub_279b10  (orig 0x279b10, ret_only)
void sdk_f_279b10() {}

// sub_27cd30  (orig 0x27cd30, ret_only)
void sdk_f_27cd30() {}

// sub_27ce10  (orig 0x27ce10, ret_only)
void sdk_f_27ce10() {}

// sub_27cff0  (orig 0x27cff0, setter)
void sdk_f_27cff0(void* a0) { *(uint32_t*)((char*)(a0) + 176) = 0; }

// sub_27d3f0  (orig 0x27d3f0, mov_ret)
uint32_t sdk_f_27d3f0() { return 0; }

// sub_27dc50  (orig 0x27dc50, ret_only)
void sdk_f_27dc50() {}

// sub_284980  (orig 0x284980, copy-chain-store)
void sdk_f_284980(void* a0) {
    uint64_t t0 = *(uint64_t*)((char*)a0 + 584);
    *(uint64_t*)((char*)a0 + 296) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 164) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 540) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint16_t*)((char*)(t0) + 24) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)(t0) + 32) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)(t0) + 248) = 0;
}

// sub_287c60  (orig 0x287c60, straight)
void sdk_f_287c60(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 608));
    *(uint8_t*)((char*)(p0) + 72) = 0;
    *(uint32_t*)((char*)(p0) + 80) = *(uint32_t*)((char*)(a0) + 128);
}

// sub_288510  (orig 0x288510, straight)
void sdk_f_288510(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 608));
    *(uint32_t*)((char*)(p0) + 104) = *(uint32_t*)((char*)(a0) + 388);
    *(uint32_t*)((char*)(p0) + 108) = *(uint32_t*)((char*)(a0) + 128);
}

// sub_288680  (orig 0x288680, setter)
void sdk_f_288680(uint64_t unused0, uint64_t unused1, uint64_t unused2, void* a3) { *(uint64_t*)((char*)(a3)) = 0; }

// sub_288690  (orig 0x288690, setter)
void sdk_f_288690(uint64_t unused0, uint64_t unused1, uint64_t a2, void* a3) { *(uint64_t*)((char*)(a3)) = a2; }

// sub_288b80  (orig 0x288b80, ret_only)
void sdk_f_288b80() {}

// sub_288b90  (orig 0x288b90, ret_only)
void sdk_f_288b90() {}

// sub_288ba0  (orig 0x288ba0, straight)
void sdk_f_288ba0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    *(uint64_t*)((char*)(p0) + 128) = 0;
    *(uint32_t*)((char*)(p0) + 40) = 0;
}

// sub_290570  (orig 0x290570, ret_only)
void sdk_f_290570() {}

// sub_2905b0  (orig 0x2905b0, ret_only)
void sdk_f_2905b0() {}

// sub_2905c0  (orig 0x2905c0, mov_ret)
uint64_t sdk_f_2905c0(uint64_t a0, uint64_t a1, uint64_t a2) { return a2; }

// sub_2905f0  (orig 0x2905f0, straight-line)
uint64_t sdk_f_2905f0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    *(uint64_t*)((char*)(p0) + 16) = 0;
    return 0;
}

// sub_290600  (orig 0x290600, straight-line)
void sdk_f_290600(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 40));
    *(uint64_t*)((char*)(p0) + 16) = 0;
}

// sub_290610  (orig 0x290610, straight-line)
int64_t sdk_f_290610(uint64_t a0, uint64_t a1) { return (((int64_t)(((((uint64_t)a0)) + (((uint64_t)a1))) - (1)))) / (((int64_t)(((uint64_t)a1)))); }

// sub_290620  (orig 0x290620, straight-line)
uint64_t sdk_f_290620(uint64_t a0, uint64_t a1) { return ((((int64_t)(((((uint64_t)a0)) + (((uint64_t)a1))) - (1)))) / (((int64_t)(((uint64_t)a1))))) * (((uint64_t)a1)); }

// sub_2907d0  (orig 0x2907d0, ret_only)
void sdk_f_2907d0() {}

// sub_292980  (orig 0x292980, getter)
uint16_t sdk_f_292980(void* a0) { return *(uint16_t*)((char*)(a0)); }

// sub_292990  (orig 0x292990, getter)
uint32_t sdk_f_292990(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_2929a0  (orig 0x2929a0, straight)
void sdk_f_2929a0(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0)) = (uint8_t)(a1);
    *(uint8_t*)((char*)(a0) + 1) = (uint8_t)((((uint32_t)a1)) >> (8));
}

// sub_2929b0  (orig 0x2929b0, straight)
void sdk_f_2929b0(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0) + 1) = (uint8_t)((((uint32_t)a1)) >> (8));
    *(uint8_t*)((char*)(a0)) = (uint8_t)(a1);
    *(uint8_t*)((char*)(a0) + 2) = (uint8_t)((((uint32_t)a1)) >> (16));
    *(uint8_t*)((char*)(a0) + 3) = (uint8_t)((((uint32_t)a1)) >> (24));
}

// sub_2929d0  (orig 0x2929d0, straight-line)
uint32_t sdk_f_2929d0(void* a0) { return __builtin_bswap32(*(uint32_t*)((char*)(a0))); }

// sub_2929e0  (orig 0x2929e0, straight)
void sdk_f_2929e0(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0)) = (uint8_t)((((uint32_t)a1)) >> (8));
    *(uint8_t*)((char*)(a0) + 1) = (uint8_t)(a1);
}

// sub_2929f0  (orig 0x2929f0, straight)
void sdk_f_2929f0(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0)) = (uint8_t)((((uint32_t)a1)) >> (24));
    *(uint8_t*)((char*)(a0) + 1) = (uint8_t)((((uint32_t)a1)) >> (16));
    *(uint8_t*)((char*)(a0) + 2) = (uint8_t)((((uint32_t)a1)) >> (8));
    *(uint8_t*)((char*)(a0) + 3) = (uint8_t)(a1);
}

// sub_294900  (orig 0x294900, ret_only)
void sdk_f_294900() {}

// sub_294930  (orig 0x294930, straight)
void sdk_f_294930(void* a0, uint64_t a1) {
    *(uint32_t*)((char*)(a0) + 32) = (uint32_t)(a1);
    *(uint32_t*)((char*)(a0) + 8) = (uint32_t)(((*(uint64_t*)((char*)(a0) + 16) != 0) ? 1 : 0));
}

// sub_294a70  (orig 0x294a70, getter)
uint64_t sdk_f_294a70(void* a0) { return *(uint64_t*)((char*)(a0) + 40); }

// sub_294a80  (orig 0x294a80, getter)
uint64_t sdk_f_294a80(void* a0) { return *(uint64_t*)((char*)(a0) + 48); }

// sub_295020  (orig 0x295020, ret_only)
void sdk_f_295020() {}

// sub_295090  (orig 0x295090, straight)
void sdk_f_295090(void* a0, uint64_t a1) {
    *(uint32_t*)((char*)(a0) + 40) = (uint32_t)(a1);
    *(uint32_t*)((char*)(a0) + 8) = (uint32_t)(((*(uint64_t*)((char*)(a0) + 16) != 0) ? 1 : 0));
}

// sub_2950b0  (orig 0x2950b0, straight)
void sdk_f_2950b0(void* a0, uint64_t a1) {
    *(uint32_t*)((char*)(a0) + 44) = (uint32_t)(a1);
    *(uint32_t*)((char*)(a0) + 8) = (uint32_t)(((*(uint64_t*)((char*)(a0) + 16) != 0) ? 1 : 0));
}

// sub_2951a0  (orig 0x2951a0, getter)
uint64_t sdk_f_2951a0(void* a0) { return *(uint64_t*)((char*)(a0) + 48); }

// sub_295a00  (orig 0x295a00, mov_ret)
uint32_t sdk_f_295a00() { return 744; }

// sub_295a60  (orig 0x295a60, ret_only)
void sdk_f_295a60() {}

// sub_295a80  (orig 0x295a80, straight)
void sdk_f_295a80(void* a0, uint64_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 16));
    *(uint16_t*)((char*)(p0) + 682) = (uint16_t)(a1);
    *(uint32_t*)((char*)(a0) + 8) = 1;
}

// sub_295aa0  (orig 0x295aa0, straight-line)
void sdk_f_295aa0(void* a0, uint64_t a1, uint32_t a2) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 16));
    *(uint64_t*)((char*)(p0) + 672) = a1;
    *(uint16_t*)((char*)(p0) + 680) = (uint16_t)((((((uint64_t)a1) == 0)) ? (0) : (((uint32_t)a2))));
    *(uint32_t*)((char*)(a0) + 8) = 1;
}

// sub_295ac0  (orig 0x295ac0, straight)
void sdk_f_295ac0(void* a0, uint64_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 16));
    *(uint64_t*)((char*)(p0) + 688) = (uint64_t)(a1);
    *(uint32_t*)((char*)(a0) + 8) = 1;
}

// sub_295ae0  (orig 0x295ae0, straight-line)
void sdk_f_295ae0(void* a0, uint64_t a1, uint32_t a2) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 16));
    *(uint64_t*)((char*)(p0) + 704) = a1;
    *(uint16_t*)((char*)(p0) + 712) = (uint16_t)((((((uint64_t)a1) == 0)) ? (0) : (((uint32_t)a2))));
    *(uint32_t*)((char*)(a0) + 8) = 1;
}

// sub_295b00  (orig 0x295b00, straight)
void sdk_f_295b00(void* a0, uint64_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 16));
    *(uint64_t*)((char*)(p0) + 720) = (uint64_t)(a1);
    *(uint32_t*)((char*)(a0) + 8) = 1;
}

// sub_295b20  (orig 0x295b20, straight-line)
void sdk_f_295b20(void* a0, uint64_t a1, uint32_t a2) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 16));
    *(uint64_t*)((char*)(p0) + 728) = a1;
    *(uint32_t*)((char*)(p0) + 740) = (uint32_t)((((((uint64_t)a1) == 0)) ? (0) : (((uint32_t)a2))));
    *(uint32_t*)((char*)(a0) + 8) = 1;
}

// sub_295fd0  (orig 0x295fd0, getter)
uint16_t sdk_f_295fd0(void* a0) { return *(uint16_t*)((char*)(a0) + 24); }

// sub_2960d0  (orig 0x2960d0, mov_ret)
uint32_t sdk_f_2960d0() { return 240; }

// sub_296100  (orig 0x296100, ret_only)
void sdk_f_296100() {}

// sub_296120  (orig 0x296120, straight)
void sdk_f_296120(void* a0, uint64_t a1, uint64_t a2) {
    *(uint64_t*)((char*)(a0) + 24) = (uint64_t)(a1);
    *(uint16_t*)((char*)(a0) + 32) = (uint16_t)(a2);
    *(uint32_t*)((char*)(a0) + 8) = 1;
}

// sub_296cb0  (orig 0x296cb0, straight-line)
void sdk_f_296cb0(void* a0, void* a1) {
    *(uint32_t*)((char*)(a0)) = (uint32_t)((((int32_t)(((int8_t)((((*(uint32_t*)((char*)(a1)) < 8)) ? (*(uint32_t*)((char*)(a1))) : ((((*(uint32_t*)((char*)(a1)) == 16)) ? ((8) + (1)) : (8))))))))) & (4294902015));
}

// sub_296ce0  (orig 0x296ce0, straight)
uint32_t sdk_f_296ce0(void* a0) { return (*(uint32_t*)((char*)(a0))) >> (8); }

// sub_296d00  (orig 0x296d00, ret_only)
void sdk_f_296d00() {}

// sub_2990b0  (orig 0x2990b0, ret_only)
void sdk_f_2990b0() {}

// sub_2991d0  (orig 0x2991d0, strlit-ret)
const char *sdk_f_2991d0() { static char g_f_2991d0[1]; __asm__ volatile("" ::: "memory"); return g_f_2991d0; }

// sub_2991e0  (orig 0x2991e0, ret_only)
void sdk_f_2991e0() {}

// sub_299680  (orig 0x299680, ret_only)
void sdk_f_299680() {}

// sub_299e70  (orig 0x299e70, setter)
void sdk_f_299e70(void* a0) { *(uint8_t*)((char*)(a0)) = 0; }

// sub_299e80  (orig 0x299e80, ret_only)
void sdk_f_299e80() {}

// sub_29a010  (orig 0x29a010, call)
extern void callee_51be70();
uint64_t sdk_f_29a010(void* a0) {
    uint64_t r0 = ((((uint64_t (*)(uintptr_t))&callee_51be70)(((uintptr_t)((char*)(a0) + 8))) != 0) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_29a8c0  (orig 0x29a8c0, copy2)
void sdk_f_29a8c0(void* a0, uint64_t unused1, void* a2) { *(uint32_t*)((char*)(a0) + 376) = *(uint32_t*)((char*)(a2)); }

// sub_29a8d0  (orig 0x29a8d0, copy2)
void sdk_f_29a8d0(void* a0, void* a1) { *(uint32_t*)((char*)(a1)) = *(uint32_t*)((char*)(a0) + 376); }

// sub_29ca40  (orig 0x29ca40, setter-chain-zero)
void sdk_f_29ca40(uint64_t unused0, void* a1) {
    struct u64x2 { uint64_t a, b; };
    *(uint8_t*)((char*)a1 + 48) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint8_t*)((char*)a1 + 80) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint8_t*)((char*)a1 + 16) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a1 = (struct u64x2){ 0, 0 };
}

// sub_29ca70  (orig 0x29ca70, const-ret)
uint32_t sdk_f_29ca70() { return 103117u; }

// sub_29ca80  (orig 0x29ca80, const-ret)
uint32_t sdk_f_29ca80() { return 103629u; }

// sub_29ca90  (orig 0x29ca90, const-ret)
uint32_t sdk_f_29ca90() { return 104141u; }

// sub_29caa0  (orig 0x29caa0, call)
extern void callee_51ee70();
uint64_t sdk_f_29caa0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_51ee70)(((uintptr_t)((char*)(a0) + 48)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29cbe0  (orig 0x29cbe0, ret_only)
void sdk_f_29cbe0() {}

// sub_29d330  (orig 0x29d330, call)
extern void callee_51f3b0();
uint64_t sdk_f_29d330() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f3b0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29d470  (orig 0x29d470, call)
extern void callee_51f3e0();
uint64_t sdk_f_29d470() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f3e0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29d490  (orig 0x29d490, call)
extern void callee_51f010();
uint64_t sdk_f_29d490() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f010)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29d670  (orig 0x29d670, call)
extern void callee_51f400();
uint64_t sdk_f_29d670() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f400)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29d690  (orig 0x29d690, call)
extern void callee_51f080();
uint64_t sdk_f_29d690() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f080)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29d790  (orig 0x29d790, call)
extern void callee_51f430();
uint64_t sdk_f_29d790() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f430)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29d810  (orig 0x29d810, call)
extern void callee_51f440();
uint64_t sdk_f_29d810() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f440)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29d880  (orig 0x29d880, call)
extern void callee_51f460();
uint64_t sdk_f_29d880() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f460)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29d9f0  (orig 0x29d9f0, call)
extern void callee_51f470();
uint64_t sdk_f_29d9f0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f470)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29da10  (orig 0x29da10, setter)
void sdk_f_29da10(void* a0) { *(uint32_t*)((char*)(a0)) = 0; }

// sub_29da70  (orig 0x29da70, call)
extern void callee_51f490();
uint64_t sdk_f_29da70() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_51f490)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ec00  (orig 0x29ec00, ptr_add)
void* sdk_f_29ec00(void* a0) { return (char*)a0 + 16; }

// sub_29ec10  (orig 0x29ec10, call)
extern void callee_519270();
uint64_t sdk_f_29ec10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(302)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ec30  (orig 0x29ec30, call)
extern void callee_519270();
uint64_t sdk_f_29ec30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(303)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ec50  (orig 0x29ec50, call)
extern void callee_5155d0();
uint64_t sdk_f_29ec50(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(304)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ec70  (orig 0x29ec70, call)
extern void callee_51dd20();
uint64_t sdk_f_29ec70(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(305)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29eca0  (orig 0x29eca0, call)
extern void callee_51f580();
uint64_t sdk_f_29eca0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f580)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(306)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ecd0  (orig 0x29ecd0, call)
extern void callee_51f590();
uint64_t sdk_f_29ecd0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f590)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(307)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ed00  (orig 0x29ed00, call)
extern void callee_51f5a0();
uint64_t sdk_f_29ed00(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f5a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(308)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ed30  (orig 0x29ed30, call)
extern void callee_51f5b0();
uint64_t sdk_f_29ed30(void* a0, uint64_t a1, uint64_t a2, void* a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f5b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)((((uint64_t)a4)) & (4294967295))), ((uintptr_t)(309)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ed60  (orig 0x29ed60, call)
extern void callee_51f5c0();
uint64_t sdk_f_29ed60(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f5c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(310)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ed90  (orig 0x29ed90, call)
extern void callee_512de0();
uint64_t sdk_f_29ed90(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512de0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(311)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29edc0  (orig 0x29edc0, call)
extern void callee_51f5d0();
uint64_t sdk_f_29edc0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f5d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(312)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29edf0  (orig 0x29edf0, call)
extern void callee_51dd20();
uint64_t sdk_f_29edf0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(313)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ee20  (orig 0x29ee20, call)
extern void callee_51f5e0();
uint64_t sdk_f_29ee20(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f5e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(314)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ee50  (orig 0x29ee50, call)
extern void callee_51f5f0();
uint64_t sdk_f_29ee50(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f5f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)((((uint64_t)a3)) & (4294967295))), ((uintptr_t)(315)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ee80  (orig 0x29ee80, call)
extern void callee_51f600();
uint64_t sdk_f_29ee80(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f600)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(316)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29eeb0  (orig 0x29eeb0, call)
extern void callee_51f5c0();
uint64_t sdk_f_29eeb0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f5c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(317)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29eee0  (orig 0x29eee0, call)
extern void callee_51dd20();
uint64_t sdk_f_29eee0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(318)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ef10  (orig 0x29ef10, call)
extern void callee_51f610();
uint64_t sdk_f_29ef10(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f610)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (4294967295))), ((uintptr_t)(319)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ef40  (orig 0x29ef40, ptr_add)
void* sdk_f_29ef40(void* a0) { return (char*)a0 + 8; }

// sub_29ef50  (orig 0x29ef50, straight)
void* sdk_f_29ef50(void* a0) { return (char*)(a0) - 8; }

// sub_29ff60  (orig 0x29ff60, ptr_add)
void* sdk_f_29ff60(void* a0) { return (char*)a0 + 16; }

// sub_29ff70  (orig 0x29ff70, call)
extern void callee_5128a0();
uint64_t sdk_f_29ff70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ff90  (orig 0x29ff90, call)
extern void callee_51ded0();
uint64_t sdk_f_29ff90(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(501)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ffc0  (orig 0x29ffc0, call)
extern void callee_5128a0();
uint64_t sdk_f_29ffc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(502)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_29ffe0  (orig 0x29ffe0, call)
extern void callee_51ded0();
uint64_t sdk_f_29ffe0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51ded0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(503)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2a0010  (orig 0x2a0010, ptr_add)
void* sdk_f_2a0010(void* a0) { return (char*)a0 + 8; }

// sub_2a0020  (orig 0x2a0020, straight)
void* sdk_f_2a0020(void* a0) { return (char*)(a0) - 8; }

// sub_2a00e0  (orig 0x2a00e0, straight)
void sdk_f_2a00e0(void* a0, void* a1) {
    uint64_t k0 = 1068149419;
    *(uint32_t*)((char*)(a0)) = (uint32_t)k0;
    *(uint32_t*)((char*)(a1)) = 1065353216;
}

// sub_2a2660  (orig 0x2a2660, straight)
void sdk_f_2a2660(void* a0, void* a1) {
    uint64_t k0 = 1068149419;
    *(uint32_t*)((char*)(a0)) = (uint32_t)k0;
    *(uint32_t*)((char*)(a1)) = 1065353216;
}

// sub_2a7f40  (orig 0x2a7f40, straight)
uint32_t sdk_f_2a7f40(void* a0, uint64_t a1) {
    *(uint8_t*)((char*)(a0)) = (uint8_t)(a1);
    return 0;
}

// sub_2b25a0  (orig 0x2b25a0, ret_only)
void sdk_f_2b25a0() {}

// sub_2b2810  (orig 0x2b2810, ptr_add)
void* sdk_f_2b2810(void* a0) { return (char*)a0 + 16; }

// sub_2b28f0  (orig 0x2b28f0, ptr_add)
void* sdk_f_2b28f0(void* a0) { return (char*)a0 + 8; }

// sub_2b2900  (orig 0x2b2900, straight)
void* sdk_f_2b2900(void* a0) { return (char*)(a0) - 8; }

// sub_2b2cc0  (orig 0x2b2cc0, ptr_add)
void* sdk_f_2b2cc0(void* a0) { return (char*)a0 + 16; }

// sub_2b2d10  (orig 0x2b2d10, call)
extern void callee_5127e0();
uint64_t sdk_f_2b2d10(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5127e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b2dc0  (orig 0x2b2dc0, ptr_add)
void* sdk_f_2b2dc0(void* a0) { return (char*)a0 + 8; }

// sub_2b2dd0  (orig 0x2b2dd0, straight)
void* sdk_f_2b2dd0(void* a0) { return (char*)(a0) - 8; }

// sub_2b3dc0  (orig 0x2b3dc0, setter-chain-zero)
void sdk_f_2b3dc0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_2b3dd0  (orig 0x2b3dd0, getter)
uint32_t sdk_f_2b3dd0(void* a0) { return *(uint32_t*)((char*)(a0) + 12); }

// sub_2b4580  (orig 0x2b4580, getter)
uint32_t sdk_f_2b4580(void* a0) { return *(uint32_t*)((char*)(a0) + 20); }

// sub_2b4fb0  (orig 0x2b4fb0, setter-chain)
void sdk_f_2b4fb0(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint32_t*)((char*)(a0) + 4) = 0; }

// sub_2b4fc0  (orig 0x2b4fc0, ret_only)
void sdk_f_2b4fc0() {}

// sub_2b4fd0  (orig 0x2b4fd0, getter)
uint32_t sdk_f_2b4fd0(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_2b5460  (orig 0x2b5460, ret_only)
void sdk_f_2b5460() {}

// sub_2b5480  (orig 0x2b5480, setter)
void sdk_f_2b5480(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0)) = a1; }

// sub_2b5490  (orig 0x2b5490, straight)
void sdk_f_2b5490(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0) + 8) = (uint8_t)((((uint32_t)a1)) & (1));
}

// sub_2b55c0  (orig 0x2b55c0, mov_ret)
uint32_t sdk_f_2b55c0() { return 32; }

// sub_2b5640  (orig 0x2b5640, ret_only)
void sdk_f_2b5640() {}

// sub_2b5700  (orig 0x2b5700, mov_ret)
uint32_t sdk_f_2b5700() { return 28; }

// sub_2b5860  (orig 0x2b5860, ret_only)
void sdk_f_2b5860() {}

// sub_2b5920  (orig 0x2b5920, mov_ret)
uint32_t sdk_f_2b5920() { return 1304; }

// sub_2b6ba0  (orig 0x2b6ba0, ret_only)
void sdk_f_2b6ba0() {}

// sub_2b6cf0  (orig 0x2b6cf0, compare)
bool sdk_f_2b6cf0(uint64_t a0, uint64_t a1) { return (uint32_t)(a0) == (uint32_t)(a1); }

// sub_2b6dc0  (orig 0x2b6dc0, straight-line)
uint32_t sdk_f_2b6dc0(uint32_t a0) { return __builtin_bswap32(((uint32_t)a0)); }

// sub_2b7270  (orig 0x2b7270, ptr_add)
void* sdk_f_2b7270(void* a0) { return (char*)a0 + 16; }

// sub_2b7310  (orig 0x2b7310, ptr_add)
void* sdk_f_2b7310(void* a0) { return (char*)a0 + 8; }

// sub_2b7320  (orig 0x2b7320, straight)
void* sdk_f_2b7320(void* a0) { return (char*)(a0) - 8; }

// sub_2b74b0  (orig 0x2b74b0, ptr_add)
void* sdk_f_2b74b0(void* a0) { return (char*)a0 + 16; }

// sub_2b74e0  (orig 0x2b74e0, call)
extern void callee_51f9d0();
uint64_t sdk_f_2b74e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f9d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1152)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7510  (orig 0x2b7510, call)
extern void callee_512770();
uint64_t sdk_f_2b7510(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512770)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7530  (orig 0x2b7530, call)
extern void callee_51f9e0();
uint64_t sdk_f_2b7530(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51f9e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7550  (orig 0x2b7550, call)
extern void callee_51e3e0();
uint64_t sdk_f_2b7550(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51e3e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7570  (orig 0x2b7570, call)
extern void callee_51f9f0();
uint64_t sdk_f_2b7570(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51f9f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7590  (orig 0x2b7590, call)
extern void callee_5126d0();
uint64_t sdk_f_2b7590(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b75b0  (orig 0x2b75b0, call)
extern void callee_51fa00();
uint64_t sdk_f_2b75b0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51fa00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1152)), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (3))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7660  (orig 0x2b7660, call)
extern void callee_512780();
uint64_t sdk_f_2b7660(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(104)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7690  (orig 0x2b7690, call)
extern void callee_512700();
uint64_t sdk_f_2b7690(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b76b0  (orig 0x2b76b0, call)
extern void callee_512700();
uint64_t sdk_f_2b76b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(201)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b76d0  (orig 0x2b76d0, call)
extern void callee_51fa20();
uint64_t sdk_f_2b76d0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51fa20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(202)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7720  (orig 0x2b7720, call)
extern void callee_512700();
uint64_t sdk_f_2b7720(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(204)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7740  (orig 0x2b7740, call)
extern void callee_512780();
uint64_t sdk_f_2b7740(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(205)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7770  (orig 0x2b7770, call)
extern void callee_51fa40();
uint64_t sdk_f_2b7770(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51fa40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(206)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b77a0  (orig 0x2b77a0, call)
extern void callee_512760();
uint64_t sdk_f_2b77a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(207)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b77d0  (orig 0x2b77d0, call)
extern void callee_515280();
uint64_t sdk_f_2b77d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(208)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7800  (orig 0x2b7800, call)
extern void callee_512700();
uint64_t sdk_f_2b7800(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(209)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7820  (orig 0x2b7820, call)
extern void callee_512700();
uint64_t sdk_f_2b7820(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(300)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7840  (orig 0x2b7840, call)
extern void callee_512700();
uint64_t sdk_f_2b7840(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b78d0  (orig 0x2b78d0, call)
extern void callee_512700();
uint64_t sdk_f_2b78d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(304)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b78f0  (orig 0x2b78f0, call)
extern void callee_519270();
uint64_t sdk_f_2b78f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7910  (orig 0x2b7910, call)
extern void callee_512700();
uint64_t sdk_f_2b7910(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(401)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7930  (orig 0x2b7930, call)
extern void callee_51dd20();
uint64_t sdk_f_2b7930(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(402)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b7960  (orig 0x2b7960, ptr_add)
void* sdk_f_2b7960(void* a0) { return (char*)a0 + 8; }

// sub_2b7970  (orig 0x2b7970, straight)
void* sdk_f_2b7970(void* a0) { return (char*)(a0) - 8; }

// sub_2b8b00  (orig 0x2b8b00, ptr_add)
void* sdk_f_2b8b00(void* a0) { return (char*)a0 + 16; }

// sub_2b8ba0  (orig 0x2b8ba0, ptr_add)
void* sdk_f_2b8ba0(void* a0) { return (char*)a0 + 8; }

// sub_2b8bb0  (orig 0x2b8bb0, straight)
void* sdk_f_2b8bb0(void* a0) { return (char*)(a0) - 8; }

// sub_2b8d40  (orig 0x2b8d40, ptr_add)
void* sdk_f_2b8d40(void* a0) { return (char*)a0 + 16; }

// sub_2b8d70  (orig 0x2b8d70, call)
extern void callee_51f9d0();
uint64_t sdk_f_2b8d70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f9d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1152)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b8da0  (orig 0x2b8da0, call)
extern void callee_512770();
uint64_t sdk_f_2b8da0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512770)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b8dc0  (orig 0x2b8dc0, call)
extern void callee_51f9e0();
uint64_t sdk_f_2b8dc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51f9e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b8de0  (orig 0x2b8de0, call)
extern void callee_51e3e0();
uint64_t sdk_f_2b8de0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51e3e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b8e00  (orig 0x2b8e00, call)
extern void callee_51f9f0();
uint64_t sdk_f_2b8e00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51f9f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b8e20  (orig 0x2b8e20, call)
extern void callee_512700();
uint64_t sdk_f_2b8e20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b8e40  (orig 0x2b8e40, call)
extern void callee_512700();
uint64_t sdk_f_2b8e40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b8e60  (orig 0x2b8e60, ptr_add)
void* sdk_f_2b8e60(void* a0) { return (char*)a0 + 8; }

// sub_2b8e70  (orig 0x2b8e70, straight)
void* sdk_f_2b8e70(void* a0) { return (char*)(a0) - 8; }

// sub_2b8f50  (orig 0x2b8f50, ptr_add)
void* sdk_f_2b8f50(void* a0) { return (char*)a0 + 16; }

// sub_2b8ff0  (orig 0x2b8ff0, ptr_add)
void* sdk_f_2b8ff0(void* a0) { return (char*)a0 + 8; }

// sub_2b9000  (orig 0x2b9000, straight)
void* sdk_f_2b9000(void* a0) { return (char*)(a0) - 8; }

// sub_2b9190  (orig 0x2b9190, ptr_add)
void* sdk_f_2b9190(void* a0) { return (char*)a0 + 16; }

// sub_2b91c0  (orig 0x2b91c0, call)
extern void callee_51f9d0();
uint64_t sdk_f_2b91c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51f9d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1152)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b91f0  (orig 0x2b91f0, call)
extern void callee_512770();
uint64_t sdk_f_2b91f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512770)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9210  (orig 0x2b9210, call)
extern void callee_51f9e0();
uint64_t sdk_f_2b9210(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51f9e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9230  (orig 0x2b9230, call)
extern void callee_51e3e0();
uint64_t sdk_f_2b9230(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51e3e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9250  (orig 0x2b9250, call)
extern void callee_51f9f0();
uint64_t sdk_f_2b9250(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51f9f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9270  (orig 0x2b9270, call)
extern void callee_5126d0();
uint64_t sdk_f_2b9270(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9290  (orig 0x2b9290, call)
extern void callee_51fa00();
uint64_t sdk_f_2b9290(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51fa00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1152)), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (3))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9340  (orig 0x2b9340, call)
extern void callee_512780();
uint64_t sdk_f_2b9340(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(104)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9370  (orig 0x2b9370, call)
extern void callee_512700();
uint64_t sdk_f_2b9370(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9390  (orig 0x2b9390, call)
extern void callee_512700();
uint64_t sdk_f_2b9390(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(201)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b93b0  (orig 0x2b93b0, call)
extern void callee_51fa20();
uint64_t sdk_f_2b93b0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51fa20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(202)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9400  (orig 0x2b9400, call)
extern void callee_512700();
uint64_t sdk_f_2b9400(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(204)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9420  (orig 0x2b9420, call)
extern void callee_512780();
uint64_t sdk_f_2b9420(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (4294967295))), ((uintptr_t)(205)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9450  (orig 0x2b9450, call)
extern void callee_51fa40();
uint64_t sdk_f_2b9450(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51fa40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(206)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9480  (orig 0x2b9480, call)
extern void callee_512760();
uint64_t sdk_f_2b9480(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(207)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b94b0  (orig 0x2b94b0, call)
extern void callee_515280();
uint64_t sdk_f_2b94b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(208)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b94e0  (orig 0x2b94e0, call)
extern void callee_512700();
uint64_t sdk_f_2b94e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(209)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9500  (orig 0x2b9500, call)
extern void callee_512700();
uint64_t sdk_f_2b9500(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(300)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9520  (orig 0x2b9520, call)
extern void callee_512700();
uint64_t sdk_f_2b9520(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b95b0  (orig 0x2b95b0, call)
extern void callee_512700();
uint64_t sdk_f_2b95b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(304)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b95d0  (orig 0x2b95d0, call)
extern void callee_519270();
uint64_t sdk_f_2b95d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_519270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b95f0  (orig 0x2b95f0, call)
extern void callee_512700();
uint64_t sdk_f_2b95f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(401)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9610  (orig 0x2b9610, call)
extern void callee_512780();
uint64_t sdk_f_2b9610(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(402)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9640  (orig 0x2b9640, call)
extern void callee_51dd20();
uint64_t sdk_f_2b9640(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dd20)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(403)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2b9670  (orig 0x2b9670, ptr_add)
void* sdk_f_2b9670(void* a0) { return (char*)a0 + 8; }

// sub_2b9680  (orig 0x2b9680, straight)
void* sdk_f_2b9680(void* a0) { return (char*)(a0) - 8; }

// sub_2b9740  (orig 0x2b9740, getter)
uint64_t sdk_f_2b9740(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_2b9750  (orig 0x2b9750, setter)
void sdk_f_2b9750(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0)) = a1; }

// sub_2b9760  (orig 0x2b9760, getter)
uint64_t sdk_f_2b9760(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_2b9770  (orig 0x2b9770, setter)
void sdk_f_2b9770(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 8) = a1; }

// sub_2b9780  (orig 0x2b9780, straight)
uint8_t sdk_f_2b9780(void* a0) { return (*(uint8_t*)((char*)(a0) + 16)) & (1); }

// sub_2b97a0  (orig 0x2b97a0, straight)
uint8_t sdk_f_2b97a0(void* a0) { return ((*(uint8_t*)((char*)(a0) + 16)) >> (1)) & (1); }

// sub_2b97d0  (orig 0x2b97d0, straight)
uint8_t sdk_f_2b97d0(void* a0) { return ((*(uint8_t*)((char*)(a0) + 16)) >> (2)) & (1); }

// sub_2b9800  (orig 0x2b9800, getter)
uint8_t sdk_f_2b9800(void* a0) { return *(uint8_t*)((char*)(a0) + 18); }

// sub_2b9810  (orig 0x2b9810, setter)
void sdk_f_2b9810(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 18) = a1; }

// sub_2b9820  (orig 0x2b9820, getter)
uint8_t sdk_f_2b9820(void* a0) { return *(uint8_t*)((char*)(a0) + 19); }

// sub_2b9830  (orig 0x2b9830, setter)
void sdk_f_2b9830(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 19) = a1; }

// sub_2b9840  (orig 0x2b9840, getter)
uint32_t sdk_f_2b9840(void* a0) { return *(uint32_t*)((char*)(a0) + 20); }

// sub_2b9850  (orig 0x2b9850, setter)
void sdk_f_2b9850(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 20) = a1; }

// sub_2b9ea0  (orig 0x2b9ea0, straight)
uint64_t sdk_f_2b9ea0(void* a0) { return (*(uint64_t*)((char*)(a0) + 16)) - (*(uint64_t*)((char*)(a0) + 32)); }

// sub_2ba6a0  (orig 0x2ba6a0, ptr_add)
void* sdk_f_2ba6a0(void* a0) { return (char*)a0 + 16; }

// sub_2ba6d0  (orig 0x2ba6d0, call)
extern void callee_512700();
uint64_t sdk_f_2ba6d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ba720  (orig 0x2ba720, ptr_add)
void* sdk_f_2ba720(void* a0) { return (char*)a0 + 8; }

// sub_2ba730  (orig 0x2ba730, straight)
void* sdk_f_2ba730(void* a0) { return (char*)(a0) - 8; }

// sub_2bab70  (orig 0x2bab70, ptr_add)
void* sdk_f_2bab70(void* a0) { return (char*)a0 + 16; }

// sub_2bac30  (orig 0x2bac30, ptr_add)
void* sdk_f_2bac30(void* a0) { return (char*)a0 + 8; }

// sub_2bac40  (orig 0x2bac40, straight)
void* sdk_f_2bac40(void* a0) { return (char*)(a0) - 8; }

// sub_2badc0  (orig 0x2badc0, ptr_add)
void* sdk_f_2badc0(void* a0) { return (char*)a0 + 16; }

// sub_2bae00  (orig 0x2bae00, call)
extern void callee_512780();
uint64_t sdk_f_2bae00(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2bae30  (orig 0x2bae30, ptr_add)
void* sdk_f_2bae30(void* a0) { return (char*)a0 + 8; }

// sub_2bae40  (orig 0x2bae40, straight)
void* sdk_f_2bae40(void* a0) { return (char*)(a0) - 8; }

// sub_2bb6d0  (orig 0x2bb6d0, call)
extern void callee_51fdb0();
uint32_t sdk_f_2bb6d0() {
    uint32_t r0 = (((uint32_t (*)(void))&callee_51fdb0)()) & (65535);
    asm volatile("");
    return r0;
}

// sub_2bc050  (orig 0x2bc050, setter-chain)
void sdk_f_2bc050(void* a0, uint32_t a1, uint64_t a2, uint64_t a3, uint8_t a4) { *(uint32_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 48) = a2; *(uint64_t*)((char*)(a0) + 56) = a3; *(uint8_t*)((char*)(a0) + 96) = a4; }

// sub_2bc060  (orig 0x2bc060, ret_only)
void sdk_f_2bc060() {}

// sub_2bc070  (orig 0x2bc070, ret_only)
void sdk_f_2bc070() {}

// sub_2bc7d0  (orig 0x2bc7d0, straight)
uint16_t sdk_f_2bc7d0(void* a0) { return (*(uint16_t*)((char*)(a0) + 138)) & (1); }

// sub_2bc800  (orig 0x2bc800, getter)
uint8_t sdk_f_2bc800(void* a0) { return *(uint8_t*)((char*)(a0) + 140); }

// sub_2bc820  (orig 0x2bc820, getter)
uint16_t sdk_f_2bc820(void* a0) { return *(uint16_t*)((char*)(a0) + 136); }

// sub_2bc830  (orig 0x2bc830, getter)
uint64_t sdk_f_2bc830(void* a0) { return *(uint64_t*)((char*)(a0) - 24); }

// sub_2bc840  (orig 0x2bc840, getter)
uint8_t sdk_f_2bc840(void* a0) { return *(uint8_t*)((char*)(a0) - 28); }

// sub_2bc850  (orig 0x2bc850, straight)
uint32_t sdk_f_2bc850(void* a0) { return ((*(uint32_t*)((char*)(a0) - 28)) >> (15)) & (1); }

// sub_2bcea0  (orig 0x2bcea0, getter)
uint64_t sdk_f_2bcea0(void* a0) { return *(uint64_t*)((char*)(a0) + 104); }

// sub_2bceb0  (orig 0x2bceb0, getter)
uint64_t sdk_f_2bceb0(void* a0) { return *(uint64_t*)((char*)(a0) + 112); }

// sub_2bd0b0  (orig 0x2bd0b0, pair-ret)
struct pair16_f_2bd0b0_ { uint64_t f[2]; }; pair16_f_2bd0b0_ sdk_f_2bd0b0(void* a0) { return *(struct pair16_f_2bd0b0_ *)((char*)(a0) + 104); }

// sub_2bd0c0  (orig 0x2bd0c0, straight)
void sdk_f_2bd0c0(void* a0, void* a1) {
    *(uint64_t*)((char*)(a0) + 104) = *(uint64_t*)((char*)(a1));
    *(uint64_t*)((char*)(a0) + 112) = *(uint64_t*)((char*)(a1) + 8);
}

// sub_2bd390  (orig 0x2bd390, setter)
void sdk_f_2bd390(void* a0) { *(uint64_t*)((char*)(a0) + 104) = 0; }

// sub_2bd4b0  (orig 0x2bd4b0, getter)
uint64_t sdk_f_2bd4b0(void* a0) { return *(uint64_t*)((char*)(a0) + 112); }

// sub_2bd4f0  (orig 0x2bd4f0, getter)
uint32_t sdk_f_2bd4f0(void* a0) { return *(uint32_t*)((char*)(a0) + 124); }

// sub_2bd500  (orig 0x2bd500, getter)
uint32_t sdk_f_2bd500(void* a0) { return *(uint32_t*)((char*)(a0) + 120); }

// sub_2bdbf0  (orig 0x2bdbf0, getter)
uint32_t sdk_f_2bdbf0(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_2bdc00  (orig 0x2bdc00, ptr_add)
void* sdk_f_2bdc00(void* a0) { return (char*)a0 + 8; }

// sub_2bdc10  (orig 0x2bdc10, getter)
uint64_t sdk_f_2bdc10(void* a0) { return *(uint64_t*)((char*)(a0) + 4104L); }

// sub_2bdee0  (orig 0x2bdee0, const-ret)
uint32_t sdk_f_2bdee0() { return 20181106u; }

// sub_2bdef0  (orig 0x2bdef0, const-ret)
uint32_t sdk_f_2bdef0() { return 70001u; }

// sub_2bdf50  (orig 0x2bdf50, mov_ret)
uint32_t sdk_f_2bdf50() { return 0; }

// sub_2be1a0  (orig 0x2be1a0, mov_ret)
uint32_t sdk_f_2be1a0() { return 22; }

// sub_2be1b0  (orig 0x2be1b0, mov_ret)
uint32_t sdk_f_2be1b0() { return 22; }

// sub_2d0dc0  (orig 0x2d0dc0, mov_ret)
uint32_t sdk_f_2d0dc0() { return 22; }

// sub_2d0dd0  (orig 0x2d0dd0, mov_ret)
uint32_t sdk_f_2d0dd0() { return 22; }

// sub_2d0de0  (orig 0x2d0de0, mov_ret)
uint32_t sdk_f_2d0de0() { return 22; }

// sub_2d2070  (orig 0x2d2070, ret_only)
void sdk_f_2d2070() {}

// sub_2d21a0  (orig 0x2d21a0, call)
extern void callee_520420();
uint32_t sdk_f_2d21a0() {
    callee_520420();
    uint32_t r0 = 0;
    asm volatile("");
    return r0;
}

// sub_2d21c0  (orig 0x2d21c0, call)
extern void callee_520430();
uint32_t sdk_f_2d21c0() {
    callee_520430();
    uint32_t r0 = 0;
    asm volatile("");
    return r0;
}

// sub_2d22b0  (orig 0x2d22b0, straight)
uint32_t sdk_f_2d22b0(void* a0) {
    uint32_t k0 = 2097152;
    *(uint64_t*)((char*)(a0)) = (uint64_t)k0;
    return 0;
}

// sub_2d2b60  (orig 0x2d2b60, mov_ret)
uint32_t sdk_f_2d2b60() { return 0; }

// sub_2d2b70  (orig 0x2d2b70, mov_ret)
uint32_t sdk_f_2d2b70() { return 0; }

// sub_2d2d50  (orig 0x2d2d50, call)
extern void callee_520510();
uint32_t sdk_f_2d2d50() {
    callee_520510();
    uint32_t r0 = 0;
    asm volatile("");
    return r0;
}

// sub_2d2e20  (orig 0x2d2e20, call)
extern void callee_520560();
uint32_t sdk_f_2d2e20() {
    callee_520560();
    uint32_t r0 = 0;
    asm volatile("");
    return r0;
}

// sub_2d3070  (orig 0x2d3070, mov_ret)
uint32_t sdk_f_2d3070() { return 38; }

// sub_2d3360  (orig 0x2d3360, straight)
uint32_t sdk_f_2d3360(void* a0) {
    *(uint32_t*)((char*)(a0)) = -16;
    return 0;
}

// sub_2d3370  (orig 0x2d3370, straight)
uint32_t sdk_f_2d3370(void* a0) {
    *(uint32_t*)((char*)(a0)) = 15;
    return 0;
}

// sub_2d3380  (orig 0x2d3380, straight)
uint32_t sdk_f_2d3380(void* a0) {
    *(uint32_t*)((char*)(a0)) = 0;
    return 0;
}

// sub_2d33a0  (orig 0x2d33a0, ret_only)
void sdk_f_2d33a0() {}

// sub_2d33b0  (orig 0x2d33b0, straight)
uint32_t sdk_f_2d33b0(void* a0, uint64_t unused1, uint64_t a2) {
    *(uint64_t*)((char*)(a0)) = (((((uint64_t)a2) < 1024)) ? (((uint64_t)a2)) : (1024));
    return 0;
}

// sub_2d33d0  (orig 0x2d33d0, straight)
uint32_t sdk_f_2d33d0(void* a0, uint64_t unused1, uint64_t a2) {
    *(uint64_t*)((char*)(a0)) = (((((uint64_t)a2) < 1024)) ? (((uint64_t)a2)) : (1024));
    return 0;
}

// sub_2d37b0  (orig 0x2d37b0, mov_ret)
uint32_t sdk_f_2d37b0() { return 0; }

// sub_2d37c0  (orig 0x2d37c0, mov_ret)
uint32_t sdk_f_2d37c0() { return 0; }

// sub_2d37d0  (orig 0x2d37d0, straight-line)
uint32_t sdk_f_2d37d0(void* a0, uint32_t a1) {
    *(uint64_t*)((char*)(a0)) = (uint64_t)(((int64_t)(((int32_t)(((uint32_t)a1))))));
    return 0;
}

// sub_2d3b10  (orig 0x2d3b10, straight)
uint32_t sdk_f_2d3b10(uint64_t a0) { return (((((uint64_t)a0) == 0)) ? (22) : (95)); }

// sub_2d3b30  (orig 0x2d3b30, mov_ret)
uint32_t sdk_f_2d3b30() { return 95; }

// sub_2d3b40  (orig 0x2d3b40, mov_ret)
uint32_t sdk_f_2d3b40() { return 95; }

// sub_2d3cd0  (orig 0x2d3cd0, mov_ret)
uint64_t sdk_f_2d3cd0() { return 0; }

// sub_2d3ce0  (orig 0x2d3ce0, ret_only)
void sdk_f_2d3ce0() {}

// sub_2d3cf0  (orig 0x2d3cf0, mov_ret)
uint64_t sdk_f_2d3cf0() { return 0; }

// sub_2d3d00  (orig 0x2d3d00, mov_ret)
uint64_t sdk_f_2d3d00() { return 0; }

// sub_2d3d10  (orig 0x2d3d10, mov_ret)
uint64_t sdk_f_2d3d10() { return 0; }

// sub_2d3d20  (orig 0x2d3d20, ret_only)
void sdk_f_2d3d20() {}

// sub_2d3d30  (orig 0x2d3d30, mov_ret)
uint64_t sdk_f_2d3d30() { return 0; }

// sub_2d5c20  (orig 0x2d5c20, mov_ret)
uint32_t sdk_f_2d5c20() { return 1; }

// sub_2d7800  (orig 0x2d7800, setter)
void sdk_f_2d7800(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_2de140  (orig 0x2de140, straight-line)
void sdk_f_2de140(void* a0) {
    uint16_t k0 = 0;
    uint16_t k1 = 0;
    *(uint16_t*)((char*)(a0)) = 0;
    *(uint64_t*)((char*)(a0) + 8) = 0;
    *(uint64_t*)((char*)(a0) + 24) = 0;
    *(uint8_t*)((char*)(a0) + 32) = (uint8_t)k0;
    *(uint32_t*)((char*)(a0) + 52) = (uint32_t)k1;
    *(uint64_t*)((char*)(a0) + 44) = 0;
    *(uint64_t*)((char*)(a0) + 36) = 0;
}

// sub_2e1640  (orig 0x2e1640, getter)
uint8_t sdk_f_2e1640(void* a0) { return *(uint8_t*)((char*)(a0) + 38); }

// sub_2e1650  (orig 0x2e1650, getter)
uint8_t sdk_f_2e1650(void* a0) { return *(uint8_t*)((char*)(a0) + 39); }

// sub_2e1660  (orig 0x2e1660, getter)
uint8_t sdk_f_2e1660(void* a0) { return *(uint8_t*)((char*)(a0) + 40); }

// sub_2e1670  (orig 0x2e1670, getter)
uint8_t sdk_f_2e1670(void* a0) { return *(uint8_t*)((char*)(a0) + 41); }

// sub_2e1680  (orig 0x2e1680, getter)
uint8_t sdk_f_2e1680(void* a0) { return *(uint8_t*)((char*)(a0) + 42); }

// sub_2e1690  (orig 0x2e1690, compare)
bool sdk_f_2e1690(void* a0) { return (uint8_t)(*(uint8_t*)((char*)(a0) + 51)) == (uint64_t)(1); }

// sub_2e16a0  (orig 0x2e16a0, getter)
uint8_t sdk_f_2e16a0(void* a0) { return *(uint8_t*)((char*)(a0) + 49); }

// sub_2e16b0  (orig 0x2e16b0, getter)
uint8_t sdk_f_2e16b0(void* a0) { return *(uint8_t*)((char*)(a0) + 45); }

// sub_2e16c0  (orig 0x2e16c0, getter)
uint8_t sdk_f_2e16c0(void* a0) { return *(uint8_t*)((char*)(a0) + 46); }

// sub_2e1b40  (orig 0x2e1b40, call)
extern void callee_5181b0();
uint32_t sdk_f_2e1b40(uint64_t a0, uint64_t a1) {
    uint32_t r0 = ((((uint32_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5181b0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(22))) == 0) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_2e1b60  (orig 0x2e1b60, delegator)
extern void callee_520b70();
void sdk_f_2e1b60(unsigned long a0) { ((void(*)(unsigned long))callee_520b70)(a0); asm volatile(""); }

// sub_2e1b80  (orig 0x2e1b80, delegator)
extern void callee_520b80();
void sdk_f_2e1b80(unsigned long a0) { ((void(*)(unsigned long))callee_520b80)(a0); asm volatile(""); }

// sub_2e1cb0  (orig 0x2e1cb0, getter)
uint8_t sdk_f_2e1cb0(void* a0) { return *(uint8_t*)((char*)(a0) + 38); }

// sub_2e1cc0  (orig 0x2e1cc0, getter)
uint8_t sdk_f_2e1cc0(void* a0) { return *(uint8_t*)((char*)(a0) + 39); }

// sub_2e1cd0  (orig 0x2e1cd0, getter)
uint8_t sdk_f_2e1cd0(void* a0) { return *(uint8_t*)((char*)(a0) + 40); }

// sub_2e1ce0  (orig 0x2e1ce0, getter)
uint8_t sdk_f_2e1ce0(void* a0) { return *(uint8_t*)((char*)(a0) + 41); }

// sub_2e1cf0  (orig 0x2e1cf0, getter)
uint8_t sdk_f_2e1cf0(void* a0) { return *(uint8_t*)((char*)(a0) + 42); }

// sub_2e1d00  (orig 0x2e1d00, pair-ret)
struct pair16_f_2e1d00_ { uint64_t f[2]; }; pair16_f_2e1d00_ sdk_f_2e1d00(void* a0) { return *(struct pair16_f_2e1d00_ *)((char*)(a0)); }

// sub_2e1d10  (orig 0x2e1d10, compare)
bool sdk_f_2e1d10(void* a0) { return (uint8_t)(*(uint8_t*)((char*)(a0) + 43)) == (uint64_t)(1); }

// sub_2e1d20  (orig 0x2e1d20, getter)
uint8_t sdk_f_2e1d20(void* a0) { return *(uint8_t*)((char*)(a0) + 44); }

// sub_2e1d30  (orig 0x2e1d30, getter)
uint8_t sdk_f_2e1d30(void* a0) { return *(uint8_t*)((char*)(a0) + 45); }

// sub_2e1d40  (orig 0x2e1d40, getter)
uint8_t sdk_f_2e1d40(void* a0) { return *(uint8_t*)((char*)(a0) + 46); }

// sub_2e1d50  (orig 0x2e1d50, getter)
uint8_t sdk_f_2e1d50(void* a0) { return *(uint8_t*)((char*)(a0) + 47); }

// sub_2e1d60  (orig 0x2e1d60, getter)
uint8_t sdk_f_2e1d60(void* a0) { return *(uint8_t*)((char*)(a0) + 48); }

// sub_2e1d70  (orig 0x2e1d70, getter)
uint8_t sdk_f_2e1d70(void* a0) { return *(uint8_t*)((char*)(a0) + 49); }

// sub_2e1d80  (orig 0x2e1d80, getter)
uint8_t sdk_f_2e1d80(void* a0) { return *(uint8_t*)((char*)(a0) + 50); }

// sub_2e1d90  (orig 0x2e1d90, getter)
uint8_t sdk_f_2e1d90(void* a0) { return *(uint8_t*)((char*)(a0) + 51); }

// sub_2e1da0  (orig 0x2e1da0, getter)
uint8_t sdk_f_2e1da0(void* a0) { return *(uint8_t*)((char*)(a0) + 52); }

// sub_2e1db0  (orig 0x2e1db0, getter)
uint8_t sdk_f_2e1db0(void* a0) { return *(uint8_t*)((char*)(a0) + 53); }

// sub_2e1dc0  (orig 0x2e1dc0, getter)
uint8_t sdk_f_2e1dc0(void* a0) { return *(uint8_t*)((char*)(a0) + 54); }

// sub_2e1dd0  (orig 0x2e1dd0, getter)
uint8_t sdk_f_2e1dd0(void* a0) { return *(uint8_t*)((char*)(a0) + 55); }

// sub_2e1de0  (orig 0x2e1de0, getter)
uint8_t sdk_f_2e1de0(void* a0) { return *(uint8_t*)((char*)(a0) + 56); }

// sub_2e1df0  (orig 0x2e1df0, getter)
uint8_t sdk_f_2e1df0(void* a0) { return *(uint8_t*)((char*)(a0) + 57); }

// sub_2e1e00  (orig 0x2e1e00, getter)
uint8_t sdk_f_2e1e00(void* a0) { return *(uint8_t*)((char*)(a0) + 58); }

// sub_2e1e10  (orig 0x2e1e10, getter)
uint8_t sdk_f_2e1e10(void* a0) { return *(uint8_t*)((char*)(a0) + 59); }

// sub_2e1e20  (orig 0x2e1e20, getter)
uint8_t sdk_f_2e1e20(void* a0) { return *(uint8_t*)((char*)(a0) + 60); }

// sub_2e1e30  (orig 0x2e1e30, getter)
uint8_t sdk_f_2e1e30(void* a0) { return *(uint8_t*)((char*)(a0) + 61); }

// sub_2e1e40  (orig 0x2e1e40, getter)
uint8_t sdk_f_2e1e40(void* a0) { return *(uint8_t*)((char*)(a0) + 62); }

// sub_2e1e50  (orig 0x2e1e50, getter)
uint8_t sdk_f_2e1e50(void* a0) { return *(uint8_t*)((char*)(a0) + 63); }

// sub_2e1e60  (orig 0x2e1e60, getter)
uint8_t sdk_f_2e1e60(void* a0) { return *(uint8_t*)((char*)(a0) + 64); }

// sub_2e1e70  (orig 0x2e1e70, getter)
uint8_t sdk_f_2e1e70(void* a0) { return *(uint8_t*)((char*)(a0) + 65); }

// sub_2e1e80  (orig 0x2e1e80, getter)
uint8_t sdk_f_2e1e80(void* a0) { return *(uint8_t*)((char*)(a0) + 66); }

// sub_2e1e90  (orig 0x2e1e90, getter)
uint8_t sdk_f_2e1e90(void* a0) { return *(uint8_t*)((char*)(a0) + 67); }

// sub_2e1ea0  (orig 0x2e1ea0, getter)
uint8_t sdk_f_2e1ea0(void* a0) { return *(uint8_t*)((char*)(a0) + 68); }

// sub_2e1eb0  (orig 0x2e1eb0, getter)
uint8_t sdk_f_2e1eb0(void* a0) { return *(uint8_t*)((char*)(a0) + 69); }

// sub_2e1ec0  (orig 0x2e1ec0, getter)
uint8_t sdk_f_2e1ec0(void* a0) { return *(uint8_t*)((char*)(a0) + 70); }

// sub_2e1ed0  (orig 0x2e1ed0, getter)
uint8_t sdk_f_2e1ed0(void* a0) { return *(uint8_t*)((char*)(a0) + 71); }

// sub_2e1ee0  (orig 0x2e1ee0, getter)
uint8_t sdk_f_2e1ee0(void* a0) { return *(uint8_t*)((char*)(a0) + 72); }

// sub_2e1ef0  (orig 0x2e1ef0, getter)
uint8_t sdk_f_2e1ef0(void* a0) { return *(uint8_t*)((char*)(a0) + 73); }

// sub_2e1f00  (orig 0x2e1f00, getter)
uint8_t sdk_f_2e1f00(void* a0) { return *(uint8_t*)((char*)(a0) + 74); }

// sub_2e1f10  (orig 0x2e1f10, getter)
uint8_t sdk_f_2e1f10(void* a0) { return *(uint8_t*)((char*)(a0) + 75); }

// sub_2e1f20  (orig 0x2e1f20, getter)
uint8_t sdk_f_2e1f20(void* a0) { return *(uint8_t*)((char*)(a0) + 76); }

// sub_2e1f30  (orig 0x2e1f30, getter)
uint8_t sdk_f_2e1f30(void* a0) { return *(uint8_t*)((char*)(a0) + 77); }

// sub_2e1f40  (orig 0x2e1f40, getter)
uint8_t sdk_f_2e1f40(void* a0) { return *(uint8_t*)((char*)(a0) + 78); }

// sub_2e1f50  (orig 0x2e1f50, getter)
uint8_t sdk_f_2e1f50(void* a0) { return *(uint8_t*)((char*)(a0) + 79); }

// sub_2e1f60  (orig 0x2e1f60, getter)
uint8_t sdk_f_2e1f60(void* a0) { return *(uint8_t*)((char*)(a0) + 80); }

// sub_2e1f70  (orig 0x2e1f70, getter)
uint8_t sdk_f_2e1f70(void* a0) { return *(uint8_t*)((char*)(a0) + 81); }

// sub_2e1f80  (orig 0x2e1f80, getter)
uint8_t sdk_f_2e1f80(void* a0) { return *(uint8_t*)((char*)(a0) + 82); }

// sub_2e1f90  (orig 0x2e1f90, getter)
uint8_t sdk_f_2e1f90(void* a0) { return *(uint8_t*)((char*)(a0) + 83); }

// sub_2e1fa0  (orig 0x2e1fa0, getter)
uint8_t sdk_f_2e1fa0(void* a0) { return *(uint8_t*)((char*)(a0) + 84); }

// sub_2e1fb0  (orig 0x2e1fb0, getter)
uint8_t sdk_f_2e1fb0(void* a0) { return *(uint8_t*)((char*)(a0) + 85); }

// sub_2e1fc0  (orig 0x2e1fc0, getter)
uint8_t sdk_f_2e1fc0(void* a0) { return *(uint8_t*)((char*)(a0) + 86); }

// sub_2e21c0  (orig 0x2e21c0, call)
extern void callee_520ba0();
uint32_t sdk_f_2e21c0() {
    uint32_t r0 = ((~((uint32_t)((uint32_t (*)(void))&callee_520ba0)()))) & (1);
    asm volatile("");
    return r0;
}

// sub_2e2280  (orig 0x2e2280, delegator)
extern void callee_520bc0();
void sdk_f_2e2280(unsigned long a0) { ((void(*)(unsigned long))callee_520bc0)(a0); asm volatile(""); }

// sub_2e22a0  (orig 0x2e22a0, delegator)
extern void callee_520bd0();
void sdk_f_2e22a0(unsigned long a0) { ((void(*)(unsigned long))callee_520bd0)(a0); asm volatile(""); }

// sub_2e22c0  (orig 0x2e22c0, delegator)
extern void callee_520be0();
void sdk_f_2e22c0(unsigned long a0) { ((void(*)(unsigned long))callee_520be0)(a0); asm volatile(""); }

// sub_2e22e0  (orig 0x2e22e0, delegator)
extern void callee_520bf0();
void sdk_f_2e22e0(unsigned long a0) { ((void(*)(unsigned long))callee_520bf0)(a0); asm volatile(""); }

// sub_2e2300  (orig 0x2e2300, delegator)
extern void callee_520c00();
void sdk_f_2e2300(unsigned long a0) { ((void(*)(unsigned long))callee_520c00)(a0); asm volatile(""); }

// sub_2e2320  (orig 0x2e2320, delegator)
extern void callee_520c10();
void sdk_f_2e2320(unsigned long a0) { ((void(*)(unsigned long))callee_520c10)(a0); asm volatile(""); }

// sub_2e2340  (orig 0x2e2340, delegator)
extern void callee_520c20();
void sdk_f_2e2340(unsigned long a0) { ((void(*)(unsigned long))callee_520c20)(a0); asm volatile(""); }

// sub_2e2360  (orig 0x2e2360, delegator)
extern void callee_520c30();
void sdk_f_2e2360(unsigned long a0) { ((void(*)(unsigned long))callee_520c30)(a0); asm volatile(""); }

// sub_2e2380  (orig 0x2e2380, delegator)
extern void callee_520c40();
void sdk_f_2e2380(unsigned long a0) { ((void(*)(unsigned long))callee_520c40)(a0); asm volatile(""); }

// sub_2e23a0  (orig 0x2e23a0, delegator)
extern void callee_520c50();
void sdk_f_2e23a0(unsigned long a0) { ((void(*)(unsigned long))callee_520c50)(a0); asm volatile(""); }

// sub_2e23c0  (orig 0x2e23c0, delegator)
extern void callee_520b80();
void sdk_f_2e23c0(unsigned long a0) { ((void(*)(unsigned long))callee_520b80)(a0); asm volatile(""); }

// sub_2e23e0  (orig 0x2e23e0, ret_only)
void sdk_f_2e23e0() {}

// sub_2e2400  (orig 0x2e2400, call)
extern void callee_520c60();
uint32_t sdk_f_2e2400() {
    uint32_t r0 = ((~((uint32_t)((uint32_t (*)(void))&callee_520c60)()))) & (1);
    asm volatile("");
    return r0;
}

// sub_2e2430  (orig 0x2e2430, call)
extern void callee_520c70();
uint32_t sdk_f_2e2430() {
    uint32_t r0 = ((~((uint32_t)((uint32_t (*)(void))&callee_520c70)()))) & (1);
    asm volatile("");
    return r0;
}

// sub_2e2470  (orig 0x2e2470, ret_only)
void sdk_f_2e2470() {}

// sub_2e2480  (orig 0x2e2480, call)
extern void callee_5181b0();
uint32_t sdk_f_2e2480(uint64_t a0, uint64_t a1) {
    uint32_t r0 = ((((uint32_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5181b0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(68))) == 0) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_2e25a0  (orig 0x2e25a0, setter-chain)
void sdk_f_2e25a0(void* a0, uint64_t a1, uint64_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 8) = a1; *(uint64_t*)((char*)(a0) + 16) = a2; }

// sub_2e25b0  (orig 0x2e25b0, ret_only)
void sdk_f_2e25b0() {}

// sub_2e25c0  (orig 0x2e25c0, straight)
void sdk_f_2e25c0(void* a0, uint64_t a1) {
    *(uint64_t*)((char*)(a0)) = (*(uint64_t*)((char*)(a0))) + (((uint64_t)a1));
}

// sub_2e25e0  (orig 0x2e25e0, straight)
void sdk_f_2e25e0(void* a0, uint64_t a1) {
    *(uint64_t*)((char*)(a0)) = (((((uint64_t)a1)) + (*(uint64_t*)((char*)(a0)))) - (1)) & ((0 - ((uint64_t)((uint64_t)a1))));
}

// sub_2e2600  (orig 0x2e2600, getter)
uint64_t sdk_f_2e2600(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_2e2610  (orig 0x2e2610, getter)
uint64_t sdk_f_2e2610(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_2e2640  (orig 0x2e2640, setter)
void sdk_f_2e2640(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_2e2650  (orig 0x2e2650, ret_only)
void sdk_f_2e2650() {}

// sub_2e26c0  (orig 0x2e26c0, getter)
uint64_t sdk_f_2e26c0(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_2e26d0  (orig 0x2e26d0, mov_ret)
uint32_t sdk_f_2e26d0() { return 1; }

// sub_2e26e0  (orig 0x2e26e0, call)
extern void callee_520ca0();
uint32_t sdk_f_2e26e0() {
    uint32_t r0 = ((((uint32_t (*)(void))&callee_520ca0)() == 0) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_2e3af0  (orig 0x2e3af0, ret_only)
void sdk_f_2e3af0() {}

// sub_2e4ee0  (orig 0x2e4ee0, call)
extern void sub_2e4240();
uint32_t sdk_f_2e4ee0(uint64_t a0) {
    uint32_t r0 = ((((uint32_t (*)(uintptr_t, uintptr_t))&sub_2e4240)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(1))) == 0) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_2e7f30  (orig 0x2e7f30, straight)
void sdk_f_2e7f30(void* a0, void* a1) {
    *(uint16_t*)((char*)(a0)) = *(uint16_t*)((char*)(a1));
    *(uint16_t*)((char*)(a0) + 2) = *(uint16_t*)((char*)(a1) + 2);
    *(uint16_t*)((char*)(a0) + 4) = *(uint16_t*)((char*)(a1) + 4);
    *(uint16_t*)((char*)(a0) + 6) = *(uint16_t*)((char*)(a1) + 6);
    *(uint16_t*)((char*)(a0) + 8) = *(uint16_t*)((char*)(a1) + 8);
    *(uint16_t*)((char*)(a0) + 10) = *(uint16_t*)((char*)(a1) + 10);
    *(uint16_t*)((char*)(a0) + 12) = *(uint16_t*)((char*)(a1) + 12);
    *(uint16_t*)((char*)(a0) + 14) = *(uint16_t*)((char*)(a1) + 14);
    *(uint16_t*)((char*)(a0) + 16) = *(uint16_t*)((char*)(a1) + 16);
    *(uint16_t*)((char*)(a0) + 18) = *(uint16_t*)((char*)(a1) + 18);
    *(uint16_t*)((char*)(a0) + 20) = *(uint16_t*)((char*)(a1) + 20);
}

// sub_2e8030  (orig 0x2e8030, straight)
void sdk_f_2e8030(void* a0, void* a1) {
    *(uint16_t*)((char*)(a0)) = *(uint16_t*)((char*)(a1));
    *(uint16_t*)((char*)(a0) + 2) = *(uint16_t*)((char*)(a1) + 2);
    *(uint16_t*)((char*)(a0) + 4) = *(uint16_t*)((char*)(a1) + 4);
    *(uint16_t*)((char*)(a0) + 6) = *(uint16_t*)((char*)(a1) + 6);
    *(uint16_t*)((char*)(a0) + 8) = *(uint16_t*)((char*)(a1) + 8);
    *(uint16_t*)((char*)(a0) + 10) = *(uint16_t*)((char*)(a1) + 10);
    *(uint16_t*)((char*)(a0) + 12) = *(uint16_t*)((char*)(a1) + 12);
    *(uint16_t*)((char*)(a0) + 14) = *(uint16_t*)((char*)(a1) + 14);
    *(uint16_t*)((char*)(a0) + 16) = *(uint16_t*)((char*)(a1) + 16);
    *(uint16_t*)((char*)(a0) + 18) = *(uint16_t*)((char*)(a1) + 18);
    *(uint16_t*)((char*)(a0) + 20) = *(uint16_t*)((char*)(a1) + 20);
}

// sub_2e8130  (orig 0x2e8130, getter)
uint8_t sdk_f_2e8130(void* a0) { return *(uint8_t*)((char*)(a0)); }

// sub_2e8140  (orig 0x2e8140, getter)
uint8_t sdk_f_2e8140(void* a0) { return *(uint8_t*)((char*)(a0) + 1); }

// sub_2e8150  (orig 0x2e8150, getter)
uint8_t sdk_f_2e8150(void* a0) { return *(uint8_t*)((char*)(a0) + 2); }

// sub_2e8160  (orig 0x2e8160, getter)
uint8_t sdk_f_2e8160(void* a0) { return *(uint8_t*)((char*)(a0) + 3); }

// sub_2e8170  (orig 0x2e8170, getter)
uint8_t sdk_f_2e8170(void* a0) { return *(uint8_t*)((char*)(a0) + 4); }

// sub_2e8180  (orig 0x2e8180, getter)
uint8_t sdk_f_2e8180(void* a0) { return *(uint8_t*)((char*)(a0) + 5); }

// sub_2e8190  (orig 0x2e8190, getter)
uint8_t sdk_f_2e8190(void* a0) { return *(uint8_t*)((char*)(a0) + 6); }

// sub_2e81a0  (orig 0x2e81a0, getter)
uint8_t sdk_f_2e81a0(void* a0) { return *(uint8_t*)((char*)(a0) + 7); }

// sub_2e81b0  (orig 0x2e81b0, setter)
void sdk_f_2e81b0(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_2e81c0  (orig 0x2e81c0, setter)
void sdk_f_2e81c0(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0)) = a1; }

// sub_2e81d0  (orig 0x2e81d0, setter)
void sdk_f_2e81d0(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 1) = a1; }

// sub_2e81e0  (orig 0x2e81e0, setter)
void sdk_f_2e81e0(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 2) = a1; }

// sub_2e81f0  (orig 0x2e81f0, setter)
void sdk_f_2e81f0(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 3) = a1; }

// sub_2e8200  (orig 0x2e8200, setter)
void sdk_f_2e8200(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 4) = a1; }

// sub_2e8210  (orig 0x2e8210, setter)
void sdk_f_2e8210(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 5) = a1; }

// sub_2e8220  (orig 0x2e8220, setter)
void sdk_f_2e8220(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 6) = a1; }

// sub_2e8230  (orig 0x2e8230, setter)
void sdk_f_2e8230(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 7) = a1; }

// sub_2e9d50  (orig 0x2e9d50, pair-ret)
struct pair16_f_2e9d50_ { uint64_t f[2]; }; pair16_f_2e9d50_ sdk_f_2e9d50(void* a0) { return *(struct pair16_f_2e9d50_ *)((char*)(a0) + 48); }

// sub_2ea080  (orig 0x2ea080, ret_only)
void sdk_f_2ea080() {}

// sub_2ea8c0  (orig 0x2ea8c0, call)
extern void callee_521910();
uint32_t sdk_f_2ea8c0() {
    uint32_t r0 = ((((uint32_t (*)(void))&callee_521910)() == 1) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_2ea930  (orig 0x2ea930, ret_only)
void sdk_f_2ea930() {}

// sub_2eabd0  (orig 0x2eabd0, mov_ret)
uint32_t sdk_f_2eabd0() { return 1; }

// sub_2ead00  (orig 0x2ead00, ret_only)
void sdk_f_2ead00() {}

// sub_2ee2b0  (orig 0x2ee2b0, call)
extern void callee_521c50();
uint32_t sdk_f_2ee2b0() {
    uint32_t r0 = ((((uint32_t (*)(void))&callee_521c50)() == 0) ? 1 : 0);
    asm volatile("");
    return r0;
}

// sub_2f2e00  (orig 0x2f2e00, setter)
void sdk_f_2f2e00(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_2f3300  (orig 0x2f3300, ret_only)
void sdk_f_2f3300() {}

// sub_2f3310  (orig 0x2f3310, setter)
void sdk_f_2f3310(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_2f38e0  (orig 0x2f38e0, setter)
void sdk_f_2f38e0(void* a0) { *(uint8_t*)((char*)(a0)) = 0; }

// sub_2f38f0  (orig 0x2f38f0, ret_only)
void sdk_f_2f38f0() {}

// sub_2f3af0  (orig 0x2f3af0, getter)
uint8_t sdk_f_2f3af0(void* a0) { return *(uint8_t*)((char*)(a0)); }

// sub_2f4280  (orig 0x2f4280, ret_only)
void sdk_f_2f4280() {}

// sub_2f4ca0  (orig 0x2f4ca0, ptr_add)
void* sdk_f_2f4ca0(void* a0) { return (char*)a0 + 32; }

// sub_2f4d60  (orig 0x2f4d60, ptr_add)
void* sdk_f_2f4d60(void* a0) { return (char*)a0 + 8; }

// sub_2f4d70  (orig 0x2f4d70, straight)
void* sdk_f_2f4d70(void* a0) { return (char*)(a0) - 24; }

// sub_2f4ea0  (orig 0x2f4ea0, ptr_add)
void* sdk_f_2f4ea0(void* a0) { return (char*)a0 + 32; }

// sub_2f4ee0  (orig 0x2f4ee0, call)
extern void callee_5114b0();
uint64_t sdk_f_2f4ee0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f4f00  (orig 0x2f4f00, call)
extern void callee_522030();
uint64_t sdk_f_2f4f00(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522030)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f4f30  (orig 0x2f4f30, call)
extern void callee_522040();
uint64_t sdk_f_2f4f30(void* a0, uint64_t a1, void* a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522040)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) * (92))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f4f70  (orig 0x2f4f70, call)
extern void callee_522040();
uint64_t sdk_f_2f4f70(void* a0, uint64_t a1, void* a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522040)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) * (88))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f4fb0  (orig 0x2f4fb0, call)
extern void callee_522050();
uint64_t sdk_f_2f4fb0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f4fe0  (orig 0x2f4fe0, call)
extern void callee_522060();
uint64_t sdk_f_2f4fe0(void* a0, uint64_t a1, uint32_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522060)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5010  (orig 0x2f5010, call)
extern void callee_522070();
uint64_t sdk_f_2f5010(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522070)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5040  (orig 0x2f5040, call)
extern void callee_522040();
uint64_t sdk_f_2f5040(void* a0, uint64_t a1, void* a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522040)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 3))) << (3))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5080  (orig 0x2f5080, call)
extern void callee_522040();
uint64_t sdk_f_2f5080(void* a0, uint64_t a1, void* a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522040)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 4))) << (2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f50c0  (orig 0x2f50c0, call)
extern void callee_522080();
uint64_t sdk_f_2f50c0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522080)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f50f0  (orig 0x2f50f0, call)
extern void callee_522090();
uint64_t sdk_f_2f50f0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522090)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5120  (orig 0x2f5120, call)
extern void callee_5220a0();
uint64_t sdk_f_2f5120(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5220a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5150  (orig 0x2f5150, call)
extern void callee_5220b0();
uint64_t sdk_f_2f5150(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5220b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5170  (orig 0x2f5170, call)
extern void callee_51b310();
uint64_t sdk_f_2f5170(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b310)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5190  (orig 0x2f5190, call)
extern void callee_511510();
uint64_t sdk_f_2f5190(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f51b0  (orig 0x2f51b0, call)
extern void callee_511510();
uint64_t sdk_f_2f51b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f51d0  (orig 0x2f51d0, call)
extern void callee_511510();
uint64_t sdk_f_2f51d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f51f0  (orig 0x2f51f0, call)
extern void callee_51b140();
uint64_t sdk_f_2f51f0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5220  (orig 0x2f5220, call)
extern void callee_512180();
uint64_t sdk_f_2f5220(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5250  (orig 0x2f5250, call)
extern void callee_5114b0();
uint64_t sdk_f_2f5250(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5270  (orig 0x2f5270, call)
extern void callee_5220c0();
uint64_t sdk_f_2f5270(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5220c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5290  (orig 0x2f5290, call)
extern void callee_511780();
uint64_t sdk_f_2f5290(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f52c0  (orig 0x2f52c0, call)
extern void callee_5220d0();
uint64_t sdk_f_2f52c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5220d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f52e0  (orig 0x2f52e0, call)
extern void callee_5220e0();
uint64_t sdk_f_2f52e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5220e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5300  (orig 0x2f5300, call)
extern void callee_5220f0();
uint64_t sdk_f_2f5300(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5220f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f5320  (orig 0x2f5320, ptr_add)
void* sdk_f_2f5320(void* a0) { return (char*)a0 + 8; }

// sub_2f5330  (orig 0x2f5330, straight)
void* sdk_f_2f5330(void* a0) { return (char*)(a0) - 24; }

// sub_2f6c90  (orig 0x2f6c90, ptr_add)
void* sdk_f_2f6c90(void* a0) { return (char*)a0 + 16; }

// sub_2f6cd0  (orig 0x2f6cd0, call)
extern void callee_512700();
uint64_t sdk_f_2f6cd0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6cf0  (orig 0x2f6cf0, call)
extern void callee_5126e0();
uint64_t sdk_f_2f6cf0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6d10  (orig 0x2f6d10, call)
extern void callee_512710();
uint64_t sdk_f_2f6d10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6d30  (orig 0x2f6d30, call)
extern void callee_512710();
uint64_t sdk_f_2f6d30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6d50  (orig 0x2f6d50, call)
extern void callee_522130();
uint64_t sdk_f_2f6d50(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522130)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6e00  (orig 0x2f6e00, call)
extern void callee_516f00();
uint64_t sdk_f_2f6e00(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_516f00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (4))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6e30  (orig 0x2f6e30, call)
extern void callee_512700();
uint64_t sdk_f_2f6e30(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6e50  (orig 0x2f6e50, call)
extern void callee_512700();
uint64_t sdk_f_2f6e50(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6e70  (orig 0x2f6e70, call)
extern void callee_516f00();
uint64_t sdk_f_2f6e70(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_516f00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(102)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6ea0  (orig 0x2f6ea0, call)
extern void callee_51dff0();
uint64_t sdk_f_2f6ea0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51dff0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(103)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6ed0  (orig 0x2f6ed0, call)
extern void callee_522120();
uint64_t sdk_f_2f6ed0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522120)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(104)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f6f00  (orig 0x2f6f00, ptr_add)
void* sdk_f_2f6f00(void* a0) { return (char*)a0 + 8; }

// sub_2f6f10  (orig 0x2f6f10, straight)
void* sdk_f_2f6f10(void* a0) { return (char*)(a0) - 8; }

// sub_2f7a80  (orig 0x2f7a80, getter)
uint32_t sdk_f_2f7a80(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_2f7a90  (orig 0x2f7a90, ptr_add)
void* sdk_f_2f7a90(void* a0) { return (char*)a0 + 140; }

// sub_2f7bf0  (orig 0x2f7bf0, ptr_add)
void* sdk_f_2f7bf0(void* a0) { return (char*)a0 + 12; }

// sub_2f7c40  (orig 0x2f7c40, getter)
uint32_t sdk_f_2f7c40(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_2f7c50  (orig 0x2f7c50, getter)
uint32_t sdk_f_2f7c50(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_2f7c60  (orig 0x2f7c60, getter)
uint32_t sdk_f_2f7c60(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_2f7c70  (orig 0x2f7c70, getter)
uint32_t sdk_f_2f7c70(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_2f7c80  (orig 0x2f7c80, setter)
void sdk_f_2f7c80(void* a0) { *(uint8_t*)((char*)(a0)) = 0; }

// sub_2f7c90  (orig 0x2f7c90, ret_only)
void sdk_f_2f7c90() {}

// sub_2f7da0  (orig 0x2f7da0, getter)
uint8_t sdk_f_2f7da0(void* a0) { return *(uint8_t*)((char*)(a0)); }

// sub_2f7db0  (orig 0x2f7db0, getter)
uint32_t sdk_f_2f7db0(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_2f7dc0  (orig 0x2f7dc0, straight-line)
uint32_t sdk_f_2f7dc0(void* a0) { return ((*(uint32_t*)((char*)(a0) + 12) == 2770581391) ? 1 : 0); }

// sub_2f7de0  (orig 0x2f7de0, ptr_add)
void* sdk_f_2f7de0(void* a0) { return (char*)a0 + 144; }

// sub_2f7e00  (orig 0x2f7e00, ptr_add)
void* sdk_f_2f7e00(void* a0) { return (char*)a0 + 16; }

// sub_2f7e10  (orig 0x2f7e10, straight)
void sdk_f_2f7e10(void* a0) {
    *(uint32_t*)((char*)(a0) + 260) = 1;
}

// sub_2f7e20  (orig 0x2f7e20, setter)
void sdk_f_2f7e20(void* a0) { *(uint32_t*)((char*)(a0) + 260) = 0; }

// sub_2f7e30  (orig 0x2f7e30, setter-chain)
void sdk_f_2f7e30(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 260) = 0; *(uint32_t*)((char*)(a0) + 264) = a1; }

// sub_2f7e40  (orig 0x2f7e40, setter-chain)
void sdk_f_2f7e40(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 260) = 0; *(uint32_t*)((char*)(a0) + 264) = a1; }

// sub_2f7e50  (orig 0x2f7e50, setter-chain)
void sdk_f_2f7e50(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 260) = 0; *(uint32_t*)((char*)(a0) + 264) = a1; }

// sub_2f7e60  (orig 0x2f7e60, call)
extern void callee_5221b0();
uint64_t sdk_f_2f7e60() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_5221b0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8630  (orig 0x2f8630, ptr_add)
void* sdk_f_2f8630(void* a0) { return (char*)a0 + 32; }

// sub_2f86d0  (orig 0x2f86d0, ptr_add)
void* sdk_f_2f86d0(void* a0) { return (char*)a0 + 8; }

// sub_2f86e0  (orig 0x2f86e0, straight)
void* sdk_f_2f86e0(void* a0) { return (char*)(a0) - 24; }

// sub_2f8820  (orig 0x2f8820, ptr_add)
void* sdk_f_2f8820(void* a0) { return (char*)a0 + 32; }

// sub_2f8860  (orig 0x2f8860, call)
extern void callee_511510();
uint64_t sdk_f_2f8860(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8880  (orig 0x2f8880, call)
extern void callee_511390();
uint64_t sdk_f_2f8880(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f88a0  (orig 0x2f88a0, call)
extern void callee_5114b0();
uint64_t sdk_f_2f88a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f88c0  (orig 0x2f88c0, call)
extern void callee_512050();
uint64_t sdk_f_2f88c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f88f0  (orig 0x2f88f0, call)
extern void callee_522200();
uint64_t sdk_f_2f88f0(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522200)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (5))), ((uintptr_t)(400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8920  (orig 0x2f8920, call)
extern void callee_511510();
uint64_t sdk_f_2f8920(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(401)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8940  (orig 0x2f8940, call)
extern void callee_511390();
uint64_t sdk_f_2f8940(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(402)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8960  (orig 0x2f8960, call)
extern void callee_5114b0();
uint64_t sdk_f_2f8960(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(403)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f89b0  (orig 0x2f89b0, call)
extern void callee_522220();
uint64_t sdk_f_2f89b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(405)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f89d0  (orig 0x2f89d0, call)
extern void callee_522220();
uint64_t sdk_f_2f89d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(406)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f89f0  (orig 0x2f89f0, call)
extern void callee_511570();
uint64_t sdk_f_2f89f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(407)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8a10  (orig 0x2f8a10, call)
extern void callee_522230();
uint64_t sdk_f_2f8a10(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522230)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(408)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8a40  (orig 0x2f8a40, call)
extern void callee_5122f0();
uint64_t sdk_f_2f8a40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(409)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8a90  (orig 0x2f8a90, call)
extern void callee_522250();
uint64_t sdk_f_2f8a90(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(411)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8ab0  (orig 0x2f8ab0, call)
extern void callee_522250();
uint64_t sdk_f_2f8ab0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(412)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8ad0  (orig 0x2f8ad0, call)
extern void callee_512050();
uint64_t sdk_f_2f8ad0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8b00  (orig 0x2f8b00, call)
extern void callee_522260();
uint64_t sdk_f_2f8b00(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522260)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(510)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8b30  (orig 0x2f8b30, call)
extern void callee_522270();
uint64_t sdk_f_2f8b30(void* a0, void* a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(((*(uint64_t*)((char*)(a1) + 8)) + (((*(uint64_t*)((char*)(a1) + 8)) << 1))) << (3))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(((*(uint64_t*)((char*)(a3) + 8)) + (((*(uint64_t*)((char*)(a3) + 8)) << 1))) << (3))), ((uintptr_t)(1000)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8b80  (orig 0x2f8b80, call)
extern void callee_522280();
uint64_t sdk_f_2f8b80(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 2))) << (3))), ((uintptr_t)(1001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8c00  (orig 0x2f8c00, call)
extern void callee_5122f0();
uint64_t sdk_f_2f8c00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8c20  (orig 0x2f8c20, call)
extern void callee_5122f0();
uint64_t sdk_f_2f8c20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1302)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2f8c40  (orig 0x2f8c40, ptr_add)
void* sdk_f_2f8c40(void* a0) { return (char*)a0 + 8; }

// sub_2f8c50  (orig 0x2f8c50, straight)
void* sdk_f_2f8c50(void* a0) { return (char*)(a0) - 24; }

// sub_2f9e10  (orig 0x2f9e10, ret_only)
void sdk_f_2f9e10() {}

// sub_2fa320  (orig 0x2fa320, ptr_add)
void* sdk_f_2fa320(void* a0) { return (char*)a0 + 32; }

// sub_2fa3c0  (orig 0x2fa3c0, ptr_add)
void* sdk_f_2fa3c0(void* a0) { return (char*)a0 + 8; }

// sub_2fa3d0  (orig 0x2fa3d0, straight)
void* sdk_f_2fa3d0(void* a0) { return (char*)(a0) - 24; }

// sub_2fa510  (orig 0x2fa510, ptr_add)
void* sdk_f_2fa510(void* a0) { return (char*)a0 + 32; }

// sub_2fa550  (orig 0x2fa550, call)
extern void callee_511510();
uint64_t sdk_f_2fa550(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa570  (orig 0x2fa570, call)
extern void callee_511390();
uint64_t sdk_f_2fa570(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa590  (orig 0x2fa590, call)
extern void callee_5114b0();
uint64_t sdk_f_2fa590(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa5b0  (orig 0x2fa5b0, call)
extern void callee_522200();
uint64_t sdk_f_2fa5b0(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522200)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (5))), ((uintptr_t)(400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa5e0  (orig 0x2fa5e0, call)
extern void callee_511510();
uint64_t sdk_f_2fa5e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(401)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa600  (orig 0x2fa600, call)
extern void callee_511390();
uint64_t sdk_f_2fa600(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(402)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa620  (orig 0x2fa620, call)
extern void callee_5114b0();
uint64_t sdk_f_2fa620(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(403)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa670  (orig 0x2fa670, call)
extern void callee_522220();
uint64_t sdk_f_2fa670(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(405)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa690  (orig 0x2fa690, call)
extern void callee_522220();
uint64_t sdk_f_2fa690(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(406)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa6b0  (orig 0x2fa6b0, call)
extern void callee_511570();
uint64_t sdk_f_2fa6b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(407)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa6d0  (orig 0x2fa6d0, call)
extern void callee_522230();
uint64_t sdk_f_2fa6d0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522230)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(408)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa700  (orig 0x2fa700, call)
extern void callee_5122f0();
uint64_t sdk_f_2fa700(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(409)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa750  (orig 0x2fa750, call)
extern void callee_522250();
uint64_t sdk_f_2fa750(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(411)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa770  (orig 0x2fa770, call)
extern void callee_522250();
uint64_t sdk_f_2fa770(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(412)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa790  (orig 0x2fa790, call)
extern void callee_522270();
uint64_t sdk_f_2fa790(void* a0, void* a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(((*(uint64_t*)((char*)(a1) + 8)) + (((*(uint64_t*)((char*)(a1) + 8)) << 1))) << (3))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(((*(uint64_t*)((char*)(a3) + 8)) + (((*(uint64_t*)((char*)(a3) + 8)) << 1))) << (3))), ((uintptr_t)(1000)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa7e0  (orig 0x2fa7e0, call)
extern void callee_522280();
uint64_t sdk_f_2fa7e0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 2))) << (3))), ((uintptr_t)(1001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa860  (orig 0x2fa860, call)
extern void callee_5122f0();
uint64_t sdk_f_2fa860(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1301)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa880  (orig 0x2fa880, call)
extern void callee_5122f0();
uint64_t sdk_f_2fa880(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1302)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fa8a0  (orig 0x2fa8a0, ptr_add)
void* sdk_f_2fa8a0(void* a0) { return (char*)a0 + 8; }

// sub_2fa8b0  (orig 0x2fa8b0, straight)
void* sdk_f_2fa8b0(void* a0) { return (char*)(a0) - 24; }

// sub_2fa8c0  (orig 0x2fa8c0, ret_only)
void sdk_f_2fa8c0() {}

// sub_2fbe50  (orig 0x2fbe50, ptr_add)
void* sdk_f_2fbe50(void* a0) { return (char*)a0 + 32; }

// sub_2fbef0  (orig 0x2fbef0, ptr_add)
void* sdk_f_2fbef0(void* a0) { return (char*)a0 + 8; }

// sub_2fbf00  (orig 0x2fbf00, straight)
void* sdk_f_2fbf00(void* a0) { return (char*)(a0) - 24; }

// sub_2fc040  (orig 0x2fc040, ptr_add)
void* sdk_f_2fc040(void* a0) { return (char*)a0 + 32; }

// sub_2fc080  (orig 0x2fc080, call)
extern void callee_511510();
uint64_t sdk_f_2fc080(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc0d0  (orig 0x2fc0d0, call)
extern void callee_5122f0();
uint64_t sdk_f_2fc0d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc0f0  (orig 0x2fc0f0, call)
extern void callee_5122f0();
uint64_t sdk_f_2fc0f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc110  (orig 0x2fc110, call)
extern void callee_522370();
uint64_t sdk_f_2fc110(void* a0, uint64_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc140  (orig 0x2fc140, call)
extern void callee_5122f0();
uint64_t sdk_f_2fc140(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc160  (orig 0x2fc160, call)
extern void callee_522230();
uint64_t sdk_f_2fc160(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522230)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc1c0  (orig 0x2fc1c0, call)
extern void callee_522280();
uint64_t sdk_f_2fc1c0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc1f0  (orig 0x2fc1f0, call)
extern void callee_5122f0();
uint64_t sdk_f_2fc1f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc210  (orig 0x2fc210, call)
extern void callee_5122f0();
uint64_t sdk_f_2fc210(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc230  (orig 0x2fc230, call)
extern void callee_522390();
uint64_t sdk_f_2fc230(void* a0, uint64_t a1, uint32_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc320  (orig 0x2fc320, call)
extern void callee_522250();
uint64_t sdk_f_2fc320(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc340  (orig 0x2fc340, call)
extern void callee_522250();
uint64_t sdk_f_2fc340(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc360  (orig 0x2fc360, call)
extern void callee_511390();
uint64_t sdk_f_2fc360(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc380  (orig 0x2fc380, call)
extern void callee_522220();
uint64_t sdk_f_2fc380(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc3a0  (orig 0x2fc3a0, call)
extern void callee_522220();
uint64_t sdk_f_2fc3a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc3c0  (orig 0x2fc3c0, call)
extern void callee_522220();
uint64_t sdk_f_2fc3c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc3e0  (orig 0x2fc3e0, call)
extern void callee_511570();
uint64_t sdk_f_2fc3e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc400  (orig 0x2fc400, call)
extern void callee_522390();
uint64_t sdk_f_2fc400(void* a0, uint64_t a1, uint32_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc430  (orig 0x2fc430, call)
extern void callee_5122f0();
uint64_t sdk_f_2fc430(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc4b0  (orig 0x2fc4b0, call)
extern void callee_5223c0();
uint64_t sdk_f_2fc4b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5223c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(256)), ((uintptr_t)(103)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc4e0  (orig 0x2fc4e0, call)
extern void callee_5122f0();
uint64_t sdk_f_2fc4e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(104)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc500  (orig 0x2fc500, call)
extern void callee_5122f0();
uint64_t sdk_f_2fc500(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(105)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc520  (orig 0x2fc520, call)
extern void callee_5223d0();
uint64_t sdk_f_2fc520(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5223d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(106)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc570  (orig 0x2fc570, call)
extern void callee_5223f0();
uint64_t sdk_f_2fc570(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5223f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(664)), ((uintptr_t)(201)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc5a0  (orig 0x2fc5a0, call)
extern void callee_5122f0();
uint64_t sdk_f_2fc5a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(202)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc5c0  (orig 0x2fc5c0, call)
extern void callee_522230();
uint64_t sdk_f_2fc5c0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522230)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(203)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc620  (orig 0x2fc620, call)
extern void callee_51b140();
uint64_t sdk_f_2fc620(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_51b140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(205)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc650  (orig 0x2fc650, call)
extern void callee_522410();
uint64_t sdk_f_2fc650(void* a0, uint64_t a1, void* a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522410)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(206)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fc680  (orig 0x2fc680, ptr_add)
void* sdk_f_2fc680(void* a0) { return (char*)a0 + 8; }

// sub_2fc690  (orig 0x2fc690, straight)
void* sdk_f_2fc690(void* a0) { return (char*)(a0) - 24; }

// sub_2fdbe0  (orig 0x2fdbe0, ret_only)
void sdk_f_2fdbe0() {}

// sub_2fe0d0  (orig 0x2fe0d0, ptr_add)
void* sdk_f_2fe0d0(void* a0) { return (char*)a0 + 32; }

// sub_2fe170  (orig 0x2fe170, ptr_add)
void* sdk_f_2fe170(void* a0) { return (char*)a0 + 8; }

// sub_2fe180  (orig 0x2fe180, straight)
void* sdk_f_2fe180(void* a0) { return (char*)(a0) - 24; }

// sub_2fe2c0  (orig 0x2fe2c0, ptr_add)
void* sdk_f_2fe2c0(void* a0) { return (char*)a0 + 32; }

// sub_2fe300  (orig 0x2fe300, call)
extern void callee_511510();
uint64_t sdk_f_2fe300(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe350  (orig 0x2fe350, call)
extern void callee_5122f0();
uint64_t sdk_f_2fe350(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe370  (orig 0x2fe370, call)
extern void callee_5122f0();
uint64_t sdk_f_2fe370(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe390  (orig 0x2fe390, call)
extern void callee_522370();
uint64_t sdk_f_2fe390(void* a0, uint64_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe3c0  (orig 0x2fe3c0, call)
extern void callee_5122f0();
uint64_t sdk_f_2fe3c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe3e0  (orig 0x2fe3e0, call)
extern void callee_5122f0();
uint64_t sdk_f_2fe3e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe400  (orig 0x2fe400, call)
extern void callee_5122f0();
uint64_t sdk_f_2fe400(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe4e0  (orig 0x2fe4e0, call)
extern void callee_522250();
uint64_t sdk_f_2fe4e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe500  (orig 0x2fe500, call)
extern void callee_522250();
uint64_t sdk_f_2fe500(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe520  (orig 0x2fe520, call)
extern void callee_511390();
uint64_t sdk_f_2fe520(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe540  (orig 0x2fe540, call)
extern void callee_522220();
uint64_t sdk_f_2fe540(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe560  (orig 0x2fe560, call)
extern void callee_522220();
uint64_t sdk_f_2fe560(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe580  (orig 0x2fe580, call)
extern void callee_511570();
uint64_t sdk_f_2fe580(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe5a0  (orig 0x2fe5a0, call)
extern void callee_5122f0();
uint64_t sdk_f_2fe5a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe620  (orig 0x2fe620, call)
extern void callee_5223c0();
uint64_t sdk_f_2fe620(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5223c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(256)), ((uintptr_t)(103)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe650  (orig 0x2fe650, call)
extern void callee_5122f0();
uint64_t sdk_f_2fe650(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(104)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe670  (orig 0x2fe670, call)
extern void callee_5122f0();
uint64_t sdk_f_2fe670(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(105)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe690  (orig 0x2fe690, call)
extern void callee_5223d0();
uint64_t sdk_f_2fe690(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5223d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(106)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fe6b0  (orig 0x2fe6b0, ptr_add)
void* sdk_f_2fe6b0(void* a0) { return (char*)a0 + 8; }

// sub_2fe6c0  (orig 0x2fe6c0, straight)
void* sdk_f_2fe6c0(void* a0) { return (char*)(a0) - 24; }

// sub_2fe6d0  (orig 0x2fe6d0, ret_only)
void sdk_f_2fe6d0() {}

// sub_2febe0  (orig 0x2febe0, ptr_add)
void* sdk_f_2febe0(void* a0) { return (char*)a0 + 32; }

// sub_2fec80  (orig 0x2fec80, ptr_add)
void* sdk_f_2fec80(void* a0) { return (char*)a0 + 8; }

// sub_2fec90  (orig 0x2fec90, straight)
void* sdk_f_2fec90(void* a0) { return (char*)(a0) - 24; }

// sub_2fedd0  (orig 0x2fedd0, ptr_add)
void* sdk_f_2fedd0(void* a0) { return (char*)a0 + 32; }

// sub_2fee10  (orig 0x2fee10, call)
extern void callee_511510();
uint64_t sdk_f_2fee10(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fee60  (orig 0x2fee60, call)
extern void callee_5122f0();
uint64_t sdk_f_2fee60(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fee80  (orig 0x2fee80, call)
extern void callee_5122f0();
uint64_t sdk_f_2fee80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2feea0  (orig 0x2feea0, call)
extern void callee_522370();
uint64_t sdk_f_2feea0(void* a0, uint64_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2feed0  (orig 0x2feed0, call)
extern void callee_5122f0();
uint64_t sdk_f_2feed0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2feef0  (orig 0x2feef0, call)
extern void callee_522230();
uint64_t sdk_f_2feef0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522230)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fef50  (orig 0x2fef50, call)
extern void callee_522280();
uint64_t sdk_f_2fef50(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fef80  (orig 0x2fef80, call)
extern void callee_5122f0();
uint64_t sdk_f_2fef80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fefa0  (orig 0x2fefa0, call)
extern void callee_5122f0();
uint64_t sdk_f_2fefa0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2fefc0  (orig 0x2fefc0, call)
extern void callee_522390();
uint64_t sdk_f_2fefc0(void* a0, uint64_t a1, uint32_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ff0b0  (orig 0x2ff0b0, call)
extern void callee_522250();
uint64_t sdk_f_2ff0b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ff0d0  (orig 0x2ff0d0, call)
extern void callee_522250();
uint64_t sdk_f_2ff0d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ff0f0  (orig 0x2ff0f0, call)
extern void callee_511390();
uint64_t sdk_f_2ff0f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ff110  (orig 0x2ff110, call)
extern void callee_522220();
uint64_t sdk_f_2ff110(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ff130  (orig 0x2ff130, call)
extern void callee_522220();
uint64_t sdk_f_2ff130(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ff150  (orig 0x2ff150, call)
extern void callee_522220();
uint64_t sdk_f_2ff150(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522220)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ff170  (orig 0x2ff170, call)
extern void callee_511570();
uint64_t sdk_f_2ff170(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ff190  (orig 0x2ff190, call)
extern void callee_522390();
uint64_t sdk_f_2ff190(void* a0, uint64_t a1, uint32_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_2ff1c0  (orig 0x2ff1c0, ptr_add)
void* sdk_f_2ff1c0(void* a0) { return (char*)a0 + 8; }

// sub_2ff1d0  (orig 0x2ff1d0, straight)
void* sdk_f_2ff1d0(void* a0) { return (char*)(a0) - 24; }

// sub_2ff1e0  (orig 0x2ff1e0, ret_only)
void sdk_f_2ff1e0() {}

// sub_2ff390  (orig 0x2ff390, strlit-ret)
const char *sdk_f_2ff390() { static char g_f_2ff390[1]; __asm__ volatile("" ::: "memory"); return g_f_2ff390; }

// sub_301500  (orig 0x301500, call)
extern void callee_522550();
uint64_t sdk_f_301500(uint64_t a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_522550)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3022a0  (orig 0x3022a0, setter-chain)
void sdk_f_3022a0(void* a0) { *(uint32_t*)((char*)(a0) + 12) = 0; *(uint64_t*)((char*)(a0) + 32) = 0; *(uint32_t*)((char*)(a0) + 40) = 0; }

// sub_302580  (orig 0x302580, call)
extern void callee_522580();
uint64_t sdk_f_302580(uint64_t a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522580)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3025a0  (orig 0x3025a0, setter)
void sdk_f_3025a0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 12) = a1; }

// sub_3025b0  (orig 0x3025b0, setter)
void sdk_f_3025b0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 40) = a1; }

// sub_304c40  (orig 0x304c40, call)
extern void sub_305580();
uint32_t sdk_f_304c40(uint64_t a0, uint64_t a1, uint64_t unused2, void* a3) {
    uint64_t f_304c40__r0 = ((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&sub_305580)(((uintptr_t)(a3)), ((uintptr_t)((((uint64_t)a0)) - (*(uint64_t*)((char*)(a3) + 8)))), ((uintptr_t)((((uint64_t)a1)) - (*(uint64_t*)((char*)(a3) + 8)))));
    uint32_t r0 = 1;
    asm volatile("");
    return r0;
}

// sub_305730  (orig 0x305730, straight)
uint32_t sdk_f_305730(uint64_t unused0, uint64_t unused1, uint64_t unused2, void* a3) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a3)) = (uint8_t)k0;
    return 0;
}

// sub_306980  (orig 0x306980, setter-chain)
void sdk_f_306980(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint32_t*)((char*)(a0) + 4) = 0; }

// sub_306990  (orig 0x306990, ret_only)
void sdk_f_306990() {}

// sub_30a080  (orig 0x30a080, compare)
bool sdk_f_30a080(void* a0, void* a1) { return (uint64_t)(*(uint64_t*)((char*)(a0))) < (uint64_t)(*(uint64_t*)((char*)(a1))); }

// sub_30a0a0  (orig 0x30a0a0, compare)
bool sdk_f_30a0a0(void* a0, void* a1) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 8)) < (uint64_t)(*(uint64_t*)((char*)(a1) + 8)); }

// sub_30cce0  (orig 0x30cce0, straight)
uint64_t sdk_f_30cce0(uint64_t unused0, void* a1) {
    *(uint64_t*)((char*)(a1)) = -1;
    return 0;
}

// sub_30cef0  (orig 0x30cef0, mov_ret)
uint64_t sdk_f_30cef0(uint64_t a0, uint64_t a1, uint64_t a2) { return a2; }

// sub_30cf00  (orig 0x30cf00, mov_ret)
uint64_t sdk_f_30cf00(uint64_t a0, uint64_t a1) { return a1; }

// sub_30d350  (orig 0x30d350, straight)
uint64_t sdk_f_30d350(uint64_t unused0, void* a1) {
    *(uint64_t*)((char*)(a1)) = -1;
    return 0;
}

// sub_30d510  (orig 0x30d510, mov_ret)
uint32_t sdk_f_30d510() { return 1; }

// sub_30d530  (orig 0x30d530, ret_only)
void sdk_f_30d530() {}

// sub_30d550  (orig 0x30d550, mov_ret)
uint32_t sdk_f_30d550() { return 1; }

// sub_30d570  (orig 0x30d570, ret_only)
void sdk_f_30d570() {}

// sub_30d590  (orig 0x30d590, mov_ret)
uint32_t sdk_f_30d590() { return 1; }

// sub_30d8f0  (orig 0x30d8f0, straight)
uint32_t sdk_f_30d8f0(void* a0) { return ((((*(uint32_t*)((char*)(a0))) + (31)) >> (3)) & (536870908)) + (28); }

// sub_312d00  (orig 0x312d00, ptr_add)
void* sdk_f_312d00(void* a0) { return (char*)a0 + 8; }

// sub_3133d0  (orig 0x3133d0, ptr_add)
void* sdk_f_3133d0(void* a0) { return (char*)a0 + 56; }

// sub_313990  (orig 0x313990, ret_only)
void sdk_f_313990() {}

// sub_313c30  (orig 0x313c30, ptr_add)
void* sdk_f_313c30(void* a0) { return (char*)a0 + 8; }

// sub_313cb0  (orig 0x313cb0, ret_only)
void sdk_f_313cb0() {}

// sub_313cc0  (orig 0x313cc0, ret_only)
void sdk_f_313cc0() {}

// sub_313cd0  (orig 0x313cd0, ret_only)
void sdk_f_313cd0() {}

// sub_314660  (orig 0x314660, ptr_add)
void* sdk_f_314660(void* a0) { return (char*)a0 + 32; }

// sub_3147c0  (orig 0x3147c0, ptr_add)
void* sdk_f_3147c0(void* a0) { return (char*)a0 + 8; }

// sub_3147d0  (orig 0x3147d0, straight)
void* sdk_f_3147d0(void* a0) { return (char*)(a0) - 24; }

// sub_314900  (orig 0x314900, ptr_add)
void* sdk_f_314900(void* a0) { return (char*)a0 + 32; }

// sub_314910  (orig 0x314910, call)
extern void callee_522fd0();
uint64_t sdk_f_314910(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_522fd0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314a90  (orig 0x314a90, call)
extern void callee_523000();
uint64_t sdk_f_314a90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_523000)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(380)), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314ac0  (orig 0x314ac0, call)
extern void callee_523010();
uint64_t sdk_f_314ac0(void* a0, void* a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_523010)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (3))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314b00  (orig 0x314b00, call)
extern void callee_523020();
uint64_t sdk_f_314b00(void* a0, void* a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_523020)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) * (117))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (255))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314b70  (orig 0x314b70, call)
extern void callee_523040();
uint64_t sdk_f_314b70(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_523040)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(380)), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314ba0  (orig 0x314ba0, call)
extern void callee_51b310();
uint64_t sdk_f_314ba0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b310)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314c00  (orig 0x314c00, call)
extern void callee_512250();
uint64_t sdk_f_314c00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314c20  (orig 0x314c20, call)
extern void callee_523050();
uint64_t sdk_f_314c20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_523050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(52)), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314d00  (orig 0x314d00, call)
extern void callee_523080();
uint64_t sdk_f_314d00(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_523080)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314d20  (orig 0x314d20, call)
extern void callee_512050();
uint64_t sdk_f_314d20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314d50  (orig 0x314d50, call)
extern void callee_5114b0();
uint64_t sdk_f_314d50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314d70  (orig 0x314d70, call)
extern void callee_523090();
uint64_t sdk_f_314d70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_523090)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314d90  (orig 0x314d90, call)
extern void callee_512050();
uint64_t sdk_f_314d90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314dc0  (orig 0x314dc0, call)
extern void callee_5114b0();
uint64_t sdk_f_314dc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314e20  (orig 0x314e20, call)
extern void callee_5114b0();
uint64_t sdk_f_314e20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314e40  (orig 0x314e40, call)
extern void callee_511510();
uint64_t sdk_f_314e40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314e60  (orig 0x314e60, call)
extern void callee_511510();
uint64_t sdk_f_314e60(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314e80  (orig 0x314e80, call)
extern void callee_5123e0();
uint64_t sdk_f_314e80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5123e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314ee0  (orig 0x314ee0, call)
extern void callee_5230c0();
uint64_t sdk_f_314ee0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5230c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(194)), ((uintptr_t)(27)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314f10  (orig 0x314f10, call)
extern void callee_5230d0();
uint64_t sdk_f_314f10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5230d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(194)), ((uintptr_t)(28)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314f40  (orig 0x314f40, call)
extern void callee_512050();
uint64_t sdk_f_314f40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(29)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314f70  (orig 0x314f70, call)
extern void callee_512050();
uint64_t sdk_f_314f70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314fa0  (orig 0x314fa0, call)
extern void callee_511570();
uint64_t sdk_f_314fa0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(31)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314fc0  (orig 0x314fc0, call)
extern void callee_5230e0();
uint64_t sdk_f_314fc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5230e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1568)), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_314ff0  (orig 0x314ff0, call)
extern void callee_511510();
uint64_t sdk_f_314ff0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(33)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315010  (orig 0x315010, call)
extern void callee_512050();
uint64_t sdk_f_315010(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(34)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315080  (orig 0x315080, call)
extern void callee_523050();
uint64_t sdk_f_315080(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_523050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(52)), ((uintptr_t)(36)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3150b0  (orig 0x3150b0, call)
extern void callee_511510();
uint64_t sdk_f_3150b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(37)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315100  (orig 0x315100, ptr_add)
void* sdk_f_315100(void* a0) { return (char*)a0 + 8; }

// sub_315110  (orig 0x315110, straight)
void* sdk_f_315110(void* a0) { return (char*)(a0) - 24; }

// sub_315430  (orig 0x315430, ptr_add)
void* sdk_f_315430(void* a0) { return (char*)a0 + 32; }

// sub_315460  (orig 0x315460, call)
extern void callee_5114b0();
uint64_t sdk_f_315460(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315480  (orig 0x315480, call)
extern void callee_511510();
uint64_t sdk_f_315480(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3154a0  (orig 0x3154a0, call)
extern void callee_511570();
uint64_t sdk_f_3154a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3154c0  (orig 0x3154c0, call)
extern void callee_5117a0();
uint64_t sdk_f_3154c0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5117a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3154f0  (orig 0x3154f0, ptr_add)
void* sdk_f_3154f0(void* a0) { return (char*)a0 + 8; }

// sub_315500  (orig 0x315500, straight)
void* sdk_f_315500(void* a0) { return (char*)(a0) - 24; }

// sub_315630  (orig 0x315630, ptr_add)
void* sdk_f_315630(void* a0) { return (char*)a0 + 32; }

// sub_315660  (orig 0x315660, call)
extern void callee_511510();
uint64_t sdk_f_315660(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315680  (orig 0x315680, call)
extern void callee_5230f0();
uint64_t sdk_f_315680(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5230f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3156a0  (orig 0x3156a0, call)
extern void callee_511510();
uint64_t sdk_f_3156a0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3156c0  (orig 0x3156c0, call)
extern void callee_511510();
uint64_t sdk_f_3156c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3156e0  (orig 0x3156e0, call)
extern void callee_523100();
uint64_t sdk_f_3156e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_523100)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315700  (orig 0x315700, call)
extern void callee_511780();
uint64_t sdk_f_315700(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315730  (orig 0x315730, call)
extern void callee_512050();
uint64_t sdk_f_315730(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315760  (orig 0x315760, call)
extern void callee_51b310();
uint64_t sdk_f_315760(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_51b310)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315780  (orig 0x315780, call)
extern void callee_512050();
uint64_t sdk_f_315780(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3157b0  (orig 0x3157b0, call)
extern void callee_512050();
uint64_t sdk_f_3157b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3157e0  (orig 0x3157e0, call)
extern void callee_512050();
uint64_t sdk_f_3157e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315810  (orig 0x315810, call)
extern void callee_512050();
uint64_t sdk_f_315810(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315840  (orig 0x315840, call)
extern void callee_523110();
uint64_t sdk_f_315840(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_523110)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315870  (orig 0x315870, call)
extern void callee_512050();
uint64_t sdk_f_315870(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3158a0  (orig 0x3158a0, call)
extern void callee_512050();
uint64_t sdk_f_3158a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3158d0  (orig 0x3158d0, call)
extern void callee_512050();
uint64_t sdk_f_3158d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315900  (orig 0x315900, call)
extern void callee_511780();
uint64_t sdk_f_315900(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315930  (orig 0x315930, call)
extern void callee_523120();
uint64_t sdk_f_315930(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_523120)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315950  (orig 0x315950, call)
extern void callee_511390();
uint64_t sdk_f_315950(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3159d0  (orig 0x3159d0, call)
extern void callee_512050();
uint64_t sdk_f_3159d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315a00  (orig 0x315a00, call)
extern void callee_511780();
uint64_t sdk_f_315a00(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315a30  (orig 0x315a30, call)
extern void callee_511780();
uint64_t sdk_f_315a30(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_315a60  (orig 0x315a60, ptr_add)
void* sdk_f_315a60(void* a0) { return (char*)a0 + 8; }

// sub_315a70  (orig 0x315a70, straight)
void* sdk_f_315a70(void* a0) { return (char*)(a0) - 24; }

// sub_317480  (orig 0x317480, ptr_add)
void* sdk_f_317480(void* a0) { return (char*)a0 + 32; }

// sub_3174c0  (orig 0x3174c0, call)
extern void callee_523150();
uint64_t sdk_f_3174c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_523150)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3174e0  (orig 0x3174e0, call)
extern void callee_5123e0();
uint64_t sdk_f_3174e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5123e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_317500  (orig 0x317500, ptr_add)
void* sdk_f_317500(void* a0) { return (char*)a0 + 8; }

// sub_317510  (orig 0x317510, straight)
void* sdk_f_317510(void* a0) { return (char*)(a0) - 24; }

// sub_3185f0  (orig 0x3185f0, call)
extern void sub_318610();
uint64_t sdk_f_3185f0() {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&sub_318610)(((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_318760  (orig 0x318760, call)
extern void sub_318610();
uint64_t sdk_f_318760() {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&sub_318610)(((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_318780  (orig 0x318780, call)
extern void sub_318610();
uint64_t sdk_f_318780() {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&sub_318610)(((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3187a0  (orig 0x3187a0, call)
extern void sub_3187c0();
uint64_t sdk_f_3187a0() {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&sub_3187c0)(((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_318890  (orig 0x318890, call)
extern void sub_3187c0();
uint64_t sdk_f_318890() {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&sub_3187c0)(((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3188b0  (orig 0x3188b0, call)
extern void sub_3187c0();
uint64_t sdk_f_3188b0() {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&sub_3187c0)(((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3188d0  (orig 0x3188d0, ret_only)
void sdk_f_3188d0() {}

// sub_319e30  (orig 0x319e30, call)
extern void callee_523350();
uint64_t sdk_f_319e30() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_523350)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_319fb0  (orig 0x319fb0, call)
extern void callee_523370();
uint64_t sdk_f_319fb0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_523370)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_319fd0  (orig 0x319fd0, call)
extern void callee_523380();
uint64_t sdk_f_319fd0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_523380)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_319ff0  (orig 0x319ff0, call)
extern void callee_523390();
uint64_t sdk_f_319ff0() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_523390)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a010  (orig 0x31a010, call)
extern void callee_5233a0();
uint64_t sdk_f_31a010() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_5233a0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a030  (orig 0x31a030, call)
extern void callee_5233b0();
uint64_t sdk_f_31a030(uint64_t a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5233b0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a050  (orig 0x31a050, call)
extern void callee_5233c0();
uint64_t sdk_f_31a050(uint64_t a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_5233c0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)((((uint32_t)a1)) & (1))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a070  (orig 0x31a070, call)
extern void callee_5233d0();
uint64_t sdk_f_31a070() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_5233d0)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a090  (orig 0x31a090, call)
extern void callee_5233e0();
uint64_t sdk_f_31a090(uint64_t a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_5233e0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)((((uint32_t)a1)) & (1))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a0b0  (orig 0x31a0b0, call)
extern void callee_5233f0();
uint64_t sdk_f_31a0b0(uint64_t a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_5233f0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)((((uint32_t)a1)) & (1))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a0d0  (orig 0x31a0d0, call)
extern void callee_523400();
uint64_t sdk_f_31a0d0(uint64_t a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_523400)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)((((uint32_t)a1)) & (1))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a0f0  (orig 0x31a0f0, call)
extern void callee_523410();
uint64_t sdk_f_31a0f0(uint64_t a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_523410)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)((((uint32_t)a1)) & (1))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a110  (orig 0x31a110, call)
extern void callee_523420();
uint64_t sdk_f_31a110(uint64_t a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_523420)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)((((uint32_t)a1)) & (1))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a130  (orig 0x31a130, call)
extern void callee_523430();
uint64_t sdk_f_31a130(uint64_t a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_523430)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)((((uint32_t)a1)) & (1))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a150  (orig 0x31a150, call)
extern void callee_523440();
uint64_t sdk_f_31a150() {
    uint64_t r0 = (((uint64_t (*)(void))&callee_523440)()) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_31a1c0  (orig 0x31a1c0, ret_only)
void sdk_f_31a1c0() {}

// sub_31a320  (orig 0x31a320, call)
extern void callee_523470();
uint64_t sdk_f_31a320(uint64_t a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_523470)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

