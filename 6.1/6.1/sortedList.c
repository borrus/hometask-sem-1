#include <stdio.h>
#include <stdlib.h>
#include "sortedList.h"
#include <stdbool.h>
#include <string.h>

struct Node
{
	int value;
	struct Node* next;
	struct Node* previous;
};

struct SortedList
{
	struct Node* head;
	struct Node* tail;
	int size;
};

struct SortedList* initializeList()
{
	struct SortedList* sortedListPointer = (struct SortedList*)malloc(sizeof(struct SortedList));
	sortedListPointer->head = NULL;
	sortedListPointer->tail = NULL;
	sortedListPointer->size = 0;

	return sortedListPointer;
}

struct Node* initializeNode(int const value, struct Node* next, struct Node* previous)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->next = next;
	newNode->previous = previous;
	newNode->value = value;

	return newNode;
}

void pushFront(struct SortedList* sortedListPointer, int const value)
{
	if (sortedListPointer->size == 0)
	{
		sortedListPointer->head = initializeNode(value, NULL, NULL);
		++sortedListPointer->size;
		sortedListPointer->tail = sortedListPointer->head;

		return;
	}

	sortedListPointer->head->previous = initializeNode(value, sortedListPointer->head, NULL);
	sortedListPointer->head = sortedListPointer->head->previous;
	++sortedListPointer->size;
}

void pushBack(struct SortedList* sortedListPointer, int const value)
{
	if (sortedListPointer->size == 0)
	{
		sortedListPointer->head = initializeNode(value, NULL, NULL);
		++sortedListPointer->size;
		sortedListPointer->tail = sortedListPointer->head;

		return;
	}

	sortedListPointer->tail->next = initializeNode(value, NULL, sortedListPointer->tail);
	sortedListPointer->tail = sortedListPointer->tail->next;
	++sortedListPointer->size;
}

void addToList(struct SortedList* sortedListPointer, int const value)
{
	if (sortedListPointer->size == 0)
	{
		pushBack(sortedListPointer, value);

		return;
	}

	if (value <= sortedListPointer->head->value)
	{
		pushFront(sortedListPointer, value);

		return;
	}

	if (value >= sortedListPointer->tail->value)
	{
		pushBack(sortedListPointer, value);

		return;
	}

	struct Node* temp = sortedListPointer->head;

	while (value > temp->value)
	{
		temp = temp->next;
	}

	struct Node* n1 = temp->previous;
	struct Node* n3 = temp;
	struct Node* n2 = initializeNode(value, n3, n1);
	n1->next = n2;
	n3->previous = n2;

	++sortedListPointer->size;
}

void printList(struct SortedList const* sortedListPointer)
{
	if (sortedListPointer->size == 0)
	{
		printf("List is empty!\n");
		return;
	}

	struct Node* temp = sortedListPointer->head;

	while (temp->next != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("%d\n", temp->value);
}

void popFront(struct SortedList* sortedList)
{
	if (sortedList->size == 0)
	{
		return;
	}

	if (sortedList->size == 1)
	{
		free(sortedList->head);
		sortedList->head = NULL;
		sortedList->tail = NULL;
		sortedList->size = 0;
		return;
	}

	struct Node* newHead = sortedList->head->next;
	free(sortedList->head);
	sortedList->head = newHead;
	sortedList->head->previous = NULL;
	--sortedList->size;
}

void popBack(struct SortedList* sortedList)
{
	if (sortedList->size == 0)
	{
		return;
	}

	if (sortedList->size == 1)
	{
		free(sortedList->head);
		sortedList->size = 0;
		return;
	}

	struct Node* newTail = sortedList->tail->previous;
	free(sortedList->tail);
	sortedList->tail = newTail;
	sortedList->tail->next = NULL;
	--sortedList->size;
}

void popElement(struct SortedList* sortedList, struct Node* element)
{
	if (element == sortedList->head)
	{
		popFront(sortedList);
		return;
	}

	if (element == sortedList->tail)
	{
		popBack(sortedList);
		return;
	}

	struct Node* node1 = element->previous;
	struct Node* node2 = element;
	struct Node* node3 = element->next;
	free(element);
	node1->next = node3;
	node3->previous = node1;
	--sortedList->size;
}

void deleteElement(struct SortedList* sortedList, int const value)
{
	if (sortedList->size == 0)
	{
		return;
	}

	struct Node* element = NULL;
	for (struct Node* temp = sortedList->head; temp != NULL; temp = temp->next)
	{
		if (temp->value == value)
		{
			element = temp;
			break;
		}
	}

	if (element == NULL)
	{
		return;
	}

	popElement(sortedList, element);
}

char* toString(struct SortedList const* list)
{
	if (list->size == 0)
	{
		return "list is empty";
	}

	char* outputString = (char*)malloc(sizeof(char) * list->size);
	outputString[0] = '\0';

	struct Node* temp = list->head;

	for (int i = 0; i < list->size; ++i)
	{
		char* string = (char*)malloc(sizeof(char) * 20);
		sprintf(string, "%d", temp->value);

		string = strcat(string, " ");
		string = strcat(outputString, string);

		temp = temp->next;
	}

	return outputString;
}

void task()
{
	struct SortedList* list = initializeList();
	int menuItem = -1;

	while (true)
	{
		scanf("%d", &menuItem);
		if (menuItem == 0)
		{
			printf("bye :)");
			break;
		}

		if (menuItem == 1)
		{
			int value = 0;
			printf("input value: ");
			scanf("%d", &value);
			addToList(list, value);
			continue;
		}

		if (menuItem == 2)
		{
			int value = 0;
			printf("input value: ");
			scanf("%d", &value);
			deleteElement(list, value);
			continue;
		}

		if (menuItem == 3)
		{
			printList(list);
			continue;
		}
	}
}

