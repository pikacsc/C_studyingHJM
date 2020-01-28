#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h> // strlen()
#include <stdlib.h>	// exit()

unsigned char to_decimal(const char bi[]);

//int charToParseInt(const char c);

int main()
{

	//printf("%d",charToParseInt('2'));

	printf("Binary (string) to Decimal conversion\n");

	printf("%d\n", to_decimal("00000110")); // 1*(2^2) + 1 * (2^1) = 4 + 2 = 6
	printf("%d\n", to_decimal("00010110")); // 1*(2^4) + 1 * (2^2) + 1 * (2^1) = 16 + 4 + 2 = 22

	// Note: ^ (caret) means power in math.
	// Hint: (int)pow(2, 3) == 8

	printf("%d\n", to_decimal("10010100"));

	return 0;
}

//MyCode
//unsigned char to_decimal(const char bi[])
//{
//	//get count of bi
//	int maxbinary = strlen(bi);
//	int lastIdx = maxbinary - 1;
//	int sum = 0, i = 0;
//	
//	//(int)pow(2, 0)* charToParseInt(bi[maxbinary - 1]) + (int)pow(2,1)*charToParseInt(bi[maxbinary - 2]) + (int)pow(2, 2) * charToParseInt(bi[maxbinary - 3]) + (int)pow(2, 3) * charToParseInt(bi[maxbinary - 4])
//	for (i = 0; i < maxbinary; i++)
//	{
//		sum += (int)pow(2, i)* charToParseInt(bi[lastIdx--]);
//	}
//
//	return (unsigned char)sum;
//}
//
////MyCode
//int charToParseInt(const char c)
//{
//	return (int)(c - 48);
//}

unsigned char to_decimal(const char bi[])
{
	const size_t bits = strlen(bi);
	unsigned char sum = 0;
	for (size_t i = 0; i < bits; ++i)
	{
		if (bi[i] == '1')
			sum += (int)pow(2, bits - 1 - i);
		else if (bi[i] != '0') {
			printf("Wrong character : %c", bi[i]);
			exit(1);
		}
	}

	return sum;
	//printf("Binary %s == Deciaml %d\n", bi, sum);

}
