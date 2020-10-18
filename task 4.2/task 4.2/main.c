#include <stdio.h>
#include "Sort.h"

int theMostCommonArrayElement()
{
	int temp = 0;
	int i = 0;
	int length = 0;
	FILE* file = fopen("fileArray.txt", "r");

	if (file == NULL)
	{
		printf("file is not found");
		return;
	}

	if (!feof(file))
	{
		if (!fscanf(file, "%d", &length))
		{
			return -50;
		}
	}

	int* array = (int*)malloc(sizeof(int) * length);

	while (!feof(file))
	{
		if (!fscanf(file, "%d", &array[i]))
		{
			return -50;
		}
		++i;
	}

	fclose(file);
	qsortRecursive(array, length);
	
	int counter = 0;
	int max = -1;
	int number = 0;
	int currentNumber = 0;

	for (int i = 0; i < length - 1; ++i)
	{
		if (array[i] == array[i + 1])
		{
			++counter;
			++currentNumber;
		}

		else
		{
			if (counter > max)
			{
				max = counter;
				number = currentNumber;
			}
			counter = 0;
		}
	}

	return array[number];
}

int main()
{
	printf("%d",theMostCommonArrayElement());

	return  0;
}