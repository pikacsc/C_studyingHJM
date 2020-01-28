#define _CRT_SECURE_NO_WARNINGS
#define PERIOD '.'
#include <stdio.h>
#include <stdlib.h> //exit()
#include <locale.h>



int main()
{
	_wsetlocale(LC_ALL, L"korean");

	int c;
	int input;
	


	printf("please input code to search answer : ");
	//input code
	while ((input = getchar()) != PERIOD)
		break;


	FILE* file = NULL;
	char file_name[] = "code.txt"; //TODO: use scanf(...)

	file = fopen(file_name, "r"); // read or write

	if (file == NULL)
	{
		printf("Failed to open file.\n");
		exit(1);
	}
	
	

	while ((c = getc(file)) != EOF)
		putchar(c);
	


	//get file infos
	


	fclose(file);
	//print code with answer

	return 0;
}


