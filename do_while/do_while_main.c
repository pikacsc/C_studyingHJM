#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int pwd = 337;

	int input = 0;
	//while (input != pwd)
	//{
	//	printf("Enter secret code : ");
	//	scanf("%d", &input);
	//	printf("\n");
	//} 

	do
	{
		printf("Enter secret code : ");
		scanf("%d", &input);
	} while (input != pwd);

	printf("Good!");

	return 0;
}
