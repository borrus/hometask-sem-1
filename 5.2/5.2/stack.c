#include <stdio.h>
#include <stdbool.h>

#include "stack.h"

struct Node* initializeStack(char const value)
{
	struct Node* stack = (struct Node*)malloc(sizeof(struct Node));
	stack->value = value;
	stack->next = NULL;
	return stack;
}

void push(struct Node** stackPointer, char const value)
{
	struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
	newHead->value = value;
	newHead->next = (*stackPointer);
	(*stackPointer) = newHead;
}

void printStack(struct Node const* stack)
{
	if (stack == NULL)
	{
		printf("stack is empty!");
		return;
	}

	while (stack->next != NULL)
	{
		printf("%c", stack->value);
		stack = stack->next;
	}

	printf("%c", stack->value);
	printf("\n");
}

char pop(struct Node** stackPointer)
{
	char value = (*stackPointer)->value;
	struct Node* temp = (*stackPointer)->next;
	free(*stackPointer);
	*stackPointer = temp;
	return value;
}

void freeStack(struct Node** stackPointer)
{
	while ((*stackPointer)->next != NULL)
	{
		pop(stackPointer);
	}
	free(*stackPointer);
	*stackPointer = NULL;
}

char peek(struct Node* const stack)
{
	return stack->value;
}