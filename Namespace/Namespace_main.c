#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int iamfunction()
{
	return 0;
}

int main()
{
	/*
		namespace
		- Identify parts of a program in which a name is recognized
		- You can use the same name for one variable and one tag
		- C++: use 'namespace' to use the same identifiers in the duplicated scopes.
	*/

	{
		int myname = 345;
		//double myname = 3.14;//Error
	}

	struct rect { double x; double y };

	//int rect = 123; // OK in C (Not OK in C++)
	struct rect rect = { 1.1, 2.2 }; // struct rect and rect are in different categories

	/*
	typedef struct rect rect;
	rect rect = { 1.1, 2.2 }; //Not OK
	*/

	//int iamfunction = iamfuntion(); //Error, you can't use function name as variable name

	/*
		Namespace pollution (KNK p.465)
		- Names in different files accidentally conflicting with each other
	*/
	return 0;
}