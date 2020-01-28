#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


/*
	10
	10/2 = 5, remainder = 0
	5/2 = 2, remainder = 1
	2/2 = 1, remainder = 0
	1/2 = 0, remainder = 1

*/


void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main(void)
{
	long num = 19;
	print_binary(num);
	//print_binary_loop(num);
	return 0;
}



// My Solution
void print_binary(unsigned long n)
{
	if (n >= 1)
	{
		if (n % 2 == 0)
		{
			print_binary(n/2);
			printf("0");
		}
		else
		{
			print_binary(n/2);
			printf("1");
		}
	}
}

// reverse print
void print_binary_loop(unsigned long n)
{
	while (n >= 1)
	{
		if(n%2 == 0)
			printf("0\n");
		else
			printf("1\n");
		n /= 2;
	}
}



// lecture
void print_binary_2(unsigned long n)
{
	int remainder = n % 2;

	if (n >= 2)
		print_binary_2(n / 2);
	printf("%d", remainder);

	return;
}

// reverse print
void print_binary_loop_2(unsigned long n)
{
	while (1)
	{
		int quotient = n / 2;
		int remainder = n % 2;

		printf("%d", remainder); // remainder is 0 or 1

		n = quotient;

		if (n == 0) break;
	}
	printf("\n");
}
