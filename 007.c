#include <stdio.h>
#include <stdlib.h>

/* prints prime < n, not really what I wanted */
void
sieve_wheel(int *ps, int n) {
	for (int p = 2; p < n; p++) {
		if (ps[p] == 0) {
			ps[p] = 1;
		}
		int c = 2;
		int mul = p * c;
		while (mul < n) {
			ps[mul] = -1;
			c++;
			mul = p * c;
		}
	}
	for (int i = n - 1; i > 0; i--) {
		if(ps[i] > 0) {
			printf("%d\n", i);
			break;
		}
	}
}

int
sieve_until(int n) {
	int i = 1, p = 1;
	while(i <= n) {
		p += 1;
		int flag = 1;
		for(int count = 2; count <= p - 1; count++) {
			if(p % count == 0) {
				flag = 0;
				break;
			}  
		}
		if(flag == 1) {
			i += 1;
		}
	}
	return p;
}

int
main(int argc, char *argv[]) {
	int n = atoi(argv[1]), p;
	p = sieve_until(n);
	printf("%d\n",p);
	return 0;
}
