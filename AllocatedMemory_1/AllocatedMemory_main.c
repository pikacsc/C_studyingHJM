#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()

int main(void)
{
	float x;
	char str[] = "Dancing with a start";

	int arr[100];

	/*
		malloc() returns a void type pointer.
		void* : generic pointer
		
		free() deallocates the memory
	*/

	double* ptr = NULL;

	ptr = (double*)malloc(30 * sizeof(double));

	if (ptr == NULL)
	{
		puts("Memory allocation failed.");

		/*
			exit(EXIT_FAILURE) is similar to return 1 IN main().
			exit(EXIT_SUCCESS) is similar to return 0 IN main().
		*/

		exit(EXIT_FAILURE);
	}
	
	printf("Before free %p\n", ptr);

	free(ptr); // no action occurs when ptr is NULL

	printf("After free %p\n", ptr); // even after free, still old address remaind

	ptr = NULL; // optional


	/* Dynamically  Allocated Array */
	int n = 5;
	//printf("Dynamical Allocated Array\n");
	//printf("input the length of int array : ");
	//scanf_s("%d ", &n);
	//if (n <= 0)
	//	n = 5; //default

	ptr = (double*)malloc(n * sizeof(double));

	if (ptr != NULL) // if(!ptr)
	{
		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);
		printf("\n");

		for (int i = 0; i < n; ++i)
			* (ptr + i) = (double)i;

		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);
		printf("\n");
	}

	free(ptr);
	ptr = NULL;

	/*
		Comparision to VLA

		VLA
		- not supported by VS compilers
		- automatic duration, cannot be resized
		- limited by stack size (when compiler places VLA in stack segment)
	*/

	return 0;
}