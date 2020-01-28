#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // toupper(), ispunct(), ...

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);

int main()
{
	char line[NUM_LIMIT];
	char* new_line = NULL;
	fgets(line, NUM_LIMIT, stdin);
	new_line = strchr(line, '\n'); // find first new line
	if (new_line)
		* new_line = '\0';

	ToUpper(line);
	puts(line);
	printf("%d\n", PunctCount(line));


	return 0;
}

void ToUpper(char* line)
{
	while (*line)
	{
		*line = toupper(*line);
		/*
		if(islower(*line))
		*line = toupper(*line);
		*/
		line++;
	}
}

int PunctCount(const char* line)
{
	int ct = 0;
	while (*line)
	{
		if (ispunct(*line))
			ct++;
		line++;
	}
	return ct;
}
