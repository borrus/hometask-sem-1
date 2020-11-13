#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void initialize(Tree* tree)
{
	tree->root = NULL;
}

void addValueByKeyNode(Node* node, int const key, char* const value)
{
	if (key == node->key)
	{
		node->value = value;
		return;
	}

	if (key < node->key)
	{
		if (node->left == NULL)
		{
			node->left = (Node*)malloc(sizeof(Node));
			node->left->key = key;
			node->left->value = value;
			node->left->left = NULL;
			node->left->right = NULL;
			node->left->parent = node;
			return;
		}

		addValueByKeyNode(node->left, key, value);
		return;
	}

	if (key > node->key)
	{
		if (node->right == NULL)
		{
			node->right = (Node*)malloc(sizeof(Node));
			node->right->key = key;
			node->right->value = value;
			node->right->right = NULL;
			node->right->left = NULL;
			node->right->parent = node;
			return;
		}

		addValueByKeyNode(node->right, key, value);
		return;
	}
}

void addValueByKey(Tree* tree, int const key, char* const value)
{
	if (tree->root == NULL)
	{
		tree->root = (Node*)malloc(sizeof(Node));
		tree->root->key = key;
		tree->root->value = value;
		tree->root->left = NULL;
		tree->root->right = NULL;
		tree->root->parent = NULL;
		return;
	}

	addValueByKeyNode(tree->root, key, value);
}

char* getValueByKeyNode(Node* const node, int const key)
{
	if (key == node->key)
	{
		return node->value;
	}

	if (key > node->key)
	{
		if (node->right == NULL)
		{
			return NULL;
		}

		return getValueByKeyNode(node->right, key);
	}

	if (key < node->key)
	{
		if (node->left == NULL)
		{
			return NULL;
		}

		return getValueByKeyNode(node->left, key);

	}
}

char* getValueByKey(Tree* const tree, int const key)
{
	if (tree->root == NULL)
	{
		return NULL;
	}

	return getValueByKeyNode(tree->root, key);
}

bool keyExistNode(Node* const node, int const key)
{
	if (node == NULL)
	{
		return false;
	}

	if (key > node->key)
	{
		if (node->right == NULL)
		{
			return false;
		}

		return keyExistNode(node->right, key);
	}

	if (key < node->key)
	{
		if (node->left == NULL)
		{
			return false;
		}

		return keyExistNode(node->left, key);
	}

	if (node->key == key)
	{
		return true;
	}
}

bool keyExist(Tree* tree, int const key)
{
	if (tree->root == NULL)
	{
		return false;
	}

	return keyExistNode(tree->root, key);
}

bool isLeave(Node* node)
{
	if (node->left == NULL && node->right == NULL)
	{
		return true;
	}

	return false;
}
//
Node* getNodeByKey(Tree* const tree, int const key)
{
	if (!keyExist(&tree, key))
	{
		return NULL;
	}

	Node* temp = tree->root;

	while (key != temp->key)
	{
		if (temp->key < key)
		{
			temp = temp->right;
		}

		if (temp->key > key)
		{
			temp = temp->left;
		}
	}

	return temp;
}

Node* getMaxNodeLeftNode(Node* const node)
{
	Node* temp = node->left;
	int counter = 0;

	while (temp->right != NULL)
	{
		temp = temp->right;
		++counter;
	}

	if (counter > 0)
	{
		return temp;
	}

	return NULL;
}

void deleteElementByKey(Tree* tree, int const key)
{
	if (!keyExist(&tree, key))
	{
		return;
	}

	Node* nodeToDelete = getNodeByKey(&tree, key);

	if (nodeToDelete->left == NULL && nodeToDelete->right == NULL)
	{
		free(nodeToDelete);
		return;
	}

	if (nodeToDelete->left != NULL && nodeToDelete->right != NULL)
	{
		Node* n2 = getMaxNodeLeftNode(&nodeToDelete);
		Node* n1 = nodeToDelete->parent;

		if (nodeToDelete->right != NULL)
		{
			Node* n2Right = nodeToDelete->right;
			free(nodeToDelete);

			if (n1->value > n2->value)
			{
				n1->left = n2;
				n2->parent = n1;
				n2->right = n2Right;
			}

			if (n1->value < n2->value)
			{
				n1->right = n2;
				n2->parent = n1;
				n2->right = n2Right;
			}

			return;
		}

		if (nodeToDelete->right == NULL)
		{
			free(nodeToDelete);

			if (n1->value > n2->value)
			{
				n1->left = n2;
				n2->parent = n1;
			}

			if (n1->value < n2->value)
			{
				n1->right = n2;
				n2->parent = n1;
			}

			return;
		}
	}

	Node* child = NULL;

	if (nodeToDelete->left != NULL && nodeToDelete->right == NULL)
	{
		child = nodeToDelete->left;
	}
	else
	{
		child = nodeToDelete->right;
	}

	Node* parent = nodeToDelete->parent;

	if (nodeToDelete == parent->left)
	{
		parent->left = child;
	}
	else
	{
		parent->right = child;
	}

	child->parent = parent;
	free(nodeToDelete);
}