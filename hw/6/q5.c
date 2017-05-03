#include <stdio.h>

int decode(int x, int n) {
	int result = -1;
	for (int mask =1; mask != 0; mask = mask << n) {
		result ^= mask & x;
	}
	return result;
}

void main(){
	int x = 7;
	int n = 5;

	int b = decode(x, n);

	printf("%d\n", b);
	
}