#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int; // from second.c 

void fun_third(void)
{
	g_int += 1;
	printf("g_int in fun_third() %d %p\n", g_int, &g_int);
}