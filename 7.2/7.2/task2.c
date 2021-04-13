#include "tree.h"
#include <stdio.h>

void task2()
{
	Tree tree;
	initializeTree(&tree);

	createTree(&tree);

	printf("%d", calculateTree(&tree));
}