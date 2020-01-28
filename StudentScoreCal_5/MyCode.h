#pragma once

typedef struct StudentData
{
	int num;
	char* p_name;
	int kor, eng, math;
	int sum;
	float avg;
	struct StudentData* p_next;
} SD;

void AddStudent(SD*, int);

void ShowStudentList(SD*, int);

void DeleteData(SD* pfirstSD);