#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int height(Node* node)
{
	if (node != NULL)
	{
		return node->height;
	}

	return 0;
}

char* copyStr(char const* from)
{
	char* result = (char*)malloc((strlen(from) + 1) * sizeof(char));
	strcpy(result, from);
	return result;
}

int bFactor(Node* node)
{
	return height(node->right) - height(node->left);
}

void fixHeight(Node* node)
{
	int leftHeight = height(node->left);
	int rightHeight = height(node->right);

	node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

Node* rightRotate(Node* node)
{
	Node* newNode = node->left;
	node->left = newNode->right;
	newNode->right = node;
	fixHeight(node);
	fixHeight(newNode);

	return newNode;
}

Node* leftRotate(Node* node)
{
	Node* newNode = node->right;
	node->right = newNode->left;
	newNode->left = node;
	fixHeight(node);
	fixHeight(newNode);

	return newNode;
}

Node* balance(Node* node)
{
	fixHeight(node);

	if (bFactor(node) == 2)
	{
		if (bFactor(node->right) < 0)
		{
			node->right = rightRotate(node->right);
		}

		return leftRotate(node);
	}

	if (bFactor(node) == -2)
	{
		if (bFactor(node->left) > 0)
		{
			node->left = leftRotate(node->left);
		}

		return rightRotate(node);
	}

	return node;
}