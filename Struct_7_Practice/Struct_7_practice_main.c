#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main()
{
	struct name_count user_name = { 0 };

	receive_input(&user_name);
	count_characters(&user_name);
	show_result(&user_name);

	return;
}
//
//void receive_input(struct name_count* user_name)
//{
//	printf("Input your first name\n>>");
//	if(s_gets(user_name->first, NLEN) == NULL) return;
//
//	printf("Input your last name\n>>");
//	if(s_gets(user_name->last, NLEN) == NULL) return;
//	
//}
//
//void count_characters(struct name_count* user_name)
//{
//	user_name->num = 0;
//
//	for (size_t i = 0; i < strlen(user_name->first); i++)
//	{
//		if (user_name->first[i] == EOF)
//			break;
//		else if (user_name->first[i] == 32) // ignore space bar(empty space)
//			continue;
//		else
//			user_name->num++;
//	}
//
//	for (size_t i = 0; i < strlen(user_name->last); i++)
//	{
//		if (user_name->last[i] == EOF)
//			break;
//		else if (user_name->last[i] == 32) // ignore space bar(empty space)
//			continue;
//		else
//			user_name->num++;
//	}
//}

void show_result(const struct name_count* user_name)
{
	printf("Hi, %s %s, Your name has %d characters.", user_name->first, user_name->last, user_name->num);
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


// Guide Code
void receive_input(struct name_count* ptr_nc)
{
	int flag;

	printf("Input your first name:\n>> ");

	//s_gets(ptr_nc->first, NLEN);
	/*
	   scanf("%[^\n]%*c", ...)  
	   
	   %[^\n] means get input until '\n' (enter) and
	   
	   %*c means ignore one char input at the end, so '\n'
	*/

	flag = scanf("%[^\n]%*c", ptr_nc->first);  
	if (flag != 1)
		printf("Wrong input");

	printf("Input your last name:\n>> ");

	//s_gets(ptr_nc->last, NLEN);
	flag = scanf("%[^\n]%*c", ptr_nc->last);
	if (flag != 1)
		printf("Wrong input");
}

void count_characters(struct name_count* ptr_nc)
{
	ptr_nc->num = strlen(ptr_nc->first) + strlen(ptr_nc->last);
}