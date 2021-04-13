#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

bool test1()
{
	Tree* tree = (Tree*)malloc(sizeof(Tree*));

	if (tree == NULL)
	{
		return 0;
	}

	createTree(tree, "test1.txt");

	if (calculateTree(tree) != 2)
	{
		printf("test1 failed\n");
		freeTree(tree);

		return false;
	}

	freeTree(tree);

	return true;
}

bool test2()
{
	Tree* tree = (Tree*)malloc(sizeof(Tree*));

	if (tree == NULL)
	{
		return 0;
	}

	createTree(tree, "test2.txt");

	if (calculateTree(tree) != 75)
	{
		printf("test2 failed\n");
		freeTree(tree);

		return false;
	}

	freeTree(tree);

	return true;
}

bool test3()
{
	Tree* tree = (Tree*)malloc(sizeof(Tree*));

	if (tree == NULL)
	{
		return 0;
	}

	createTree(tree, "test.txt");

	if (calculateTree(tree) != 37)
	{
		printf("test3 failed\n");
		freeTree(tree);

		return false;
	}

	freeTree(tree);

	return true;
}

bool tests()
{
	return test1() && test2() && test3();
}