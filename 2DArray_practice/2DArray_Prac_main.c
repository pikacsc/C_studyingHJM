#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main(void)
{
	double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
	double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
	double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };
	/*
	1. Use 2D Array
	2. Print data
	3. Calculate and print yearly average temperatures of 3 years
	4. Calculate and print monthly average temperatures for 3 years
	*/



	// My Solution

	double temperatureData2DArr[YEARS][MONTHS] =
	{
		{ -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 },
		{ -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
		{ -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 }
	};

	double temperatureData2DArr_2[MONTHS][YEARS] =
	{
		{ -3.2, -1.8, -4.0 },
		{ 0.2, -0.2, -1.6 },
		{ 7.0, 6.3, 8.1 },
		{ 14.1, 13.9, 13.0 },
		{ 19.6, 19.5, 18.2 },
		{ 23.6, 23.3, 23.1 },
		{ 26.2, 26.9, 27.8 },
		{ 28.0, 25.9, 28.8 },
		{ 23.1, 22.1, 21.5 },
		{ 16.1, 16.4, 13.1 },
		{ 6.8, 5.6, 7.8 },
		{ 1.2, -1.9, -0.6 }
	};

	printf("[Temperature Data]\n");
	printf("Year index :");
	for (int i = 1; i <= 12; i++)
	{
		printf("\t%d",i);
	}
	printf("\n");
	for (int j = 0; j < 3; j++)
	{
		printf("Year %d\t:", j);
		for (int i = 0; i < 12; i++)
		{
			printf("\t%4.1f",temperatureData2DArr[j][i]);
		}
		printf("\n");
	}



	printf("\n");
	printf("[Yearly average temperatures of 3 years]\n");
	for (int j = 0; j < 3; j++)
	{
		double sum = 0;
		for (int i = 0; i < 12; i++)
		{
			sum += temperatureData2DArr[j][i];
		}
		printf("Year %d : average temperature = %4.1f \n",j, sum / 12);
	}
	printf("\n");



	printf("\n");
	printf("[Monthly average temperatures of 3 years]\n");
	printf("Year index :");
	for (int i = 1; i <= 12; i++)
	{
		printf("\t%d", i);
	}
	printf("\n");
	printf("Avg temps :");
	for (int j = 0; j < 12; j++)
	{
		double sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum += temperatureData2DArr_2[j][i];
		}
		printf("\t%4.1f", sum/YEARS );
	}
	


	return 0;
}