#include "tree.h"
#include <stdio.h>

int main()
{
	Tree tree;
	createTree(&tree);

	printf("%d", calculateTree(&tree));
	return 0;
}