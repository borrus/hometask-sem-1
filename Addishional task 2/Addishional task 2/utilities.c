#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(char* a, char* b)
{
	char* c = (char*)malloc(sizeof(char) * 100);

	if (c == NULL)
	{
		return;
	}

	*c = *b;
	*b = *a;
	*a = *c;

	free(c);
}

char* copyStr(char const* source)
{
	char* copy = (char*)malloc(sizeof(char) * (strlen(source) + 1));

	if (copy != NULL)
	{
		strcpy(copy, source);
	}

	return copy;
}

bool isNumber(char* number)
{
	int const length = strlen(number);

	if (length == 0)
	{
		return false;
	}

	if (length > 1 && number[0] == '0')
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (!isdigit(number[i]))
		{
			return false;
		}
	}

	return true;
}