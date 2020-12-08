#pragma once

typedef struct Node
{
	struct Node* next;
	int value;
} Node;


typedef struct List
{
	Node* root;
	int size;
} List;

List* initializeList();

void push(List* list, int value);