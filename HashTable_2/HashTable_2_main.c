/*

HashTable_2

Open Addressing
Binary Search
*/

#define VALUE_MAX 30
#define KEY_MAX 50
#define BUCKET_FIRST_MAX 20
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct _tagBucket
{
	char key[KEY_MAX]; //compare later when hash collision
	char value[VALUE_MAX];
} Bucket;


size_t HashFunc(char* key, size_t bucket_max);
void Insert(Bucket* buckets, size_t capacity);
void Display(Bucket* buckets, size_t capacity);
void Update(Bucket* buckets, size_t capacity);
bool Search(Bucket* buckets, Bucket** targetBucket, char* key, size_t capacity);
void Remove(Bucket* buckets, size_t capacity);
Bucket* InitHashTable(size_t tableSize);
void Find(Bucket* buckets, size_t capacity);


int main(void)
{
	//char buckets[BUCKET_FIRST_MAX][VALUE_MAX] = { 0 };
	size_t capacity = BUCKET_FIRST_MAX;
	size_t currentSize = 0;
	bool onLoop = true;
	size_t input = 0;
	Bucket* buckets = InitHashTable(BUCKET_FIRST_MAX);


	//Dummy data
	/*
	char dummy_key[][KEY_MAX] =
	{
		"aba",
		"abb",
		"abc",
		"abd",
		"abe",
		"abf",
		"abg",
		"abh",
		"abi",
		"abj",
		"abk",
		"abl",
		"abm",
		"abn",
		"abo",
		"abp",
		"abq",
		"abr",
		"abs",
		"abt"
	};

	char dummy_value[][KEY_MAX] =
	{
		"aba",
		"abb",
		"abc",
		"abd",
		"abe",
		"abf",
		"abg",
		"abh",
		"abi",
		"abj",
		"abk",
		"abl",
		"abm",
		"abn",
		"abo",
		"abp",
		"abq",
		"abr",
		"abs",
		"abt"
	};



	for (size_t i = 0; i < BUCKET_FIRST_MAX; i++)
	{
		strcpy_s(buckets[i].key, VALUE_MAX, dummy_key[i]);
		strcpy_s(buckets[i].value, VALUE_MAX, dummy_value[i]);
	}
	*/

	while (onLoop)
	{
		rewind(stdin);
		printf("\n");
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Update\n");
		printf("4.Remove\n");
		printf("5.Find\n");
		printf("0.Quit\n");
		printf(">>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			Insert(buckets,capacity);
			break;
		case 2:
			Display(buckets,capacity);
			break;
		case 3:
			Update(buckets,capacity);
			break;		
		case 4:
			Remove(buckets, capacity);
			break;
		case 5:
			Find(buckets, capacity);
			break;
		case 0:
			onLoop = false;
			break;
		default:
			break;
		}
	}

	free(buckets);
	return 0;
}


Bucket* InitHashTable(size_t tableSize)
{
	Bucket* newBuckets = (Bucket*)calloc(tableSize, sizeof(Bucket));
	return newBuckets;
}


void Find(Bucket* buckets, size_t capacity)
{
	rewind(stdin);
	char key[KEY_MAX] = { 0 };
	Bucket* targetBucket = NULL;
	size_t index = 0;
	printf("\nInput key to find value\n>>");
	scanf_s("%[^\n]%*c", key, KEY_MAX);
	if (Search(buckets, &targetBucket ,key, capacity) == false || targetBucket == NULL)
	{
		printf("Can't find value");
		return;
	}
	else
	{
		printf("\nFound value : %s", targetBucket->value);
	}
}




size_t HashFunc(char* key, size_t bucket_max)
{
	size_t index = 0;
	for (size_t i = 0; i < strlen(key); i++)
	{
		index += key[i];
	}
	return index % bucket_max;
}



