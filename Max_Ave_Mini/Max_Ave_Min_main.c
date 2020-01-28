#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>

int main(void)
{
	float max = -FLT_MAX;
	float min = FLT_MAX;
	float sum = 0.0f;
	float input;
	int n = 0;

	while (scanf("%f", &input) == 1)
	{
		if (input < 0.0f || input > 100.f) continue; 
		max = (input > max) ? input : max;
		min = (input < min) ? input : min;
		sum += input;


		//MySolution
		/*sum += input;
		n++;
		if (max < input)
		{
			max = input;
			if (input < min)
				min = input;
		}
		else
		{
			if (input < min)
				min = input;
		}*/
	}

	if (n > 0)
		printf("min %f, max = %f, ave = %f\n", min, max, sum / n);
	else
		printf("No input\n");


	return 0;
}