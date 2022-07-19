#include "include/platform.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FATAL, ERROR, WARN, INFO, DEBUG, TRACE
static u8 level_color[6] = {64, 4, 6, 2, 1, 8};

void process_event(SDL_Event e);

// Initializes the platform
b8 platform_init(Platform *self, const char *title, i32 x, i32 y, i32 width,
                 i32 height) {
  SDL_Window *window;
  u32 flags = SDL_WINDOW_VULKAN;

  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    return FALSE;
  }
  // Create an application window with the following settings:
  window = SDL_CreateWindow(title,   // window title
                            x,       // initial x position
                            y,       // initial y position
                            width,   // width, in pixels
                            height,  // height, in pixels
                            flags    // flags - see below
  );

  void *win_info = malloc(sizeof(SDL_SysWMinfo));
  SDL_GetWindowWMInfo(window, (SDL_SysWMinfo *)win_info);
  self->internal_state = win_info;
  return TRUE;
}

// Shutsdown the platform
void platform_shutdown(Platform *self) {
  if (self->internal_state != NULL) {
    free(self->internal_state);
    self->internal_state = NULL;
  }
  SDL_Quit();
}

// Continuously poll for platform events
b8 platform_poll() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    process_event(e);
  }
  return TRUE;
}

void *platform_alloc_mem(u64 size, b8 aligned) {
  printf("%d", aligned);
  return malloc(size);
}
void platform_free_mem(void *mem_ptr, b8 aligned) {
  printf("%d", aligned);
  free(mem_ptr);
  mem_ptr = NULL;
}
void *platform_zero_mem(void *mem_ptr, u64 length) {
  return memset(mem_ptr, 0, length);
}
void *platform_set_mem(void *mem_ptr, i32 value, u64 length) {
  return memset(mem_ptr, value, length);
}
void *platform_copy_mem(void *dest_ptr, const void *src_ptr, u64 length) {
  return memcpy(dest_ptr, src_ptr, length);
}

void platform_console_write(const char *message, u8 color) {
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO info;
  GetConsoleScreenBufferInfo(console, &info);
  SetConsoleTextAttribute(console, level_color[color]);
  fprintf(stdout, "%s", message);
  SetConsoleTextAttribute(console, info.wAttributes);
}
void platform_console_err(const char *message, u8 color) {
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO info;
  GetConsoleScreenBufferInfo(console, &info);
  SetConsoleTextAttribute(console, level_color[color]);
  fprintf(stderr, "%s", message);
  SetConsoleTextAttribute(console, info.wAttributes);
}

u64 platform_get_abstime() { return SDL_GetTicks64(); }

void platform_sleep(u32 ms) { SDL_Delay(ms); }

void process_event(SDL_Event e) {
  switch (e.type) {
    case SDL_QUIT:

      // case SDL_APP_TERMINATING
      // case SDL_APP_LOWMEMORY
      // case SDL_APP_WILLENTERBACKGROUND
      // case SDL_APP_DIDENTERBACKGROUND
      // case SDL_APP_WILLENTERFOREGROUND
      // case SDL_APP_DIDENTERFOREGROUND
    case SDL_WINDOWEVENT:

      // case SDL_SYSWMEVENT
    case SDL_KEYDOWN:
    case SDL_KEYUP:
      // case SDL_TEXTEDITING
      // case SDL_TEXTINPUT
      // case SDL_KEYMAPCHANGED
    case SDL_MOUSEMOTION:
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
    case SDL_MOUSEWHEEL:
      // case SDL_JOYAXISMOTION
      // case SDL_JOYBALLMOTION
      // case SDL_JOYHATMOTION
      // case SDL_JOYBUTTONDOWN
      // case SDL_JOYBUTTONUP
      // case SDL_JOYDEVICEADDED
      // case SDL_JOYDEVICEREMOVED

      // case SDL_CONTROLLERAXISMOTION
      // case SDL_CONTROLLERBUTTONDOWN
      // case SDL_CONTROLLERBUTTONUP
      // case SDL_CONTROLLERDEVICEADDED
      // case SDL_CONTROLLERDEVICEREMOVED
      // case SDL_CONTROLLERDEVICEREMAPPED

      // case SDL_FINGERDOWN
      // case SDL_FINGERUP
      // case SDL_FINGERMOTION
      // case SDL_DOLLARGESTURE
      // case SDL_DOLLARRECORD
      // case SDL_MULTIGESTURE

      // case SDL_CLIPBOARDUPDATE

      // case SDL_DROPFILE
      // case SDL_DROPTEXT
      // case SDL_DROPBEGIN
      // case SDL_DROPCOMPLETE

      // case SDL_AUDIODEVICEADDED
      // case SDL_AUDIODEVICEREMOVED

      // case SDL_RENDER_TARGETS_RESET
      // case SDL_RENDER_DEVICE_RESET

      // case SDL_USEREVENT
      break;
  }
}
