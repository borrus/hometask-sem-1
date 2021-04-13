#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

bool test1()
{
	Tree* tree = initialize();

	if (tree == NULL)
	{
		return false;
	}

	addValueByKey(tree, 1, "a");
	addValueByKey(tree, 2, "b");
	addValueByKey(tree, 3, "c");

	if (getNodeKey(getTreeRoot(tree)) != 1)
	{
		return false;
	}

	if (getNodeKey(getRightChild(getTreeRoot(tree))) != 2)
	{
		return false;
	}

	if (getNodeKey(getRightChild(getRightChild(getTreeRoot(tree)))) != 3)
	{
		return false;
	}

	return true;
}

bool test2()
{
	Tree* tree = initialize();

	if (tree == NULL)
	{
		return false;
	}

	addValueByKey(tree, 1, "a");
	deleteElementByKey(tree, 1);

	return getTreeRoot(tree) == NULL;
}

bool test3()
{
	Tree* tree = initialize();

	if (tree == NULL)
	{
		return false;
	}

	addValueByKey(tree, 1, "qwerty");
	addValueByKey(tree, 56, "abc");
	addValueByKey(tree, 101, "abcedf");

	return strcmp(getValueByKey(tree, 56), "qwerty");
}

bool tests()
{
	if (!test1())
	{
		printf("test1 failed\n");

		return false;
	}

	if (!test2())
	{
		printf("test2 failed\n");

		return false;
	}

	if (!test3())
	{
		printf("test3 failed\n");

		return false;
	}

	printf("tests completed\n\n");

	return true;
}
