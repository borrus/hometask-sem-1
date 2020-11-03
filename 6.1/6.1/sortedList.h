#pragma once

typedef struct Node
{
	int value;
	struct Node* next;
	struct Node* previous;
}Node;

typedef struct SortedList
{
	Node* head;
	Node* tail;
	int size;
}SortedList;

void initializeList(SortedList* sortedListPointer);

void addToList(SortedList* sortedListPointer, int const value);

void printList(SortedList const sortedList);

void popFront(SortedList* sortedList);

void popBack(SortedList* sortedList);

void deleteElement(SortedList* sortedList, int const value);