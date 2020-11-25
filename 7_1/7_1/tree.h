#pragma once
#include <stdbool.h>

typedef struct Node
{
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	int key;
	char* value;
} Node;

typedef struct Tree
{
	Node* root;
} Tree;

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