#include <stdio.h>

extern int el; // extern - to use other file's variable
extern int il; // link error, int il is already static variable

void testLinkage()
{
	printf("DoSomething called\n");
	printf("%d\n", el);
	//printf("%d\n", il);
	//printf("%d\n", dodgers);

	el++;
}