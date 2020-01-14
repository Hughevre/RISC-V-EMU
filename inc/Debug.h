#ifndef DEBUG_H
#define DEBUG_H

#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

#define FILE_DEBUG "debug.txt"

typedef enum debug_verbose_level_t {
    NONE        = -3,
    CRITICAL    = -2,
    ERROR       = -1,
    WARNING     = 0,
    INFORMATION = 1,
    TRACE       = 2,
    DEBUG       = 3
}DebugVerboseLevel;

extern int8_t RF;

void	setDebugLevel(DebugVerboseLevel);
int	    printError(const char*, ...);
bool	isDebugLevelAbove(DebugVerboseLevel);

#endif