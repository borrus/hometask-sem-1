#include <stdbool.h>
#include <stdio.h>
#include "sorts.h"

bool test1BubbleSort()
{
	int array[3] = { 3, 1, 2 };
	bubbleSort(array, 3);

	if (array[0] == 3 && array[1] == 2 && array[2] == 1)
	{
		return true;
	}

	return false;
}

bool test2BubbleSort()
{
	int array[3] = { -3, -1, -2 };
	bubbleSort(array, 3);

	if (array[0] == -1 && array[1] == -2 && array[2] == -3)
	{
		return true;
	}

	return false;
}

bool testsBubbleSort()
{
	if (!test1BubbleSort())
	{
		return false;
	}

	if (!test2BubbleSort())
	{
		return false;
	}

	return true;
}

bool test1Calc()
{
	int array[3] = { 3, 1, 2 };

	countingSort(array, 3);

	if (array[0] == 1 && array[1] == 2 && array[2] == 3)
	{
		return true;
	}

	return false;
}

bool testsCalc()
{
	if (!test1Calc())
	{
		return false;
	}

	return true;
}

bool tests()
{
	if (!testsCalc())
	{
		return false;
	}

	if (!testsBubbleSort())
	{
		return false;
	}

	return true;
}