void Insert(Bucket* buckets,size_t capacity)
{
	rewind(stdin);
	char key[KEY_MAX] = { 0 };
	char value[VALUE_MAX] = { 0 };
	size_t index = 0;
	printf("\nInput key\n>>");
	scanf_s("%[^\n]%*c", key, KEY_MAX);
	index = HashFunc(key, capacity);
	while (1)
	{
		if (strlen(buckets[index].value) == 0) // value is empty on bucket
			break;
		else if (strcmp(buckets[index].key, key) == 0)
		{
			printf("Key is already used, use another key");
			return;
		}
		index++;
	}
	rewind(stdin);
	printf("\nInput value\n>>");
	scanf_s("%[^\n]%*c", value, VALUE_MAX);
	strcpy_s(buckets[index].key, KEY_MAX, key);
	strcpy_s(buckets[index].value, VALUE_MAX, value);
	printf("\nData Inserted\n");
}

void Display(Bucket* buckets,size_t capacity)
{
	printf("\ncapacity : %d\n", capacity);
	printf("\nindex\tkey\tvalue\n");
	for (size_t i = 0; i < capacity; i++)
		printf("%d\t%s\t%s\n", i, buckets[i].key,buckets[i].value);
	
}

void Update(Bucket* buckets, size_t capacity)
{
	rewind(stdin);
	char key[KEY_MAX] = { 0 };
	char newValue[VALUE_MAX] = { 0 };
	Bucket* targetBucket = NULL;
	size_t index = 0;
	printf("\nInput key to find value\n>>");
	scanf_s("%[^\n]%*c", key, KEY_MAX);
	if (Search(buckets, &targetBucket, key, capacity) == false)
	{
		printf("Can't find value");
		return;
	}
	rewind(stdin);
	printf("\nInput new value\n>>");
	scanf_s("%[^\n]%*c", newValue, VALUE_MAX);
	strcpy_s(targetBucket->value, VALUE_MAX, newValue);

}

bool Search(Bucket* buckets, Bucket** targetBucket, char* key, size_t capacity)
{
	size_t tryCount = 0;
	//Selection search
	size_t index = HashFunc(key,capacity);
	
	for (size_t i = index; i < capacity; i++)
	{
		printf("\nselection search try %d\n", ++tryCount);
		if (strcmp(buckets[i].key, key) == 0)
		{
			*targetBucket = &buckets[i];
			return true;
		}
	}


	//Binary Search
	size_t startIndex = 0;
	size_t endIndex = capacity - 1;
	size_t middleIndex = startIndex + ((size_t)(endIndex * 0.5f));
	while(startIndex <= endIndex) 
	{
		printf("\nbinary search try %d\n", ++tryCount);
		int compare = strcmp(buckets[middleIndex].key, key);
		switch (compare)
		{
		case 0:
			*targetBucket = &buckets[middleIndex];
			return true;
			break;
		case 1:
			endIndex = middleIndex - 1;
			break;
		case -1:
			startIndex = middleIndex + 1;
			break;
		default:
			middleIndex++;
			break;
		}
		middleIndex = (size_t)(startIndex + (endIndex - startIndex) * 0.5f);
	}



	return false;
}

void Remove(Bucket* buckets, size_t capacity)
{
	rewind(stdin);
	char key[KEY_MAX] = { 0 };
	//char value[VALUE_MAX] = { 0 };
	Bucket* targetBucket = NULL;
	size_t index = 0;
	printf("\nInput key to delete\n>>");
	scanf_s("%[^\n]%*c", key, KEY_MAX);
	char input = 0;
	rewind(stdin);
	if (Search(buckets, &targetBucket, key, capacity) == false || targetBucket == NULL)
	{
		printf("Can't find value");
		return;
	}
	else
	{
		printf("\nFound the value : %s\n", targetBucket->value);
		printf("Are you sure want to delete? y / n\n>>");
		scanf_s("%c", &input, sizeof(char));
		if (input == 'y' || input == 'Y')
		{
			targetBucket->key[0] = '\0';
			targetBucket->value[0] = '\0';
			printf("\nData Deleted\n");
		}
		else
			return;
	}

	
}
