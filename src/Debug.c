#include "../inc/Debug.h"

int8_t RF 		= 0;
int8_t debugLevel[7] 	= {-3,-2,-1,0,1,2,3};

void setDebugLevel(DebugVerboseLevel level) {
	RF = level;
}

int printError(const char *format, ...) {
	const char *fileName = "debug.txt";
	va_list argsList;
	FILE *fileHandle = fopen(fileName, "wb");

	if (fileHandle == NULL)
		return EIO;

	va_start(argsList, format);
	vfprintf(fileHandle, format, argsList);
	fclose(fileHandle);
	va_end(argsList);

	return 0;
}

bool isDebugLevelAbove(DebugVerboseLevel level) {
	if (debugLevel[RF] <= level)
		return false;
	return true;
}
