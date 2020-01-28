#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
  int arr[10];

  int num = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < num; ++i) 
	  arr[i] = (i + 1) * 100;

  int *ptr = arr;

  printf("int arr[10] = { 1, 2, 3, ... , 100 }; \n");
  printf("int *ptr = arr; \n");
  printf("ptr : %p, arr : %p, &arr[0] : %p \n", ptr, arr, &arr[0]);
  printf("\n");

  ptr += 2;
  printf("ptr += 2;\n");
  printf("ptr : %p, arr + 2 : %p, &arr[2] : %p\n", ptr, arr + 2, &arr[2]);

  //// Note: arr += 2; // invalid

  printf("*(ptr + 1) : %d, *(arr + 3) : %d, arr[3] : %d\n", *(ptr + 1), *(arr + 3), arr[3]);
  printf("\n\n");
  // Warning
  printf("Warning\n");
  printf("*ptr + 1 : %d, *arr + 3 : %d, arr[3] : %d\n", *ptr + 1, *arr + 3, arr[3]);
  printf("\n\n");

  for (int i = 0, *ptr = arr; i < num; ++i) 
  {
    printf("%d %d\n", *ptr++, arr[i]);
    //printf("%d %d\n", *(ptr + i), arr[i]);
    //printf("%d %d\n", *ptr + i, arr[i]);
  }

  return 0;
}