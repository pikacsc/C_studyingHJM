#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#define PERIOD '.'

int main(void)
{
	int ch;
	int charCounters = 0;
	int wordCounters = 0;
	while ((ch = getchar()) != PERIOD)
	{
		if (ch != ' ')
			charCounters++;
		else if (ch == ' ')
			wordCounters++;
	} 
	putchar(ch);
	printf("Characters = %d, word = %d", charCounters, ++wordCounters);
	return 0;
}