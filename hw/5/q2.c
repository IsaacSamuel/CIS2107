#include <stdio.h>

#include <stdlib.h>
 
typedef unsigned float_bits;

void printbits(float_bits v) {
  int i; // for C89 compatability
  for(i = 31; i >= 0; i--) {
  	putchar('0' + ((v >> i) & 1));
  }
  printf("\n");
}
 
union repr {
    float f;
    unsigned u;
};
 
 
unsigned f2u(float f)
{
    union repr r;
    r.f = f;
 
    return r.u;
}

float u2f(unsigned u) { 
    union repr r;
    r.u= u; 

    return r.f;  
}

float_bits myi2f(int i)
{
  unsigned sign; 
  unsigned exp; 
  unsigned frac; 
  int j = 1;
  int count = 0;

  if (i < 0) {
  	sign = 1;
  }
  else {
  	sign = 0;
  }

  /*gets exponent */
  while (i / j != 0) {
  	j = j * 2;
  	count++;
  } 

  if (count > 0 && count < 128) {
  	/* normalized number */
  	exp = (count+127-1);

  	printf("%u %x\n", exp, exp);
  	printbits(exp);


  	/*eliminates sign bit*/
  	i = i<<1;
  	while (i > 0) {
  		i = i << 1;
  	}
  	i=i<<1;
  	/*truncates fractional value */
  	frac = (unsigned) i >> 9;
  	printbits(frac);

  }
  else if (count >= 127) {
  	/*overflow*/
  	exp = 0xFF;
  	frac = 0;
  }
  else {
  	/*int is zero */
  	exp = 0;
  	frac = 0;
  }


  return ((sign << 31) | (exp << 23) | frac); 
}


int main()
{
    unsigned i;
    unsigned sysconv;
    float_bits our;
 
    for (i = 100; i<110 ; i++) {
        sysconv = f2u( (float) ((int) i) );
        our = myi2f((int) i);

        printf("Original int is %d\n", i);  
        printbits(i);
        printf("\nOur conversion is %f\n", u2f(our)) ; 
        printbits(our);

        printf("\nSys conversion in hex is %x and our conversion in hex is  %x\n", sysconv, our);
        if ( sysconv != our ) {
            printf(" Mismatch:\n original int %08X --> sys %08X , ours %08X\n", i, sysconv, our);
            exit(1);
        }

    }
 
    printf("Success Test\n");
 
    return 0;
}

