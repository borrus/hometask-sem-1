#pragma once
#include <stdbool.h>

typedef struct Node
{
	char* value;
	struct Node* next;
	struct Node* previous;
} Node;

// initialize Node by value 
Node* initializeNode(char const* value);

typedef struct List
{
	Node* root;
	Node* tail;
	int size;
} List;

//initialize List. Returns new List
List* initializeList();

//Adding an element from the end 
void pushBack(List* list, char const* value);

//Deleting an element from the end
void popBack(List* list);

//Deleting an element from the beginning
void popFront(List* list);

//Getting Node by Value 
Node* getNodeByValue(List const* list, char const* value);

//key existance check
bool valueExists(List const* list, char const* value);

//deleting Node by value
void deleteNodeByValue(List* list, char const* value);

bool firstBiggerThenSecond(char const* first, char const* second);

void printList(List const* list);

void sortList(List* list);

char* copyStr(char const* from);