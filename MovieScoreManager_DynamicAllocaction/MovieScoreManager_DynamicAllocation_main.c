#define _CRT_SECURE_NO_WARNINGS
//Menu
//Please select an option and press enter.
/*
1. Print all items
2. Print an item
3. Edit an item
4. Add an item
5. Insert an item
6. Delete an item
7. Delete all items
8. save file
9. Search by name
10. quit
*/

//get file name and search file, if no file then error exit(1)
//get movie counts and print "x items have been read from the file"
#define FILENAME "my_movies.txt"
#define FILENAME_LEN 30
#define TITLE_LEN 30
#define MAX_LEN 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tagMovie
{
	char title[TITLE_LEN];
	float score;
} MOVIE;


void menu(const char**);

void printAll(MOVIE* movieArr, int* currentCount);

void SearchMovie(MOVIE* movieArr, int* currentCount);

void EditAnItem(MOVIE* movieArr, int* currentCount);

void printAnItem(MOVIE* movieArr, int* currentCount);

void AddAnItem(MOVIE* movieArr, int* currentCount);

void InsertAnItem(MOVIE** movieArr, int* currentCount);

void DeleteAnItem(MOVIE* movieArr, int* currentCount);

void DeleteAllItem(MOVIE* movieArr, int* currentCount);

void SaveFile(MOVIE* movieArr, int* currentCount);

void getMovieDatas(FILE* fileStem, MOVIE** movieArr, int* currentCount);

int main()
{
	const char* menuStrArr[MAX_LEN] =
	{ "Print all items", "Print an item",
	 "Edit an item", "Add an item",
	 "Insert an item", "Delete an item",
	 "Delete all items","save file",
	 "Search by name","Quit" };

	MOVIE movieArr[MAX_LEN] = { 0, };

	char filename[FILENAME_LEN] = { 0 };
	int menuflag = 1;
	int menuSelect = 0;
	int currentCount = 0;

	printf("Please input file name\n");
	if (!scanf("%[^\n]%*c", filename))
	{
		printf("Error : inputfile name");
		exit(1);
	}

	FILE* fileStream = fopen(filename, "r");
	if (!fileStream)
	{
		printf("error : failed to open file");
		exit(1);
	}
	getMovieDatas(fileStream, movieArr, &currentCount);
	fclose(fileStream);
	while (menuflag)
	{
		menu(menuStrArr);
		if (!scanf("%d", &menuSelect))
		{
			printf("Error : menuSelect");
			exit(1);
		}
		switch (menuSelect)
		{
		case 1:
			printAll(movieArr,
				&currentCount);
			break;
		case 2:
			printAnItem(movieArr,
				&currentCount);
			break;
		case 3:
			EditAnItem(movieArr,
				&currentCount);
			break;
		case 4:
			AddAnItem(movieArr,
				&currentCount);
			break;
		case 5:
			InsertAnItem(movieArr,
				&currentCount);
			break;
		case 6:
			DeleteAnItem(movieArr,
				&currentCount);
			break;
		case 7:
			DeleteAllItem(movieArr,
				&currentCount);
			break;
		case 8:
			SaveFile(movieArr, &currentCount);
			break;
		case 9:
			SearchMovie(movieArr,
				&currentCount);
			break;
		}
		menuSelect = 0;

	}
	fclose(fileStream);
	return 0;
}

void getMovieDatas(FILE* fileStem,
	MOVIE** movieArr, int* currentCount)
{
	/*char buff[100] = { 0 };
	char* pStr = NULL;
	while (!feof(fileStem))
	{
		fgets(movieArr->title, TITLE_LEN, fileStem);
		fgets(buff, 5, fileStem);
		movieArr[*currentCount].score = (float)atof(buff);
		(*currentCount)++;
	}*/

	while (!feof(fileStem))
	{
		(*currentCount)++;
		if (fscanf(fileStem, "%[^\n]%*c", movieArr[(*currentCount)].title) != 1 ||
			fscanf(fileStem, "%f%*c", &movieArr[(*currentCount)].score) != 1)
		{
			printf("Error : Wrong file format.\n");
			exit(1);
		}
	}
	*movieArr = (MOVIE *)malloc(sizeof(MOVIE) * num)
}



// index 0 is dummy data, null item, 
// start from index 1
void printAll(MOVIE* movieArr, int* currentCount)
{
	for (int i = 1; i <= *currentCount; i++)
	{
		printf("%d.%s\n", i, movieArr[i].title);
		printf("%f\n", movieArr[i].score);
	}
};

void printAnItem(MOVIE* movieArr, int* currentCount)
{
	rewind(stdin);
	printf("Input the index of the movie\n");
	int movieIndex = 0;
	int result = scanf("%d", &movieIndex);
	/*if (result == 0);
	{
		printf("Error : wrong input\n");
		return;
	}*/
	if (movieIndex >= *currentCount)
	{
		printf("Error : out of bound\n");
		return;
	}

	if (movieIndex == 0)
	{
		printf("Error : index start from 1 not 0\n");
		return;
	}

	printf("%d.%s\n", movieIndex, movieArr[movieIndex].title);
	printf("%f\n", movieArr[movieIndex].score);


}

