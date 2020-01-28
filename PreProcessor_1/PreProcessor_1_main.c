#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	#define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

/*
	#undef
*/


#define LIMIT 400
//#undef LIMIT // It's ok to undefine previously NOT defined macro


#define TYPE 1

#if TYPE == 1
#include "my_function_1.h"
#elif TYPE == 2
#include "my_function_2.h"
#else
static void my_function()
{
	printf("Wrong compile option");
}
#endif

int main()
{
	printf("%d\n", LIMIT);

	my_function();

	return 0;
}