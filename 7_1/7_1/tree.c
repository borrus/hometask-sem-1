#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

Tree* initialize()
{
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;
	return tree;
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

char* getValueByKey(Tree* const tree, int const key)
{
	Node* node = getNodeByKey(tree, key);

	if (node == NULL)
	{
		return NULL;
	}

	return node->value;
}

bool keyExist(Tree* tree, int const key)
{
	return getNodeByKey(tree, key) != NULL;
}

Node* descent(Node* const subtree, int const key)
{
	
	if (key == subtree->key)
	{
		return subtree;
	}

	if (key > subtree->key && subtree->right != NULL)
	{
		return descent(subtree->right, key);
	}

	if (key < subtree->key && subtree->left != NULL)
	{
		return descent(subtree->left, key);
	}

	return NULL;
}

Node* getNodeByKey(Tree* const tree, int const key)
{
	if (tree->root == NULL)
	{
		return NULL;
	}

	return descent(tree->root, key);
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

	if (nodeToDelete == tree->root)
	{
		free(tree->root);
		tree->root = NULL;
		return;
	}

	if (nodeToDelete->left == NULL && nodeToDelete->right == NULL)
	{
		if (nodeToDelete->parent->value > nodeToDelete->value)
		{
			nodeToDelete->parent->right = NULL;
			free(nodeToDelete);
			return;
		}

		nodeToDelete->parent->left = NULL;
		free(nodeToDelete);
		return;
	}

	if (nodeToDelete->left != NULL && nodeToDelete->right != NULL)
	{
		Node* node2 = getMaxNodeLeftNode(&nodeToDelete);
		Node* node1 = nodeToDelete->parent;

		if (nodeToDelete->right != NULL)
		{
			Node* n2Right = nodeToDelete->right;
			free(nodeToDelete);

			if (node1->value > node2->value)
			{
				node1->left = node2;
				node2->parent = node1;
				node2->right = n2Right;
			}

			if (node1->value < node2->value)
			{
				node1->right = node2;
				node2->parent = node1;
				node2->right = n2Right;
			}

			return;
		}

		if (nodeToDelete->right == NULL)
		{
			free(nodeToDelete);

			if (node1->value > node2->value)
			{
				node1->left = node2;
				node2->parent = node1;
			}

			if (node1->value < node2->value)
			{
				node1->right = node2;
				node2->parent = node1;
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