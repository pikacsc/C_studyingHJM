#define _CRT_SECURE_NO_WARNINGS //only for visual studio
#include <stdio.h>



/*
double average(double *arr, int arrSize);
double average(double *, int arrSize);
double average(double arr[], int arrSize);
double average(double [], int arrSize);
*/

double average(double arr[], int arrSize);
//double average(double arr[3], int arrSize);  // meaningless, double arr[3] will be used like a pointer (double *arr)


int main(void)
{
	double arr1[5] = { 10, 13, 12, 7, 8 };
	double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
	//double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different

	printf("Address = %p\n", arr1);
	printf("Size = %zd\n", sizeof(arr1));
	printf("Address = %p\n", arr2);
	printf("Size = %zd\n", sizeof(arr2));

	printf("Avg = %f\n", average(arr1, 5));
	printf("Avg = %f\n", average(arr2, 3));

	return 0;
}


double average(double arr[], int arrSize)
{
	printf("Size = %zd in function average\n", sizeof(arr));

	double avg = 0.0;
	for (int i = 0; i < arrSize; ++i)
	{
		avg += arr[i];
	}
	avg /= (double)arrSize;

	return avg;
}
