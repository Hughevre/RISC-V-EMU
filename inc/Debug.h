#ifndef DEBUG_H
#define DEBUG_H

#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

typedef enum debug_verbose_level_t {
    NONE        = -3,
    CRITICAL    = -2,
    ERROR       = -1,
    WARNING     = 0,
    INFORMATION = 1,
    TRACE       = 2,
    DEBUG       = 3
}DebugVerboseLevel;

static int8_t RF			= 0;
static int8_t debugLevel[7]	= { -3,-2,-1,0,1,2,3 };

void	setDebugLevel(DebugVerboseLevel);
int		printError(const char*, ...);
bool	isDebugLevelAbove(DebugVerboseLevel);

#endif 