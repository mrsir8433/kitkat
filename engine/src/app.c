#include "include/app.h"

#include "include/logger.h"
#include "include/platform.h"

typedef struct application {
  Sketch* sketch;
  b8 running;
  b8 suspended;
  Platform platform;

  i32 w;
  i32 h;

  f64 last_time;
} Application;

// The application singleton
static Application app;
static b8 initialized = FALSE;

// Creates the app and initilizes the subsystems
b8 app_create(Sketch* s) {
  // check if app is double-initializing
  if (initialized) {
    KERROR("Application initialised more than once");
    return FALSE;
  }

  app.sketch = s;

  // initialises the logging subsystem
  log_init();

  app.running = TRUE;
  app.suspended = FALSE;

  if (!platform_init(&(app.platform), s->config.name, s->config.x, s->config.y,
                     s->config.w, s->config.h)) {
    KERROR("Application startup failed.");
    return FALSE;
  }

  // sketches setup routine

  if (!app.sketch->setup()) {
    KFATAL("Sketch setup failed!");
    return FALSE;
  }
  app.sketch->on_resize(app.w, app.h);

  initialized = TRUE;
  return TRUE;  // ALL OK
}

// Game loop
b8 app_run() {
  while (app.running) {
    if (!platform_poll()) {
      app.running = FALSE;
    }

    if (!app.sketch->update((f64)0.00016)) {
      KFATAL("Game update failed!");
      app.running = FALSE;
      break;
    }
    if (!app.sketch->draw((f64)0.00016)) {
      KFATAL("Game draw failed!");
      app.running = FALSE;
      break;
    }
  }
  app.running = FALSE;
  platform_shutdown(&(app.platform));
  return TRUE;
}