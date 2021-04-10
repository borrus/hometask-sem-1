#pragma once 

struct Node
{
	struct Node* next;
	char value;
};

//push first element
struct Node* initializeStack(char const value);

// add element
void push(struct Node** stackPtr, char const value);

//printf elements from stack
void printStack(struct Node const* stack);

//deletes element from stack
char pop(struct Node** stackPointer);

//free stack
void freeStack(struct Node** stackPointer);

//returns head of the stack
char peek(struct Node* const stack);