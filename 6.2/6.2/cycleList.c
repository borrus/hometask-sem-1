#include "cycleList.h"
#include <stdio.h>

void initialize(CycleList* cycleListPointer)
{
	cycleListPointer->head = NULL;
	cycleListPointer->size = 0;
}

void addElement(CycleList* cycleListPointer, int const value)
{
	if (cycleListPointer->size == 0)
	{
		cycleListPointer->head = (Node*)malloc(sizeof(Node));
		cycleListPointer->head->value = value;
		cycleListPointer->head->next = cycleListPointer->head;
		cycleListPointer->head->previous = cycleListPointer->head;
		++cycleListPointer->size;
		return;
	}

	if (cycleListPointer->size == 1)
	{
		Node* n2 = (Node*)malloc(sizeof(Node));
		n2->value = value;
		n2->previous = cycleListPointer->head;
		n2->next = cycleListPointer->head;
		cycleListPointer->head->previous = n2;
		cycleListPointer->head->next = n2;
		++cycleListPointer->size;
		return;
	}

	Node* n3 = cycleListPointer->head;
	Node* n1 = cycleListPointer->head->previous;
	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->value = value;
	n2->next = n3;
	n2->previous = n1;
	n3->previous = n2;
	n1->next = n2;
	++cycleListPointer->size;
}

void printList(CycleList const cycleList)
{
	if (cycleList.size == 0)
	{
		printf("list is empty");
		return;
	}

	Node* temp = cycleList.head;

	for (int i = 0; i < cycleList.size; ++i)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void popHead(CycleList* cycleListPointer)
{
	Node* n1 = cycleListPointer->head->previous;
	Node* n2 = cycleListPointer->head;
	Node* n3 = cycleListPointer->head->next;
	free(n2);
	n1->next = n3;
	n3->previous = n1;
	cycleListPointer->head = n2;
	--cycleListPointer->size;
}

void deleteElement(CycleList* cycleListPointer, int const position)
{
	if (cycleListPointer->size == 0)
	{
		return;
	}

	Node* temp = cycleListPointer->head;
	for (int i = 0; i < (position - 1) % cycleListPointer->size; ++i)
	{
		temp = temp->next;
	}

	cycleListPointer->head = temp;
	popHead(cycleListPointer);
}

void Joseph(CycleList* cycleListPointer, int const position)
{
	while (cycleListPointer->size > 1)
	{
		deleteElement(cycleListPointer, position);
	}
}

int main()
{
	CycleList list;
	initialize(&list);
	addElement(&list, 1);
	addElement(&list, 2);
	addElement(&list, 3);
	Joseph(&list, 3);
	printList(list);

}