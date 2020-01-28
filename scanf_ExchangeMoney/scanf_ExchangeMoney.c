#define _CRT_SECURE_NO_WARNINGS //only for visual studio
#include <stdio.h>

int main()
{
	int KRW = 0;
	float USD = 0;
	float exchangeRateUSD = 0.00089f;
	printf("input KRW : ");
	scanf("%d",&KRW);
	USD = KRW * exchangeRateUSD;

	printf("KRW : %d \n", KRW);
	printf("USD : %f \n", USD);

}
