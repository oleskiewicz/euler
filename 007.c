#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int
main(int argc, char *argv[]) {
	int n = atoi(argv[1]), p;
	p = sieve_until(n);
	printf("%d\n",p);
	return 0;
}
