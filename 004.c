#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool
is_palindrome(int num) {
	int tmp = num, rev = 0;

	while(tmp > 0) {
		int dig = tmp % 10;
		rev = rev * 10 + dig;
		tmp = tmp / 10;
	}

	return (num == rev) ? true : false;
}

int
main(int argc, char *argv[]) {
	int d = atoi(argv[1]), m = pow(10, d), a = 0;

	for(int i = m; i > 0; i--) {
		for(int j = m; j > 0; j--) {
			int p = i * j;
			if(p > a && is_palindrome(p)) {
				a = p;
			}
		}
	}

	printf("%d\n", a);
	return 0;
}
