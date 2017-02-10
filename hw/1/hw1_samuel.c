#include <stdio.h>

void main() {
	char x[256];
	char y[256];
	char count = 0;
	char input;


	/* this fills the x array up with every potential ascii character */
	for (int d = 0; d < 255; d++) {
		x[d] = count;
		++count;
	}

	/* this fills up the y array with 0s */
	for (int d = 0; d < 255; d++) {
		y[d] = 0;
	}

	//takes in characters, checks against first array, adds to count in second array
	printf("Please input chars.\n");
	input = getchar();

	while (input != EOF) {
		for (int d = 0; d < 255; d++) {
			if (input == x[d]) {
				++y[d];
			}
		}
		input = getchar();
	}

	for (int d = 0; d < 255; d++){
		printf("%c : %d\n", x[d], y[d]);
	}

}