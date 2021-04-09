#include <stdio.h>
#include <stdbool.h>
#include "sortedList.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf("tests failed\n");

		return 0;
	}

	printf("Hello, these are your options: \n");
	printf("0 - exit\n");
	printf("1 - add a value to the list\n");
	printf("2 - delete value from a list\n");
	printf("3 - printf list\n");
	task();

	return 0;
}