#include <stdio.h>
#include "sorts.h"

int task(int* array, int const length)
{
	qsortRec(array, length);
	int counter = 1;
	int currentElement = 0;
	int max = -_CRT_INT_MAX;
	int elementToReturn = 0;

	for (int i = 0; i < length; ++i)
	{
		if (currentElement == array[i])
		{
			++counter;
		}
		else
		{
			counter = 1;
		}

		if (counter > max)
		{
			max = counter;
			elementToReturn = currentElement;
		}
		
		currentElement = array[i];
	}

	return elementToReturn;
}