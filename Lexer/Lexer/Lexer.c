#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isDigit(char const symbol)
{
	if ((int)'0' <= (int)symbol && (int)'9' >= (int)symbol)
	{
		return true;
	}

	return false;
}

bool numberLexer(const char* string)
{
	int state = 0;

	for (int position = 0; position < strlen(string); ++position)
	{
		char symbol = string[position];

		switch (state)
		{

		case 0:

			state = 1;

			if (!isDigit(symbol))
			{
				return false;
			}
			break;

		case 1:

			if (symbol == '.')
			{
				state = 2;
				break;
			}

			if (symbol == 'E')
			{
				state = 4;
				break;
			}

			if (!isDigit(symbol))
			{
				return false;
			}
			break;

		case 2:

			if (!isDigit(symbol))
			{
				return false;
			}
			state = 3;
			break;

		case 3:

			if (symbol == 'E')
			{
				state = 4;
				break;
			}

			if (!isDigit(symbol))
			{
				return false;
			}
			break;

		case 4:

			if (symbol == '+' || symbol == '-')
			{
				state = 5;
				break;
			}

			if (isDigit(symbol))
			{
				state = 5;
				break;
			}

			return false;

		case 5:

			if (!isDigit(symbol))
			{
				return false;
			}
			break;
		}
	}

	return state == 1 || state == 3 || state == 5;
}