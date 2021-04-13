#include "list.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>

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

void setListRoot(List* list, Node const* root)
{
	list->root = root;
}

void setNextNode(Node* node, Node const* nodeToSet)
{
	node->next = nodeToSet;
}

void setSize(List* list, int const size)
{
	list->size = size;
}

Node* getListRoot(List* list)
{
	return list->root;
}

Node* getNextNode(Node* node)
{
	return node->next;
}

char* getNodeName(Node* node)
{
	return copyStr(node->name);
}

char* getNodeNumber(Node* node)
{
	return copyStr(node->number);
}

int getListSize(List* list)
{
	return list->size;
}

Node* nodeInitialize(char const* name, char const* number)
{
	Node* node = (Node*)malloc(sizeof(Node));

	if (node == NULL)
	{
		return NULL;
	}

	node->name = copyStr(name);
	node->number = copyStr(number);
	node->next = NULL;

	return node;
}

List* listInitialize()
{
	List* list = (List*)malloc(sizeof(List));

	if (list == NULL)
	{
		return NULL;
	}

	list->root = NULL;
	list->size = 0;

	return list;
}

void listPushBack(List* list, char const* name, char const* number)
{
	if (list->root == NULL)
	{
		list->root = nodeInitialize(name, number);
		++list->size;
		return;
	}

	Node* temp = list->root;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = nodeInitialize(name, number);
	++list->size;
}

void listPopBack(List* list)
{
	if (list->root == NULL)
	{
		return;
	}

	Node* temp = list->root;

	if (temp->next == NULL)
	{
		free(temp);
		list->root = NULL;
		list->size = 0;

		return;
	}

	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}

	free(temp->next);
	temp->next = NULL;
	--list->size;
}

void listFree(List* list)
{
	while (list->size != 0)
	{
		listPopBack(list);
	}
}

void listPrint(List const* list)
{
	Node* temp = list->root;

	if (temp == NULL)
	{
		printf("list is empty\n");
		return;
	}

	while (temp != NULL)
	{
		printf("name = %s; number = %s\n", temp->name, temp->number);
		temp = temp->next;
	}
}