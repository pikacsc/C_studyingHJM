#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	//char* title;		// Not recommended
	//char* author;		// Not recommended
	float price;
};

struct rectangle
{
	double width;
	double height;
};

double rect_area(struct rectangle r)
{
	return r.width* r.height;
}

double rect_area_ptr(struct rectangle* r)
{
	return r->width* r->height;
}

int main(void)
{
	struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f };

	/*
		Compound literals
		- Temporary structure values
	*/

	// if we want to define values all at once then Error comes
	//book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3f }; //Error

	//solution 1, seperately, define value in each variable
	strcpy(book_to_read.title, "Alice in Wonderland");
	strcpy(book_to_read.author, "Alice in Wonderland");
	book_to_read.price = 20.3f;


	//solution 2, declare another variable B and copy B to A(original) 
	struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
	book_to_read = book2;

	
	//solution 3, Compound Literals
	book_to_read = (struct book) { "Alice in Wonderland", "Lewis Carroll", 20.3f }; // Compound literals == Lvalue

	printf("%s %s\n", book_to_read.title, book_to_read.author);

	struct rectangle rec1 = { 1.0, 2.0 };
	double area = rect_area(rec1);
	area = rect_area((struct rectangle) { 1.0, 2.0 }); // you can use Compound Literals as argument

	area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = 2.0 }); // you can do Designated intialize, evne you can use &
	printf("%f\n", area);

	return 0;
}