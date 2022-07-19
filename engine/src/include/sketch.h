#pragma once

typedef struct app_init_config {
  char* name;  // title
  i32 x;       // starting xpos
  i32 y;       // starting ypos
  i32 w;       // starting width
  i32 h;       // starting height
} AppInitConfig;

typedef struct sketch {
  AppInitConfig config;

  // Setup the game
  b8 (*setup)();

  // Updates every frame
  b8 (*update)(f64 delta);

  // Draws every frame
  b8 (*draw)(f64 delta);

  // Callback on resize.
  void (*on_resize)(i32 width, i32 height);

  void* internal;

} Sketch;