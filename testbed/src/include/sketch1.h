#pragma once

#include <defines.h>

typedef struct sketch_state {
  i32 data1;
} SketchState;

b8 setup();
b8 update(f64 delta);
b8 draw(f64 delta);
void on_resize(i32 w, i32 h);
