#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task.h"

bool test1()
{
	if (!strcmp(task(0),"0 \n"))
	{
		printf("test1 = true\n");

		return true;
	}

	printf("test1 = false\n");

	return false;
}

bool test2()
{
	if (!strcmp(task(1), "0 0 \n0 1 \n1 0 \n1 1 \n"))
	{
		printf("test2 = true\n");
		
		return true;
	}

	printf("test2 = false\n");

	return false;
}

bool tests()
{
	return test1() && test2();
}