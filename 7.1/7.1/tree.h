#pragma once
#include <stdbool.h>

typedef struct Node
{
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	int key;
	char* value;
}Node;

typedef struct Tree
{
	Node* root;
}Tree;

void addValueByKey(Tree* tree, int const key, char* const value);

char* getValueByKey(Tree* const tree, int const key);

bool keyExist(Tree* tree, int const key);

void initialize(Tree* tree);

void deleteElementByKey(Tree* tree, int const key);