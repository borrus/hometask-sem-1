#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include"utilities.h"

Node* initRoot(int key, char* value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->value = copyStr(value);
	newNode->height = 1;
	newNode->key = key;

	return newNode;
}

Tree* initTree()
{
	Tree* newTree = (Tree*)malloc(sizeof(Tree));
	newTree->root = NULL;

	return newTree;
}

Node* pushNode(Node* node, int key, char* value)
{
	if (node == NULL)
	{
		node = initRoot(key, value);
	}

	if (key < node->key)
	{
		node->left = pushNode(node->left, key, value);
	}

	if (key > node->key)
	{
		node->right = pushNode(node->right, key, value);
	}

	return 	balance(node);
}

void push(Tree* tree, int key, char* value)
{
	if (tree == NULL)
	{
		return;
	}

	tree->root = pushNode(tree->root, key, value);
}

Node* findMin(Node* node)
{
	return node->left ? findMin(node->left) : node;
}

Node* removeMin(Node* node)
{
	if (node->left == NULL)
	{
		return node->right;
	}

	node->left = removeMin(node->left);
	return balance(node);
}

Node* removeNode(Node* node, int key)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (key < node->key)
	{
		node->left = removeNode(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = removeNode(node->right, key);
	}
	else
	{
		Node* left = node->left;
		Node* right = node->right;
		free(node);
		
		if (right == NULL)
		{
			return left;
		}

		Node* min = findMin(right);
		min->right = removeMin(right);
		min->left = left;
		return balance(min);
	}

	return balance(node);
}

void deleteNodeByKey(Tree* tree, int key)
{
	if (tree->root == NULL)
	{
		return;
	}

	tree->root = removeNode(tree->root, key);
}

//Проверить функцию.
char* getValueByKeyNode(Node* node, int key)
{
	if (node == NULL)
	{
		return "\0";
	}

	if (key == node->key)
	{
		return node->value;
	}

	if (key > node->key)
	{
		return getValueByKeyNode(node->right, key);
	}

	if (key < node->key)
	{
		return getValueByKeyNode(node->left, key);
	}
}

//Проверить функцию.
char* getValueByKey(Tree* tree, int key)
{
	if (tree->root == NULL)
	{
		return "\0";
	}

	return getValueByKeyNode(tree->root, key);
}

//Проверить функцию.
bool keyExistsNode(Node* node, int key)
{
	if (node == NULL)
	{
		return false;
	}

	if (node->key == key)
	{
		return true;
	}

	if (node->key > key)
	{
		return keyExistsNode(node->left, key);
	}

	if (node->key < key)
	{
		return keyExistsNode(node->right, key);
	}
}

//Проверить функцию.
bool keyExists(Tree* tree, int key)
{
	if (tree->root == NULL)
	{
		return false;
	}

	return keyExistsNode(tree->root, key);
}