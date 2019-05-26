#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib.h"

#define LIM 50

bool
is_pythagorean_triplet(int a, int b, int c) {
	return a*a + b*b == c*c;
}

int
prod_of_triplets_of_sum(int s) {
	for(int k = 1; k <= LIM; k++) {
		for(int m = 1; m <= LIM; m++) {
			for(int n = 1; n <= LIM; n++) {
				if(m > n && gcd(m, n) == 1) {
					if(!(m % 2 == 1 && n % 2 == 1)) {
						int a = k * (m*m - n*n), b = k * (2*m*n), c = k*(m*m+n*n);
						if(a + b + c == s)
							return a*b*c;
					}
				}
			}
		}
	}
	return 0;
}

int
main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	printf("%d\n", prod_of_triplets_of_sum(n));
	return 0;
}
