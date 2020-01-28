#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define TMAX 40

typedef struct
{
	char character[TMAX];
	char name[TMAX];
} Item;

void print_items_array(Item items[], int size);

int compare_items(const void* first, const void* second);

const Item* sequential_search(const Item items[], const int size, const char name[TMAX]);
const Item* binary_search(const Item items[], const int size, const char character[TMAX]);

int main()
{
	/* Assume that there is no duplicated items */

	Item itemArr[] = {
	   {"Iron Man", "Tony Stark"},
	   {"Thor", "Thor Odinson"},
	   {"Ant-Man", "Hank Pym"},
	   {"Wasp", "Janet van Dyne"},
	   {"Hulk", "Bruce Banner"},
	   {"Captain America", "Steve Rogers"},
	   {"Scarlet Witch", "Wanda Maximoff"},
	   {"Black Widow", "Natasha Romanoff"},
	   {"Dr. Strange", "Stephen Strange"},
	   {"Daredevil", "Matthew Murdock"},
	   {"Punisher", "Frank Castle"},
	   {"Batman", "Bruce Wayne"}
	};


	int n = sizeof(itemArr) / sizeof(itemArr[0]);

	print_items_array(itemArr, n);

	qsort(itemArr, n, sizeof(Item), compare_items);

	print_items_array(itemArr, n);


	while (1)
	{
		char key[TMAX] = "";
		printf("Input character(key)>> ");

		fgets(key, TMAX, stdin);
		if ((strlen(key) > 0) && (key[strlen(key) - 1] == '\n'))
			key[strlen(key) - 1] = '\0';

		if (strcmp(key, "exit") == 0)
			break;

		/*const Item* found = sequential_search(itemArr, n, key);*/
		const Item * found = binary_search(itemArr, n, key);

		if (found == NULL)
			printf("Not in the list.\n\n");
		else
			printf("%s is %s\n\n", found->character, found->name);


	}

	return 0;
}

void print_items_array(Item items[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s ( %s )\n", items[i].character, items[i].name);
	}
	printf("\n");
}

int compare_items(const void* first, const void* second)
{
	Item firstItem = *(Item*)first;
	Item SecondItem = *(Item*)second;

	return strcmp(firstItem.character, SecondItem.character);
}

const Item* sequential_search(const Item items[], const int size, const char name[TMAX])
{
	int i = 0;
	int trycount = 0;
	int middleIdx = 0;
	for (; i < size; i++)
	{
		printf("try: %d, %s %s\n", trycount, items[middleIdx].name, name);
		if (!strcmp(items[i].name, name))
		{
			return &items[i];
		}
	}


	return NULL;
}
//MyCode
/*
const Item* binary_search(const Item items[], const int size, const char character[TMAX])
{
	// Make it half, compare with middle one
	int trycount = 0;
	Item* found = NULL;
	int first = 0;
	int middleIdx = 0;
	int last = size - 1;
	short result = 0;
	while (middleIdx < size)
	{
		trycount++;
		middleIdx = (int)((first + last) * 0.5);
		printf("try %d, index %d, %s %s\n", trycount, middleIdx, items[middleIdx].character, character);
		result = strcmp(items[middleIdx].character,
			character);
		switch (result)
		{
		case 0:
			return &items[middleIdx];
			break;
		case 1:
			last = middleIdx;
			break;
		case -1:
			first = middleIdx;
			break;
		default:
			break;
		}
	}

	return found;
}
*/

const Item* binary_search(const Item items[], const int size, const char character[TMAX])
{
	int first = 0;
	int last = size - 1;
	int middle = (first + last) / 2;

	while (first <= last)
	{
		int comp = strcmp(items[middle].character, character);

		if (comp < 0)
			first = middle + 1;
		else if (comp == 0)
		{
			return &items[middle];
		}
		else
			last = middle - 1;
		middle = (first + last) / 2;
	}

	return NULL;
}
