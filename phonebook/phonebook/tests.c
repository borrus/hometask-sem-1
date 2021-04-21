#include <stdio.h>
#include <string.h>
#include "task.h"
#include <stdbool.h>

bool test1()
{
	pushDataToFile("fileForTests.txt", "boris", "123");
	
	if (!strcmp(findNameByNumber("123", "fileForTests.txt"), "boris"))
	{
		return true;
	}

	return false;
}

bool test2()
{
	pushDataToFile("fileForTests.txt", "boris", "123");

	if (!strcmp(findNumberByName("boris", "fileForTests.txt"), "123"))
	{
		return true;
	}

	return false;
}

bool tests()
{
	if (!test1())
	{
		printf("test1 is not working\n");
		return false;
	}

	if (!test2())
	{
		printf("test2 is not working\n");
		return false;
	}

	printf("passed tests\n\n");
	return true;
}
