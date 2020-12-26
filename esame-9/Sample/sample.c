#define _CRT_SECURE_NO_WARNINGS
#include "sample.h"
#include <string.h>

extern int sample_scrivi(FILE* f, const struct sample* s) {

	size_t end;
	char *zero = 0;

	end = fwrite(&s->idSample, sizeof(int), 1, f);
	if (end != 1) {
		return 0;
	}
	end = fwrite(&s->nomeCategoria, sizeof(char), strlen(s->nomeCategoria), f);
	if (end != strlen(s->nomeCategoria)) {
		return 0;
	}
	end = fwrite(&zero, sizeof(char), 1, f);
	if (end != 1) {
		return 0;
	}
	end = fwrite(&s->accuracy, sizeof(double), 1, f);
	if (end != 1) {
		return 0;
	}

	return 1;
}

extern int sample_leggi(FILE* f, struct sample* s) {


	int i = -1;
	size_t end;

	end = fread(&s->idSample, sizeof(int), 1, f);
	if (end != 1) {
		return 0;
	}

	char var;
	do {
		end = fread(&var, sizeof(char), 1, f);
		i++;
		if (end != 1 || i > 20) {
			return 0;
		}

		s->nomeCategoria[i] = var;

	} while (s->nomeCategoria[i] != 0);

	end = fread(&s->accuracy, sizeof(double), 1, f);
	if (end != 1) {
		return 0;
	}

	return 1;
}
