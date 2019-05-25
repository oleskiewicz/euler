#include <stdio.h>

unsigned long int
max_factor(unsigned long int n) {
	unsigned long int m = 2;

	while(n > m) {
		if(n % m == 0) {
			n = n / m;
			m = 2;
		} else {
			m += 1;
		}
	}
	return m;
}

int
main(int argc, char *argv[]) {
	unsigned long int n;
	sscanf(argv[1], "%lu", &n);
	printf("%lu\n", max_factor(n));
	return 0;
}
