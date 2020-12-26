#include "matrix.h"
#define true 1
#define false 0

extern int mat_isupper(const struct matrix* matr) {

	if (matr->M != matr->N) {
		return false;
	}

	for (size_t i = 0, j = 0; i < matr->M * matr->N; i += matr->M, j++) {

		for (size_t j1 = 0, i1 = i; j1 < j; j1++) {
			if (matr->data[i1] != 0) {
				return false;
			}
			i1++;
		}

	}

	return true;
}
