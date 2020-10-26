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

struct Node* putDataToStack()
{
	struct Node* stack = initializeStack(getchar());
	char symbol = getchar();
	while (symbol != '\n')
	{
		push(&stack, symbol);
		symbol = getchar();
	}

	return stack;
}

int charToInt(char const digit)
{
	return (int)digit - (int)'0';
}

int oneOperation(struct Node** const stackPointer)
{
	char operation = pop(stackPointer);
	int operand1 = charToInt(pop(stackPointer));
	int operand2 = charToInt(pop(stackPointer));

	switch (operation)
	{
	case '+':
		return operand2 + operand1;
		break;
	case '-':
		return operand2 - operand1;
		break;
	case '*':
		return operand2 * operand1;
		break;
	case '/':
		return operand2 / operand1;
		break;
	default:
		return 0;
		break;
	}
}

int calculateStack(struct Node** const stackPointer)
{
	if ((*stackPointer)->next == NULL)
	{
		return charToInt(pop(stackPointer));
	}

	char operation = pop(stackPointer);

	if (isOperation(peek(*stackPointer)))
	{
		switch (operation)
		{
		case '+':
			return oneOperation(stackPointer) + oneOperation(stackPointer);
			break;
		case '-':
			return oneOperation(stackPointer) - oneOperation(stackPointer);
			break;
		case '*':
			return oneOperation(stackPointer) * oneOperation(stackPointer);
			break;
		case '/':
			return oneOperation(stackPointer) / oneOperation(stackPointer);
			break;
		default:
			return 0;
			break;
		}
	}
	else
	{
		int operand1 = charToInt(pop(stackPointer));

		switch (operation)
		{
		case '+':
			return calculateStack(stackPointer) + operand1;
			break;
		case '-':
			return calculateStack(stackPointer) - operand1;
			break;
		case '*':
			return calculateStack(stackPointer) * operand1;
			break;
		case '/':
			return calculateStack(stackPointer) / operand1;
			break;
		default:
			return 0;
			break;
		}
	}
}

int postfixCalculator()
{
	struct Node* stack = putDataToStack();
	printStack(stack);
	int x = calculateStack(&stack);
	printf("%d", x);
	return 0;

}

