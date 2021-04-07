#include <stdio.h>
#include <stdlib.h>
#include "sortedList.h"
#include <stdbool.h>

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


void initializeList(struct SortedList* sortedListPointer)
{
	sortedListPointer->head = NULL;
	sortedListPointer->tail = NULL;
	sortedListPointer->size = 0;
}

void pushFront(struct SortedList* sortedListPointer, int const value)
{
	struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
	newHead->value = value;
	newHead->next = sortedListPointer->head;
	sortedListPointer->head->previous = newHead;
	newHead->previous = NULL;
	sortedListPointer->head = newHead;
	++sortedListPointer->size;
}

void pushBack(struct SortedList* sortedListPointer, int const value)
{
	struct Node* newTail = (struct Node*)malloc(sizeof(struct Node));
	newTail->next = NULL;
	newTail->previous = NULL;
	newTail->value = 0;
	newTail->value = value;
	newTail->previous = sortedListPointer->tail;
	sortedListPointer->tail->next = newTail;
	newTail->next = NULL;
	sortedListPointer->tail = newTail;
	++sortedListPointer->size;
}

void addToList(struct SortedList* sortedListPointer, int const value)
{
	if (sortedListPointer->size == 0)
	{
		sortedListPointer->head = (struct Node*)malloc(sizeof(struct Node));
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

	struct Node* temp = sortedListPointer->head;

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

	struct Node* node1 = temp;
	struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* node3 = node1->next;
	node2->previous = node1;
	node2->next = node3;
	node3->previous = node2;
	node1->next = node2;
	node2->value = value;

	++sortedListPointer->size;
}

void printList(struct SortedList const sortedList)
{
	if (sortedList.size == 0)
	{
		printf("List is empty!\n");
		return;
	}

	struct Node* temp = sortedList.head;

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

void task()
{
	struct SortedList list;
	initializeList(&list);
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
			addToList(&list, value);
			continue;
		}

		if (menuItem == 2)
		{
			int value = 0;
			printf("input value: ");
			scanf("%d", &value);
			deleteElement(&list, value);
			continue;
		}

		if (menuItem == 3)
		{
			printList(list);
			continue;
		}
	}
}

bool testPushFront()
{
	struct SortedList list;
	initializeList(&list);
	pushFront(&list, 1);
	pushFront(&list, 2);
	pushFront(&list, 3);

	if (list.head == 3 && list.head->next == 2 && list.head->next->next == 1)
	{
		return true;
	}

	return false;
}

bool testPushBack()
{
	struct SortedList list;
	initializeList(&list);
	pushBack(&list, 1);
	pushBack(&list, 2);
	pushBack(&list, 3);

	if (list.head == 1 && list.head->next == 2 && list.head->next->next == 3)
	{
		return true;
	}

	return false;
}

bool testPopBack()
{
	struct SortedList list;
	initializeList(&list);
	pushBack(&list, 1);
	pushBack(&list, 2);
	pushBack(&list, 3);
	popBack(&list);

	if (list.head == 1 && list.head->next == 2 && list.head->next->next == NULL)
	{
		return true;
	}

	return false;
}