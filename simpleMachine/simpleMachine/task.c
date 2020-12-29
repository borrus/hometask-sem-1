#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* inputString()
{
	char* line = malloc(100);
	scanf("%s", line);

	return line;
}

bool task()
{
	char* string = inputString();
	int id = 0;
	int currentOut = 0;

	while (id < strlen(string))
	{
		char currentChar = string[id];

		switch (currentOut)
		{
		case 0:

			if (!isalpha(string[id]))
			{
				return false;
			}
			currentOut = 1;

			break;
		case 1:

			if (!isalpha(string[id]) && !isdigit(string[id]) && currentChar != '_')
			{
				return false;
			}

			break;
		}

		++id;
	}

	return currentOut == 1;
}




