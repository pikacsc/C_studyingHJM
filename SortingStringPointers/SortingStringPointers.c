#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp()

void swap(char** xp, char** yp);
void printStringArray(char* arr[], int size);
void MySelectionSort(char* arr[], int n);
void selectionSort(char* arr[], int n);

int main(void)
{
	char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
	int n = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, n);

	MySelectionSort(arr, n); // ascending order

	printStringArray(arr, n);

	return 0;
}

void swap(char** xp, char** yp)
{
	char *tempArr = *xp;
	*xp = *yp;
	*yp = tempArr;
}

void printStringArray(char* arr[], int size)
{
	for (int i = 0; i < size; i++) 
	{
		printf("%s", arr[i]);
		printf("\n");
	}
	printf("\n");
}

void MySelectionSort(char* arr[], int n)
{
	int min_idx = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < n; j++)
		{
			//comparing Astr and Bstr, 
			if (strcmp(arr[j], arr[min_idx]) < 0)
				min_idx = j;
		}
		swap(&arr[min_idx], &arr[i]);
	}


	
}

void selectionSort(char* arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(arr[j], arr[min_idx]) < 0)
				min_idx = j;
		}

		// Swap the found minimum element with the first element
		/*
		char* temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
		*/
		swap(&arr[i], &arr[min_idx]);
	}
}
