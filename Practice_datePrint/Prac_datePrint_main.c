/*
�Ʒ��� ���� �迭�� ��¥ �������� ������ 5���� ���ڿ��� �־������� �� ��¥�� �߿��� �ֱ� ��¥�� ã�Ƽ� ����Ͻÿ�
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


	// �ִ� �׸��� ��ġ�� ���
	int max_index = 0;

	// ù ��¥�� ���ڷ� ��ȯ�ϰ� �ִ��� �����
	int max = DateToInt(date_list[0]);

	for (int i = 1; i < 5; i++)
	{
		// ��� ��¥�� ���ڷ� ��ȯ
		int temp_num = DateToInt(date_list[i]);
		// ��ȯ�� ������ �ִ��� ��� ������
		if (max < temp_num) 
		{
			max = temp_num;
			max_index = i;
		}
	}


	printf("�ֱ� ��¥ : %s (%d)", date_list[max_index], max);

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
//	printf("�ֱ� ��¥ : %s (%d)", date_list[index], max);
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
			// '-' ���ڴ� �����ϰ� a_date_str[i] ���ڸ� ���ڷ� �����ؼ� �ջ��Ѵ�.
			// �׸��� �ջ��ϱ� ���� date_num�� ����� ���� 10�� ���ؼ� �ڸ����� ������Ų��.
			date_num = date_num * 10 + a_date_str[i] - '0';
		}
	}
	return date_num;
}