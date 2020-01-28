#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int;

static void tool(void)
{
	//
}

void fun_second(void)
{
	tool();

	g_int += 1;
	printf("g_int in fun_second() %d %p\n", g_int, &g_int);
}