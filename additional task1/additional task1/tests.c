#include <stdbool.h>
#include <stdio.h>
#include "task.h"
#include <string.h>
#include "utilities.h"

bool test1()
{
	char* number = copyStr("241356");
	task(number);

	if (strcmp(number, "123456") != 0)
	{
		printf("test1 failed\n");

		return false;
	}

	return true;
}

bool test2()
{
	char* number = copyStr("9876543210");
	task(number);

	if (strcmp(number, "1023456789") != 0)
	{
		printf("test2 failed\n");

		return false;
	}

	return true;
}

bool test3()
{
	char* number = copyStr("000987654321");
	task(number);

	if (strcmp(number, "100023456789") != 0)
	{
		printf("test3 failed\n");

		return false;
	}

	return true;
}

bool tests()
{
	return test1() && test2() && test3();
}