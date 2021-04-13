#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum State
{
	start,
	seenFirstDigit,
	seenDot,
	seenDigitAfterDot,
	seenE,
	seenOpOrDigit,
	end
} State;

bool isDigit(char const symbol)
{
	return '0' <= symbol && '9' >= symbol;
}

bool numberLexer(const char* string)
{
	State state = start;

	for (int position = 0; position < strlen(string); ++position)
	{
		char symbol = string[position];

		switch (state)
		{

		case start:

			state = seenFirstDigit;

			if (!isDigit(symbol))
			{
				return false;
			}
			break;

		case seenFirstDigit:

			if (symbol == '.')
			{
				state = seenDot;
				break;
			}

			if (symbol == 'E')
			{
				state = seenE;
				break;
			}

			if (!isDigit(symbol))
			{
				return false;
			}
			break;

		case seenDot:

			if (!isDigit(symbol))
			{
				return false;
			}
			state = seenDigitAfterDot;
			break;

		case seenDigitAfterDot:

			if (symbol == 'E')
			{
				state = seenE;
				break;
			}

			if (!isDigit(symbol))
			{
				return false;
			}
			break;

		case seenE:

			if (symbol == '+' || symbol == '-' || isDigit(symbol))
			{
				state = seenOpOrDigit;
				break;
			}

			return false;

		case seenOpOrDigit:

			if (!isDigit(symbol))
			{
				return false;
			}

			state = end;

			break;
		}
	}

	return state == seenFirstDigit || state == seenDigitAfterDot || state == end;
}