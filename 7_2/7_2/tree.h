#pragma once

typedef struct Node
{
	struct Node* leftChild;
	struct Node* rightChild;
	struct Node* parent;

	char value;
}Node;

typedef struct Tree
{
	Node* root;
}Tree;

void createTree(Tree* tree);

int calculateTree(Node* node);

int calculate(Tree* tree);