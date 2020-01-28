#define _CRT_SECURE_NO_WARNINGS //only for visual studio

#include <stdio.h>

int main()
{
	/*
	while(expression)
		statement
	
	*/


	/*basic usage
	int n = 1;

	while (n < 3)
	{
		printf("%d\n", n);
		n = n + 1;
	}
	*/


	/*Pseudo code

	1.Initialize sum to 0

	2.Prompt User

	3.Read input

	4.While the input is an integer

	5.Add the input to sum

	6.Prompt user

	7.Then read next input

	8.After input complete, print sum*/



	/*
	int num, sum = 0;
	int status;

	printf("Enter an integer ( q to quit ) : ");

	status = scanf("%d", &num); // return value of scanf()

	while (status == 1) //equality operator
	{
		sum += num;
		printf("Enter next integer (q to quit) : ");
		status = scanf("%d", &num);
	}

	printf("Sum = %d\n", sum);
	*/


	// C-style shortcut
	int num, sum = 0;
	
	printf("Enter an integer ( q to quit ) : ");


	while (scanf("%d", &num)) //equality operator
	{
		sum += num;
		printf("Enter next integer (q to quit) : ");
	}

	printf("Sum = %d\n", sum);





	return 0;
}