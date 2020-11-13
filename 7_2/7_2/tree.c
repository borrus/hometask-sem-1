#include "tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void initializeTree(Tree* tree)
{
	tree->root = NULL;
}

bool isOperation(char const symbol)
{
	if (symbol == '*' || symbol == '/' || symbol == '-' || symbol == '+')
	{
		return true;
	}

	return false;
}

bool isDigit(char const symbol)
{
	return !isOperation(symbol);
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
	subTree->leftChild->value = symbol;
	subTree->leftChild->leftChild = NULL;
	subTree->leftChild->rightChild = NULL;
	subTree->leftChild->parent = subTree;

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
	subTree->rightChild->value = symbol;
	subTree->rightChild->leftChild = NULL;
	subTree->rightChild->rightChild = NULL;
	subTree->rightChild->parent = subTree;

	if (isOperation(symbol))
	{
		createSubtree(subTree->rightChild, file);
	}
}

void createTree(Tree* tree)
{
	FILE* file = fopen("test.txt", "r");

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
	tree->root->value = symbol;
	tree->root->leftChild = NULL;
	tree->root->rightChild = NULL;
	tree->root->parent = NULL;

	createSubtree(tree->root, file);
}

int charToInt(char const value)
{
	return (int)value - (int)'0';
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