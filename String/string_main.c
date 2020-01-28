#define _CRT_SECURE_NO_WARNINGS //only for visual studio
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

	char str1[100] = "Hello";
	char str2[] = "Hello";
	char str3[100] = "\0";
	char str4[100] = "\n";

	printf("%zu %zu\n", sizeof(str1), strlen(str1));
	printf("%zu %zu\n", sizeof(str2), strlen(str2));
	printf("%zu %zu\n", sizeof(str3), strlen(str3));
	printf("%zu %zu\n", sizeof(str4), strlen(str4));




	printf("What is your favorite fruit?\n");
	
	//char fruit_name; // stores only one character.
	//scanf("%c", &fruit_name);
	

	char fruit_name[40];
	scanf("%s", fruit_name); //becareful with &, when you use array, array name is memory address it self



	printf("You like %s!\n", fruit_name);
	printf("%d\n", strlen(fruit_name));



	//dynamic memory allocation
	char* str5 = (char*)malloc(sizeof(char) * 100);
	str5[0] = 'H';
	str5[1] = 'e';
	str5[2] = 'l';
	str5[3] = 'l';
	str5[4] = 'o';
	str5[5] = '\0';

	printf("%zu %zu\n", sizeof(str5), strlen(str5));


	return 0;
}