#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy
#include "constants.h"

int main(void)
{
	double area_circle = PI * 2.f * 2.f;


	/*
		Qualifed types
		const, volatile, restrict, _Atomic
	*/

	/*
		const
	*/

	// C99 ideompotent
	const const const int n = 6; // const int n = 6;

	typedef const int zip;
	const zip q = 8; //const const int zip

	//const int i; // NOT initialized!
	//i = 12; //Error
	//printf("%d\n", i); // Error

	const int j = 123;
	const int arr[] = { 1, 2, 3 };

	float f1 = 3.14f, f2 = 1.2f;

	const float* pf1 = &f1; // stuck value
	//*pf1 = 5.0f; //Error
	pf1 = &f2; // Allowd

	float* const pf2 = &f1; // stuck address

	*pf2 = 6.0f; // Allowd
	//pf2 = &f2; // Error

	const float* const pf3 = &f1;
	//*pf3 = 7.f; // Error
	//pf3 = &pf2; // Error

	/*
		Global constants
	*/

	/*
		volatile
		- Ask to compiler, Do not optimize, block cacheing(store into cache memory, to use later)
		- (ex: hardward clock)
	*/

	volatile int vi = 1; // volatile location
	volatile int* pvi = &vi; // points to a volatile location

	int i1 = vi;

	// ...

	int i2 = vi;

	/*
		restrict( __restrict in VS)
		- sole initial means of accessing a data object
		- compiler can't check this restriction
	*/

	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* par = ar;

	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar)exit(1);

	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8;


	restar[0] += 3;
	restar[0] += 5;
	//restar[0] += 8; // Equalivalent

	free(restar);

	return 0;
}