/*
HashTable_1 

basic version

no duplicate exception 
using array

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define VALUE_LENGTH 30
#define TABLE_MAX 10
#define KEY_MAX 30

size_t HashFunc(char* key);

void Insert(char(*Buckets)[VALUE_LENGTH]);
void Display(char(*Buckets)[VALUE_LENGTH]);
void Update(char(*Buckets)[VALUE_LENGTH]);
bool Search(char* pValue, size_t* pIndex, char(*Buckets)[VALUE_LENGTH]);
void Remove(char(*Buckets)[VALUE_LENGTH]);

int main(void)
{
	char buffer[VALUE_LENGTH] = { 0 };
	char Buckets[TABLE_MAX][VALUE_LENGTH] = { 0, };
	int count = 0;
	int input = 0;
	bool onloop = true;
	char* findBuffer = NULL;
	while (onloop)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Update\n");
		printf("4.Remove\n");
		printf("5.Find\n");
		printf("0.Quit\n");
		printf("Input menu number\n>>");
		scanf_s("%d", &input);
		rewind(stdin);
		switch (input)
		{
		case 1:
			Insert(Buckets);
			break;
		case 2:
			Display(Buckets);
			break;
		case 3:
			Update(Buckets);
			break;
		case 4:
			Remove(Buckets);
			break;
		case 5:
			if (Search(buffer,NULL,Buckets) == true)
				printf("\nFound it! value : %s\n", buffer);
			else
				printf("\nNo value found\n");
			findBuffer = NULL;
			break;
		case 0:
			onloop = false;
			break;
		default:
			break;
		}

	}

	return 0;
}

size_t HashFunc(char* key)
{
	size_t index = 0;
	for (size_t i = 0; i < strlen(key); i++)
	{
		index += key[i];
	}
	return index % TABLE_MAX;
}

void Insert(char (*Buckets)[VALUE_LENGTH])
{
	char key[KEY_MAX] = { 0 };
	char value[VALUE_LENGTH] = { 0 };
	printf("\nPlease input key\n>> ");
	scanf_s("%[^\n]%*c", key, KEY_MAX);
	rewind(stdin);
	printf("\nPlease input value\n>> ");
	scanf_s("%[^\n]%*c", value, VALUE_LENGTH);
	size_t index = HashFunc(key);
	strcpy_s(Buckets[index],KEY_MAX, value);
}

void Display(char(*Buckets)[VALUE_LENGTH])
{
	printf("\nIndex\tValue\n");
	for (size_t i = 0; i < TABLE_MAX; i++)
	{
		printf("%d\t%s\n", i, Buckets[i]);
	}
}

void Update(char(*Buckets)[VALUE_LENGTH])
{
	char newValue[VALUE_LENGTH] = { 0 };
	char* oldValue = NULL;
	size_t index = 0;
	bool found = Search(oldValue,&index,Buckets);
	if (found == false)
	{
		printf("\nNo value found can't update value\n");
	}
	else
	{
		printf("\ncurrent value : %s\n", Buckets[index]);
		printf("\ninput new value to update\n>>");
		rewind(stdin);
		scanf_s("%s", newValue, VALUE_LENGTH);
		int err = strcpy_s(Buckets[index], VALUE_LENGTH, newValue);
		if (err == -1)
			printf("\nError : can't update value");
		else
			printf("\nUpdate success\n");
	}

}

bool Search(char *pValue, size_t *pIndex, char(*Buckets)[VALUE_LENGTH])
{
	printf("\nInput key to find value\n>>");
	char key[KEY_MAX] = { 0 };
	rewind(stdin);
	scanf_s("%s", key, KEY_MAX);
	int index = HashFunc(key);
	if (strlen(Buckets[index]) == 0)
	{
		return false;
	}
	else
	{
		if(pValue)
			strcpy_s(pValue,VALUE_LENGTH,Buckets[index]);
		if(pIndex)
			*pIndex = index;
		return true;
	}
}

void Remove(char(*Buckets)[VALUE_LENGTH])
{
	char yn = 0;
	char* value = NULL;
	size_t index = 0;
	bool found = Search(value, &index, Buckets);
	if (found == false)
	{
		printf("\nNo value found can't remove value\n");
	}
	else
	{
		printf("\ncurrent value : %s\n", Buckets[index]);
		printf("\nAre you sure want to delete? input y or n\n>>");
		rewind(stdin);
		scanf_s("%c", &yn, sizeof(char));
		if (yn == 'y')
		{
			Buckets[index][0] = '\0';
			printf("\nRemove Success\n");
		}
	}
}
