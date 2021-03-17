#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int* prefix(char* substring)
{
	int* array = (int*)malloc(sizeof(int) * strlen(substring));
	array[0] = 0;
	int j = 0;
	int i = 1;

	while (substring[i] != '\0')
	{
		if (substring[i] == substring[j])
		{
			array[i] = j + 1;
			++i;
			++j;
		}

		else if (j == 0)
		{
			array[i] = 0;
			++i;
		}

		else
		{
			j = array[j - 1];
		}
	}

	return array;
}

bool algoritm(char* string, char* substring, int* position)
{
	int* array = prefix(substring);

	int k = 0;
	int l = 0;

	while (string[k] != '\0')
	{
		if (string[k] == substring[l])
		{
			++(*position);
			++k;
			++l;

			if (l == strlen(substring))
			{
				return true;
			}
		}

		if (string[k] != substring[l] && l == 0)
		{
			++(*position);
			++k;
			if (k == strlen(string))
			{
				return false;
			}
		}

		if (string[k] != substring[l] && l != 0)
		{
			l = array[l - 1];
		}
	}
}

bool algoritmTests(char* string, char* substring)
{
	int* array = prefix(substring);

	int k = 0;
	int l = 0;

	while (string[k] != '\0')
	{
		if (string[k] == substring[l])
		{
			++k;
			++l;

			if (l == strlen(substring))
			{
				return true;
			}
		}

		if (string[k] != substring[l] && l == 0)
		{
			++k;
			if (k == strlen(string))
			{
				return false;
			}
		}

		if (string[k] != substring[l] && l != 0)
		{
			l = array[l - 1];
		}
	}
}
