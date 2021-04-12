#pragma once
#include <stdbool.h>

typedef struct Node Node;

typedef struct Tree Tree;

//returns tree root;
Node* getTreeRoot(Tree* tree);

//returns left child of a current node
Node* getLeftChild(Node* node);

//returns right child of a current node
Node* getRightChild(Node* node);

//returns key of a current node
int getNodeKey(Node* node);

//returns value of a current node
char* getNodeValue(Node* node);

//returns node by key
Node* getNodeByKey(Tree* const tree, int const key);

//adding value by key
void addValueByKey(Tree* tree, int const key, char* const value); 

//getting value by key
char* getValueByKey(Tree* const tree, int const key);

//checking for key existence
bool keyExist(Tree* tree, int const key);

//tree initialization 
Tree* initialize();

//deleting element by key
void deleteElementByKey(Tree* tree, int const key);