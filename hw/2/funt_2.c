#include <stdio.h>

/*Recieves a string and converts it to a double floating point value. */


/* outputs the size a char array */
int strlen(char s[]) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

double convertFloat(char s[]) {
	int size = strlen(s);
	int left_of_decimal=0;
	int right_of_decimal = 0;
	float to_float;
	int i = 0;
	int count;
	float power;
	unsigned int converter;

	/*boolean*/
	int is_left_of_zero = 1;
	int negative =0;

	/*finds meta information about string*/
	for (i = 0; i < size; i++) {
		if (s[i] == '.') {
			is_left_of_zero = 0;
		}
		else {
			if(is_left_of_zero) {
				left_of_decimal++;
			}
			else {
				right_of_decimal++;
			}
		}
	}


	/*turns string into float */
	is_left_of_zero = 1;
	i = 0;
	if (s[0] == '-') {
		negative = 1;
		i = 1;
		left_of_decimal--;
	}
	for (i; i < size; i++) {
		if (s[i]=='.') {
			is_left_of_zero = 0;
		}
		else if (is_left_of_zero) {
			power = 1;
			converter = s[i]-48;
			for (int j = 0; j < left_of_decimal-1; j++) {
				power = power*10;
			}
			converter = converter * power;
			to_float += converter;
			left_of_decimal--;
		} 
		else {
			power = .1;
			converter = s[i]-48;
			for (int j = 0; j < count; j++) {
				power = power*.1;
			}
			to_float += converter * power;
			right_of_decimal--;
			count++;
		}
	}


	return (negative ? -to_float : to_float);
}

void main() {
	char a[6] = "12345";
	char b[6] = "12.34";
	char c[6] = ".1234";
	char d[11] = "12345.6789";
	char e[7] = "-12.34";
	float x;

	x = convertFloat(a);
	printf("%f \n", x);

	x = convertFloat(b);
	printf("%f \n", x);

	x = convertFloat(c);
	printf("%f \n", x);

	/*Some impreciseness due to nature of floats*/
	x = convertFloat(d);
	printf("%f \n", x);

	x = convertFloat(e);
	printf("%f \n", x);

}