#include <stdio.h>
#include <stdlib.h>

int
s(int n) {
	return n * (n + 1) / 2;
}

int
ss(int n, int k) {
	int p = (n - 1) / k;
	return k * s(p);
}

int
main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	int sum = ss(n, 3) + ss(n, 5) - ss(n, 15);
	printf("%d\n", sum);
	return 0;
}
