#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* intToCharArray(int const number)
{
	char* string = (char*)malloc(sizeof(char) * 1000);

	if (string == NULL)
	{
		return NULL;
	}

	string[0] = '\0';

	sprintf(string, "%d", number);

	return string;
}

char* spaces(int const amount)
{
	char* res = (char*)malloc(sizeof(char) * (amount + 1));
	res[amount] = '\0';

	for (int i = 0; i < amount; i++)
	{
		res[i] = ' ';
	}

	return res;
}

char* polynomial(int const* array, int const size)
{
	if (size == 0)
	{
		return "polynomial is incorrect";
	}

	char* degrees = (char*)malloc(sizeof(char) * 1000);
	char* outputString = (char*)malloc(sizeof(char) * 1000);

	if (outputString == NULL)
	{
		return NULL;
	}

	if (degrees == NULL)
	{
		return NULL;
	}

	degrees[0] = '\0';
	outputString[0] = '\0';

	for (int i = 0; i < size; ++i)
	{
		if (array[i] != 0)
		{
			if (array[i] > 0 && i != 0)
			{
				strcat(outputString, " + ");
			}
			else if (array[i] < 0)
			{
				strcat(outputString, " - ");
			}

			int const coefficient = abs(array[i]);

			int const degree = size - i - 1;

			if (coefficient != 1 || degree == 0)
			{
				strcat(outputString, intToCharArray(coefficient));
			}

			if (degree > 0)
			{
				strcat(outputString, "x");

				if (degree > 1)
				{
					int polyLen = strlen(outputString);
					int degreeLen = strlen(degrees);

					if (degreeLen < polyLen)
					{
						strcat(degrees, spaces(polyLen - degreeLen));
					}

					strcat(degrees, intToCharArray(degree));
				}
			}
		}
	}

	strcat(degrees, "\n");
	strcat(degrees, outputString);
	free(outputString);

	return degrees;
}

char* task(int const* array, int const size)
{
	int position = 0;

	while (array[position] == 0)
	{
		++position;
	}

	if (position == size)
	{
		return "";
	}

	int const length = size - position;
	int* fixedArray = (int*)malloc(sizeof(int) * length);

	if (fixedArray == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < length; ++i)
	{
		fixedArray[i] = array[i + position];
	}

	char* result = (char*)malloc(sizeof(char) * length);
	result = polynomial(fixedArray, length);
	free(fixedArray);

	return result;
}