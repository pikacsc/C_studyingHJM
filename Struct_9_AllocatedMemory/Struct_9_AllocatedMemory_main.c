#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen(), strcmp()
#include <stdlib.h> // malloc(), free()
#define SLEN 81

struct namect {
	char* fname; // Use malloc()
	char* lname; // Use malloc()
	int letters;
};

void getinfo(struct namect*); // allocate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);	// free memory when done
char* s_gets(char* st, int n);

int main(void)
{
	//Dangerous usage
	//

	//struct namect p = { "Jeong-Mo", "Hong" };
	//printf("%s %s\n", p.fname, p.lname);
	//
	//int f1 = scanf("%[^\n]%*c", p.lname);
	//printf("%s %s\n", p.lname, p.fname);
 //   



	////Recommended usage
	

	//char buffer[SLEN] = { 0, };
	//int f2 = scanf("%[^\n]%*c", buffer);
	//p.fname = (char*)malloc(strlen(buffer) + 1);
	//if (p.fname != NULL)
	//	strcpy(p.fname, buffer);
	//printf("%s %s\n", p.fname, p.lname);

	/* Problem */
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}
//	My Code
//void getinfo(struct namect* p_nct)
//{
//	//allocate memory
//	char buffer[SLEN] = { 0 };
//	int flag = 0;
//	printf("Input first name\n");
//	flag = scanf_s("%[^\n]%*c", buffer, SLEN);
//	p_nct->fname = (char*)malloc(strlen(buffer) + 1);
//	if (p_nct != NULL)
//		strcpy_s(p_nct->fname, strlen(buffer) + 1, buffer);
//	
//
//	printf("Input last name\n");
//	flag = scanf_s("%[^\n]%*c", buffer, SLEN);
//	p_nct->lname = (char*)malloc(strlen(buffer) + 1);
//	if (p_nct != NULL)
//		strcpy_s(p_nct->lname, strlen(buffer) + 1, buffer);
//
//}

//  Guide Code
void getinfo(struct namect* pst)
{
	int flag;
	char temp[SLEN] = { 0, };

	printf("Please enter your first name.\n");
	flag = scanf("%[^\n]%*c", temp);
	if (flag != 1)
		printf("Wrong input"); //TODO: receive input again
	else
	{
		pst->fname = (char*)malloc(strlen(temp) + 1); // + 1 is for '\0'
		if (pst->fname != NULL)
			strcpy(pst->fname, temp);
		else
			printf("Malloc() failed");
	}

	printf("Please enter your last name.\n");
	flag = scanf("%[^\n]%*c", temp);
	if (flag != 1)
		printf("Wrong input"); 
	else
	{
		pst->lname = (char*)malloc(strlen(temp) + 1);
		if (pst->lname != NULL)
			strcpy(pst->lname, temp);
		else
			printf("Malloc() failed");
	}
}

void makeinfo(struct namect* p_nct)
{
	p_nct->letters = strlen(p_nct->fname) + strlen(p_nct->lname);
}

void showinfo(const struct namect* p_nct)
{
	printf("%s %s, your name contains %d letters.", p_nct->fname, p_nct->lname, p_nct->letters);
}

void cleanup(struct namect* p_nct)
{
	free(p_nct->fname);
	p_nct->fname = NULL;
	free(p_nct->lname);
	p_nct->lname = NULL;
}
