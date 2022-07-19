#include "include/sketch1.h"

#include <logger.h>

b8 setup() {
  KDEBUG("SETUP() called...");
  return TRUE;
}
b8 update(f64 delta) {
  KDEBUG("UPDATE() called...%f", delta);
  return TRUE;
}
b8 draw(f64 delta) {
  KDEBUG("DRAW() called...%f", delta);
  return TRUE;
}
void on_resize(i32 w, i32 h) { KDEBUG("%d, %d", w, h); }