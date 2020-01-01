#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdint.h>

enum DebugVerboseLevel {
    NONE        = -3,
    CRITICAL    = -2,
    ERROR       = -1,
    WARNING     = 0,
    INFORMATION = 1,
    TRACE       = 2,
    DEBUG       = 3
};

extern int8_t g_RF;
extern int8_t g_debug_level[7];
extern FILE *g_debug_file_handle;

#endif 