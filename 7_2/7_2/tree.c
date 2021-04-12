#include "tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "utilities.h"

typedef struct Node
{
	struct Node* leftChild;
	struct Node* rightChild;
	struct Node* parent;

	char value;
} Node;

typedef struct Tree
{
	Node* root;
} Tree;

void initializeTree(Tree* tree)
{
	tree->root = NULL;
}

void createSon(Node* parent, Node* node, char value)
{
	node->parent = parent;
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->value = value;
}

void createSubtree(Node* subTree, FILE* file)
{
	if (feof(file))
	{
		return;
	}

	char symbol = '\0';

	if (!fscanf(file, "%c", &symbol))
	{
		return;
	}

	subTree->leftChild = (Node*)malloc(sizeof(Node));

	if (subTree->leftChild == NULL)
	{
		return;
	}

	createSon(subTree, subTree->leftChild, symbol);

	if (isOperation(symbol))
	{
		createSubtree(subTree->leftChild, file);
	}

	if (feof(file))
	{
		return;
	}

	symbol = '\0';

	if (!fscanf(file, "%c", &symbol))
	{
		return;
	}

	subTree->rightChild = (Node*)malloc(sizeof(Node));

	if (subTree->rightChild == NULL)
	{
		return;
	}

	createSon(subTree, subTree->rightChild, symbol);

	if (isOperation(symbol))
	{
		createSubtree(subTree->rightChild, file);
	}
}

void createTree(Tree* tree, char* path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		return;
	}

	if (feof(file))
	{
		return;
	}

	char symbol = '\0';

	if (!fscanf(file, "%c", &symbol))
	{
		return;
	}

	tree->root = (Node*)malloc(sizeof(Node));

	if (tree->root == NULL)
	{
		return;
	}

	createSon(NULL, tree->root, symbol);

	createSubtree(tree->root, file);
}

int calculateSubTree(Node* node)
{
	if (!isOperation(node->value))
	{
		return charToInt(node->value);
	}

	if (node->value == '+')
	{
		return calculateSubTree(node->leftChild) + calculateSubTree(node->rightChild);
	}

	if (node->value == '-')
	{
		return calculateSubTree(node->leftChild) - calculateSubTree(node->rightChild);
	}

	if (node->value == '/')
	{
		return calculateSubTree(node->leftChild) / calculateSubTree(node->rightChild);
	}

	if (node->value == '*')
	{
		return calculateSubTree(node->leftChild) * calculateSubTree(node->rightChild);
	}
}

int calculateTree(Tree* tree)
{
	if (tree->root == NULL)
	{
		printf("");
		return -1;
	}

	return calculateSubTree(tree->root);
}