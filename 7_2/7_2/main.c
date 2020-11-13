#include "tree.h"
#include <stdio.h>

int main()
{
	Tree tree;
	createTree(&tree);

	printf("%c", tree.root->rightChild->value);
	return 0;
}