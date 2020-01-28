/*
아래와 같이 배열에 날짜 형식으로 구성된 5개의 문자열이 주어졌을때 이 날짜들 중에서 최근 날짜를 찾아서 출력하시오
*/

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATE_LENGTH 11;

int DateToInt(const char date_list[]);

//int DateToInt(char date_list[]);

//void GetRecentDate(char date_list[][12]);

int main(void)
{
	char date_list[5][12] =
	{
		"2014-05-07",
		"2015-02-01",
		"2016-09-16",
		"2013-11-25",
		"2016-01-07"
	};

	int num = 0;
	
	
	
	//printf("%d", DateToInt(date_list[0]));

	//GetRecentDate(date_list);


	// 최댓값 항목의 위치를 기억
	int max_index = 0;

	// 첫 날짜를 숫자로 변환하고 최댓값을 기록함
	int max = DateToInt(date_list[0]);

	for (int i = 1; i < 5; i++)
	{
		// 계속 날짜를 숫자로 변환
		int temp_num = DateToInt(date_list[i]);
		// 변환된 숫자의 최댓값을 계속 갱신함
		if (max < temp_num) 
		{
			max = temp_num;
			max_index = i;
		}
	}


	printf("최근 날짜 : %s (%d)", date_list[max_index], max);

	return 0;
}
//MySolution
//int DateToInt(char *date)
//{
//	int num;
//	char cRegex = '-';
//	char newDate[11] = { 0 };
//	for (int i = 0;  i < 11 ; date++)
//	{
//		if (*date == cRegex)
//			continue;
//		newDate[i++] = *date;
//	}
//	num = atoi(newDate);
//	return num;
//}
//
//void GetRecentDate(char date_list[][12])
//{
//	int max = 0;
//	int index = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		if (max < DateToInt(date_list[i]))
//		{
//			index = i;
//			max = DateToInt(date_list[i]);
//		}
//	}
//	printf("최근 날짜 : %s (%d)", date_list[index], max);
//
//}



//lecture
int DateToInt(const char a_date_str[])
{
	int date_num = 0;

	for (int i = 0; a_date_str[i]; i++) 
	{
		if (a_date_str[i] != '-')
		{
			// '-' 문자는 제외하고 a_date_str[i] 문자를 숫자로 변경해서 합산한다.
			// 그리고 합산하기 전에 date_num에 저장된 값은 10을 곱해서 자릿수를 증가시킨다.
			date_num = date_num * 10 + a_date_str[i] - '0';
		}
	}
	return date_num;
}