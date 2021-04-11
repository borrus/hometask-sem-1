#include <stdio.h>
#include <string.h>
#include "task.h"
#include "tests.h"
#include <stdlib.h>

int main()
{
	if (!tests())
	{
		printf("tests failed\n");

		return 0;
	}

	printf("tests completed\n");
	int array[10] = { 1, 5, 3, -25, 0, 0, 15, -3, 0, 1 };
	printf("task result:\n\n");
	printf("%s\n\n", task(array, 10));

	return 0;
}