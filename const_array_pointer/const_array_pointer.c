#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	// type qualifiers : const, volatille, ...

	const double PI = 3.14159;
	//PI = 2.14159; //no allow to change value

	const int arr[5] = { 1, 2, 3, 4, 5 };
	//arr[1] = 123; //no allow to change element

	const double arr2[3] = { 1.0, 2.0, 3.0 };
	//arr2[0] = 100.0; //no allow to change element

	const double* pd = arr2;
	//*pd = 3.0; // pd[0] = 3.0; arr2[0] = 3.0;
	//pd[2] = 1024.0; // arr2[2] = 1024.0;

	printf("%f %f", pd[1], arr2[1]);

	pd++; // allowed

	printf("\n after pd++ %f %f", pd[1], arr2[1]);


	const double* const pd2 = arr2; 

	//pd2++; // not allowed


	return 0;
}