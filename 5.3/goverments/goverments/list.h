#pragma once
#include <stdbool.h>

typedef struct Node
{
	int value;
	struct Node* next;
	struct Node* previous;
} Node;

Node* initializeNode(int const value);

typedef struct List
{
	Node* root;
	Node* tail;
	int size;
} List;

List* initializeList();

void pushBack(List* list, int const value);

void popBack(List* list);

void popFront(List* list);

Node* getNodeByValue(List const* list, int const value);

bool valueExists(List const* list, int const value);

void deleteNodeByValue(List* list, int const value);

void printList(List const* list);