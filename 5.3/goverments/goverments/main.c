#include <stdio.h>
#include "task.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf("Boris is crazy\n");
	}

	printf("tests completed\n\n\n");
	task();

	return 0;
}