#pragma once

#include "app.h"
#include "logger.h"
#include "sketch.h"

extern b8 create_sketch(Sketch* out1);

int main() {
  // AppInitConfig config = { .name = "testbed", .x = 200, .y = 200, .w = 512,
  // .h = 512 };

  Sketch s;
  if (!create_sketch(&s)) {
    KERROR("Sketch creation failed");
    return -1;
  }

  if (!s.setup || !s.update || !s.draw || !s.on_resize) {
    KERROR("Functions cannot be null pointer");
    return -2;
  }

  if (!app_create(&s)) {
    KERROR("app creation failed");
    return -3;
  }

  if (!app_run()) {
    KERROR("app closed unexpectedly");
    return -4;
  }

  return 0;
}