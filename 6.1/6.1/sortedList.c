#include <stdio.h>
#include "sortedList.h"
#include <stdbool.h>

void initializeList(SortedList* sortedListPointer)
{
	sortedListPointer->head = NULL;
	sortedListPointer->tail = NULL;
	sortedListPointer->size = 0;
}

void pushFront(SortedList* sortedListPointer, int const value)
{
	Node* newHead = (Node*)malloc(sizeof(Node));
	newHead->value = value;
	newHead->next = sortedListPointer->head;
	sortedListPointer->head->previous = newHead;
	newHead->previous = NULL;
	sortedListPointer->head = newHead;
	++sortedListPointer->size;
}

void pushBack(SortedList* sortedListPointer, int const value)
{
	Node* newTail = (Node*)malloc(sizeof(Node));
	newTail->value = value;
	newTail->previous = sortedListPointer->tail;
	sortedListPointer->tail->next = newTail;
	newTail->next = NULL;
	sortedListPointer->tail = newTail;
	++sortedListPointer->size;
}

void addToList(SortedList* sortedListPointer, int const value)
{
	if (sortedListPointer->size == 0)
	{
		sortedListPointer->head = (Node*)malloc(sizeof(Node));
		sortedListPointer->head->next = NULL;
		sortedListPointer->head->value = value;
		sortedListPointer->head->previous = NULL;
		sortedListPointer->tail = sortedListPointer->head;
		++sortedListPointer->size;
		return;
	}

	if (sortedListPointer->size == 1)
	{
		if (value > sortedListPointer->head->value)
		{
			pushBack(sortedListPointer, value);
		}
		else
		{
			pushFront(sortedListPointer, value);
		}
		return;
	}

	if (value <= sortedListPointer->head->value)
	{
		pushFront(sortedListPointer, value);
		return;
	}

	Node* temp = sortedListPointer->head;

	for (int i = 0; i < sortedListPointer->size; ++i)
	{
		if (value < temp->value && temp->previous != NULL)
		{
			temp = temp->previous;
			break;
		}

		temp = temp->next;
	}

	if (temp == NULL)
	{
		temp = sortedListPointer->tail;
	}

	if (temp->next == NULL)
	{
		pushBack(sortedListPointer, value);
		return;
	}

	Node* node1 = temp;
	Node* node2 = (Node*)malloc(sizeof(Node));
	Node* node3 = node1->next;
	node2->previous = node1;
	node2->next = node3;
	node3->previous = node2;
	node1->next = node2;
	node2->value = value;

	++sortedListPointer->size;
}

void printList(SortedList const sortedList)
{
	if (sortedList.size == 0)
	{
		printf("List is empty!\n");
		return;
	}

	Node* temp = sortedList.head;

	while (temp->next != NULL)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("%d\n", temp->value);
}

void popFront(SortedList* sortedList)
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

	Node* newHead = sortedList->head->next;
	free(sortedList->head);
	sortedList->head = newHead;
	sortedList->head->previous = NULL;
	--sortedList->size;
}

void popBack(SortedList* sortedList)
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

	Node* newTail = sortedList->tail->previous;
	free(sortedList->tail);
	sortedList->tail = newTail;
	sortedList->tail->next = NULL;
	--sortedList->size;
}

void popElement(SortedList* sortedList, Node* element)
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

	Node* node1 = element->previous;
	Node* node2 = element;
	Node* node3 = element->next;
	free(element);
	node1->next = node3;
	node3->previous = node1;
	--sortedList->size;
}

void deleteElement(SortedList* sortedList, int const value)
{
	if (sortedList->size == 0)
	{
		return;
	}

	Node* element = NULL;
	for (Node* temp = sortedList->head; temp != NULL; temp = temp->next)
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