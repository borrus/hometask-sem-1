#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool equalStrings(char const* first, char const* second)
{
	if (strlen(first) != strlen(second))
	{
		return false;
	}

	for (int i = 0; i < strlen(first); ++i)
	{
		if (first[i] != second[i])
		{
			return false;
		}
	}

	return true;
}

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

	fclose(file);
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
		char* string = (char*)malloc(sizeof(char) * 100);
		char* number = (char*)malloc(sizeof(char) * 100);

		if (string == NULL)
		{
			return NULL;
		}

		if (number == NULL)
		{
			return NULL;
		}

		fscanf(file, "%s", string);

		if (equalStrings(name, string))
		{
			fscanf(file, "%s", number);
			printf("%s\n", number);

			return number;
		}

		free(string);
		free(number);
	}

	fclose(file);
}

char* findNameByNumber(char const* number, char* const path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		return;
	}

	char* currentNumber = (char*)malloc(sizeof(char) * 100);
	char* currentName = (char*)malloc(sizeof(char) * 100);

	if (currentName == NULL)
	{
		return NULL;
	}

	if (currentNumber == NULL)
	{
		return NULL;
	}

	while (!feof(file))
	{
		fscanf(file, "%s", currentName);
		fscanf(file, "%s", currentNumber);

		if (equalStrings(currentNumber, number))
		{
			char* name = (char*)malloc(sizeof(char) * 100);

			if (name == NULL)
			{
				return NULL;
			}

			fscanf(file, "%s", name);
			printf("%s\n", name);

			return name;
		}
	}

	free(currentName);
	free(currentNumber);

	fclose(file);
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

	fclose(file);
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