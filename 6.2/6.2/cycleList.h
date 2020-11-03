#pragma once

typedef struct Node
{
	struct Node* next;
	struct Node* previous;
	int value;

}Node;

typedef struct CycleList 
{
	Node* head;
	int size;

}CycleList;