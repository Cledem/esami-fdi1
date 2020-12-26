extern double semifattoriale(char n) {

	if (n < 0) {
		return -1;
	}

	double ris = 1;
	while (n > 1) {
		ris *= n;
		n -= 2;
	}

	return ris;
}
