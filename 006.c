#include <stdio.h>
#include <stdlib.h>

long int
diff_sqsum_sumsq(int n) {
	long int sqsum = 0, sumsq = 0;
	for(int i = 1; i <= n; i++) {
		sqsum += i;
		sumsq += i*i;
	}
	sqsum = sqsum * sqsum;
	return sqsum - sumsq;
}

int
main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	printf("%ld\n", diff_sqsum_sumsq(n));
	return 0;
}
