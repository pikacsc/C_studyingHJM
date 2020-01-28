#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>		//pow()
#include <string.h>		//strlen()
#include <stdlib.h>		//exit()
#include <stdbool.h>	

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
	unsigned char i = to_decimal("01000110");
	unsigned char mask = to_decimal("00000101");

	print_binary(i);
	print_binary(mask);
	print_binary(i & mask);


}

void print_binary(const unsigned char num)
{
	printf("Decimal %d\t== Binary ",num);
}