#include <stdlib.h>

uintptr_t semihost_call_8(uintptr_t p0, uintptr_t p1, uintptr_t p2, uintptr_t p3, uintptr_t p4, uintptr_t p5, uintptr_t p6, uintptr_t call) {
    register uintptr_t
        a0 asm("a0") = p0,
        a1 asm("a1") = p1,
        a2 asm("a2") = p2,
        a3 asm("a3") = p3,
        a4 asm("a4") = p4,
        a5 asm("a5") = p5,
        a6 asm("a6") = p6,
        a7 asm("a7") = call;
    asm volatile("ecall" : "+r"(a0) : "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7) : "memory");
    return a0;
}

uintptr_t semihost_call_7(uintptr_t p0, uintptr_t p1, uintptr_t p2, uintptr_t p3, uintptr_t p4, uintptr_t p5, uintptr_t call) {
    register uintptr_t
        a0 asm("a0") = p0,
        a1 asm("a1") = p1,
        a2 asm("a2") = p2,
        a3 asm("a3") = p3,
        a4 asm("a4") = p4,
        a5 asm("a5") = p5,
        a6 asm("a6"),
        a7 asm("a7") = call;
    asm volatile("ecall" : "+r"(a0) : "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7) : "memory");
    return a0;
}

uintptr_t semihost_call_6(uintptr_t p0, uintptr_t p1, uintptr_t p2, uintptr_t p3, uintptr_t p4, uintptr_t call) {
    register uintptr_t
        a0 asm("a0") = p0,
        a1 asm("a1") = p1,
        a2 asm("a2") = p2,
        a3 asm("a3") = p3,
        a4 asm("a4") = p4,
        a5 asm("a5"),
        a6 asm("a6"),
        a7 asm("a7") = call;
    asm volatile("ecall" : "+r"(a0) : "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7) : "memory");
    return a0;
}

uintptr_t semihost_call_5(uintptr_t p0, uintptr_t p1, uintptr_t p2, uintptr_t p3, uintptr_t call) {
    register uintptr_t
        a0 asm("a0") = p0,
        a1 asm("a1") = p1,
        a2 asm("a2") = p2,
        a3 asm("a3") = p3,
        a4 asm("a4"),
        a5 asm("a5"),
        a6 asm("a6"),
        a7 asm("a7") = call;
    asm volatile("ecall" : "+r"(a0) : "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7) : "memory");
    return a0;
}

uintptr_t semihost_call_4(uintptr_t p0, uintptr_t p1, uintptr_t p2, uintptr_t call) {
    register uintptr_t
        a0 asm("a0") = p0,
        a1 asm("a1") = p1,
        a2 asm("a2") = p2,
        a3 asm("a3"),
        a4 asm("a4"),
        a5 asm("a5"),
        a6 asm("a6"),
        a7 asm("a7") = call;
    asm volatile("ecall" : "+r"(a0) : "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7) : "memory");
    return a0;
}

uintptr_t semihost_call_3(uintptr_t p0, uintptr_t p1, uintptr_t call) {
    register uintptr_t
        a0 asm("a0") = p0,
        a1 asm("a1") = p1,
        a2 asm("a2"),
        a3 asm("a3"),
        a4 asm("a4"),
        a5 asm("a5"),
        a6 asm("a6"),
        a7 asm("a7") = call;
    asm volatile("ecall" : "+r"(a0) : "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7) : "memory");
    return a0;
}

uintptr_t semihost_call_2(uintptr_t p0, uintptr_t call) {
    register uintptr_t
        a0 asm("a0") = p0,
        a1 asm("a1"),
        a2 asm("a2"),
        a3 asm("a3"),
        a4 asm("a4"),
        a5 asm("a5"),
        a6 asm("a6"),
        a7 asm("a7") = call;
    asm volatile("ecall" : "+r"(a0) : "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7) : "memory");
    return a0;
}

uintptr_t semihost_call_1(uintptr_t call) {
    register uintptr_t
        a0 asm("a0"),
        a1 asm("a1"),
        a2 asm("a2"),
        a3 asm("a3"),
        a4 asm("a4"),
        a5 asm("a5"),
        a6 asm("a6"),
        a7 asm("a7") = call;
    asm volatile("ecall" : "=r"(a0) : "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5), "r"(a6), "r"(a7) : "memory");
    return a0;
}



uint32_t strlen(const char* str) {
    const char* pos = str;
    while(*pos++);
    return pos-str;
}

void puts(const char* str) {
    semihost_call_4(0, (uintptr_t)str, strlen(str), 64);
}

void exit(int32_t err) {
    semihost_call_2(err, 93);
     __builtin_unreachable();
}
