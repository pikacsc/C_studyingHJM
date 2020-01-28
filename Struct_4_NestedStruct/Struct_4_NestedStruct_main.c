#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

struct names // A struct
{
	char given[LEN]; //first name
	char family[LEN]; // last name
};

struct reservation // another struct
{
	struct names guest; // a nested struct
	struct names host; // one more nested struct
	char food[LEN];
	char place[LEN];

	//time
	int year;
	int month;
	int day;
	int hours;
	int minutes;
};

int main(void)
{
	struct reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"the Gatsby mansion"},
		.food = {"Escargot"},
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};


	/*
	Dear Nick Carraway,
	I would like to serve you Escargot.
	Please visit the Gatsby masion on 10/4/1925 at 18:30.
	Sincerely,
	Jay Gatsby
	*/

	//MyCode
	/*printf("Dear %s %s,\n",res.guest.given,res.guest.family);
	printf("I would like to serve you %s.\n",res.food);
	printf("Please visit %s on %d/%d/%d at %d:%d.\n",res.place,res.day,res.month,res.year,res.hours,res.minutes);
	printf("Sincerely,\n");
	printf("%s %s", res.host.given, res.host.family);*/


	//Guide Code
	const char* formatted =
		"\
Dear %s %s, \nI would like to serve you %s.\n\
Please visit %s on %d/%d/%d at %d:%d.\n\
Sincerely,\n\
%s %s\
";
	printf(formatted, res.guest.given, res.guest.family, res.food,
		res.place, res.day, res.month, res.year, res.hours, res.minutes,
		res.host.given, res.host.family);
	return 0;
}