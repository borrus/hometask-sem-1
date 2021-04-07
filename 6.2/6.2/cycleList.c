#include "cycleList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* next;
	struct Node* previous;
	int value;
};

struct CycleList
{
	struct Node* head;
	int size;
};

struct CycleList* initializeList()
{
	struct CycleList* newList = (struct CycleList*)malloc(sizeof(struct CycleList));
	newList->head = NULL;
	newList->size = 0;

	return newList;
}

void addElement(struct CycleList* cycleListPointer, int const value)
{
	if (cycleListPointer->size == 0)
	{
		cycleListPointer->head = (struct Node*)malloc(sizeof(struct Node));
		cycleListPointer->head->value = value;
		cycleListPointer->head->next = cycleListPointer->head;
		cycleListPointer->head->previous = cycleListPointer->head;
		++cycleListPointer->size;
		return;
	}

	if (cycleListPointer->size == 1)
	{
		struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
		n2->value = value;
		n2->previous = cycleListPointer->head;
		n2->next = cycleListPointer->head;
		cycleListPointer->head->previous = n2;
		cycleListPointer->head->next = n2;
		++cycleListPointer->size;
		return;
	}

	struct Node* n3 = cycleListPointer->head;
	struct Node* n1 = cycleListPointer->head->previous;
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
	n2->value = value;
	n2->next = n3;
	n2->previous = n1;
	n3->previous = n2;
	n1->next = n2;
	++cycleListPointer->size;
}

void printList(struct CycleList const* cycleListPointer)
{
	if (cycleListPointer->size == 0)
	{
		printf("list is empty");
		return;
	}

	struct Node* temp = cycleListPointer->head;

	for (int i = 0; i < cycleListPointer->size; ++i)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}

	printf("\n");
}

void popHead(struct CycleList* cycleListPointer)
{
	if (cycleListPointer->size == 0)
	{
		return;
	}

	struct Node* n1 = cycleListPointer->head->previous;
	struct Node* n2 = cycleListPointer->head;
	struct Node* n3 = cycleListPointer->head->next;
	free(n2);
	n1->next = n3;
	n3->previous = n1;
	cycleListPointer->head = n3;
	--cycleListPointer->size;
}

void deleteElement(struct CycleList* cycleListPointer, int const position)
{
	if (cycleListPointer->size == 0)
	{
		return;
	}

	struct Node* temp = cycleListPointer->head;

	for (int i = 0; i < (position - 1) % cycleListPointer->size; ++i)
	{
		temp = temp->next;
	}

	cycleListPointer->head = temp;
	popHead(cycleListPointer);
}

int joseph(struct CycleList* cycleListPointer, int const position)
{
	if (cycleListPointer->size == 0)
	{
		return -1;
	}

	while (cycleListPointer->size > 1)
	{
		deleteElement(cycleListPointer, position);
	}

	return cycleListPointer->head->value;
}
