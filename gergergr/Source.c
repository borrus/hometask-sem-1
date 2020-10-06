#include <stdio.h>
#include <stdlib.h>
//source for task 1
void arrayPull(int* array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		array[i] = rand() % 1000;
	}
}

void qsortRecursive(int* array, int length)
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

void printArray(int* array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", array[i]);
	}
}

void reverse(int* array, int const length)
{
	for (int i = 0; i < length / 2; ++i)
	{
		int const temp = array[i];
		array[i] = array[length - i - 1];
		array[length - i - 1] = temp;
	}
}

int summAriph(int* array, int const length)
{
	if (length < 1)
	{
		return 0;
	}
	int allSum = 0;
	for (int i = 0; i < length; ++i)
	{
		allSum += array[i];
	}
	double current = allSum / length;
	printf("%lf", current);

	return 0;
}


//task 1
int task1(int* array, int const length)
{
	int temp = 0;
	scanf_s("%d",&temp);
	if (temp == 0)
	{
		return 0;
	}

	if (temp == 1)
	{
		arrayPull(array, length);
		printArray(array, length);
	}

	if (temp == 2)
	{
		qsortRecursive(array, length);
		printArray(array, length);
	}

	if (temp == 3)
	{
		reverse(array, length);
		printArray(array, length);
	}

	if (temp == 4)
	{
		summAriph(array, length);
	}

	return 0;
}

// task 2
void sortArrayOfTenElements()
{
	int const length = 10;
	int* array = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; ++i)
	{
		scanf_s("%d", &array[i]);
	}

	for (int i = 0; i < length - 1; ++i)
	{
		int minI = i;
		for (int j = i + 1; j < length; ++j) 
		{
			if (array[j] < array[minI]) 
			{
				minI= j;
			}
		}
		int temp = array[i];
		array[i] = array[minI];
		array[minI] = temp;
	}
	printArray(array, length);

	free(array);
}

int main()
{
	int array[5] = { 5,3,4,2,1 };
	
	sortArrayOfTenElements();
	return 0;
}