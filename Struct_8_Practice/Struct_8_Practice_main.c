#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);

int main(void)
{
	struct name_count user_name;

	user_name = receive_input();
	user_name = count_characters(user_name);
	show_result(user_name);

	return 0;
}

//MyCode
//struct name_count receive_input()
//{
//	struct name_count tempStruct = { 0 };
//	
//	printf("Input first name\n>> ");
//	scanf_s("%[^\n]%*c", tempStruct.first, NLEN);
//
//	printf("Input last name\n>> ");
//	scanf_s("%[^\n]%*c", tempStruct.last, NLEN);
//
//	return tempStruct;
//}
//
//struct name_count count_characters(struct name_count _name_count)
//{
//	_name_count.num = strlen(_name_count.first) + strlen(_name_count.last);
//	return _name_count;
//}


//Guide Code
struct name_count receive_input()
{
	struct name_count nc;

	int flag;
	printf("Input your first name:\n>> ");
	flag = scanf_s("%[^\n]%*c", nc.first, NLEN);
	
	if (flag != 1)
		printf("Wrong input");

	printf("Input your last name:\n>> ");

	flag = scanf_s("%[^\n]%*c", nc.last, NLEN);
	if (flag != 1)
		printf("Wrong input");

	return nc;
}


struct name_count count_characters(struct name_count nc)
{
	nc.num = strlen(nc.first) + strlen(nc.last);
	return nc;
}

void show_result(const struct name_count _name_count)
{
	printf("Hi, %s %s, Your name has %d characters.", _name_count.first, _name_count.last, _name_count.num);
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); // look for new line
		if (find)				 // if the address is not NULL
			* find = '\0';		 // place a null character there
		else
			while (getchar() != '\n')
				continue;		 // dispose of rest of line
	}
	return ret_val;
}
