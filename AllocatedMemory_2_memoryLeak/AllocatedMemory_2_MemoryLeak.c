#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Dummy Output\n");

	{
		int n = 100000000; // ! warning x64 recommended 
		int* ptr = (int*)malloc(n * sizeof(int)); // 400,000,000 byte == 381MB

		if (!ptr)//if(ptr == NULL)
		{
			printf("Malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i)
			ptr[i] = i + 1;

		//prevent Memory Leak
		free(ptr);
		ptr = NULL;
	}

	// what happens?

	printf("Dummy Output\n");

	return 0;
}