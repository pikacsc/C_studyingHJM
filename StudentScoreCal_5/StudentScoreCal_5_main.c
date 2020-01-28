//MyCode
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "MyCode.h"

int main(void)
{
	int currentStudentCount = 0, selectNum = 0;

	SD* pfirstSD = NULL;
	SD* pEndSD = NULL;

	while (selectNum!= 3)
	{
		printf("STUDENT SCORE MANAGER\n");
		printf("1.Add Student\n");
		printf("2.Show Student List\n");
		printf("3.Quit\n");
		printf("select : ");
		scanf_s("%d", &selectNum);
		if (selectNum == 1)
		{
			if (!pfirstSD) // Zero
			{
				pfirstSD = (SD*)malloc(sizeof(SD));
				AddStudent(pfirstSD, currentStudentCount);
				pEndSD = pfirstSD->p_next;
				currentStudentCount++;
			}
			else if(pfirstSD->p_next) // more then one
			{
				SD* curSD = NULL;
				curSD = pfirstSD->p_next;
				while (curSD->p_next)
					curSD = curSD->p_next;
				curSD->p_next = (SD*)malloc(sizeof(SD));
				pEndSD = curSD->p_next;
				currentStudentCount++;
			}
			else // one
			{
				pfirstSD->p_next = (SD*)malloc(sizeof(SD));
				AddStudent(pfirstSD->p_next, currentStudentCount);
				pEndSD = pfirstSD->p_next;
				currentStudentCount++;
			}
		}
		else if (selectNum == 2)
		{
			ShowStudentList(pfirstSD,currentStudentCount);
		}
	}

	DeleteData(pfirstSD);

	return 0;
}

//Guide Code
/*
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define NAME_LENGTH 32

typedef struct StudentData
{
	int num;
	char* p_name;
	int kor, eng, math;
	int sum;
	float avg;
	struct StudentData* p_next;
} SD;

void InputData(SD* ap_user)
{
	char temp[NAME_LENGTH];
	printf("input student's info.\n");
	printf("student nubmer : ");
	scanf_s("%d", &ap_user->num);
	printf("name : ");
	scanf_s("%s", temp, NAME_LENGTH);
	int len = strlen(temp) + 1;
	ap_user->p_name = (char*)malloc(len);
	memcpy(ap_user->p_name, temp, len);

	printf("kor score : ");
	scanf_s("%d", &ap_user->kor);
	printf("eng score : ");
	scanf_s("%d", &ap_user->eng);
	printf("math score : ");
	scanf_s("%d", &ap_user->math);

	ap_user->sum = ap_user->kor + ap_user->eng + ap_user->math;
	ap_user->avg = ap_user->sum / 3.f;
}


void ShowList(SD* ap_user)
{
	printf("\n number     name     kor     eng     math     sum     avg\n");
	while (NULL != ap_user)
	{
		printf("%5d %8.8s %6d %6d %6d    %5d     %f\n",
			ap_user->num, ap_user->p_name, ap_user->kor,
			ap_user->eng, ap_user->math, ap_user->sum, ap_user->avg);
		ap_user = ap_user->p_next;
	}
}

void DeleteData(SD* ap_user)
{
	SD* p_delete;
	while (NULL != ap_user)
	{
		p_delete = ap_user;
		ap_user = ap_user->p_next;
		free(p_delete->p_name);
		free(p_delete);
	}
}

int main()
{
	SD* p_head = NULL, * p_tail = NULL;
	int select = 0;
	int count = 0;
	while (select != 3)
	{
		printf("[ MENU ]\n");
		printf("1.Add Student\n");
		printf("2.Show Student List\n");
		printf("3.Quit\n");
		printf("select : ");

		scanf_s("%d", &select);
		if (select == 1)
		{
			if (NULL != p_head)
			{
				p_tail->p_next = (SD*)malloc(sizeof(SD));
				p_tail = p_tail->p_next;
			}
			else
			{
				p_head = (SD*)malloc(sizeof(SD));
				p_tail = p_head;
			}

			p_tail->p_next = NULL;
			InputData(p_tail);
			count++;
		}
		else if (select == 2)
		{
			ShowList(p_head);
		}
		printf("\n");
	}

	DeleteData(p_head);
	return 0;
}
*/