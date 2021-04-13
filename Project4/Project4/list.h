#pragma once


typedef struct Node Node;

typedef struct List List;

// sets list size
void setSize(List* list, int const size);

// sets new list root
void setListRoot(List* list, Node const* root);

// sets next node
void setNextNode(Node* node, Node const* nodeToSet);

// returns list root
Node* getListRoot(List* list);

// returns next node
Node* getNextNode(Node* node);

// returns node value
char* getNodeName(Node* node);

// returns node number
char* getNodeNumber(Node* node);

// returns list size
int getListSize(List* list);

// initializes node
Node* nodeInitialize(char const* name, char const* number);

// initializes list
List* listInitialize();

// add element to the back
void listPushBack(List* list, char const* name, char const* number);

// delete element from the back
void listPopBack(List* list);

// free list 
void listFree(List* list);

// prints list
void listPrint(List const* list);