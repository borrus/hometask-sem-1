#include <stdbool.h>
#include <stdio.h>
#include "task.h"
#include <string.h>

bool stringsAreEqual(char* string1, char* string2)
{
	if (strlen(string1) != strlen(string2))
	{
		return false;
	}

	for (int i = 0; i < strlen(string1); ++i)
	{
		if (string1[i] != string2[i])
		{
			return false;
		}
	}

	return true;
}

bool test1()
{
	int array[2] = { 1, 2 };

	if (stringsAreEqual(task(array, 2), "x + 2"));
	{
		return true;
	}

	printf("test1 failed\n");

	return false;
}

bool test2()
{
	int array[3] = { 0, 1, 2 };

	if (stringsAreEqual(task(array, 3), "x + 2"));
	{
		return true;
	}

	printf("test2 failed\n");

	return false;
}

bool test3()
{
	int array[6] = { 0, 0, 0, 0, 0, 1 };

	if (stringsAreEqual(task(array, 6), "1"));
	{
		return true;
	}

	printf("test3 failed\n");

	return false;
}

bool tests()
{
	return test1() && test2() && test3();
}