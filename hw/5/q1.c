#include <stdio.h>

typedef unsigned float_bits;

void printbits(float_bits v) {
  int i; // for C89 compatability
  for(i = 31; i >= 0; i--) {
  	putchar('0' + ((v >> i) & 1));
  }
  printf("\n");
}

float_bits float_negate(float_bits x) {
	unsigned sign_bit = (x >> 31);
	unsigned exponent = (x >> 23) & 0xFF;
	unsigned fraction = x & 0x7FFFFF;

	if (sign_bit == 1) {
		sign_bit = 0;
	}
	else {
		sign_bit = 1;
	}

	if ((exponent == 0xFF) && (fraction != 0x00)) {
		return x;
	}

	return (sign_bit << 31 | exponent << 23 | fraction);

}

void main() {
	float_bits a = 0xFFFFFFFF;
	float_bits a_return;

	float_bits b = 0x0ACCDAAA;
	float_bits b_return;

	float_bits c = 0x00000000;
	float_bits c_return;

	float_bits d = 0xF00A000A;
	float_bits d_return;

	a_return = float_negate(a);
	b_return = float_negate(b);
	c_return = float_negate(c);
	d_return = float_negate(d);

	printf("A: %x ", a);
	printbits(a);
	printf("A negated: %x ", a_return);
	printbits(a_return);

	printf("B: %x ", b);
	printbits(b);
	printf("B negated: %x ", b_return);
	printbits(b_return);

	printf("C: %x ", c);
	printbits(c);
	printf("C negated: %x ", c_return);
	printbits(c_return);

	printf("D: %x ", d);
	printbits(d);
	printf("D negated: %x ", d_return);
	printbits(d_return);

	
}