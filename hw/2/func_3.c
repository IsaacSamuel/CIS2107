#include <stdio.h>

void main() {
	int SIZE = 2000;
	int num[SIZE];
	int count=2;

	/*populates array */
	for (int i = 0; i < SIZE; i++) {
		num[i] = i;
	}


	num[0] = 0;
	num[1] = 0;
	while (count < SIZE/2) {
		for (int i = 1; i < SIZE; i++) {
			if ((num[i] != count) && (num[i]%count==0)) {
				num[i] = 0;
			}
		}
		count++;
	}


	for (int i = 0; i < SIZE; i++) {
		if (num[i] != 0) {
			printf("%d ", num[i]);
		}
	}

	printf("\n They are all prime numbers! \n");


}