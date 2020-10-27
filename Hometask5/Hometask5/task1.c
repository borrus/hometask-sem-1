#include <stdio.h>
#include "stack.h"
#include <stdbool.h>
#include "task1.h"

bool isDigit(char const symbol)
{
	int const code = (int)symbol;
	int const code0 = (int)'0';
	int const code9 = (int)'9';

	return code >= code0 && code <= code9;
}

bool isOperator(char const symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int charToDigit(char const symbol)
{
	return (int)symbol - (int)'0';
}

void postfixCalculator()
{
	struct Node* operands = NULL;

	char symbol = getchar();

	while (symbol != '\n')
	{
		if (isOperator(symbol))
		{
			int operand2 = pop(&operands);
			int operand1 = pop(&operands);

			switch (symbol)
			{
			case '+':
				push(&operands, operand1 + operand2);
				break;
			case '-':
				push(&operands, operand1 - operand2);
				break;
			case '*':
				push(&operands, operand1 * operand2);
				break;
			case '/':
				push(&operands, operand1 / operand2);
				break;
			default:
				break;
			}
		}

		if (isDigit(symbol))
		{
			push(&operands, charToDigit(symbol));
		}

		symbol = getchar();
	}

	printf("%d", peek(operands));

	freeStack(&operands);
}