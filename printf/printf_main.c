#include <stdio.h>

int main(void)
{
	int x, y, z;

	x = 1;
	y = 2;
	z = x + y;

	printf("\"The truth is ... \nI am Ironman.\"\n");
	// \ escape sequence
	// \n, next line
	// \",  "

	printf("x = %i \n", x);
	printf("y = %i \n", y);
	printf("x + y = ? \n");
	printf("The answer is %i ", z);



	return 0;
}