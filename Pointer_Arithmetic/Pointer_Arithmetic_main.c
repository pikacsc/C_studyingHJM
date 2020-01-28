#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char *ptr = 0;  // try double*, long long *, char*, void*
	//int *ptr = 0;
    //double *ptr = 0;
    //long long *ptr = 0;
	//void *ptr = 0; // can't available pointer arithmetic

	//printf("%d", *ptr); //Error in this lecture

	printf("%p %lld\n", ptr, (long long)ptr);

	ptr++; // try -=, ++, --, -, +

	printf("%p %lld\n", ptr, (long long)ptr);

	//ptr = -ptr; // Not working
	//ptr = +ptr; // Not working

	/* Subtraction */
	 char arr[10];
	 char *ptr1 = &arr[3], *ptr2 = &arr[5];

	// ptr2 = ptr1 + ptr2; // Not working
     int i = ptr2 - ptr1;  // working
	printf("%p %p %d\n", ptr1, ptr2, i);
	return 0;
}