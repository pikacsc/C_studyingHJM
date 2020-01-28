#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_DAYS 365

int main(void)
{
	/*char my_chars[] = "Hello, World!";

	int daily_temperature[NUM_DAYS];
	double stock_prices_history[NUM_DAYS];

	printf("%zd\n", sizeof(stock_prices_history));
	printf("%zd\n", sizeof(double) * NUM_DAYS);
	printf("%zd\n", sizeof(stock_prices_history[0]));
	printf("\n");*/

	
	int my_numbers[5];


	// subscripts, indices, offsets, array name is origin memory address, array index is how far from origin memory address 
	my_numbers[0] = 1; 	// my_numbers[0] == *(my_numbers)
	my_numbers[1] = 3;  // my_numbers[1] == *(my_numbers+1)
	my_numbers[2] = 4;  // my_numbers[2] == *(my_numbers+2)
	my_numbers[3] = 2;  // my_numbers[3] == *(my_numbers+3)
	my_numbers[4] = 1024;  // my_numbers[4] == *(my_numbers+4)

	scanf("%d", &my_numbers[0]);

	printf("%s\n", ( my_numbers[0] == *(my_numbers) )? "true" : "false");
	printf("%s\n", ( my_numbers[1] == *(my_numbers + 1) ) ? "true" : "false");
	printf("%s\n", ( my_numbers[2] == *(my_numbers + 2) ) ? "true" : "false");
	printf("%s\n", ( my_numbers[3] == *(my_numbers + 3) ) ? "true" : "false");
	printf("%s\n", ( my_numbers[4] == *(my_numbers + 4) ) ? "true" : "false");
	

	/* Runtime Error*/
	//my_numbers[5] = 123;// out of bound

	return 0;
}