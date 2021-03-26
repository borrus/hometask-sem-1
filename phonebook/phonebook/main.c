#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main()
{
	if (!tests())
	{
		return;
	}

	int temp = -1;
	printf("options:\n");
	output();

	while (temp != 0)
	{
		scanf("%d", &temp);

		if (temp == 1)
		{
			char* path = (char*)malloc(sizeof(char));
			printf("input path:\n");
			scanf("%s", path);

			char* name = (char*)malloc(sizeof(char));
			printf("input name:\n");
			scanf("%s", name);
			char* number = (char*)malloc(sizeof(char));
			printf("input number:\n");
			scanf("%s", number);
			pushDataToFile(path, name, number);
			printf("data has been added\n\n");
		}

		if (temp == 2)
		{
			char* path = (char*)malloc(sizeof(char));
			printf("input path:\n");
			scanf("%s", path);
			printDataFromFile(path);
		}

		if (temp == 3)
		{
			char name[20];
			printf("input name\n");
			char* path = (char*)malloc(sizeof(char));
			printf("input path:\n");
			scanf("%s", path);
			scanf("%s", name);
			findNumberByName(name, path);
		}

		if (temp == 4)
		{
			char* path = (char*)malloc(sizeof(char));
			printf("input path:\n");
			scanf("%s", path);
			char number[20];
			printf("input number\n");
			scanf("%s", number);
			findNameByNumber(number, path);
		}

		if (temp == 5)
		{
			char* path = (char*)malloc(sizeof(char));
			printf("input path:\n");
			scanf("%s", path);
			char* pathToSave = (char*)malloc(sizeof(char));
			printf("input path to save:\n");
			scanf("%s", path);
			saveDataToFile(path, pathToSave);
		}
	}

}
