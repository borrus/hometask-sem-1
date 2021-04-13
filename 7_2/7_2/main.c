#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "tree.h"

int main()
{
	if (!tests())
	{
		printf("tests are failed\n");

		return;
	}

	printf("tests completed\n\n");

	Tree* tree = (Tree*)malloc(sizeof(Tree*));

	if (tree == NULL)
	{
		return 0;
	}

	createTree(tree, "user.txt");
	printTree(tree);
	freeTree(tree);

	return 0;
}


