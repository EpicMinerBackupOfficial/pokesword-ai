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

/* Self-contained preamble: a bare-metal aarch64-none-elf target has no
 * <stdint.h> under -nostdinc++, and a decomp translation unit should not depend
 * on a hosted C library anyway. */
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
/* A 32-byte aggregate of two NEON vectors. `stp q0, q0, [x0]` is ONE register
 * stored twice, so the C has to be a two-field struct -- a 16-byte store emits
 * `str q0, [x0]` instead. Measured, clang 5.0.1 -O3. */
struct Q2 { uint64x2_t a, b; };


// sub_1b0  (orig 0x1b0, mov_ret)
uint32_t sdk_f_1b0() { return 0; }

// sub_1c0  (orig 0x1c0, mov_ret)
uint32_t sdk_f_1c0() { return 0; }

// sub_1d0  (orig 0x1d0, mov_ret)
uint32_t sdk_f_1d0() { return 0; }

// sub_230  (orig 0x230, ret_only)
void sdk_f_230() {}

// sub_280  (orig 0x280, straight-line)
typedef struct { unsigned char b[24]; } __S_f_280;
__S_f_280 sdk_f_280() {
    __S_f_280 r;
    *(uint64_t *)((char *)&r + 0) = 0;
    return r;
}

// sub_290  (orig 0x290, mov_ret)
uint64_t sdk_f_290() { return 0; }

// sub_2a0  (orig 0x2a0, mov_ret)
uint64_t sdk_f_2a0() { return 0; }

// sub_2b0  (orig 0x2b0, mov_ret)
uint32_t sdk_f_2b0() { return 0; }

// sub_330  (orig 0x330, mov_ret)
uint32_t sdk_f_330() { return 1; }

// sub_340  (orig 0x340, mov_ret)
uint32_t sdk_f_340() { return 0; }

// sub_4a0  (orig 0x4a0, mov_ret)
uint32_t sdk_f_4a0() { return -38; }

// sub_4b0  (orig 0x4b0, mov_ret)
uint32_t sdk_f_4b0() { return -38; }

// sub_4c0  (orig 0x4c0, mov_ret)
uint32_t sdk_f_4c0() { return 0; }

// sub_680  (orig 0x680, ret_only)
void sdk_f_680() {}

// sub_a40  (orig 0xa40, straight)
uint32_t sdk_f_a40(uint64_t unused0, uint64_t unused1, void* a2, void* a3) {
    uint32_t k0 = 0;
    *(uint32_t*)((char*)(a2)) = 0;
    *(uint8_t*)((char*)(a3)) = (uint8_t)k0;
    return -38;
}

// sub_1470  (orig 0x1470, compare)
bool sdk_f_1470(void* a0) { return (uint32_t)(*(uint32_t*)((char*)(a0) + 48)) != (uint64_t)(0); }

// sub_16e0  (orig 0x16e0, mov_ret)
uint32_t sdk_f_16e0() { return -38; }

// sub_18a0  (orig 0x18a0, ret_only)
void sdk_f_18a0() {}

// sub_1c30  (orig 0x1c30, ptr_add)
void* sdk_f_1c30(void* a0) { return (char*)a0 + 136; }

// sub_1c40  (orig 0x1c40, ptr_add)
void* sdk_f_1c40(void* a0) { return (char*)a0 + 128; }

// sub_1cd0  (orig 0x1cd0, ret_only)
void sdk_f_1cd0() {}

// sub_1ce0  (orig 0x1ce0, ret_only)
void sdk_f_1ce0() {}

// sub_1f80  (orig 0x1f80, ret_only)
void sdk_f_1f80() {}

