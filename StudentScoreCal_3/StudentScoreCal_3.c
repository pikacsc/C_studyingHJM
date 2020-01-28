// MyCode
#include <stdio.h>
#define MAX_NAMELENGTH 12
#define MAX_STUDENT 30

typedef struct _tagStudent
{
	char name[MAX_NAMELENGTH];
	int kor;
	int eng;
	int math;
} STUDENT;

void RecordStudent(STUDENT*, int);

void ShowStudentList(STUDENT*, int);

int main(void)
{
	int currentStudentCount = 0;

	STUDENT studentArr[MAX_STUDENT] = { 0 };

	int menuSelect = 0;

	// Menu 
	while (menuSelect != 3)
	{
		printf("\n[ STUDENT SCORE MANAGER ]\n");
		printf("1.New Student\n");
		printf("2.List\n");
		printf("3.Quit\n");
		printf("please input number of menu\n");
		printf(":");
		scanf_s("%d", &menuSelect);
		if (menuSelect == 1)
		{
			RecordStudent(studentArr, currentStudentCount);
			currentStudentCount++;
		}
		else if (menuSelect == 2)
		{
			ShowStudentList(studentArr, currentStudentCount);
		}

	}


	return 0;
}

void RecordStudent(STUDENT* arr, int currentStudentCount)
{
	printf("\n\n");
	printf("please input student's info\n");
	printf("number %d student's name : ",currentStudentCount+1);
	scanf_s("%s", (arr + currentStudentCount)->name, MAX_NAMELENGTH);
	printf("\n");
	printf("%s's kor score : ", arr[currentStudentCount].name);
	scanf_s("%d", &(arr + currentStudentCount)->kor);
	printf("\n");
	printf("%s's eng score : ", arr[currentStudentCount].name);
	scanf_s("%d", &(arr + currentStudentCount)->eng);
	printf("\n");
	printf("%s's math score : ", arr[currentStudentCount].name);
	scanf_s("%d", &(arr + currentStudentCount)->math);
}

void ShowStudentList(STUDENT* arr, int currentStudentCount)
{
	if (currentStudentCount == 0)
	{
		printf("\n No Students on list \n");
		return;
	}
	printf("index \t name \t kor \t eng \t math \t sum \t avg \n");
	for (int i = 0; i < currentStudentCount; i++)
	{
		int sum = (arr + i)->kor + (arr + i)->eng + (arr + i)->math;
		float avg = sum / 3.f;
		printf("%d \t ", i+1); 
		printf("%s \t ", (arr + i)->name);
		printf("%d \t ", (arr + i)->kor);
		printf("%d \t ", (arr + i)->eng);
		printf("%d \t ", (arr + i)->math);
		printf("%d \t ", sum);
		printf("%f \t ", avg);
		printf("\n");
	}
}

//
//// Guide Code
//#include <stdio.h> 
//#define MAX_COUNT 30
//#define NAME_LENGTH 12
//
//typedef struct StudentData
//{
//	char name[NAME_LENGTH];
//	int kor, eng, math;
//	int sum;
//	float avg;
//} SD;
//
//void InputData(SD *ap_user, int index)
//{
//	printf("input student's info.\n");
//
//	printf("%d's student's name : ", index + 1);
//	
//	// users[index].name == &users[index].name[0]
//	scanf_s("%s", ap_user->name, NAME_LENGTH);
//	printf("%s's kor score : ", ap_user->name);
//	scanf_s("%d", &ap_user->kor);
//	printf("%s's eng score : ", ap_user->name);
//	scanf_s("%d", &ap_user->eng);
//	printf("%s's maht score : ", ap_user->name);
//	scanf_s("%d", &ap_user->math);
//
//	ap_user->sum = ap_user->kor + ap_user->eng + ap_user->math;
//	ap_user->avg = ap_user->sum / 3.f;
//}
//
//void ShowList(SD *ap_user, int count)
//{
//	printf("\nindex     name     kor     eng     math     sum      avg\n");
//	for (int i = 0; i < count; i++)
//	{
//		printf("%3d %7s %6d %6d %6d    %5d     %f\n",
//			i + 1, ap_user->name, ap_user->kor, ap_user->eng, ap_user->math,
//			ap_user->sum, ap_user->avg);
//		ap_user++;
//	}
//}
//
//int main()
//{
//	SD users[MAX_COUNT];
//	int select = 0, count = 0;
//
//	while (select != 3)
//	{
//		printf("[ MENU ]\n");
//		printf("1.Add Student\n");
//		printf("2.List\n");
//		printf("3.Quit\n");
//		printf("select : ");
//
//		scanf_s("%d", &select);
//		if (select == 1)
//		{
//			if (count < MAX_COUNT)
//			{
//				InputData(users, count);
//				count++;
//			}
//		}
//		else if (select == 2)
//		{
//			ShowList(users, count);
//		}
//		printf("\n");
//	}
//	return 0;
//}



