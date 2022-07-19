#include <entry.h>
#include <platform.h>
#include <sketch.h>

#include "include/sketch1.h"

b8 create_sketch(Sketch* out1) {
  AppInitConfig config = {
      .name = "testbed", .x = 100, .y = 100, .w = 512, .h = 512};

  out1->config = config;
  out1->setup = setup;
  out1->update = update;
  out1->draw = draw;
  out1->on_resize = on_resize;

  out1->internal = NULL;

  return TRUE;
}