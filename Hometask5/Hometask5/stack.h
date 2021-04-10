#pragma once

struct Node
{
	struct Node* next;
	int value;
};

void push(struct Node** stackPointer, int const value);

void printStack(struct Node const* stack);

int pop(struct Node** stackPointer);

void freeStack(struct Node** stackPointer);

int peek(struct Node* const stack);

int stackLength(struct Node* stack);