// sub_4240  (orig 0x4240, getter)
uint64_t sdk_f_4240(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_42b0  (orig 0x42b0, ptr_add)
void* sdk_f_42b0(void* a0) { return (char*)a0 + 8; }

// sub_4480  (orig 0x4480, getter)
uint64_t sdk_f_4480(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_44f0  (orig 0x44f0, ptr_add)
void* sdk_f_44f0(void* a0) { return (char*)a0 + 8; }

// sub_5190  (orig 0x5190, getter)
uint64_t sdk_f_5190(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_55c0  (orig 0x55c0, mov_ret)
uint32_t sdk_f_55c0() { return -38; }

// sub_55d0  (orig 0x55d0, mov_ret)
uint32_t sdk_f_55d0() { return -38; }

// sub_55e0  (orig 0x55e0, mov_ret)
uint32_t sdk_f_55e0() { return -38; }

// sub_5ee0  (orig 0x5ee0, getter)
uint64_t sdk_f_5ee0(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_5ef0  (orig 0x5ef0, ptr_add)
void* sdk_f_5ef0(void* a0) { return (char*)a0 + 16; }

// sub_6da0  (orig 0x6da0, getter)
uint32_t sdk_f_6da0(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_6dd0  (orig 0x6dd0, getter)
uint64_t sdk_f_6dd0(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_6e00  (orig 0x6e00, getter)
uint64_t sdk_f_6e00(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_6e30  (orig 0x6e30, getter)
uint32_t sdk_f_6e30(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_6e60  (orig 0x6e60, getter)
uint32_t sdk_f_6e60(void* a0) { return *(uint32_t*)((char*)(a0) + 52); }

// sub_7970  (orig 0x7970, getter)
uint64_t sdk_f_7970(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_79c0  (orig 0x79c0, getter)
uint64_t sdk_f_79c0(void* a0) { return *(uint64_t*)((char*)(a0) + 32); }

// sub_79d0  (orig 0x79d0, getter)
uint64_t sdk_f_79d0(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_7d40  (orig 0x7d40, setter-chain)
void sdk_f_7d40(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 32) = a1; *(uint64_t*)((char*)(a0) + 64) = 0; }

// sub_8260  (orig 0x8260, straight)
void sdk_f_8260(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0) + 74) = (uint8_t)((((uint32_t)a1)) & (1));
}

// sub_8700  (orig 0x8700, getter)
uint64_t sdk_f_8700(void* a0) { return *(uint64_t*)((char*)(a0) + 40); }

// sub_8770  (orig 0x8770, getter)
uint64_t sdk_f_8770(void* a0) { return *(uint64_t*)((char*)(a0) + 48); }

// sub_8780  (orig 0x8780, getter)
uint32_t sdk_f_8780(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_8790  (orig 0x8790, setter)
void sdk_f_8790(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0)) = a1; }

// sub_b210  (orig 0xb210, getter)
uint64_t sdk_f_b210(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_b240  (orig 0xb240, getter)
uint64_t sdk_f_b240(void* a0) { return *(uint64_t*)((char*)(a0) + 40); }

// sub_b250  (orig 0xb250, getter)
uint64_t sdk_f_b250(void* a0) { return *(uint64_t*)((char*)(a0) + 48); }

// sub_b570  (orig 0xb570, setter-chain)
void sdk_f_b570(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint64_t*)((char*)(a0) + 16) = 0; }

// sub_b600  (orig 0xb600, setter-chain)
void sdk_f_b600(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint64_t*)((char*)(a0) + 16) = 0; }

// sub_bb90  (orig 0xbb90, ret_only)
void sdk_f_bb90() {}

// sub_c900  (orig 0xc900, ret_only)
void sdk_f_c900() {}

// sub_c910  (orig 0xc910, ret_only)
void sdk_f_c910() {}

// sub_cb30  (orig 0xcb30, mov_ret)
uint32_t sdk_f_cb30() { return -1; }

// sub_cb40  (orig 0xcb40, mov_ret)
uint64_t sdk_f_cb40() { return -1; }

// sub_cb50  (orig 0xcb50, mov_ret)
uint32_t sdk_f_cb50() { return -1; }

// sub_cb60  (orig 0xcb60, mov_ret)
uint32_t sdk_f_cb60() { return -1; }

// sub_cb70  (orig 0xcb70, mov_ret)
uint32_t sdk_f_cb70() { return 4096; }

// sub_d440  (orig 0xd440, mov_ret)
uint32_t sdk_f_d440() { return -38; }

// sub_d450  (orig 0xd450, mov_ret)
uint32_t sdk_f_d450() { return -38; }

// sub_d460  (orig 0xd460, mov_ret)
uint32_t sdk_f_d460() { return -38; }

// sub_d470  (orig 0xd470, mov_ret)
uint32_t sdk_f_d470() { return -38; }

// sub_d4c0  (orig 0xd4c0, mov_ret)
uint64_t sdk_f_d4c0() { return 0; }

// sub_dd10  (orig 0xdd10, ret_only)
void sdk_f_dd10() {}

// sub_e540  (orig 0xe540, mov_ret)
uint32_t sdk_f_e540() { return -38; }

// sub_e780  (orig 0xe780, ptr_add)
void* sdk_f_e780(void* a0) { return (char*)a0 + 16; }

// sub_e790  (orig 0xe790, mov_ret)
uint64_t sdk_f_e790() { return 0; }

// sub_ea20  (orig 0xea20, ptr_add)
void* sdk_f_ea20(void* a0) { return (char*)a0 + 8; }

// sub_ea30  (orig 0xea30, straight)
void* sdk_f_ea30(void* a0) { return (char*)(a0) - 8; }

// sub_fe00  (orig 0xfe00, mov_ret)
uint32_t sdk_f_fe00() { return -1; }

// sub_fe10  (orig 0xfe10, mov_ret)
uint32_t sdk_f_fe10() { return -1; }

// sub_ffe0  (orig 0xffe0, straight-line)
uint32_t sdk_f_ffe0(void* a0) { return (((*(uint32_t*)((char*)(a0)) == 12)) ? (0) : (-22)); }

// sub_10000  (orig 0x10000, mov_ret)
uint32_t sdk_f_10000() { return -1; }

// sub_10090  (orig 0x10090, mov_ret)
uint32_t sdk_f_10090() { return 0; }

// sub_101a0  (orig 0x101a0, mov_ret)
uint32_t sdk_f_101a0() { return 64; }

// sub_10fc0  (orig 0x10fc0, ptr_add)
void* sdk_f_10fc0(void* a0) { return (char*)a0 + 8; }

// sub_111f0  (orig 0x111f0, getter)
uint64_t sdk_f_111f0(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_12ab0  (orig 0x12ab0, ret_only)
void sdk_f_12ab0() {}

// sub_12bc0  (orig 0x12bc0, ptr_add)
void* sdk_f_12bc0(void* a0) { return (char*)a0 + 16; }

// sub_12bf0  (orig 0x12bf0, ptr_add)
void* sdk_f_12bf0(void* a0) { return (char*)a0 + 8; }

// sub_12d90  (orig 0x12d90, getter)
uint64_t sdk_f_12d90(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_12dc0  (orig 0x12dc0, getter)
uint64_t sdk_f_12dc0(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_13450  (orig 0x13450, mov_ret)
uint32_t sdk_f_13450() { return 52; }

// sub_1ab70  (orig 0x1ab70, ptr_add)
void* sdk_f_1ab70(void* a0) { return (char*)a0 + 8; }

// sub_1ae00  (orig 0x1ae00, ret_only)
void sdk_f_1ae00() {}

// sub_1ae10  (orig 0x1ae10, ret_only)
void sdk_f_1ae10() {}

// sub_1beb0  (orig 0x1beb0, ret_only)
void sdk_f_1beb0() {}

// sub_1cae0  (orig 0x1cae0, ptr_add)
void* sdk_f_1cae0(void* a0) { return (char*)a0 + 8; }

// sub_1d100  (orig 0x1d100, getter)
uint64_t sdk_f_1d100(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_1e520  (orig 0x1e520, getter)
uint64_t sdk_f_1e520(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_1f770  (orig 0x1f770, call)
extern void callee_510140();
uint64_t sdk_f_1f770(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 8));
    uint64_t f_1f770__r0 = ((uint64_t (*)(uintptr_t))&callee_510140)(((uintptr_t)(*(uint64_t*)((char*)(p0) + 48))));
    uint64_t r0 = (f_1f770__r0) + (48);
    asm volatile("");
    return r0;
}

// sub_1fc10  (orig 0x1fc10, getter)
uint64_t sdk_f_1fc10(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_1fc40  (orig 0x1fc40, getter)
uint64_t sdk_f_1fc40(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_210d0  (orig 0x210d0, ptr_add)
void* sdk_f_210d0(void* a0) { return (char*)a0 + 8; }

// sub_21300  (orig 0x21300, getter)
uint64_t sdk_f_21300(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_21540  (orig 0x21540, straight-line)
typedef struct { unsigned char b[24]; } __S_f_21540;
__S_f_21540 sdk_f_21540() {
    __S_f_21540 r;
    *(uint64_t *)((char *)&r + 0) = 0;
    return r;
}

// sub_22ca0  (orig 0x22ca0, ret_only)
void sdk_f_22ca0() {}

// sub_22cb0  (orig 0x22cb0, ret_only)
void sdk_f_22cb0() {}

// sub_23700  (orig 0x23700, ret_only)
void sdk_f_23700() {}

// sub_23710  (orig 0x23710, ret_only)
void sdk_f_23710() {}

// sub_24540  (orig 0x24540, ptr_add)
void* sdk_f_24540(void* a0) { return (char*)a0 + 8; }

// sub_24770  (orig 0x24770, getter)
uint64_t sdk_f_24770(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_26da0  (orig 0x26da0, straight)
uint32_t sdk_f_26da0(void* a0, void* a1) {
    *(uint64_t*)((char*)(a1)) = *(uint64_t*)((char*)(a0) + 3888);
    return 0;
}

// sub_2a750  (orig 0x2a750, getter)
uint32_t sdk_f_2a750(void* a0) { return *(uint32_t*)((char*)(a0) + 48); }

// sub_2d7e0  (orig 0x2d7e0, mov_ret)
uint64_t sdk_f_2d7e0() { return 0; }

// sub_2d7f0  (orig 0x2d7f0, ret_only)
void sdk_f_2d7f0() {}

// sub_2d800  (orig 0x2d800, mov_ret)
uint64_t sdk_f_2d800() { return 0; }

// sub_2ddb0  (orig 0x2ddb0, getter)
uint64_t sdk_f_2ddb0(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_2ddc0  (orig 0x2ddc0, getter)
uint64_t sdk_f_2ddc0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_2e070  (orig 0x2e070, mov_ret)
uint32_t sdk_f_2e070() { return 36; }

// sub_2e080  (orig 0x2e080, mov_ret)
uint64_t sdk_f_2e080() { return 0; }

// sub_2e3b0  (orig 0x2e3b0, mov_ret)
uint32_t sdk_f_2e3b0() { return 0; }

// sub_2e3c0  (orig 0x2e3c0, straight-line)
uint64_t sdk_f_2e3c0(void* a0) { return (8) + ((*(uint64_t*)((char*)(a0) + 24)) * (24)); }

// sub_2ec90  (orig 0x2ec90, getter)
uint32_t sdk_f_2ec90(void* a0) { return *(uint32_t*)((char*)(a0) + 200); }

// sub_2fa60  (orig 0x2fa60, ret_only)
void sdk_f_2fa60() {}

// sub_2fa70  (orig 0x2fa70, ret_only)
void sdk_f_2fa70() {}

// sub_30160  (orig 0x30160, getter-chain)
uint16_t sdk_f_30160(void* a0) { return *(uint16_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 4); }

// sub_309e0  (orig 0x309e0, getter)
uint64_t sdk_f_309e0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_30c40  (orig 0x30c40, compare)
bool sdk_f_30c40(void* a0, void* a1) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 8)) == (uint64_t)(*(uint64_t*)((char*)(a1) + 8)); }

// sub_32390  (orig 0x32390, ret_only)
void sdk_f_32390() {}

// sub_32b00  (orig 0x32b00, straight)
uint64_t sdk_f_32b00(void* a0) { return (*(uint64_t*)((char*)(a0) + 16)) << (4); }

// sub_33050  (orig 0x33050, ret_only)
void sdk_f_33050() {}

// sub_33060  (orig 0x33060, ret_only)
void sdk_f_33060() {}

// sub_33150  (orig 0x33150, ret_only)
void sdk_f_33150() {}

// sub_334f0  (orig 0x334f0, getter-chain)
uint32_t sdk_f_334f0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 8)))); }

// sub_33500  (orig 0x33500, getter)
uint64_t sdk_f_33500(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_33700  (orig 0x33700, getter)
uint32_t sdk_f_33700(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_33710  (orig 0x33710, ret_only)
void sdk_f_33710() {}

// sub_33720  (orig 0x33720, ret_only)
void sdk_f_33720() {}

// sub_33760  (orig 0x33760, getter)
uint64_t sdk_f_33760(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_338d0  (orig 0x338d0, ret_only)
void sdk_f_338d0() {}

// sub_338e0  (orig 0x338e0, ret_only)
void sdk_f_338e0() {}

// sub_338f0  (orig 0x338f0, straight)
uint32_t sdk_f_338f0(uint64_t unused0, uint32_t a1) { return (((uint32_t)a1)) & (1); }

// sub_33900  (orig 0x33900, ret_only)
void sdk_f_33900() {}

// sub_33910  (orig 0x33910, ret_only)
void sdk_f_33910() {}

// sub_33920  (orig 0x33920, ret_only)
void sdk_f_33920() {}

// sub_33930  (orig 0x33930, ret_only)
void sdk_f_33930() {}

// sub_36f70  (orig 0x36f70, ret_only)
void sdk_f_36f70() {}

// sub_36fc0  (orig 0x36fc0, mov_ret)
uint32_t sdk_f_36fc0() { return -1; }

// sub_36fd0  (orig 0x36fd0, mov_ret)
uint64_t sdk_f_36fd0() { return -1; }

// sub_36fe0  (orig 0x36fe0, ret_only)
void sdk_f_36fe0() {}

// sub_37530  (orig 0x37530, mov_ret)
uint32_t sdk_f_37530() { return 0; }

// sub_38030  (orig 0x38030, call)
extern void sub_37f20();
uint64_t sdk_f_38030(uint64_t a0, uint64_t a1, uint64_t a2) {
    uint64_t f_38030__r0 = ((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&sub_37f20)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))));
    void* p0 = (void*)((uintptr_t)(f_38030__r0));
    *(uint16_t*)((char*)(p0)) = 0;
    uint64_t r0 = f_38030__r0;
    asm volatile("");
    return r0;
}

// sub_39640  (orig 0x39640, getter)
uint64_t sdk_f_39640(void* a0) { return *(uint64_t*)((char*)(a0) + 40); }

// sub_396f0  (orig 0x396f0, delegator)
extern void callee_510a70();
void sdk_f_396f0(unsigned long a0) { ((void(*)(unsigned long))callee_510a70)(a0); asm volatile(""); }

// sub_3a960  (orig 0x3a960, getter)
uint64_t sdk_f_3a960(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_3e0e0  (orig 0x3e0e0, ptr_add)
void* sdk_f_3e0e0(void* a0) { return (char*)a0 + 32; }

// sub_3e110  (orig 0x3e110, call)
extern void callee_5113a0();
uint64_t sdk_f_3e110(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e130  (orig 0x3e130, call)
extern void callee_5113b0();
uint64_t sdk_f_3e130(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (4))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e160  (orig 0x3e160, call)
extern void callee_5113b0();
uint64_t sdk_f_3e160(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (4))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e190  (orig 0x3e190, call)
extern void callee_5113c0();
uint64_t sdk_f_3e190(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e250  (orig 0x3e250, call)
extern void callee_5113f0();
uint64_t sdk_f_3e250(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e270  (orig 0x3e270, call)
extern void callee_511400();
uint64_t sdk_f_3e270(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511400)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e290  (orig 0x3e290, call)
extern void callee_511410();
uint64_t sdk_f_3e290(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511410)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e350  (orig 0x3e350, call)
extern void callee_511440();
uint64_t sdk_f_3e350(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e530  (orig 0x3e530, call)
extern void callee_511470();
uint64_t sdk_f_3e530(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511470)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e560  (orig 0x3e560, call)
extern void callee_511480();
uint64_t sdk_f_3e560(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e6d0  (orig 0x3e6d0, call)
extern void callee_5113b0();
uint64_t sdk_f_3e6d0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (4))), ((uintptr_t)(131)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e700  (orig 0x3e700, call)
extern void callee_511440();
uint64_t sdk_f_3e700(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(140)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e720  (orig 0x3e720, call)
extern void callee_5113b0();
uint64_t sdk_f_3e720(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (4))), ((uintptr_t)(141)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e750  (orig 0x3e750, call)
extern void callee_5114b0();
uint64_t sdk_f_3e750(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(150)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3e770  (orig 0x3e770, ptr_add)
void* sdk_f_3e770(void* a0) { return (char*)a0 + 8; }

// sub_3e780  (orig 0x3e780, straight)
void* sdk_f_3e780(void* a0) { return (char*)(a0) - 24; }

// sub_3ef40  (orig 0x3ef40, ptr_add)
void* sdk_f_3ef40(void* a0) { return (char*)a0 + 32; }

// sub_3ef80  (orig 0x3ef80, call)
extern void callee_5114f0();
uint64_t sdk_f_3ef80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3efa0  (orig 0x3efa0, call)
extern void callee_511390();
uint64_t sdk_f_3efa0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3efc0  (orig 0x3efc0, call)
extern void callee_511500();
uint64_t sdk_f_3efc0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3eff0  (orig 0x3eff0, ptr_add)
void* sdk_f_3eff0(void* a0) { return (char*)a0 + 8; }

// sub_3f000  (orig 0x3f000, straight)
void* sdk_f_3f000(void* a0) { return (char*)(a0) - 24; }

// sub_3fb20  (orig 0x3fb20, ptr_add)
void* sdk_f_3fb20(void* a0) { return (char*)a0 + 32; }

// sub_3fb30  (orig 0x3fb30, call)
extern void callee_511510();
uint64_t sdk_f_3fb30(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(999)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3fb50  (orig 0x3fb50, ptr_add)
void* sdk_f_3fb50(void* a0) { return (char*)a0 + 8; }

// sub_3fb60  (orig 0x3fb60, straight)
void* sdk_f_3fb60(void* a0) { return (char*)(a0) - 24; }

// sub_3fcb0  (orig 0x3fcb0, ptr_add)
void* sdk_f_3fcb0(void* a0) { return (char*)a0 + 32; }

// sub_3fce0  (orig 0x3fce0, call)
extern void callee_511520();
uint64_t sdk_f_3fce0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3fd90  (orig 0x3fd90, call)
extern void callee_511500();
uint64_t sdk_f_3fd90(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3fdc0  (orig 0x3fdc0, call)
extern void callee_511530();
uint64_t sdk_f_3fdc0(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511530)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(104)), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(130)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3feb0  (orig 0x3feb0, call)
extern void callee_511510();
uint64_t sdk_f_3feb0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(160)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_3ff60  (orig 0x3ff60, ptr_add)
void* sdk_f_3ff60(void* a0) { return (char*)a0 + 8; }

// sub_3ff70  (orig 0x3ff70, straight)
void* sdk_f_3ff70(void* a0) { return (char*)(a0) - 24; }

// sub_400c0  (orig 0x400c0, ptr_add)
void* sdk_f_400c0(void* a0) { return (char*)a0 + 32; }

// sub_400f0  (orig 0x400f0, call)
extern void callee_511510();
uint64_t sdk_f_400f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_40110  (orig 0x40110, call)
extern void callee_5114b0();
uint64_t sdk_f_40110(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_40130  (orig 0x40130, call)
extern void callee_511510();
uint64_t sdk_f_40130(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_40150  (orig 0x40150, ptr_add)
void* sdk_f_40150(void* a0) { return (char*)a0 + 8; }

// sub_40160  (orig 0x40160, straight)
void* sdk_f_40160(void* a0) { return (char*)(a0) - 24; }

// sub_40780  (orig 0x40780, ptr_add)
void* sdk_f_40780(void* a0) { return (char*)a0 + 32; }

// sub_40840  (orig 0x40840, call)
extern void callee_5114b0();
uint64_t sdk_f_40840(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_40860  (orig 0x40860, call)
extern void callee_511500();
uint64_t sdk_f_40860(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_40890  (orig 0x40890, call)
extern void callee_511500();
uint64_t sdk_f_40890(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_408c0  (orig 0x408c0, call)
extern void callee_511590();
uint64_t sdk_f_408c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511590)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(128)), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_408f0  (orig 0x408f0, ptr_add)
void* sdk_f_408f0(void* a0) { return (char*)a0 + 8; }

// sub_40900  (orig 0x40900, straight)
void* sdk_f_40900(void* a0) { return (char*)(a0) - 24; }

// sub_40d90  (orig 0x40d90, ptr_add)
void* sdk_f_40d90(void* a0) { return (char*)a0 + 32; }

// sub_40dc0  (orig 0x40dc0, call)
extern void callee_511510();
uint64_t sdk_f_40dc0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_40de0  (orig 0x40de0, call)
extern void callee_5114b0();
uint64_t sdk_f_40de0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_40e00  (orig 0x40e00, call)
extern void callee_511510();
uint64_t sdk_f_40e00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_40e20  (orig 0x40e20, call)
extern void callee_511390();
uint64_t sdk_f_40e20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_40e40  (orig 0x40e40, ptr_add)
void* sdk_f_40e40(void* a0) { return (char*)a0 + 8; }

// sub_40e50  (orig 0x40e50, straight)
void* sdk_f_40e50(void* a0) { return (char*)(a0) - 24; }

// sub_413d0  (orig 0x413d0, ptr_add)
void* sdk_f_413d0(void* a0) { return (char*)a0 + 32; }

// sub_41400  (orig 0x41400, call)
extern void callee_511520();
uint64_t sdk_f_41400(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41420  (orig 0x41420, call)
extern void callee_511520();
uint64_t sdk_f_41420(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41440  (orig 0x41440, call)
extern void callee_5113b0();
uint64_t sdk_f_41440(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41470  (orig 0x41470, call)
extern void callee_511500();
uint64_t sdk_f_41470(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_414a0  (orig 0x414a0, call)
extern void callee_511500();
uint64_t sdk_f_414a0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_414d0  (orig 0x414d0, ptr_add)
void* sdk_f_414d0(void* a0) { return (char*)a0 + 8; }

// sub_414e0  (orig 0x414e0, straight)
void* sdk_f_414e0(void* a0) { return (char*)(a0) - 24; }

// sub_41790  (orig 0x41790, ptr_add)
void* sdk_f_41790(void* a0) { return (char*)a0 + 32; }

// sub_417c0  (orig 0x417c0, call)
extern void callee_5113a0();
uint64_t sdk_f_417c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_417e0  (orig 0x417e0, call)
extern void callee_5113b0();
uint64_t sdk_f_417e0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (4))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41810  (orig 0x41810, call)
extern void callee_5113b0();
uint64_t sdk_f_41810(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (4))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41840  (orig 0x41840, call)
extern void callee_5113c0();
uint64_t sdk_f_41840(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41900  (orig 0x41900, call)
extern void callee_5113f0();
uint64_t sdk_f_41900(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41920  (orig 0x41920, call)
extern void callee_511400();
uint64_t sdk_f_41920(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511400)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41940  (orig 0x41940, call)
extern void callee_511410();
uint64_t sdk_f_41940(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511410)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41d90  (orig 0x41d90, call)
extern void callee_5115e0();
uint64_t sdk_f_41d90(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41dc0  (orig 0x41dc0, call)
extern void callee_5115f0();
uint64_t sdk_f_41dc0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41e10  (orig 0x41e10, call)
extern void callee_511610();
uint64_t sdk_f_41e10(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511610)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(113)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41f00  (orig 0x41f00, call)
extern void callee_511640();
uint64_t sdk_f_41f00(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511640)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(190)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41f20  (orig 0x41f20, call)
extern void callee_511510();
uint64_t sdk_f_41f20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(191)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41f40  (orig 0x41f40, call)
extern void callee_511480();
uint64_t sdk_f_41f40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(997)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41f60  (orig 0x41f60, call)
extern void callee_511480();
uint64_t sdk_f_41f60(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(998)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41f80  (orig 0x41f80, call)
extern void callee_511480();
uint64_t sdk_f_41f80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(999)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_41fa0  (orig 0x41fa0, ptr_add)
void* sdk_f_41fa0(void* a0) { return (char*)a0 + 8; }

// sub_41fb0  (orig 0x41fb0, straight)
void* sdk_f_41fb0(void* a0) { return (char*)(a0) - 24; }

// sub_42100  (orig 0x42100, ptr_add)
void* sdk_f_42100(void* a0) { return (char*)a0 + 32; }

// sub_42130  (orig 0x42130, ptr_add)
void* sdk_f_42130(void* a0) { return (char*)a0 + 8; }

// sub_42140  (orig 0x42140, straight)
void* sdk_f_42140(void* a0) { return (char*)(a0) - 24; }

// sub_42290  (orig 0x42290, ptr_add)
void* sdk_f_42290(void* a0) { return (char*)a0 + 32; }

// sub_422c0  (orig 0x422c0, call)
extern void callee_511520();
uint64_t sdk_f_422c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_42370  (orig 0x42370, call)
extern void callee_511500();
uint64_t sdk_f_42370(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_42460  (orig 0x42460, call)
extern void callee_511660();
uint64_t sdk_f_42460(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511660)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_42480  (orig 0x42480, call)
extern void callee_511670();
uint64_t sdk_f_42480(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_424a0  (orig 0x424a0, call)
extern void callee_511660();
uint64_t sdk_f_424a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511660)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(113)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_424c0  (orig 0x424c0, call)
extern void callee_511520();
uint64_t sdk_f_424c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_424e0  (orig 0x424e0, call)
extern void callee_511680();
uint64_t sdk_f_424e0(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511680)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(592)), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(130)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_42650  (orig 0x42650, call)
extern void callee_5116a0();
uint64_t sdk_f_42650(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5116a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(140)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_42880  (orig 0x42880, ptr_add)
void* sdk_f_42880(void* a0) { return (char*)a0 + 8; }

// sub_42890  (orig 0x42890, straight)
void* sdk_f_42890(void* a0) { return (char*)(a0) - 24; }

// sub_443c0  (orig 0x443c0, ptr_add)
void* sdk_f_443c0(void* a0) { return (char*)a0 + 32; }

// sub_443f0  (orig 0x443f0, call)
extern void callee_5113a0();
uint64_t sdk_f_443f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44410  (orig 0x44410, call)
extern void callee_5113b0();
uint64_t sdk_f_44410(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (4))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44440  (orig 0x44440, call)
extern void callee_5113b0();
uint64_t sdk_f_44440(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)((*(uint64_t*)((char*)(a1) + 8)) << (4))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44470  (orig 0x44470, call)
extern void callee_5113c0();
uint64_t sdk_f_44470(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44530  (orig 0x44530, call)
extern void callee_5113f0();
uint64_t sdk_f_44530(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44550  (orig 0x44550, call)
extern void callee_511400();
uint64_t sdk_f_44550(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511400)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44570  (orig 0x44570, call)
extern void callee_511410();
uint64_t sdk_f_44570(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511410)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_449c0  (orig 0x449c0, call)
extern void callee_5115e0();
uint64_t sdk_f_449c0(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_449f0  (orig 0x449f0, call)
extern void callee_5115f0();
uint64_t sdk_f_449f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5115f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44a40  (orig 0x44a40, call)
extern void callee_511610();
uint64_t sdk_f_44a40(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511610)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(113)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44b30  (orig 0x44b30, call)
extern void callee_511640();
uint64_t sdk_f_44b30(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511640)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(190)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44b50  (orig 0x44b50, call)
extern void callee_511510();
uint64_t sdk_f_44b50(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(191)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44b70  (orig 0x44b70, call)
extern void callee_511480();
uint64_t sdk_f_44b70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(997)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44b90  (orig 0x44b90, call)
extern void callee_511480();
uint64_t sdk_f_44b90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(998)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44bb0  (orig 0x44bb0, call)
extern void callee_511480();
uint64_t sdk_f_44bb0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(999)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44bd0  (orig 0x44bd0, call)
extern void callee_5113c0();
uint64_t sdk_f_44bd0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44bf0  (orig 0x44bf0, call)
extern void callee_511480();
uint64_t sdk_f_44bf0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(201)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44c10  (orig 0x44c10, call)
extern void callee_511480();
uint64_t sdk_f_44c10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(202)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44c30  (orig 0x44c30, call)
extern void callee_511480();
uint64_t sdk_f_44c30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(203)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44c50  (orig 0x44c50, call)
extern void callee_5116d0();
uint64_t sdk_f_44c50(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5116d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(204)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_44d20  (orig 0x44d20, call)
extern void callee_511480();
uint64_t sdk_f_44d20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(206)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_450f0  (orig 0x450f0, ptr_add)
void* sdk_f_450f0(void* a0) { return (char*)a0 + 8; }

// sub_45100  (orig 0x45100, straight)
void* sdk_f_45100(void* a0) { return (char*)(a0) - 24; }

// sub_453b0  (orig 0x453b0, ptr_add)
void* sdk_f_453b0(void* a0) { return (char*)a0 + 32; }

// sub_453f0  (orig 0x453f0, call)
extern void callee_5114f0();
uint64_t sdk_f_453f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45410  (orig 0x45410, call)
extern void callee_511390();
uint64_t sdk_f_45410(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45430  (orig 0x45430, call)
extern void callee_511500();
uint64_t sdk_f_45430(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45460  (orig 0x45460, call)
extern void callee_511730();
uint64_t sdk_f_45460(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511730)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(128)), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45490  (orig 0x45490, call)
extern void callee_511740();
uint64_t sdk_f_45490(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511740)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(128)), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_454c0  (orig 0x454c0, ptr_add)
void* sdk_f_454c0(void* a0) { return (char*)a0 + 8; }

// sub_454d0  (orig 0x454d0, straight)
void* sdk_f_454d0(void* a0) { return (char*)(a0) - 24; }

// sub_45a80  (orig 0x45a80, ptr_add)
void* sdk_f_45a80(void* a0) { return (char*)a0 + 32; }

// sub_45ab0  (orig 0x45ab0, call)
extern void callee_511520();
uint64_t sdk_f_45ab0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45ad0  (orig 0x45ad0, call)
extern void callee_511520();
uint64_t sdk_f_45ad0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45af0  (orig 0x45af0, call)
extern void callee_5113b0();
uint64_t sdk_f_45af0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45b20  (orig 0x45b20, call)
extern void callee_511500();
uint64_t sdk_f_45b20(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45b50  (orig 0x45b50, call)
extern void callee_511500();
uint64_t sdk_f_45b50(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45b80  (orig 0x45b80, call)
extern void callee_5113c0();
uint64_t sdk_f_45b80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45ba0  (orig 0x45ba0, call)
extern void callee_511480();
uint64_t sdk_f_45ba0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45db0  (orig 0x45db0, ptr_add)
void* sdk_f_45db0(void* a0) { return (char*)a0 + 8; }

// sub_45dc0  (orig 0x45dc0, straight)
void* sdk_f_45dc0(void* a0) { return (char*)(a0) - 24; }

// sub_45f10  (orig 0x45f10, ptr_add)
void* sdk_f_45f10(void* a0) { return (char*)a0 + 32; }

// sub_45f40  (orig 0x45f40, call)
extern void callee_511520();
uint64_t sdk_f_45f40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_45ff0  (orig 0x45ff0, call)
extern void callee_511500();
uint64_t sdk_f_45ff0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_460e0  (orig 0x460e0, call)
extern void callee_511660();
uint64_t sdk_f_460e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511660)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46100  (orig 0x46100, call)
extern void callee_511670();
uint64_t sdk_f_46100(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46120  (orig 0x46120, call)
extern void callee_511660();
uint64_t sdk_f_46120(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511660)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(113)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46140  (orig 0x46140, call)
extern void callee_511520();
uint64_t sdk_f_46140(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46160  (orig 0x46160, call)
extern void callee_511680();
uint64_t sdk_f_46160(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511680)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(592)), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(130)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_462d0  (orig 0x462d0, call)
extern void callee_5116a0();
uint64_t sdk_f_462d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5116a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(140)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46500  (orig 0x46500, call)
extern void callee_5114b0();
uint64_t sdk_f_46500(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46640  (orig 0x46640, call)
extern void callee_511510();
uint64_t sdk_f_46640(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(203)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46830  (orig 0x46830, call)
extern void callee_5114b0();
uint64_t sdk_f_46830(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(250)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46d10  (orig 0x46d10, call)
extern void callee_511770();
uint64_t sdk_f_46d10(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511770)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(400)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46e60  (orig 0x46e60, call)
extern void callee_511780();
uint64_t sdk_f_46e60(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(998)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_46e90  (orig 0x46e90, ptr_add)
void* sdk_f_46e90(void* a0) { return (char*)a0 + 8; }

// sub_46ea0  (orig 0x46ea0, straight)
void* sdk_f_46ea0(void* a0) { return (char*)(a0) - 24; }

// sub_46ff0  (orig 0x46ff0, ptr_add)
void* sdk_f_46ff0(void* a0) { return (char*)a0 + 32; }

// sub_470c0  (orig 0x470c0, call)
extern void callee_5117a0();
uint64_t sdk_f_470c0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5117a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_47190  (orig 0x47190, call)
extern void callee_511580();
uint64_t sdk_f_47190(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511580)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_471b0  (orig 0x471b0, call)
extern void callee_5117c0();
uint64_t sdk_f_471b0(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5117c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4096)), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(256)), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_471f0  (orig 0x471f0, call)
extern void callee_5114b0();
uint64_t sdk_f_471f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_47210  (orig 0x47210, ptr_add)
void* sdk_f_47210(void* a0) { return (char*)a0 + 8; }

// sub_47220  (orig 0x47220, straight)
void* sdk_f_47220(void* a0) { return (char*)(a0) - 24; }

// sub_47df0  (orig 0x47df0, ptr_add)
void* sdk_f_47df0(void* a0) { return (char*)a0 + 32; }

// sub_47ec0  (orig 0x47ec0, call)
extern void callee_5117a0();
uint64_t sdk_f_47ec0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5117a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_47f90  (orig 0x47f90, call)
extern void callee_511580();
uint64_t sdk_f_47f90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511580)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_47fb0  (orig 0x47fb0, ptr_add)
void* sdk_f_47fb0(void* a0) { return (char*)a0 + 8; }

// sub_47fc0  (orig 0x47fc0, straight)
void* sdk_f_47fc0(void* a0) { return (char*)(a0) - 24; }

// sub_48110  (orig 0x48110, ptr_add)
void* sdk_f_48110(void* a0) { return (char*)a0 + 32; }

// sub_481e0  (orig 0x481e0, call)
extern void callee_5117a0();
uint64_t sdk_f_481e0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5117a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_482b0  (orig 0x482b0, call)
extern void callee_511580();
uint64_t sdk_f_482b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511580)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_482d0  (orig 0x482d0, call)
extern void callee_511520();
uint64_t sdk_f_482d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_482f0  (orig 0x482f0, call)
extern void callee_511520();
uint64_t sdk_f_482f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_48310  (orig 0x48310, call)
extern void callee_5113b0();
uint64_t sdk_f_48310(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5113b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(102)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_48340  (orig 0x48340, call)
extern void callee_511500();
uint64_t sdk_f_48340(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(103)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_48370  (orig 0x48370, ptr_add)
void* sdk_f_48370(void* a0) { return (char*)a0 + 8; }

// sub_48380  (orig 0x48380, straight)
void* sdk_f_48380(void* a0) { return (char*)(a0) - 24; }

// sub_485b0  (orig 0x485b0, getter)
uint64_t sdk_f_485b0(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_487c0  (orig 0x487c0, compare)
bool sdk_f_487c0(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 24)) != (uint64_t)(0); }

// sub_492c0  (orig 0x492c0, ptr_add)
void* sdk_f_492c0(void* a0) { return (char*)a0 + 32; }

// sub_493b0  (orig 0x493b0, call)
extern void callee_511840();
uint64_t sdk_f_493b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511840)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_493d0  (orig 0x493d0, ptr_add)
void* sdk_f_493d0(void* a0) { return (char*)a0 + 8; }

// sub_493e0  (orig 0x493e0, straight)
void* sdk_f_493e0(void* a0) { return (char*)(a0) - 24; }

// sub_49510  (orig 0x49510, ptr_add)
void* sdk_f_49510(void* a0) { return (char*)a0 + 32; }

// sub_49540  (orig 0x49540, call)
extern void callee_511510();
uint64_t sdk_f_49540(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_49560  (orig 0x49560, call)
extern void callee_5114b0();
uint64_t sdk_f_49560(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_49580  (orig 0x49580, call)
extern void callee_511510();
uint64_t sdk_f_49580(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_495a0  (orig 0x495a0, ptr_add)
void* sdk_f_495a0(void* a0) { return (char*)a0 + 8; }

// sub_495b0  (orig 0x495b0, straight)
void* sdk_f_495b0(void* a0) { return (char*)(a0) - 24; }

// sub_499f0  (orig 0x499f0, ret_only)
void sdk_f_499f0() {}

// sub_49ac0  (orig 0x49ac0, setter)
void sdk_f_49ac0(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_49ad0  (orig 0x49ad0, ret_only)
void sdk_f_49ad0() {}

// sub_49ae0  (orig 0x49ae0, getter)
uint8_t sdk_f_49ae0(void* a0) { return *(uint8_t*)((char*)(a0) + 8); }

// sub_49cf0  (orig 0x49cf0, getter)
uint8_t sdk_f_49cf0(void* a0) { return *(uint8_t*)((char*)(a0) + 513); }

// sub_49d00  (orig 0x49d00, getter)
uint8_t sdk_f_49d00(void* a0) { return *(uint8_t*)((char*)(a0) + 596); }

// sub_49d80  (orig 0x49d80, setter)
void sdk_f_49d80(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_49d90  (orig 0x49d90, setter)
void sdk_f_49d90(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0)) = a1; }

// sub_49da0  (orig 0x49da0, copy-chain)
void sdk_f_49da0(void* a0, void* a1) { *(uint64_t*)((char*)(a0)) = *(uint64_t*)((char*)(a1)); *(uint64_t*)((char*)(a1)) = 0; }

// sub_49f80  (orig 0x49f80, setter)
void sdk_f_49f80(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_49f90  (orig 0x49f90, setter)
void sdk_f_49f90(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0)) = a1; }

// sub_49fa0  (orig 0x49fa0, copy-chain)
void sdk_f_49fa0(void* a0, void* a1) { *(uint64_t*)((char*)(a0)) = *(uint64_t*)((char*)(a1)); *(uint64_t*)((char*)(a1)) = 0; }

// sub_4aac0  (orig 0x4aac0, getter)
uint64_t sdk_f_4aac0(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_4caa0  (orig 0x4caa0, call)
extern void callee_5119a0();
uint64_t sdk_f_4caa0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_5119a0)(((uintptr_t)((char*)(a0) + 24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_4cac0  (orig 0x4cac0, call)
extern void callee_5119b0();
uint64_t sdk_f_4cac0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_5119b0)(((uintptr_t)((char*)(a0) + 24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_4cae0  (orig 0x4cae0, call)
extern void callee_5119c0();
uint64_t sdk_f_4cae0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_5119c0)(((uintptr_t)((char*)(a0) + 24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_4dd80  (orig 0x4dd80, getter)
uint64_t sdk_f_4dd80(void* a0) { return *(uint64_t*)((char*)(a0) + 48); }

// sub_4f010  (orig 0x4f010, ret_only)
void sdk_f_4f010() {}

// sub_4f180  (orig 0x4f180, setter-chain)
void sdk_f_4f180(void* a0) { *(uint32_t*)((char*)(a0)) = 0; *(uint16_t*)((char*)(a0) + 4) = 0; }

// sub_4f190  (orig 0x4f190, compare)
bool sdk_f_4f190(void* a0) { return (int32_t)(*(uint32_t*)((char*)(a0))) > (int64_t)(0); }

// sub_4f1a0  (orig 0x4f1a0, getter)
uint8_t sdk_f_4f1a0(void* a0) { return *(uint8_t*)((char*)(a0) + 4); }

// sub_4f1b0  (orig 0x4f1b0, getter)
uint8_t sdk_f_4f1b0(void* a0) { return *(uint8_t*)((char*)(a0) + 5); }

// sub_4f260  (orig 0x4f260, ptr_add)
void* sdk_f_4f260(void* a0) { return (char*)a0 + 8; }

// sub_4f320  (orig 0x4f320, mov_ret)
uint32_t sdk_f_4f320() { return 100663296; }

// sub_4f330  (orig 0x4f330, mov_ret)
uint32_t sdk_f_4f330() { return 4096; }

// sub_502d0  (orig 0x502d0, getter)
uint32_t sdk_f_502d0(void* a0) { return *(uint32_t*)((char*)(a0) + 20); }

// sub_502e0  (orig 0x502e0, setter)
void sdk_f_502e0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 20) = a1; }

// sub_502f0  (orig 0x502f0, getter)
uint32_t sdk_f_502f0(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_50300  (orig 0x50300, setter)
void sdk_f_50300(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 24) = a1; }

// sub_50310  (orig 0x50310, getter)
uint32_t sdk_f_50310(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_50320  (orig 0x50320, setter)
void sdk_f_50320(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 28) = a1; }

// sub_50330  (orig 0x50330, getter)
uint32_t sdk_f_50330(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_50340  (orig 0x50340, setter)
void sdk_f_50340(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 32) = a1; }

// sub_50350  (orig 0x50350, getter)
uint32_t sdk_f_50350(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_50360  (orig 0x50360, setter)
void sdk_f_50360(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 36) = a1; }

// sub_50370  (orig 0x50370, setter)
void sdk_f_50370(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 56) = a1; }

// sub_50380  (orig 0x50380, getter)
uint32_t sdk_f_50380(void* a0) { return *(uint32_t*)((char*)(a0) + 40); }

// sub_50390  (orig 0x50390, setter)
void sdk_f_50390(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 40) = a1; }

// sub_503a0  (orig 0x503a0, getter)
uint32_t sdk_f_503a0(void* a0) { return *(uint32_t*)((char*)(a0) + 44); }

// sub_503b0  (orig 0x503b0, setter)
void sdk_f_503b0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 44) = a1; }

// sub_503c0  (orig 0x503c0, getter)
uint32_t sdk_f_503c0(void* a0) { return *(uint32_t*)((char*)(a0) + 48); }

// sub_503d0  (orig 0x503d0, setter)
void sdk_f_503d0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 48) = a1; }

// sub_503e0  (orig 0x503e0, getter)
uint32_t sdk_f_503e0(void* a0) { return *(uint32_t*)((char*)(a0) + 52); }

// sub_503f0  (orig 0x503f0, setter)
void sdk_f_503f0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 52) = a1; }

// sub_55ea0  (orig 0x55ea0, ptr_add)
void* sdk_f_55ea0(void* a0) { return (char*)a0 + 32; }

// sub_56420  (orig 0x56420, ptr_add)
void* sdk_f_56420(void* a0) { return (char*)a0 + 8; }

// sub_56430  (orig 0x56430, straight)
void* sdk_f_56430(void* a0) { return (char*)(a0) - 24; }

// sub_56770  (orig 0x56770, ptr_add)
void* sdk_f_56770(void* a0) { return (char*)a0 + 32; }

// sub_56f00  (orig 0x56f00, ptr_add)
void* sdk_f_56f00(void* a0) { return (char*)a0 + 8; }

// sub_56f10  (orig 0x56f10, straight)
void* sdk_f_56f10(void* a0) { return (char*)(a0) - 24; }

// sub_57040  (orig 0x57040, ptr_add)
void* sdk_f_57040(void* a0) { return (char*)a0 + 32; }

// sub_57070  (orig 0x57070, call)
extern void callee_511390();
uint64_t sdk_f_57070(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57090  (orig 0x57090, call)
extern void callee_512000();
uint64_t sdk_f_57090(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512000)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_570b0  (orig 0x570b0, call)
extern void callee_511510();
uint64_t sdk_f_570b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_570d0  (orig 0x570d0, call)
extern void callee_511510();
uint64_t sdk_f_570d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_570f0  (orig 0x570f0, call)
extern void callee_5114b0();
uint64_t sdk_f_570f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57110  (orig 0x57110, call)
extern void callee_511390();
uint64_t sdk_f_57110(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57130  (orig 0x57130, call)
extern void callee_5114b0();
uint64_t sdk_f_57130(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57150  (orig 0x57150, call)
extern void callee_5114b0();
uint64_t sdk_f_57150(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57170  (orig 0x57170, call)
extern void callee_5114b0();
uint64_t sdk_f_57170(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57190  (orig 0x57190, call)
extern void callee_511510();
uint64_t sdk_f_57190(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_571b0  (orig 0x571b0, call)
extern void callee_511510();
uint64_t sdk_f_571b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_571d0  (orig 0x571d0, call)
extern void callee_511510();
uint64_t sdk_f_571d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_571f0  (orig 0x571f0, call)
extern void callee_511570();
uint64_t sdk_f_571f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57460  (orig 0x57460, call)
extern void callee_512040();
uint64_t sdk_f_57460(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512040)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57480  (orig 0x57480, call)
extern void callee_5114b0();
uint64_t sdk_f_57480(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_574a0  (orig 0x574a0, call)
extern void callee_512050();
uint64_t sdk_f_574a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_574d0  (orig 0x574d0, call)
extern void callee_512050();
uint64_t sdk_f_574d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(52)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57500  (orig 0x57500, call)
extern void callee_511510();
uint64_t sdk_f_57500(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(53)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57520  (orig 0x57520, call)
extern void callee_511510();
uint64_t sdk_f_57520(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(54)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57540  (orig 0x57540, call)
extern void callee_5114b0();
uint64_t sdk_f_57540(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(55)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57560  (orig 0x57560, call)
extern void callee_512060();
uint64_t sdk_f_57560(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512060)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57580  (orig 0x57580, call)
extern void callee_511570();
uint64_t sdk_f_57580(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(61)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_575a0  (orig 0x575a0, call)
extern void callee_511390();
uint64_t sdk_f_575a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(62)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_575c0  (orig 0x575c0, call)
extern void callee_511570();
uint64_t sdk_f_575c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(63)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_575e0  (orig 0x575e0, call)
extern void callee_511780();
uint64_t sdk_f_575e0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(64)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57610  (orig 0x57610, call)
extern void callee_512070();
uint64_t sdk_f_57610(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512070)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57640  (orig 0x57640, call)
extern void callee_511780();
uint64_t sdk_f_57640(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(66)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57670  (orig 0x57670, call)
extern void callee_511780();
uint64_t sdk_f_57670(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_576a0  (orig 0x576a0, call)
extern void callee_512050();
uint64_t sdk_f_576a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(90)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_576d0  (orig 0x576d0, call)
extern void callee_511390();
uint64_t sdk_f_576d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(91)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_576f0  (orig 0x576f0, call)
extern void callee_511390();
uint64_t sdk_f_576f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57710  (orig 0x57710, ptr_add)
void* sdk_f_57710(void* a0) { return (char*)a0 + 8; }

// sub_57720  (orig 0x57720, straight)
void* sdk_f_57720(void* a0) { return (char*)(a0) - 24; }

// sub_579a0  (orig 0x579a0, ptr_add)
void* sdk_f_579a0(void* a0) { return (char*)a0 + 32; }

// sub_579b0  (orig 0x579b0, call)
extern void callee_512080();
uint64_t sdk_f_579b0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512080)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_579e0  (orig 0x579e0, call)
extern void callee_511510();
uint64_t sdk_f_579e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57a00  (orig 0x57a00, call)
extern void callee_511570();
uint64_t sdk_f_57a00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_57a20  (orig 0x57a20, ptr_add)
void* sdk_f_57a20(void* a0) { return (char*)a0 + 8; }

// sub_57a30  (orig 0x57a30, straight)
void* sdk_f_57a30(void* a0) { return (char*)(a0) - 24; }

// sub_58080  (orig 0x58080, ptr_add)
void* sdk_f_58080(void* a0) { return (char*)a0 + 32; }

// sub_580b0  (orig 0x580b0, call)
extern void callee_511510();
uint64_t sdk_f_580b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_580d0  (orig 0x580d0, call)
extern void callee_511510();
uint64_t sdk_f_580d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_580f0  (orig 0x580f0, call)
extern void callee_511510();
uint64_t sdk_f_580f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58110  (orig 0x58110, call)
extern void callee_511510();
uint64_t sdk_f_58110(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58130  (orig 0x58130, call)
extern void callee_511570();
uint64_t sdk_f_58130(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58150  (orig 0x58150, call)
extern void callee_511780();
uint64_t sdk_f_58150(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58180  (orig 0x58180, call)
extern void callee_512050();
uint64_t sdk_f_58180(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_581b0  (orig 0x581b0, call)
extern void callee_512050();
uint64_t sdk_f_581b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_581e0  (orig 0x581e0, call)
extern void callee_512090();
uint64_t sdk_f_581e0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512090)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58210  (orig 0x58210, call)
extern void callee_512050();
uint64_t sdk_f_58210(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58240  (orig 0x58240, call)
extern void callee_511480();
uint64_t sdk_f_58240(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58260  (orig 0x58260, call)
extern void callee_512050();
uint64_t sdk_f_58260(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58290  (orig 0x58290, call)
extern void callee_512050();
uint64_t sdk_f_58290(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_582c0  (orig 0x582c0, call)
extern void callee_512050();
uint64_t sdk_f_582c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_582f0  (orig 0x582f0, call)
extern void callee_511780();
uint64_t sdk_f_582f0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58320  (orig 0x58320, call)
extern void callee_511780();
uint64_t sdk_f_58320(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58350  (orig 0x58350, call)
extern void callee_511520();
uint64_t sdk_f_58350(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58370  (orig 0x58370, call)
extern void callee_511510();
uint64_t sdk_f_58370(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(41)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58390  (orig 0x58390, call)
extern void callee_5120a0();
uint64_t sdk_f_58390(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5120a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(42)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_583b0  (orig 0x583b0, call)
extern void callee_511520();
uint64_t sdk_f_583b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(43)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_583d0  (orig 0x583d0, call)
extern void callee_512050();
uint64_t sdk_f_583d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58400  (orig 0x58400, call)
extern void callee_511510();
uint64_t sdk_f_58400(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58420  (orig 0x58420, call)
extern void callee_5120b0();
uint64_t sdk_f_58420(void* a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5120b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58450  (orig 0x58450, call)
extern void callee_512050();
uint64_t sdk_f_58450(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(61)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58480  (orig 0x58480, call)
extern void callee_511780();
uint64_t sdk_f_58480(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(62)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_584b0  (orig 0x584b0, call)
extern void callee_511390();
uint64_t sdk_f_584b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(63)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_584d0  (orig 0x584d0, call)
extern void callee_511780();
uint64_t sdk_f_584d0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(64)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58500  (orig 0x58500, call)
extern void callee_511510();
uint64_t sdk_f_58500(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58520  (orig 0x58520, call)
extern void callee_511390();
uint64_t sdk_f_58520(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(66)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58540  (orig 0x58540, call)
extern void callee_5114b0();
uint64_t sdk_f_58540(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(67)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58560  (orig 0x58560, call)
extern void callee_512050();
uint64_t sdk_f_58560(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(68)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58590  (orig 0x58590, call)
extern void callee_5114b0();
uint64_t sdk_f_58590(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(69)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_585b0  (orig 0x585b0, call)
extern void callee_5120c0();
uint64_t sdk_f_585b0(void* a0, uint32_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5120c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(70)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_585e0  (orig 0x585e0, call)
extern void callee_5120d0();
uint64_t sdk_f_585e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5120d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(71)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58600  (orig 0x58600, call)
extern void callee_511780();
uint64_t sdk_f_58600(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58630  (orig 0x58630, call)
extern void callee_511520();
uint64_t sdk_f_58630(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(90)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58650  (orig 0x58650, call)
extern void callee_511570();
uint64_t sdk_f_58650(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(91)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58670  (orig 0x58670, call)
extern void callee_512050();
uint64_t sdk_f_58670(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_58740  (orig 0x58740, ptr_add)
void* sdk_f_58740(void* a0) { return (char*)a0 + 8; }

// sub_58750  (orig 0x58750, straight)
void* sdk_f_58750(void* a0) { return (char*)(a0) - 24; }

// sub_59010  (orig 0x59010, ptr_add)
void* sdk_f_59010(void* a0) { return (char*)a0 + 32; }

// sub_59160  (orig 0x59160, call)
extern void callee_511570();
uint64_t sdk_f_59160(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_59180  (orig 0x59180, call)
extern void callee_511510();
uint64_t sdk_f_59180(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_591a0  (orig 0x591a0, ptr_add)
void* sdk_f_591a0(void* a0) { return (char*)a0 + 8; }

// sub_591b0  (orig 0x591b0, straight)
void* sdk_f_591b0(void* a0) { return (char*)(a0) - 24; }

// sub_592e0  (orig 0x592e0, ptr_add)
void* sdk_f_592e0(void* a0) { return (char*)a0 + 32; }

// sub_59450  (orig 0x59450, ptr_add)
void* sdk_f_59450(void* a0) { return (char*)a0 + 8; }

// sub_59460  (orig 0x59460, straight)
void* sdk_f_59460(void* a0) { return (char*)(a0) - 24; }

// sub_59590  (orig 0x59590, ptr_add)
void* sdk_f_59590(void* a0) { return (char*)a0 + 32; }

// sub_595c0  (orig 0x595c0, call)
extern void callee_512120();
uint64_t sdk_f_595c0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512120)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_595f0  (orig 0x595f0, call)
extern void callee_512130();
uint64_t sdk_f_595f0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512130)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_59620  (orig 0x59620, ptr_add)
void* sdk_f_59620(void* a0) { return (char*)a0 + 8; }

// sub_59630  (orig 0x59630, straight)
void* sdk_f_59630(void* a0) { return (char*)(a0) - 24; }

// sub_59b40  (orig 0x59b40, ptr_add)
void* sdk_f_59b40(void* a0) { return (char*)a0 + 32; }

// sub_59b70  (orig 0x59b70, call)
extern void callee_512140();
uint64_t sdk_f_59b70(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512140)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_59b90  (orig 0x59b90, ptr_add)
void* sdk_f_59b90(void* a0) { return (char*)a0 + 8; }

// sub_59ba0  (orig 0x59ba0, straight)
void* sdk_f_59ba0(void* a0) { return (char*)(a0) - 24; }

// sub_59e50  (orig 0x59e50, ptr_add)
void* sdk_f_59e50(void* a0) { return (char*)a0 + 32; }

// sub_59f10  (orig 0x59f10, call)
extern void callee_511520();
uint64_t sdk_f_59f10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_59f30  (orig 0x59f30, call)
extern void callee_511520();
uint64_t sdk_f_59f30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_59f50  (orig 0x59f50, call)
extern void callee_511510();
uint64_t sdk_f_59f50(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_59f70  (orig 0x59f70, call)
extern void callee_511510();
uint64_t sdk_f_59f70(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_59f90  (orig 0x59f90, call)
extern void callee_511510();
uint64_t sdk_f_59f90(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_59fb0  (orig 0x59fb0, call)
extern void callee_512050();
uint64_t sdk_f_59fb0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_59fe0  (orig 0x59fe0, call)
extern void callee_511670();
uint64_t sdk_f_59fe0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a000  (orig 0x5a000, ptr_add)
void* sdk_f_5a000(void* a0) { return (char*)a0 + 8; }

// sub_5a010  (orig 0x5a010, straight)
void* sdk_f_5a010(void* a0) { return (char*)(a0) - 24; }

// sub_5a140  (orig 0x5a140, ptr_add)
void* sdk_f_5a140(void* a0) { return (char*)a0 + 32; }

// sub_5a150  (orig 0x5a150, ptr_add)
void* sdk_f_5a150(void* a0) { return (char*)a0 + 8; }

// sub_5a160  (orig 0x5a160, straight)
void* sdk_f_5a160(void* a0) { return (char*)(a0) - 24; }

// sub_5a290  (orig 0x5a290, ptr_add)
void* sdk_f_5a290(void* a0) { return (char*)a0 + 32; }

// sub_5a2d0  (orig 0x5a2d0, call)
extern void callee_511390();
uint64_t sdk_f_5a2d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a2f0  (orig 0x5a2f0, call)
extern void callee_511390();
uint64_t sdk_f_5a2f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a370  (orig 0x5a370, ptr_add)
void* sdk_f_5a370(void* a0) { return (char*)a0 + 8; }

// sub_5a380  (orig 0x5a380, straight)
void* sdk_f_5a380(void* a0) { return (char*)(a0) - 24; }

// sub_5a600  (orig 0x5a600, ptr_add)
void* sdk_f_5a600(void* a0) { return (char*)a0 + 32; }

// sub_5a640  (orig 0x5a640, call)
extern void callee_511510();
uint64_t sdk_f_5a640(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a660  (orig 0x5a660, call)
extern void callee_512180();
uint64_t sdk_f_5a660(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a690  (orig 0x5a690, call)
extern void callee_512180();
uint64_t sdk_f_5a690(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a6c0  (orig 0x5a6c0, call)
extern void callee_511510();
uint64_t sdk_f_5a6c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a6e0  (orig 0x5a6e0, call)
extern void callee_512190();
uint64_t sdk_f_5a6e0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512190)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a710  (orig 0x5a710, call)
extern void callee_512190();
uint64_t sdk_f_5a710(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512190)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a740  (orig 0x5a740, call)
extern void callee_512190();
uint64_t sdk_f_5a740(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512190)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a770  (orig 0x5a770, call)
extern void callee_5121a0();
uint64_t sdk_f_5a770(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5121a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a7a0  (orig 0x5a7a0, call)
extern void callee_512160();
uint64_t sdk_f_5a7a0(void* a0, uint32_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512160)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a7d0  (orig 0x5a7d0, call)
extern void callee_511570();
uint64_t sdk_f_5a7d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a7f0  (orig 0x5a7f0, call)
extern void callee_511510();
uint64_t sdk_f_5a7f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a810  (orig 0x5a810, call)
extern void callee_511570();
uint64_t sdk_f_5a810(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a830  (orig 0x5a830, call)
extern void callee_511510();
uint64_t sdk_f_5a830(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a850  (orig 0x5a850, call)
extern void callee_511570();
uint64_t sdk_f_5a850(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a870  (orig 0x5a870, call)
extern void callee_511510();
uint64_t sdk_f_5a870(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a890  (orig 0x5a890, call)
extern void callee_5121b0();
uint64_t sdk_f_5a890(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5121b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a8b0  (orig 0x5a8b0, call)
extern void callee_5121b0();
uint64_t sdk_f_5a8b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5121b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a8d0  (orig 0x5a8d0, call)
extern void callee_5121b0();
uint64_t sdk_f_5a8d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5121b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a8f0  (orig 0x5a8f0, call)
extern void callee_5121c0();
uint64_t sdk_f_5a8f0(void* a0, uint32_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5121c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a920  (orig 0x5a920, call)
extern void callee_511780();
uint64_t sdk_f_5a920(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a950  (orig 0x5a950, call)
extern void callee_5121d0();
uint64_t sdk_f_5a950(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5121d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a970  (orig 0x5a970, call)
extern void callee_511510();
uint64_t sdk_f_5a970(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a990  (orig 0x5a990, call)
extern void callee_5121d0();
uint64_t sdk_f_5a990(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5121d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a9b0  (orig 0x5a9b0, call)
extern void callee_511510();
uint64_t sdk_f_5a9b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a9d0  (orig 0x5a9d0, call)
extern void callee_5121d0();
uint64_t sdk_f_5a9d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5121d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(26)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5a9f0  (orig 0x5a9f0, call)
extern void callee_511510();
uint64_t sdk_f_5a9f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(27)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5aa10  (orig 0x5aa10, call)
extern void callee_5121e0();
uint64_t sdk_f_5aa10(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5121e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(28)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5aa40  (orig 0x5aa40, ptr_add)
void* sdk_f_5aa40(void* a0) { return (char*)a0 + 8; }

// sub_5aa50  (orig 0x5aa50, straight)
void* sdk_f_5aa50(void* a0) { return (char*)(a0) - 24; }

// sub_5b490  (orig 0x5b490, ptr_add)
void* sdk_f_5b490(void* a0) { return (char*)a0 + 32; }

// sub_5b570  (orig 0x5b570, call)
extern void callee_511780();
uint64_t sdk_f_5b570(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b5a0  (orig 0x5b5a0, call)
extern void callee_511510();
uint64_t sdk_f_5b5a0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b600  (orig 0x5b600, call)
extern void callee_512210();
uint64_t sdk_f_5b600(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512210)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b620  (orig 0x5b620, call)
extern void callee_511780();
uint64_t sdk_f_5b620(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b650  (orig 0x5b650, ptr_add)
void* sdk_f_5b650(void* a0) { return (char*)a0 + 8; }

// sub_5b660  (orig 0x5b660, straight)
void* sdk_f_5b660(void* a0) { return (char*)(a0) - 24; }

// sub_5b790  (orig 0x5b790, ptr_add)
void* sdk_f_5b790(void* a0) { return (char*)a0 + 32; }

// sub_5b7e0  (orig 0x5b7e0, call)
extern void callee_5114b0();
uint64_t sdk_f_5b7e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b800  (orig 0x5b800, call)
extern void callee_511510();
uint64_t sdk_f_5b800(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b820  (orig 0x5b820, call)
extern void callee_511510();
uint64_t sdk_f_5b820(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b840  (orig 0x5b840, call)
extern void callee_511510();
uint64_t sdk_f_5b840(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b860  (orig 0x5b860, call)
extern void callee_511510();
uint64_t sdk_f_5b860(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b880  (orig 0x5b880, call)
extern void callee_511510();
uint64_t sdk_f_5b880(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b8a0  (orig 0x5b8a0, call)
extern void callee_511510();
uint64_t sdk_f_5b8a0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b8c0  (orig 0x5b8c0, call)
extern void callee_5114b0();
uint64_t sdk_f_5b8c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b980  (orig 0x5b980, call)
extern void callee_511520();
uint64_t sdk_f_5b980(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5b9f0  (orig 0x5b9f0, call)
extern void callee_512180();
uint64_t sdk_f_5b9f0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(122)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5ba20  (orig 0x5ba20, call)
extern void callee_512180();
uint64_t sdk_f_5ba20(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512180)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(123)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5ba50  (orig 0x5ba50, call)
extern void callee_5113c0();
uint64_t sdk_f_5ba50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(124)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5baa0  (orig 0x5baa0, call)
extern void callee_5114b0();
uint64_t sdk_f_5baa0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(131)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5bac0  (orig 0x5bac0, call)
extern void callee_511520();
uint64_t sdk_f_5bac0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(132)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5bae0  (orig 0x5bae0, call)
extern void callee_511500();
uint64_t sdk_f_5bae0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (4))), ((uintptr_t)(140)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5bb10  (orig 0x5bb10, call)
extern void callee_511510();
uint64_t sdk_f_5bb10(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(150)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5bb30  (orig 0x5bb30, ptr_add)
void* sdk_f_5bb30(void* a0) { return (char*)a0 + 8; }

// sub_5bb40  (orig 0x5bb40, straight)
void* sdk_f_5bb40(void* a0) { return (char*)(a0) - 24; }

// sub_5bc70  (orig 0x5bc70, ptr_add)
void* sdk_f_5bc70(void* a0) { return (char*)a0 + 32; }

// sub_5bcc0  (orig 0x5bcc0, call)
extern void callee_5114b0();
uint64_t sdk_f_5bcc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5bce0  (orig 0x5bce0, call)
extern void callee_511510();
uint64_t sdk_f_5bce0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5bd00  (orig 0x5bd00, call)
extern void callee_511510();
uint64_t sdk_f_5bd00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5bd20  (orig 0x5bd20, call)
extern void callee_511510();
uint64_t sdk_f_5bd20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5bd40  (orig 0x5bd40, call)
extern void callee_511510();
uint64_t sdk_f_5bd40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5bd60  (orig 0x5bd60, ptr_add)
void* sdk_f_5bd60(void* a0) { return (char*)a0 + 8; }

// sub_5bd70  (orig 0x5bd70, straight)
void* sdk_f_5bd70(void* a0) { return (char*)(a0) - 24; }

// sub_5c5b0  (orig 0x5c5b0, ptr_add)
void* sdk_f_5c5b0(void* a0) { return (char*)a0 + 32; }

// sub_5c770  (orig 0x5c770, call)
extern void callee_511510();
uint64_t sdk_f_5c770(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5c790  (orig 0x5c790, call)
extern void callee_511510();
uint64_t sdk_f_5c790(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5c850  (orig 0x5c850, ptr_add)
void* sdk_f_5c850(void* a0) { return (char*)a0 + 8; }

// sub_5c860  (orig 0x5c860, straight)
void* sdk_f_5c860(void* a0) { return (char*)(a0) - 24; }

// sub_5cae0  (orig 0x5cae0, ptr_add)
void* sdk_f_5cae0(void* a0) { return (char*)a0 + 32; }

// sub_5cb30  (orig 0x5cb30, call)
extern void callee_5114b0();
uint64_t sdk_f_5cb30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5cb50  (orig 0x5cb50, call)
extern void callee_511510();
uint64_t sdk_f_5cb50(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5cb70  (orig 0x5cb70, call)
extern void callee_511510();
uint64_t sdk_f_5cb70(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5cb90  (orig 0x5cb90, call)
extern void callee_511510();
uint64_t sdk_f_5cb90(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5cbb0  (orig 0x5cbb0, call)
extern void callee_511510();
uint64_t sdk_f_5cbb0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5cbd0  (orig 0x5cbd0, call)
extern void callee_512050();
uint64_t sdk_f_5cbd0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5ce30  (orig 0x5ce30, call)
extern void callee_511570();
uint64_t sdk_f_5ce30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(105)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5ce50  (orig 0x5ce50, call)
extern void callee_511570();
uint64_t sdk_f_5ce50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(106)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5ce70  (orig 0x5ce70, call)
extern void callee_5114b0();
uint64_t sdk_f_5ce70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5ce90  (orig 0x5ce90, call)
extern void callee_512000();
uint64_t sdk_f_5ce90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512000)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5ceb0  (orig 0x5ceb0, call)
extern void callee_511510();
uint64_t sdk_f_5ceb0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(150)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5ced0  (orig 0x5ced0, call)
extern void callee_512270();
uint64_t sdk_f_5ced0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512270)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(160)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5cef0  (orig 0x5cef0, ptr_add)
void* sdk_f_5cef0(void* a0) { return (char*)a0 + 8; }

// sub_5cf00  (orig 0x5cf00, straight)
void* sdk_f_5cf00(void* a0) { return (char*)(a0) - 24; }

// sub_5d190  (orig 0x5d190, ptr_add)
void* sdk_f_5d190(void* a0) { return (char*)a0 + 32; }

// sub_5d250  (orig 0x5d250, call)
extern void callee_511510();
uint64_t sdk_f_5d250(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5d270  (orig 0x5d270, call)
extern void callee_5114b0();
uint64_t sdk_f_5d270(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5d4b0  (orig 0x5d4b0, ptr_add)
void* sdk_f_5d4b0(void* a0) { return (char*)a0 + 8; }

// sub_5d4c0  (orig 0x5d4c0, straight)
void* sdk_f_5d4c0(void* a0) { return (char*)(a0) - 24; }

// sub_5da20  (orig 0x5da20, ptr_add)
void* sdk_f_5da20(void* a0) { return (char*)a0 + 32; }

// sub_5da30  (orig 0x5da30, call)
extern void callee_511510();
uint64_t sdk_f_5da30(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5da50  (orig 0x5da50, call)
extern void callee_511510();
uint64_t sdk_f_5da50(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5da70  (orig 0x5da70, call)
extern void callee_511510();
uint64_t sdk_f_5da70(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5db30  (orig 0x5db30, call)
extern void callee_511570();
uint64_t sdk_f_5db30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5dca0  (orig 0x5dca0, call)
extern void callee_5122b0();
uint64_t sdk_f_5dca0(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5122b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (4))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5dcd0  (orig 0x5dcd0, ptr_add)
void* sdk_f_5dcd0(void* a0) { return (char*)a0 + 8; }

// sub_5dce0  (orig 0x5dce0, straight)
void* sdk_f_5dce0(void* a0) { return (char*)(a0) - 24; }

// sub_5e030  (orig 0x5e030, ptr_add)
void* sdk_f_5e030(void* a0) { return (char*)a0 + 32; }

// sub_5e060  (orig 0x5e060, call)
extern void callee_511510();
uint64_t sdk_f_5e060(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e080  (orig 0x5e080, call)
extern void callee_512050();
uint64_t sdk_f_5e080(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e0b0  (orig 0x5e0b0, call)
extern void callee_511510();
uint64_t sdk_f_5e0b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e0d0  (orig 0x5e0d0, call)
extern void callee_511510();
uint64_t sdk_f_5e0d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e0f0  (orig 0x5e0f0, call)
extern void callee_5114b0();
uint64_t sdk_f_5e0f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e110  (orig 0x5e110, call)
extern void callee_511510();
uint64_t sdk_f_5e110(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e130  (orig 0x5e130, call)
extern void callee_511510();
uint64_t sdk_f_5e130(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e150  (orig 0x5e150, call)
extern void callee_511670();
uint64_t sdk_f_5e150(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e170  (orig 0x5e170, call)
extern void callee_511510();
uint64_t sdk_f_5e170(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e190  (orig 0x5e190, call)
extern void callee_5114b0();
uint64_t sdk_f_5e190(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e1b0  (orig 0x5e1b0, call)
extern void callee_511570();
uint64_t sdk_f_5e1b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e1d0  (orig 0x5e1d0, ptr_add)
void* sdk_f_5e1d0(void* a0) { return (char*)a0 + 8; }

// sub_5e1e0  (orig 0x5e1e0, straight)
void* sdk_f_5e1e0(void* a0) { return (char*)(a0) - 24; }

// sub_5e310  (orig 0x5e310, ptr_add)
void* sdk_f_5e310(void* a0) { return (char*)a0 + 32; }

// sub_5e5c0  (orig 0x5e5c0, ptr_add)
void* sdk_f_5e5c0(void* a0) { return (char*)a0 + 8; }

// sub_5e5d0  (orig 0x5e5d0, straight)
void* sdk_f_5e5d0(void* a0) { return (char*)(a0) - 24; }

// sub_5e700  (orig 0x5e700, ptr_add)
void* sdk_f_5e700(void* a0) { return (char*)a0 + 32; }

// sub_5e710  (orig 0x5e710, call)
extern void callee_5122c0();
uint64_t sdk_f_5e710(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5122c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e740  (orig 0x5e740, call)
extern void callee_512120();
uint64_t sdk_f_5e740(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512120)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5e770  (orig 0x5e770, ptr_add)
void* sdk_f_5e770(void* a0) { return (char*)a0 + 8; }

// sub_5e780  (orig 0x5e780, straight)
void* sdk_f_5e780(void* a0) { return (char*)(a0) - 24; }

// sub_5eab0  (orig 0x5eab0, ptr_add)
void* sdk_f_5eab0(void* a0) { return (char*)a0 + 32; }

// sub_5f100  (orig 0x5f100, ptr_add)
void* sdk_f_5f100(void* a0) { return (char*)a0 + 8; }

// sub_5f110  (orig 0x5f110, straight)
void* sdk_f_5f110(void* a0) { return (char*)(a0) - 24; }

// sub_5f240  (orig 0x5f240, ptr_add)
void* sdk_f_5f240(void* a0) { return (char*)a0 + 32; }

// sub_5f430  (orig 0x5f430, call)
extern void callee_511570();
uint64_t sdk_f_5f430(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f450  (orig 0x5f450, call)
extern void callee_511570();
uint64_t sdk_f_5f450(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f470  (orig 0x5f470, call)
extern void callee_511510();
uint64_t sdk_f_5f470(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f490  (orig 0x5f490, call)
extern void callee_512000();
uint64_t sdk_f_5f490(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512000)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f4b0  (orig 0x5f4b0, call)
extern void callee_5113c0();
uint64_t sdk_f_5f4b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f4d0  (orig 0x5f4d0, call)
extern void callee_5114b0();
uint64_t sdk_f_5f4d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f4f0  (orig 0x5f4f0, call)
extern void callee_5113c0();
uint64_t sdk_f_5f4f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f510  (orig 0x5f510, call)
extern void callee_5122e0();
uint64_t sdk_f_5f510(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5122e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(16384)), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f540  (orig 0x5f540, call)
extern void callee_5114b0();
uint64_t sdk_f_5f540(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f560  (orig 0x5f560, call)
extern void callee_511500();
uint64_t sdk_f_5f560(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (4))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f590  (orig 0x5f590, call)
extern void callee_5113c0();
uint64_t sdk_f_5f590(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f5b0  (orig 0x5f5b0, call)
extern void callee_511390();
uint64_t sdk_f_5f5b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f670  (orig 0x5f670, call)
extern void callee_511570();
uint64_t sdk_f_5f670(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f730  (orig 0x5f730, call)
extern void callee_511520();
uint64_t sdk_f_5f730(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f750  (orig 0x5f750, call)
extern void callee_5122f0();
uint64_t sdk_f_5f750(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5122f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f770  (orig 0x5f770, call)
extern void callee_512300();
uint64_t sdk_f_5f770(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512300)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(512)), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f7a0  (orig 0x5f7a0, call)
extern void callee_512310();
uint64_t sdk_f_5f7a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512310)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f7c0  (orig 0x5f7c0, call)
extern void callee_511510();
uint64_t sdk_f_5f7c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f8e0  (orig 0x5f8e0, call)
extern void callee_511510();
uint64_t sdk_f_5f8e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f900  (orig 0x5f900, call)
extern void callee_511510();
uint64_t sdk_f_5f900(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(102)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f920  (orig 0x5f920, call)
extern void callee_512340();
uint64_t sdk_f_5f920(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512340)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (4))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_5f950  (orig 0x5f950, ptr_add)
void* sdk_f_5f950(void* a0) { return (char*)a0 + 8; }

// sub_5f960  (orig 0x5f960, straight)
void* sdk_f_5f960(void* a0) { return (char*)(a0) - 24; }

// sub_602a0  (orig 0x602a0, ptr_add)
void* sdk_f_602a0(void* a0) { return (char*)a0 + 32; }

// sub_602b0  (orig 0x602b0, call)
extern void callee_512350();
uint64_t sdk_f_602b0(void* a0, uint64_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512350)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_602e0  (orig 0x602e0, call)
extern void callee_512360();
uint64_t sdk_f_602e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512360)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_60300  (orig 0x60300, call)
extern void callee_511570();
uint64_t sdk_f_60300(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511570)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_60320  (orig 0x60320, call)
extern void callee_512370();
uint64_t sdk_f_60320(void* a0, void* a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_60360  (orig 0x60360, ptr_add)
void* sdk_f_60360(void* a0) { return (char*)a0 + 8; }

// sub_60370  (orig 0x60370, straight)
void* sdk_f_60370(void* a0) { return (char*)(a0) - 24; }

// sub_60e90  (orig 0x60e90, ptr_add)
void* sdk_f_60e90(void* a0) { return (char*)a0 + 32; }

// sub_614e0  (orig 0x614e0, ptr_add)
void* sdk_f_614e0(void* a0) { return (char*)a0 + 8; }

// sub_614f0  (orig 0x614f0, straight)
void* sdk_f_614f0(void* a0) { return (char*)(a0) - 24; }

// sub_61620  (orig 0x61620, ptr_add)
void* sdk_f_61620(void* a0) { return (char*)a0 + 32; }

// sub_61650  (orig 0x61650, call)
extern void callee_511510();
uint64_t sdk_f_61650(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_61670  (orig 0x61670, call)
extern void callee_511520();
uint64_t sdk_f_61670(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_61690  (orig 0x61690, call)
extern void callee_511670();
uint64_t sdk_f_61690(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_616b0  (orig 0x616b0, call)
extern void callee_512050();
uint64_t sdk_f_616b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_616e0  (orig 0x616e0, call)
extern void callee_511780();
uint64_t sdk_f_616e0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_61710  (orig 0x61710, call)
extern void callee_512050();
uint64_t sdk_f_61710(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_61740  (orig 0x61740, call)
extern void callee_511510();
uint64_t sdk_f_61740(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_61760  (orig 0x61760, call)
extern void callee_511510();
uint64_t sdk_f_61760(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_61780  (orig 0x61780, call)
extern void callee_512050();
uint64_t sdk_f_61780(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(90)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_617b0  (orig 0x617b0, call)
extern void callee_511510();
uint64_t sdk_f_617b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_617d0  (orig 0x617d0, ptr_add)
void* sdk_f_617d0(void* a0) { return (char*)a0 + 8; }

// sub_617e0  (orig 0x617e0, straight)
void* sdk_f_617e0(void* a0) { return (char*)(a0) - 24; }

// sub_61910  (orig 0x61910, ptr_add)
void* sdk_f_61910(void* a0) { return (char*)a0 + 32; }

// sub_61ec0  (orig 0x61ec0, ptr_add)
void* sdk_f_61ec0(void* a0) { return (char*)a0 + 8; }

// sub_61ed0  (orig 0x61ed0, straight)
void* sdk_f_61ed0(void* a0) { return (char*)(a0) - 24; }

// sub_62000  (orig 0x62000, ptr_add)
void* sdk_f_62000(void* a0) { return (char*)a0 + 32; }

// sub_62170  (orig 0x62170, call)
extern void callee_511670();
uint64_t sdk_f_62170(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62190  (orig 0x62190, call)
extern void callee_5123b0();
uint64_t sdk_f_62190(void* a0, uint64_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5123b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62210  (orig 0x62210, call)
extern void callee_5123d0();
uint64_t sdk_f_62210(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5123d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(32)), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62240  (orig 0x62240, call)
extern void callee_511840();
uint64_t sdk_f_62240(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511840)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62260  (orig 0x62260, call)
extern void callee_512310();
uint64_t sdk_f_62260(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512310)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62280  (orig 0x62280, call)
extern void callee_511780();
uint64_t sdk_f_62280(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_622b0  (orig 0x622b0, call)
extern void callee_5123e0();
uint64_t sdk_f_622b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5123e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_622d0  (orig 0x622d0, call)
extern void callee_5123f0();
uint64_t sdk_f_622d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5123f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_622f0  (orig 0x622f0, call)
extern void callee_512400();
uint64_t sdk_f_622f0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512400)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62320  (orig 0x62320, call)
extern void callee_512410();
uint64_t sdk_f_62320(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512410)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (255))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(26)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62350  (orig 0x62350, call)
extern void callee_512420();
uint64_t sdk_f_62350(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512420)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (65535))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(27)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62380  (orig 0x62380, call)
extern void callee_511670();
uint64_t sdk_f_62380(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_623a0  (orig 0x623a0, call)
extern void callee_511510();
uint64_t sdk_f_623a0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(31)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_623c0  (orig 0x623c0, call)
extern void callee_511670();
uint64_t sdk_f_623c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_623e0  (orig 0x623e0, call)
extern void callee_511510();
uint64_t sdk_f_623e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(33)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62400  (orig 0x62400, call)
extern void callee_5114b0();
uint64_t sdk_f_62400(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62420  (orig 0x62420, call)
extern void callee_5123e0();
uint64_t sdk_f_62420(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5123e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62440  (orig 0x62440, call)
extern void callee_512050();
uint64_t sdk_f_62440(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62470  (orig 0x62470, call)
extern void callee_5114b0();
uint64_t sdk_f_62470(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5114b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62490  (orig 0x62490, call)
extern void callee_512430();
uint64_t sdk_f_62490(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512430)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(66)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_624b0  (orig 0x624b0, call)
extern void callee_511780();
uint64_t sdk_f_624b0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(67)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_624e0  (orig 0x624e0, call)
extern void callee_511510();
uint64_t sdk_f_624e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(68)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62500  (orig 0x62500, call)
extern void callee_511510();
uint64_t sdk_f_62500(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(70)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62520  (orig 0x62520, call)
extern void callee_511510();
uint64_t sdk_f_62520(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(71)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62540  (orig 0x62540, call)
extern void callee_511510();
uint64_t sdk_f_62540(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62560  (orig 0x62560, call)
extern void callee_512050();
uint64_t sdk_f_62560(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(90)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62590  (orig 0x62590, call)
extern void callee_512440();
uint64_t sdk_f_62590(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62620  (orig 0x62620, call)
extern void callee_512050();
uint64_t sdk_f_62620(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(102)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62650  (orig 0x62650, call)
extern void callee_512460();
uint64_t sdk_f_62650(void* a0, uint64_t a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512460)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 1))) << (3))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (3))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_626d0  (orig 0x626d0, call)
extern void callee_512170();
uint64_t sdk_f_626d0(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512170)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62700  (orig 0x62700, call)
extern void callee_511510();
uint64_t sdk_f_62700(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(121)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62770  (orig 0x62770, call)
extern void callee_511390();
uint64_t sdk_f_62770(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(123)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62790  (orig 0x62790, call)
extern void callee_512050();
uint64_t sdk_f_62790(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512050)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(124)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_627c0  (orig 0x627c0, call)
extern void callee_512480();
uint64_t sdk_f_627c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_62890  (orig 0x62890, call)
extern void callee_511510();
uint64_t sdk_f_62890(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_628b0  (orig 0x628b0, ptr_add)
void* sdk_f_628b0(void* a0) { return (char*)a0 + 8; }

// sub_628c0  (orig 0x628c0, straight)
void* sdk_f_628c0(void* a0) { return (char*)(a0) - 24; }

// sub_641e0  (orig 0x641e0, ptr_add)
void* sdk_f_641e0(void* a0) { return (char*)a0 + 32; }

// sub_64290  (orig 0x64290, call)
extern void callee_511520();
uint64_t sdk_f_64290(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_642b0  (orig 0x642b0, ptr_add)
void* sdk_f_642b0(void* a0) { return (char*)a0 + 8; }

// sub_642c0  (orig 0x642c0, straight)
void* sdk_f_642c0(void* a0) { return (char*)(a0) - 24; }

// sub_643f0  (orig 0x643f0, ptr_add)
void* sdk_f_643f0(void* a0) { return (char*)a0 + 32; }

// sub_644a0  (orig 0x644a0, call)
extern void callee_511670();
uint64_t sdk_f_644a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_644c0  (orig 0x644c0, call)
extern void callee_511660();
uint64_t sdk_f_644c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511660)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_644e0  (orig 0x644e0, call)
extern void callee_511670();
uint64_t sdk_f_644e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_64500  (orig 0x64500, call)
extern void callee_511670();
uint64_t sdk_f_64500(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_64520  (orig 0x64520, call)
extern void callee_511670();
uint64_t sdk_f_64520(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_64540  (orig 0x64540, call)
extern void callee_511670();
uint64_t sdk_f_64540(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_64560  (orig 0x64560, call)
extern void callee_5124c0();
uint64_t sdk_f_64560(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5124c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_64590  (orig 0x64590, call)
extern void callee_5124d0();
uint64_t sdk_f_64590(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5124d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_64650  (orig 0x64650, call)
extern void callee_511670();
uint64_t sdk_f_64650(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_64670  (orig 0x64670, call)
extern void callee_512500();
uint64_t sdk_f_64670(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(41)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_646a0  (orig 0x646a0, call)
extern void callee_512480();
uint64_t sdk_f_646a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_646c0  (orig 0x646c0, call)
extern void callee_512480();
uint64_t sdk_f_646c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512480)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(52)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_646e0  (orig 0x646e0, ptr_add)
void* sdk_f_646e0(void* a0) { return (char*)a0 + 8; }

// sub_646f0  (orig 0x646f0, straight)
void* sdk_f_646f0(void* a0) { return (char*)(a0) - 24; }

// sub_64820  (orig 0x64820, ptr_add)
void* sdk_f_64820(void* a0) { return (char*)a0 + 32; }

// sub_64880  (orig 0x64880, call)
extern void callee_512520();
uint64_t sdk_f_64880(void* a0, uint32_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_648b0  (orig 0x648b0, call)
extern void callee_512530();
uint64_t sdk_f_648b0(void* a0, uint32_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512530)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_64930  (orig 0x64930, ptr_add)
void* sdk_f_64930(void* a0) { return (char*)a0 + 8; }

// sub_64940  (orig 0x64940, straight)
void* sdk_f_64940(void* a0) { return (char*)(a0) - 24; }

// sub_65bd0  (orig 0x65bd0, ptr_add)
void* sdk_f_65bd0(void* a0) { return (char*)a0 + 32; }

// sub_65be0  (orig 0x65be0, call)
extern void callee_5124c0();
uint64_t sdk_f_65be0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5124c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (4))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_65d60  (orig 0x65d60, ptr_add)
void* sdk_f_65d60(void* a0) { return (char*)a0 + 8; }

// sub_65d70  (orig 0x65d70, straight)
void* sdk_f_65d70(void* a0) { return (char*)(a0) - 24; }

// sub_65eb0  (orig 0x65eb0, ptr_add)
void* sdk_f_65eb0(void* a0) { return (char*)a0 + 32; }

// sub_66050  (orig 0x66050, ptr_add)
void* sdk_f_66050(void* a0) { return (char*)a0 + 8; }

// sub_66060  (orig 0x66060, straight)
void* sdk_f_66060(void* a0) { return (char*)(a0) - 24; }

// sub_66230  (orig 0x66230, ptr_add)
void* sdk_f_66230(void* a0) { return (char*)a0 + 32; }

// sub_66460  (orig 0x66460, ptr_add)
void* sdk_f_66460(void* a0) { return (char*)a0 + 8; }

// sub_66470  (orig 0x66470, straight)
void* sdk_f_66470(void* a0) { return (char*)(a0) - 24; }

// sub_666e0  (orig 0x666e0, ptr_add)
void* sdk_f_666e0(void* a0) { return (char*)a0 + 32; }

// sub_66880  (orig 0x66880, ptr_add)
void* sdk_f_66880(void* a0) { return (char*)a0 + 8; }

// sub_66890  (orig 0x66890, straight)
void* sdk_f_66890(void* a0) { return (char*)(a0) - 24; }

// sub_66ec0  (orig 0x66ec0, ptr_add)
void* sdk_f_66ec0(void* a0) { return (char*)a0 + 32; }

// sub_66f80  (orig 0x66f80, ptr_add)
void* sdk_f_66f80(void* a0) { return (char*)a0 + 8; }

// sub_66f90  (orig 0x66f90, straight)
void* sdk_f_66f90(void* a0) { return (char*)(a0) - 24; }

// sub_670d0  (orig 0x670d0, ptr_add)
void* sdk_f_670d0(void* a0) { return (char*)a0 + 32; }

// sub_67270  (orig 0x67270, ptr_add)
void* sdk_f_67270(void* a0) { return (char*)a0 + 8; }

// sub_67280  (orig 0x67280, straight)
void* sdk_f_67280(void* a0) { return (char*)(a0) - 24; }

// sub_674a0  (orig 0x674a0, ptr_add)
void* sdk_f_674a0(void* a0) { return (char*)a0 + 16; }

// sub_67a20  (orig 0x67a20, ptr_add)
void* sdk_f_67a20(void* a0) { return (char*)a0 + 8; }

// sub_67a30  (orig 0x67a30, straight)
void* sdk_f_67a30(void* a0) { return (char*)(a0) - 8; }

// sub_67d90  (orig 0x67d90, ptr_add)
void* sdk_f_67d90(void* a0) { return (char*)a0 + 16; }

// sub_68520  (orig 0x68520, ptr_add)
void* sdk_f_68520(void* a0) { return (char*)a0 + 8; }

// sub_68530  (orig 0x68530, straight)
void* sdk_f_68530(void* a0) { return (char*)(a0) - 8; }

// sub_68840  (orig 0x68840, ptr_add)
void* sdk_f_68840(void* a0) { return (char*)a0 + 16; }

// sub_68870  (orig 0x68870, call)
extern void callee_5126e0();
uint64_t sdk_f_68870(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68890  (orig 0x68890, call)
extern void callee_5126f0();
uint64_t sdk_f_68890(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_688b0  (orig 0x688b0, call)
extern void callee_512700();
uint64_t sdk_f_688b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_688d0  (orig 0x688d0, call)
extern void callee_512700();
uint64_t sdk_f_688d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_688f0  (orig 0x688f0, call)
extern void callee_512710();
uint64_t sdk_f_688f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68910  (orig 0x68910, call)
extern void callee_5126e0();
uint64_t sdk_f_68910(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68930  (orig 0x68930, call)
extern void callee_512710();
uint64_t sdk_f_68930(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68950  (orig 0x68950, call)
extern void callee_512710();
uint64_t sdk_f_68950(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68970  (orig 0x68970, call)
extern void callee_512710();
uint64_t sdk_f_68970(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68990  (orig 0x68990, call)
extern void callee_512700();
uint64_t sdk_f_68990(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_689b0  (orig 0x689b0, call)
extern void callee_512700();
uint64_t sdk_f_689b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_689d0  (orig 0x689d0, call)
extern void callee_512700();
uint64_t sdk_f_689d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_689f0  (orig 0x689f0, call)
extern void callee_5126d0();
uint64_t sdk_f_689f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68c60  (orig 0x68c60, call)
extern void callee_512750();
uint64_t sdk_f_68c60(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512750)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68c80  (orig 0x68c80, call)
extern void callee_512710();
uint64_t sdk_f_68c80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68ca0  (orig 0x68ca0, call)
extern void callee_512760();
uint64_t sdk_f_68ca0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68cd0  (orig 0x68cd0, call)
extern void callee_512760();
uint64_t sdk_f_68cd0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(52)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68d00  (orig 0x68d00, call)
extern void callee_512700();
uint64_t sdk_f_68d00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(53)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68d20  (orig 0x68d20, call)
extern void callee_512700();
uint64_t sdk_f_68d20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(54)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68d40  (orig 0x68d40, call)
extern void callee_512710();
uint64_t sdk_f_68d40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(55)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68d60  (orig 0x68d60, call)
extern void callee_512770();
uint64_t sdk_f_68d60(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512770)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68d80  (orig 0x68d80, call)
extern void callee_5126d0();
uint64_t sdk_f_68d80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(61)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68da0  (orig 0x68da0, call)
extern void callee_5126e0();
uint64_t sdk_f_68da0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(62)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68dc0  (orig 0x68dc0, call)
extern void callee_5126d0();
uint64_t sdk_f_68dc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(63)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68de0  (orig 0x68de0, call)
extern void callee_512780();
uint64_t sdk_f_68de0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(64)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68e10  (orig 0x68e10, call)
extern void callee_512790();
uint64_t sdk_f_68e10(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512790)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68e40  (orig 0x68e40, call)
extern void callee_512780();
uint64_t sdk_f_68e40(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(66)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68e70  (orig 0x68e70, call)
extern void callee_512780();
uint64_t sdk_f_68e70(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68ea0  (orig 0x68ea0, call)
extern void callee_512760();
uint64_t sdk_f_68ea0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(90)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68ed0  (orig 0x68ed0, call)
extern void callee_5126e0();
uint64_t sdk_f_68ed0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(91)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68ef0  (orig 0x68ef0, call)
extern void callee_5126e0();
uint64_t sdk_f_68ef0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_68f10  (orig 0x68f10, ptr_add)
void* sdk_f_68f10(void* a0) { return (char*)a0 + 8; }

// sub_68f20  (orig 0x68f20, straight)
void* sdk_f_68f20(void* a0) { return (char*)(a0) - 8; }

// sub_694a0  (orig 0x694a0, ptr_add)
void* sdk_f_694a0(void* a0) { return (char*)a0 + 16; }

// sub_694b0  (orig 0x694b0, call)
extern void callee_5127a0();
uint64_t sdk_f_694b0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5127a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_694e0  (orig 0x694e0, call)
extern void callee_512700();
uint64_t sdk_f_694e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69500  (orig 0x69500, call)
extern void callee_5126d0();
uint64_t sdk_f_69500(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69520  (orig 0x69520, ptr_add)
void* sdk_f_69520(void* a0) { return (char*)a0 + 8; }

// sub_69530  (orig 0x69530, straight)
void* sdk_f_69530(void* a0) { return (char*)(a0) - 8; }

// sub_69e90  (orig 0x69e90, ptr_add)
void* sdk_f_69e90(void* a0) { return (char*)a0 + 16; }

// sub_69ec0  (orig 0x69ec0, call)
extern void callee_512700();
uint64_t sdk_f_69ec0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69ee0  (orig 0x69ee0, call)
extern void callee_512700();
uint64_t sdk_f_69ee0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69f00  (orig 0x69f00, call)
extern void callee_512700();
uint64_t sdk_f_69f00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69f20  (orig 0x69f20, call)
extern void callee_512700();
uint64_t sdk_f_69f20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69f40  (orig 0x69f40, call)
extern void callee_5126d0();
uint64_t sdk_f_69f40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69f60  (orig 0x69f60, call)
extern void callee_512780();
uint64_t sdk_f_69f60(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69f90  (orig 0x69f90, call)
extern void callee_512760();
uint64_t sdk_f_69f90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69fc0  (orig 0x69fc0, call)
extern void callee_512760();
uint64_t sdk_f_69fc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_69ff0  (orig 0x69ff0, call)
extern void callee_5127b0();
uint64_t sdk_f_69ff0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5127b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a020  (orig 0x6a020, call)
extern void callee_512760();
uint64_t sdk_f_6a020(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a050  (orig 0x6a050, call)
extern void callee_5127c0();
uint64_t sdk_f_6a050(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a070  (orig 0x6a070, call)
extern void callee_512760();
uint64_t sdk_f_6a070(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a0a0  (orig 0x6a0a0, call)
extern void callee_512760();
uint64_t sdk_f_6a0a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a0d0  (orig 0x6a0d0, call)
extern void callee_512760();
uint64_t sdk_f_6a0d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a100  (orig 0x6a100, call)
extern void callee_512780();
uint64_t sdk_f_6a100(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a130  (orig 0x6a130, call)
extern void callee_512780();
uint64_t sdk_f_6a130(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a160  (orig 0x6a160, call)
extern void callee_5127d0();
uint64_t sdk_f_6a160(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a180  (orig 0x6a180, call)
extern void callee_512700();
uint64_t sdk_f_6a180(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(41)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a1a0  (orig 0x6a1a0, call)
extern void callee_5127e0();
uint64_t sdk_f_6a1a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5127e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(42)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a1c0  (orig 0x6a1c0, call)
extern void callee_5127d0();
uint64_t sdk_f_6a1c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(43)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a1e0  (orig 0x6a1e0, call)
extern void callee_512760();
uint64_t sdk_f_6a1e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a210  (orig 0x6a210, call)
extern void callee_512700();
uint64_t sdk_f_6a210(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a230  (orig 0x6a230, call)
extern void callee_5127f0();
uint64_t sdk_f_6a230(void* a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5127f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a260  (orig 0x6a260, call)
extern void callee_512760();
uint64_t sdk_f_6a260(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(61)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a290  (orig 0x6a290, call)
extern void callee_512780();
uint64_t sdk_f_6a290(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(62)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a2c0  (orig 0x6a2c0, call)
extern void callee_5126e0();
uint64_t sdk_f_6a2c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(63)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a2e0  (orig 0x6a2e0, call)
extern void callee_512780();
uint64_t sdk_f_6a2e0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(64)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a310  (orig 0x6a310, call)
extern void callee_512700();
uint64_t sdk_f_6a310(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a330  (orig 0x6a330, call)
extern void callee_5126e0();
uint64_t sdk_f_6a330(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(66)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a350  (orig 0x6a350, call)
extern void callee_512710();
uint64_t sdk_f_6a350(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(67)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a370  (orig 0x6a370, call)
extern void callee_512760();
uint64_t sdk_f_6a370(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(68)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a3a0  (orig 0x6a3a0, call)
extern void callee_512710();
uint64_t sdk_f_6a3a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(69)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a3c0  (orig 0x6a3c0, call)
extern void callee_512800();
uint64_t sdk_f_6a3c0(void* a0, uint32_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512800)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(70)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a3f0  (orig 0x6a3f0, call)
extern void callee_512810();
uint64_t sdk_f_6a3f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512810)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(71)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a410  (orig 0x6a410, call)
extern void callee_512780();
uint64_t sdk_f_6a410(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a440  (orig 0x6a440, call)
extern void callee_5127d0();
uint64_t sdk_f_6a440(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(90)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a460  (orig 0x6a460, call)
extern void callee_5126d0();
uint64_t sdk_f_6a460(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(91)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a480  (orig 0x6a480, call)
extern void callee_512760();
uint64_t sdk_f_6a480(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6a550  (orig 0x6a550, ptr_add)
void* sdk_f_6a550(void* a0) { return (char*)a0 + 8; }

// sub_6a560  (orig 0x6a560, straight)
void* sdk_f_6a560(void* a0) { return (char*)(a0) - 8; }

// sub_6aef0  (orig 0x6aef0, ptr_add)
void* sdk_f_6aef0(void* a0) { return (char*)a0 + 16; }

// sub_6b040  (orig 0x6b040, call)
extern void callee_5126d0();
uint64_t sdk_f_6b040(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6b060  (orig 0x6b060, call)
extern void callee_512700();
uint64_t sdk_f_6b060(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6b080  (orig 0x6b080, ptr_add)
void* sdk_f_6b080(void* a0) { return (char*)a0 + 8; }

// sub_6b090  (orig 0x6b090, straight)
void* sdk_f_6b090(void* a0) { return (char*)(a0) - 8; }

// sub_6b210  (orig 0x6b210, ptr_add)
void* sdk_f_6b210(void* a0) { return (char*)a0 + 16; }

// sub_6b380  (orig 0x6b380, ptr_add)
void* sdk_f_6b380(void* a0) { return (char*)a0 + 8; }

// sub_6b390  (orig 0x6b390, straight)
void* sdk_f_6b390(void* a0) { return (char*)(a0) - 8; }

// sub_6b510  (orig 0x6b510, ptr_add)
void* sdk_f_6b510(void* a0) { return (char*)a0 + 16; }

// sub_6b540  (orig 0x6b540, call)
extern void callee_512860();
uint64_t sdk_f_6b540(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512860)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6b570  (orig 0x6b570, call)
extern void callee_512870();
uint64_t sdk_f_6b570(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512870)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6b5a0  (orig 0x6b5a0, ptr_add)
void* sdk_f_6b5a0(void* a0) { return (char*)a0 + 8; }

// sub_6b5b0  (orig 0x6b5b0, straight)
void* sdk_f_6b5b0(void* a0) { return (char*)(a0) - 8; }

// sub_6bb50  (orig 0x6bb50, ptr_add)
void* sdk_f_6bb50(void* a0) { return (char*)a0 + 16; }

// sub_6bb80  (orig 0x6bb80, call)
extern void callee_512880();
uint64_t sdk_f_6bb80(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512880)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6bba0  (orig 0x6bba0, ptr_add)
void* sdk_f_6bba0(void* a0) { return (char*)a0 + 8; }

// sub_6bbb0  (orig 0x6bbb0, straight)
void* sdk_f_6bbb0(void* a0) { return (char*)(a0) - 8; }

// sub_6be70  (orig 0x6be70, ptr_add)
void* sdk_f_6be70(void* a0) { return (char*)a0 + 16; }

// sub_6bf30  (orig 0x6bf30, call)
extern void callee_5127d0();
uint64_t sdk_f_6bf30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6bf50  (orig 0x6bf50, call)
extern void callee_5127d0();
uint64_t sdk_f_6bf50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6bf70  (orig 0x6bf70, call)
extern void callee_512700();
uint64_t sdk_f_6bf70(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6bf90  (orig 0x6bf90, call)
extern void callee_512700();
uint64_t sdk_f_6bf90(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6bfb0  (orig 0x6bfb0, call)
extern void callee_512700();
uint64_t sdk_f_6bfb0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6bfd0  (orig 0x6bfd0, call)
extern void callee_512760();
uint64_t sdk_f_6bfd0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c000  (orig 0x6c000, call)
extern void callee_5128a0();
uint64_t sdk_f_6c000(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c020  (orig 0x6c020, ptr_add)
void* sdk_f_6c020(void* a0) { return (char*)a0 + 8; }

// sub_6c030  (orig 0x6c030, straight)
void* sdk_f_6c030(void* a0) { return (char*)(a0) - 8; }

// sub_6c1b0  (orig 0x6c1b0, ptr_add)
void* sdk_f_6c1b0(void* a0) { return (char*)a0 + 16; }

// sub_6c1c0  (orig 0x6c1c0, ptr_add)
void* sdk_f_6c1c0(void* a0) { return (char*)a0 + 8; }

// sub_6c1d0  (orig 0x6c1d0, straight)
void* sdk_f_6c1d0(void* a0) { return (char*)(a0) - 8; }

// sub_6c350  (orig 0x6c350, ptr_add)
void* sdk_f_6c350(void* a0) { return (char*)a0 + 16; }

// sub_6c390  (orig 0x6c390, call)
extern void callee_5126e0();
uint64_t sdk_f_6c390(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c3b0  (orig 0x6c3b0, call)
extern void callee_5126e0();
uint64_t sdk_f_6c3b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c430  (orig 0x6c430, ptr_add)
void* sdk_f_6c430(void* a0) { return (char*)a0 + 8; }

// sub_6c440  (orig 0x6c440, straight)
void* sdk_f_6c440(void* a0) { return (char*)(a0) - 8; }

// sub_6c7d0  (orig 0x6c7d0, ptr_add)
void* sdk_f_6c7d0(void* a0) { return (char*)a0 + 16; }

// sub_6c810  (orig 0x6c810, call)
extern void callee_512700();
uint64_t sdk_f_6c810(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c830  (orig 0x6c830, call)
extern void callee_5128d0();
uint64_t sdk_f_6c830(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c860  (orig 0x6c860, call)
extern void callee_5128d0();
uint64_t sdk_f_6c860(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c890  (orig 0x6c890, call)
extern void callee_512700();
uint64_t sdk_f_6c890(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c8b0  (orig 0x6c8b0, call)
extern void callee_5128e0();
uint64_t sdk_f_6c8b0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c8e0  (orig 0x6c8e0, call)
extern void callee_5128e0();
uint64_t sdk_f_6c8e0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c910  (orig 0x6c910, call)
extern void callee_5128e0();
uint64_t sdk_f_6c910(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c940  (orig 0x6c940, call)
extern void callee_5128f0();
uint64_t sdk_f_6c940(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c970  (orig 0x6c970, call)
extern void callee_5128b0();
uint64_t sdk_f_6c970(void* a0, uint32_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c9a0  (orig 0x6c9a0, call)
extern void callee_5126d0();
uint64_t sdk_f_6c9a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c9c0  (orig 0x6c9c0, call)
extern void callee_512700();
uint64_t sdk_f_6c9c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6c9e0  (orig 0x6c9e0, call)
extern void callee_5126d0();
uint64_t sdk_f_6c9e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ca00  (orig 0x6ca00, call)
extern void callee_512700();
uint64_t sdk_f_6ca00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ca20  (orig 0x6ca20, call)
extern void callee_5126d0();
uint64_t sdk_f_6ca20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ca40  (orig 0x6ca40, call)
extern void callee_512700();
uint64_t sdk_f_6ca40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ca60  (orig 0x6ca60, call)
extern void callee_512900();
uint64_t sdk_f_6ca60(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512900)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ca80  (orig 0x6ca80, call)
extern void callee_512900();
uint64_t sdk_f_6ca80(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512900)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6caa0  (orig 0x6caa0, call)
extern void callee_512900();
uint64_t sdk_f_6caa0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512900)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6cac0  (orig 0x6cac0, call)
extern void callee_512910();
uint64_t sdk_f_6cac0(void* a0, uint32_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512910)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6caf0  (orig 0x6caf0, call)
extern void callee_512780();
uint64_t sdk_f_6caf0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6cb20  (orig 0x6cb20, call)
extern void callee_512920();
uint64_t sdk_f_6cb20(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512920)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6cb40  (orig 0x6cb40, call)
extern void callee_512700();
uint64_t sdk_f_6cb40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6cb60  (orig 0x6cb60, call)
extern void callee_512920();
uint64_t sdk_f_6cb60(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512920)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6cb80  (orig 0x6cb80, call)
extern void callee_512700();
uint64_t sdk_f_6cb80(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6cba0  (orig 0x6cba0, call)
extern void callee_512920();
uint64_t sdk_f_6cba0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512920)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(26)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6cbc0  (orig 0x6cbc0, call)
extern void callee_512700();
uint64_t sdk_f_6cbc0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(27)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6cbe0  (orig 0x6cbe0, call)
extern void callee_512930();
uint64_t sdk_f_6cbe0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512930)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(28)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6cc10  (orig 0x6cc10, ptr_add)
void* sdk_f_6cc10(void* a0) { return (char*)a0 + 8; }

// sub_6cc20  (orig 0x6cc20, straight)
void* sdk_f_6cc20(void* a0) { return (char*)(a0) - 8; }

// sub_6d4d0  (orig 0x6d4d0, ptr_add)
void* sdk_f_6d4d0(void* a0) { return (char*)a0 + 16; }

// sub_6d5b0  (orig 0x6d5b0, call)
extern void callee_512780();
uint64_t sdk_f_6d5b0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d5e0  (orig 0x6d5e0, call)
extern void callee_512700();
uint64_t sdk_f_6d5e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d640  (orig 0x6d640, call)
extern void callee_512960();
uint64_t sdk_f_6d640(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512960)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d660  (orig 0x6d660, call)
extern void callee_512780();
uint64_t sdk_f_6d660(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d690  (orig 0x6d690, ptr_add)
void* sdk_f_6d690(void* a0) { return (char*)a0 + 8; }

// sub_6d6a0  (orig 0x6d6a0, straight)
void* sdk_f_6d6a0(void* a0) { return (char*)(a0) - 8; }

// sub_6d820  (orig 0x6d820, ptr_add)
void* sdk_f_6d820(void* a0) { return (char*)a0 + 16; }

// sub_6d870  (orig 0x6d870, call)
extern void callee_512710();
uint64_t sdk_f_6d870(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d890  (orig 0x6d890, call)
extern void callee_512700();
uint64_t sdk_f_6d890(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d8b0  (orig 0x6d8b0, call)
extern void callee_512700();
uint64_t sdk_f_6d8b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d8d0  (orig 0x6d8d0, call)
extern void callee_512700();
uint64_t sdk_f_6d8d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d8f0  (orig 0x6d8f0, call)
extern void callee_512700();
uint64_t sdk_f_6d8f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d910  (orig 0x6d910, call)
extern void callee_512700();
uint64_t sdk_f_6d910(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d930  (orig 0x6d930, call)
extern void callee_512700();
uint64_t sdk_f_6d930(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6d950  (orig 0x6d950, call)
extern void callee_512710();
uint64_t sdk_f_6d950(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(111)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6da10  (orig 0x6da10, call)
extern void callee_5127d0();
uint64_t sdk_f_6da10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6da80  (orig 0x6da80, call)
extern void callee_5128d0();
uint64_t sdk_f_6da80(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(122)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6dab0  (orig 0x6dab0, call)
extern void callee_5128d0();
uint64_t sdk_f_6dab0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(123)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6dae0  (orig 0x6dae0, call)
extern void callee_512990();
uint64_t sdk_f_6dae0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512990)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(124)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6db30  (orig 0x6db30, call)
extern void callee_512710();
uint64_t sdk_f_6db30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(131)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6db50  (orig 0x6db50, call)
extern void callee_5127d0();
uint64_t sdk_f_6db50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(132)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6db70  (orig 0x6db70, call)
extern void callee_5129b0();
uint64_t sdk_f_6db70(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5129b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (4))), ((uintptr_t)(140)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6dba0  (orig 0x6dba0, call)
extern void callee_512700();
uint64_t sdk_f_6dba0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(150)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6dbc0  (orig 0x6dbc0, ptr_add)
void* sdk_f_6dbc0(void* a0) { return (char*)a0 + 8; }

// sub_6dbd0  (orig 0x6dbd0, straight)
void* sdk_f_6dbd0(void* a0) { return (char*)(a0) - 8; }

// sub_6dd50  (orig 0x6dd50, ptr_add)
void* sdk_f_6dd50(void* a0) { return (char*)a0 + 16; }

// sub_6dda0  (orig 0x6dda0, call)
extern void callee_512710();
uint64_t sdk_f_6dda0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ddc0  (orig 0x6ddc0, call)
extern void callee_512700();
uint64_t sdk_f_6ddc0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6dde0  (orig 0x6dde0, call)
extern void callee_512700();
uint64_t sdk_f_6dde0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6de00  (orig 0x6de00, call)
extern void callee_512700();
uint64_t sdk_f_6de00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6de20  (orig 0x6de20, call)
extern void callee_512700();
uint64_t sdk_f_6de20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6de40  (orig 0x6de40, ptr_add)
void* sdk_f_6de40(void* a0) { return (char*)a0 + 8; }

// sub_6de50  (orig 0x6de50, straight)
void* sdk_f_6de50(void* a0) { return (char*)(a0) - 8; }

// sub_6e820  (orig 0x6e820, ptr_add)
void* sdk_f_6e820(void* a0) { return (char*)a0 + 16; }

// sub_6e9e0  (orig 0x6e9e0, call)
extern void callee_512700();
uint64_t sdk_f_6e9e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ea00  (orig 0x6ea00, call)
extern void callee_512700();
uint64_t sdk_f_6ea00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6eac0  (orig 0x6eac0, ptr_add)
void* sdk_f_6eac0(void* a0) { return (char*)a0 + 8; }

// sub_6ead0  (orig 0x6ead0, straight)
void* sdk_f_6ead0(void* a0) { return (char*)(a0) - 8; }

// sub_6ed60  (orig 0x6ed60, ptr_add)
void* sdk_f_6ed60(void* a0) { return (char*)a0 + 16; }

// sub_6edb0  (orig 0x6edb0, call)
extern void callee_512710();
uint64_t sdk_f_6edb0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6edd0  (orig 0x6edd0, call)
extern void callee_512700();
uint64_t sdk_f_6edd0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6edf0  (orig 0x6edf0, call)
extern void callee_512700();
uint64_t sdk_f_6edf0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ee10  (orig 0x6ee10, call)
extern void callee_512700();
uint64_t sdk_f_6ee10(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ee30  (orig 0x6ee30, call)
extern void callee_512700();
uint64_t sdk_f_6ee30(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6ee50  (orig 0x6ee50, call)
extern void callee_512760();
uint64_t sdk_f_6ee50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6f0b0  (orig 0x6f0b0, call)
extern void callee_5126d0();
uint64_t sdk_f_6f0b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(105)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6f0d0  (orig 0x6f0d0, call)
extern void callee_5126d0();
uint64_t sdk_f_6f0d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(106)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6f0f0  (orig 0x6f0f0, call)
extern void callee_512710();
uint64_t sdk_f_6f0f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6f110  (orig 0x6f110, call)
extern void callee_5126f0();
uint64_t sdk_f_6f110(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6f130  (orig 0x6f130, call)
extern void callee_512700();
uint64_t sdk_f_6f130(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(150)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6f150  (orig 0x6f150, call)
extern void callee_5129e0();
uint64_t sdk_f_6f150(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5129e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(160)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6f170  (orig 0x6f170, ptr_add)
void* sdk_f_6f170(void* a0) { return (char*)a0 + 8; }

// sub_6f180  (orig 0x6f180, straight)
void* sdk_f_6f180(void* a0) { return (char*)(a0) - 8; }

// sub_6f420  (orig 0x6f420, ptr_add)
void* sdk_f_6f420(void* a0) { return (char*)a0 + 16; }

// sub_6f4e0  (orig 0x6f4e0, call)
extern void callee_512700();
uint64_t sdk_f_6f4e0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6f500  (orig 0x6f500, call)
extern void callee_512710();
uint64_t sdk_f_6f500(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_6f740  (orig 0x6f740, ptr_add)
void* sdk_f_6f740(void* a0) { return (char*)a0 + 8; }

// sub_6f750  (orig 0x6f750, straight)
void* sdk_f_6f750(void* a0) { return (char*)(a0) - 8; }

// sub_6ffe0  (orig 0x6ffe0, ptr_add)
void* sdk_f_6ffe0(void* a0) { return (char*)a0 + 16; }

// sub_6fff0  (orig 0x6fff0, call)
extern void callee_512700();
uint64_t sdk_f_6fff0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70010  (orig 0x70010, call)
extern void callee_512700();
uint64_t sdk_f_70010(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70030  (orig 0x70030, call)
extern void callee_512700();
uint64_t sdk_f_70030(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_700f0  (orig 0x700f0, call)
extern void callee_5126d0();
uint64_t sdk_f_700f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70260  (orig 0x70260, call)
extern void callee_512a30();
uint64_t sdk_f_70260(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512a30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (4))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70290  (orig 0x70290, ptr_add)
void* sdk_f_70290(void* a0) { return (char*)a0 + 8; }

// sub_702a0  (orig 0x702a0, straight)
void* sdk_f_702a0(void* a0) { return (char*)(a0) - 8; }

// sub_705f0  (orig 0x705f0, ptr_add)
void* sdk_f_705f0(void* a0) { return (char*)a0 + 16; }

// sub_70620  (orig 0x70620, call)
extern void callee_512700();
uint64_t sdk_f_70620(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70640  (orig 0x70640, call)
extern void callee_512760();
uint64_t sdk_f_70640(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70670  (orig 0x70670, call)
extern void callee_512700();
uint64_t sdk_f_70670(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70690  (orig 0x70690, call)
extern void callee_512700();
uint64_t sdk_f_70690(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_706b0  (orig 0x706b0, call)
extern void callee_512710();
uint64_t sdk_f_706b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_706d0  (orig 0x706d0, call)
extern void callee_512700();
uint64_t sdk_f_706d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_706f0  (orig 0x706f0, call)
extern void callee_512700();
uint64_t sdk_f_706f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70710  (orig 0x70710, call)
extern void callee_5128a0();
uint64_t sdk_f_70710(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70730  (orig 0x70730, call)
extern void callee_512700();
uint64_t sdk_f_70730(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70750  (orig 0x70750, call)
extern void callee_512710();
uint64_t sdk_f_70750(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70770  (orig 0x70770, call)
extern void callee_5126d0();
uint64_t sdk_f_70770(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70790  (orig 0x70790, ptr_add)
void* sdk_f_70790(void* a0) { return (char*)a0 + 8; }

// sub_707a0  (orig 0x707a0, straight)
void* sdk_f_707a0(void* a0) { return (char*)(a0) - 8; }

// sub_70920  (orig 0x70920, ptr_add)
void* sdk_f_70920(void* a0) { return (char*)a0 + 16; }

// sub_70bd0  (orig 0x70bd0, ptr_add)
void* sdk_f_70bd0(void* a0) { return (char*)a0 + 8; }

// sub_70be0  (orig 0x70be0, straight)
void* sdk_f_70be0(void* a0) { return (char*)(a0) - 8; }

// sub_70d60  (orig 0x70d60, ptr_add)
void* sdk_f_70d60(void* a0) { return (char*)a0 + 16; }

// sub_70d70  (orig 0x70d70, call)
extern void callee_512a40();
uint64_t sdk_f_70d70(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512a40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70da0  (orig 0x70da0, call)
extern void callee_512860();
uint64_t sdk_f_70da0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512860)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_70dd0  (orig 0x70dd0, ptr_add)
void* sdk_f_70dd0(void* a0) { return (char*)a0 + 8; }

// sub_70de0  (orig 0x70de0, straight)
void* sdk_f_70de0(void* a0) { return (char*)(a0) - 8; }

// sub_71180  (orig 0x71180, ptr_add)
void* sdk_f_71180(void* a0) { return (char*)a0 + 16; }

// sub_717d0  (orig 0x717d0, ptr_add)
void* sdk_f_717d0(void* a0) { return (char*)a0 + 8; }

// sub_717e0  (orig 0x717e0, straight)
void* sdk_f_717e0(void* a0) { return (char*)(a0) - 8; }

// sub_71960  (orig 0x71960, ptr_add)
void* sdk_f_71960(void* a0) { return (char*)a0 + 16; }

// sub_71b50  (orig 0x71b50, call)
extern void callee_5126d0();
uint64_t sdk_f_71b50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71b70  (orig 0x71b70, call)
extern void callee_5126d0();
uint64_t sdk_f_71b70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71b90  (orig 0x71b90, call)
extern void callee_512700();
uint64_t sdk_f_71b90(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71bb0  (orig 0x71bb0, call)
extern void callee_5126f0();
uint64_t sdk_f_71bb0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71bd0  (orig 0x71bd0, call)
extern void callee_512990();
uint64_t sdk_f_71bd0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512990)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71bf0  (orig 0x71bf0, call)
extern void callee_512710();
uint64_t sdk_f_71bf0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71c10  (orig 0x71c10, call)
extern void callee_512990();
uint64_t sdk_f_71c10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512990)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71c30  (orig 0x71c30, call)
extern void callee_512a60();
uint64_t sdk_f_71c30(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512a60)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(16384)), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71c60  (orig 0x71c60, call)
extern void callee_512710();
uint64_t sdk_f_71c60(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71c80  (orig 0x71c80, call)
extern void callee_5129b0();
uint64_t sdk_f_71c80(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5129b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (4))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71cb0  (orig 0x71cb0, call)
extern void callee_512990();
uint64_t sdk_f_71cb0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512990)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71cd0  (orig 0x71cd0, call)
extern void callee_5126e0();
uint64_t sdk_f_71cd0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71d90  (orig 0x71d90, call)
extern void callee_5126d0();
uint64_t sdk_f_71d90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71e50  (orig 0x71e50, call)
extern void callee_5127d0();
uint64_t sdk_f_71e50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71e70  (orig 0x71e70, call)
extern void callee_512a70();
uint64_t sdk_f_71e70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512a70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71e90  (orig 0x71e90, call)
extern void callee_512a80();
uint64_t sdk_f_71e90(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512a80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(512)), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71ec0  (orig 0x71ec0, call)
extern void callee_512a90();
uint64_t sdk_f_71ec0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512a90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_71ee0  (orig 0x71ee0, call)
extern void callee_512700();
uint64_t sdk_f_71ee0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_72000  (orig 0x72000, call)
extern void callee_512700();
uint64_t sdk_f_72000(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_72020  (orig 0x72020, call)
extern void callee_512700();
uint64_t sdk_f_72020(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(102)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_72040  (orig 0x72040, call)
extern void callee_512ac0();
uint64_t sdk_f_72040(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512ac0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (4))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_72070  (orig 0x72070, ptr_add)
void* sdk_f_72070(void* a0) { return (char*)a0 + 8; }

// sub_72080  (orig 0x72080, straight)
void* sdk_f_72080(void* a0) { return (char*)(a0) - 8; }

// sub_72860  (orig 0x72860, ptr_add)
void* sdk_f_72860(void* a0) { return (char*)a0 + 16; }

// sub_72870  (orig 0x72870, call)
extern void callee_512ad0();
uint64_t sdk_f_72870(void* a0, uint64_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512ad0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_728a0  (orig 0x728a0, call)
extern void callee_512ae0();
uint64_t sdk_f_728a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512ae0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_728c0  (orig 0x728c0, call)
extern void callee_5126d0();
uint64_t sdk_f_728c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_728e0  (orig 0x728e0, call)
extern void callee_512af0();
uint64_t sdk_f_728e0(void* a0, void* a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512af0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_72920  (orig 0x72920, ptr_add)
void* sdk_f_72920(void* a0) { return (char*)a0 + 8; }

// sub_72930  (orig 0x72930, straight)
void* sdk_f_72930(void* a0) { return (char*)(a0) - 8; }

// sub_73320  (orig 0x73320, ptr_add)
void* sdk_f_73320(void* a0) { return (char*)a0 + 16; }

// sub_73970  (orig 0x73970, ptr_add)
void* sdk_f_73970(void* a0) { return (char*)a0 + 8; }

// sub_73980  (orig 0x73980, straight)
void* sdk_f_73980(void* a0) { return (char*)(a0) - 8; }

// sub_73b00  (orig 0x73b00, ptr_add)
void* sdk_f_73b00(void* a0) { return (char*)a0 + 16; }

// sub_73b30  (orig 0x73b30, call)
extern void callee_512700();
uint64_t sdk_f_73b30(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73b50  (orig 0x73b50, call)
extern void callee_5127d0();
uint64_t sdk_f_73b50(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73b70  (orig 0x73b70, call)
extern void callee_5128a0();
uint64_t sdk_f_73b70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73b90  (orig 0x73b90, call)
extern void callee_512760();
uint64_t sdk_f_73b90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73bc0  (orig 0x73bc0, call)
extern void callee_512780();
uint64_t sdk_f_73bc0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73bf0  (orig 0x73bf0, call)
extern void callee_512760();
uint64_t sdk_f_73bf0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73c20  (orig 0x73c20, call)
extern void callee_512700();
uint64_t sdk_f_73c20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73c40  (orig 0x73c40, call)
extern void callee_512700();
uint64_t sdk_f_73c40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73c60  (orig 0x73c60, call)
extern void callee_512760();
uint64_t sdk_f_73c60(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(90)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73c90  (orig 0x73c90, call)
extern void callee_512700();
uint64_t sdk_f_73c90(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(101)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_73cb0  (orig 0x73cb0, ptr_add)
void* sdk_f_73cb0(void* a0) { return (char*)a0 + 8; }

// sub_73cc0  (orig 0x73cc0, straight)
void* sdk_f_73cc0(void* a0) { return (char*)(a0) - 8; }

// sub_73e40  (orig 0x73e40, ptr_add)
void* sdk_f_73e40(void* a0) { return (char*)a0 + 16; }

// sub_743f0  (orig 0x743f0, ptr_add)
void* sdk_f_743f0(void* a0) { return (char*)a0 + 8; }

// sub_74400  (orig 0x74400, straight)
void* sdk_f_74400(void* a0) { return (char*)(a0) - 8; }

// sub_74580  (orig 0x74580, ptr_add)
void* sdk_f_74580(void* a0) { return (char*)a0 + 16; }

// sub_746f0  (orig 0x746f0, call)
extern void callee_5128a0();
uint64_t sdk_f_746f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74710  (orig 0x74710, call)
extern void callee_512b30();
uint64_t sdk_f_74710(void* a0, uint64_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512b30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74790  (orig 0x74790, call)
extern void callee_512b50();
uint64_t sdk_f_74790(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512b50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(32)), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_747c0  (orig 0x747c0, call)
extern void callee_512b60();
uint64_t sdk_f_747c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512b60)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_747e0  (orig 0x747e0, call)
extern void callee_512a90();
uint64_t sdk_f_747e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512a90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74800  (orig 0x74800, call)
extern void callee_512780();
uint64_t sdk_f_74800(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74830  (orig 0x74830, call)
extern void callee_512b70();
uint64_t sdk_f_74830(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512b70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74850  (orig 0x74850, call)
extern void callee_512b80();
uint64_t sdk_f_74850(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512b80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74870  (orig 0x74870, call)
extern void callee_512b90();
uint64_t sdk_f_74870(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512b90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_748a0  (orig 0x748a0, call)
extern void callee_512ba0();
uint64_t sdk_f_748a0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512ba0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (255))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(26)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_748d0  (orig 0x748d0, call)
extern void callee_512bb0();
uint64_t sdk_f_748d0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512bb0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (65535))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(27)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74900  (orig 0x74900, call)
extern void callee_5128a0();
uint64_t sdk_f_74900(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74920  (orig 0x74920, call)
extern void callee_512700();
uint64_t sdk_f_74920(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(31)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74940  (orig 0x74940, call)
extern void callee_5128a0();
uint64_t sdk_f_74940(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74960  (orig 0x74960, call)
extern void callee_512700();
uint64_t sdk_f_74960(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(33)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74980  (orig 0x74980, call)
extern void callee_512710();
uint64_t sdk_f_74980(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_749a0  (orig 0x749a0, call)
extern void callee_512b70();
uint64_t sdk_f_749a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512b70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_749c0  (orig 0x749c0, call)
extern void callee_512760();
uint64_t sdk_f_749c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_749f0  (orig 0x749f0, call)
extern void callee_512710();
uint64_t sdk_f_749f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74a10  (orig 0x74a10, call)
extern void callee_512bc0();
uint64_t sdk_f_74a10(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512bc0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(66)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74a30  (orig 0x74a30, call)
extern void callee_512780();
uint64_t sdk_f_74a30(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(67)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74a60  (orig 0x74a60, call)
extern void callee_512700();
uint64_t sdk_f_74a60(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(68)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74a80  (orig 0x74a80, call)
extern void callee_512700();
uint64_t sdk_f_74a80(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(70)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74aa0  (orig 0x74aa0, call)
extern void callee_512700();
uint64_t sdk_f_74aa0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(71)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74ac0  (orig 0x74ac0, call)
extern void callee_512700();
uint64_t sdk_f_74ac0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(80)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74ae0  (orig 0x74ae0, call)
extern void callee_512760();
uint64_t sdk_f_74ae0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(90)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74b10  (orig 0x74b10, call)
extern void callee_512bd0();
uint64_t sdk_f_74b10(void* a0, uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512bd0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74ba0  (orig 0x74ba0, call)
extern void callee_512760();
uint64_t sdk_f_74ba0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(102)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74bd0  (orig 0x74bd0, call)
extern void callee_512bf0();
uint64_t sdk_f_74bd0(void* a0, uint64_t a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512bf0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(((*(uint64_t*)((char*)(a2) + 8)) + (((*(uint64_t*)((char*)(a2) + 8)) << 1))) << (3))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)((*(uint64_t*)((char*)(a3) + 8)) << (3))), ((uintptr_t)(110)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74c50  (orig 0x74c50, call)
extern void callee_5128c0();
uint64_t sdk_f_74c50(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(120)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74c80  (orig 0x74c80, call)
extern void callee_512700();
uint64_t sdk_f_74c80(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(121)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74cf0  (orig 0x74cf0, call)
extern void callee_5126e0();
uint64_t sdk_f_74cf0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(123)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74d10  (orig 0x74d10, call)
extern void callee_512760();
uint64_t sdk_f_74d10(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(124)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74d40  (orig 0x74d40, call)
extern void callee_512c10();
uint64_t sdk_f_74d40(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(500)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74e10  (orig 0x74e10, call)
extern void callee_512700();
uint64_t sdk_f_74e10(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_74e30  (orig 0x74e30, ptr_add)
void* sdk_f_74e30(void* a0) { return (char*)a0 + 8; }

// sub_74e40  (orig 0x74e40, straight)
void* sdk_f_74e40(void* a0) { return (char*)(a0) - 8; }

// sub_76380  (orig 0x76380, ptr_add)
void* sdk_f_76380(void* a0) { return (char*)a0 + 16; }

// sub_76430  (orig 0x76430, call)
extern void callee_5127d0();
uint64_t sdk_f_76430(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76450  (orig 0x76450, ptr_add)
void* sdk_f_76450(void* a0) { return (char*)a0 + 8; }

// sub_76460  (orig 0x76460, straight)
void* sdk_f_76460(void* a0) { return (char*)(a0) - 8; }

// sub_765e0  (orig 0x765e0, ptr_add)
void* sdk_f_765e0(void* a0) { return (char*)a0 + 16; }

// sub_76690  (orig 0x76690, call)
extern void callee_5128a0();
uint64_t sdk_f_76690(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_766b0  (orig 0x766b0, call)
extern void callee_512c50();
uint64_t sdk_f_766b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_766d0  (orig 0x766d0, call)
extern void callee_5128a0();
uint64_t sdk_f_766d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_766f0  (orig 0x766f0, call)
extern void callee_5128a0();
uint64_t sdk_f_766f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76710  (orig 0x76710, call)
extern void callee_5128a0();
uint64_t sdk_f_76710(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76730  (orig 0x76730, call)
extern void callee_5128a0();
uint64_t sdk_f_76730(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76750  (orig 0x76750, call)
extern void callee_512c60();
uint64_t sdk_f_76750(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c60)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76780  (orig 0x76780, call)
extern void callee_512c70();
uint64_t sdk_f_76780(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76840  (orig 0x76840, call)
extern void callee_5128a0();
uint64_t sdk_f_76840(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76860  (orig 0x76860, call)
extern void callee_512ca0();
uint64_t sdk_f_76860(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512ca0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(41)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76890  (orig 0x76890, call)
extern void callee_512c10();
uint64_t sdk_f_76890(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_768b0  (orig 0x768b0, call)
extern void callee_512c10();
uint64_t sdk_f_768b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(52)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_768d0  (orig 0x768d0, ptr_add)
void* sdk_f_768d0(void* a0) { return (char*)a0 + 8; }

// sub_768e0  (orig 0x768e0, straight)
void* sdk_f_768e0(void* a0) { return (char*)(a0) - 8; }

// sub_76a60  (orig 0x76a60, ptr_add)
void* sdk_f_76a60(void* a0) { return (char*)a0 + 16; }

// sub_76ac0  (orig 0x76ac0, call)
extern void callee_512cc0();
uint64_t sdk_f_76ac0(void* a0, uint32_t a1, uint32_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512cc0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76af0  (orig 0x76af0, call)
extern void callee_512cd0();
uint64_t sdk_f_76af0(void* a0, uint32_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512cd0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_76b70  (orig 0x76b70, ptr_add)
void* sdk_f_76b70(void* a0) { return (char*)a0 + 8; }

// sub_76b80  (orig 0x76b80, straight)
void* sdk_f_76b80(void* a0) { return (char*)(a0) - 8; }

// sub_77ea0  (orig 0x77ea0, ptr_add)
void* sdk_f_77ea0(void* a0) { return (char*)a0 + 16; }

// sub_77eb0  (orig 0x77eb0, call)
extern void callee_512c60();
uint64_t sdk_f_77eb0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c60)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (4))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_78030  (orig 0x78030, ptr_add)
void* sdk_f_78030(void* a0) { return (char*)a0 + 8; }

// sub_78040  (orig 0x78040, straight)
void* sdk_f_78040(void* a0) { return (char*)(a0) - 8; }

// sub_78440  (orig 0x78440, strlit-ret)
const char *sdk_f_78440() { static char g_f_78440[1]; __asm__ volatile("" ::: "memory"); return g_f_78440; }

// sub_786b0  (orig 0x786b0, ptr_add)
void* sdk_f_786b0(void* a0) { return (char*)a0 + 16; }

// sub_786c0  (orig 0x786c0, call)
extern void callee_512d30();
uint64_t sdk_f_786c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512d30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_78720  (orig 0x78720, call)
extern void callee_5129e0();
uint64_t sdk_f_78720(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5129e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_78740  (orig 0x78740, call)
extern void callee_512d50();
uint64_t sdk_f_78740(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512d50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_78770  (orig 0x78770, call)
extern void callee_5126d0();
uint64_t sdk_f_78770(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_78830  (orig 0x78830, ptr_add)
void* sdk_f_78830(void* a0) { return (char*)a0 + 8; }

// sub_78840  (orig 0x78840, straight)
void* sdk_f_78840(void* a0) { return (char*)(a0) - 8; }

// sub_78db0  (orig 0x78db0, ptr_add)
void* sdk_f_78db0(void* a0) { return (char*)a0 + 16; }

// sub_78df0  (orig 0x78df0, call)
extern void callee_512c60();
uint64_t sdk_f_78df0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c60)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_78e20  (orig 0x78e20, call)
extern void callee_5126d0();
uint64_t sdk_f_78e20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_78e40  (orig 0x78e40, call)
extern void callee_512d80();
uint64_t sdk_f_78e40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512d80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_78e60  (orig 0x78e60, ptr_add)
void* sdk_f_78e60(void* a0) { return (char*)a0 + 8; }

// sub_78e70  (orig 0x78e70, straight)
void* sdk_f_78e70(void* a0) { return (char*)(a0) - 8; }

// sub_79e20  (orig 0x79e20, ptr_add)
void* sdk_f_79e20(void* a0) { return (char*)a0 + 16; }

// sub_79ed0  (orig 0x79ed0, call)
extern void callee_5126e0();
uint64_t sdk_f_79ed0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_79ef0  (orig 0x79ef0, call)
extern void callee_512710();
uint64_t sdk_f_79ef0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_79f10  (orig 0x79f10, ptr_add)
void* sdk_f_79f10(void* a0) { return (char*)a0 + 8; }

// sub_79f20  (orig 0x79f20, straight)
void* sdk_f_79f20(void* a0) { return (char*)(a0) - 8; }

// sub_7a0a0  (orig 0x7a0a0, ptr_add)
void* sdk_f_7a0a0(void* a0) { return (char*)a0 + 16; }

// sub_7a0e0  (orig 0x7a0e0, call)
extern void callee_512de0();
uint64_t sdk_f_7a0e0(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512de0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_7a110  (orig 0x7a110, ptr_add)
void* sdk_f_7a110(void* a0) { return (char*)a0 + 8; }

// sub_7a120  (orig 0x7a120, straight)
void* sdk_f_7a120(void* a0) { return (char*)(a0) - 8; }

// sub_7a190  (orig 0x7a190, ret_only)
void sdk_f_7a190() {}

// sub_7a400  (orig 0x7a400, ptr_add)
void* sdk_f_7a400(void* a0) { return (char*)a0 + 16; }

// sub_7a4b0  (orig 0x7a4b0, ptr_add)
void* sdk_f_7a4b0(void* a0) { return (char*)a0 + 8; }

// sub_7a4c0  (orig 0x7a4c0, straight)
void* sdk_f_7a4c0(void* a0) { return (char*)(a0) - 8; }

// sub_7af20  (orig 0x7af20, ptr_add)
void* sdk_f_7af20(void* a0) { return (char*)a0 + 16; }

// sub_7af60  (orig 0x7af60, call)
extern void callee_512e00();
uint64_t sdk_f_7af60(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512e00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_7af90  (orig 0x7af90, call)
extern void callee_512e10();
uint64_t sdk_f_7af90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512e10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_7afb0  (orig 0x7afb0, call)
extern void callee_512e10();
uint64_t sdk_f_7afb0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512e10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_7afd0  (orig 0x7afd0, call)
extern void callee_512700();
uint64_t sdk_f_7afd0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_7aff0  (orig 0x7aff0, call)
extern void callee_512700();
uint64_t sdk_f_7aff0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_7b010  (orig 0x7b010, call)
extern void callee_512780();
uint64_t sdk_f_7b010(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_7b040  (orig 0x7b040, call)
extern void callee_5126e0();
uint64_t sdk_f_7b040(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_7b060  (orig 0x7b060, ptr_add)
void* sdk_f_7b060(void* a0) { return (char*)a0 + 8; }

// sub_7b070  (orig 0x7b070, straight)
void* sdk_f_7b070(void* a0) { return (char*)(a0) - 8; }

// sub_7bad0  (orig 0x7bad0, getter)
uint32_t sdk_f_7bad0(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_7bae0  (orig 0x7bae0, getter)
uint32_t sdk_f_7bae0(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_7bf30  (orig 0x7bf30, ptr_add)
void* sdk_f_7bf30(void* a0) { return (char*)a0 + 32; }

// sub_7c170  (orig 0x7c170, getter)
uint32_t sdk_f_7c170(void* a0) { return *(uint32_t*)((char*)(a0) + 140); }

// sub_7c8b0  (orig 0x7c8b0, getter)
uint64_t sdk_f_7c8b0(void* a0) { return *(uint64_t*)((char*)(a0) + 144); }

// sub_7e9e0  (orig 0x7e9e0, getter)
uint64_t sdk_f_7e9e0(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_7e9f0  (orig 0x7e9f0, getter)
uint64_t sdk_f_7e9f0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_7ea00  (orig 0x7ea00, straight)
void sdk_f_7ea00(void* a0) {
    *(uint64_t*)((char*)(a0)) = -4990551337079930880;
}

// sub_7ea70  (orig 0x7ea70, getter)
uint64_t sdk_f_7ea70(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_7ea80  (orig 0x7ea80, getter)
uint64_t sdk_f_7ea80(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_7ea90  (orig 0x7ea90, straight)
void sdk_f_7ea90(void* a0) {
    *(uint64_t*)((char*)(a0)) = -3819615433963601920;
}

// sub_7eaa0  (orig 0x7eaa0, setter-chain)
void sdk_f_7eaa0(void* a0, uint64_t a1, uint64_t a2) { *(uint64_t*)((char*)(a0) + 8) = a1; *(uint64_t*)((char*)(a0) + 24) = a2; }

// sub_7eab0  (orig 0x7eab0, setter-chain)
void sdk_f_7eab0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) { *(uint64_t*)((char*)(a0) + 8) = a1; *(uint64_t*)((char*)(a0) + 16) = a2; *(uint64_t*)((char*)(a0) + 24) = a3; }

// sub_7eac0  (orig 0x7eac0, getter)
uint64_t sdk_f_7eac0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_7ead0  (orig 0x7ead0, getter)
uint64_t sdk_f_7ead0(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_7eae0  (orig 0x7eae0, getter)
uint64_t sdk_f_7eae0(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_7f4f0  (orig 0x7f4f0, getter-chain)
uint64_t sdk_f_7f4f0(void* a0) { return *(uint64_t*)((char*)((*(uint64_t*)((char*)(a0) + 64)))); }

// sub_7f900  (orig 0x7f900, setter)
void sdk_f_7f900(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_7f910  (orig 0x7f910, setter-chain)
void sdk_f_7f910(void* a0) { *(uint64_t*)((char*)(a0)) = 0; *(uint32_t*)((char*)(a0) + 72) = 0; }

// sub_7f920  (orig 0x7f920, call)
extern void callee_513160();
uint64_t sdk_f_7f920() {
    uint64_t f_7f920__r0 = ((uint64_t (*)(void))&callee_513160)();
    uint64_t r0 = (((f_7f920__r0) + (63)) & (18446744073709551552)) + (972);
    asm volatile("");
    return r0;
}

// sub_7f9c0  (orig 0x7f9c0, getter-chain)
uint16_t sdk_f_7f9c0(void* a0) { return *(uint16_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 12); }

// sub_7fbb0  (orig 0x7fbb0, straight-line)
typedef struct { unsigned char b[48]; } __S_f_7fbb0;
__S_f_7fbb0 sdk_f_7fbb0(void* a0) {
    __S_f_7fbb0 r;
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    *(uint32_t *)((char *)&r + 4) = *(uint32_t*)((char*)(p0) + 24);
    *(uint32_t *)((char *)&r + 40) = *(uint32_t*)((char*)(p0) + 28);
    *(uint32_t *)((char *)&r + 8) = *(uint32_t*)((char*)(p0) + 32);
    *(uint32_t *)((char *)&r + 12) = *(uint32_t*)((char*)(p0) + 36);
    *(uint32_t *)((char *)&r + 0) = *(uint32_t*)((char*)(p0) + 40);
    *(uint32_t *)((char *)&r + 16) = *(uint32_t*)((char*)(p0) + 44);
    *(uint32_t *)((char *)&r + 24) = *(uint32_t*)((char*)(p0) + 48);
    *(uint32_t *)((char *)&r + 32) = *(uint32_t*)((char*)(p0) + 52);
    *(uint32_t *)((char *)&r + 20) = *(uint32_t*)((char*)(p0) + 56);
    *(uint32_t *)((char *)&r + 28) = *(uint32_t*)((char*)(p0) + 60);
    *(uint32_t *)((char *)&r + 36) = *(uint32_t*)((char*)(p0) + 64);
    *(uint32_t *)((char *)&r + 44) = *(uint32_t*)((char*)(p0) + 68);
    return r;
}

// sub_7fd00  (orig 0x7fd00, copy2)
void sdk_f_7fd00(void* a0) { (*(uint8_t *)((char *)(*(void **)((char*)(a0))) + 72)) = 0; }

// sub_7fde0  (orig 0x7fde0, getter-chain)
uint16_t sdk_f_7fde0(void* a0) { return *(uint16_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 12); }

// sub_80100  (orig 0x80100, copy2)
void sdk_f_80100(void* a0) { (*(uint8_t *)((char *)(*(void **)((char*)(a0))) + 64)) = 0; }

// sub_80680  (orig 0x80680, straight-line)
uint64_t sdk_f_80680(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    return (*(int32_t*)((char*)(p0) + 16)) * (1000000);
}

// sub_806a0  (orig 0x806a0, copy2)
void sdk_f_806a0(void* a0) { (*(uint8_t *)((char *)(*(void **)((char*)(a0))) + 52)) = 0; }

// sub_80c80  (orig 0x80c80, getter-chain)
uint64_t sdk_f_80c80(void* a0) { return *(uint64_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 32); }

// sub_80c90  (orig 0x80c90, getter-chain)
uint64_t sdk_f_80c90(void* a0) { return *(uint64_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 24); }

// sub_80ca0  (orig 0x80ca0, getter-chain)
uint16_t sdk_f_80ca0(void* a0) { return *(uint16_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 80); }

// sub_80cb0  (orig 0x80cb0, copy2)
void sdk_f_80cb0(void* a0) { (*(uint8_t *)((char *)(*(void **)((char*)(a0))) + 84)) = 0; }

// sub_80fa0  (orig 0x80fa0, straight)
uint32_t sdk_f_80fa0(void* a0) { return (*(uint32_t*)((char*)(a0) + 40)) & (1); }

// sub_812f0  (orig 0x812f0, getter)
uint32_t sdk_f_812f0(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_81300  (orig 0x81300, const-ret)
uint32_t sdk_f_81300() { return 262809u; }

// sub_81310  (orig 0x81310, const-ret)
uint32_t sdk_f_81310() { return 262809u; }

// sub_81320  (orig 0x81320, straight)
uint64_t sdk_f_81320(void* a0) {
    *(uint64_t*)((char*)(a0)) = 0;
    return 0;
}

// sub_81710  (orig 0x81710, getter-chain)
uint32_t sdk_f_81710(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 92); }

// sub_81a20  (orig 0x81a20, getter-chain)
uint32_t sdk_f_81a20(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 84); }

// sub_81a30  (orig 0x81a30, getter-chain)
uint32_t sdk_f_81a30(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 132); }

// sub_81e20  (orig 0x81e20, getter-chain)
uint8_t sdk_f_81e20(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 2); }

// sub_82340  (orig 0x82340, getter-chain)
uint8_t sdk_f_82340(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 2); }

// sub_82910  (orig 0x82910, getter-chain)
uint8_t sdk_f_82910(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 2); }

// sub_82b10  (orig 0x82b10, straight-line)
uint64_t sdk_f_82b10(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    return (*(int32_t*)((char*)(p0) + 48)) * (1000000);
}

// sub_82b30  (orig 0x82b30, getter-chain)
uint16_t sdk_f_82b30(void* a0) { return *(uint16_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 44); }

// sub_82b40  (orig 0x82b40, straight-line)
uint64_t sdk_f_82b40(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    return (*(int32_t*)((char*)(p0) + 52)) * (1000000);
}

// sub_830f0  (orig 0x830f0, call)
extern void callee_513160();
uint64_t sdk_f_830f0() {
    uint64_t f_830f0__r0 = ((uint64_t (*)(void))&callee_513160)();
    uint64_t r0 = ((f_830f0__r0) + (63)) & (18446744073709551552);
    asm volatile("");
    return r0;
}

// sub_834f0  (orig 0x834f0, getter-chain)
uint16_t sdk_f_834f0(void* a0) { return *(uint16_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 44); }

// sub_83550  (orig 0x83550, getter-chain)
uint8_t sdk_f_83550(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 2); }

// sub_83760  (orig 0x83760, getter-chain)
float sdk_f_83760(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 80);
}

// sub_837d0  (orig 0x837d0, getter-chain)
float sdk_f_837d0(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 76);
}

// sub_83840  (orig 0x83840, getter-chain)
float sdk_f_83840(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 72);
}

// sub_83a70  (orig 0x83a70, getter-chain)
float sdk_f_83a70(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 56);
}

// sub_83ae0  (orig 0x83ae0, getter-chain)
float sdk_f_83ae0(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 60);
}

// sub_83c30  (orig 0x83c30, getter-chain)
float sdk_f_83c30(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 68);
}

// sub_83ca0  (orig 0x83ca0, getter-chain)
float sdk_f_83ca0(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 84);
}

// sub_83d10  (orig 0x83d10, getter-chain)
float sdk_f_83d10(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 96);
}

// sub_83d80  (orig 0x83d80, getter-chain)
float sdk_f_83d80(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 100);
}

// sub_83f50  (orig 0x83f50, straight-line)
typedef struct { unsigned char b[48]; } __S_f_83f50;
__S_f_83f50 sdk_f_83f50(void* a0) {
    __S_f_83f50 r;
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    *(uint32_t *)((char *)&r + 4) = *(uint32_t*)((char*)(p0) + 56);
    *(uint32_t *)((char *)&r + 40) = *(uint32_t*)((char*)(p0) + 60);
    *(uint32_t *)((char *)&r + 8) = *(uint32_t*)((char*)(p0) + 64);
    *(uint32_t *)((char *)&r + 12) = *(uint32_t*)((char*)(p0) + 68);
    *(uint32_t *)((char *)&r + 0) = *(uint32_t*)((char*)(p0) + 72);
    *(uint32_t *)((char *)&r + 16) = *(uint32_t*)((char*)(p0) + 76);
    *(uint32_t *)((char *)&r + 24) = *(uint32_t*)((char*)(p0) + 80);
    *(uint32_t *)((char *)&r + 32) = *(uint32_t*)((char*)(p0) + 84);
    *(uint32_t *)((char *)&r + 20) = *(uint32_t*)((char*)(p0) + 88);
    *(uint32_t *)((char *)&r + 28) = *(uint32_t*)((char*)(p0) + 92);
    *(uint32_t *)((char *)&r + 36) = *(uint32_t*)((char*)(p0) + 96);
    *(uint32_t *)((char *)&r + 44) = *(uint32_t*)((char*)(p0) + 100);
    return r;
}

// sub_840d0  (orig 0x840d0, setter-chain-zero)
void sdk_f_840d0(void* a0) {
    struct u64x2 { uint64_t a, b; };
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

// sub_848e0  (orig 0x848e0, getter-chain)
uint16_t sdk_f_848e0(void* a0) { return *(uint16_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 44); }

// sub_84940  (orig 0x84940, getter-chain)
uint8_t sdk_f_84940(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 2); }

// sub_854c0  (orig 0x854c0, getter-chain)
uint32_t sdk_f_854c0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 8); }

// sub_854d0  (orig 0x854d0, getter-chain)
float sdk_f_854d0(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)(char*)(t0);
}

// sub_85540  (orig 0x85540, getter-chain)
uint32_t sdk_f_85540(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 24); }

// sub_85550  (orig 0x85550, getter-chain)
uint32_t sdk_f_85550(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 4); }

// sub_855d0  (orig 0x855d0, getter)
uint64_t sdk_f_855d0(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_855e0  (orig 0x855e0, getter)
uint64_t sdk_f_855e0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_858c0  (orig 0x858c0, getter)
uint8_t sdk_f_858c0(void* a0) { return *(uint8_t*)((char*)(a0) + 20); }

// sub_85ad0  (orig 0x85ad0, straight)
uint32_t sdk_f_85ad0(void* a0) { return (((*(uint32_t*)((char*)(a0) + 16) == 4) ? 1 : 0)) | (((*(uint32_t*)((char*)(a0) + 16) == 2) ? 1 : 0)); }

// sub_85af0  (orig 0x85af0, getter)
uint64_t sdk_f_85af0(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_85b00  (orig 0x85b00, getter)
uint64_t sdk_f_85b00(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_85b10  (orig 0x85b10, getter)
uint32_t sdk_f_85b10(void* a0) { return *(uint32_t*)((char*)(a0) + 16); }

// sub_85b20  (orig 0x85b20, straight)
uint32_t sdk_f_85b20(void* a0, void* a1) {
    *(uint64_t*)((char*)(a1)) = *(uint64_t*)((char*)(a0));
    *(uint64_t*)((char*)(a1) + 8) = *(uint64_t*)((char*)(a0) + 8);
    *(uint32_t*)((char*)(a1) + 16) = *(uint32_t*)((char*)(a0) + 16);
    return 32;
}

// sub_85db0  (orig 0x85db0, getter)
uint32_t sdk_f_85db0(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_862d0  (orig 0x862d0, getter-chain)
uint32_t sdk_f_862d0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 4); }

// sub_862e0  (orig 0x862e0, getter)
uint32_t sdk_f_862e0(void* a0) { return *(uint32_t*)((char*)(a0) + 16); }

// sub_864f0  (orig 0x864f0, compare)
bool sdk_f_864f0(void* a0, void* a1) { return (uint64_t)(*(uint64_t*)((char*)(a0))) == (uint64_t)(*(uint64_t*)((char*)(a1))); }

// sub_86b60  (orig 0x86b60, setter-chain-zero)
void sdk_f_86b60(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_86b70  (orig 0x86b70, setter-chain-zero)
void sdk_f_86b70(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_86c00  (orig 0x86c00, getter-chain)
uint32_t sdk_f_86c00(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 16))) + 16); }

// sub_86c10  (orig 0x86c10, getter-chain)
uint8_t sdk_f_86c10(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0) + 16))) + 36); }

// sub_86c20  (orig 0x86c20, getter-chain)
uint32_t sdk_f_86c20(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 16))) + 20); }

// sub_86c30  (orig 0x86c30, getter-chain)
uint64_t sdk_f_86c30(void* a0) { return *(uint64_t*)((char*)((*(uint64_t*)((char*)(a0) + 16))) + 24); }

// sub_86c40  (orig 0x86c40, getter-chain)
uint32_t sdk_f_86c40(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 16))) + 32); }

// sub_86c50  (orig 0x86c50, straight)
uint64_t sdk_f_86c50(void* a0, void* a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 16));
    *(uint32_t*)((char*)(a1)) = *(uint32_t*)((char*)(p0) + 4);
    return *(uint64_t*)((char*)(a0) + 24);
}

// sub_86c70  (orig 0x86c70, straight)
uint64_t sdk_f_86c70(void* a0, void* a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 16));
    *(uint32_t*)((char*)(a1)) = *(uint32_t*)((char*)(p0) + 8);
    return *(uint64_t*)((char*)(a0) + 32);
}

// sub_86d50  (orig 0x86d50, getter)
uint64_t sdk_f_86d50(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_86f50  (orig 0x86f50, straight-line)
uint64_t sdk_f_86f50(void* a0) { return ((((((((int64_t)(((int32_t)(((((*(uint32_t*)((char*)(a0) + 12)) + (*(uint32_t*)((char*)(a0) + 16))) + (*(uint32_t*)((char*)(a0) + 20))) + (*(uint32_t*)((char*)(a0) + 24))) + (1)))))) * (((int64_t)(((int32_t)(24)))))) + (2448)) * (*(int32_t*)((char*)(a0) + 28))) + (((((((((int64_t)(((int32_t)(((((*(uint32_t*)((char*)(a0) + 12)) + (*(uint32_t*)((char*)(a0) + 16))) + (*(uint32_t*)((char*)(a0) + 20))) + (*(uint32_t*)((char*)(a0) + 24))) + (1)))))) * (((int64_t)(((int32_t)(24)))))) + (2448)) * (*(int32_t*)((char*)(a0) + 28)) == 0)) ? (0) : (48)))) + (63)) & (18446744073709551552); }

// sub_87640  (orig 0x87640, getter-chain)
uint8_t sdk_f_87640(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 283); }

// sub_878b0  (orig 0x878b0, getter-chain)
uint32_t sdk_f_878b0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 4); }

// sub_878c0  (orig 0x878c0, getter-chain)
uint32_t sdk_f_878c0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 4); }

// sub_878d0  (orig 0x878d0, setter)
void sdk_f_878d0(void* a0) { *(uint16_t*)((char*)(a0)) = 0; }

// sub_878e0  (orig 0x878e0, setter)
void sdk_f_878e0(void* a0) { *(uint16_t*)((char*)(a0)) = 0; }

// sub_878f0  (orig 0x878f0, getter)
uint8_t sdk_f_878f0(void* a0) { return *(uint8_t*)((char*)(a0)); }

// sub_879a0  (orig 0x879a0, getter)
uint8_t sdk_f_879a0(void* a0) { return *(uint8_t*)((char*)(a0) + 1); }

// sub_87aa0  (orig 0x87aa0, getter)
uint32_t sdk_f_87aa0(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_87ab0  (orig 0x87ab0, getter)
uint32_t sdk_f_87ab0(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_88380  (orig 0x88380, straight-line)
int64_t sdk_f_88380(uint32_t a0) { return (((int64_t)(((int32_t)(((uint32_t)a0)))))) * (((int64_t)(((int32_t)(48))))); }

// sub_887b0  (orig 0x887b0, straight)
void sdk_f_887b0(void* a0, uint64_t a1) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 17) = (uint8_t)k0;
    *(uint32_t*)((char*)(a0) + 24) = (uint32_t)(a1);
}

// sub_887c0  (orig 0x887c0, straight)
void sdk_f_887c0(void* a0, uint64_t a1) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 17) = (uint8_t)k0;
    *(uint32_t*)((char*)(a0) + 28) = (uint32_t)(a1);
}

// sub_88c90  (orig 0x88c90, getter)
uint32_t sdk_f_88c90(void* a0) { return *(uint32_t*)((char*)(a0) + 20); }

// sub_88ca0  (orig 0x88ca0, getter)
uint32_t sdk_f_88ca0(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_88cb0  (orig 0x88cb0, getter)
uint8_t sdk_f_88cb0(void* a0) { return *(uint8_t*)((char*)(a0) + 17); }

// sub_88cc0  (orig 0x88cc0, getter)
uint8_t sdk_f_88cc0(void* a0) { return *(uint8_t*)((char*)(a0) + 16); }

// sub_88cd0  (orig 0x88cd0, getter)
uint32_t sdk_f_88cd0(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_88d90  (orig 0x88d90, straight)
void sdk_f_88d90(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 17) = (uint8_t)k0;
}

// sub_88da0  (orig 0x88da0, getter)
uint32_t sdk_f_88da0(void* a0) { return *(uint32_t*)((char*)(a0) + 16); }

// sub_88de0  (orig 0x88de0, straight)
void sdk_f_88de0(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0) + 120) = (uint8_t)((((uint32_t)a1)) & (1));
}

// sub_88df0  (orig 0x88df0, straight)
void sdk_f_88df0(void* a0, uint32_t a1) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 120) = (uint8_t)(((((uint32_t)a1) != 2147483647) ? 1 : 0));
    *(uint8_t*)((char*)(a0) + 121) = (uint8_t)k0;
    *(uint32_t*)((char*)(a0) + 20) = (uint32_t)(a1);
}

// sub_88e10  (orig 0x88e10, setter-chain-zero)
void sdk_f_88e10(void* a0) {
    struct u64x2 { uint64_t a, b; };
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
}

// sub_88e30  (orig 0x88e30, straight-line)
int64_t sdk_f_88e30(uint32_t a0) { return (((int64_t)(((int32_t)(((uint32_t)a0)))))) * (((int64_t)(((int32_t)(112))))); }

// sub_88e40  (orig 0x88e40, getter)
uint8_t sdk_f_88e40(void* a0) { return *(uint8_t*)((char*)(a0) + 120); }

// sub_88e50  (orig 0x88e50, getter)
uint32_t sdk_f_88e50(void* a0) { return *(uint32_t*)((char*)(a0) + 20); }

// sub_88e90  (orig 0x88e90, getter)
uint8_t sdk_f_88e90(void* a0) { return *(uint8_t*)((char*)(a0) + 121); }

// sub_890a0  (orig 0x890a0, getter-chain)
uint32_t sdk_f_890a0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 4); }

// sub_890b0  (orig 0x890b0, getter-chain)
uint32_t sdk_f_890b0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 8); }

// sub_890c0  (orig 0x890c0, getter-chain)
float sdk_f_890c0(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)(char*)(t0);
}

// sub_89250  (orig 0x89250, getter-chain)
uint32_t sdk_f_89250(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 24); }

// sub_896d0  (orig 0x896d0, compare)
bool sdk_f_896d0(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0))) != (uint64_t)(0); }

// sub_89930  (orig 0x89930, getter-chain)
uint32_t sdk_f_89930(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 76); }

// sub_89940  (orig 0x89940, getter-chain)
uint32_t sdk_f_89940(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 88); }

// sub_89950  (orig 0x89950, getter-chain)
uint8_t sdk_f_89950(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 75); }

// sub_899a0  (orig 0x899a0, getter-chain)
uint32_t sdk_f_899a0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 80); }

// sub_899f0  (orig 0x899f0, getter-chain)
uint8_t sdk_f_899f0(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0)))) + 74); }

// sub_89a50  (orig 0x89a50, getter-chain)
float sdk_f_89a50(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 92);
}

// sub_89ab0  (orig 0x89ab0, getter-chain)
float sdk_f_89ab0(void* a0) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(float*)((char*)(t0) + 96);
}

// sub_89ca0  (orig 0x89ca0, straight)
void* sdk_f_89ca0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    return (char*)(p0) + 100;
}

// sub_89fa0  (orig 0x89fa0, const-field-set-store)
void sdk_f_89fa0(void* a0, void* a1) {
    uint64_t t0 = *(uint64_t*)(char*)a1;
    uint64_t t1 = -2147483649;
    *(uint64_t*)((char*)(t0) + 152) = (uint64_t)(t1);
}

// sub_89fe0  (orig 0x89fe0, straight-line)
int64_t sdk_f_89fe0(uint32_t a0) { return (((int64_t)(((int32_t)(((uint32_t)a0)))))) * (((int64_t)(((int32_t)(648))))); }

// sub_8ad70  (orig 0x8ad70, straight)
uint32_t sdk_f_8ad70(uint32_t a0) { return (((uint32_t)a0)) >> (28); }

// sub_8ad80  (orig 0x8ad80, straight)
uint32_t sdk_f_8ad80(uint32_t a0) { return ((((uint32_t)a0)) >> (16)) & (4095); }

// sub_8ad90  (orig 0x8ad90, straight)
uint32_t sdk_f_8ad90(uint32_t a0) { return (((uint32_t)a0)) & (65535); }

// sub_8ada0  (orig 0x8ada0, mov_ret)
uint32_t sdk_f_8ada0() { return -268435456; }

// sub_8aef0  (orig 0x8aef0, getter)
uint32_t sdk_f_8aef0(void* a0) { return *(uint32_t*)((char*)(a0) + 12); }

// sub_8af10  (orig 0x8af10, setter-chain-zero)
void sdk_f_8af10(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint32_t*)((char*)a0 + 16) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_8af30  (orig 0x8af30, getter)
uint32_t sdk_f_8af30(void* a0) { return *(uint32_t*)((char*)(a0) + 12); }

// sub_8afd0  (orig 0x8afd0, setter-chain-zero)
void sdk_f_8afd0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint64_t*)((char*)a0 + 24) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 32) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a0 + 40) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 48) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 72) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 16) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 56) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_8b510  (orig 0x8b510, getter)
uint32_t sdk_f_8b510(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_8b520  (orig 0x8b520, const-ret)
uint32_t sdk_f_8b520() { return 1212436051u; }

// sub_8b530  (orig 0x8b530, const-ret)
uint32_t sdk_f_8b530() { return 1229213267u; }

// sub_8b540  (orig 0x8b540, const-ret)
uint32_t sdk_f_8b540() { return 1145327187u; }

// sub_8b5c0  (orig 0x8b5c0, const-ret)
uint32_t sdk_f_8b5c0() { return 928400722u; }

// sub_8b5d0  (orig 0x8b5d0, const-ret)
uint32_t sdk_f_8b5d0() { return 928400722u; }

// sub_8b5e0  (orig 0x8b5e0, const-ret)
uint32_t sdk_f_8b5e0() { return 911623506u; }

// sub_8b5f0  (orig 0x8b5f0, const-ret)
uint32_t sdk_f_8b5f0() { return 894846290u; }

// sub_8b600  (orig 0x8b600, const-ret)
uint32_t sdk_f_8b600() { return 878069074u; }

// sub_8b610  (orig 0x8b610, const-ret)
uint32_t sdk_f_8b610() { return 827737426u; }

// sub_8b620  (orig 0x8b620, const-ret)
uint32_t sdk_f_8b620() { return 844514642u; }

// sub_8b630  (orig 0x8b630, const-ret)
uint32_t sdk_f_8b630() { return 861291858u; }

// sub_8b640  (orig 0x8b640, const-ret)
uint32_t sdk_f_8b640() { return 827737426u; }

// sub_8b6d0  (orig 0x8b6d0, straight)
void sdk_f_8b6d0(void* a0, uint64_t a1) {
    *(uint32_t*)((char*)(a0)) = (uint32_t)(a1);
    *(uint64_t*)((char*)(a0) + 52) = 0;
    *(uint64_t*)((char*)(a0) + 44) = 0;
    *(uint64_t*)((char*)(a0) + 36) = 0;
    *(uint64_t*)((char*)(a0) + 28) = 0;
    *(uint64_t*)((char*)(a0) + 20) = 0;
    *(uint64_t*)((char*)(a0) + 12) = 0;
    *(uint64_t*)((char*)(a0) + 4) = 0;
    *(uint32_t*)((char*)(a0) + 60) = 64;
}

// sub_8b700  (orig 0x8b700, getter)
uint32_t sdk_f_8b700(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_8b710  (orig 0x8b710, getter)
uint32_t sdk_f_8b710(void* a0) { return *(uint32_t*)((char*)(a0) + 60); }

// sub_8b730  (orig 0x8b730, setter-chain)
void sdk_f_8b730(void* a0, uint64_t a1, uint64_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 8) = a2; *(uint64_t*)((char*)(a0) + 16) = 0; }

// sub_8d450  (orig 0x8d450, mov_ret)
uint32_t sdk_f_8d450() { return 0; }

// sub_8e450  (orig 0x8e450, straight-line)
int64_t sdk_f_8e450(uint32_t a0) { return (((int64_t)(((int32_t)(((uint32_t)a0)))))) * (((int64_t)(((int32_t)(608))))); }

// sub_90140  (orig 0x90140, ptr_add)
void* sdk_f_90140(void* a0) { return (char*)a0 + 16; }

// sub_90180  (orig 0x90180, call)
extern void callee_512700();
uint64_t sdk_f_90180(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_901a0  (orig 0x901a0, call)
extern void callee_512700();
uint64_t sdk_f_901a0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_901c0  (orig 0x901c0, call)
extern void callee_512700();
uint64_t sdk_f_901c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_901e0  (orig 0x901e0, ptr_add)
void* sdk_f_901e0(void* a0) { return (char*)a0 + 8; }

// sub_901f0  (orig 0x901f0, straight)
void* sdk_f_901f0(void* a0) { return (char*)(a0) - 8; }

// sub_90710  (orig 0x90710, ptr_add)
void* sdk_f_90710(void* a0) { return (char*)a0 + 16; }

// sub_90a60  (orig 0x90a60, ptr_add)
void* sdk_f_90a60(void* a0) { return (char*)a0 + 8; }

// sub_90a70  (orig 0x90a70, straight)
void* sdk_f_90a70(void* a0) { return (char*)(a0) - 8; }

// sub_91040  (orig 0x91040, ptr_add)
void* sdk_f_91040(void* a0) { return (char*)a0 + 16; }

// sub_91070  (orig 0x91070, call)
extern void callee_512700();
uint64_t sdk_f_91070(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_91090  (orig 0x91090, call)
extern void callee_512700();
uint64_t sdk_f_91090(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_910e0  (orig 0x910e0, call)
extern void callee_5126d0();
uint64_t sdk_f_910e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_91130  (orig 0x91130, call)
extern void callee_513930();
uint64_t sdk_f_91130(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513930)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_91210  (orig 0x91210, call)
extern void callee_5126e0();
uint64_t sdk_f_91210(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_91260  (orig 0x91260, call)
extern void callee_5126e0();
uint64_t sdk_f_91260(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_91280  (orig 0x91280, call)
extern void callee_512710();
uint64_t sdk_f_91280(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_912a0  (orig 0x912a0, ptr_add)
void* sdk_f_912a0(void* a0) { return (char*)a0 + 8; }

// sub_912b0  (orig 0x912b0, straight)
void* sdk_f_912b0(void* a0) { return (char*)(a0) - 8; }

// sub_92460  (orig 0x92460, ptr_add)
void* sdk_f_92460(void* a0) { return (char*)a0 + 16; }

// sub_92490  (orig 0x92490, call)
extern void callee_513970();
uint64_t sdk_f_92490(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_924b0  (orig 0x924b0, call)
extern void callee_512c50();
uint64_t sdk_f_924b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_92500  (orig 0x92500, ptr_add)
void* sdk_f_92500(void* a0) { return (char*)a0 + 8; }

// sub_92510  (orig 0x92510, straight)
void* sdk_f_92510(void* a0) { return (char*)(a0) - 8; }

// sub_92800  (orig 0x92800, ptr_add)
void* sdk_f_92800(void* a0) { return (char*)a0 + 16; }

// sub_92830  (orig 0x92830, call)
extern void callee_5128a0();
uint64_t sdk_f_92830(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_92850  (orig 0x92850, ptr_add)
void* sdk_f_92850(void* a0) { return (char*)a0 + 8; }

// sub_92860  (orig 0x92860, straight)
void* sdk_f_92860(void* a0) { return (char*)(a0) - 8; }

// sub_92c00  (orig 0x92c00, ptr_add)
void* sdk_f_92c00(void* a0) { return (char*)a0 + 16; }

// sub_92e30  (orig 0x92e30, ptr_add)
void* sdk_f_92e30(void* a0) { return (char*)a0 + 8; }

// sub_92e40  (orig 0x92e40, straight)
void* sdk_f_92e40(void* a0) { return (char*)(a0) - 8; }

// sub_92fd0  (orig 0x92fd0, ptr_add)
void* sdk_f_92fd0(void* a0) { return (char*)a0 + 16; }

// sub_93000  (orig 0x93000, call)
extern void callee_512700();
uint64_t sdk_f_93000(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_93020  (orig 0x93020, call)
extern void callee_512700();
uint64_t sdk_f_93020(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_93070  (orig 0x93070, call)
extern void callee_5126d0();
uint64_t sdk_f_93070(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_930c0  (orig 0x930c0, call)
extern void callee_513930();
uint64_t sdk_f_930c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513930)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_93140  (orig 0x93140, call)
extern void callee_5126e0();
uint64_t sdk_f_93140(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_93160  (orig 0x93160, call)
extern void callee_5127d0();
uint64_t sdk_f_93160(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5127d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_93180  (orig 0x93180, call)
extern void callee_512710();
uint64_t sdk_f_93180(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_931d0  (orig 0x931d0, call)
extern void callee_5126e0();
uint64_t sdk_f_931d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_931f0  (orig 0x931f0, ptr_add)
void* sdk_f_931f0(void* a0) { return (char*)a0 + 8; }

// sub_93200  (orig 0x93200, straight)
void* sdk_f_93200(void* a0) { return (char*)(a0) - 8; }

// sub_932e0  (orig 0x932e0, ptr_add)
void* sdk_f_932e0(void* a0) { return (char*)a0 + 16; }

// sub_93310  (orig 0x93310, call)
extern void callee_513970();
uint64_t sdk_f_93310(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_93330  (orig 0x93330, call)
extern void callee_512c50();
uint64_t sdk_f_93330(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_93380  (orig 0x93380, call)
extern void callee_512c50();
uint64_t sdk_f_93380(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_933d0  (orig 0x933d0, ptr_add)
void* sdk_f_933d0(void* a0) { return (char*)a0 + 8; }

// sub_933e0  (orig 0x933e0, straight)
void* sdk_f_933e0(void* a0) { return (char*)(a0) - 8; }

// sub_934c0  (orig 0x934c0, ptr_add)
void* sdk_f_934c0(void* a0) { return (char*)a0 + 16; }

// sub_934f0  (orig 0x934f0, call)
extern void callee_5128a0();
uint64_t sdk_f_934f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_93510  (orig 0x93510, ptr_add)
void* sdk_f_93510(void* a0) { return (char*)a0 + 8; }

// sub_93520  (orig 0x93520, straight)
void* sdk_f_93520(void* a0) { return (char*)(a0) - 8; }

// sub_938f0  (orig 0x938f0, ptr_add)
void* sdk_f_938f0(void* a0) { return (char*)a0 + 16; }

// sub_939d0  (orig 0x939d0, call)
extern void callee_5139a0();
uint64_t sdk_f_939d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5139a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_93c10  (orig 0x93c10, ptr_add)
void* sdk_f_93c10(void* a0) { return (char*)a0 + 8; }

// sub_93c20  (orig 0x93c20, straight)
void* sdk_f_93c20(void* a0) { return (char*)(a0) - 8; }

// sub_94000  (orig 0x94000, ptr_add)
void* sdk_f_94000(void* a0) { return (char*)a0 + 16; }

// sub_94030  (orig 0x94030, call)
extern void callee_5126e0();
uint64_t sdk_f_94030(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94050  (orig 0x94050, call)
extern void callee_5126e0();
uint64_t sdk_f_94050(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94070  (orig 0x94070, call)
extern void callee_5126e0();
uint64_t sdk_f_94070(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_940d0  (orig 0x940d0, call)
extern void callee_512700();
uint64_t sdk_f_940d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_940f0  (orig 0x940f0, call)
extern void callee_512700();
uint64_t sdk_f_940f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94110  (orig 0x94110, call)
extern void callee_5126d0();
uint64_t sdk_f_94110(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94130  (orig 0x94130, call)
extern void callee_512780();
uint64_t sdk_f_94130(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94160  (orig 0x94160, call)
extern void callee_5126e0();
uint64_t sdk_f_94160(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_941c0  (orig 0x941c0, call)
extern void callee_512700();
uint64_t sdk_f_941c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_941e0  (orig 0x941e0, ptr_add)
void* sdk_f_941e0(void* a0) { return (char*)a0 + 8; }

// sub_941f0  (orig 0x941f0, straight)
void* sdk_f_941f0(void* a0) { return (char*)(a0) - 8; }

// sub_948a0  (orig 0x948a0, ptr_add)
void* sdk_f_948a0(void* a0) { return (char*)a0 + 16; }

// sub_94940  (orig 0x94940, call)
extern void callee_5128d0();
uint64_t sdk_f_94940(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5128d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94970  (orig 0x94970, call)
extern void callee_5126d0();
uint64_t sdk_f_94970(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94990  (orig 0x94990, call)
extern void callee_5126e0();
uint64_t sdk_f_94990(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94a40  (orig 0x94a40, call)
extern void callee_513a30();
uint64_t sdk_f_94a40(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513a30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94a70  (orig 0x94a70, call)
extern void callee_5126d0();
uint64_t sdk_f_94a70(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94a90  (orig 0x94a90, call)
extern void callee_5126d0();
uint64_t sdk_f_94a90(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94ab0  (orig 0x94ab0, call)
extern void callee_513a40();
uint64_t sdk_f_94ab0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513a40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_94ae0  (orig 0x94ae0, ptr_add)
void* sdk_f_94ae0(void* a0) { return (char*)a0 + 8; }

// sub_94af0  (orig 0x94af0, straight)
void* sdk_f_94af0(void* a0) { return (char*)(a0) - 8; }

// sub_95790  (orig 0x95790, ptr_add)
void* sdk_f_95790(void* a0) { return (char*)a0 + 16; }

// sub_957c0  (orig 0x957c0, call)
extern void callee_513970();
uint64_t sdk_f_957c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513970)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_957e0  (orig 0x957e0, call)
extern void callee_512c50();
uint64_t sdk_f_957e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_95830  (orig 0x95830, call)
extern void callee_5128a0();
uint64_t sdk_f_95830(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_95850  (orig 0x95850, call)
extern void callee_5128a0();
uint64_t sdk_f_95850(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_95870  (orig 0x95870, call)
extern void callee_512c50();
uint64_t sdk_f_95870(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512c50)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_958c0  (orig 0x958c0, ptr_add)
void* sdk_f_958c0(void* a0) { return (char*)a0 + 8; }

// sub_958d0  (orig 0x958d0, straight)
void* sdk_f_958d0(void* a0) { return (char*)(a0) - 8; }

// sub_959b0  (orig 0x959b0, ptr_add)
void* sdk_f_959b0(void* a0) { return (char*)a0 + 16; }

// sub_959e0  (orig 0x959e0, call)
extern void callee_5128a0();
uint64_t sdk_f_959e0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_95a00  (orig 0x95a00, ptr_add)
void* sdk_f_95a00(void* a0) { return (char*)a0 + 8; }

// sub_95a10  (orig 0x95a10, straight)
void* sdk_f_95a10(void* a0) { return (char*)(a0) - 8; }

// sub_95c20  (orig 0x95c20, ptr_add)
void* sdk_f_95c20(void* a0) { return (char*)a0 + 16; }

// sub_95cf0  (orig 0x95cf0, ptr_add)
void* sdk_f_95cf0(void* a0) { return (char*)a0 + 8; }

// sub_95d00  (orig 0x95d00, straight)
void* sdk_f_95d00(void* a0) { return (char*)(a0) - 8; }

// sub_96080  (orig 0x96080, ptr_add)
void* sdk_f_96080(void* a0) { return (char*)a0 + 16; }

// sub_960b0  (orig 0x960b0, call)
extern void callee_512700();
uint64_t sdk_f_960b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_960d0  (orig 0x960d0, call)
extern void callee_512700();
uint64_t sdk_f_960d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_96120  (orig 0x96120, call)
extern void callee_5126d0();
uint64_t sdk_f_96120(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_96170  (orig 0x96170, call)
extern void callee_513930();
uint64_t sdk_f_96170(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513930)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_96190  (orig 0x96190, call)
extern void callee_513a70();
uint64_t sdk_f_96190(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_513a70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_96210  (orig 0x96210, call)
extern void callee_512710();
uint64_t sdk_f_96210(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_96230  (orig 0x96230, ptr_add)
void* sdk_f_96230(void* a0) { return (char*)a0 + 8; }

// sub_96240  (orig 0x96240, straight)
void* sdk_f_96240(void* a0) { return (char*)(a0) - 8; }

// sub_96950  (orig 0x96950, ptr_add)
void* sdk_f_96950(void* a0) { return (char*)a0 + 16; }

// sub_96980  (orig 0x96980, call)
extern void callee_512700();
uint64_t sdk_f_96980(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_969a0  (orig 0x969a0, call)
extern void callee_5126e0();
uint64_t sdk_f_969a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_969c0  (orig 0x969c0, ptr_add)
void* sdk_f_969c0(void* a0) { return (char*)a0 + 8; }

// sub_969d0  (orig 0x969d0, straight)
void* sdk_f_969d0(void* a0) { return (char*)(a0) - 8; }

// sub_97160  (orig 0x97160, ret_only)
void sdk_f_97160() {}

// sub_97170  (orig 0x97170, ret_only)
void sdk_f_97170() {}

// sub_97180  (orig 0x97180, straight-line)
uint32_t sdk_f_97180(void* a0) { return (16) + ((*(uint32_t*)((char*)(a0) + 16)) * (12)); }

// sub_971a0  (orig 0x971a0, ret_only)
void sdk_f_971a0() {}

// sub_971b0  (orig 0x971b0, ret_only)
void sdk_f_971b0() {}

// sub_97bb0  (orig 0x97bb0, ptr_add)
void* sdk_f_97bb0(void* a0) { return (char*)a0 + 16; }

// sub_97bc0  (orig 0x97bc0, getter)
uint32_t sdk_f_97bc0(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_97bd0  (orig 0x97bd0, getter)
uint32_t sdk_f_97bd0(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_97be0  (orig 0x97be0, getter)
uint32_t sdk_f_97be0(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_98e90  (orig 0x98e90, ptr_add)
void* sdk_f_98e90(void* a0) { return (char*)a0 + 16; }

// sub_98ea0  (orig 0x98ea0, getter)
uint32_t sdk_f_98ea0(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_98eb0  (orig 0x98eb0, getter)
uint32_t sdk_f_98eb0(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_98ec0  (orig 0x98ec0, getter)
uint32_t sdk_f_98ec0(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_98ed0  (orig 0x98ed0, setter-chain)
void sdk_f_98ed0(void* a0, uint64_t a1, uint64_t a2) { *(uint64_t*)((char*)(a0) + 8) = a1; *(uint64_t*)((char*)(a0) + 24) = a2; }

// sub_98ee0  (orig 0x98ee0, setter-chain)
void sdk_f_98ee0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) { *(uint64_t*)((char*)(a0) + 8) = a1; *(uint64_t*)((char*)(a0) + 16) = a2; *(uint64_t*)((char*)(a0) + 24) = a3; }

// sub_98ef0  (orig 0x98ef0, getter)
uint64_t sdk_f_98ef0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_98f00  (orig 0x98f00, getter)
uint64_t sdk_f_98f00(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_98f10  (orig 0x98f10, getter)
uint64_t sdk_f_98f10(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_99e60  (orig 0x99e60, getter)
uint32_t sdk_f_99e60(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_99e70  (orig 0x99e70, getter)
uint32_t sdk_f_99e70(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_99e80  (orig 0x99e80, getter)
uint32_t sdk_f_99e80(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_99e90  (orig 0x99e90, setter-chain)
void sdk_f_99e90(void* a0, uint64_t a1, uint64_t a2) { *(uint64_t*)((char*)(a0) + 16) = a1; *(uint64_t*)((char*)(a0) + 32) = a2; }

// sub_99ea0  (orig 0x99ea0, setter-chain)
void sdk_f_99ea0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) { *(uint64_t*)((char*)(a0) + 16) = a1; *(uint64_t*)((char*)(a0) + 24) = a2; *(uint64_t*)((char*)(a0) + 32) = a3; }

// sub_99eb0  (orig 0x99eb0, getter)
uint64_t sdk_f_99eb0(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_99ec0  (orig 0x99ec0, getter)
uint64_t sdk_f_99ec0(void* a0) { return *(uint64_t*)((char*)(a0) + 32); }

// sub_9a270  (orig 0x9a270, setter)
void sdk_f_9a270(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_9a280  (orig 0x9a280, getter)
uint64_t sdk_f_9a280(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_9c310  (orig 0x9c310, getter)
uint32_t sdk_f_9c310(void* a0) { return *(uint32_t*)((char*)(a0) + 720); }

// sub_9c320  (orig 0x9c320, setter)
void sdk_f_9c320(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 720) = a1; }

// sub_9cbf0  (orig 0x9cbf0, getter)
uint32_t sdk_f_9cbf0(void* a0) { return *(uint32_t*)((char*)(a0) + 416); }

// sub_9cc10  (orig 0x9cc10, getter)
uint64_t sdk_f_9cc10(void* a0) { return *(uint64_t*)((char*)(a0) + 112); }

// sub_9cc20  (orig 0x9cc20, getter)
uint64_t sdk_f_9cc20(void* a0) { return *(uint64_t*)((char*)(a0) + 120); }

// sub_9cc30  (orig 0x9cc30, getter)
uint32_t sdk_f_9cc30(void* a0) { return *(uint32_t*)((char*)(a0) + 20); }

// sub_9cc40  (orig 0x9cc40, getter)
uint32_t sdk_f_9cc40(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_9cc50  (orig 0x9cc50, getter)
uint32_t sdk_f_9cc50(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_9cc70  (orig 0x9cc70, getter)
uint32_t sdk_f_9cc70(void* a0) { return *(uint32_t*)((char*)(a0) + 728); }

// sub_9cc80  (orig 0x9cc80, getter)
uint32_t sdk_f_9cc80(void* a0) { return *(uint32_t*)((char*)(a0) + 732); }

// sub_9cce0  (orig 0x9cce0, ret_only)
void sdk_f_9cce0() {}

// sub_9cde0  (orig 0x9cde0, call)
extern void callee_5140e0();
uint64_t sdk_f_9cde0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_5140e0)(((uintptr_t)((char*)(a0) + 96)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9ce00  (orig 0x9ce00, call)
extern void callee_5140f0();
uint64_t sdk_f_9ce00(void* a0) {
    uint64_t f_9ce00__r0 = ((uint64_t (*)(uintptr_t))&callee_5140f0)(((uintptr_t)((char*)(a0) + 96)));
    uint64_t r0 = 0;
    asm volatile("");
    return r0;
}

// sub_9ce20  (orig 0x9ce20, call)
extern void callee_514100();
uint64_t sdk_f_9ce20(void* a0) {
    uint64_t f_9ce20__r0 = ((uint64_t (*)(uintptr_t))&callee_514100)(((uintptr_t)((char*)(a0) + 96)));
    uint64_t r0 = 0;
    asm volatile("");
    return r0;
}

// sub_9ce70  (orig 0x9ce70, call)
extern void callee_514120();
uint64_t sdk_f_9ce70(void* a0, void* a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_514120)(((uintptr_t)((char*)(a0) + 96)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9ceb0  (orig 0x9ceb0, call)
extern void callee_514120();
uint64_t sdk_f_9ceb0(void* a0, void* a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_514120)(((uintptr_t)((char*)(a0) + 96)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9cef0  (orig 0x9cef0, call)
extern void callee_514120();
uint64_t sdk_f_9cef0(void* a0, void* a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_514120)(((uintptr_t)((char*)(a0) + 96)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9d7c0  (orig 0x9d7c0, ret_only)
void sdk_f_9d7c0() {}

// sub_9d7d0  (orig 0x9d7d0, ret_only)
void sdk_f_9d7d0() {}

// sub_9d910  (orig 0x9d910, call)
extern void callee_514120();
uint64_t sdk_f_9d910(void* a0, void* a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_514120)(((uintptr_t)((char*)(a0) + 112)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9d950  (orig 0x9d950, call)
extern void callee_5140e0();
uint64_t sdk_f_9d950(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_5140e0)(((uintptr_t)((char*)(a0) + 112)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9d970  (orig 0x9d970, call)
extern void callee_5140f0();
uint64_t sdk_f_9d970(void* a0) {
    uint64_t f_9d970__r0 = ((uint64_t (*)(uintptr_t))&callee_5140f0)(((uintptr_t)((char*)(a0) + 112)));
    uint64_t r0 = 0;
    asm volatile("");
    return r0;
}

// sub_9d9f0  (orig 0x9d9f0, call)
extern void callee_514100();
uint64_t sdk_f_9d9f0(void* a0) {
    uint64_t f_9d9f0__r0 = ((uint64_t (*)(uintptr_t))&callee_514100)(((uintptr_t)((char*)(a0) + 112)));
    uint64_t r0 = 0;
    asm volatile("");
    return r0;
}

// sub_9da40  (orig 0x9da40, call)
extern void callee_514120();
uint64_t sdk_f_9da40(void* a0, void* a1, void* a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_514120)(((uintptr_t)((char*)(a0) + 112)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9da80  (orig 0x9da80, call)
extern void callee_514240();
uint64_t sdk_f_9da80(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514240)(((uintptr_t)((char*)(a0) + 16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9dce0  (orig 0x9dce0, call)
extern void callee_5142c0();
uint64_t sdk_f_9dce0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_5142c0)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9dd00  (orig 0x9dd00, call)
extern void callee_5142d0();
uint64_t sdk_f_9dd00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_5142d0)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9dd20  (orig 0x9dd20, call)
extern void callee_5142e0();
uint64_t sdk_f_9dd20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_5142e0)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9dd40  (orig 0x9dd40, call)
extern void callee_5142f0();
uint64_t sdk_f_9dd40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_5142f0)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9dd60  (orig 0x9dd60, call)
extern void callee_514300();
uint64_t sdk_f_9dd60(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514300)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9dd80  (orig 0x9dd80, call)
extern void callee_514310();
uint64_t sdk_f_9dd80(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514310)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9dda0  (orig 0x9dda0, call)
extern void callee_514320();
uint64_t sdk_f_9dda0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514320)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9ddc0  (orig 0x9ddc0, call)
extern void callee_514330();
uint64_t sdk_f_9ddc0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514330)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9dde0  (orig 0x9dde0, call)
extern void callee_514340();
uint64_t sdk_f_9dde0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514340)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9de00  (orig 0x9de00, call)
extern void callee_514350();
uint64_t sdk_f_9de00(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514350)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9de20  (orig 0x9de20, call)
extern void callee_514360();
uint64_t sdk_f_9de20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514360)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9de40  (orig 0x9de40, call)
extern void callee_514370();
uint64_t sdk_f_9de40(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514370)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9de60  (orig 0x9de60, call)
extern void callee_514380();
uint64_t sdk_f_9de60(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514380)(((uintptr_t)((char*)(a0) + 8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_9e560  (orig 0x9e560, getter)
uint64_t sdk_f_9e560(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_9e570  (orig 0x9e570, getter)
uint64_t sdk_f_9e570(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_9e580  (orig 0x9e580, getter)
uint32_t sdk_f_9e580(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_9e590  (orig 0x9e590, getter)
uint32_t sdk_f_9e590(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_9e5b0  (orig 0x9e5b0, pair-ret)
struct pair16_f_9e5b0_ { uint64_t f[2]; }; pair16_f_9e5b0_ sdk_f_9e5b0(void* a0) { return *(struct pair16_f_9e5b0_ *)((char*)(a0) + 24); }

// sub_9e5c0  (orig 0x9e5c0, straight)
void sdk_f_9e5c0(void* a0, void* a1) {
    *(uint64_t*)((char*)(a0) + 24) = *(uint64_t*)((char*)(a1));
    *(uint32_t*)((char*)(a0) + 32) = *(uint32_t*)((char*)(a1) + 8);
    *(uint32_t*)((char*)(a0) + 36) = *(uint32_t*)((char*)(a1) + 12);
}

// sub_a2180  (orig 0xa2180, ret_only)
void sdk_f_a2180() {}

// sub_a4aa0  (orig 0xa4aa0, mov_ret)
uint32_t sdk_f_a4aa0() { return 0; }

// sub_a4c10  (orig 0xa4c10, mov_ret)
uint32_t sdk_f_a4c10() { return 1080; }

// sub_a4c80  (orig 0xa4c80, const-ret)
uint32_t sdk_f_a4c80() { return 357915u; }

// sub_a4c90  (orig 0xa4c90, straight)
uint32_t sdk_f_a4c90(uint64_t unused0, void* a1) { return (((*(uint8_t*)((char*)(a1) + 84) == 0)) ? (3765) : (15956)); }

// sub_a4cb0  (orig 0xa4cb0, mov_ret)
uint32_t sdk_f_a4cb0() { return 10042; }

// sub_a4cc0  (orig 0xa4cc0, mov_ret)
uint32_t sdk_f_a4cc0() { return 55; }

// sub_a4d50  (orig 0xa4d50, mov_ret)
uint32_t sdk_f_a4d50() { return 1454; }

// sub_a4d90  (orig 0xa4d90, mov_ret)
uint32_t sdk_f_a4d90() { return 16108; }

// sub_a4da0  (orig 0xa4da0, mov_ret)
uint32_t sdk_f_a4da0() { return 0; }

// sub_a4ee0  (orig 0xa4ee0, mov_ret)
uint32_t sdk_f_a4ee0() { return 0; }

// sub_a6fc0  (orig 0xa6fc0, mov_ret)
uint32_t sdk_f_a6fc0() { return 0; }

// sub_a7080  (orig 0xa7080, ret_only)
void sdk_f_a7080() {}

// sub_a7190  (orig 0xa7190, getter)
uint8_t sdk_f_a7190(void* a0) { return *(uint8_t*)((char*)(a0) + 128); }

// sub_a7480  (orig 0xa7480, setter)
void sdk_f_a7480(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 132) = a1; }

// sub_a7490  (orig 0xa7490, compare)
bool sdk_f_a7490(void* a0, uint64_t a1) { return (uint32_t)(*(uint32_t*)((char*)(a0) + 132)) == (uint32_t)(a1); }

// sub_a7640  (orig 0xa7640, getter)
uint8_t sdk_f_a7640(void* a0) { return *(uint8_t*)((char*)(a0) + 128); }

// sub_a7970  (orig 0xa7970, setter)
void sdk_f_a7970(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 132) = a1; }

// sub_a7980  (orig 0xa7980, compare)
bool sdk_f_a7980(void* a0, uint64_t a1) { return (uint32_t)(*(uint32_t*)((char*)(a0) + 132)) == (uint32_t)(a1); }

// sub_a7ac0  (orig 0xa7ac0, getter)
uint32_t sdk_f_a7ac0(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_a7ad0  (orig 0xa7ad0, getter)
uint32_t sdk_f_a7ad0(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_a7ae0  (orig 0xa7ae0, setter)
void sdk_f_a7ae0(void* a0) { *(uint32_t*)((char*)(a0) + 176) = 0; }

// sub_a7b20  (orig 0xa7b20, setter)
void sdk_f_a7b20(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 4) = a1; }

// sub_a7b30  (orig 0xa7b30, straight)
uint32_t sdk_f_a7b30(void* a0) { return (*(uint32_t*)((char*)(a0) + 8)) & (1); }

// sub_a7b40  (orig 0xa7b40, copy2)
void sdk_f_a7b40(void* a0, void* a1) { *(uint64_t*)((char*)(a0) + 8) = *(uint64_t*)((char*)(a1)); }

// sub_a7df0  (orig 0xa7df0, mov_ret)
uint32_t sdk_f_a7df0() { return 0; }

// sub_a8040  (orig 0xa8040, getter)
uint8_t sdk_f_a8040(void* a0) { return *(uint8_t*)((char*)(a0) + 9); }

// sub_a8050  (orig 0xa8050, getter)
uint8_t sdk_f_a8050(void* a0) { return *(uint8_t*)((char*)(a0) + 10); }

// sub_a8060  (orig 0xa8060, getter)
uint8_t sdk_f_a8060(void* a0) { return *(uint8_t*)((char*)(a0) + 8); }

// sub_a8070  (orig 0xa8070, getter)
uint32_t sdk_f_a8070(void* a0) { return *(uint32_t*)((char*)(a0) + 12); }

// sub_a8080  (orig 0xa8080, getter)
uint32_t sdk_f_a8080(void* a0) { return *(uint32_t*)((char*)(a0) + 16); }

// sub_a8090  (orig 0xa8090, ptr_add)
void* sdk_f_a8090(void* a0) { return (char*)a0 + 128; }

// sub_a80a0  (orig 0xa80a0, ptr_add)
void* sdk_f_a80a0(void* a0) { return (char*)a0 + 320; }

// sub_a80b0  (orig 0xa80b0, setter)
void sdk_f_a80b0(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 11) = a1; }

// sub_a80d0  (orig 0xa80d0, getter)
uint8_t sdk_f_a80d0(void* a0) { return *(uint8_t*)((char*)(a0) + 11); }

// sub_a8120  (orig 0xa8120, setter-chain)
void sdk_f_a8120(uint64_t unused0, void* a1) { *(uint32_t*)((char*)(a1)) = 0; *(uint64_t*)((char*)(a1) + 8) = 0; }

// sub_a8130  (orig 0xa8130, ret_only)
void sdk_f_a8130() {}

// sub_a8140  (orig 0xa8140, mov_ret)
uint64_t sdk_f_a8140() { return 0; }

// sub_a8230  (orig 0xa8230, straight-line)
void sdk_f_a8230(void* a0) {
    *(uint8_t*)((char*)(a0) + 11) = (uint8_t)((((*(uint8_t*)((char*)(a0) + 9) == 0)) ? ((2) + (1)) : (2)));
}

// sub_a8370  (orig 0xa8370, straight-line)
void sdk_f_a8370(void* a0) {
    uint32_t k0 = 2;
    *(uint8_t*)((char*)(a0) + 11) = (uint8_t)((((*(uint8_t*)((char*)(a0) + 9) == 0)) ? ((2) + (1)) : (2)));
    *(uint8_t*)((char*)(a0) + 180) = (uint8_t)k0;
}

// sub_a8530  (orig 0xa8530, straight-line)
void sdk_f_a8530(void* a0) {
    uint32_t k0 = 2;
    *(uint8_t*)((char*)(a0) + 11) = (uint8_t)((((*(uint8_t*)((char*)(a0) + 9) == 0)) ? ((2) + (1)) : (2)));
    *(uint8_t*)((char*)(a0) + 192) = (uint8_t)k0;
}

// sub_a86f0  (orig 0xa86f0, straight-line)
void sdk_f_a86f0(void* a0) {
    uint32_t k0 = 2;
    *(uint8_t*)((char*)(a0) + 11) = (uint8_t)((((*(uint8_t*)((char*)(a0) + 9) == 0)) ? ((2) + (1)) : (2)));
    *(uint8_t*)((char*)(a0) + 200) = (uint8_t)k0;
}

// sub_a88c0  (orig 0xa88c0, straight-line)
void sdk_f_a88c0(void* a0) {
    *(uint8_t*)((char*)(a0) + 11) = (uint8_t)((((*(uint8_t*)((char*)(a0) + 9) == 0)) ? ((2) + (1)) : (2)));
}

// sub_a8940  (orig 0xa8940, straight-line)
void sdk_f_a8940(void* a0) {
    uint32_t k0 = 2;
    *(uint8_t*)((char*)(a0) + 11) = (uint8_t)((((*(uint8_t*)((char*)(a0) + 9) == 0)) ? ((2) + (1)) : (2)));
    *(uint8_t*)((char*)(a0) + 151) = (uint8_t)k0;
}

// sub_a8960  (orig 0xa8960, setter-chain)
void sdk_f_a8960(void* a0) { *(uint64_t*)((char*)(a0)) = 0; *(uint32_t*)((char*)(a0) + 8) = 0; }

// sub_a8970  (orig 0xa8970, setter-chain)
void sdk_f_a8970(void* a0, uint64_t a1, uint32_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint32_t*)((char*)(a0) + 8) = a2; }

// sub_a8980  (orig 0xa8980, straight-line)
uint64_t sdk_f_a8980(void* a0, uint32_t a1) { return (*(uint64_t*)((char*)(a0))) + ((((int64_t)(((int32_t)(((uint32_t)a1)))))) * (((int64_t)(((int32_t)(1216)))))); }

// sub_a8990  (orig 0xa8990, getter)
uint32_t sdk_f_a8990(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_a89a0  (orig 0xa89a0, setter-chain)
void sdk_f_a89a0(void* a0, uint32_t a1) { *(uint64_t*)((char*)(a0) + 24) = 0; *(uint64_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint32_t*)((char*)(a0) + 32) = a1; }

// sub_a89b0  (orig 0xa89b0, getter)
uint64_t sdk_f_a89b0(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_a89c0  (orig 0xa89c0, getter)
uint64_t sdk_f_a89c0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_a89d0  (orig 0xa89d0, getter)
uint64_t sdk_f_a89d0(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_a89e0  (orig 0xa89e0, getter)
uint32_t sdk_f_a89e0(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_a89f0  (orig 0xa89f0, setter-chain)
void sdk_f_a89f0(void* a0, uint64_t a1, uint64_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 24) = a2; }

// sub_a8a00  (orig 0xa8a00, setter)
void sdk_f_a8a00(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 8) = a1; }

// sub_a8a40  (orig 0xa8a40, compare)
bool sdk_f_a8a40(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 8)) != (uint64_t)(0); }

// sub_a8aa0  (orig 0xa8aa0, straight)
void sdk_f_a8aa0(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0) + 36) = (uint8_t)((((uint32_t)a1)) & (1));
}

// sub_a8ab0  (orig 0xa8ab0, getter)
uint8_t sdk_f_a8ab0(void* a0) { return *(uint8_t*)((char*)(a0) + 36); }

// sub_a8ca0  (orig 0xa8ca0, getter)
uint64_t sdk_f_a8ca0(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_a8cb0  (orig 0xa8cb0, setter)
void sdk_f_a8cb0(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 16) = a1; }

// sub_a8cc0  (orig 0xa8cc0, getter)
uint64_t sdk_f_a8cc0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_a8cd0  (orig 0xa8cd0, setter)
void sdk_f_a8cd0(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 24) = a1; }

// sub_a8ea0  (orig 0xa8ea0, setter-chain)
void sdk_f_a8ea0(void* a0, uint64_t a1, uint64_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 8) = a2; *(uint64_t*)((char*)(a0) + 16) = 0; *(uint64_t*)((char*)(a0) + 24) = 0; }

// sub_a8eb0  (orig 0xa8eb0, getter)
uint8_t sdk_f_a8eb0(void* a0) { return *(uint8_t*)((char*)(a0) + 20); }

// sub_a8f30  (orig 0xa8f30, straight)
void sdk_f_a8f30(void* a0, uint64_t a1, uint32_t a2) {
    *(uint32_t*)((char*)(a0)) = (uint32_t)(a1);
    *(uint64_t*)((char*)(a0) + 8) = 0;
    *(uint32_t*)((char*)(a0) + 16) = 0;
    *(uint8_t*)((char*)(a0) + 20) = (uint8_t)((((uint32_t)a2)) & (1));
}

// sub_a8f50  (orig 0xa8f50, straight)
void sdk_f_a8f50(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint32_t a4) {
    *(uint32_t*)((char*)(a0)) = (uint32_t)(a1);
    *(uint64_t*)((char*)(a0) + 8) = a2;
    *(uint32_t*)((char*)(a0) + 16) = (uint32_t)(a3);
    *(uint8_t*)((char*)(a0) + 20) = (uint8_t)((((uint32_t)a4)) & (1));
}

// sub_a9030  (orig 0xa9030, call)
extern void callee_514a20();
uint32_t sdk_f_a9030(uint64_t unused0, uint32_t a1, uint64_t a2, uint64_t a3) {
    uint64_t f_a9030__r0 = ((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_514a20)(((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))));
    uint32_t r0 = 1;
    asm volatile("");
    return r0;
}

// sub_a92f0  (orig 0xa92f0, setter-chain)
void sdk_f_a92f0(void* a0, uint64_t a1, uint64_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 8) = a2; *(uint64_t*)((char*)(a0) + 16) = 0; *(uint64_t*)((char*)(a0) + 24) = 0; }

// sub_a9300  (orig 0xa9300, setter-chain-zero)
void sdk_f_a9300(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_a93e0  (orig 0xa93e0, getter)
uint64_t sdk_f_a93e0(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_a9940  (orig 0xa9940, getter-chain)
uint64_t sdk_f_a9940(void* a0, int32_t a1) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(uint64_t*)((char*)(t0) + (uintptr_t)(a1) * 8);
}

// sub_a9950  (orig 0xa9950, straight-line)
void sdk_f_a9950(void* a0, int32_t a1, uint64_t a2) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    *(uint64_t*)(((char*)(p0) + (uintptr_t)a1 * 8)) = a2;
}

// sub_a9960  (orig 0xa9960, straight-line)
uint64_t sdk_f_a9960(void* a0, uint32_t a1) { return (*(uint64_t*)((char*)(a0) + 8)) + ((((int64_t)(((int32_t)(((uint32_t)a1)))))) * (((int64_t)(((int32_t)(2368)))))); }

// sub_a9970  (orig 0xa9970, getter)
uint64_t sdk_f_a9970(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_a9980  (orig 0xa9980, getter)
uint32_t sdk_f_a9980(void* a0) { return *(uint32_t*)((char*)(a0) + 16); }

// sub_aa9e0  (orig 0xaa9e0, setter-chain-zero)
void sdk_f_aa9e0(uint64_t unused0, void* a1, void* a2) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a2 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a2 = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)(char*)a1 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a1 + 8) = 0;
}

// sub_aaa00  (orig 0xaaa00, ret_only)
void sdk_f_aaa00() {}

// sub_aaa10  (orig 0xaaa10, ptr_add)
void* sdk_f_aaa10(void* a0) { return (char*)a0 + 32; }

// sub_aaa20  (orig 0xaaa20, getter)
uint8_t sdk_f_aaa20(void* a0) { return *(uint8_t*)((char*)(a0) + 8); }

// sub_aaa30  (orig 0xaaa30, getter)
uint8_t sdk_f_aaa30(void* a0) { return *(uint8_t*)((char*)(a0) + 9); }

// sub_aaa40  (orig 0xaaa40, getter)
uint8_t sdk_f_aaa40(void* a0) { return *(uint8_t*)((char*)(a0) + 10); }

// sub_aaa50  (orig 0xaaa50, getter)
uint32_t sdk_f_aaa50(void* a0) { return *(uint32_t*)((char*)(a0) + 12); }

// sub_aaa60  (orig 0xaaa60, setter)
void sdk_f_aaa60(void* a0) { *(uint16_t*)((char*)(a0) + 8) = 0; }

// sub_aaa70  (orig 0xaaa70, ptr_add)
void* sdk_f_aaa70(void* a0) { return (char*)a0 + 32; }

// sub_aaa80  (orig 0xaaa80, ptr_add)
void* sdk_f_aaa80(void* a0) { return (char*)a0 + 80; }

// sub_aabf0  (orig 0xaabf0, ret_only)
void sdk_f_aabf0() {}

// sub_aac90  (orig 0xaac90, straight)
uint8_t sdk_f_aac90(void* a0, void* a1) { return (((*(uint8_t*)((char*)(a0) + 9) != *(uint8_t*)((char*)(a1) + 1)) ? 1 : 0)) | (((*(uint8_t*)((char*)(a0) + 10) != 0) ? 1 : 0)); }

// sub_aad70  (orig 0xaad70, setter-chain-zero)
void sdk_f_aad70(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint16_t*)((char*)a0 + 8) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
}

// sub_aadd0  (orig 0xaadd0, setter-chain)
void sdk_f_aadd0(void* a0) { *(uint64_t*)((char*)(a0)) = 0; *(uint32_t*)((char*)(a0) + 8) = 0; }

// sub_aade0  (orig 0xaade0, setter-chain)
void sdk_f_aade0(void* a0, uint64_t a1, uint32_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint32_t*)((char*)(a0) + 8) = a2; }

// sub_aadf0  (orig 0xaadf0, straight-line)
uint64_t sdk_f_aadf0(void* a0, uint32_t a1) { return (*(uint64_t*)((char*)(a0))) + ((((int64_t)(((int32_t)(((uint32_t)a1)))))) * (((int64_t)(((int32_t)(368)))))); }

// sub_aae00  (orig 0xaae00, getter)
uint32_t sdk_f_aae00(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_aae60  (orig 0xaae60, setter-chain-zero)
void sdk_f_aae60(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 184) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 168) = (struct u64x2){ 0, 0 };
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

// sub_aaea0  (orig 0xaaea0, getter)
uint32_t sdk_f_aaea0(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_aaee0  (orig 0xaaee0, getter)
uint32_t sdk_f_aaee0(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_aaf10  (orig 0xaaf10, ptr_add)
void* sdk_f_aaf10(void* a0) { return (char*)a0 + 8; }

// sub_aaf40  (orig 0xaaf40, ptr_add)
void* sdk_f_aaf40(void* a0) { return (char*)a0 + 104; }

// sub_ab0c0  (orig 0xab0c0, straight)
void sdk_f_ab0c0(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 209) = (uint8_t)k0;
}

// sub_ab120  (orig 0xab120, straight-line)
void sdk_f_ab120(void* a0, uint64_t a1) {
    *(uint32_t*)((char*)(a0)) = (uint32_t)(a1);
    *(uint32_t*)((char*)(a0) + 28) = 0;
    *(uint64_t*)((char*)(a0) + 20) = 0;
    *(uint64_t*)((char*)(a0) + 12) = 0;
    *(uint64_t*)((char*)(a0) + 4) = 0;
}

// sub_ab230  (orig 0xab230, getter)
uint32_t sdk_f_ab230(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_ab240  (orig 0xab240, getter)
uint8_t sdk_f_ab240(void* a0) { return *(uint8_t*)((char*)(a0) + 12); }

// sub_ab250  (orig 0xab250, setter)
void sdk_f_ab250(void* a0) { *(uint8_t*)((char*)(a0) + 12) = 0; }

// sub_ab300  (orig 0xab300, straight-line)
void* sdk_f_ab300(void* a0, uint32_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0)));
    return ((char *)(char*)(p0) + (uintptr_t)(((int64_t)(((int32_t)(((uint32_t)a1)))))) * 32);
}

// sub_ab310  (orig 0xab310, getter)
uint32_t sdk_f_ab310(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_ab320  (orig 0xab320, getter)
uint32_t sdk_f_ab320(void* a0) { return *(uint32_t*)((char*)(a0) + 8); }

// sub_ab330  (orig 0xab330, straight-line)
uint64_t sdk_f_ab330(void* a0, uint32_t a1) { return (*(uint64_t*)((char*)(a0) + 16)) + ((((int64_t)(((int32_t)(((uint32_t)a1)))))) * (((int64_t)(((int32_t)(224)))))); }

// sub_ab340  (orig 0xab340, straight)
void sdk_f_ab340(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint32_t a5) {
    *(uint64_t*)((char*)(a0)) = a1;
    *(uint32_t*)((char*)(a0) + 8) = (uint32_t)(a2);
    *(uint64_t*)((char*)(a0) + 16) = a3;
    *(uint32_t*)((char*)(a0) + 24) = (uint32_t)(a4);
    *(uint8_t*)((char*)(a0) + 28) = (uint8_t)((((uint32_t)a5)) & (1));
}

// sub_ac850  (orig 0xac850, straight)
uint8_t sdk_f_ac850(void* a0, void* a1) { return (((*(uint8_t*)((char*)(a1) + 26) == 0) ? 1 : 0)) | (((*(uint8_t*)((char*)(a0) + 538) != 0) ? 1 : 0)); }

// sub_ad500  (orig 0xad500, straight-line)
void* sdk_f_ad500(void* a0, uint32_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 32));
    return ((char *)(char*)(p0) + (uintptr_t)(((int64_t)(((int32_t)(((uint32_t)a1)))))) * 256);
}

// sub_ad510  (orig 0xad510, straight-line)
void* sdk_f_ad510(void* a0, uint32_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 24));
    return ((char *)(char*)(p0) + (uintptr_t)(((int64_t)(((int32_t)(((uint32_t)a1)))))) * 256);
}

// sub_ad520  (orig 0xad520, straight-line)
uint64_t sdk_f_ad520(void* a0, uint32_t a1) { return (*(uint64_t*)((char*)(a0) + 16)) + ((((int64_t)(((int32_t)(((uint32_t)a1)))))) * (((int64_t)(((int32_t)(208)))))); }

// sub_ad550  (orig 0xad550, setter-chain-zero)
void sdk_f_ad550(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_ad560  (orig 0xad560, getter-chain)
uint64_t sdk_f_ad560(void* a0, int32_t a1) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(uint64_t*)((char*)(t0) + (uintptr_t)(a1) * 8);
}

// sub_ad570  (orig 0xad570, straight-line)
uint64_t sdk_f_ad570(void* a0, uint32_t a1) { return (*(uint64_t*)((char*)(a0) + 8)) + ((((int64_t)(((int32_t)(((uint32_t)a1)))))) * (((int64_t)(((int32_t)(544)))))); }

// sub_ad580  (orig 0xad580, getter)
uint32_t sdk_f_ad580(void* a0) { return *(uint32_t*)((char*)(a0) + 40); }

// sub_ad590  (orig 0xad590, getter)
uint32_t sdk_f_ad590(void* a0) { return *(uint32_t*)((char*)(a0) + 44); }

// sub_ad5a0  (orig 0xad5a0, setter)
void sdk_f_ad5a0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 44) = a1; }

// sub_aeae0  (orig 0xaeae0, ret_only)
void sdk_f_aeae0() {}

// sub_aeaf0  (orig 0xaeaf0, ret_only)
void sdk_f_aeaf0() {}

// sub_aeb00  (orig 0xaeb00, mov_ret)
uint32_t sdk_f_aeb00() { return 0; }

// sub_aeb10  (orig 0xaeb10, ret_only)
void sdk_f_aeb10() {}

// sub_aeb20  (orig 0xaeb20, float_const)
float sdk_f_aeb20() { return 1.00000000f; }

// sub_aeb30  (orig 0xaeb30, ret_only)
void sdk_f_aeb30() {}

// sub_aeb40  (orig 0xaeb40, const-ret)
uint32_t sdk_f_aeb40() { return 263321u; }

// sub_aeb50  (orig 0xaeb50, const-ret)
uint32_t sdk_f_aeb50() { return 263321u; }

// sub_aeb60  (orig 0xaeb60, const-ret)
uint32_t sdk_f_aeb60() { return 263321u; }

// sub_aeb70  (orig 0xaeb70, mov_ret)
uint32_t sdk_f_aeb70() { return 0; }

// sub_aeb90  (orig 0xaeb90, ret_only)
void sdk_f_aeb90() {}

// sub_aeba0  (orig 0xaeba0, ret_only)
void sdk_f_aeba0() {}

// sub_aebb0  (orig 0xaebb0, ret_only)
void sdk_f_aebb0() {}

// sub_aebc0  (orig 0xaebc0, ret_only)
void sdk_f_aebc0() {}

// sub_aebd0  (orig 0xaebd0, ret_only)
void sdk_f_aebd0() {}

// sub_aebe0  (orig 0xaebe0, ret_only)
void sdk_f_aebe0() {}

// sub_aebf0  (orig 0xaebf0, ret_only)
void sdk_f_aebf0() {}

// sub_aec00  (orig 0xaec00, ret_only)
void sdk_f_aec00() {}

// sub_aec10  (orig 0xaec10, ret_only)
void sdk_f_aec10() {}

// sub_aec20  (orig 0xaec20, ret_only)
void sdk_f_aec20() {}

// sub_aec30  (orig 0xaec30, ret_only)
void sdk_f_aec30() {}

// sub_aec40  (orig 0xaec40, ret_only)
void sdk_f_aec40() {}

// sub_aec50  (orig 0xaec50, ret_only)
void sdk_f_aec50() {}

// sub_aec60  (orig 0xaec60, ret_only)
void sdk_f_aec60() {}

// sub_aec70  (orig 0xaec70, ret_only)
void sdk_f_aec70() {}

// sub_aec80  (orig 0xaec80, ret_only)
void sdk_f_aec80() {}

// sub_aec90  (orig 0xaec90, ret_only)
void sdk_f_aec90() {}

// sub_aeca0  (orig 0xaeca0, ret_only)
void sdk_f_aeca0() {}

// sub_aecb0  (orig 0xaecb0, ret_only)
void sdk_f_aecb0() {}

// sub_aecc0  (orig 0xaecc0, ret_only)
void sdk_f_aecc0() {}

// sub_aecd0  (orig 0xaecd0, ret_only)
void sdk_f_aecd0() {}

// sub_aece0  (orig 0xaece0, ret_only)
void sdk_f_aece0() {}

// sub_aecf0  (orig 0xaecf0, ret_only)
void sdk_f_aecf0() {}

// sub_aed00  (orig 0xaed00, ret_only)
void sdk_f_aed00() {}

// sub_aed20  (orig 0xaed20, ret_only)
void sdk_f_aed20() {}

// sub_aed30  (orig 0xaed30, ret_only)
void sdk_f_aed30() {}

// sub_aede0  (orig 0xaede0, call)
extern void callee_514cb0();
uint64_t sdk_f_aede0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t))&callee_514cb0)(((uintptr_t)((char*)(a0) + 16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_aeee0  (orig 0xaeee0, ret_only)
void sdk_f_aeee0() {}

// sub_aeef0  (orig 0xaeef0, ret_only)
void sdk_f_aeef0() {}

// sub_af340  (orig 0xaf340, setter-chain)
void sdk_f_af340(void* a0) { *(uint64_t*)((char*)(a0)) = 0; *(uint32_t*)((char*)(a0) + 8) = 0; }

// sub_af770  (orig 0xaf770, ret_only)
void sdk_f_af770() {}

// sub_af780  (orig 0xaf780, ret_only)
void sdk_f_af780() {}

// sub_af7d0  (orig 0xaf7d0, setter)
void sdk_f_af7d0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 24) = a1; }

// sub_b05d0  (orig 0xb05d0, getter)
uint32_t sdk_f_b05d0(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_b05e0  (orig 0xb05e0, getter)
uint32_t sdk_f_b05e0(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_b05f0  (orig 0xb05f0, getter)
uint32_t sdk_f_b05f0(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_b0600  (orig 0xb0600, getter)
uint64_t sdk_f_b0600(void* a0) { return *(uint64_t*)((char*)(a0) + 40); }

// sub_b0610  (orig 0xb0610, getter)
uint32_t sdk_f_b0610(void* a0) { return *(uint32_t*)((char*)(a0) + 48); }

// sub_b0620  (orig 0xb0620, getter)
uint32_t sdk_f_b0620(void* a0) { return *(uint32_t*)((char*)(a0) + 52); }

// sub_b0630  (orig 0xb0630, straight)
uint32_t sdk_f_b0630(void* a0) { return (*(uint32_t*)((char*)(a0) + 28)) - (*(uint32_t*)((char*)(a0) + 52)); }

// sub_b26f0  (orig 0xb26f0, mov_ret)
uint64_t sdk_f_b26f0() { return 0; }

// sub_b2700  (orig 0xb2700, ret_only)
void sdk_f_b2700() {}

// sub_b2710  (orig 0xb2710, ret_only)
void sdk_f_b2710() {}

// sub_b2720  (orig 0xb2720, ret_only)
void sdk_f_b2720() {}

// sub_b2730  (orig 0xb2730, ret_only)
void sdk_f_b2730() {}

// sub_b2740  (orig 0xb2740, ret_only)
void sdk_f_b2740() {}

// sub_b2750  (orig 0xb2750, mov_ret)
uint64_t sdk_f_b2750(uint64_t a0, uint64_t a1) { return a1; }

// sub_b2760  (orig 0xb2760, ret_only)
void sdk_f_b2760() {}

// sub_b2770  (orig 0xb2770, ret_only)
void sdk_f_b2770() {}

// sub_b2780  (orig 0xb2780, ret_only)
void sdk_f_b2780() {}

// sub_b2790  (orig 0xb2790, ret_only)
void sdk_f_b2790() {}

// sub_b27a0  (orig 0xb27a0, mov_ret)
uint32_t sdk_f_b27a0() { return 0; }

// sub_b27b0  (orig 0xb27b0, ret_only)
void sdk_f_b27b0() {}

// sub_b27d0  (orig 0xb27d0, ret_only)
void sdk_f_b27d0() {}

// sub_b27e0  (orig 0xb27e0, ret_only)
void sdk_f_b27e0() {}

// sub_b27f0  (orig 0xb27f0, ret_only)
void sdk_f_b27f0() {}

// sub_b2800  (orig 0xb2800, ret_only)
void sdk_f_b2800() {}

// sub_befb0  (orig 0xbefb0, straight)
void sdk_f_befb0(void* a0) {
    *(uint32_t*)((char*)(a0)) = 2;
}

// sub_befc0  (orig 0xbefc0, straight)
void sdk_f_befc0(void* a0) {
    *(uint32_t*)((char*)(a0)) = 3;
}

// sub_befd0  (orig 0xbefd0, setter)
void sdk_f_befd0(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 96) = a1; }

// sub_c08b0  (orig 0xc08b0, setter)
void sdk_f_c08b0(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_c1140  (orig 0xc1140, setter)
void sdk_f_c1140(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_c31e0  (orig 0xc31e0, ptr_add)
void* sdk_f_c31e0(void* a0) { return (char*)a0 + 32; }

// sub_c3400  (orig 0xc3400, ptr_add)
void* sdk_f_c3400(void* a0) { return (char*)a0 + 8; }

// sub_c3410  (orig 0xc3410, straight)
void* sdk_f_c3410(void* a0) { return (char*)(a0) - 24; }

// sub_c3540  (orig 0xc3540, ptr_add)
void* sdk_f_c3540(void* a0) { return (char*)a0 + 32; }

// sub_c36a0  (orig 0xc36a0, call)
extern void callee_511510();
uint64_t sdk_f_c36a0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_511510)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(10200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c3830  (orig 0xc3830, call)
extern void callee_5151a0();
uint64_t sdk_f_c3830(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5151a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(30100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c3860  (orig 0xc3860, call)
extern void callee_5151b0();
uint64_t sdk_f_c3860(void* a0, uint64_t a1, uint32_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5151b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(30200)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c3890  (orig 0xc3890, call)
extern void callee_511670();
uint64_t sdk_f_c3890(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30201)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c38b0  (orig 0xc38b0, call)
extern void callee_511670();
uint64_t sdk_f_c38b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30202)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c38d0  (orig 0xc38d0, call)
extern void callee_511670();
uint64_t sdk_f_c38d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(30203)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c38f0  (orig 0xc38f0, call)
extern void callee_511500();
uint64_t sdk_f_c38f0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (6))), ((uintptr_t)(90100)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c3950  (orig 0xc3950, call)
extern void callee_511670();
uint64_t sdk_f_c3950(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511670)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(90201)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c3980  (orig 0xc3980, call)
extern void callee_511500();
uint64_t sdk_f_c3980(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (4))), ((uintptr_t)(90300)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c39b0  (orig 0xc39b0, ptr_add)
void* sdk_f_c39b0(void* a0) { return (char*)a0 + 8; }

// sub_c39c0  (orig 0xc39c0, straight)
void* sdk_f_c39c0(void* a0) { return (char*)(a0) - 24; }

// sub_c3af0  (orig 0xc3af0, ptr_add)
void* sdk_f_c3af0(void* a0) { return (char*)a0 + 32; }

// sub_c3b20  (orig 0xc3b20, call)
extern void callee_5151d0();
uint64_t sdk_f_c3b20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5151d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(512)), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c3b50  (orig 0xc3b50, ptr_add)
void* sdk_f_c3b50(void* a0) { return (char*)a0 + 8; }

// sub_c3b60  (orig 0xc3b60, straight)
void* sdk_f_c3b60(void* a0) { return (char*)(a0) - 24; }

// sub_c4470  (orig 0xc4470, ptr_add)
void* sdk_f_c4470(void* a0) { return (char*)a0 + 32; }

// sub_c45c0  (orig 0xc45c0, call)
extern void callee_511500();
uint64_t sdk_f_c45c0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) << (5))), ((uintptr_t)(10)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c45f0  (orig 0xc45f0, ptr_add)
void* sdk_f_c45f0(void* a0) { return (char*)a0 + 8; }

// sub_c4600  (orig 0xc4600, straight)
void* sdk_f_c4600(void* a0) { return (char*)(a0) - 24; }

// sub_c4730  (orig 0xc4730, ptr_add)
void* sdk_f_c4730(void* a0) { return (char*)a0 + 32; }

// sub_c4760  (orig 0xc4760, call)
extern void callee_515210();
uint64_t sdk_f_c4760(void* a0, uint64_t a1, uint64_t a2, void* a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515210)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(*(uint64_t*)((char*)(a3)))), ((uintptr_t)(*(uint64_t*)((char*)(a3) + 8))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c4790  (orig 0xc4790, call)
extern void callee_511520();
uint64_t sdk_f_c4790(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511520)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c47b0  (orig 0xc47b0, call)
extern void callee_5113c0();
uint64_t sdk_f_c47b0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5113c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c47d0  (orig 0xc47d0, ptr_add)
void* sdk_f_c47d0(void* a0) { return (char*)a0 + 8; }

// sub_c47e0  (orig 0xc47e0, straight)
void* sdk_f_c47e0(void* a0) { return (char*)(a0) - 24; }

// sub_c4ca0  (orig 0xc4ca0, ptr_add)
void* sdk_f_c4ca0(void* a0) { return (char*)a0 + 32; }

// sub_c4cd0  (orig 0xc4cd0, call)
extern void callee_511500();
uint64_t sdk_f_c4cd0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_511500)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)((*(uint64_t*)((char*)(a2) + 8)) * (56))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c4d00  (orig 0xc4d00, call)
extern void callee_511390();
uint64_t sdk_f_c4d00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_511390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c4d20  (orig 0xc4d20, ptr_add)
void* sdk_f_c4d20(void* a0) { return (char*)a0 + 8; }

// sub_c4d30  (orig 0xc4d30, straight)
void* sdk_f_c4d30(void* a0) { return (char*)(a0) - 24; }

// sub_c4f90  (orig 0xc4f90, ptr_add)
void* sdk_f_c4f90(void* a0) { return (char*)a0 + 16; }

// sub_c4fc0  (orig 0xc4fc0, call)
extern void callee_5126d0();
uint64_t sdk_f_c4fc0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c4fe0  (orig 0xc4fe0, call)
extern void callee_512700();
uint64_t sdk_f_c4fe0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5000  (orig 0xc5000, call)
extern void callee_512700();
uint64_t sdk_f_c5000(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5020  (orig 0xc5020, call)
extern void callee_512700();
uint64_t sdk_f_c5020(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5040  (orig 0xc5040, call)
extern void callee_515240();
uint64_t sdk_f_c5040(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515240)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(259)), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5070  (orig 0xc5070, call)
extern void callee_515250();
uint64_t sdk_f_c5070(void* a0, uint32_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515250)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c50a0  (orig 0xc50a0, call)
extern void callee_515260();
uint64_t sdk_f_c50a0(void* a0, uint32_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515260)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c50d0  (orig 0xc50d0, call)
extern void callee_512700();
uint64_t sdk_f_c50d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c50f0  (orig 0xc50f0, call)
extern void callee_512700();
uint64_t sdk_f_c50f0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5150  (orig 0xc5150, call)
extern void callee_515280();
uint64_t sdk_f_c5150(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(11)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5180  (orig 0xc5180, call)
extern void callee_515280();
uint64_t sdk_f_c5180(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(12)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c51b0  (orig 0xc51b0, call)
extern void callee_515290();
uint64_t sdk_f_c51b0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515290)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)((((uint64_t)a3)) & (255))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(13)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c51e0  (orig 0xc51e0, call)
extern void callee_5152a0();
uint64_t sdk_f_c51e0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint32_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)((((uint64_t)a3)) & (255))), ((uintptr_t)(((uint32_t)a4))), ((uintptr_t)(14)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5210  (orig 0xc5210, call)
extern void callee_5152b0();
uint64_t sdk_f_c5210(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(15)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5240  (orig 0xc5240, call)
extern void callee_5152c0();
uint64_t sdk_f_c5240(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (65535))), ((uintptr_t)(16)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5270  (orig 0xc5270, call)
extern void callee_515280();
uint64_t sdk_f_c5270(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c52a0  (orig 0xc52a0, call)
extern void callee_515280();
uint64_t sdk_f_c52a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c52d0  (orig 0xc52d0, call)
extern void callee_5152d0();
uint64_t sdk_f_c52d0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(642)), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5300  (orig 0xc5300, call)
extern void callee_5152e0();
uint64_t sdk_f_c5300(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(20)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5330  (orig 0xc5330, call)
extern void callee_5152f0();
uint64_t sdk_f_c5330(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(642)), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5360  (orig 0xc5360, call)
extern void callee_515300();
uint64_t sdk_f_c5360(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515300)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (255))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5390  (orig 0xc5390, call)
extern void callee_515280();
uint64_t sdk_f_c5390(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515280)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c53c0  (orig 0xc53c0, call)
extern void callee_515310();
uint64_t sdk_f_c53c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515310)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(512)), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c53f0  (orig 0xc53f0, call)
extern void callee_515320();
uint64_t sdk_f_c53f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515320)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(512)), ((uintptr_t)(25)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5420  (orig 0xc5420, call)
extern void callee_512700();
uint64_t sdk_f_c5420(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(26)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5440  (orig 0xc5440, call)
extern void callee_5152b0();
uint64_t sdk_f_c5440(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(27)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5470  (orig 0xc5470, call)
extern void callee_515330();
uint64_t sdk_f_c5470(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515330)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)(28)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c54a0  (orig 0xc54a0, call)
extern void callee_515330();
uint64_t sdk_f_c54a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515330)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(29)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c54d0  (orig 0xc54d0, call)
extern void callee_5152e0();
uint64_t sdk_f_c54d0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(30)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5500  (orig 0xc5500, call)
extern void callee_512760();
uint64_t sdk_f_c5500(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(31)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5530  (orig 0xc5530, call)
extern void callee_512700();
uint64_t sdk_f_c5530(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5550  (orig 0xc5550, call)
extern void callee_512700();
uint64_t sdk_f_c5550(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(33)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5570  (orig 0xc5570, call)
extern void callee_512760();
uint64_t sdk_f_c5570(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(34)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c55a0  (orig 0xc55a0, call)
extern void callee_515340();
uint64_t sdk_f_c55a0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515340)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(35)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c55d0  (orig 0xc55d0, call)
extern void callee_512760();
uint64_t sdk_f_c55d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(36)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5600  (orig 0xc5600, call)
extern void callee_5126d0();
uint64_t sdk_f_c5600(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(37)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5620  (orig 0xc5620, call)
extern void callee_5126d0();
uint64_t sdk_f_c5620(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(38)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5640  (orig 0xc5640, call)
extern void callee_515350();
uint64_t sdk_f_c5640(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515350)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(132)), ((uintptr_t)(39)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5670  (orig 0xc5670, call)
extern void callee_512700();
uint64_t sdk_f_c5670(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(40)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5690  (orig 0xc5690, call)
extern void callee_515360();
uint64_t sdk_f_c5690(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515360)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(136)), ((uintptr_t)(41)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c56c0  (orig 0xc56c0, call)
extern void callee_512760();
uint64_t sdk_f_c56c0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(42)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c56f0  (orig 0xc56f0, call)
extern void callee_512710();
uint64_t sdk_f_c56f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(43)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5710  (orig 0xc5710, call)
extern void callee_512760();
uint64_t sdk_f_c5710(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(44)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5740  (orig 0xc5740, call)
extern void callee_512710();
uint64_t sdk_f_c5740(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(45)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5760  (orig 0xc5760, call)
extern void callee_5126d0();
uint64_t sdk_f_c5760(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(46)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5780  (orig 0xc5780, call)
extern void callee_512700();
uint64_t sdk_f_c5780(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(47)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c57a0  (orig 0xc57a0, call)
extern void callee_512700();
uint64_t sdk_f_c57a0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(48)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c57c0  (orig 0xc57c0, call)
extern void callee_512700();
uint64_t sdk_f_c57c0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(49)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c57e0  (orig 0xc57e0, call)
extern void callee_515340();
uint64_t sdk_f_c57e0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515340)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)((((uint64_t)a2)) & (1))), ((uintptr_t)(50)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5810  (orig 0xc5810, call)
extern void callee_515370();
uint64_t sdk_f_c5810(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(51)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5830  (orig 0xc5830, call)
extern void callee_515370();
uint64_t sdk_f_c5830(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_515370)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(52)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5850  (orig 0xc5850, call)
extern void callee_515380();
uint64_t sdk_f_c5850(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515380)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(204)), ((uintptr_t)(53)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5880  (orig 0xc5880, call)
extern void callee_515390();
uint64_t sdk_f_c5880(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515390)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)((((uint64_t)a2)) & (65535))), ((uintptr_t)((((uint64_t)a3)) & (65535))), ((uintptr_t)(54)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c58b0  (orig 0xc58b0, call)
extern void callee_512700();
uint64_t sdk_f_c58b0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(55)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c58d0  (orig 0xc58d0, call)
extern void callee_512700();
uint64_t sdk_f_c58d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(56)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c58f0  (orig 0xc58f0, call)
extern void callee_5153a0();
uint64_t sdk_f_c58f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5153a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(62)), ((uintptr_t)(57)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5920  (orig 0xc5920, call)
extern void callee_5153a0();
uint64_t sdk_f_c5920(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5153a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(62)), ((uintptr_t)(58)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5950  (orig 0xc5950, call)
extern void callee_512760();
uint64_t sdk_f_c5950(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(59)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5980  (orig 0xc5980, call)
extern void callee_512700();
uint64_t sdk_f_c5980(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(60)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c59a0  (orig 0xc59a0, call)
extern void callee_512760();
uint64_t sdk_f_c59a0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (1))), ((uintptr_t)(61)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c59d0  (orig 0xc59d0, call)
extern void callee_5153b0();
uint64_t sdk_f_c59d0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5153b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(62)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c59f0  (orig 0xc59f0, call)
extern void callee_512760();
uint64_t sdk_f_c59f0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(63)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5a20  (orig 0xc5a20, call)
extern void callee_512700();
uint64_t sdk_f_c5a20(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(64)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5a40  (orig 0xc5a40, call)
extern void callee_5153c0();
uint64_t sdk_f_c5a40(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5153c0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)((((uint64_t)a3)) & (281474976710655))), ((uintptr_t)((((uint64_t)a4)) & (1))), ((uintptr_t)(65)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5a70  (orig 0xc5a70, call)
extern void callee_5153d0();
uint64_t sdk_f_c5a70(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5153d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)((((uint64_t)a2)) & (281474976710655))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(66)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5aa0  (orig 0xc5aa0, call)
extern void callee_512780();
uint64_t sdk_f_c5aa0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(67)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5ad0  (orig 0xc5ad0, call)
extern void callee_5153e0();
uint64_t sdk_f_c5ad0(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5153e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (281474976710655))), ((uintptr_t)(68)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5b00  (orig 0xc5b00, call)
extern void callee_5153f0();
uint64_t sdk_f_c5b00(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5153f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(69)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5b30  (orig 0xc5b30, call)
extern void callee_515400();
uint64_t sdk_f_c5b30(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515400)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (65535))), ((uintptr_t)(70)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5b60  (orig 0xc5b60, call)
extern void callee_5153b0();
uint64_t sdk_f_c5b60(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5153b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(71)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5b80  (orig 0xc5b80, call)
extern void callee_512760();
uint64_t sdk_f_c5b80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512760)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(72)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5bb0  (orig 0xc5bb0, call)
extern void callee_5153d0();
uint64_t sdk_f_c5bb0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5153d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)((((uint64_t)a2)) & (281474976710655))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(73)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5be0  (orig 0xc5be0, call)
extern void callee_515410();
uint64_t sdk_f_c5be0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515410)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)((((uint64_t)a2)) & (281474976710655))), ((uintptr_t)(74)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5c10  (orig 0xc5c10, call)
extern void callee_515420();
uint64_t sdk_f_c5c10(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515420)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (255))), ((uintptr_t)((((uint64_t)a4)) & (1))), ((uintptr_t)(75)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5c40  (orig 0xc5c40, call)
extern void callee_515430();
uint64_t sdk_f_c5c40(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515430)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(76)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5c70  (orig 0xc5c70, call)
extern void callee_515440();
uint64_t sdk_f_c5c70(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515440)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)((((uint64_t)a4)) & (65535))), ((uintptr_t)((((uint64_t)a5)) & (255))), ((uintptr_t)(77)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5ca0  (orig 0xc5ca0, call)
extern void callee_515450();
uint64_t sdk_f_c5ca0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515450)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)((((uint64_t)a4)) & (65535))), ((uintptr_t)(78)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5cd0  (orig 0xc5cd0, call)
extern void callee_5152b0();
uint64_t sdk_f_c5cd0(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(79)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5de0  (orig 0xc5de0, call)
extern void callee_5153b0();
uint64_t sdk_f_c5de0(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5153b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(84)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5e00  (orig 0xc5e00, call)
extern void callee_5153b0();
uint64_t sdk_f_c5e00(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5153b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(85)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5e20  (orig 0xc5e20, call)
extern void callee_5153b0();
uint64_t sdk_f_c5e20(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5153b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(86)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5e40  (orig 0xc5e40, call)
extern void callee_5153b0();
uint64_t sdk_f_c5e40(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5153b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(87)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5e60  (orig 0xc5e60, call)
extern void callee_5153b0();
uint64_t sdk_f_c5e60(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5153b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(88)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5e80  (orig 0xc5e80, call)
extern void callee_5153b0();
uint64_t sdk_f_c5e80(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5153b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(89)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5ea0  (orig 0xc5ea0, call)
extern void callee_5154a0();
uint64_t sdk_f_c5ea0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5154a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)((((uint64_t)a5)) & (255))), ((uintptr_t)(90)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5fa0  (orig 0xc5fa0, call)
extern void callee_5154e0();
uint64_t sdk_f_c5fa0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5154e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(94)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c5fd0  (orig 0xc5fd0, call)
extern void callee_5154e0();
uint64_t sdk_f_c5fd0(void* a0, uint32_t a1, uint64_t a2, uint64_t a3, uint64_t a4) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5154e0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (1))), ((uintptr_t)(((uint64_t)a4))), ((uintptr_t)(95)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c6000  (orig 0xc6000, call)
extern void callee_5152b0();
uint64_t sdk_f_c6000(void* a0, uint64_t a1, void* a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5152b0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(*(uint64_t*)((char*)(a2)))), ((uintptr_t)(*(uint64_t*)((char*)(a2) + 8))), ((uintptr_t)(96)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c6030  (orig 0xc6030, call)
extern void callee_5126d0();
uint64_t sdk_f_c6030(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5126d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(97)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c6050  (orig 0xc6050, call)
extern void callee_5154f0();
uint64_t sdk_f_c6050(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5154f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (65535))), ((uintptr_t)((((uint64_t)a2)) & (65535))), ((uintptr_t)(98)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c6080  (orig 0xc6080, call)
extern void callee_512710();
uint64_t sdk_f_c6080(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512710)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(256)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c60a0  (orig 0xc60a0, call)
extern void callee_512780();
uint64_t sdk_f_c60a0(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(257)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_c60d0  (orig 0xc60d0, ptr_add)
void* sdk_f_c60d0(void* a0) { return (char*)a0 + 8; }

// sub_c60e0  (orig 0xc60e0, straight)
void* sdk_f_c60e0(void* a0) { return (char*)(a0) - 8; }

// sub_ca580  (orig 0xca580, ret_only)
void sdk_f_ca580() {}

// sub_cc8f0  (orig 0xcc8f0, ptr_add)
void* sdk_f_cc8f0(void* a0) { return (char*)a0 + 16; }

// sub_cca10  (orig 0xcca10, call)
extern void callee_515590();
uint64_t sdk_f_cca10(void* a0, uint64_t a1, uint32_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515590)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)((((uint64_t)a4)) & (1))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_cca40  (orig 0xcca40, call)
extern void callee_515590();
uint64_t sdk_f_cca40(void* a0, uint64_t a1, uint32_t a2, uint64_t a3, uint64_t a4, uint64_t a5) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515590)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)((((uint64_t)a4)) & (1))), ((uintptr_t)(((uint64_t)a5))), ((uintptr_t)(5)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_ccb10  (orig 0xccb10, call)
extern void callee_5155d0();
uint64_t sdk_f_ccb10(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5155d0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_ccb30  (orig 0xccb30, ptr_add)
void* sdk_f_ccb30(void* a0) { return (char*)a0 + 8; }

// sub_ccb40  (orig 0xccb40, straight)
void* sdk_f_ccb40(void* a0) { return (char*)(a0) - 8; }

// sub_cdef0  (orig 0xcdef0, straight)
uint8_t sdk_f_cdef0(void* a0) { return *(uint8_t*)((char*)(a0) + 10049L); }

// sub_d0110  (orig 0xd0110, ret_only)
void sdk_f_d0110() {}

// sub_d0130  (orig 0xd0130, getter)
uint8_t sdk_f_d0130(void* a0) { return *(uint8_t*)((char*)(a0) + 8); }

// sub_d0160  (orig 0xd0160, getter)
uint16_t sdk_f_d0160(void* a0) { return *(uint16_t*)((char*)(a0) + 32); }

// sub_d0170  (orig 0xd0170, getter)
uint32_t sdk_f_d0170(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_d0270  (orig 0xd0270, getter)
uint16_t sdk_f_d0270(void* a0) { return *(uint16_t*)((char*)(a0) + 40); }

// sub_d0280  (orig 0xd0280, getter)
uint16_t sdk_f_d0280(void* a0) { return *(uint16_t*)((char*)(a0) + 42); }

// sub_d0290  (orig 0xd0290, getter)
uint8_t sdk_f_d0290(void* a0) { return *(uint8_t*)((char*)(a0) + 44); }

// sub_d0850  (orig 0xd0850, getter)
uint16_t sdk_f_d0850(void* a0) { return *(uint16_t*)((char*)(a0) + 40); }

// sub_d0860  (orig 0xd0860, getter)
uint8_t sdk_f_d0860(void* a0) { return *(uint8_t*)((char*)(a0) + 42); }

// sub_d2620  (orig 0xd2620, ptr_add)
void* sdk_f_d2620(void* a0) { return (char*)a0 + 16; }

// sub_d26c0  (orig 0xd26c0, ptr_add)
void* sdk_f_d26c0(void* a0) { return (char*)a0 + 8; }

// sub_d26d0  (orig 0xd26d0, straight)
void* sdk_f_d26d0(void* a0) { return (char*)(a0) - 8; }

// sub_d2860  (orig 0xd2860, ptr_add)
void* sdk_f_d2860(void* a0) { return (char*)a0 + 16; }

// sub_d2890  (orig 0xd2890, call)
extern void callee_5159f0();
uint64_t sdk_f_d2890(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_5159f0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (65535))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d28c0  (orig 0xd28c0, call)
extern void callee_515a00();
uint64_t sdk_f_d28c0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515a00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (65535))), ((uintptr_t)(2)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d28f0  (orig 0xd28f0, call)
extern void callee_515a10();
uint64_t sdk_f_d28f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515a10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2910  (orig 0xd2910, call)
extern void callee_512700();
uint64_t sdk_f_d2910(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(4)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2970  (orig 0xd2970, call)
extern void callee_515a10();
uint64_t sdk_f_d2970(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515a10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(6)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2990  (orig 0xd2990, call)
extern void callee_512700();
uint64_t sdk_f_d2990(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(7)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d29b0  (orig 0xd29b0, call)
extern void callee_515a30();
uint64_t sdk_f_d29b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515a30)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(8)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d29d0  (orig 0xd29d0, call)
extern void callee_512700();
uint64_t sdk_f_d29d0(void* a0) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t))&callee_512700)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(9)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2a30  (orig 0xd2a30, call)
extern void callee_512900();
uint64_t sdk_f_d2a30(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512900)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(17)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2a50  (orig 0xd2a50, call)
extern void callee_515a40();
uint64_t sdk_f_d2a50(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515a40)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (281474976710655))), ((uintptr_t)(18)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2a80  (orig 0xd2a80, call)
extern void callee_512780();
uint64_t sdk_f_d2a80(void* a0, uint32_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_512780)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(19)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2af0  (orig 0xd2af0, call)
extern void callee_512900();
uint64_t sdk_f_d2af0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512900)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(21)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2b10  (orig 0xd2b10, call)
extern void callee_515a60();
uint64_t sdk_f_d2b10(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515a60)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(22)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2b40  (orig 0xd2b40, call)
extern void callee_515a60();
uint64_t sdk_f_d2b40(void* a0, uint32_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515a60)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint32_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(23)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2b70  (orig 0xd2b70, call)
extern void callee_515a70();
uint64_t sdk_f_d2b70(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515a70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (281474976710655))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(24)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2be0  (orig 0xd2be0, call)
extern void callee_512900();
uint64_t sdk_f_d2be0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512900)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(26)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2db0  (orig 0xd2db0, call)
extern void callee_512900();
uint64_t sdk_f_d2db0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_512900)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(33)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2dd0  (orig 0xd2dd0, call)
extern void callee_515ad0();
uint64_t sdk_f_d2dd0(void* a0, uint64_t a1, uint32_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515ad0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint32_t)a2))), ((uintptr_t)((((uint64_t)a3)) & (65535))), ((uintptr_t)(34)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2e00  (orig 0xd2e00, call)
extern void callee_515ae0();
uint64_t sdk_f_d2e00(void* a0, uint64_t a1, uint64_t a2, uint32_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515ae0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint32_t)a3))), ((uintptr_t)(35)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2e30  (orig 0xd2e30, call)
extern void callee_515af0();
uint64_t sdk_f_d2e30(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515af0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(36)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2e50  (orig 0xd2e50, call)
extern void callee_515af0();
uint64_t sdk_f_d2e50(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515af0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(37)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d2e70  (orig 0xd2e70, ptr_add)
void* sdk_f_d2e70(void* a0) { return (char*)a0 + 8; }

// sub_d2e80  (orig 0xd2e80, straight)
void* sdk_f_d2e80(void* a0) { return (char*)(a0) - 8; }

// sub_d47b0  (orig 0xd47b0, ret_only)
void sdk_f_d47b0() {}

// sub_d47c0  (orig 0xd47c0, ret_only)
void sdk_f_d47c0() {}

// sub_d5060  (orig 0xd5060, ptr_add)
void* sdk_f_d5060(void* a0) { return (char*)a0 + 16; }

// sub_d5070  (orig 0xd5070, call)
extern void callee_515b10();
uint64_t sdk_f_d5070(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d5160  (orig 0xd5160, ptr_add)
void* sdk_f_d5160(void* a0) { return (char*)a0 + 8; }

// sub_d5170  (orig 0xd5170, straight)
void* sdk_f_d5170(void* a0) { return (char*)(a0) - 8; }

// sub_d6b60  (orig 0xd6b60, ret_only)
void sdk_f_d6b60() {}

// sub_d6dd0  (orig 0xd6dd0, ptr_add)
void* sdk_f_d6dd0(void* a0) { return (char*)a0 + 16; }

// sub_d6de0  (orig 0xd6de0, call)
extern void callee_515b10();
uint64_t sdk_f_d6de0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b10)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(32)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d6e50  (orig 0xd6e50, call)
extern void callee_515b70();
uint64_t sdk_f_d6e50(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b70)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)((((uint64_t)a2)) & (255))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(103)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d6e80  (orig 0xd6e80, call)
extern void callee_515b80();
uint64_t sdk_f_d6e80(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(104)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d6ea0  (orig 0xd6ea0, call)
extern void callee_515b90();
uint64_t sdk_f_d6ea0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b90)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(105)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d6f60  (orig 0xd6f60, call)
extern void callee_515bb0();
uint64_t sdk_f_d6f60(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515bb0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)((((uint64_t)a1)) & (255))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(130)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d71a0  (orig 0xd71a0, ptr_add)
void* sdk_f_d71a0(void* a0) { return (char*)a0 + 8; }

// sub_d71b0  (orig 0xd71b0, straight)
void* sdk_f_d71b0(void* a0) { return (char*)(a0) - 8; }

// sub_d8160  (orig 0xd8160, ptr_add)
void* sdk_f_d8160(void* a0) { return (char*)a0 + 16; }

// sub_d8170  (orig 0xd8170, call)
extern void callee_515b80();
uint64_t sdk_f_d8170(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515b80)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(((uint64_t)a3))), ((uintptr_t)(2001)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d8190  (orig 0xd8190, call)
extern void callee_5128a0();
uint64_t sdk_f_d8190(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2002)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d81b0  (orig 0xd81b0, call)
extern void callee_515c00();
uint64_t sdk_f_d81b0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_515c00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(2003)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d8200  (orig 0xd8200, call)
extern void callee_5128a0();
uint64_t sdk_f_d8200(void* a0, uint64_t a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5128a0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(2005)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_d8220  (orig 0xd8220, ptr_add)
void* sdk_f_d8220(void* a0) { return (char*)a0 + 8; }

// sub_d8230  (orig 0xd8230, straight)
void* sdk_f_d8230(void* a0) { return (char*)(a0) - 8; }

// sub_d8410  (orig 0xd8410, straight-line)
uint64_t sdk_f_d8410(uint32_t a0) { return (1013904223) + ((((uint32_t)a0)) * (1664525)); }

// libopus_unknown_fixed  (orig 0xdc4a0, strlit-ret)
const char *sdk_f_dc4a0() { static char g_f_dc4a0[1]; __asm__ volatile("" ::: "memory"); return g_f_dc4a0; }

// sub_e8ce0  (orig 0xe8ce0, straight)
void sdk_f_e8ce0(void* a0, uint64_t a1, uint64_t a2) {
    uint32_t k0 = -1;
    *(uint64_t*)((char*)(a0) + 20) = 141733920768;
    *(uint64_t*)((char*)(a0) + 28) = -9223372036854775808;
    *(uint64_t*)((char*)(a0)) = (uint64_t)(a1);
    *(uint64_t*)((char*)(a0) + 12) = 0;
    *(uint64_t*)((char*)(a0) + 36) = 0;
    *(uint32_t*)((char*)(a0) + 8) = (uint32_t)(a2);
    *(uint64_t*)((char*)(a0) + 44) = (uint64_t)k0;
}

// sub_fa070  (orig 0xfa070, straight)
uint32_t sdk_f_fa070(void* a0) {
    *(uint32_t*)((char*)(a0)) = 8600;
    return 0;
}

// sub_fc840  (orig 0xfc840, straight)
uint32_t sdk_f_fc840(void* a0) {
    *(uint32_t*)((char*)(a0)) = 19688;
    return 0;
}

// sub_10dc00  (orig 0x10dc00, straight-line)
uint32_t sdk_f_10dc00(uint32_t a0) { return ((18439) + (((((uint32_t)a0)) << 11))) & (4294965248); }

// sub_10fae0  (orig 0x10fae0, straight-line)
uint32_t sdk_f_10fae0(uint32_t a0) { return ((22535) + ((((uint32_t)a0)) * (10240))) & (4294965248); }

// sub_115980  (orig 0x115980, mov_ret)
uint32_t sdk_f_115980() { return 496; }

// sub_115990  (orig 0x115990, setter)
void sdk_f_115990(void* a0) { *(uint32_t*)((char*)(a0) + 4) = 0; }

// sub_115ac0  (orig 0x115ac0, getter)
uint32_t sdk_f_115ac0(void* a0) { return *(uint32_t*)((char*)(a0) + 4); }

// sub_118a40  (orig 0x118a40, mov_ret)
uint32_t sdk_f_118a40() { return 47104; }

// sub_11ac50  (orig 0x11ac50, straight-line)
uint32_t sdk_f_11ac50(uint32_t a0) { return (59392) + ((((uint32_t)a0)) * (40)); }

// sub_11d490  (orig 0x11d490, ret_only)
void sdk_f_11d490() {}

// sub_11d8f0  (orig 0x11d8f0, getter)
uint32_t sdk_f_11d8f0(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_11d900  (orig 0x11d900, getter)
uint32_t sdk_f_11d900(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_11da50  (orig 0x11da50, straight-line)
uint64_t sdk_f_11da50(void* a0) { return (*(uint64_t*)((char*)(a0) + 32)) * (1000); }

// sub_11da60  (orig 0x11da60, straight)
void sdk_f_11da60(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 40) = (uint8_t)k0;
}

// sub_11da80  (orig 0x11da80, compare)
bool sdk_f_11da80(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 8)) != (uint64_t)(0); }

// sub_11da90  (orig 0x11da90, getter)
uint32_t sdk_f_11da90(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_11daa0  (orig 0x11daa0, getter)
uint32_t sdk_f_11daa0(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_11dab0  (orig 0x11dab0, straight)
void sdk_f_11dab0(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 48) = (uint8_t)k0;
}

// sub_11db00  (orig 0x11db00, ret_only)
void sdk_f_11db00() {}

// sub_11de60  (orig 0x11de60, getter)
uint32_t sdk_f_11de60(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_11de70  (orig 0x11de70, getter)
uint32_t sdk_f_11de70(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_11de80  (orig 0x11de80, getter)
uint32_t sdk_f_11de80(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_11de90  (orig 0x11de90, getter)
uint32_t sdk_f_11de90(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_11dfe0  (orig 0x11dfe0, straight-line)
uint64_t sdk_f_11dfe0(void* a0) { return (*(uint64_t*)((char*)(a0) + 40)) * (1000); }

// sub_11dff0  (orig 0x11dff0, straight)
void sdk_f_11dff0(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 48) = (uint8_t)k0;
}

// sub_11e0d0  (orig 0x11e0d0, compare)
bool sdk_f_11e0d0(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 8)) != (uint64_t)(0); }

// sub_11e0e0  (orig 0x11e0e0, getter)
uint32_t sdk_f_11e0e0(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_11e0f0  (orig 0x11e0f0, getter)
uint32_t sdk_f_11e0f0(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_11e100  (orig 0x11e100, getter)
uint32_t sdk_f_11e100(void* a0) { return *(uint32_t*)((char*)(a0) + 40); }

// sub_11e110  (orig 0x11e110, getter)
uint32_t sdk_f_11e110(void* a0) { return *(uint32_t*)((char*)(a0) + 44); }

// sub_11e120  (orig 0x11e120, straight)
void sdk_f_11e120(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 56) = (uint8_t)k0;
}

// sub_11e140  (orig 0x11e140, mov_ret)
uint32_t sdk_f_11e140() { return 6000; }

// sub_11e170  (orig 0x11e170, strlit-ret)
const char *sdk_f_11e170() { static char g_f_11e170[1]; __asm__ volatile("" ::: "memory"); return g_f_11e170; }

// sub_11e1f0  (orig 0x11e1f0, ret_only)
void sdk_f_11e1f0() {}

// sub_11e240  (orig 0x11e240, compare)
bool sdk_f_11e240(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 8)) != (uint64_t)(0); }

// sub_11e290  (orig 0x11e290, call)
extern void callee_516990();
int64_t sdk_f_11e290(uint64_t unused0, uint32_t a1) {
    int64_t r0 = ((int64_t)(((int32_t)(((uint64_t (*)(uintptr_t))&callee_516990)(((uintptr_t)(((uint32_t)a1))))))));
    asm volatile("");
    return r0;
}

// sub_11e310  (orig 0x11e310, setter-chain-zero)
void sdk_f_11e310(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_11e320  (orig 0x11e320, getter)
uint32_t sdk_f_11e320(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_11e330  (orig 0x11e330, getter)
uint32_t sdk_f_11e330(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_11e4a0  (orig 0x11e4a0, straight)
void sdk_f_11e4a0(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 32) = (uint8_t)k0;
}

// sub_11e4e0  (orig 0x11e4e0, ret_only)
void sdk_f_11e4e0() {}

// sub_11e530  (orig 0x11e530, compare)
bool sdk_f_11e530(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 8)) != (uint64_t)(0); }

// sub_11e620  (orig 0x11e620, call)
extern void callee_516a40();
int64_t sdk_f_11e620(uint64_t unused0, uint32_t a1) {
    int64_t r0 = ((int64_t)(((int32_t)(((uint64_t (*)(uintptr_t))&callee_516a40)(((uintptr_t)(((uint32_t)a1))))))));
    asm volatile("");
    return r0;
}

// sub_11e820  (orig 0x11e820, getter)
uint32_t sdk_f_11e820(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_11e830  (orig 0x11e830, getter)
uint32_t sdk_f_11e830(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_11e960  (orig 0x11e960, getter)
uint32_t sdk_f_11e960(void* a0) { return *(uint32_t*)((char*)(a0) + 40); }

// sub_11e9d0  (orig 0x11e9d0, getter)
uint32_t sdk_f_11e9d0(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_11ea40  (orig 0x11ea40, getter)
uint32_t sdk_f_11ea40(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_11eac0  (orig 0x11eac0, getter)
uint32_t sdk_f_11eac0(void* a0) { return *(uint32_t*)((char*)(a0) + 44); }

// sub_11eba0  (orig 0x11eba0, ret_only)
void sdk_f_11eba0() {}

// sub_11ec00  (orig 0x11ec00, compare)
bool sdk_f_11ec00(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 8)) != (uint64_t)(0); }

// sub_11ed50  (orig 0x11ed50, setter-chain-zero)
void sdk_f_11ed50(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_11ed60  (orig 0x11ed60, getter)
uint32_t sdk_f_11ed60(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_11ed70  (orig 0x11ed70, getter)
uint32_t sdk_f_11ed70(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_11ed80  (orig 0x11ed80, getter)
uint32_t sdk_f_11ed80(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_11ed90  (orig 0x11ed90, getter)
uint32_t sdk_f_11ed90(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_11ef00  (orig 0x11ef00, straight)
void sdk_f_11ef00(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 40) = (uint8_t)k0;
}

// sub_11f1e0  (orig 0x11f1e0, straight-line)
uint32_t sdk_f_11f1e0(void* a0, void* a1) {
    *(uint32_t*)((char*)(a0)) = (((*(uint8_t*)((char*)(a1) + 8) < 96)) ? (3) : ((((((int32_t)(((int8_t)(*(uint8_t*)((char*)(a1) + 8))))) >= 0)) ? (4) : (2))));
    return 0;
}

// sub_11f440  (orig 0x11f440, ret_only)
void sdk_f_11f440() {}

// sub_11f850  (orig 0x11f850, ptr_add)
void* sdk_f_11f850(void* a0) { return (char*)a0 + 16; }

// sub_11f910  (orig 0x11f910, call)
extern void callee_516ec0();
uint64_t sdk_f_11f910(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_516ec0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_11f9f0  (orig 0x11f9f0, call)
extern void callee_516ee0();
uint64_t sdk_f_11f9f0(void* a0, uint64_t a1, uint64_t a2) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_516ee0)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(((uint64_t)a1))), ((uintptr_t)(((uint64_t)a2))), ((uintptr_t)(272)), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_11fa20  (orig 0x11fa20, ptr_add)
void* sdk_f_11fa20(void* a0) { return (char*)a0 + 8; }

// sub_11fa30  (orig 0x11fa30, straight)
void* sdk_f_11fa30(void* a0) { return (char*)(a0) - 8; }

// sub_11fdb0  (orig 0x11fdb0, ptr_add)
void* sdk_f_11fdb0(void* a0) { return (char*)a0 + 16; }

// sub_11fdf0  (orig 0x11fdf0, call)
extern void callee_516f00();
uint64_t sdk_f_11fdf0(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_516f00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(1)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_11fe50  (orig 0x11fe50, call)
extern void callee_516f00();
uint64_t sdk_f_11fe50(void* a0, void* a1) {
    uint64_t r0 = (((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t))&callee_516f00)(((uintptr_t)((char*)(a0) + 8)), ((uintptr_t)(*(uint64_t*)((char*)(a1)))), ((uintptr_t)(*(uint64_t*)((char*)(a1) + 8))), ((uintptr_t)(3)))) & (4294967295);
    asm volatile("");
    return r0;
}

// sub_120040  (orig 0x120040, ptr_add)
void* sdk_f_120040(void* a0) { return (char*)a0 + 8; }

// sub_120050  (orig 0x120050, straight)
void* sdk_f_120050(void* a0) { return (char*)(a0) - 8; }

// sub_121020  (orig 0x121020, mov_ret)
uint32_t sdk_f_121020() { return 48960; }

// sub_121070  (orig 0x121070, mov_ret)
uint32_t sdk_f_121070() { return 37184; }

// sub_1210c0  (orig 0x1210c0, mov_ret)
uint32_t sdk_f_1210c0() { return 1984; }

// sub_121110  (orig 0x121110, mov_ret)
uint32_t sdk_f_121110() { return 65536; }

// sub_121160  (orig 0x121160, mov_ret)
uint32_t sdk_f_121160() { return 56; }

// sub_1211b0  (orig 0x1211b0, mov_ret)
uint32_t sdk_f_1211b0() { return 32784; }

// sub_121200  (orig 0x121200, mov_ret)
uint32_t sdk_f_121200() { return 8208; }

// sub_1251e0  (orig 0x1251e0, getter)
uint32_t sdk_f_1251e0(void* a0) { return *(uint32_t*)((char*)(a0) + 13456L); }

// sub_128880  (orig 0x128880, setter-chain)
void sdk_f_128880(void* a0, uint64_t a1, uint64_t a2, uint64_t a3) { *(uint64_t*)((char*)(a0)) = a1; *(uint64_t*)((char*)(a0) + 144) = a2; *(uint64_t*)((char*)(a0) + 152) = a3; }

// sub_12a8a0  (orig 0x12a8a0, ret_only)
void sdk_f_12a8a0() {}

// sub_138170  (orig 0x138170, ret_only)
void sdk_f_138170() {}

// sub_138180  (orig 0x138180, setter-chain-zero)
void sdk_f_138180(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint32_t*)((char*)a0 + 16) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_138790  (orig 0x138790, getter)
uint32_t sdk_f_138790(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_1387a0  (orig 0x1387a0, straight)
uint32_t sdk_f_1387a0(void* a0) { return (*(uint32_t*)((char*)(a0) + 36)) - (*(uint32_t*)((char*)(a0))); }

// sub_1387b0  (orig 0x1387b0, setter)
void sdk_f_1387b0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 12) = a1; }

// sub_1387c0  (orig 0x1387c0, getter)
uint32_t sdk_f_1387c0(void* a0) { return *(uint32_t*)((char*)(a0) + 12); }

// sub_1392f0  (orig 0x1392f0, copy-chain)
void sdk_f_1392f0(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint8_t*)((char*)(a0) + 16) = 0; *(uint8_t*)((char*)(a0) + 32) = 0; *(uint64_t*)((char*)(a0) + 64) = 0; *(uint16_t*)((char*)(a0) + 72) = *(uint16_t*)((char*)(a0) + 60); }

// sub_13ff40  (orig 0x13ff40, ret_only)
void sdk_f_13ff40() {}

// sub_140f30  (orig 0x140f30, ret_only)
void sdk_f_140f30() {}

// sub_140f70  (orig 0x140f70, ret_only)
void sdk_f_140f70() {}

// sub_141e90  (orig 0x141e90, setter-chain)
void sdk_f_141e90(void* a0, uint64_t a1, uint32_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint32_t*)((char*)(a0) + 24) = 0; *(uint64_t*)((char*)(a0) + 16) = 0; *(uint32_t*)((char*)(a0) + 32) = a2; }

// sub_1441d0  (orig 0x1441d0, setter)
void sdk_f_1441d0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 64) = a1; }

// sub_145bc0  (orig 0x145bc0, setter)
void sdk_f_145bc0(void* a0) { *(uint8_t*)((char*)(a0) + 464) = 0; }

// sub_145c00  (orig 0x145c00, compare)
bool sdk_f_145c00(void* a0) { return (uint8_t)(*(uint8_t*)((char*)(a0) + 461)) != (uint64_t)(0); }

// sub_14c440  (orig 0x14c440, getter)
uint32_t sdk_f_14c440(void* a0) { return *(uint32_t*)((char*)(a0) + 12); }

// sub_14c450  (orig 0x14c450, compare)
bool sdk_f_14c450(void* a0) { return (uint8_t)(*(uint8_t*)((char*)(a0) + 52)) != (uint64_t)(0); }

// sub_14c460  (orig 0x14c460, getter)
uint32_t sdk_f_14c460(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_14c470  (orig 0x14c470, getter)
uint8_t sdk_f_14c470(void* a0) { return *(uint8_t*)((char*)(a0) + 48); }

// sub_14c4c0  (orig 0x14c4c0, mov_ret)
uint32_t sdk_f_14c4c0() { return 1424; }

// sub_14c510  (orig 0x14c510, mov_ret)
uint32_t sdk_f_14c510() { return 8192; }

// sub_14c9e0  (orig 0x14c9e0, straight-line)
uint64_t sdk_f_14c9e0(uint64_t a0, uint32_t a1) { return ((((uint64_t)a0)) + ((((uint64_t)(((uint32_t)(((uint32_t)a1)))))) * (((uint64_t)(((uint32_t)(56))))))) + (56); }

// sub_14c9f0  (orig 0x14c9f0, getter)
uint32_t sdk_f_14c9f0(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_14d650  (orig 0x14d650, straight-line)
uint32_t sdk_f_14d650(void* a0, uint32_t a1) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((uint32_t)a1)) * 4)));
    return *(uint32_t*)((char*)(p0) + 1380);
}

// sub_14d660  (orig 0x14d660, straight)
uint32_t sdk_f_14d660(void* a0, void* a1) {
    *(uint32_t*)((char*)(a0)) = *(uint32_t*)((char*)(a1) + 1404);
    return 0;
}

// sub_14f0d0  (orig 0x14f0d0, getter)
uint32_t sdk_f_14f0d0(void* a0) { return *(uint32_t*)((char*)(a0)); }

// sub_15a670  (orig 0x15a670, mov_ret)
uint32_t sdk_f_15a670() { return 0; }

// sub_16b950  (orig 0x16b950, mov_ret)
uint32_t sdk_f_16b950() { return 3448; }

// sub_16b9a0  (orig 0x16b9a0, mov_ret)
uint32_t sdk_f_16b9a0() { return 960; }

// sub_16b9f0  (orig 0x16b9f0, mov_ret)
uint32_t sdk_f_16b9f0() { return 40536; }

// sub_16ba40  (orig 0x16ba40, mov_ret)
uint32_t sdk_f_16ba40() { return 20880; }

// sub_16ba90  (orig 0x16ba90, mov_ret)
uint32_t sdk_f_16ba90() { return 27792; }

// sub_16bae0  (orig 0x16bae0, mov_ret)
uint32_t sdk_f_16bae0() { return 8584; }

// sub_16bb30  (orig 0x16bb30, mov_ret)
uint32_t sdk_f_16bb30() { return 8208; }

// sub_16bb80  (orig 0x16bb80, mov_ret)
uint32_t sdk_f_16bb80() { return 8208; }

// sub_1711a0  (orig 0x1711a0, delegator)
extern void callee_50fda0();
void sdk_f_1711a0(unsigned long a0) { ((void(*)(unsigned long))callee_50fda0)(a0); asm volatile(""); }

// sub_171350  (orig 0x171350, delegator)
extern void callee_518280();
void sdk_f_171350(unsigned long a0) { ((void(*)(unsigned long))callee_518280)(a0); asm volatile(""); }

// sub_171380  (orig 0x171380, call)
extern void callee_5182a0();
uint64_t sdk_f_171380(uint64_t a0, uint32_t a1, uint32_t a2) {
    uint64_t r0 = ((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5182a0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((int64_t)(((int32_t)(((uint32_t)a1))))))), ((uintptr_t)(((uint32_t)a2))));
    asm volatile("");
    return r0;
}

// sub_1713a0  (orig 0x1713a0, call)
extern void callee_5182b0();
uint64_t sdk_f_1713a0(uint64_t a0, uint32_t a1, uint32_t a2) {
    uint64_t r0 = ((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t))&callee_5182b0)(((uintptr_t)(((uint64_t)a0))), ((uintptr_t)(((int64_t)(((int32_t)(((uint32_t)a1))))))), ((uintptr_t)(((uint32_t)a2))));
    asm volatile("");
    return r0;
}

// sub_171620  (orig 0x171620, ret_only)
void sdk_f_171620() {}

// sub_171a00  (orig 0x171a00, getter)
uint32_t sdk_f_171a00(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_171a10  (orig 0x171a10, getter)
uint32_t sdk_f_171a10(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_171a20  (orig 0x171a20, getter)
uint32_t sdk_f_171a20(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_171b50  (orig 0x171b50, compare)
bool sdk_f_171b50(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 16)) != (uint64_t)(0); }

// sub_171ba0  (orig 0x171ba0, getter)
uint32_t sdk_f_171ba0(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_171bb0  (orig 0x171bb0, getter)
uint32_t sdk_f_171bb0(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_171bc0  (orig 0x171bc0, getter)
uint32_t sdk_f_171bc0(void* a0) { return *(uint32_t*)((char*)(a0) + 40); }

// sub_171dc0  (orig 0x171dc0, ret_only)
void sdk_f_171dc0() {}

// sub_171e40  (orig 0x171e40, ret_only)
void sdk_f_171e40() {}

// sub_171f10  (orig 0x171f10, ret_only)
void sdk_f_171f10() {}

// sub_171fc0  (orig 0x171fc0, ret_only)
void sdk_f_171fc0() {}

// sub_173960  (orig 0x173960, setter-chain-zero)
void sdk_f_173960(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

