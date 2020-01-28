#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> // getchar(), putchar()


int main(void)
{
	/*
		1. Introduce getchar(), putchar()
		2. Use while loop to process character sequences
		3. Filter a specific character
		4. Convert numbers to asterisks
		5. Lower characters to Upper characters
	*/

	char ch;
	
	//while(ch !='\n') // Use '\n' to find the end of a sentence
	while ( (ch = getchar()) != '\n')
	{
		if (ch >= 'a' && ch <= 'z') // 'A' = 65, 'a = 97
			ch -= 'a' - 'A';
		/*if (ch >= '0' && ch <= '9')
			ch = '*';
		if (ch == 'f' || ch == 'F')
			ch = 'X';
*/
		putchar(ch);

	}
	
	ch = 'f';
	
	putchar(ch);



	return 0;
}