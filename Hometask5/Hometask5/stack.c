#include "stack.h"
#include <stdio.h>

void push(struct Node** stackPointer, int const value)
{
	if (*stackPointer == NULL)
	{
		*stackPointer = (struct Node*)malloc(sizeof(struct Node));
		(*stackPointer)->value = value;
		(*stackPointer)->next = NULL;
		return;
	}

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
		printf("%d", stack->value);
		stack = stack->next;
	}

	printf("%c", stack->value);
	printf("\n");
}

int pop(struct Node** stackPointer)
{
	int value = (*stackPointer)->value;
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

int peek(struct Node* const stack)
{
	return stack->value;
}
