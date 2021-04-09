#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

bool isDigit(char const symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isOperation(char const symbol)
{
	switch (symbol)
	{
	case '+':
		return true;
	case '-':
		return true;
	case '*':
		return true;
	case '/':
		return true;
	default:
		return false;
	}
}

int priority(char const operator1, char const operator2)
{
	if ((operator1 == '*' || operator1 == '/') && (operator2 == '+' || operator2 == '-'))
	{
		return 1;
	}

	if ((operator2 == '*' || operator2 == '/') && (operator1 == '+' || operator1 == '-'))
	{
		return -1;
	}

	return 0;
}

bool isLeftBracket(char const symbol)
{
	char leftBracket = '(';
	if (symbol == leftBracket)
	{
		return true;
	}

	return false;
}

bool isRightBracket(char const symbol)
{
	char rightBracket = ')';
	if (symbol == rightBracket)
	{
		return true;
	}

	return false;
}

bool isBracket(char const symbol)
{
	return isLeftBracket(symbol) || isRightBracket(symbol);
}

char* infixToPostfix(char const* string)
{
	struct List* queue = initializeList();
	struct List* stack = initializeList();
	int position = 0;
	char symbol = string[position];
	++position;

	while (symbol != '\0')
	{
		if (isDigit(symbol))
		{
			pushBack(queue, symbol);
		}
		else if (isOperation(symbol))
		{
			while (size(stack) != 0 && priority(peek(stack), symbol))
			{
				pushBack(queue, peek(stack));
				popFront(stack);
			}

			pushFront(stack, symbol);
		}
		else if (isLeftBracket(symbol))
		{
			pushFront(stack, symbol);
		}
		else if (isRightBracket(symbol))
		{
			while (size(stack) != 0 && !isLeftBracket(peek(stack)))
			{
				if (!isOperation(peek(stack)))
				{
					return "incorrect expression";
				}

				pushBack(queue, peek(stack));
				popFront(stack);
			}

			if (!isLeftBracket(peek(stack)))
			{
				return "there is bracket withuot pair!";
			}

			popFront(stack);
		}

		symbol = string[position];
		++position;
	}

	while (size(stack) != 0)
	{
		if (isBracket(peek(stack)))
		{
			return "there is bracket withuot pair!";
		}

		pushBack(queue, peek(stack));
		popFront(stack);
	}

	return toString(queue);
}