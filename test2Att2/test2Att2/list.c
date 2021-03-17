#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* initializeNode(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->value = value;

	return newNode;
}

List* initializeList()
{
	List* newList = (List*)malloc(sizeof(List));
	newList->root = NULL;
	newList->size = 0;
	return newList;
}

Node* getLast(Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	while (head->next != NULL)
	{
		head = head->next;
	}

	return head;
}

void push(List* list, int value)
{
	if (list->root == NULL)
	{
		list->root = initializeNode(value);

		return;
	}

	Node* last = getLast(list->root);
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = value;
	temp->next = NULL;
	last->next = temp;
}
