long int
gcd(long int a, long int b) {
	while(b) {
		a %= b;
		b ^= a;
		a ^= b;
		b ^= a;
	}
	return a;
}

long int
lcm(long int a, long int b) {
	return a * b / gcd(a, b);
}
