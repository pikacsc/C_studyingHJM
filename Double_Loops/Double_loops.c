#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 5
#define FIRST_CHAR 'A'
#define LAST_CHAR 'K'

int main(void)
{
	//int r; // row loop
	//int c; // character loop

	//for (r = 0; r < NUM_ROWS; ++r) // outer row loop
	//{
	//	for (c = FIRST_CHAR; c <= LAST_CHAR; ++c)// inner character loop
	//		printf("%c ", c);
	//	printf("\n");
	//}



	//My Solution
	//int AschiiIndex = 65; // 65 == A, ... 75 == K
	//for (int i = 0; i < 5; i++)
	//{
	//	AschiiIndex = 65;	
	//	for (int j = 0; j < 11; j++)
	//	{
	//		printf("%c ", (char)AschiiIndex);
	//		AschiiIndex++;
	//	}
	//	printf("\n");
	//}



	//int r; // row loop
	//int c; // character loop

	//for (r = 0; r < NUM_ROWS; ++r)
	//{
	//	for (c = FIRST_CHAR; c <= FIRST_CHAR + r; ++c)
	//		printf("%c ", c);
	//	printf("\n");
	//}


	//My Solution
	/*int last_Char = FIRST_CHAR;
	for (int i = 0; i < 10; i++)
	{
		for (int c = FIRST_CHAR; c <= last_Char; c++)
			printf("%c ",c);
		last_Char++;
		printf("\n");
	}*/




	int r; // row loop
	int c; // character loop

	for (r = 0; r < NUM_ROWS; ++r)
	{
		for (c = FIRST_CHAR + r; c < FIRST_CHAR + NUM_ROWS; ++c)
			printf("%c ", c);
		printf("\n");
	}


	//My Solution
	/*int numberOfChar = 12;
	int first_char = FIRST_CHAR;
	for (int row_num = numberOfChar; row_num >= 1; row_num--)
	{
		for (int c = first_char;c <= LAST_CHAR; c++)
		{
			printf("%c ", c);
		}
		printf("\n");
		first_char++;
	}*/



	return 0;
}