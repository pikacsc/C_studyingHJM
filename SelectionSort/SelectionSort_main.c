#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Selection Sort Algorithm

	https://www.geeksforgeeks.org/selection-sort/

	64 25 12 22 11 (min_idx = 0)
	   65          (min_idx = 0)
	   25          (min_idx = 1)
	      25       (min_idx = 1)
		  12       (min_idx = 2)
		     12    (min_idx = 2)
			    12 (min_idx = 2)
				11 (min_idx = 4)
	11 25 12 22 64 (swap arr[0] and arr[4])



*/

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++) //Note n - 1
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++) //Note i + 1
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}

		// Swap the found minimum element with the first element
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
}


void MySelectionSort(int arr[])
{
	int min_idx = 0;
	for (int i = 0; i < 5; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}


}

void PrintArr(int arr[])
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{

	int arr[5] = { 64, 25, 12, 22, 11 };

	PrintArr(arr);

	printf("after SelectioSort\n");
	
	MySelectionSort(arr);
	//selectionSort(arr, 5);
	PrintArr(arr);

	return 0;
}