#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utilities.h"
#include <stdbool.h>

void changeIfFirstZero(char* number);

void sort(char* number);

void task(char* number)
{
	if (!isNumber(number))
	{
		printf("number is incorrect\n");

		return;
	}

	sort(number);

	if (number[0] == '0')
	{
		changeIfFirstZero(number);
	}
}

void changeIfFirstZero(char* number)
{
	int counter = 1;

	while (number[counter] == '0')
	{
		++counter;
	}

	swap(&number[0], &number[counter]);
}

void sort(char* number)
{
	int const length = strlen(number);

	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - 1; ++j)
		{
			if (number[j] > number[j + 1])
			{
				swap(&number[j], &number[j + 1]);
			}
		}
	}

	return number;
}