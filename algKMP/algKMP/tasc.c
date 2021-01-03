#include "KMP.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int task()
{
	char inputString[100];
	scanf("%s", inputString);
	FILE* inputFile = fopen("text.txt", "r");

	if (inputFile == NULL)
	{
		printf("file is empty");
		return;
	}
	
	int position = 0;

	while (!feof(inputFile))
	{
		int currentPosition = 0;
		char string[100];
		fscanf(inputFile, "%s", string);

		if (algoritm(string, inputString, &currentPosition))
		{
			position += currentPosition;
			return position - strlen(inputString);
		}
		else
		{
			position += strlen(string);
		}
	}

	return -1;
}