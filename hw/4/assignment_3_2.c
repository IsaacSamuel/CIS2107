#include <stdio.h>

void printbits(int v) {
  int i; // for C89 compatability
  for(i = 7; i >= 0; i--) {
  	putchar('0' + ((v >> i) & 1));
  }
  printf("\n");
}

int make_bit_with_k(int k) {
	int a = -1;
	return 	a << k;
}

int make_bit_with_j(int k, int j) {
	int a = 0;
	int b = -1;

	b = b ^ (b << k);
	/*
	a = a + b;
	a = a << j;
	*/

	return b << j;
}


void main() {
	int k = 2;
	int j = 3;
	int answer;
	int answer2;


	printf("k = 2: ");
	printbits(k);
	printf("j = 3: ");
	printbits(j);

	answer = make_bit_with_k(k);
	answer2 = make_bit_with_j(k, j);

	printf("First formula with k = 2: ");
	printbits(answer);
	printf("First formula with k = 2, j = 3: ");
	printbits(answer2);

}