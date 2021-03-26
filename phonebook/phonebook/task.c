#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pushDataToFile(char* const path, char* const name, char* const number)
{
	FILE* file = fopen(path, "a+");

	if (file == NULL)
	{
		return;
	}

	fprintf(file, "%s   ", name);
	fprintf(file, "%s\n", number);

	fclose(file);
}

void printDataFromFile(char* const path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		return;
	}

	while (!feof(file))
	{
		char symbol = fgetc(file);
		printf("%c", symbol);
	}
}

char* findNumberByName(char const* name, char* const path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		return;
	}

	while (!feof(file))
	{
		char* string = (char*)malloc(sizeof(char));
		char* number = (char*)malloc(sizeof(char));
		fscanf(file, "%s", string);

		if (!strcmp(name, string))
		{
			fscanf(file, "%s", number);
			return number;
		}
	}
}

char* findNameByNumber(char const* number, char* const path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		return;
	}

	char* currentNumber = (char*)malloc(sizeof(char));
	char* currentName = (char*)malloc(sizeof(char));

	while (!feof(file))
	{
		fscanf(file, "%s", currentName);
		fscanf(file, "%s", currentNumber);

		if (!strcmp(currentNumber, number))
		{
			return currentName;
		}
	}
}

void saveDataToFile(char* const path, char* const pathToSave)
{
	FILE* file = fopen(path, "r");
	FILE* fileToSave = fopen(pathToSave, "w+");

	if (file == NULL)
	{
		return;
	}

	if (fileToSave == NULL)
	{
		return;
	}

	while (!feof(file))
	{
		char symbol = fgetc(file);

		if ((int)symbol != -1)
		{
			fprintf(fileToSave, "%c", symbol);
		}
	}
}

void output()
{
	printf("0 - exit\n");
	printf("1 - add data to file\n");
	printf("2 - printf data from file\n");
	printf("3 - find number by name\n");
	printf("4 - find name by number\n");
	printf("5 - save data to file\n");
}