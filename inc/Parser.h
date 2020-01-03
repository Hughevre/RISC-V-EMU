#ifndef PARSER_H
#define PARSER_H

#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "Debug.h"

int readMemory(const char*, void*, size_t);
int saveMemory(const char*, void*, size_t);

#endif