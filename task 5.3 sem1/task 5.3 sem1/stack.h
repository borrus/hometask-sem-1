#pragma once

struct Node;

struct List;

struct List* initializeList();

struct Node* initializeNode(char const value, struct Node* next, struct Node* previous);

void pushFront(struct List* listPointer, char const value);

void pushBack(struct List* listPointer, char const value);

void addToList(struct List* listPointer, char const value);

void printList(struct List const* listPointer);

void popFront(struct List* List);

void popBack(struct List* List);

char peek(struct List const* List);

char* toString(struct List const* list);

int size(struct List const* list);
