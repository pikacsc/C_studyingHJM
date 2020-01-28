//MyCode
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#define NAME_LENGTH 32
//#define MAX_STUDENT 30
//
//typedef struct StudentData
//{
//	int num; 
//	char* p_name;
//	int kor, eng, math;
//	int sum;
//	float avg;
//} SD;
//
//void RecordStudent(SD*, int);
//
//void ShowStudentList(SD* , int);
//
//void Release(SD*,int );
//
//int main(void)
//{
//	int currentStdCount = 0, menuSelect = 0;
//
//	SD* stdPtr = NULL;
//
//	stdPtr = (SD*)malloc(MAX_STUDENT*sizeof(SD));
//
//	while (menuSelect != 3)
//	{
//		printf("[ STUDENT SCORE MANAGER ]\n");
//		printf("1.Add Student\n");
//		printf("2.Show Student List\n");
//		printf("3.Quit\n");
//		printf("select : ");
//		scanf_s("%d", &menuSelect);
//		if (menuSelect == 1)
//		{
//			RecordStudent(stdPtr, currentStdCount);
//			currentStdCount++;
//		}
//		else if (menuSelect == 2)
//		{
//			ShowStudentList(stdPtr, currentStdCount);
//		}
//
//	}
//
//
//	Release(stdPtr,currentStdCount);
//
//
//	return 0;
//}
//
//void RecordStudent(SD* stdPtr, int currentStdCount)
//{
//	int inputNameSize = 0;
//	SD newStd = { 0 };
//	char tempStr[NAME_LENGTH];
//
//
//	printf("please input student info.\n");
//	printf("student number : ");
//	scanf_s("%d", &newStd.num);
//	printf("\n");
//	
//	printf("name : ");
//	scanf_s("%s", tempStr,NAME_LENGTH);
//	int realNameSize = strlen(tempStr) + 1;
//	newStd.p_name = (char*)malloc(realNameSize);
//	memcpy(newStd.p_name, tempStr, realNameSize);
//	printf("\n");
//	printf("student's kor score : ");
//	scanf_s("%d", &newStd.kor);
//	printf("\n");
//	printf("student's eng score : ");
//	scanf_s("%d", &newStd.eng);
//	printf("\n");
//	printf("student's math score : ");
//	scanf_s("%d", &newStd.math);
//	printf("\n");
//
//	newStd.sum = newStd.kor + newStd.eng + newStd.math;
//	newStd.avg = (newStd.sum) / 3.f;
//
//	stdPtr[currentStdCount] = newStd;
//
//}
//
//void ShowStudentList(SD* stdPtr,int currentStdCount)
//{
//	printf("\n");
//	printf("number \t name \t kor \t eng \t math \t sum \t average \n");
//	for (int i = 0; i < currentStdCount; i++)
//	{
//		printf("%d \t ", stdPtr[i].num);
//		printf("%s \t ", stdPtr[i].p_name);
//		printf("%d \t ", stdPtr[i].kor);
//		printf("%d \t ", stdPtr[i].eng);
//		printf("%d \t ", stdPtr[i].math);
//		printf("%d \t ", stdPtr[i].sum);
//		printf("%f \n ", stdPtr[i].avg);
//	}
//	printf("\n");
//}
//
//void Release(SD* stdPtr,int currentStdCount)
//{
//	SD* stdPtr_end = stdPtr + currentStdCount;
//
//	while (stdPtr < stdPtr_end) 
//	{
//		free(stdPtr->p_name);
//		stdPtr++;
//	}
//}

//Guide Code
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX_COUNT 30
#define NAME_LENGTH 32

typedef struct StudentData
{
	int num;
	char* p_name;
	int kor, eng, math;
	int sum;
	float avg;
} SD;

void InputData(SD* ap_user)
{
	char temp[NAME_LENGTH];
	printf("please input student info.\n");

	printf("student number : ");
	scanf_s("%d", &ap_user->num);
	printf("\n");
	printf("name : ");
	scanf_s("%s", temp, NAME_LENGTH);
	int len = strlen(temp) + 1;
	ap_user->p_name = (char*)malloc(len);
	memcpy(ap_user->p_name, temp, len);

	printf("Kor score : ");
	scanf_s("%d", &ap_user->kor);
	printf("Eng score : ");
	scanf_s("%d", &ap_user->eng);
	printf("Math score : ");
	scanf_s("%d", &ap_user->math);

	ap_user->sum = ap_user->kor + ap_user->eng + ap_user->math;
	ap_user->avg = ap_user->sum / 3.f;
}

void ShowList(SD* ap_user, int count)
{
	printf("\n index     name     kor     eng     math     sum     avg \n");
	SD* p_end_user = ap_user + count;

	while (ap_user < p_end_user)
	{
		printf("%5d %8.8s %6d %6d %6d    %5d      %f\n",
			ap_user->num, ap_user->p_name, ap_user->kor,
			ap_user->eng, ap_user->math, ap_user->sum, ap_user->avg);
		ap_user++;
	}
	
}

void DeleteData(SD* ap_user, int count)
{
	SD* p_end_user = ap_user + count;
	while (ap_user < p_end_user)
	{
		free(ap_user->p_name);
		ap_user++;
	}
}


int main(void)
{
	SD users[MAX_COUNT];

	int select = 0, count = 0;

	while (select != 3)
	{
		printf("[ MENU ]\n");
		printf("1.Add Student\n");
		printf("2.Show List\n");
		printf("3.Quit\n");
		printf("Select : ");

		scanf_s("%d", &select);
		if (select == 1)
		{
			if (count < MAX_COUNT)
			{
				InputData(users + count);
				count++;
			}
		}
		else if (select == 2)
		{
			ShowList(users, count);
		}
		printf("\n");
	}

	DeleteData(users, count);
	return 0;
}