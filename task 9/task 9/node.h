#pragma once

typedef struct Node
{
	struct Node* next;
	char* value;
} Node;


typedef struct List
{
	Node* root;
	int size;
} List;

void push(struct List* list, char* value);

struct List* initializeList();

void printList(List* list);

char* copyStr(char const* from);