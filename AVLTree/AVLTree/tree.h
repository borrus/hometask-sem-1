#pragma once
#include <stdbool.h>

typedef struct Node Node;

typedef struct Tree Tree;

// returns root
Node* getTreeRoot(Tree* tree);

// checks if strings are equal
bool equalStrings(char const* first, char const* second);

// returns nodes left son
Node* getLeftSon(Node* node);

// returns nodes right son
Node* getRightSon(Node* node);

// return nodes value
char* getNodeValue(Node* node);

// return nodes key
char* getNodeKey(Node* node);

// Creating node with value and key
Node* initRoot(char const* key, char const* value);

// initialization of tree.
Tree* initTree();

// add element to tree by key
void push(Tree* tree, char const* key, char* value);

// delete element by key
void deleteNodeByKey(Tree* tree, char const* key);

// return value by key
char* getValueByKey(Tree* tree, char const* key);

// checks if key exists in the tree
bool keyExists(Tree* tree, char const* key);