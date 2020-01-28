#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Variable scopes (visibility)
	- block, function, function prototype, file.
*/

int g_i = 123;	// global variable - file area
int g_j;		//global variable - BSS, auto initialize with 0

void func1()
{
	g_i++; 
}

void func2()
{
	g_i += 2;

	// local = 456; //error
}

int main()
{
	int local = 1234;

	func1();
	func2();

	printf("%d\n", g_i);
	printf("%d\n", g_j);
	printf("%d\n", local);


	return 0;
}