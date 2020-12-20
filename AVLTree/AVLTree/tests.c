#include "node.h"
#include "utilities.h"
#include <stdio.h>
#include <string.h>

void test1()
{
	Tree* tree = initTree();
	push(tree, 1, "a");
	push(tree, 5, "ab");
	push(tree, 7, "abc");

	if (tree->root->key == 5 && tree->root->left->key == 1 && tree->root->right->key == 7)
	{
		printf("test1 = true\n");
		return;
	}

	printf("test1 = false\n");
}

void test2()
{
	Tree* tree = initTree();
	push(tree, 1, "a");
	push(tree, 5, "ab");
	push(tree, 7, "abc");
	deleteNodeByKey(tree, 5);

	if (tree->root->key == 7 && tree->root->left->key == 1)
	{
		printf("test2 = true\n");
		return;
	}

	printf("test2 = false\n");
}

void test3()
{
	Tree* tree = initTree();
	push(tree, 1, "a");
	push(tree, 5, "ab");
	push(tree, 7, "abc");
	deleteNodeByKey(tree, 1);

	if (tree->root->key == 5 && tree->root->right->key == 7)
	{
		printf("test3 = true\n");
		return;
	}

	printf("test3 = false\n");
}

void test4()
{
	Tree* tree = initTree();
	push(tree, 1, "a");
	push(tree, 5, "ab");
	push(tree, 7, "abc");

	if (!strcmp(getValueByKey(tree, 5), "ab"))
	{
		printf("test4 = true\n");
		return;
	}

	printf("test4 = false\n");
}

void test5()
{
	Tree* tree = initTree();
	push(tree, 1, "a");
	push(tree, 5, "ab");
	push(tree, 7, "abc");

	if (keyExists(tree, 7))
	{
		printf("test5 = true\n");
		return;
	}

	printf("test5 = false\n");
}

void tests()
{
	printf("running all tests:\n");
	test1();
	test2();
	test3();
	test4();
	test5();
}