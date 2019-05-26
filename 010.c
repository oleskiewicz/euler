#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

long int
sum_primes_below(int n) {
	long int s = 0;
	int *ps = calloc(n, sizeof(int));
	sieve_erastosthenes(ps, n);
	for(int i = 2; i < n; i++) {
		if(ps[i] == 0) {
			s += i;
		}
	}
	free(ps);
	return s;
}

int
main(int argc, char *argv[]) {
	int n = (int)atof(argv[1]);
	long int s = sum_primes_below(n);
	printf("%ld\n", s);
	return 0;
}
