#include "cycleList.h"
#include <stdbool.h>
#include <stdio.h>

bool test1()
{
	struct CycleList* list = initializeList();
	addElement(list, 1);
	addElement(list, 2);
	addElement(list, 3);
	addElement(list, 4);
	addElement(list, 5);
	
	return joseph(list, 3) == 4;
}

bool test2()
{
	struct CycleList* list = initializeList();
	addElement(list, 1);
	addElement(list, 2);
	addElement(list, 3);
	addElement(list, 4);
	addElement(list, 5);

	return joseph(list, 1) == 5;
}

bool test3()
{
	struct CycleList* list = initializeList();
	addElement(list, 1);
	addElement(list, 2);
	
	return joseph(list, 1) == 2;
}

bool tests()
{
	if (!test1())
	{
		printf("tests 1 failed\n");

		return false;
	}

	if (!test2())
	{
		printf("tests 2 failed\n");

		return false;
	}

	if (!test3())
	{
		printf("tests 3 failed\n");

		return false;
	}

	printf("all tests passed\n\n\n");

	return true;
}