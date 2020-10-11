#pragma once
#include "AlgoritmsForMain.h"
#include "tests.h"

//tests for task 1;

bool testForSorts(int* array, int const length)
{
	qsortRecursive(array, length);
	for (int i = 0; i < length - 1; ++i)
	{
		if (array[i] >= array[i + 1])
		{
			return false;
		}
	}

	return true;
}

void testsForSorts()
{
	printf("tests for sortings (task 1): \n");
	int array1[5] = { 5, 4, 3, 2, 1 };
	printf("test 1: ");
	if (testForSorts(array1, 5))
	{
		printf("true;   expected positive result \n");
	}
	else
	{
		printf("false;   expected positive result \n");
	}

	int array2[7] = { 1, 3, 5, 11, 23, 15, 13 };
	printf("test 2: ");
	if (testForSorts(array2, 7))
	{
		printf("true;   expected positive result\n\n");
	}
	else
	{
		printf("false;   expected positive result \n");
	}
}

//tests for task 2

void testForTask2()
{
	printf("tests (task2): \n");
	int array1[5] = { 1, 2, 3, 4, 5 };
	int array2[3] = { 1, 1, 6 };

	bool* isOrNot = boolArrayOfNumbers(array1, 5, array2, 3);
	bool ok = false;
	if (isOrNot[0] && isOrNot[1] && !isOrNot[2])
	{
		ok = true;
	}

	if (ok)
	{
		printf("test 1: true;   expected positive result\n\n");
	}
	else
	{
		printf("test 1: false;   expected positive result\n\n");
	}

	free(isOrNot);
}

//tests for task 3;

void testForFindingMostCommonElementInArray(int* array, int const length, int testNumber)
{
	if (theMostCommonArrayElement(array, length) == testNumber)
	{
		printf("true;   ");
	}
	else
	{
		printf("false;  ");
	}
}

void testsForFindingMostCommonElementInArray()
{
	printf("testsForFindingMostCommonElementInArray (task3): \n");
	int array1[5] = { 1, 5, 4, 1, 2 };
	printf("test 1: ");
	testForFindingMostCommonElementInArray(array1, 5, 1);
	printf("expected positive result\n");
	printf("test 2: ");
	testForFindingMostCommonElementInArray(array1, 5, 3);
	printf("expected negative result\n");
	int array2[4] = { 5, 4, 4, 3 };
	printf("test 3: ");
	testForFindingMostCommonElementInArray(array2, 4, 4);
	printf("expected positive result\n");
	printf("test 4: ");
	testForFindingMostCommonElementInArray(array2, 4, 3);
	printf("expected negative result\n");
}

void allTests()
{
	testsForSorts();
	testForTask2();
	testsForFindingMostCommonElementInArray();
}