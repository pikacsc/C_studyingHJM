#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
	for(initialize; test; update)
		statement
	
	*/

	for (int i = 10; i > 0; i--)
		printf("%d ", i);

	for (int i = 0; i < 100; i += 8)
		printf("%d ", i);

	for (char c = 'A'; c <= 'Z'; c++)
		printf("%c ", c);

	for (int i = 0; i * i < 10; i++)
		printf("%d ", i);

	for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10)
		printf("%d ", x);


	int i, n;
	n = 2;
	for (i = 2; n < 10; )
	{
		n = n * i;
		printf("%d \n", n);
	}

	/*
	for(;;) // while(1)
		statement
	*/
	return 0;
}