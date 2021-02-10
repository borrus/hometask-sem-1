#include "list.h"
#include "utilities.h"

#include <stdlib.h>
#include <stdio.h>

Node* nodeInitialize(char const* name, char const* number)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->name = copyStr(name);
	node->number = copyStr(number);
	node->next = NULL;

	return node;
}

List* listInitialize()
{
	List* list = (List*)malloc(sizeof(List));
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