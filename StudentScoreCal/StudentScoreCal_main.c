//My Code
//
#include <stdio.h>
#define STUDENTCOUNT 5
#define NAMEBUFFERSIZE 12
#define SUBJECTCOUNT 3

enum SUBJECTS
{
	E_Kor,
	E_Eng,
	E_Math
};

int main(void)
{
	int StudentScore[STUDENTCOUNT][SUBJECTCOUNT] = { 0,{0} };
	char StudentName[STUDENTCOUNT][NAMEBUFFERSIZE] = { 0 };

	
	for (int i = 0; i < STUDENTCOUNT; i++)
	{
		printf("input student number %d's name : ",i+1);
		scanf_s("%s",&StudentName[i],NAMEBUFFERSIZE);
		printf("\n");
		for (int j = 0; j < SUBJECTCOUNT;)
		{
			printf("input %s Kor Score :", StudentName[i]);
			scanf_s("%d", &StudentScore[i][j]);
			j++;
			printf("\n");

			printf("input %s Eng Score :", StudentName[i]);
			scanf_s("%d", &StudentScore[i][j]);
			j++;
			printf("\n");

			printf("input %s Math Score :", StudentName[i]);
			scanf_s("%d", &StudentScore[i][j]);
			j++;
			printf("\n");
		}
	}
	printf("\n");

	printf("Index \t Name \t Kor \t Eng \t Math \t Total \t Average \n");
	for (int i = 0; i < STUDENTCOUNT; i++)
	{
		int kor = StudentScore[i][E_Kor];
		int Eng = StudentScore[i][E_Eng];
		int Math = StudentScore[i][E_Math];
		int Total = kor + Eng + Math;
		float average = (float)Total/SUBJECTCOUNT;
		printf("%d \t %s \t %d \t %d \t %d \t %d \t %f \n", i+1, StudentName[i], kor, Eng, Math, Total, average);
	}

	return 0;
}



// Guide code
//https://blog.naver.com/tipsware/221578822051
//#include <stdio.h> // To use printf, scanf_s
//
//// Max student count
//#define MAX_COUNT 5
//
//// Max student name length
//#define NAME_LENGTH 12
//
//int main(void)
//{
//	char name[MAX_COUNT][NAME_LENGTH]; // 5 student's name's storage
//	
//	int kor[MAX_COUNT], eng[MAX_COUNT], math[MAX_COUNT]; // each student's kor, eng, math score's storage
//	
//	int sum[MAX_COUNT]; // each student's sum of all scores
//
//	float avg[MAX_COUNT]; // each student's average score's storage
//
//	printf("input student's info.");
//	for (int i = 0; i < MAX_COUNT; i++)
//	{
//		printf("%d's student's name : ", i + 1);
//		scanf_s("%s", name[i], NAME_LENGTH); // name[i] == &name[i][0]
//		printf("%s's Kor score : ", name[i]);
//		scanf_s("%d", kor + i); // kor + i == &kor[i]
//		printf("%s's Eng score : ", name[i]);
//		scanf_s("%d", eng + i); // eng + i == &eng[i]
//		printf("%s's Math score : ", name[i]);
//		scanf_s("%d", math + i); // math + i == &math[i]
//	}
//
//	// sum and average
//	for (int i = 0; i < MAX_COUNT; i++)
//	{
//		sum[i] = kor[i] + eng[i] + math[i];
//		avg[i] = sum[i] / 3.f;
//	}
//
//	// printing
//	printf("\n index    name    kor    eng    math    sum    avg\n");
//	for (int i = 0; i < MAX_COUNT; i++)
//	{
//		printf("%3d %7s %6d %6d %6d    %5d    %f\n", i + 1, name[i], kor[i], eng[i], math[i], sum[i], avg[i]);
//	}
//	return 0;
//}