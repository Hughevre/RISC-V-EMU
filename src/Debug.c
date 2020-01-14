#include "../inc/Debug.h"

int8_t RF = 0;

void setDebugLevel(DebugVerboseLevel level) {
	RF = level;
	remove(FILE_DEBUG);
}

int printError(const char *format, ...) {
	const char *fileName = FILE_DEBUG;
	va_list argsList;
	FILE *fileHandle = fopen(fileName, "a");

	if (fileHandle == NULL)
		return EIO;

	va_start(argsList, format);
	vfprintf(fileHandle, format, argsList);
	fclose(fileHandle);
	va_end(argsList);

	return 0;
}

bool isDebugLevelAbove(DebugVerboseLevel level) {
	return (RF <= level) ? false : true;
}