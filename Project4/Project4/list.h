#pragma once


typedef struct Node
{
	struct Node* next;
	char* name;
	char* number;
} Node;

typedef struct List
{
	Node* root;
	int size;
} List;

Node* nodeInitialize(char const* name, char const* number);

List* listInitialize();

void listPushBack(List* list, char const* name, char const* number);

void listPopBack(List* list);

void listFree(List* list);

void listPrint(List const* list);