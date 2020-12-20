#pragma once
#include <stdbool.h>

typedef struct Node
{
	struct Node* left;
	struct Node* right;
	char* value;
	int height;
	int key;
} Node;

typedef struct Tree
{
	Node* root;
} Tree;

//initialization of tree->root. Creating node with value and key
Node* initRoot(int key, char* value);

//initialization of tree.
Tree* initTree();

//add element to tree by key
void push(Tree* tree, int key, char* value);

// delete element by key
void deleteNodeByKey(Tree* tree, int key);

//return value by key
char* getValueByKey(Tree* tree, int key);

//checks if key exists in the tree
bool keyExists(Tree* tree, int key);