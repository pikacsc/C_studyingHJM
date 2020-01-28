#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void test_function();

int main(void)
{
	/* Array Versus Pointer */
	const char* pt2 = "I am a string!.";
	const char* pt3 = "I am a string!.";
	const char* pt4 = "I am a string!!!!!!!.";
	const char ar1[] = "I am a string!.";
	const char ar2[] = "I am a string!.";
	const char ar3[] = "I am a string!.";

	printf("Text low \t%llu %llu %llu %llu\n",
		(unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4,
		(unsigned long long) "I am a string!.");

	printf("Stack high \t%llu %llu %llu %llu\n",
		(unsigned long long)ar1, (unsigned long long)ar2, (unsigned long long)ar3, // check address numbers! 
		(unsigned long long) "I am a string!.");

	printf("Stack high \t%llu %llu %llu %llu\n", 
		(unsigned long long) ar1, (unsigned long long) ar2, (unsigned long long) ar3, 
		(unsigned long long) "I am a string!."); // check address numbers!

	/* Memory address check */

	/* Local variables */

	printf("Stack high \t%llu %llu %llu\n",
		(unsigned long long) & pt2, (unsigned long long) & pt3, (unsigned long long) & pt4);

	int i;
	printf("Stack high \t%llu\n", (unsigned long long) & i);

	/* Local variable in a function */
	test_function();

	/* Dynamic allocation */
	char* p5 = (char*)malloc(sizeof(char) * 100);
	printf("Heap middle \t%llu\n", (unsigned long long) p5);

	char* p6 = (char*)malloc(sizeof(char) * 100);
	printf("Heap middle \t%llu\n", (unsigned long long) p6);

	/* Array Versus Pointer (continued) */

	//ar1++; // Error
	pt2++; //OK
	puts(pt2); // Check the first character

	/* Array and Pointer Differences */

	char heart[] = "I love Kelly!";
	const char* head = "I love Helly!";

	for (int i = 0; i < 6; i++)
		putchar(heart[i]); //Note: putchar()
	putchar('\n');

	for (int i = 0; i < 6; i++)
		putchar(head[i]); //Note: putchar()
	putchar('\n');


	/* Pointer Addition */
	for (int i = 0; i < 6; i++)
		putchar(*(heart + i));
	putchar('\n');

	for (int i = 0; i < 6; i++)
		putchar(*(head + i));
	putchar('\n');

	while (*(head) != '\0')
		putchar(*(head++));

	head = heart;
	//heart = head; //Error

	 //Cannot change heart. Can change the element of heart
	heart[7] = 'H'; // Note : character
	*(heart + 7) = 'K';

	putchar('\n');

	char* word = "Goggle";
	//word[2] = 'o'; // Run-time error!
	puts(word);

	//Note : const char * word = "Google"; is recommended

	const char * str1 = "When all the lights are low, ...";
	const char * copy;

	copy = str1;

	printf("%s %p %p\n", str1, str1, &str1);
	printf("%s %p %p\n", copy, copy, &copy);

	//Note : strcpy(), strncpy()

	return 0;
}

void test_function()
{
	int j;
	printf("Stack high \t%llu\n", (unsigned long long) & j);
}