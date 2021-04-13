#pragma once

struct Node;

struct List;

//initializes lists
struct List* initializeList();

//initializes node
struct Node* initializeNode(char const value, struct Node* next, struct Node* previous);

//add element to the front
void pushFront(struct List* listPointer, char const value);

//add element to the back
void pushBack(struct List* listPointer, char const value);

//add element
void addToList(struct List* listPointer, char const value);

//print list
void printList(struct List const* listPointer);

//delete front element
void popFront(struct List* List);

//delete back element
void popBack(struct List* List);

//returns peek value
char peek(struct List const* List);

//to string
char const* toString(struct List const* list);

//list size
int size(struct List const* list);
