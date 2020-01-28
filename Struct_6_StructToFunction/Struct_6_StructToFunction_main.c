#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define FUNDLEN 50

struct fortune
{
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;
};

//double sum(double*, double*);

//double sum(struct fortune my_fortune);

double sum(const struct fortune* my_fortune);


int main(void)
{
	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f.\n",
		//sum(&my_fortune.bank_saving, &my_fortune.fund_invest)
		sum(&my_fortune));

	return 0;
}
//
//double sum(const double* x, const double* y) 
//{
//	return *x + *y;
//}
//
//double sum(struct fortune my_fortune) // becareful, it can be slow, if my_fortune is too big, 
//{
//	return my_fortune.bank_saving + my_fortune.fund_invest;
//}

double sum(const struct fortune* my_fortune)
{
	return my_fortune->bank_saving + my_fortune->fund_invest;
}