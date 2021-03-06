#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

struct Person /* Person is a tag of structure */
{
	char name[MAX]; //member
	int age;
	float height;
};

int main(void)
{
	int flag; // Receives return value of scanf()

	/* Structure variable */

	struct Person genie;

	/* dot(.) is structure membership operator (member access operator, member operator) */

	strcpy(genie.name, "Will Smith");	
	//strncpy(genie.name, "Will Smith", MAX);

	genie.age = 1000;

	// dot(.) has higher precedence than &
	flag = scanf("%f", &genie.height); //&(genie.height)
	printf("%f\n", genie.height);
	

	// Initialization

	struct Person princess = ("Naomi Scott", 18, 160.f);

	struct Person princess2 = {
		"Naomi Scott",
		18,
		160.f
	};

	strcpy(princess.name, "Naomi Scott");
	princess.age = 18;
	princess.height = 160.0f;


	/* Designated initializers */

	struct Person beauty = {
		.age = 19,
		.name = "Bell",
		.height = 150.0f
	};

	// struct Person beauty  = { .age = 19, .name = "Bell", .height = 150.0f };

	/* Pointer to a structure variable */

	struct Person* someone;

	someone = &genie;
	//someone = (struct Person*)malloc(sizeof(struct Person)); // and free later

	/* Indirect member(ship) operator (or structure pointer operator) */

	someone->age = 1001; // arrow(->) operator, someone->age == (*someone).age
	printf("%s %d\n", someone->name, (*someone).age);
	

	/* Structure declarations in a function */
	struct book
	{
		char title[MAX];
		float price;
	};


	/* No tag */
	struct {
		char farm[MAX];
		float price;
	} apple, apple2;

	strcpy(apple.farm, "Trade Joe");
	apple.price = 1.2f;

	strcpy(apple2.farm, "Safeway");
	apple.price = 1.2f;

	/* typedef and structure */

	typedef struct person my_person;

	//my_person p3;

	typedef struct person person;

	//person p4;

	typedef struct {
		char name[MAX];
		char hobby[MAX];
	} friend;

	friend f4;

	return 0;
}