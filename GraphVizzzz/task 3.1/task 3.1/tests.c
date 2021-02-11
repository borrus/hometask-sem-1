#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

bool test1Qsort()
{
	int a[3] = {2, 1, 3};
	qsortRec(a, 3);
	int current = -_CRT_INT_MAX;

	for (int i = 0; i < 3; ++i)
	{
		if (a[i] < current)
		{
			return false;
			current = a[i];
		}
	}

	return true;
}

bool test2Qsort()
{
	int a[7] = {2, 1, 3, -11, 50, 15, 21};
	qsortRec(a, 7);
	int current = -_CRT_INT_MAX;

	for (int i = 0; i < 7; ++i)
	{
		if (a[i] < current)
		{
			return false;
			current = a[i];
		}
	}

	return true;
}

bool testsQsort()
{
	if (!test1Qsort())
	{
		return false;
	}

	if (!test2Qsort())
	{
		return false;
	}

	return true;
}

bool test1InsertSort()
{
	int a[7] = {2, 1, 3, -11, 50, 15, 21};
	insertSort(a, 7);
	int current = -_CRT_INT_MAX;

	for (int i = 0; i < 7; ++i)
	{
		if (a[i] < current)
		{
			return false;
			current = a[i];
		}
	}

	return true;
}

bool test2InsertSort()
{
	int a[3] = {2, 1, 3};
	insertSort(a, 3);
	int current = -_CRT_INT_MAX;

	for (int i = 0; i < 3; ++i)
	{
		if (a[i] < current)
		{
			return false;
			current = a[i];
		}
	}

	return true;
}

bool testsInsertSort()
{
	if (!test1InsertSort())
	{
		return false;
	}

	if (!test2InsertSort())
	{
		return false;
	}

	return true;
}

bool test1SuperSort()
{
	int a[3] = { 2, 1, 3 };
	superSort(a, 3);
	int current = -_CRT_INT_MAX;

	for (int i = 0; i < 3; ++i)
	{
		if (a[i] < current)
		{
			return false;
			current = a[i];
		}
	}

	return true;
}

bool test2SuperSort()
{
	int a[11] = {2, 1, 3, 5, 4, 7, 6, 9, 8, 7, 10};
	superSort(a, 11);
	int current = -_CRT_INT_MAX;

	for (int i = 0; i < 11; ++i)
	{
		if (a[i] < current)
		{
			return false;
			current = a[i];
		}
	}

	return true;
}

bool testsSuperSort()
{
	if (!test1SuperSort())
	{
		return false;
	}

	if (!test2SuperSort())
	{
		return false;
	}

	return true;
}

bool tests()
{
	if (!testsInsertSort())
	{
		return false;
	}

	if (!testsQsort())
	{
		return false;
	}

	if (!testsSuperSort())
	{
		return false;
	}

	return true;
}