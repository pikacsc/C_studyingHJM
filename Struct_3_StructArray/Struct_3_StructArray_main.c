//MyCode
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_BOOKCOUNT 3
#define MAX_NAMELENGTH 50

struct Book
{
	char name[MAX_NAMELENGTH];
	char author[MAX_NAMELENGTH];
	float price;
};


int main()
{
	int BookCount = 0;
	char c = 0;
	struct Book bookArr[MAX_BOOKCOUNT] = { 0 };
	
	while (BookCount != MAX_BOOKCOUNT)
	{
		//when you press enter, then break the loop
		printf("\nInput a book title or press [Enter] to stop.\n");
		printf(">>");
		//TODO: finish this


		printf("Input the author\n");
		printf(">>");
		scanf_s("%s", bookArr[BookCount].author, MAX_NAMELENGTH);
		printf("Input the price\n");
		printf(">>");
		scanf_s("%f", &bookArr[BookCount].price);
		BookCount++;
	}

	if (BookCount == 0)
		printf("\nNo Books to show\n");
	else
	{
		printf("The list of books:\n");
		for (int i = 0; i < BookCount; i++)
		{
			printf("\"%s\" written by %s : %f\n", bookArr[i].name, bookArr[i].author, bookArr[i].price);
		}
	}
	return 0;
}