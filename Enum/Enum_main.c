#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	/*
		Enumerated type
		- Symbolic names to represent integer constants
		- Improve readability and make it easy to maintain
		- enum-specifier (struct-specifier, union-specifier)

		Enumerators
		- The symbolic constants
	*/

	enum spectrum 
	{ 
		red,	// 0
		orange, // 1
		yellow, // 2
		green,  // 3
		blue,   // 4
		violet  // 5
	};
	
	
	enum spectrum color;

	color = blue;

	if (color == yellow) 
		printf("yellow"); //Note : enumerators are not strings

	for (color = red; color <= violet; color++)	//Note : ++operator doesn't allowd in C++, use type int.
		printf("%d\n", color);

	printf("red = %d, orange = %d\n", red, orange);
	
	enum kids { jackjack, dash, snoopy, nano, pitz };
	// nina has a value of 3
	enum kids my_kid = nano;
	printf("nano %d %d\n", my_kid, nano);

	enum levels { low = 100, medium = 500, high = 200 };

	int score = 800; //TODO user input
	if (score > high)
		printf("High score!\n");
	else if (score > medium)
		printf("Good job\n");
	else if (score > low)
		printf("Not bad\n");
	else
		printf("Do your best\n");

	enum pet { cat, dog = 10, lion, tiger };
	// puma has a value of 11

	return 0;
}