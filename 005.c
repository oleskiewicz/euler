#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lib.h"

long int
vreduce(long int (*f)(long int, long int), int n, va_list ap) {
	long int y, a = va_arg(ap, long int);
	if(n == 2) {
		long int b = va_arg(ap, int);
		y = f(a, b);
	} else if(n > 2) {
		y = f(a, vreduce(f, n - 1, ap));
	} else {
		printf("error: n must be >= 1, got %d\n", n);
		exit(1);
	}
	return y;
}

long int
reduce(long int (*f)(long int, long int), int n, ...) {
	va_list ap;
	va_start(ap, n);
	long int y = vreduce(f, n, ap);
	va_end(ap);
	return y;
}

int
main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	printf("%ld\n", reduce(lcm, n,
			       1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			       15, 16, 17, 18, 19, 20));
	return 0;
}
