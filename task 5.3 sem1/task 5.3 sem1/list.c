#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	char value;
	struct Node* next;
	struct Node* previous;
};

struct List
{
	struct Node* head;
	struct Node* tail;
	int size;
};

struct List* initializeList()
{
	struct List* listPointer = (struct List*)malloc(sizeof(struct List));
	listPointer->head = NULL;
	listPointer->tail = NULL;
	listPointer->size = 0;

	return listPointer;
}

struct Node* initializeNode(char const value, struct Node* next, struct Node* previous)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = next;
	newNode->previous = previous;
	newNode->value = value;

	return newNode;
}

void pushFront(struct List* listPointer, char const value)
{
	if (listPointer->size == 0)
	{
		listPointer->head = initializeNode(value, NULL, NULL);
		++listPointer->size;
		listPointer->tail = listPointer->head;

		return;
	}

	listPointer->head->previous = initializeNode(value, listPointer->head, NULL);
	listPointer->head = listPointer->head->previous;
	++listPointer->size;
}

void pushBack(struct List* listPointer, char const value)
{
	if (listPointer->size == 0)
	{
		listPointer->head = initializeNode(value, NULL, NULL);
		++listPointer->size;
		listPointer->tail = listPointer->head;

		return;
	}

	listPointer->tail->next = initializeNode(value, NULL, listPointer->tail);
	listPointer->tail = listPointer->tail->next;
	++listPointer->size;
}

void addToList(struct List* listPointer, char const value)
{
	if (listPointer->size == 0)
	{
		pushBack(listPointer, value);

		return;
	}

	if (value <= listPointer->head->value)
	{
		pushFront(listPointer, value);

		return;
	}

	if (value >= listPointer->tail->value)
	{
		pushBack(listPointer, value);

		return;
	}

	struct Node* temp = listPointer->head;

	while (value > temp->value)
	{
		temp = temp->next;
	}

	struct Node* n1 = temp->previous;
	struct Node* n3 = temp;
	struct Node* n2 = initializeNode(value, n3, n1);
	n1->next = n2;
	n3->previous = n2;

	++listPointer->size;
}

void printList(struct List const* listPointer)
{
	if (listPointer->size == 0)
	{
		printf("List is empty!\n");
		return;
	}

	struct Node* temp = listPointer->head;

	while (temp->next != NULL)
	{
		printf("%c ", temp->value);
		temp = temp->next;
	}

	printf("%c\n", temp->value);
}

void popFront(struct List* list)
{
	if (list->size == 0)
	{
		return;
	}

	if (list->size == 1)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
		return;
	}

	struct Node* newHead = list->head->next;
	free(list->head);
	list->head = newHead;
	list->head->previous = NULL;
	--list->size;
}

void popBack(struct List* list)
{
	if (list->size == 0)
	{
		return;
	}

	if (list->size == 1)
	{
		free(list->head);
		list->size = 0;
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	struct Node* newTail = list->tail->previous;
	free(list->tail);
	list->tail = newTail;
	list->tail->next = NULL;
	--list->size;
}

char peek(struct List const* list)
{
	if (list->size == 0)
	{
		return '\0';
	}

	return list->head->value;
}

char const* toString(struct List const* list)
{
	if (list->size == 0)
	{
		return "list is empty";
	}

	char* outputString = (char*)malloc(sizeof(char) * (list->size + 1));

	outputString[list->size] = '\0';

	struct Node* temp = list->head;

	for (int i = 0; i < list->size; ++i)
	{
		outputString[i] = temp->value;

		temp = temp->next;
	}

	return outputString;
}

int size(struct List const* list)
{
	return list->size;
}
