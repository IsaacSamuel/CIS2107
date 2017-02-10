#include <stdio.h>

/* Takes in an int and prints out the the sum of the first and last numbers of the int
Ex: '245' would be 2+5=7
*/ 

void main() {
	int input;
	int divisor = 10;
	int lower;
	int higher;
	int sum;

	scanf("%d", &input);

	lower = input%divisor;

	while (input/divisor > 0) {
		divisor= divisor * 10;
	}

	higher = input/(divisor/10);

	sum = higher + lower;

	printf("lower: %d \nhigher: %d\nsum: %d\n", lower, higher, sum);

}