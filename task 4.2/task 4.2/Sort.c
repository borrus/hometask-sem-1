#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

void qsortRecursive(int* array, int const length)
{
	int i = 0;
	int j = length - 1;
	int mid = array[length / 2];
	do {
		while (array[i] < mid)
		{
			++i;
		}
		while (array[j] > mid)
		{
			--j;
		}

		if (i <= j)
		{
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			++i;
			--j;
		}
	} while (i <= j);

	if (j > 0)
	{
		qsortRecursive(array, j + 1);
	}
	if (i < length)
	{
		qsortRecursive(&array[i], length - i);
	}
}