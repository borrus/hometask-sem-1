#define _CRT_SECURE_NO_WARNINGS

#include "utilities.h"

#include <string.h>

bool firstBiggerThanSecond(char const* str1, char const* str2)
{
	int const size1 = strlen(str1);
	int const size2 = strlen(str2);

	if (size1 > size2)
	{
		return true;
	}

	if (size1 < size2)
	{
		return false;
	}

	for (int i = 0; i < size1; ++i)
	{
		if ((int)str1[i] > (int)str2[i])
		{
			return true;
		}

		if ((int)str1[i] < (int)str2[i])
		{
			return false;
		}
	}

	return false;
}

char* copyStr(char const* source)
{
	int const size = strlen(source);
	char* destination = (char*)malloc((size + 1) * sizeof(char));
	strcpy(destination, source);

	return destination;
}