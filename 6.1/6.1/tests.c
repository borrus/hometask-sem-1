#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"

bool test1Push()
{
	struct SortedList* list = initializeList();
	addToList(list, 3);
	addToList(list, 1);
	addToList(list, 2);
	
	return strcmp(toString(list), "1 2 3 ") == 0;
}

bool test2Push()
{
	struct SortedList* list = initializeList();
	addToList(list, 15);
	addToList(list, 1);
	addToList(list, 7);
	addToList(list, 4);
	addToList(list, 11);
	addToList(list, 9);
	return strcmp(toString(list), "1 4 7 9 11 15 ") == 0;
}

bool tests()
{
	if (!test1Push)
	{
		printf("test 1 failed\n");

		return false;
	}

	if (!test2Push)
	{
		printf("test 2 failed\n");

		return false;
	}

	printf("tests passed");
	return true;
}
