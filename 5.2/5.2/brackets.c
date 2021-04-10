#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

bool isLeftBracket(char const symbol)
{
	char leftBrackets[3] = { '(', '[', '{' };
	for (int i = 0; i < 3; ++i)
	{
		if (symbol == leftBrackets[i])
		{
			return true;
		}
	}

	return false;
}

bool isRightBracket(char const symbol)
{
	char rightBrackets[3] = { ')', ']', '}' };
	for (int i = 0; i < 3; ++i)
	{
		if (symbol == rightBrackets[i])
		{
			return true;
		}
	}

	return false;
}

bool isBracket(char const symbol)
{
	return isRightBracket(symbol) || isLeftBracket(symbol);
}

bool bracketsIsPair(char const leftBracket, char const rightBracket)
{
	char leftBrackets[3] = { '(', '[', '{' };
	char rightBrackets[3] = { ')', ']', '}' };

	for (int i = 0; i < 3; ++i)
	{
		if (leftBracket == leftBrackets[i])
		{
			return rightBracket == rightBrackets[i];
		}
	}
}

bool bracketsBalance(char const* string)
{
	char symbol = string[0];
	int position = 1;

	while (!isBracket(symbol))
	{
		if (symbol == '\0')
		{
			return true;
		}

		symbol = string[position];
		++position;
	}

	if (isRightBracket(symbol))
	{
		return false;
	}

	struct stack* leftBrackets = initializeStack(symbol);

	symbol = string[position];
	++position;

	while (symbol != '\0')
	{
		if (isLeftBracket(symbol))
		{
			push(&leftBrackets, symbol);
		}

		if (isRightBracket(symbol))
		{
			if (leftBrackets == NULL)
			{
				return false;
			}

			if (bracketsIsPair(peek(leftBrackets), symbol))
			{
				pop(&leftBrackets);
			}
			else
			{
				return false;
			}
		}

		symbol = string[position];
		++position;
	}

	bool flag = (leftBrackets == NULL);
	freeStack(&leftBrackets);

	return flag;
}