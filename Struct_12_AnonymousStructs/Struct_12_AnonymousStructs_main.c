#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct names
{
	char first[20];
	char last[20];
};

struct person
{
	int id;
	struct names name; // nested struct member
};

struct person2
{
	int id;
	struct { char first[20]; char last[20]; }; //anonymous struct
};

int main(void)
{
	struct person ted = { 123, {"Bill", "Gates"} };
	struct person ted3 = { 125, "Robert", "Hand" };

	// nested struct member
	puts(ted.name.first);
	puts(ted3.name.first);

	struct person2 ted2 = { 124, {"Steve", "wozniak"} };
	//struct person2 ted2 = { 124, "Steve", "wozniak" }; // also works
	
	//anonymous struct member
	puts(ted2.first);

	return 0;
}