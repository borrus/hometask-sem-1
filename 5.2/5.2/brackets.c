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
			if (rightBracket == rightBrackets[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool bracketsBalance()
{
	char symbol = getchar();
	while (!isBracket(symbol))
	{
		if (symbol == '\n')
		{
			return true;
		}

		symbol = getchar();
	}

	if (isRightBracket(symbol))
	{
		return false;
	}

	struct stack* leftBrackets = initializeStack(symbol);

	symbol = getchar();
	while (symbol != '\n')
	{
		if (isLeftBracket(symbol))
		{
			push(&leftBrackets, symbol);
		}

		if (isRightBracket(symbol))
		{
			if (bracketsIsPair(peek(leftBrackets), symbol))
			{
				pop(&leftBrackets);
			}
			else
			{
				return false;
			}
		}

		symbol = getchar();
	}

	if (leftBrackets == NULL)
	{
		return true;
	}

	return false;
}