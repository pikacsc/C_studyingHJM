#define _CRT_SECURE_NO_WARNINGS //only for visual studio

#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int sum = 0;
	printf("Please input Two Numbers : ");
	scanf("%d%d", &i, &j); // & : ampersand, variable memory address

	sum = i + j;

	printf("Values are %d %d\n", i, j);
	printf("sum : %d", sum);
	return 0;
}