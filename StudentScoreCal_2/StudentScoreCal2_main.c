//My code
//#include <stdio.h>
//#define MAX_STUDENT 30
//#define MAX_NAMELENGTH 12
//
//void InputStudentScores(char[][MAX_NAMELENGTH],int, int[], int [], int []);
//void ShowStudentList(char[][MAX_NAMELENGTH],int,int[],int[],int[]);
//
//int main(void)
//{
//	int menuInput = 0;
//	char student[MAX_STUDENT][MAX_NAMELENGTH] = { 0 };
//	int studentIndex = 0;
//	int kor[MAX_STUDENT] = { 0 };
//	int eng[MAX_STUDENT] = { 0 };
//	int math[MAX_STUDENT] = { 0 };
//
//	while (1)
//	{
//		printf("STUDENT SCORE MANAGER\n");
//		printf("1.new student data\n");
//		printf("2.list\n");
//		printf("3.quit\n");
//		printf("select : ");
//		scanf_s("%d", &menuInput);
//		if (menuInput == 3) 
//			break;
//		switch (menuInput)
//		{
//		case 1:
//			InputStudentScores(student, studentIndex, kor, eng, math);
//			studentIndex++;
//			break;
//		case 2:
//			ShowStudentList(student, studentIndex, kor, eng, math);
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}
//
//void InputStudentScores(char student[][MAX_NAMELENGTH],int studentIndex, int kor[], int eng[], int math[])
//{
//	printf("\n");
//	printf("please input student's info.\n");
//	printf("%d student name : ", studentIndex + 1);
//	scanf_s("%s", &student[studentIndex], MAX_NAMELENGTH);
//	printf("\n");
//	printf("%s's Kor Score : ", student[studentIndex]);
//	scanf_s("%d", &kor[studentIndex]);
//	printf("\n");
//	printf("%s's Eng Score : ", student[studentIndex]);
//	scanf_s("%d", &eng[studentIndex]);
//	printf("\n");
//	printf("%s's Math Score : ", student[studentIndex]);
//	scanf_s("%d", &math[studentIndex]);
//	printf("\n");
//
//}
//
//void ShowStudentList(char student[][MAX_NAMELENGTH], int studentIndex, int kor[], int eng[], int math[])
//{
//	if (studentIndex == 0)
//	{
//		printf("\n");
//		printf("No students on list\n\n");
//		return;
//	}
//	printf("\n");
//	printf("index \t name \t Kor \t Eng \t Math \t Sum \t Average \n");
//	for (int i = 0; i < studentIndex; i++)
//	{
//		int sum = kor[i] + eng[i] + math[i];
//		float avg = (float)sum / 3;
//		printf("%d \t %s \t %d \t %d \t %d \t %d \t %f \n", i + 1, student[i], kor[i], eng[i], math[i], sum, avg);
//	}
//	printf("\n");
//}


// Guide Code
#include <stdio.h>
#define MAX_COUNT 30
#define NAME_LENGTH 12


// char name[][NAME_LENGTH] == char(*name)[NAME_LENGTH]
// int kor[] == int *kor
void InputData(char name[][NAME_LENGTH], int kor[], int eng[], int math[], int sum[], float avg[], int index)
{
	printf("Input student's info.\n");

	printf("%d's student's name : ", index + 1);	
	//name[index] == &name[index][0]
	scanf_s("%s", name[index], NAME_LENGTH);
	printf("%s's Kor Score : ", name[index]);
	scanf_s("%d", kor + index);
	printf("%s's Eng Score : ", name[index]);
	scanf_s("%d", eng + index);
	printf("%s's Math Score : ", name[index]);
	scanf_s("%d", math + index);

	sum[index] = kor[index] + eng[index] + math[index];
	avg[index] = sum[index] / 3.f;
}

void ShowList(char name[][NAME_LENGTH], int kor[], int eng[], int math[], int sum[], float avg[], int count)
{
	printf("\nindex    name    kor    eng    math    sum    ave\n");
	for (int i = 0; i < count; i++)
	{
		printf("%3d %7s %6d %6d %6d    %5d     %f\n", i + 1, name[i], kor[i], eng[i], math[i], sum[i], avg[i]);
	}
}

int main()
{
	char name[MAX_COUNT][NAME_LENGTH];

	int kor[MAX_COUNT], eng[MAX_COUNT], math[MAX_COUNT];

	int sum[MAX_COUNT];

	float avg[MAX_COUNT];

	int select = 0;

	int count = 0;

	while (select != 3) // quit on select 3, otherwise on loop
	{
		printf("[ MENU ]\n");
		printf("1.Input Score\n");
		printf("2.Show List\n");
		printf("3.Quit\n");
		printf("select : ");

		scanf_s("%d", &select);
		if (select == 1) 
		{
			if (count < MAX_COUNT)
			{
				InputData(name, kor, eng, math, sum, avg, count);
				count++;
			}
		} 
		else if (select == 2)
		{
			ShowList(name, kor, eng, math, sum, avg, count);
		}
		printf("\n");
	}
	return 0;
}
