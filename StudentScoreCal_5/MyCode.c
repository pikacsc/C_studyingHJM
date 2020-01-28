#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "MyCode.h"


#define NAME_LENGTH 30

void AddStudent(SD* pSD, int currentStudentCount)
{
	char strBuffer[NAME_LENGTH] = { 0 };
	printf("please input student info\n");
	printf("student number : ");
	scanf_s("%d", &pSD->num);

	printf("name : ");
	scanf_s("%s", strBuffer, NAME_LENGTH);
	int length = strlen(strBuffer) + 1;
	pSD->p_name = (char*)malloc(length);
	memcpy(pSD->p_name, strBuffer, length);

	printf("kor score : ");
	scanf_s("%d", &pSD->kor);

	printf("eng score : ");
	scanf_s("%d", &pSD->eng);

	printf("math score : ");
	scanf_s("%d", &pSD->math);

	pSD->sum = pSD->kor + pSD->eng + pSD->math;
	pSD->avg = pSD->sum / 3.f;


	pSD->p_next = NULL;

}

void ShowStudentList(SD* pfirstSD, int currentStudentCount)
{
	if (!pfirstSD) return;
	SD* firstSD = pfirstSD;
	printf("index \t name \t kor \t eng \t math \t sum \t avg \n");
	while (firstSD)
	{
		printf("%d \t ", firstSD->num);
		printf("%s \t ", firstSD->p_name);
		printf("%d \t ", firstSD->kor);
		printf("%d \t ", firstSD->eng);
		printf("%d \t ", firstSD->math);
		printf("%d \t ", firstSD->sum);
		printf("%f \t ", firstSD->avg);
		printf("\n");
		firstSD = firstSD->p_next;
	}
}

void DeleteData(SD* pfirstSD)
{
	/*
	SD* SecondSD = NULL;
	while (pfirstSD)
	{
		SecondSD = pfirstSD;
		pfirstSD = pfirstSD->p_next;
		free(SecondSD->p_name);
		free(SecondSD);
	}
	*/
	SD* SecondSD = NULL;
	while (pfirstSD)
	{
		SecondSD = pfirstSD->p_next;
		free(pfirstSD->p_name);
		free(pfirstSD);
		pfirstSD = SecondSD;
	}
}
