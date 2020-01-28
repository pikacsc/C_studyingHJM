#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf() in second.c

//extern int g_int;


void func_sec()
{
	extern int g_int;

	g_int += 7;
	printf("g_int in func_sec() %d %p\n", g_int, &g_int);
}