void AddAnItem(MOVIE** movieArr, int* currentCount)
{
	rewind(stdin);
	printf("Input Title and press enter : ");
	int newMovieIndex = (*currentCount) + 1;

	if (scanf("%[^\n]%*c", movieArr[newMovieIndex].title) == 0)
	{
		printf("\nError : No input please try again \n");
		return;
	}
	rewind(stdin);
	printf("Input score and press enter : ");
	if (scanf("%f", &movieArr[newMovieIndex].score) == 0)
	{
		printf("\nError : No input please try again \n");
		return;
	}


	*currentCount += 1;

}

void InsertAnItem(MOVIE* movieArr, int* currentCount)
{
	rewind(stdin);
	if (*currentCount == MAX_LEN)
	{
		printf("No more space.\n");
		return;
	}

	printf("Input the index of item to insert \n");

	int inputIndex = 0;

	if (scanf("%d", &inputIndex) == 0)
	{
		printf("Error : No index input, please try again\n");
		return;
	}

	if (inputIndex > * currentCount)
	{
		printf("Error : out of bound\n");
		return;
	}
	rewind(stdin);
	char newMovieTitle[TITLE_LEN] = { 0 };
	float newMovieScore = 0;

	printf("Input title and press enter : ");
	if (scanf("%[^\n]%*c", newMovieTitle) == 0)
	{
		printf("\nError : No input please try again \n");
		return;
	}
	rewind(stdin);
	printf("Input score and press enter : ");
	if (scanf("%f", &newMovieScore) == 0)
	{
		printf("\nError : No input please try again \n");
		return;
	}


	//all data pushing one spot
	int endIndex = *currentCount;
	while (endIndex >= inputIndex)
	{
		memmove(&movieArr[endIndex + 1], &movieArr[endIndex], sizeof(movieArr[endIndex]));
		endIndex--;
	}


	strcpy(movieArr[inputIndex].title, newMovieTitle);
	movieArr[inputIndex].score = newMovieScore;

	(*currentCount)++;
}

void DeleteAnItem(MOVIE * movieArr, int* currentCount)
{
	rewind(stdin);
	printf("Input the index of the movie to delete it \n:");
	int movieIndex = 0;
	scanf("%d", &movieIndex);
	/*if (scanf("%d", &movieIndex) == 0);
	{
		printf("Error : wrong input\n");
		return;
	}*/

	if (movieIndex > * currentCount)
	{
		printf("Error : out of bound\n");
		return;
	}

	int endIndex = *currentCount;
	while (endIndex >= movieIndex + 1)
	{
		memmove(&movieArr[movieIndex], &movieArr[movieIndex + 1], sizeof(movieArr[endIndex]));
		movieIndex++;
	}

	(*currentCount)--;

}

void DeleteAllItem(MOVIE * movieArr, int* currentCount)
{
	int index = 0;
	while (*currentCount >= index + 1)
	{
		memmove(&movieArr[index + 1], &movieArr[index], sizeof(movieArr[index]));
		index++;
	}
	*currentCount = 0;
}

void SaveFile(MOVIE * movieArr, int* currentCount)
{
	char filename[TITLE_LEN] = { 0, };
	printf("Please input filename to write and press Enter.\n:");

	rewind(stdin);
	if (scanf("%[^\n]%*c", filename) == 0)
	{
		printf("Wrong input. Terminating.\n");
		exit(1);
	}

	FILE* fileStream = fopen(filename, "w");

	if (!fileStream)
	{
		printf("Error : Can't open file.\n");
		exit(1);
	}

	for (int i = 1; i <= *currentCount; i++)
	{
		fprintf(fileStream, "%s\n", movieArr[i].title);
		fprintf(fileStream, "%f\n", movieArr[i].score);
	}

	fclose(fileStream);

	printf("%d items have been save to the file,", *currentCount);

}


void SearchMovie(MOVIE * movieArr, int* currentCount)
{

	rewind(stdin);
	printf("Input the title of the movie\n");
	char buff[TITLE_LEN] = { 0, };

	if (scanf("%[^\n]%*c", buff) == 0)
	{
		printf("Error : no input please try again");
		return;
	}

	/*if (scanf("%[^\n]%*c", buff) != 1);
	{
		printf("Error : wrong input");
		return;
	}*/
	printf("\n movie : %s\n", buff);

	int i;
	for (i = 1; i <= *currentCount; i++)
	{
		if (strcmp(movieArr[i].title, buff) == 0)
			printf("%f\n", movieArr[i].score);
	}

}

void EditAnItem(MOVIE * movieArr, int* currentCount)
{
	printf("Input the index of item to edit.\n");
	int movieIndex = 0;
	if (scanf("%d", &movieIndex) == 0)
	{
		printf("Error : No index input, please try again\n");
		return;
	}

	if (*currentCount < movieIndex)
	{
		printf("Error : out of bound");
		return;
	}

	printf("Current Movie Title : %s\n", movieArr[movieIndex].title);
	printf("Current Movie score : %f\n", movieArr[movieIndex].score);

	rewind(stdin);
	printf("Input new Title and press enter : ");
	if (scanf("%[^\n]%*c", movieArr[movieIndex].title) == 0)
	{
		printf("Error : No input, please try again\n");
		return;
	}

	rewind(stdin);
	printf("Input new score and press enter : ");
	if (scanf("%f", &movieArr[movieIndex].score) == 0)
	{
		printf("Error : No input, please try again\n");
		return;
	}
}

void menu(const char** menuStrArr)
{
	printf("\n");
	int i = 0;
	int j = 1;
	while (i < 10)
	{
		printf("%d %s\n", j++, menuStrArr[i++]);
	}
}
