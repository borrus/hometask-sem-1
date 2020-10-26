#pragma once 

struct Node
{
	struct Node* next;
	char value;
};

struct Node* initializeStack(char const value);

void push(struct Node** stackPtr, char const value);

void printStack(struct Node const* stack);

char pop(struct Node** stackPointer);

void freeStack(struct Node** stackPointer);

char peek(struct Node* const stack);