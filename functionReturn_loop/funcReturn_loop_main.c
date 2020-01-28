#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Square(int base, int exponent);

int main(void)
{
	int base, exponent, answer = 0;
	printf("Enter a base number : ");
	scanf("%d", &base);
	printf("\n");
	printf("Enter a exponent number : ");
	scanf("%d", &exponent);
	printf("\n");
	printf("%d^%d = %d",base,exponent, Square(base,exponent));
	return 0;
}


int Square(int base, int exponent)
{
	int answer = base;
	for (int i = 1; i < exponent; i++)
		answer *= base;
	return answer;
}