#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf("tests failed\n");

		return 0 ;
	}

	char* stableNameOfFileToAdd = (char*)malloc(sizeof(char) * 100);
	char* stableNameOfFileToSave = (char*)malloc(sizeof(char) * 100);

	int counterForUser = 0;
	int counterForUserToSave = 0;

	if (stableNameOfFileToAdd == NULL)
	{
		return NULL;
	}

	if (stableNameOfFileToSave == NULL)
	{
		return NULL;
	}

	int temp = -1;
	printf("options:\n");
	output();

	while (temp != 0)
	{
		scanf("%d", &temp);

		if (temp == 1)
		{
			if (counterForUser == 0)
			{
				printf("input path:\n");
				scanf("%s", stableNameOfFileToAdd);
				++counterForUser;
			}

			char* name = (char*)malloc(sizeof(char) * 100);

			if (name == NULL)
			{
				return NULL;
			}

			printf("input name:\n");
			scanf("%s", name);
			char* number = (char*)malloc(sizeof(char) * 100);

			if (number == NULL)
			{
				return NULL;
			}

			printf("input number:\n");
			scanf("%s", number);
			pushDataToFile(stableNameOfFileToAdd, name, number);

			free(name);
			free(number);
			printf("data has been added\n\n");
		}

		if (temp == 2)
		{
			if (counterForUser == 0)
			{
				printf("file is empty\n");

				return 0;
			}

			printDataFromFile(stableNameOfFileToAdd);
		}

		if (temp == 3)
		{
			if (counterForUser == 0)
			{
				printf("file is empty\n");

				return 0;
			}

			char* name = (char*)malloc(sizeof(char) * 100);

			if (name == NULL)
			{
				return NULL;
			}

			printf("input name\n");
			scanf("%s", name);
			findNumberByName(name, stableNameOfFileToAdd);

			free(name);
		}

		if (temp == 4)
		{
			if (counterForUser == 0)
			{
				printf("file is empty\n");

				return 0;
			}

			char* number = (char*)malloc(sizeof(char) * 100);

			if (number == NULL)
			{
				return NULL;
			}

			printf("input number\n");
			scanf("%s", number);
			findNameByNumber(number, stableNameOfFileToAdd);

			free(number);
		}

		if (temp == 5)
		{
			if (counterForUserToSave == 0)
			{
				printf("input path to save:\n");
				scanf("%s", stableNameOfFileToSave);
				++counterForUserToSave;
			}

			saveDataToFile(stableNameOfFileToAdd, stableNameOfFileToSave);
			printf("data has been added\n");
		}
	}

	free(stableNameOfFileToAdd);
	free(stableNameOfFileToSave);
}
