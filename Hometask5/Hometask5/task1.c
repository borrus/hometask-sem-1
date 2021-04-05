#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "task1.h"

char* inputStringFromConsole()
{
	printf("input your expression without spaces:\n");
	char* string = (char*)malloc(sizeof(char) * 100);
	scanf("%s", string);

	return string;
}

bool isDigit(char const symbol)
{	
	return symbol >= '0' && symbol <= '9';
}

bool isOperator(char const symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int charToDigit(char const symbol)
{
	return symbol - '0';
}

char* intToString(int number)
{
	char* string = (char*)malloc(sizeof(char) * 100);
	sprintf(string, "%d", number);

	return string;
}

char* postfixCalculator(char const* expression)
{
	int const length = strlen(expression);

	if (length == 0)
	{
		return "expression is empty\n";
	}

	struct Node* operands = NULL;
	char symbol = expression[0];
	int position = 0;

	while (position != length)
	{
		if (stackLength(operands) > 3)
		{
			return "incorrect expression\n";
		}

		++position;

		if (isOperator(symbol))
		{
			int operand2 = pop(&operands);

			if (operands == NULL)
			{
				printf("incorrect expression\n");

				return;
			}

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

		symbol = expression[position];
	}

	if (stackLength(operands) > 1)
	{
		return "incorrect expression\n";
	}

	
	char* answer = (char*)malloc(sizeof(char) * 100);
	sprintf(answer, "%d", peek(operands));

	freeStack(&operands);

	return answer;
}