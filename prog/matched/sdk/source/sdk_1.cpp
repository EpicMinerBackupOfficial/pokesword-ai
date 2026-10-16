/* sdk -- 5 functions verified to match the original.
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


// sub_3c40d0  (orig 0x3c40d0, call)
extern void callee_529890();
uint32_t sdk_f_3c40d0() {
    uint32_t r0 = (((((uint32_t (*)(void))&callee_529890)() == 0)) ? (0) : (196611));
    asm volatile("");
    return r0;
}

// sub_3c4790  (orig 0x3c4790, mov_ret)
uint32_t sdk_f_3c4790() { return 1; }

// sub_3c47a0  (orig 0x3c47a0, mov_ret)
uint32_t sdk_f_3c47a0() { return 1; }

// sub_3c47c0  (orig 0x3c47c0, mov_ret)
uint32_t sdk_f_3c47c0() { return 1; }

// sub_49f340  (orig 0x49f340, const-ret)
uint32_t sdk_f_49f340() { return 81920u; }

