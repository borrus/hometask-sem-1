#pragma once
#include <stdbool.h>

typedef struct Node Node;

// initialize node
Node* initializeNode(int const value);

typedef struct List List;

// gets list size
int getListSize(List* list);

// initiaslize list
List* initializeList();

// returns root
Node* getListRoot(List* list);

// returns next node
Node* getNextNode(Node* node);

// return current node value
int getNodeValue(Node* node);

// add element to the end
void pushBack(List* list, int const value);

// delete element from the back
void popBack(List* list);

// delete element from the front
void popFront(List* list);

// returns node by value
Node* getNodeByValue(List const* list, int const value);

// cheks if value exist in the list
bool valueExists(List const* list, int const value);

// deletes current node by value
void deleteNodeByValue(List* list, int const value);

// prints list
void printList(List const* list);