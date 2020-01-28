#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// mistakes

int main(void)
{

	//int a;// uninitialized variable
	//printf("%p\n", &a); 
	//printf("%d\n", a); // garbage value
	


	//int *ptr; // uninitialized pointer
	//printf("%p\n", ptr);
	//printf("%d\n", *ptr);



	//int* ptr = 1234; // you shouldn't intialize pointer variable address directly(hard coding with pointer variable)
	//printf("%p\n", ptr);
	//printf("%d\n", *ptr);




	//int* safer_ptr; // uninitialized pointer
	//int a;
	////safer_ptr = &a; // assign address on compile time, however in many situation, pointer variables assigned on runtime.

	//scanf("%d", &a);
	//
	//if(a %2 == 0)
	//	safer_ptr = &a; // assign address on runtime, however compiler will detect unintialized pointer and cause error


	int* safer_ptr = NULL; // To assign address on runtime, initialize NULL(0), recommended
	int a;

	scanf("%d", &a);

	if (a % 2 == 0)
		safer_ptr = &a;



	if (safer_ptr != NULL) 
		printf("%p\n", safer_ptr);

	if (safer_ptr != NULL)
		printf("%d\n", *safer_ptr);


	return 0;
}