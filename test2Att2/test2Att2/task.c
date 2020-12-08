#include "list.h"
#include <stdio.h>

void readFromFile(const char* fileName, List* list)
{
	FILE* file = fopen(fileName, "r");
	
	if (file == NULL)
	{
		printf("file is not found");
		return;
	}

	int current = 0;

	while (!feof(file))
	{
		fscanf(file, "%d", &current);

		if (fgetc(file) == ' ')
		{
			push(list, current);
			current = 0;
		}
	}

	fclose(file);
}