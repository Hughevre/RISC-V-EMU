#include "Parser.h"

int save_stream(FILE *fp, void *buffer, size_t size)
{
	const uint8_t blks_to_save_no = 1;
	int read_blks_no;

	memset(buffer, 0, sizeof(buffer));
	read_blks_no = fread(buffer, size, blks_to_save_no, fp);
	if (!read_blks_no) {
		if (ferror(fp)) {
			if (g_debug_level[g_RF] > ERROR)
				fprintf(g_debug_file_handle, "**** Error reading file: %s ****\n", strerror(errno));
			return EIO;
		} else if (feof(fp)) {
			if (g_debug_level[g_RF] > TRACE)
				fprintf(g_debug_file_handle, "EOF found\n");
			return EOF;
		} else {
			if (g_debug_level[g_RF] > TRACE)
				fprintf(g_debug_file_handle, "**** Unknown error *****\n");
			return -1;
		}
	}

	if (g_debug_level[g_RF] > TRACE)
		fprintf(g_debug_file_handle, "Successfully read the file\n");
	return 0;
}

int parse_file(const char *file_name, void *buffer, size_t size)
{
	int ret = 0;
    FILE *fp = fopen(file_name, "rb");
    if (g_debug_level[g_RF] > TRACE)
        fprintf(g_debug_file_handle, "Opening file name (file_name) = %s\n", file_name);

	if (fp == NULL) {
		if (g_debug_level[g_RF] > ERROR)
			fprintf(g_debug_file_handle, "**** Error while opening file: %s ****\n", strerror(errno));
		return EIO; 
	}

	fseek(fp, 0, SEEK_SET);

	ret = save_stream(fp, buffer, size);

	fclose(fp);

	return ret;
}


