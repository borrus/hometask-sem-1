#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
	struct Node* left;
	struct Node* right;
	char* value;
	int height;
	char* key;
} Node;

typedef struct Tree
{
	Node* root;
} Tree;

Node* getTreeRoot(Tree* tree)
{
	return tree->root;
}

Node* getLeftSon(Node* node)
{
	return node->left;
}

Node* getRightSon(Node* node)
{
	return node->right;
}

char* getNodeValue(Node* node)
{
	return node->value;
}

char* getNodeKey(Node* node)
{
	return node->key;
}

char* copyStr(char const* from)
{
	char* result = (char*)malloc((strlen(from) + 1) * sizeof(char));

	if (result == NULL)
	{
		return NULL;
	}

	strcpy(result, from);
	return result;
}

bool firstStringIsBiggerSecond(char const* first, char const* second)
{
	if (strlen(first) > strlen(second))
	{
		return true;
	}

	if (strlen(first) < strlen(second))
	{
		return false;
	}

	for (int i = 0; i < strlen(first); ++i)
	{
		if (((int)first[i] - '0') > ((int)second[i] - '0'))
		{
			return true;
		}

		if (((int)first[i] - '0') < ((int)second[i] - '0'))
		{
			return false;
		}
	}

	return false;
}

bool equalStrings(char const* first, char const* second)
{
	if (strlen(first) != strlen(second))
	{
		return false;
	}

	for (int i = 0; i < strlen(first); ++i)
	{
		if (((int)first[i] - '0') != ((int)second[i] - '0'))
		{
			return false;
		}
	}

	return true;
}

Node* initRoot(char const* key, char const* value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		return NULL;
	}

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->value = copyStr(value);
	newNode->height = 1;
	newNode->key = copyStr(key);

	return newNode;
}

Tree* initTree()
{
	return calloc(1, sizeof(Tree));
}

int height(Node* node)
{
	if (node != NULL)
	{
		return node->height;
	}

	return 0;
}

int balanceFactor(Node* node)
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

	if (balanceFactor(node) == 2)
	{
		if (balanceFactor(node->right) < 0)
		{
			node->right = rightRotate(node->right);
		}

		return leftRotate(node);
	}

	if (balanceFactor(node) == -2)
	{
		if (balanceFactor(node->left) > 0)
		{
			node->left = leftRotate(node->left);
		}

		return rightRotate(node);
	}

	return node;
}

Node* pushNode(Node* node, char const* key, char const* value)
{
	if (node == NULL)
	{
		node = initRoot(key, value);
	}

	if (firstStringIsBiggerSecond(node->key, key))
	{
		node->left = pushNode(node->left, key, value);
	}

	if (firstStringIsBiggerSecond(key, node->key))
	{
		node->right = pushNode(node->right, key, value);
	}

	return 	balance(node);
}

void push(Tree* tree, char const* key, char const* value)
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

Node* removeNode(Node* node, char const* key)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (firstStringIsBiggerSecond(node->key, key))
	{
		node->left = removeNode(node->left, key);
	}
	else if (firstStringIsBiggerSecond(key, node->key))
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

void deleteNodeByKey(Tree* tree, char const* key)
{
	if (tree->root == NULL)
	{
		return;
	}

	tree->root = removeNode(tree->root, key);
}

char* getValueByKeyNode(Node* node, char const* key)
{
	if (node == NULL)
	{
		return " ";
	}

	if (equalStrings(key, node->key))
	{
		return node->value;
	}

	if (firstStringIsBiggerSecond(key, node->key))
	{
		return getValueByKeyNode(node->right, key);
	}

	if (firstStringIsBiggerSecond(node->key, key))
	{
		return getValueByKeyNode(node->left, key);
	}
}

char* getValueByKey(Tree* tree, char const* key)
{
	if (tree->root == NULL)
	{
		return " ";
	}

	return getValueByKeyNode(tree->root, key);
}

bool keyExists(Tree* tree, char const* key)
{
	if (tree->root == NULL)
	{
		return false;
	}

	return getValueByKey(tree, key) != NULL;
}