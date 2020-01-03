#include "Parser.h"

int readStream(FILE *fp, void *buffer, size_t size) {
	const uint8_t chunksToReadNo = 1;
	int chunksReadNo;

	memset(buffer, 0, size);
	chunksReadNo = fread(buffer, size, chunksToReadNo, fp);
	if (!chunksReadNo) {
		if (ferror(fp)) {
			if (isDebugLevelAbove(ERROR))
				printError("**** Error reading file: %s ****\n", strerror(errno));
			return EIO;
		} else if (feof(fp)) {
			if (isDebugLevelAbove(TRACE))
				printError("EOF found\n");
			return EOF;
		} else {
			if (isDebugLevelAbove(ERROR))
				printError("**** Unknown IO error *****\n");
			return -1;
		}
	}

	if (isDebugLevelAbove(TRACE))
		printError("Successfully read the file\n");
	return 0;
}

int saveStream(FILE *fp, void *buffer, size_t size) {
	const uint8_t chunksToSaveNo = 1;
	int chunksWrittenNo;

	chunksWrittenNo = fwrite(buffer, size, chunksToSaveNo, fp);
	if (!chunksWrittenNo) {
		if (isDebugLevelAbove(ERROR))
			printError("**** Cannot write to the file *****\n");
		return EIO;
	}

	if (isDebugLevelAbove(TRACE))
		printError("Successfully wrote to the file\n");
	return 0;
}

int readMemory(const char *fileName, void *buffer, size_t size) {
	int retval = 0;
    FILE *fp = fopen(fileName, "rb");
	if (isDebugLevelAbove(TRACE))
		printError("Opening file name (file_name) = %s\n", fileName);

	if (fp == NULL) {
		if (isDebugLevelAbove(ERROR))
			printError("**** Error while opening file: %s ****\n", strerror(errno));
		return EIO; 
	}

	fseek(fp, 0, SEEK_SET);

	retval = readStream(fp, buffer, size);

	fclose(fp);
	return retval;
}

int saveMemory(const char *fileName, void *buffer, size_t size) {
	int retval = 0;
	FILE *fp = fopen(fileName, "wb");
	if (isDebugLevelAbove(TRACE))
		printError("Opening file name (file_name) = %s\n", fileName);

	if (fp == NULL) {
		if (isDebugLevelAbove(ERROR))
			printError("**** Error while opening file: %s ****\n", strerror(errno));
		return EIO;
	}

	fseek(fp, 0, SEEK_SET);

	retval = saveStream(fp, buffer, size);

	fclose(fp);
	return retval;
}


