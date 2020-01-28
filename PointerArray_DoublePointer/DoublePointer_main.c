#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void rev_str(char* str)
{
	str = "Kept you waiting huh?";
}

void rev_str_2(char** str) // Using Double Pointer
{
	*str = "Kept you waiting huh?";
}

int main(void)
{
	int a = 0;
	int* ptr = NULL;
	int** pptr = NULL;
	int*** ppptr = NULL;

	a = 7;
	ptr = &a;
	pptr = &ptr;
	ppptr = &pptr;

	printf("name \t value \t\t address\n");
	printf("a \t %d \t\t 0x%p\n", a, &a);
	printf("ptr \t 0x%p \t 0x%p\n", ptr, &ptr);
	printf("pptr \t 0x%p \t 0x%p\n", pptr, &pptr);
	printf("ppptr \t 0x%p \t 0x%p\n", ppptr, &ppptr);
	printf("\n");

	char* p_str = NULL;
	
	rev_str(p_str);
	printf("rev_str : %s\n\n", p_str);

	rev_str_2(&p_str);
	printf("rev_str 2 :%s\n\n", p_str);


	return 0;
}
