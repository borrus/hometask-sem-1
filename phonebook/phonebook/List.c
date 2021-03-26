#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>

Node* initializeNode(char* value)
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

char* copyStr(char const* from)
{
	char* result = (char*)malloc((strlen(from) + 1) * sizeof(char));
	strcpy(result, from);
	return result;
}

void push(List* list, char* value)
{
	++list->size;
	if (list->root == NULL)
	{
		list->root = initializeNode(value);

		return;
	}

	Node* last = getLast(list->root);
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = copyStr(value);
	temp->next = NULL;
	last->next = temp;
}

void printList(List* list)
{
	if (list->root == NULL)
	{
		printf("List is empty\n");
	}
	Node* temp = list->root;
	while (temp->next != NULL)
	{
		printf("%s ", temp->value);
		temp = temp->next;
	}
	printf("%s\n", temp->value);
}