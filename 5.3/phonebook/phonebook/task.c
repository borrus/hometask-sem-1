#include <stdio.h>
#include <string.h>

void pushDataToFile()
{
	FILE* file = fopen("text.txt", "a+");

	if (file == NULL)
	{
		return;
	}

	printf("input name\n");
	char name[100];
	scanf("%s", name);
	fprintf(file, "%s   ", name);

	printf("input phone number\n");
	char number[100];
	scanf("%s", number);
	fprintf(file, "%s\n", number);
}

void printDataFromFile()
{
	FILE* file = fopen("text.txt", "r");

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

void findNumberByName(char const* name)
{
	FILE* file = fopen("text.txt", "r");

	if (file == NULL)
	{
		return;
	}

	while (!feof(file))
	{
		char string[100];
		char number[100];
		fscanf(file, "%s", string);

		if (!strcmp(name, string))
		{
			fscanf(file, "%s", number);
			printf("%s\n", number);
			return;
		}
	}
}

void findNameByNumber(char const* number)
{
	FILE* file = fopen("text.txt", "r");

	if (file == NULL)
	{
		return;
	}

	char currentNumber[100];
	char currentName[100];

	while (!feof(file))
	{
		fscanf(file, "%s", currentName);
		fscanf(file, "%s", currentNumber);

		if (!strcmp(currentNumber, number))
		{
			printf("%s\n", currentName);
			return;
		}
	}
}

void saveDataToFile()
{
	FILE* file = fopen("text.txt", "r");
	FILE* fileToSave = fopen("save.txt", "w+");

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

void phonebook()
{
	int temp = -1;
	printf("options:\n");
	output();

	while (temp != 0)
	{
		scanf("%d", &temp);

		if (temp == 1)
		{
			pushDataToFile();
			printf("data has been added\n\n");
		}

		if (temp == 2)
		{
			printDataFromFile();
		}

		if (temp == 3)
		{
			char name[20];
			printf("input name\n");
			scanf("%s", name);
			findNumberByName(name);
		}

		if (temp == 4)
		{
			char number[20];
			printf("input number\n");
			scanf("%s", number);
			findNameByNumber(number);
		}

		if (temp == 5)
		{
			saveDataToFile();
		}
	}
}