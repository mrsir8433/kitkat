#pragma once

#include <assert.h>

// unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// floating point types
typedef float f32;
typedef double f64;

// boolean types
typedef int b32;
typedef char b8;

#define STATIC_ASSERT static_assert

STATIC_ASSERT(sizeof(u8) == 1, "u8 not right size");
STATIC_ASSERT(sizeof(u16) == 2, "u16 not right size");
STATIC_ASSERT(sizeof(u32) == 4, "u32 not right size");
STATIC_ASSERT(sizeof(u64) == 8, "u64 not right size");

STATIC_ASSERT(sizeof(i8) == 1, "i8 not right size");
STATIC_ASSERT(sizeof(i16) == 2, "i16 not right size");
STATIC_ASSERT(sizeof(i32) == 4, "i32 not right size");
STATIC_ASSERT(sizeof(i64) == 8, "i64 not right size");

STATIC_ASSERT(sizeof(f32) == 4, "f32 not right size");
STATIC_ASSERT(sizeof(f64) == 8, "f64 not right size");

STATIC_ASSERT(sizeof(b32) == 4, "b32 not right size");
STATIC_ASSERT(sizeof(b8) == 1, "b8 not right size");

#define TRUE 1
#define FALSE 0

#define KAPI __declspec(dllexport)

// #ifdef KEXPORT
// // EXPORTS
// #ifdef _MSC_VER
// #define KAPI __declspec(dllexport)
// #else
// #define KAPI __attribute__((visibility("default")))
// #endif
// #endif
