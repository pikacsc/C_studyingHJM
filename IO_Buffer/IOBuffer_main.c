#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h> //Windows, _getch(), _getche()
 
int main(void)
{
	char c;

	while ((c = _getche()) != '.')
		putchar(c);

	return 0;
}