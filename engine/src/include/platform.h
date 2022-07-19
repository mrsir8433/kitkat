#pragma once

#include "defines.h"

typedef struct platform {
  void* internal_state;
} Platform;

// \param self platform_state_object
// \return true if successful
b8 platform_init(Platform* self, const char* title, i32 x, i32 y, i32 width,
                 i32 height);

void platform_shutdown(Platform* self);
b8 platform_poll();

KAPI void* platform_alloc_mem(u64 size, b8 aligned);
KAPI void platform_free_mem(void* mem_ptr, b8 aligned);
void* platform_zero_mem(void* mem_ptr, u64 length);
void* platform_set_mem(void* mem_ptr, i32 value, u64 length);
void* platform_copy_mem(void* dest_ptr, const void* src_ptr, u64 length);

void platform_console_write(const char* message, u8 color);
void platform_console_err(const char* message, u8 color);

u64 platform_get_abstime(void);
void platform_sleep(u32 ms);
