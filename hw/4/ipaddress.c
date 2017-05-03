#include <stdio.h>

char check_ip_class(unsigned input) {
	if ((input>>31)==0) {
		return 'A';
	}
	else if ((input>>30<<31>>31)==0) {
		return 'B';
	}
	else if ((input>>29<<31>>31)==0) {
		return 'C';
	}
	else if ((input>>28<<31>>31)==0) {
		return 'D';
	}
	else if ((input>>27<<31>>31)==0) {
		return 'E';
	}
}



void main() {
	char class;
	unsigned input;

	printf("Enter an ip as hex:\n");
	scanf("%x", &input);

	class = check_ip_class(input);

	printf("The class of the IP 0x%x is %c\n", input, class);

}