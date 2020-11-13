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

int calculateTree(Node* node)
{
	if (!isOperator(node->value))
	{
		return node->value;
	}
	
	if (node->value == '+')
	{
		return calculateTree(node->leftChild) + calculateTree(node->rightChild);
	}
	
	if (node->value == '-')
	{
		return calculateTree(node->leftChild) - calculateTree(node->rightChild);
	}

	if (node->value == '/')
	{
		return calculateTree(node->leftChild) / calculateTree(node->rightChild);
	}

	if (node->value == '*')
	{
		return calculateTree(node->leftChild) * calculateTree(node->rightChild);
	}
}

int calculate(Tree* tree)
{
	
5 минут
	return calculateTree(tree->root);
}