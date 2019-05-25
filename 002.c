#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SQRT5 2.236067977499
double PHI = 0.5 * (1.0 + SQRT5);
double KSI = 0.5 * (1.0 - SQRT5);

double
fib(int n) {
	double f, w;
	f = round((pow(PHI, n + 2) - pow(KSI, n + 2)) / SQRT5);
	modf(f, &w);
	return w;
}

int
sum(int n) {
	int i = 0, f = 0, s = 0;
	while(f < n) {
		if(f % 2 == 0)
			s += f;
		f = (int)fib(i);
		i += 1;
	}
	return s;
}

int
main(int argc, char *argv[]) {
	int n = (int)atof(argv[1]);
	printf("%d\n", sum(n));
	return 0;
}
