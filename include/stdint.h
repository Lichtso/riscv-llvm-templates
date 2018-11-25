#ifndef STDINT_H
#define STDINT_H

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;
typedef signed long intptr_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef unsigned long uintptr_t;

_Static_assert(sizeof(int8_t) == 1 && sizeof(uint8_t) == 1, "sizeof int8_t, uint8_t");
_Static_assert(sizeof(int16_t) == 2 && sizeof(uint16_t) == 2, "sizeof int16_t, uint16_t");
_Static_assert(sizeof(int32_t) == 4 && sizeof(uint32_t) == 4, "sizeof int32_t, uint32_t");
_Static_assert(sizeof(int64_t) == 8 && sizeof(uint64_t) == 8, "sizeof int64_t, uint64_t");
_Static_assert(sizeof(intptr_t) == sizeof(void*) && sizeof(uintptr_t) == sizeof(void*), "sizeof intptr_t, uintptr_t");

#endif
