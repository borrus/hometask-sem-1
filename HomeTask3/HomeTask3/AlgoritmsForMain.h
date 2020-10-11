#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int* array, int const length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", array[i]);
	}
}

// task1

void insertionSort(int* array, const int length);

void qsortRecursive(int* array, int const length)
{
	if (length < 10)
	{
		insertionSort(array, length);
	}
	int i = 0;
	int j = length - 1;
	int mid = array[length / 2];
	do  {
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

void insertionSort(int* array, int const length)
{
	for (int i = 1; i < length; ++i)
	{
		int temp = array[i];
		int location = i - 1;
		while (location >= 0 && array[location] > temp)
		{
			array[location + 1] = array[location];
			--location;
		}
		array[location + 1] = temp;
	}
}

//task2

bool binarySearch(int const* array, int length, int const elementToFind)
{
	int const middleIndex = length / 2;
	int const middle = array[middleIndex];
	if (elementToFind == middle)
	{
		return true;
	}

	if (length > 1)
	{
		if (elementToFind < middle)
		{
			return binarySearch(array, length / 2, elementToFind);
		}
		else
		{
			return binarySearch(array + length / 2 + 1, length / 2 - 1, elementToFind);
		}
	}

	return false;
}

void existElementsInArray()
{
	int length = 0;
	int lengthOfIntegers = 0;
	printf("provide length of origin array");
	scanf_s("%d", &length);
	printf("provide number of integer numbers");
	scanf_s("%d", &lengthOfIntegers);
	int* array = (int*)malloc(length * sizeof(int)) ;
	for (int i = 0; i < length; ++i)
	{
		array[i] = rand() % 1000;
	}
	for (int i = 0; i < lengthOfIntegers; ++i)
	{
		int currentInteger = rand() % 1000;
		binarySearch(array, length, currentInteger);
	}

	free(array);
}

//task3

int theMostCommonArrayElement(int* array, int const length)
{
	qsortRecursive(array, length);
	int counter = 0;
	int max = -1;
	int number = 0;
	int currentNumber = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		if (array[i] == array[i + 1])
		{
			++counter;
			++currentNumber;
		}
		else
		{
			if (counter > max)
			{
				max = counter;
				number = currentNumber;
			}
			counter = 0;
		}
	}

	return array[number];
}

