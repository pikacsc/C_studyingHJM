#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void swap(int a, int b) // call by value;
{
	printf("in swap func :  before swap %p %p\n", &a, &b);
	// swap
	int temp = a;
	a = b;
	b = temp;
	printf("in swap func : after swap %p %p\n", &a, &b);
	printf("in swap func : %d %d\n", a, b);
}

void swap_2(int *a, int *b) // call by pointer
{
	printf("in swap func :  before swap %p %p\n", &a, &b);
	// swap
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("in swap func : after swap %p %p\n", &a, &b);
	printf("in swap func : %d %d\n", *a, *b);
}



int main(void)
{
	int a = 123;
	int b = 456;

	swap_2(&a, &b);
	printf("after swap in main : %d %d\n", a, b);


	return 0;
}