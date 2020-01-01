#ifndef PARSER_H
#define PARSER_H

#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "Debug.h"

int parse_file(const char*, void*, size_t);

#endif