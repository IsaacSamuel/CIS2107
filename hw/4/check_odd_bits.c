#include <stdio.h>
#include <limits.h>

int any_odd_one(unsigned b) {
	int a = 0;

	a = a + ((b<<30)>>31);
	a = a + ((b<<28)>>31);
	a = a + ((b<<26)>>31);
	a = a + ((b<<24)>>31);
	a = a + ((b<<22)>>31);
	a = a + ((b<<20)>>31);
	a = a + ((b<<18)>>31);
	a = a + ((b<<16)>>31);
	a = a + ((b<<14)>>31);
	a = a + ((b<<12)>>31);
	a = a + ((b<<10)>>31);
	a = a + ((b<<8)>>31);
	a = a + ((b<<6)>>31);
	a = a + ((b<<4)>>31);
	a = a + ((b<<2)>>31);
	a = a + (b>>31);

	return a;


}

void main() {
	int a;
	int b;
	
	printf("Enter an int:\n");
	scanf("%d", &b);

	a = any_odd_one((unsigned) b);

	printf("There are %d odd ones.\n", a);

}