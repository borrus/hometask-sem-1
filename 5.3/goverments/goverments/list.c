#include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node* next;
	struct Node* previous;
} Node;

Node* initializeNode(int const value)
{
	Node* node = (Node*)malloc(sizeof(Node));

	if (node == NULL)
	{
		return NULL;
	}

	node->value = value;
	node->next = NULL;
	node->previous = NULL;

	return node;
}

typedef struct List
{
	Node* root;
	Node* tail;
	int size;
} List;

List* initializeList()
{
	return calloc(1, sizeof(List));
}

Node* getListRoot(List* list)
{
	return list->root;
}

Node* getNextNode(Node* node)
{
	return node->next;
}

int getNodeValue(Node* node)
{
	return node->value;
}

int getListSize(List* list)
{
	return list->size;
}

void pushBack(List* list, int const value)
{
	if (list->size == 0)
	{
		list->root = initializeNode(value);
		list->tail = list->root;
		++list->size;
		return;
	}

	list->tail->next = initializeNode(value);
	list->tail->next->previous = list->tail;
	list->tail = list->tail->next;
	++list->size;
}

void popBack(List* list)
{
	if (list->size == 0)
	{
		return;
	}

	if (list->size == 1)
	{
		free(list->tail);
		list->root = NULL;
		list->tail = NULL;
		--list->size;
		return;
	}

	Node* newTail = list->tail->previous;
	free(list->tail);
	list->tail = newTail;
	list->tail->next = NULL;
	--list->size;
}

void popFront(List* list)
{
	if (list->size == 0)
	{
		return;
	}

	if (list->size == 1)
	{
		free(list->root);
		--list->size;
		list->root = NULL;
		list->tail = NULL;
		return;
	}

	Node* newRoot = list->root->next;
	free(list->root);
	--list->size;
	list->root = newRoot;
	list->root->previous = NULL;
}

Node* getNodeByValue(List const* list, int const value)
{
	if (list->size == 0)
	{
		return NULL;
	}

	Node* temp = list->root;
	while (temp->next != NULL)
	{
		if (temp->value == value)
		{
			return temp;
		}

		temp = temp->next;
	}

	if (temp->value == value)
	{
		return temp;
	}

	return NULL;
}

bool valueExists(List const* list, int const value)
{
	return getNodeByValue(list, value) != NULL;
}

void deleteNodeByValue(List* list, int const value)
{
	if (!valueExists(list, value))
	{
		return;
	}

	Node* toDelete = getNodeByValue(list, value);

	if (toDelete == list->root)
	{
		popFront(list);
		return;
	}

	if (toDelete == list->tail)
	{
		popBack(list);
		return;
	}

	Node* nodeTodeletePrevious = toDelete->previous;
	Node* nodeToDeleteNext = toDelete->next;
	nodeTodeletePrevious->next = nodeToDeleteNext;
	nodeToDeleteNext->previous = nodeTodeletePrevious;
	free(toDelete);
	--list->size;
}

void printList(List const* list)
{
	if (list->size == 0)
	{
		printf("list is empty\n");
		return;
	}

	Node* temp = list->root;
	while (temp != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}