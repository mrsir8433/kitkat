#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "defines.h"
#include "platform.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// Comment this line to disable assertions.
#define KASSERT_ENABLED

#if KRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level
{
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} LogLevel;

b8 log_init();
void log_quit();

KAPI void log_output(LogLevel level, const char *format, ...);

#define KFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__)
#define KERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__)

#if LOG_WARN_ENABLED == 1
#define KWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__)
#else
#define KWARNING(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
#define KINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__)
#else
#define KINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
#define KDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)
#else
#define KDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
#define KTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__)
#else
#define KWARNING(message, ...)
#endif

#ifdef KASSERT_ENABLED
#define debug_break() __builtin_trap()

KAPI void assert_fail(const char *expr, const char *message, const char *file, i32 line);

#define KASSERT(expr)                                   \
    {                                                   \
        if (expr)                                       \
        {                                               \
        }                                               \
        else                                            \
        {                                               \
            assert_fail(#expr, "", __FILE__, __LINE__); \
            debug_break();                              \
        }                                               \
    }

#define KASSERT_MSG(expr, msg)                           \
    {                                                    \
        if (expr)                                        \
        {                                                \
        }                                                \
        else                                             \
        {                                                \
            assert_fail(#expr, msg, __FILE__, __LINE__); \
            debug_break();                               \
        }                                                \
    }

#ifdef _DEBUG
#define KASSERT_DBG(expr)                               \
    {                                                   \
        if (expr)                                       \
        {                                               \
        }                                               \
        else                                            \
        {                                               \
            assert_fail(#expr, "", __FILE__, __LINE__); \
            debug_break();                              \
        }                                               \
    }
#else
#define KASSERT_DBG(expr)
#endif
#else
#define KASSERT(expr)
#define KASSERT_MSG(expr, msg)
#define KASSERT_DBG(expr)
#endif