#include "tree.h"
#include <stdio.h>
#include <string.h>

bool test1()
{
	Tree* tree = initTree();
	push(tree, "1", "a");
	push(tree, "5", "ab");
	push(tree, "7", "abc");

	if (equalStrings(getNodeKey(getTreeRoot(tree)), "5"))
	{
		printf("test1 = true\n");

		return true;
	}

	printf("test1 = false\n");

	return false;
}

bool test2()
{
	Tree* tree = initTree();
	push(tree, "1", "a");
	push(tree, "5", "ab");
	push(tree, "7", "abc");
	deleteNodeByKey(tree, "5");

	if (equalStrings(getNodeKey(getTreeRoot(tree)), "7") && equalStrings(getNodeKey(getLeftSon(getTreeRoot(tree))), "1"))
	{
		printf("test2 = true\n");

		return true;
	}

	printf("test2 = false\n");

	return false;
}

bool test3()
{
	Tree* tree = initTree();
	push(tree, "1", "a");
	push(tree, "5", "ab");
	push(tree, "7", "abc");
	deleteNodeByKey(tree, "1");

	if (equalStrings(getNodeKey(getTreeRoot(tree)), "5") && equalStrings(getNodeKey(getRightSon(getTreeRoot(tree))), "7"))
	{
		printf("test3 = true\n");

		return true;
	}

	printf("test3 = false\n");

	return false;
}

bool test4()
{
	Tree* tree = initTree();
	push(tree, "1", "a");
	push(tree, "5", "ab");
	push(tree, "7", "abc");

	if (equalStrings(getValueByKey(tree, "5"), "ab"))
	{
		printf("test4 = true\n");

		return true;
	}

	printf("test4 = false\n");

	return false;
}

bool test5()
{
	Tree* tree = initTree();
	push(tree, "1", "a");
	push(tree, "5", "ab");
	push(tree, "7", "abc");

	if (keyExists(tree, "7"))
	{
		printf("test5 = true\n");

		return true;
	}

	printf("test5 = false\n");

	return false;
}

bool tests()
{
	printf("running all tests:\n");
	
	return test1() && test2() && test3() && test4() && test5();
}