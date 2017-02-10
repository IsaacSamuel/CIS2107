#include <stdio.h>

float square_root(float input) {
	float a;
	float b;
	float guess = 1;

	/*Iterates 1000 times, because that should be more than suffecient for most inputs.) */
	for (int i = 0; i<1000; i++) {
		guess = (guess -((guess*guess)-input)/(2*guess));
	}

	return guess;

}

void main() {
	float p[] = {1};
	float q[] = {5};
	float a[] = {1, 1, 1};
	float b[] = {5, 5, 5};
	float c[] = {1, 1, 1};
	float d[] = {-5, -5, -5};
	float distance = 0;

	for (int i = 0; i < 1; i++) {
		distance += ((p[i]-q[i])*(p[i]-q[i]));
	}
	printf(" %.3f\n", distance);

	distance = square_root(distance);

	printf("The distance between {1} and {5} is %.3f\n", distance);


	distance = 0;
	for (int i = 0; i < 3; i++) {
		distance += ((a[i]-b[i])*(a[i]-b[i]));
	}
	printf(" %.3f\n", distance);

	distance = square_root(distance);
	printf("The distance between {1, 1, 1} and {5. 5, 5} is %.3f\n", distance);


	distance = 0;
	for (int i = 0; i < 3; i++) {
		distance += ((c[i]-d[i])*(c[i]-d[i]));
	}
	printf(" %.3f\n", distance);

	distance = square_root(distance);
	printf("The distance between {1, 1, 1} and {-5. -5, -5} is %.3f\n", distance);



}