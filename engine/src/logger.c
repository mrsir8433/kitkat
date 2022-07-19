#include "include/logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

b8 log_init() {
  KDEBUG("Logger initialised.");
  return TRUE;
}
void log_quit() { KDEBUG("Logger quitted."); }

void log_output(LogLevel level, const char* format, ...) {
  const i32 buffer_length = 32000;
  char* level_str[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ",
                        "[INFO]: ",  "[DEBUG]: ", "[TRACE]: "};

  b8 is_error = (level < LOG_LEVEL_WARN);

  char buf1[buffer_length];
  char buf2[buffer_length];  // final buffer

  memset(buf1, 0, sizeof(buf1));
  memset(buf2, 0, sizeof(buf2));

  va_list list;
  va_start(list, format);
  vsnprintf(buf1, buffer_length, format, list);
  va_end(list);

  sprintf(buf2, "%s%s\n", level_str[level], buf1);
  if (is_error) {
    platform_console_err(buf2, level);
  } else {
    platform_console_write(buf2, level);
  }
}

void assert_fail(const char* expr, const char* message, const char* file,
                 i32 line) {
  log_output(LOG_LEVEL_FATAL, "expr: %s, %s, %s:%d", expr, message, file, line);
}