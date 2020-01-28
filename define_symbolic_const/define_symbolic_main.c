#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592f //replacing PI to 3.141592f preprocessing

int main()
{
	float radius, area, circum;

	printf("Input radius :  \n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0 * PI * radius; // circum = 2.0 * pi * r
}
