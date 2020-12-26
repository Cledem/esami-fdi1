#include <string.h>

extern unsigned int conta_occorrenze(const char* testo, const char* stringa) {
	
	if (testo == NULL || stringa == NULL || strlen(testo) == 0 || strlen(stringa) == 0) {
		return 0;
	}

	char *val = testo;
	unsigned int ris = 0;

	while (val != NULL) {
		val = strstr(val, stringa);
		if (val != NULL) {
			ris++;
			val++;
		}
		if (ris == 9999999) {
			return 0;
		}
	}

	return ris;
}
