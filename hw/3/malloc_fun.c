#include <stdlib.h>
#include <stdio.h>

void main() {
	char *cp;
	int count = 0;

	cp = malloc(26);

	for(char i = 'a'; i <= 'z'; i++) {
		cp[count] = i;
		count++;
	}

	count = 0;

	while(count != 26) {
		printf("%p : %c\n", cp+count, cp[count]);
		count++;
	}

	count = 0;
	free(cp);
	malloc(10);

	for(char i = '0'; i <= '9'; i++) {
		cp[count] = i;
		count++;
	}

	count = 0;

	while(count != 10) {
		printf("%p : %c\n", cp+count, cp[count]);
		count++;
	}

}