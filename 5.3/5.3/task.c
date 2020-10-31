#pragma once
#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

bool isDigit(char const symbol)
{
	int code = (int)symbol;
	int nol = (int)'0';
	int nine = (int)'9';

	if (code >= nol && code <= nine)
	{
		return true;
	}

	return false;
}

bool isOperation(char const symbol)
{
	switch (symbol)
	{
	case '+':
		return true;
		break;
	case '-':
		return true;
		break;
	case '*':
		return true;
		break;
	case '/':
		return true;
		break;
	default:
		return false;
		break;
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


char* infixToPostfix()
{
	struct Node* queue;
	struct Node* stack;
	char symbol = getchar();
	while (symbol != '\n')
	{
		if (isDigit(symbol))
		{
			push(&queue, symbol);
		}

		if (isOperation(symbol))
		{
			while (priority(peek(stack), symbol))
			{
				push(&queue, pop(&stack));
			}

			push(&stack, symbol);
		}

		if (isLeftBracket(symbol))
		{
			push(&stack, symbol);
		}

		if (isRightBracket(symbol))
		{
			while (!isLeftBracket(peek(stack)))
			{
				push(&queue, pop(&stack));
			}

			pop(&stack);
		}
	}
}