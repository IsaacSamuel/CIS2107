long exchange (long *xp, long y) {
	long x = *xp;
	*xp = y;
	return x;
}

void main() {
	long x = 1;
	long y = 2;

	x = exchange(*x, y);

	printf("%x", x);
}