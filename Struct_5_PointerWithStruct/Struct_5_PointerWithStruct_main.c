#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

struct names
{
	char given[LEN];
	char family[LEN];
};

struct friend
{
	struct names full_name;
	char mobile[LEN];
};

struct my_data
{
	int a;
	char c;
	float arr[2];
};

int main(void)
{
	struct friend my_friend[2] = {
		{ {"Ariana", "Grande"}, "1234-1234"},
		{ {"Taylor", "Swift"}, "6550-8888"}
	};

	struct friend* girl_friend;

	girl_friend = &my_friend[0];

	printf("%zd\n", sizeof(struct friend));
	printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
	// -> : indirect member access operator

	girl_friend++;

	printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);
	// . has higher precedence than * 



	struct my_data d1 = { 1234, 'A', };

	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	printf("%f %f\n", d1.arr[0], d1.arr[1]);
	printf("%lld %lld\n\n", (long long)& d1.arr[0], (long long)& d1.arr[1]);

	struct my_data d2 = d1; // copy all struct's  from d1 to d2

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	printf("%f %f\n", d2.arr[0], d2.arr[1]);
	printf("%lld %lld\n", (long long)& d2.arr[0], (long long)& d2.arr[1]);

	return 0;
}