#include "list.h"
#include <stdlib.h>
#include <stdio.h>

Node* initializeNode(int const value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
}

List* initializeList()
{
	List* list = (struct List*)malloc(sizeof(List));
	list->root = NULL;
	list->tail = NULL;
	list->size = 0;
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

	Node* n1 = toDelete->previous;
	Node* n2 = toDelete->next;
	n1->next = n2;
	n2->previous = n1;
	free(toDelete);
	--list->size;
}