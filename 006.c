#include <stdio.h>
#include <stdlib.h>

long long int
diff_sqsum_sumsq1(int n) {
	long long int sqsum = 0, sumsq = 0;
	for(int i = 1; i <= n; i++) {
		sqsum += i;
		sumsq += i*i;
	}
	sqsum = sqsum * sqsum;
	return sqsum - sumsq;
}

long long int
diff_sqsum_sumsq2(int n) {
	long long int d = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			d += 2*i*j;
		}
	}
	return d;
}

int
main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	printf("%lld\n", diff_sqsum_sumsq1(n));
	return 0;
}
