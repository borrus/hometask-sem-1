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

	return 0;
}