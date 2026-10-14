/* main -- 399 functions verified to match the original.
 *
 * These bodies were synthesised from the instruction stream by
 * tools/auto_match.py and confirmed by compiling them for
 * aarch64-none-elf and comparing against data/main.elf with
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

// sub_173ef90  (orig 0x173ef90, straight)
void main_f_173ef90(void* a0, uint64_t a1, uint32_t a2) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((uint32_t)a2)) * 1)));
    *(uint8_t*)((char*)(p0) + 1544) = (uint8_t)((((uint64_t)a1)) >> (56));
    *(uint8_t*)((char*)(p0) + 1545) = (uint8_t)((((uint64_t)a1)) >> (48));
    *(uint8_t*)((char*)(p0) + 1546) = (uint8_t)((((uint64_t)a1)) >> (40));
    *(uint8_t*)((char*)(p0) + 1547) = (uint8_t)((((uint64_t)a1)) >> (32));
    *(uint8_t*)((char*)(p0) + 1548) = (uint8_t)((((uint64_t)a1)) >> (24));
    *(uint8_t*)((char*)(p0) + 1549) = (uint8_t)((((uint64_t)a1)) >> (16));
    *(uint8_t*)((char*)(p0) + 1550) = (uint8_t)((((uint64_t)a1)) >> (8));
    *(uint8_t*)((char*)(p0) + 1551) = (uint8_t)(a1);
}

// sub_1741960  (orig 0x1741960, ret_only)
void main_f_1741960() {}

// sub_1742610  (orig 0x1742610, mov_ret)
uint32_t main_f_1742610() { return 132; }

// sub_1742620  (orig 0x1742620, mov_ret)
uint32_t main_f_1742620() { return 20; }

// sub_1743940  (orig 0x1743940, ret_only)
void main_f_1743940() {}

// sub_1743950  (orig 0x1743950, mov_ret)
uint32_t main_f_1743950() { return 124; }

// sub_1746cb0  (orig 0x1746cb0, mov_ret)
uint32_t main_f_1746cb0() { return 0; }

// sub_17474f0  (orig 0x17474f0, mov_ret)
uint32_t main_f_17474f0() { return 0; }

// sub_1747500  (orig 0x1747500, ret_only)
void main_f_1747500() {}

// sub_1747b90  (orig 0x1747b90, getter)
uint64_t main_f_1747b90(void* a0) { return *(uint64_t*)((char*)(a0) + 816); }

// sub_1747bb0  (orig 0x1747bb0, mov_ret)
uint32_t main_f_1747bb0() { return 608; }

// sub_1748970  (orig 0x1748970, ret_only)
void main_f_1748970() {}

// sub_1748980  (orig 0x1748980, mov_ret)
uint32_t main_f_1748980() { return 88; }

// sub_1748aa0  (orig 0x1748aa0, mov_ret)
uint32_t main_f_1748aa0() { return 16; }

// sub_1748ab0  (orig 0x1748ab0, straight)
void main_f_1748ab0(void* a0) {
    uint8_t k0 = 0;
    *(uint8_t*)((char*)(a0)) = 0;
    *(uint64_t*)((char*)(a0) + 4) = -1;
    *(uint32_t*)((char*)(a0) + 12) = -1;
    *(uint64_t*)((char*)(a0) + 16) = 0;
    *(uint8_t*)((char*)(a0) + 24) = 0;
    *(uint64_t*)((char*)(a0) + 72) = 0;
    *(uint64_t*)((char*)(a0) + 28) = 0;
    *(uint32_t*)((char*)(a0) + 80) = (uint32_t)k0;
}

// sub_1748ae0  (orig 0x1748ae0, ret_only)
void main_f_1748ae0() {}

// sub_1748d10  (orig 0x1748d10, straight)
void main_f_1748d10(void* a0) {
    *(uint64_t*)((char*)(a0) + 8) = -1;
}

// sub_1748e60  (orig 0x1748e60, straight)
void main_f_1748e60(void* a0, void* a1) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 24) = (uint8_t)k0;
    *(uint64_t*)((char*)(a0) + 16) = *(uint64_t*)((char*)(a1));
}

// sub_1749050  (orig 0x1749050, ret_only)
void main_f_1749050() {}

// sub_17490e0  (orig 0x17490e0, ret_only)
void main_f_17490e0() {}

// sub_1749260  (orig 0x1749260, ret_only)
void main_f_1749260() {}

// sub_17493f0  (orig 0x17493f0, setter-chain)
void main_f_17493f0(void* a0) { *(uint8_t*)((char*)(a0) + 8) = 0; *(uint64_t*)((char*)(a0) + 80) = 0; }

// sub_1749400  (orig 0x1749400, setter-chain)
void main_f_1749400(void* a0, uint64_t a1, uint8_t a2) { *(uint64_t*)((char*)(a0) + 64) = a1; *(uint8_t*)((char*)(a0) + 56) = a2; }

// sub_1749810  (orig 0x1749810, ret_only)
void main_f_1749810() {}

// sub_1749cd0  (orig 0x1749cd0, ptr_add)
void* main_f_1749cd0(void* a0) { return (char*)a0 + 8; }

// sub_1749ce0  (orig 0x1749ce0, ptr_add)
void* main_f_1749ce0(void* a0) { return (char*)a0 + 40; }

// sub_1749d50  (orig 0x1749d50, straight)
uint8_t main_f_1749d50(void* a0) { return ((*(uint8_t*)((char*)(a0) + 120)) >> (2)) & (3); }

// sub_1749d60  (orig 0x1749d60, straight)
uint8_t main_f_1749d60(void* a0) { return (*(uint8_t*)((char*)(a0) + 120)) & (3); }

// sub_1749d70  (orig 0x1749d70, straight)
uint8_t main_f_1749d70(void* a0) { return (*(uint8_t*)((char*)(a0) + 120)) >> (4); }

// sub_1749d80  (orig 0x1749d80, getter)
uint64_t main_f_1749d80(void* a0) { return *(uint64_t*)((char*)(a0) + 104); }

// sub_1749d90  (orig 0x1749d90, getter)
uint32_t main_f_1749d90(void* a0) { return *(uint32_t*)((char*)(a0) + 112); }

// sub_1749da0  (orig 0x1749da0, getter)
uint32_t main_f_1749da0(void* a0) { return *(uint32_t*)((char*)(a0) + 116); }

// sub_1749db0  (orig 0x1749db0, getter)
uint8_t main_f_1749db0(void* a0) { return *(uint8_t*)((char*)(a0) + 121); }

// sub_1749dc0  (orig 0x1749dc0, compare-pred)
bool main_f_1749dc0(void* a0) { return (uint32_t)((*(uint8_t*)((char*)a0 + 120) & 12)) == (uint32_t)(8); }

// sub_1749de0  (orig 0x1749de0, compare-pred)
bool main_f_1749de0(void* a0) { return (uint32_t)((*(uint8_t*)((char*)a0 + 120) & 12)) == (uint32_t)(4); }

// sub_1749e00  (orig 0x1749e00, straight)
uint8_t main_f_1749e00(void* a0) { return (*(uint8_t*)((char*)(a0) + 121)) & (1); }

// sub_1749e10  (orig 0x1749e10, straight)
uint8_t main_f_1749e10(void* a0) { return ((*(uint8_t*)((char*)(a0) + 121)) >> (1)) & (1); }

// sub_1749e20  (orig 0x1749e20, compare-pred)
bool main_f_1749e20(void* a0) { return (uint32_t)((*(uint8_t*)((char*)a0 + 121) & 3)) == (uint32_t)(2); }

// sub_1749e40  (orig 0x1749e40, ptr_add)
void* main_f_1749e40(void* a0) { return (char*)a0 + 72; }

// sub_1749e50  (orig 0x1749e50, ptr_add)
void* main_f_1749e50(void* a0) { return (char*)a0 + 72; }

// sub_1749e80  (orig 0x1749e80, compare)
bool main_f_1749e80(void* a0, void* a1) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 104)) == (uint64_t)(*(uint64_t*)((char*)(a1) + 104)); }

// sub_1749ea0  (orig 0x1749ea0, compare)
bool main_f_1749ea0(void* a0, void* a1) { return (uint32_t)(*(uint32_t*)((char*)(a0) + 116)) == (uint32_t)(*(uint32_t*)((char*)(a1) + 116)); }

// sub_1749ec0  (orig 0x1749ec0, compare)
bool main_f_1749ec0(void* a0, void* a1) { return (uint32_t)(*(uint32_t*)((char*)(a0) + 112)) == (uint32_t)(*(uint32_t*)((char*)(a1) + 112)); }

// sub_1749ee0  (orig 0x1749ee0, compare)
bool main_f_1749ee0(void* a0) { return (uint8_t)(*(uint8_t*)((char*)(a0) + 122)) == (uint64_t)(1); }

// sub_1749ef0  (orig 0x1749ef0, compare)
bool main_f_1749ef0(void* a0) { return (uint8_t)(*(uint8_t*)((char*)(a0) + 123)) == (uint64_t)(1); }

// sub_1749f30  (orig 0x1749f30, setter)
void main_f_1749f30(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 104) = a1; }

// sub_1749f40  (orig 0x1749f40, setter)
void main_f_1749f40(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 112) = a1; }

// sub_1749f50  (orig 0x1749f50, setter)
void main_f_1749f50(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 116) = a1; }

// sub_1749fa0  (orig 0x1749fa0, setter)
void main_f_1749fa0(void* a0, uint8_t a1) { *(uint8_t*)((char*)(a0) + 121) = a1; }

// sub_1749fb0  (orig 0x1749fb0, straight)
void main_f_1749fb0(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0) + 122) = (uint8_t)((((uint32_t)a1)) & (1));
}

// sub_1749fc0  (orig 0x1749fc0, straight)
void main_f_1749fc0(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0) + 123) = (uint8_t)((((uint32_t)a1)) & (1));
}

// sub_174a450  (orig 0x174a450, ret_only)
void main_f_174a450() {}

// sub_174a590  (orig 0x174a590, ret_only)
void main_f_174a590() {}

// sub_174ac10  (orig 0x174ac10, ret_only)
void main_f_174ac10() {}

// sub_174b0e0  (orig 0x174b0e0, getter)
uint32_t main_f_174b0e0(void* a0) { return *(uint32_t*)((char*)(a0) + 40); }

// sub_174b170  (orig 0x174b170, ret_only)
void main_f_174b170() {}

// sub_174b590  (orig 0x174b590, ret_only)
void main_f_174b590() {}

// sub_174b9a0  (orig 0x174b9a0, ret_only)
void main_f_174b9a0() {}

// Pia_SendThreadStream  (orig 0x174be00, setter)
void main_f_174be00(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 80) = a1; }

// Pia_ReceiveThreadStream  (orig 0x174be10, setter)
void main_f_174be10(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 72) = a1; }

// sub_174dbc0  (orig 0x174dbc0, getter-chain)
uint32_t main_f_174dbc0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 96))) + 4076); }

// LeaveMeshJob_LeaveSuccess_2  (orig 0x174de50, getter)
uint64_t main_f_174de50(void* a0) { return *(uint64_t*)((char*)(a0) + 144); }

// sub_174de60  (orig 0x174de60, getter)
uint64_t main_f_174de60(void* a0) { return *(uint64_t*)((char*)(a0) + 152); }

// sub_174e330  (orig 0x174e330, getter)
uint64_t main_f_174e330(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_174e340  (orig 0x174e340, getter)
uint64_t main_f_174e340(void* a0) { return *(uint64_t*)((char*)(a0) + 160); }

// sub_174e350  (orig 0x174e350, getter)
uint64_t main_f_174e350(void* a0) { return *(uint64_t*)((char*)(a0) + 168); }

// sub_174e490  (orig 0x174e490, ret_only)
void main_f_174e490() {}

// sub_174e620  (orig 0x174e620, mov_ret)
uint32_t main_f_174e620() { return 164; }

// sub_174ea90  (orig 0x174ea90, ret_only)
void main_f_174ea90() {}

// sub_174ed30  (orig 0x174ed30, ret_only)
void main_f_174ed30() {}

// sub_1755000  (orig 0x1755000, setter)
void main_f_1755000(uint64_t unused0, void* a1) { *(uint64_t*)((char*)(a1) + 2936) = 0; }

// sub_1755010  (orig 0x1755010, mov_ret)
uint32_t main_f_1755010() { return 0; }

// sub_1755020  (orig 0x1755020, ret_only)
void main_f_1755020() {}

// sub_1755030  (orig 0x1755030, mov_ret)
uint32_t main_f_1755030() { return 0; }

// sub_1755040  (orig 0x1755040, ret_only)
void main_f_1755040() {}

// sub_1755410  (orig 0x1755410, mov_ret)
uint32_t main_f_1755410() { return 0; }

// sub_1755660  (orig 0x1755660, mov_ret)
uint32_t main_f_1755660() { return 4; }

// sub_1755670  (orig 0x1755670, mov_ret)
uint32_t main_f_1755670() { return 4; }

// sub_1755680  (orig 0x1755680, mov_ret)
uint32_t main_f_1755680() { return 4; }

// sub_1755690  (orig 0x1755690, mov_ret)
uint32_t main_f_1755690() { return 4; }

// sub_17568b0  (orig 0x17568b0, setter-chain)
void main_f_17568b0(uint64_t a0, void* a1) { *(uint64_t*)((char*)(a1)) = a0; *(uint32_t*)((char*)(a1) + 8) = 0; *(uint64_t*)((char*)(a1) + 16) = 0; }

// Hostname_s_was_found_in_DNS_cache  (orig 0x1757530, compare)
bool main_f_1757530(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 2152)) != (uint64_t)(2); }

// Trying_s  (orig 0x17575d0, mov_ret)
uint32_t main_f_17575d0() { return 0; }

// Trying_s  (orig 0x17575e0, mov_ret)
uint32_t main_f_17575e0() { return 0; }

// No_URL_set  (orig 0x17577e0, setter-chain)
void main_f_17577e0(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 16) = a1; *(uint64_t*)((char*)(a0) + 24) = 0; *(uint64_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; }

// sub_17579a0  (orig 0x17579a0, getter)
uint64_t main_f_17579a0(void* a0) { return *(uint64_t*)((char*)(a0) + 24); }

// sub_1759430  (orig 0x1759430, ret_only)
void main_f_1759430() {}

// Closing_connection_ld  (orig 0x175a410, setter)
void main_f_175a410(void* a0) { *(uint64_t*)((char*)(a0) + 16) = 0; }

// Site_s_d_is_pipeline_blacklisted  (orig 0x175cc20, ptr_add)
void* main_f_175cc20(void* a0) { return (char*)a0 + 384; }

// Server_s_is_blacklisted  (orig 0x175cc30, ptr_add)
void* main_f_175cc30(void* a0) { return (char*)a0 + 416; }

// sub_175cc50  (orig 0x175cc50, compare)
bool main_f_175cc50(void* a0, uint64_t unused1, void* a2) { return (uint32_t)(*(uint32_t*)((char*)(a0))) == (uint32_t)(*(uint32_t*)((char*)(a2))); }

// sub_175f720  (orig 0x175f720, straight)
uint32_t main_f_175f720(void* a0, void* a1) {
    *(uint32_t*)((char*)(a1)) = *(uint32_t*)((char*)(a0) + 600);
    return 65536;
}

// sub_1763920  (orig 0x1763920, straight-line)
void main_f_1763920(void* a0) {
    *(uint64_t*)((char*)(a0) + 52) = 0;
    *(uint64_t*)((char*)(a0) + 72) = 0;
}

// sub_17651c0  (orig 0x17651c0, setter)
void main_f_17651c0(void* a0) { *(uint8_t*)((char*)(a0) + 2249) = 0; }

// sub_1765680  (orig 0x1765680, setter)
void main_f_1765680(void* a0) { *(uint8_t*)((char*)(a0) + 2248) = 0; }

// chunked  (orig 0x1766dd0, mov_ret)
uint32_t main_f_1766dd0() { return 0; }

// http_proxy  (orig 0x1767d40, setter-chain-zero)
void main_f_1767d40(void* a0) {
    *(uint64_t*)((char*)a0 + 2936) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a0 + 2928) = 0;
}

// sub_1769a50  (orig 0x1769a50, straight)
void main_f_1769a50(void* a0) {
    *(uint64_t*)((char*)(a0) + 20432L) = *(uint64_t*)((char*)(a0) + 792);
    *(uint64_t*)((char*)(a0) + 20440L) = *(uint64_t*)((char*)(a0) + 648);
}

// Pipe_broke_handle_p_url_s  (orig 0x1769c30, mov_ret)
uint32_t main_f_1769c30() { return 0; }

// sub_1773510  (orig 0x1773510, ret_only)
void main_f_1773510() {}

// Digest  (orig 0x17757e0, mov_ret)
uint32_t main_f_17757e0() { return 1; }

// sub_17771a0  (orig 0x17771a0, mov_ret)
uint32_t main_f_17771a0() { return 30; }

// sub_1777410  (orig 0x1777410, mov_ret)
uint32_t main_f_1777410() { return 0; }

// sub_1777430  (orig 0x1777430, mov_ret)
uint32_t main_f_1777430() { return 4; }

// sub_1777440  (orig 0x1777440, mov_ret)
uint32_t main_f_1777440() { return 4; }

// sub_1777450  (orig 0x1777450, mov_ret)
uint64_t main_f_1777450() { return 0; }

// http_proxy  (orig 0x1778130, ret_only)
void main_f_1778130() {}

// sub_1778140  (orig 0x1778140, ret_only)
void main_f_1778140() {}

// sub_1778150  (orig 0x1778150, straight)
uint32_t main_f_1778150(uint32_t a0) { return (((uint32_t)a0)) & (2147483647); }

// d41d8cd98f00b204e9800998ecf8427e  (orig 0x1778160, ret_only)
void main_f_1778160() {}

// sub_1778170  (orig 0x1778170, straight)
uint32_t main_f_1778170(uint32_t a0) { return (((uint32_t)a0)) & (2147483647); }

// RELOAD  (orig 0x1778180, ret_only)
void main_f_1778180() {}

// RELOAD  (orig 0x1778190, ret_only)
void main_f_1778190() {}

// sub_17781a0  (orig 0x17781a0, ret_only)
void main_f_17781a0() {}

// sub_1778f30  (orig 0x1778f30, ret_only)
void main_f_1778f30() {}

// sub_1779240  (orig 0x1779240, ret_only)
void main_f_1779240() {}

// sub_17796b0  (orig 0x17796b0, straight-line)
void main_f_17796b0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 48));
    *(uint32_t*)((char*)(p0) + 156) = 0;
}

// sub_17796c0  (orig 0x17796c0, ret_only)
void main_f_17796c0() {}

// sub_17796d0  (orig 0x17796d0, setter-chain-zero)
void main_f_17796d0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 8) = 0;
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
}

// sub_1779710  (orig 0x1779710, ret_only)
void main_f_1779710() {}

// sub_17797c0  (orig 0x17797c0, straight-line)
uint64_t main_f_17797c0(void* a0) { return (*(int32_t*)((char*)(a0) + 16)) * (57); }

// sub_1779890  (orig 0x1779890, setter)
void main_f_1779890(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 176) = a1; }

// sub_177a5b0  (orig 0x177a5b0, setter)
void main_f_177a5b0(void* a0, float a1) { *(float*)((char*)(a0) + 188) = a1; }

// sub_177bed0  (orig 0x177bed0, compare-pred)
bool main_f_177bed0(void* a0) { return (uint32_t)(*(uint8_t*)(char*)(*(uint64_t*)((char*)a0 + 32))) == (uint32_t)(2); }

// Signature_check_failed_c_c_c_c_must_be_c_c_c_c  (orig 0x177c0b0, setter-chain)
void main_f_177c0b0(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5, uint64_t a6) { *(uint64_t*)((char*)(a0) + 16) = a1; *(uint64_t*)((char*)(a0) + 32) = a2; *(uint64_t*)((char*)(a0) + 96) = a3; *(uint64_t*)((char*)(a0) + 104) = a4; *(uint64_t*)((char*)(a0) + 112) = a5; *(uint64_t*)((char*)(a0) + 120) = a6; }

// sub_177c110  (orig 0x177c110, getter-chain)
uint64_t main_f_177c110(void* a0) { return *(uint64_t*)((char*)((*(uint64_t*)((char*)(a0) + 40))) + 136); }

// sub_177c140  (orig 0x177c140, getter-chain)
uint8_t main_f_177c140(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0) + 32))) + 2); }

// sub_177c150  (orig 0x177c150, getter-chain)
uint8_t main_f_177c150(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0) + 32))) + 1); }

// sub_177c160  (orig 0x177c160, getter-chain)
uint8_t main_f_177c160(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0) + 32))) + 3); }

// sub_177c170  (orig 0x177c170, straight)
uint8_t main_f_177c170(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 32));
    return (*(uint8_t*)((char*)(p0) + 1)) - (*(uint8_t*)((char*)(p0) + 3));
}

// sub_177c200  (orig 0x177c200, mov_ret)
uint32_t main_f_177c200() { return 1; }

// sub_177c210  (orig 0x177c210, straight-line)
uint16_t main_f_177c210(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 32));
    void* p1 = (void*)((uintptr_t)((*(uint64_t*)((char*)(a0) + 24)) + (*(uint32_t*)((char*)(p0) + 12))));
    return (*(uint16_t*)((char*)(p1) + 10)) & (16383);
}

// sub_177c230  (orig 0x177c230, getter-chain)
int32_t main_f_177c230(void* a0) {
    uint64_t t0 = *(uint64_t*)((char*)a0 + 32);
    return *(int16_t*)((char*)(t0) + 4);
}

// sub_177c260  (orig 0x177c260, straight)
void main_f_177c260(void* a0, void* a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 32));
    *(uint8_t*)((char*)(p0) + 10) = *(uint8_t*)((char*)(a1) + 2);
    *(uint16_t*)((char*)(p0) + 8) = *(uint16_t*)((char*)(a1));
}

// sub_177c7f0  (orig 0x177c7f0, getter-chain)
uint8_t main_f_177c7f0(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0) + 32))) + 11); }

// sub_177c870  (orig 0x177c870, straight)
uint8_t main_f_177c870(void* a0) { return ((*(uint8_t*)((char*)(a0) + 88)) >> (2)) & (1); }

// sub_177c880  (orig 0x177c880, straight)
uint8_t main_f_177c880(void* a0) { return ((*(uint8_t*)((char*)(a0) + 88)) >> (1)) & (1); }

// sub_177c890  (orig 0x177c890, getter)
uint32_t main_f_177c890(void* a0) { return *(uint32_t*)((char*)(a0) + 88); }

// sub_177c8a0  (orig 0x177c8a0, getter)
uint8_t main_f_177c8a0(void* a0) { return *(uint8_t*)((char*)(a0) + 63); }

// sub_177c8b0  (orig 0x177c8b0, straight)
void main_f_177c8b0(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0) + 63) = (uint8_t)((((uint32_t)a1)) & (1));
}

// sub_177c8c0  (orig 0x177c8c0, compare-pred)
bool main_f_177c8c0(void* a0) { return (uint32_t)(*(uint8_t*)(char*)(*(uint64_t*)((char*)a0 + 32))) == (uint32_t)(2); }

// sub_177c8e0  (orig 0x177c8e0, straight-line)
uint8_t main_f_177c8e0(void* a0) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 32));
    void* p1 = (void*)((uintptr_t)((*(uint64_t*)((char*)(a0) + 24)) + (*(uint32_t*)((char*)(p0) + 12))));
    return *(uint8_t*)((char*)(p1) + 2);
}

// sub_177ccb0  (orig 0x177ccb0, ret_only)
void main_f_177ccb0() {}

// sub_177cd10  (orig 0x177cd10, getter-chain)
uint64_t main_f_177cd10(void* a0) { return *(uint64_t*)((char*)((*(uint64_t*)((char*)(a0) + 40))) + 136); }

// Signature_check_failed_c_c_c_c_must_be_c_c_c_c  (orig 0x177cd90, straight)
void main_f_177cd90(void* a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5, uint32_t a6) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 23) = (uint8_t)((((uint32_t)a6)) & (1));
    *(uint64_t*)((char*)(a0) + 8) = a1;
    *(uint16_t*)((char*)(a0) + 20) = (uint16_t)(a2);
    *(uint16_t*)((char*)(a0) + 18) = (uint16_t)(a3);
    *(uint16_t*)((char*)(a0) + 16) = (uint16_t)(a4);
    *(uint8_t*)((char*)(a0) + 22) = (uint8_t)(a5);
    *(uint8_t*)((char*)(a0) + 24) = (uint8_t)k0;
}

// sub_177cf10  (orig 0x177cf10, mov_ret)
uint32_t main_f_177cf10() { return 0; }

// sub_177d270  (orig 0x177d270, getter)
uint32_t main_f_177d270(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_177d280  (orig 0x177d280, getter)
uint32_t main_f_177d280(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_177d290  (orig 0x177d290, getter)
uint32_t main_f_177d290(void* a0) { return *(uint32_t*)((char*)(a0) + 32); }

// sub_177d2a0  (orig 0x177d2a0, straight-line)
uint32_t main_f_177d2a0(void* a0) { return (*(uint32_t*)((char*)(a0) + 28)) - (*(uint32_t*)((char*)(a0) + 32)); }

// sub_177d2b0  (orig 0x177d2b0, getter)
uint32_t main_f_177d2b0(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_177d2c0  (orig 0x177d2c0, mov_ret)
uint32_t main_f_177d2c0() { return 2; }

// sub_177d2d0  (orig 0x177d2d0, mov_ret)
uint32_t main_f_177d2d0() { return 8; }

// sub_177d2e0  (orig 0x177d2e0, getter)
uint32_t main_f_177d2e0(void* a0) { return *(uint32_t*)((char*)(a0) + 40); }

// sub_177d300  (orig 0x177d300, setter)
void main_f_177d300(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 40) = a1; }

// sub_177d310  (orig 0x177d310, copy-chain)
void main_f_177d310(void* a0, void* a1) { *(uint8_t*)((char*)(a0) + 46) = *(uint8_t*)((char*)(a1) + 2); *(uint16_t*)((char*)(a0) + 44) = *(uint16_t*)((char*)(a1)); }

// sub_177d7b0  (orig 0x177d7b0, mov_ret)
uint32_t main_f_177d7b0() { return 1; }

// sub_177d7c0  (orig 0x177d7c0, getter)
uint32_t main_f_177d7c0(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_177d7d0  (orig 0x177d7d0, getter)
uint32_t main_f_177d7d0(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_177d7e0  (orig 0x177d7e0, getter)
uint32_t main_f_177d7e0(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_177d7f0  (orig 0x177d7f0, ret_only)
void main_f_177d7f0() {}

// sub_177d800  (orig 0x177d800, mov_ret)
uint32_t main_f_177d800() { return 1; }

// sub_177d810  (orig 0x177d810, mov_ret)
uint32_t main_f_177d810() { return 1; }

// sub_177d820  (orig 0x177d820, mov_ret)
uint32_t main_f_177d820() { return 0; }

// sub_177d830  (orig 0x177d830, mov_ret)
uint32_t main_f_177d830() { return 1; }

// sub_177d860  (orig 0x177d860, ret_only)
void main_f_177d860() {}

// sub_177d920  (orig 0x177d920, mov_ret)
uint32_t main_f_177d920() { return 1; }

// sub_177d9b0  (orig 0x177d9b0, ret_only)
void main_f_177d9b0() {}

// sub_177dc70  (orig 0x177dc70, ret_only)
void main_f_177dc70() {}

// sub_177dc80  (orig 0x177dc80, ret_only)
void main_f_177dc80() {}

// sub_177dc90  (orig 0x177dc90, ret_only)
void main_f_177dc90() {}

// sub_177dca0  (orig 0x177dca0, ret_only)
void main_f_177dca0() {}

// sub_177dcb0  (orig 0x177dcb0, ret_only)
void main_f_177dcb0() {}

// sub_177dcc0  (orig 0x177dcc0, ret_only)
void main_f_177dcc0() {}

// sub_177dcd0  (orig 0x177dcd0, ret_only)
void main_f_177dcd0() {}

// sub_177dce0  (orig 0x177dce0, ret_only)
void main_f_177dce0() {}

// sub_177dd60  (orig 0x177dd60, ret_only)
void main_f_177dd60() {}

// sub_177e020  (orig 0x177e020, ret_only)
void main_f_177e020() {}

// sub_177e030  (orig 0x177e030, ret_only)
void main_f_177e030() {}

// sub_177e040  (orig 0x177e040, ret_only)
void main_f_177e040() {}

// sub_177e050  (orig 0x177e050, ret_only)
void main_f_177e050() {}

// sub_177e060  (orig 0x177e060, ret_only)
void main_f_177e060() {}

// sub_177e070  (orig 0x177e070, ret_only)
void main_f_177e070() {}

// sub_177e080  (orig 0x177e080, ret_only)
void main_f_177e080() {}

// sub_177e090  (orig 0x177e090, ret_only)
void main_f_177e090() {}

// sub_177e0a0  (orig 0x177e0a0, straight)
void* main_f_177e0a0(uint64_t unused0, void* a1, void* a2) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a1)) = (uint8_t)k0;
    return (char*)(a2) + 2;
}

// sub_17816d0  (orig 0x17816d0, mov_ret)
uint64_t main_f_17816d0() { return 0; }

// sub_17816e0  (orig 0x17816e0, mov_ret)
uint64_t main_f_17816e0() { return 0; }

// ScFontB  (orig 0x1781780, setter-chain-zero)
void main_f_1781780(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint32_t*)((char*)a0 + 24) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
}

// sub_1787320  (orig 0x1787320, setter)
void main_f_1787320(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_1787330  (orig 0x1787330, straight)
void main_f_1787330(void* a0) {
    uint32_t k0 = 7;
    *(uint8_t*)((char*)(a0)) = 0;
    *(uint16_t*)((char*)(a0) + 2) = (uint16_t)k0;
}

// sub_1787340  (orig 0x1787340, setter-chain)
void main_f_1787340(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint32_t*)((char*)(a0) + 4) = 0; }

// sub_1787350  (orig 0x1787350, setter-chain)
void main_f_1787350(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint32_t*)((char*)(a0) + 4) = 0; }

// sub_17873f0  (orig 0x17873f0, straight)
void main_f_17873f0(void* a0) {
    uint64_t k0 = 131586;
    uint32_t k1 = 1148846080;
    *(uint32_t*)((char*)(a0)) = (uint32_t)k0;
    *(uint64_t*)((char*)(a0) + 4) = 14157628378595328256;
    *(uint64_t*)((char*)(a0) + 12) = (uint64_t)k1;
}

// sub_1787490  (orig 0x1787490, straight)
void main_f_1787490(void* a0) {
    uint64_t k0 = 16777217;
    uint32_t k1 = 15;
    *(uint32_t*)((char*)(a0) + 1) = (uint32_t)k0;
    *(uint8_t*)((char*)(a0)) = (*(uint8_t*)((char*)(a0))) & (254);
    *(uint16_t*)((char*)(a0) + 5) = 0;
    *(uint8_t*)((char*)(a0) + 7) = (uint8_t)k1;
}

// sub_17874f0  (orig 0x17874f0, straight)
void main_f_17874f0(void* a0) {
    *(uint32_t*)((char*)(a0)) = 117440512;
    *(uint8_t*)((char*)(a0) + 4) = 0;
}

// sub_1787560  (orig 0x1787560, setter)
void main_f_1787560(void* a0) { *(uint64_t*)((char*)(a0)) = 0; }

// sub_1787570  (orig 0x1787570, setter-chain)
void main_f_1787570(void* a0) { *(uint32_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint64_t*)((char*)(a0) + 16) = 0; }

// sub_17875c0  (orig 0x17875c0, straight)
void main_f_17875c0(void* a0) {
    uint32_t k0 = 2;
    *(uint8_t*)((char*)(a0)) = (uint8_t)k0;
    *(uint64_t*)((char*)(a0) + 4) = 5497558141697;
    *(uint32_t*)((char*)(a0) + 12) = 720;
    *(uint64_t*)((char*)(a0) + 24) = 0;
}

// sub_17875f0  (orig 0x17875f0, ret_only)
void main_f_17875f0() {}

// sub_1787600  (orig 0x1787600, ret_only)
void main_f_1787600() {}

// sub_1787640  (orig 0x1787640, straight)
void main_f_1787640(void* a0) {
    uint32_t k0 = 1;
    *(uint16_t*)((char*)(a0)) = (uint16_t)k0;
    *(uint64_t*)((char*)(a0) + 4) = 361417177221300224;
    *(uint32_t*)((char*)(a0) + 16) = 65536;
    *(uint64_t*)((char*)(a0) + 32) = 4294967296;
    *(uint64_t*)((char*)(a0) + 48) = 0;
}

// sub_1787670  (orig 0x1787670, straight)
void main_f_1787670(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0)) = (uint8_t)k0;
    *(uint64_t*)((char*)(a0) + 4) = 0;
    *(uint16_t*)((char*)(a0) + 2) = 0;
    *(uint32_t*)((char*)(a0) + 12) = 1;
    *(uint64_t*)((char*)(a0) + 24) = 0;
}

// sub_1787690  (orig 0x1787690, straight)
void main_f_1787690(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0)) = (uint8_t)k0;
    *(uint16_t*)((char*)(a0) + 2) = 0;
    *(uint64_t*)((char*)(a0) + 8) = 4294967296;
    *(uint64_t*)((char*)(a0) + 24) = 0;
}

// sub_17876b0  (orig 0x17876b0, setter-chain)
void main_f_17876b0(void* a0) { *(uint16_t*)((char*)(a0)) = 0; *(uint32_t*)((char*)(a0) + 4) = 0; }

// sub_1787a90  (orig 0x1787a90, setter-chain-zero)
void main_f_1787a90(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 56) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 40) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_1787ab0  (orig 0x1787ab0, ret_only)
void main_f_1787ab0() {}

// sub_1787ca0  (orig 0x1787ca0, getter)
uint64_t main_f_1787ca0(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_1787d40  (orig 0x1787d40, setter-chain-zero)
void main_f_1787d40(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 216) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 200) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
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

// sub_1787d80  (orig 0x1787d80, ret_only)
void main_f_1787d80() {}

// sub_1787f40  (orig 0x1787f40, setter)
void main_f_1787f40(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 208) = a1; }

// sub_1787f50  (orig 0x1787f50, setter)
void main_f_1787f50(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 216) = a1; }

// sub_1787f60  (orig 0x1787f60, ret_only)
void main_f_1787f60() {}

// sub_1789910  (orig 0x1789910, setter-chain-zero)
void main_f_1789910(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1789930  (orig 0x1789930, ret_only)
void main_f_1789930() {}

// sub_1789ac0  (orig 0x1789ac0, straight)
void main_f_1789ac0(void* a0) {
    uint32_t k0 = 2;
    *(uint8_t*)((char*)(a0)) = (uint8_t)k0;
}

// sub_1789ad0  (orig 0x1789ad0, straight)
void main_f_1789ad0(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0)) = (uint8_t)k0;
}

// sub_1789bc0  (orig 0x1789bc0, mov_ret)
uint32_t main_f_1789bc0() { return 4096; }

// sub_1789bd0  (orig 0x1789bd0, mov_ret)
uint32_t main_f_1789bd0() { return 4096; }

// sub_1789c00  (orig 0x1789c00, ret_only)
void main_f_1789c00() {}

// sub_1789d00  (orig 0x1789d00, ret_only)
void main_f_1789d00() {}

// nvnDeviceGetProcAddress_2  (orig 0x178d530, ret_only)
void main_f_178d530() {}

// sub_178d730  (orig 0x178d730, ret_only)
void main_f_178d730() {}

// sub_178df90  (orig 0x178df90, ret_only)
void main_f_178df90() {}

// sub_178e4c0  (orig 0x178e4c0, setter-chain-zero)
void main_f_178e4c0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 104) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
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

// sub_178e4f0  (orig 0x178e4f0, ret_only)
void main_f_178e4f0() {}

// sub_178f6e0  (orig 0x178f6e0, setter-chain-zero)
void main_f_178f6e0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_178f6f0  (orig 0x178f6f0, ret_only)
void main_f_178f6f0() {}

// sub_178f8d0  (orig 0x178f8d0, setter)
void main_f_178f8d0(void* a0) { *(uint8_t*)((char*)(a0) + 44) = 0; }

// sub_178f8f0  (orig 0x178f8f0, setter-chain-zero)
void main_f_178f8f0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_178f900  (orig 0x178f900, ret_only)
void main_f_178f900() {}

// sub_178f910  (orig 0x178f910, setter-chain)
void main_f_178f910(void* a0, uint64_t a1, uint32_t a2) { *(uint64_t*)((char*)(a0)) = a1; *(uint32_t*)((char*)(a0) + 32) = a2; }

// sub_178f920  (orig 0x178f920, getter)
uint64_t main_f_178f920(void* a0) { return *(uint64_t*)((char*)(a0)); }

// sub_178fb40  (orig 0x178fb40, setter)
void main_f_178fb40(void* a0) { *(uint8_t*)((char*)(a0) + 36) = 0; }

// sub_178fb50  (orig 0x178fb50, setter-chain-zero)
void main_f_178fb50(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint32_t*)((char*)a0 + 24) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
}

// sub_178fb60  (orig 0x178fb60, ret_only)
void main_f_178fb60() {}

// sub_178fd20  (orig 0x178fd20, setter)
void main_f_178fd20(void* a0) { *(uint8_t*)((char*)(a0) + 24) = 0; }

// sub_178fda0  (orig 0x178fda0, setter-chain-zero)
void main_f_178fda0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_178fdb0  (orig 0x178fdb0, ret_only)
void main_f_178fdb0() {}

// sub_178fdc0  (orig 0x178fdc0, setter-chain)
void main_f_178fdc0(void* a0, uint64_t a1, uint32_t a2) { *(uint64_t*)((char*)(a0) + 16) = a1; *(uint32_t*)((char*)(a0) + 12) = a2; }

// sub_178fdd0  (orig 0x178fdd0, getter)
uint64_t main_f_178fdd0(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// Heap_is_not_set_in_the_argument_of_the_resource_destruct  (orig 0x1790120, setter)
void main_f_1790120(void* a0) { *(uint8_t*)((char*)(a0)) = 0; }

// sub_1790130  (orig 0x1790130, setter-chain-zero)
void main_f_1790130(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 56) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 40) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_1790150  (orig 0x1790150, ret_only)
void main_f_1790150() {}

// sub_17902f0  (orig 0x17902f0, setter)
void main_f_17902f0(void* a0) { *(uint8_t*)((char*)(a0) + 64) = 0; }

// sub_1790410  (orig 0x1790410, ret_only)
void main_f_1790410() {}

// sub_17908a0  (orig 0x17908a0, setter-chain-zero)
void main_f_17908a0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 72) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 56) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 40) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_17908c0  (orig 0x17908c0, ret_only)
void main_f_17908c0() {}

// sub_17909a0  (orig 0x17909a0, setter-chain-zero)
void main_f_17909a0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 72) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 56) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 40) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_17909c0  (orig 0x17909c0, ret_only)
void main_f_17909c0() {}

// sub_1790b10  (orig 0x1790b10, setter-chain-zero)
void main_f_1790b10(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 200) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
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

// sub_1790b50  (orig 0x1790b50, ret_only)
void main_f_1790b50() {}

// sub_1790c70  (orig 0x1790c70, setter-chain-zero)
void main_f_1790c70(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 56) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 40) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_1790c90  (orig 0x1790c90, ret_only)
void main_f_1790c90() {}

// sub_1790de0  (orig 0x1790de0, setter-chain)
void main_f_1790de0(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint64_t*)((char*)(a0) + 16) = 0; }

// sub_1790df0  (orig 0x1790df0, setter-chain-zero)
void main_f_1790df0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 56) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 40) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_1790e10  (orig 0x1790e10, ret_only)
void main_f_1790e10() {}

// sub_1790f00  (orig 0x1790f00, setter-chain)
void main_f_1790f00(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint64_t*)((char*)(a0) + 16) = 0; }

// sub_1790f10  (orig 0x1790f10, setter-chain-zero)
void main_f_1790f10(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 56) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 40) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 8) = (struct u64x2){ 0, 0 };
}

// sub_1790f30  (orig 0x1790f30, ret_only)
void main_f_1790f30() {}

// sub_1791000  (orig 0x1791000, setter-chain)
void main_f_1791000(void* a0) { *(uint8_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint64_t*)((char*)(a0) + 16) = 0; }

// sub_1791010  (orig 0x1791010, ret_only)
void main_f_1791010() {}

// sub_1791070  (orig 0x1791070, ret_only)
void main_f_1791070() {}

// sub_1791190  (orig 0x1791190, mov_ret)
uint32_t main_f_1791190() { return 0; }

// sub_17911a0  (orig 0x17911a0, ret_only)
void main_f_17911a0() {}

// sub_17912b0  (orig 0x17912b0, ret_only)
void main_f_17912b0() {}

// sub_17912c0  (orig 0x17912c0, compare)
bool main_f_17912c0(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0))) != (uint64_t)(0); }

// uConstantBufferForVertexShader  (orig 0x17912d0, mov_ret)
uint32_t main_f_17912d0() { return 1; }

// sub_1791410  (orig 0x1791410, getter)
uint64_t main_f_1791410(void* a0) { return *(uint64_t*)((char*)(a0) + 8); }

// sub_1791420  (orig 0x1791420, getter)
uint64_t main_f_1791420(void* a0) { return *(uint64_t*)((char*)(a0) + 16); }

// sub_1791460  (orig 0x1791460, getter)
uint64_t main_f_1791460(void* a0) { return *(uint64_t*)((char*)(a0) + 48); }

// sub_1791470  (orig 0x1791470, getter)
uint64_t main_f_1791470(void* a0) { return *(uint64_t*)((char*)(a0) + 56); }

// sub_1791480  (orig 0x1791480, getter)
uint32_t main_f_1791480(void* a0) { return *(uint32_t*)((char*)(a0) + 24); }

// sub_1791490  (orig 0x1791490, getter)
uint32_t main_f_1791490(void* a0) { return *(uint32_t*)((char*)(a0) + 28); }

// sub_17914a0  (orig 0x17914a0, getter)
uint32_t main_f_17914a0(void* a0) { return *(uint32_t*)((char*)(a0) + 36); }

// sub_17914b0  (orig 0x17914b0, getter)
uint32_t main_f_17914b0(void* a0) { return *(uint32_t*)((char*)(a0) + 40); }

// sub_17914d0  (orig 0x17914d0, setter)
void main_f_17914d0(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 16) = a1; }

// sub_17914e0  (orig 0x17914e0, setter)
void main_f_17914e0(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 8) = a1; }

// sub_17914f0  (orig 0x17914f0, setter)
void main_f_17914f0(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 48) = a1; }

// sub_1791500  (orig 0x1791500, setter)
void main_f_1791500(void* a0, uint64_t a1) { *(uint64_t*)((char*)(a0) + 56) = a1; }

// sub_1791510  (orig 0x1791510, setter)
void main_f_1791510(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 36) = a1; }

// sub_17919c0  (orig 0x17919c0, straight)
void main_f_17919c0(void* a0) {
    *(uint8_t*)((char*)(a0) + 221) = (*(uint8_t*)((char*)(a0) + 221)) | (1);
}

// sub_1793360  (orig 0x1793360, ret_only)
void main_f_1793360() {}

// sub_1794730  (orig 0x1794730, getter-chain)
uint16_t main_f_1794730(void* a0) { return *(uint16_t*)((char*)((*(uint64_t*)((char*)(a0) + 24))) + 8); }

// sub_1794740  (orig 0x1794740, ret_only)
void main_f_1794740() {}

// sub_1794750  (orig 0x1794750, straight)
void main_f_1794750(void* a0, uint32_t a1) {
    *(uint8_t*)((char*)(a0) + 36) = (uint8_t)((((uint32_t)a1)) & (1));
}

// sub_1794760  (orig 0x1794760, compare-pred)
bool main_f_1794760(void* a0) { return (uint32_t)(*(uint8_t*)((char*)(*(uint64_t*)((char*)a0 + 24)) + 10)) != (uint32_t)(0); }

// sub_1795520  (orig 0x1795520, setter)
void main_f_1795520(void* a0) { *(uint16_t*)((char*)(a0) + 56) = 0; }

// gamma_correction  (orig 0x1796d40, setter-chain-zero)
void main_f_1796d40(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 16) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)(char*)a0 = (struct u64x2){ 0, 0 };
}

// sub_1799a10  (orig 0x1799a10, ret_only)
void main_f_1799a10() {}

// sub_1799f80  (orig 0x1799f80, setter-chain)
void main_f_1799f80(void* a0) { *(uint16_t*)((char*)(a0) + 4) = 0; *(uint32_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint32_t*)((char*)(a0) + 16) = 0; }

// sub_179a0f0  (orig 0x179a0f0, setter-chain)
void main_f_179a0f0(void* a0) { *(uint16_t*)((char*)(a0)) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; }

// sub_179a2f0  (orig 0x179a2f0, straight)
uint64_t main_f_179a2f0(void* a0, uint32_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 24));
    void* p1 = (void*)((uintptr_t)(((char *)(char*)(p0) + (uintptr_t)(((uint32_t)a1)) * 4)));
    return (*(uint64_t*)((char*)(a0) + 24)) + (*(uint32_t*)((char*)(p1) + 12));
}

// sub_179a620  (orig 0x179a620, ret_only)
void main_f_179a620() {}

// sub_179a630  (orig 0x179a630, ret_only)
void main_f_179a630() {}

// sub_179a640  (orig 0x179a640, mov_ret)
uint64_t main_f_179a640() { return 0; }

// sub_179a650  (orig 0x179a650, ret_only)
void main_f_179a650() {}

// sub_179a730  (orig 0x179a730, ret_only)
void main_f_179a730() {}

// sub_179a750  (orig 0x179a750, straight)
void main_f_179a750(void* a0, uint64_t a1) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 396) = (uint8_t)k0;
    *(uint64_t*)((char*)(a0) + 400) = 0;
    *(uint16_t*)((char*)(a0) + 408) = 0;
    *(uint64_t*)((char*)(a0) + 192) = (uint64_t)(a1);
}

// sub_179a770  (orig 0x179a770, setter)
void main_f_179a770(void* a0) { *(uint64_t*)((char*)(a0) + 192) = 0; }

// sub_179a780  (orig 0x179a780, setter-chain)
void main_f_179a780(void* a0) { *(uint64_t*)((char*)(a0) + 400) = 0; *(uint16_t*)((char*)(a0) + 408) = 0; }

// sub_179a850  (orig 0x179a850, straight)
void main_f_179a850(void* a0, void* a1) {
    *(uint64_t*)((char*)(a0) + 40) = *(uint64_t*)((char*)(a1) + 24);
    *(uint64_t*)((char*)(a0) + 24) = *(uint64_t*)((char*)(a1) + 8);
    *(uint64_t*)((char*)(a0) + 72) = *(uint64_t*)((char*)(a1) + 56);
    *(uint64_t*)((char*)(a0) + 56) = *(uint64_t*)((char*)(a1) + 40);
    *(uint64_t*)((char*)(a0) + 32) = *(uint64_t*)((char*)(a1) + 16);
    *(uint64_t*)((char*)(a0) + 16) = *(uint64_t*)((char*)(a1));
    *(uint64_t*)((char*)(a0) + 64) = *(uint64_t*)((char*)(a1) + 48);
    *(uint64_t*)((char*)(a0) + 48) = *(uint64_t*)((char*)(a1) + 32);
}

// uTexture3  (orig 0x179a9e0, getter)
uint64_t main_f_179a9e0(void* a0) { return *(uint64_t*)((char*)(a0) + 232); }

// uTexture3  (orig 0x179a9f0, getter)
uint64_t main_f_179a9f0(void* a0) { return *(uint64_t*)((char*)(a0) + 240); }

// sub_179aa60  (orig 0x179aa60, ret_only)
void main_f_179aa60() {}

// sub_179ba80  (orig 0x179ba80, straight-line)
uint64_t main_f_179ba80(uint64_t a0, uint32_t a1) { return ((((uint64_t)a0)) + ((((uint64_t)(((uint32_t)(((uint32_t)a1)))))) * (((uint64_t)(((uint32_t)(40))))))) + (624); }

// sub_179c900  (orig 0x179c900, straight)
void* main_f_179c900(void* a0, int32_t a1) {
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 608));
    return ((char *)(char*)(p0) + (uintptr_t)(((int32_t)a1)) * 8);
}

// sub_179e670  (orig 0x179e670, ret_only)
void main_f_179e670() {}

// sub_17a0130  (orig 0x17a0130, getter-chain)
uint64_t main_f_17a0130(void* a0, int32_t a1) {
    uint64_t t0 = *(uint64_t*)(char*)a0;
    return *(uint64_t*)((char*)(t0) + (uintptr_t)(a1) * 8);
}

// sub_17a0140  (orig 0x17a0140, straight)
uint32_t main_f_17a0140(void* a0) { return (*(uint32_t*)((char*)(a0) + 8)) - (1); }

// sub_17a2d10  (orig 0x17a2d10, mov_ret)
uint32_t main_f_17a2d10() { return 1; }

// sub_17a2e30  (orig 0x17a2e30, compare)
bool main_f_17a2e30(uint64_t unused0, void* a1) { return (uint32_t)(*(uint32_t*)((char*)(a1) + 16)) == (uint64_t)(4); }

// sub_17a3150  (orig 0x17a3150, compare)
bool main_f_17a3150(uint64_t unused0, void* a1) { return (uint32_t)(*(uint32_t*)((char*)(a1) + 16)) == (uint64_t)(11); }

// sub_17a37a0  (orig 0x17a37a0, ret_only)
void main_f_17a37a0() {}

// sub_17a4330  (orig 0x17a4330, getter)
uint64_t main_f_17a4330(void* a0) { return *(uint64_t*)((char*)(a0) + 48); }

// sub_17a4340  (orig 0x17a4340, straight)
void main_f_17a4340(void* a0) {
    *(uint16_t*)((char*)(a0) + 80) = (*(uint16_t*)((char*)(a0) + 80)) & (4294967287);
}

// sub_17a43d0  (orig 0x17a43d0, ret_only)
void main_f_17a43d0() {}

// sub_17ab1b0  (orig 0x17ab1b0, mov_ret)
uint32_t main_f_17ab1b0() { return -1; }

// sub_17ab1c0  (orig 0x17ab1c0, ret_only)
void main_f_17ab1c0() {}

// sub_17ab210  (orig 0x17ab210, mov_ret)
uint32_t main_f_17ab210() { return 255; }

// sub_17ab220  (orig 0x17ab220, ret_only)
void main_f_17ab220() {}

// sub_17ac430  (orig 0x17ac430, ret_only)
void main_f_17ac430() {}

// sub_17ac590  (orig 0x17ac590, straight)
void main_f_17ac590(void* a0, void* a1) {
    *(uint64_t*)((char*)(a1) + 136) = *(uint64_t*)((char*)(a0) + 120);
    *(uint64_t*)((char*)(a1) + 168) = *(uint64_t*)((char*)(a0) + 152);
    *(uint64_t*)((char*)(a1) + 152) = *(uint64_t*)((char*)(a0) + 136);
    *(uint64_t*)((char*)(a1) + 128) = *(uint64_t*)((char*)(a0) + 112);
    *(uint64_t*)((char*)(a1) + 160) = *(uint64_t*)((char*)(a0) + 144);
    *(uint64_t*)((char*)(a1) + 144) = *(uint64_t*)((char*)(a0) + 128);
    *(uint8_t*)((char*)(a1) + 395) = 0;
}

// sub_17ac6f0  (orig 0x17ac6f0, mov_ret)
uint32_t main_f_17ac6f0() { return 0; }

// sub_17b0e00  (orig 0x17b0e00, compare)
bool main_f_17b0e00(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 216)) != (uint64_t)(0); }

// sub_17b0fa0  (orig 0x17b0fa0, straight-line)
uint32_t main_f_17b0fa0(void* a0, int32_t a1) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((int32_t)a1)) * 4)));
    return *(uint32_t*)((char*)(p0) + 224);
}

// sub_17b0fb0  (orig 0x17b0fb0, straight)
void main_f_17b0fb0(void* a0, int32_t a1, void* a2) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((int32_t)a1)) * 4)));
    *(uint32_t*)((char*)(p0) + 224) = *(uint32_t*)((char*)(a2));
}

// sub_17b2c00  (orig 0x17b2c00, ret_only)
void main_f_17b2c00() {}

// sub_17b2d00  (orig 0x17b2d00, ret_only)
void main_f_17b2d00() {}

// sub_17b2f40  (orig 0x17b2f40, mov_ret)
uint64_t main_f_17b2f40() { return 0; }

// sub_17b2f50  (orig 0x17b2f50, ret_only)
void main_f_17b2f50() {}

// sub_17b3330  (orig 0x17b3330, ret_only)
void main_f_17b3330() {}

// sub_17b3ab0  (orig 0x17b3ab0, straight-line)
void main_f_17b3ab0(void* a0, uint32_t a1) {
    *(uint32_t*)((char*)(a0) + 8) = ((*(uint32_t*)((char*)(a0) + 8)) & (4294967055)) | (((((uint32_t)a1)) << 4));
}

// sub_17b3ad0  (orig 0x17b3ad0, straight)
void main_f_17b3ad0(void* a0, uint32_t a1) {
    *(uint32_t*)((char*)(a0) + 8) = ((*(uint32_t*)((char*)(a0) + 8)) & (4294967288)) | (((uint32_t)a1));
}

// sub_17b3ff0  (orig 0x17b3ff0, straight)
uint32_t main_f_17b3ff0(void* a0) { return ((*(uint32_t*)((char*)(a0) + 8)) >> (4)) & (15); }

// sub_17b49d0  (orig 0x17b49d0, ret_only)
void main_f_17b49d0() {}

// sub_17b49f0  (orig 0x17b49f0, straight)
void main_f_17b49f0(void* a0) {
    *(uint64_t*)((char*)(a0) + 8) = 0;
    *(uint16_t*)((char*)(a0)) = ((*(uint16_t*)((char*)(a0))) & (57344)) | (144);
}

// sub_17b4a70  (orig 0x17b4a70, ret_only)
void main_f_17b4a70() {}

// sub_17b4a80  (orig 0x17b4a80, ret_only)
void main_f_17b4a80() {}

// sub_17b5cb0  (orig 0x17b5cb0, compare)
bool main_f_17b5cb0(void* a0) { return (uint64_t)(*(uint64_t*)((char*)(a0) + 320)) != (uint64_t)(0); }

// sub_17b7510  (orig 0x17b7510, getter)
uint64_t main_f_17b7510(void* a0) { return *(uint64_t*)((char*)(a0) + 240); }

// sub_17b7780  (orig 0x17b7780, ret_only)
void main_f_17b7780() {}

// sub_17b8250  (orig 0x17b8250, ret_only)
void main_f_17b8250() {}

// sub_17b8970  (orig 0x17b8970, straight-line)
typedef struct { unsigned char b[24]; } __S_f_17b8970;
__S_f_17b8970 main_f_17b8970(void* a0) {
    __S_f_17b8970 r;
    void* p0 = (void*)(*(uint64_t *)((char*)(a0) + 16));
    *(uint16_t *)((char *)&r + 0) = (uint16_t)(*(uint32_t*)((char*)(p0) + 36));
    *(uint16_t *)((char *)&r + 2) = (uint16_t)(*(uint32_t*)((char*)(p0) + 40));
    return r;
}

// sub_17b8990  (orig 0x17b8990, getter-chain)
uint32_t main_f_17b8990(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 16))) + 28); }

// sub_17b89f0  (orig 0x17b89f0, getter-chain)
uint64_t main_f_17b89f0(void* a0) { return *(uint64_t*)((char*)((*(uint64_t*)((char*)(a0) + 16))) + 136); }

// sub_17b8a00  (orig 0x17b8a00, getter-chain)
uint64_t main_f_17b8a00(void* a0) { return *(uint64_t*)((char*)((*(uint64_t*)((char*)(a0) + 16))) + 136); }

// sub_17b8e00  (orig 0x17b8e00, getter)
uint32_t main_f_17b8e00(void* a0) { return *(uint32_t*)((char*)(a0) + 208); }

// sub_17b8e10  (orig 0x17b8e10, compare)
bool main_f_17b8e10(void* a0) { return (uint32_t)(*(uint32_t*)((char*)(a0) + 208)) != (uint64_t)(0); }

// sub_17b8e20  (orig 0x17b8e20, getter)
uint64_t main_f_17b8e20(void* a0) { return *(uint64_t*)((char*)(a0) + 32); }

// sub_17b8e30  (orig 0x17b8e30, getter)
uint64_t main_f_17b8e30(void* a0) { return *(uint64_t*)((char*)(a0) + 32); }

// sub_17b8e40  (orig 0x17b8e40, getter)
uint64_t main_f_17b8e40(void* a0) { return *(uint64_t*)((char*)(a0) + 56); }

// sub_17b8f30  (orig 0x17b8f30, straight-line)
typedef struct { unsigned char b[24]; } __S_f_17b8f30;
__S_f_17b8f30 main_f_17b8f30() {
    __S_f_17b8f30 r;
    *(uint32_t *)((char *)&r + 0) = 0;
    return r;
}

// sub_17b8f40  (orig 0x17b8f40, mov_ret)
uint32_t main_f_17b8f40() { return 1; }

// sub_17b8f50  (orig 0x17b8f50, mov_ret)
uint64_t main_f_17b8f50() { return 0; }

// sub_17b8f60  (orig 0x17b8f60, mov_ret)
uint64_t main_f_17b8f60() { return 0; }

// sub_17bb4a0  (orig 0x17bb4a0, ret_only)
void main_f_17bb4a0() {}

// sub_17bbf70  (orig 0x17bbf70, straight-line)
uint32_t main_f_17bbf70(void* a0, int32_t a1) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((int32_t)a1)) * 4)));
    return *(uint32_t*)((char*)(p0) + 232);
}

// sub_17bbf80  (orig 0x17bbf80, straight)
void main_f_17bbf80(void* a0, int32_t a1, void* a2) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((int32_t)a1)) * 4)));
    *(uint32_t*)((char*)(p0) + 232) = *(uint32_t*)((char*)(a2));
}

// sub_17bbff0  (orig 0x17bbff0, straight)
uint8_t main_f_17bbff0(void* a0) { return (*(uint8_t*)((char*)(a0) + 265)) + (1); }

// sub_17c02d0  (orig 0x17c02d0, mov_ret)
uint32_t main_f_17c02d0() { return 1; }

// sub_17c19e0  (orig 0x17c19e0, straight)
void main_f_17c19e0(void* a0) {
    uint32_t k0 = 1;
    *(uint8_t*)((char*)(a0) + 9) = (uint8_t)k0;
}

// sub_17c1b90  (orig 0x17c1b90, getter-chain)
uint8_t main_f_17c1b90(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0) + 568))) + 42); }

// vfx_system_deleted_the_registered_binary_resource_id_d  (orig 0x17c48e0, ret_only)
void main_f_17c48e0() {}

// Emitter_Initialize_Failed  (orig 0x17c9ae0, setter)
void main_f_17c9ae0(void* a0, uint32_t a1) { *(uint32_t*)((char*)(a0) + 1024) = a1; }

// sub_17ccc00  (orig 0x17ccc00, ret_only)
void main_f_17ccc00() {}

// sub_17d4c20  (orig 0x17d4c20, getter)
uint32_t main_f_17d4c20(void* a0) { return *(uint32_t*)((char*)(a0) + 16); }

// sub_17d4c30  (orig 0x17d4c30, getter)
uint32_t main_f_17d4c30(void* a0) { return *(uint32_t*)((char*)(a0) + 20); }

// sub_17d4c40  (orig 0x17d4c40, getter)
uint64_t main_f_17d4c40(void* a0) { return *(uint64_t*)((char*)(a0) + 32); }

// sub_17d4c50  (orig 0x17d4c50, getter)
uint64_t main_f_17d4c50(void* a0) { return *(uint64_t*)((char*)(a0) + 40); }

// sub_17d4c70  (orig 0x17d4c70, ptr_add)
void* main_f_17d4c70(void* a0) { return (char*)a0 + 72; }

// sub_17d4c80  (orig 0x17d4c80, mov_ret)
uint32_t main_f_17d4c80() { return 1; }

// sub_17d4c90  (orig 0x17d4c90, mov_ret)
uint32_t main_f_17d4c90() { return 0; }

// sub_17d4ca0  (orig 0x17d4ca0, mov_ret)
uint32_t main_f_17d4ca0() { return 6405; }

// sub_17d4cb0  (orig 0x17d4cb0, mov_ret)
uint32_t main_f_17d4cb0() { return 2; }

// sub_17d4cc0  (orig 0x17d4cc0, straight-line)
uint64_t main_f_17d4cc0(void* a0, uint32_t a1) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((uint32_t)a1)) * 8)));
    return *(uint64_t*)((char*)(p0) + 112);
}

// sub_17d4df0  (orig 0x17d4df0, getter-chain)
uint32_t main_f_17d4df0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 24))) + 80); }

// sub_17d4e00  (orig 0x17d4e00, getter-chain)
uint32_t main_f_17d4e00(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 40))) + 44); }

// sub_17d4e60  (orig 0x17d4e60, ptr_add)
void* main_f_17d4e60(void* a0) { return (char*)a0 + 48; }

// sub_17d4e70  (orig 0x17d4e70, getter-chain)
uint8_t main_f_17d4e70(void* a0) { return *(uint8_t*)((char*)((*(uint64_t*)((char*)(a0) + 24))) + 77); }

// sub_17d4e80  (orig 0x17d4e80, straight-line)
uint32_t main_f_17d4e80(void* a0, uint32_t a1) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((uint32_t)a1)) * 4)));
    return *(uint32_t*)((char*)(p0) + 84);
}

// sub_17d4e90  (orig 0x17d4e90, straight-line)
uint32_t main_f_17d4e90(void* a0, uint32_t a1) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((uint32_t)a1)) * 4)));
    return *(uint32_t*)((char*)(p0) + 64);
}

// sub_17d4ea0  (orig 0x17d4ea0, getter-chain)
uint32_t main_f_17d4ea0(void* a0) { return *(uint32_t*)((char*)((*(uint64_t*)((char*)(a0) + 40))) + 40); }

// sub_17d4eb0  (orig 0x17d4eb0, straight-line)
uint64_t main_f_17d4eb0(void* a0, uint32_t a1) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((uint32_t)a1)) * 8)));
    return *(uint64_t*)((char*)(p0) + 104);
}

// Gap_d  (orig 0x17d57a0, setter-chain-zero)
void main_f_17d57a0(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint8_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a0 + 8) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 16) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 48) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint64_t*)((char*)a0 + 24) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
}

// Gap_d  (orig 0x17d5c10, setter-chain-zero)
void main_f_17d5c10(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(uint8_t*)(char*)a0 = 0;
    __asm__ __volatile__("" ::: "memory");
    *(uint32_t*)((char*)a0 + 40) = 0;
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 24) = (struct u64x2){ 0, 0 };
}

// sub_17d60b0  (orig 0x17d60b0, setter)
void main_f_17d60b0(void* a0) { *(uint8_t*)((char*)(a0)) = 0; }

// sub_17d6d30  (orig 0x17d6d30, mov_ret)
uint32_t main_f_17d6d30() { return 1; }

// Emitter_Initialize_Failed  (orig 0x17de500, copy2)
void main_f_17de500(void* a0, void* a1) { *(uint64_t*)((char*)(a1) + 152) = *(uint64_t*)((char*)(a0) + 2240); }

// sub_17df790  (orig 0x17df790, setter-chain)
void main_f_17df790(void* a0, uint32_t a1, uint64_t a2) { *(uint32_t*)((char*)(a0) + 4488L) = a1; *(uint64_t*)((char*)(a0) + 4520L) = a2; }

// sub_17e5360  (orig 0x17e5360, mov_ret)
uint32_t main_f_17e5360() { return 1; }

// sub_17e5370  (orig 0x17e5370, call)
extern void sub_17e53b0();
uint32_t main_f_17e5370(void* a0) {
    uint64_t f_17e5370__r0 = ((uint64_t (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t))&sub_17e53b0)(((uintptr_t)(*(uint64_t*)((char*)(a0)))), ((uintptr_t)(*(uint64_t*)((char*)(a0) + 8))), ((uintptr_t)(*(uint32_t*)((char*)(a0) + 16))), ((uintptr_t)(*(uint64_t*)((char*)(a0) + 24))), ((uintptr_t)(*(uint64_t*)((char*)(a0) + 32))));
    uint32_t r0 = 1;
    asm volatile("");
    return r0;
}

// sub_17e53a0  (orig 0x17e53a0, mov_ret)
uint32_t main_f_17e53a0() { return 1; }

// sub_17e5d50  (orig 0x17e5d50, ret_only)
void main_f_17e5d50() {}

// TempBuffer_WorkSize_d  (orig 0x17e8260, setter-chain)
void main_f_17e8260(void* a0) { *(uint32_t*)((char*)(a0)) = 0; *(uint8_t*)((char*)(a0) + 48) = 0; *(uint64_t*)((char*)(a0) + 24) = 0; *(uint64_t*)((char*)(a0) + 32) = 0; *(uint64_t*)((char*)(a0) + 8) = 0; *(uint64_t*)((char*)(a0) + 16) = 0; }

// sub_17e84c0  (orig 0x17e84c0, ret_only)
void main_f_17e84c0() {}

// TempBuffer_WorkSize_d  (orig 0x17e8d00, setter-chain-zero)
void main_f_17e8d00(void* a0) {
    struct u64x2 { uint64_t a, b; };
    *(struct u64x2*)((char*)a0 + 80) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 64) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 48) = (struct u64x2){ 0, 0 };
    __asm__ __volatile__("" ::: "memory");
    *(struct u64x2*)((char*)a0 + 32) = (struct u64x2){ 0, 0 };
}

// sub_17e8ec0  (orig 0x17e8ec0, straight-line)
uint64_t main_f_17e8ec0(void* a0, uint32_t a1) {
    void* p0 = (void*)((uintptr_t)(((char *)(char*)(a0) + (uintptr_t)(((uint32_t)a1)) * 8)));
    return *(uint64_t*)((char*)(p0) + 80);
}

// sub_17e8ed0  (orig 0x17e8ed0, ret_only)
void main_f_17e8ed0() {}

