#define _CRT_SECURE_NO_WARNINGS
#include "lettura.h"
#include <stdlib.h>

extern char* fgets_malloc(FILE* f) {

	int c = fgetc(f);
	if (c == EOF) {
		return NULL;
	}

	unsigned int len = 1;
	char* str = malloc(1);
	int i = 0;

	do {

		if (c != '\n') {
			len++;
			str = realloc(str, len);
			str[i] = c;
			i++;
		}

	} while ((c = fgetc(f)) != EOF);
	str[i] = 0;

	return str;
}
