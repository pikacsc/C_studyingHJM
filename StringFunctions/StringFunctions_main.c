#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);

char* tech_strcat(char*, const char*);

int tech_strcmp(const char* X, const char* Y);

//my solution
void my_strcat(char*, char*);

int my_strcmp(char* , char* );

int main(void)
{
	/*
		strlen() : returns length of the string
	*/

	////TODO: use debugger
	//char msg[] = "Just," " do it!";
	//puts(msg);
	//printf("Length %d\n", strlen(msg));
	//fit_str(msg, 4);
	//puts(msg);
	//printf("Length %d\n", strlen(msg));
	////TODO: implement fit_str() function


	/*
		strcat() and strncat() : string concatenation
	*/

	//char str1[100] = "First string";
	//char str2[] = "Second string";

	//////strcat(str1, ", ");
	////strcat(str1, str2);
	////strncat(str1, str2, 2); // Append 2 characters
	//my_strcat(str1, str2);
	//puts(str1);

	/*
		strcmp(str1, str2) and strncmp(str1, str2, size) : compare strings (not characters)

		Same : 0
		Different 
		if str1's ASCII index is lower then str2: -1
		else  : 1

	*/
	//
	//printf("strcmp(A,A) %d\t my_strcmp(A,A) %d\n", strcmp("A", "A"), my_strcmp("A", "A"));
	//printf("strcmp(A,B) %d\t my_strcmp(A,B) %d\n", strcmp("A", "B"), my_strcmp("A", "B"));
	//printf("strcmp(B,A) %d\t my_strcmp(B,A) %d\n", strcmp("B", "A"), my_strcmp("B", "A"));
	//printf("strcmp(Hello, Hello) %d\t my_strcmp(Hello, Hello) %d\n", strcmp("Hello", "Hello"), my_strcmp("Hello", "Hello"));
	//printf("strcmp(Banana, Bananas) %d\t my_strcmp(Banana, Bananas) %d\n", strcmp("Banana", "Bananas"), my_strcmp("Banana", "Bananas"));
	//printf("strcmp(Bananas, Bananas) %d\t my_strcmp(Bananas, Bananas) %d\n", strcmp("Bananas", "Banana"), my_strcmp("Bananas", "Banana"));
	//printf("strncmp(Bananas, Bananas) %d\n", strncmp("Bananas", "Banana", 6));
	//TODO: implement strcmp!
	
	/*
		strcpy() and strncpy()
	*/

	//char dest[100] = ""; // make sure memory is enough
	//char source[] = "Start programming!";
	////dest = source; // Error
	////dest = "Start something"; // Error
	//strcpy(dest, source);
	//strncpy(dest, source, 5); // '\0' is NOT added
	////strcpy(dest, source + 6);
	////strcpy(dest, source);
	////strcpy(dest + 6, "coding!");
	//puts(dest);

	/*
		sprintf()
	*/

	//char str[100] = "";
	//int i = 123;
	//double d = 3.14;
	//sprintf(str, "%05d.png %f", i, d);
	//puts(str);

	//capture00000.png, capture00001.png, ...

	/*
		There are more functions ...
	*/

	printf("%s\n", strchr("Hello, World", 'W'));
	printf("%s\n", strpbrk("Hello, World", "ABCDE"));
	printf("%s\n", strpbrk("Hello, World", "abcde"));
	printf("%s\n", strrchr("Hello, World, Hello, World", 'l'));
	printf("%s\n", strstr("Hello, World", "wor"));
	printf("%s\n", strstr("Hello, World", "Wor"));
	
	return 0;

}

void fit_str(char* str, unsigned int endIndex)
{

	if (strlen(str) > endIndex)
		str[endIndex] = '\0';




	//MySolution
	////validate endIndex 
	//if (endIndex > strlen(str))
	//	return;
	//*(str + endIndex) = '\0';

}


char* tech_strcat(char* destination, const char* source)
{
	// make ptr point to the end of destination string
	char* ptr = destination + strlen(destination);

	// Appends characters of source to the destination string
	while (*source != '\0')
		* ptr++ = *source++;

	// null terminate destination string
	*ptr = '\0';

	// destination is returned by standard strcat()
	return destination;
}
//https://www.techiedelight.com/implement-strcat-function-c/


int tech_strcmp(const char* X, const char* Y)
{
	while (*X)
	{
		//if characters differ or end of second string is reached
		if (*X != *Y)
			break;

		// move to next pair of characters
		X++;
		Y++;
	}
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}
//https://www.techiedelight.com/implement-strcmp-function-c/

//my solution
void my_strcat(char* str1, char* str2)
{
	int str1len = strlen(str1);
	int str2len = strlen(str2);
	for (int i = 0; i < str2len; i++)
		str1[str1len + i] = str2[i];

}

int my_strcmp(char* str1, char* str2)
{
	int result = 0;
	int maxSize = strlen(str1) < strlen(str2) ? strlen(str2) : strlen(str1);
	for (int i = 0; i < maxSize; i++)
	{
		if ((int)str1[i] < (int)str2[i])
			result = -1;
		else if ((int)str1[i] > (int)str2[i])
			result = 1;
	}
	return result;
}

