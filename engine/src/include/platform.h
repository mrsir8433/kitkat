#pragma once

#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

#include "defines.h"

KAPI typedef struct platform_state
{
    SDL_SysWMinfo *internal_state;
} PlatformState;

// \param self platform_state_object
// \return true if successful
KAPI b8 platform_init(
    PlatformState *self,
    const char *title,
    i32 x,
    i32 y,
    i32 width,
    i32 height);

void platform_shutdown(PlatformState *self);
KAPI b8 platform_poll(PlatformState *self);

void *platform_alloc_mem(u64 size, b8 aligned);
void platform_free_mem(void *mem_ptr, b8 aligned);
void *platform_zero_mem(void *mem_ptr, u64 length);
void *platform_set_mem(void *mem_ptr, i32 value, u64 length);
void *platform_copy_mem(void *dest_ptr, const void *src_ptr, u64 length);

void platform_console_write(const char *message, u8 color);
void platform_console_err(const char *message, u8 color);

u64 platform_get_abstime();

KAPI void platform_sleep(u32 ms);