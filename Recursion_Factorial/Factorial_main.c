#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Loop vs Recursion
	factorial : multiplying every unsigned integer number in certain range except zero.
	ex)
	3!(factorial 3) == 3  * 2 * 1 == 6
*/

long loop_factorial(int n);
long recursive_factorial(int n);
long loop_factorial_2(int n);
long recursive_factorial_2(int n);
int main(void)
{
	int num = 5;

	//printf("%d\n", loop_factorial(num));
	printf("%d\n", recursive_factorial(num));
	return 0;
}

// my solutions
long loop_factorial(int n)
{
	int nextNum = n;
	//(n*(n-1)) *(n-2)
	while (--nextNum != 0)
	{
		n *= nextNum;
	}
	return (long)n;
}

long recursive_factorial(int n)
{
	if (n > 0)
	{
		n *= recursive_factorial(n - 1);
	}
	else
		return 1;
}


// lecture
long loop_factorial_2(int n)
{
	long ans;

	for (ans = 1; n > 1; n--)
		ans *= n;
	return ans;
}


long recursive_factorial_2(int n)
{
	if (n > 0)
		return n * recursive_factorial_2(n - 1); // tail (end) recursion : use recursion with return
	else
		return 1;
}