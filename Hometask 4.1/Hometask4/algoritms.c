#include <stdio.h>
#include <stdbool.h>

bool* doubleConvert(int number)
{
	const int size = sizeof(int) * 8;
	bool* array = (bool*)calloc(size);
	int digit = size - 1;
	while (number != 0)
	{
		array[digit] = number % 2;
		number /= 2;
		--digit;
	}

	return array;
}

bool* doubleSum(bool* array1, bool* array2)
{
	int length = sizeof(int) * 8;
	bool* arrayOfSum = (bool*)malloc(length);
	for (int i = 0; i < length; ++i)
	{
		arrayOfSum[i] = 0;
	}
	int one = 0;
	for (int i = length - 1; i >= 0; --i)
	{
		int sum = array1[i] + array2[i] + one;
		if (sum == 1)
		{
			arrayOfSum[i] = 1;
			one = 0;
		}

		if (sum == 2)
		{
			arrayOfSum[i] = 0;
			one = 1;
		}

		if (sum == 3)
		{
			arrayOfSum[i] = 1;
			one = 1;
		}
	}

	return arrayOfSum;
}

void printBoolArrayOf32(bool const* array)
{
	for (int i = 0; i < 32; ++i)
	{
		printf("%d", array[i]);
	}

	printf("\n");
}

int boolToTen(bool const* array)
{
	int doubleElement = 1;
	int sum = 0;
	for (int i = 31; i >= 0; --i)
	{
		if (array[i] == 1)
		{
			sum += doubleElement;
		}
		doubleElement *= 2;
	}

	return sum;
}

bool testForDoubleConvert()
{
	bool* array1 = doubleConvert(7);
	for (int i = 0; i < 3; ++i)
	{
		if (array1[i] != 1)
		{
			return false;
		}
	}

	free(array1);
	return true;
}

bool testForDoubleSum()
{
	bool* array1 = doubleConvert(7);
	bool* array2 = doubleConvert(8);
	bool* array3 = doubleSum(array1, array2);
	for (int i = 0; i < 4; ++i)
	{
		if (array3[i] != 1)
		{
			return false;
		}
	}
	free(array1);
	free(array2);
	free(array3);

	return true;
}

bool testForBoolToTen()
{
	bool* array1 = doubleConvert(7);
	bool* array2 = doubleConvert(8);
	bool* array3 = doubleSum(array1, array2);
	if (boolToTen(array3) == 15)
	{
		return true;
	}

	return false;
}

void allTests()
{
	if (testForDoubleConvert)
	{
		printf("double convert is working clearly\n");
	}
	else
	{
		printf("double convert is not working properly\n");
	}

	if (testForDoubleSum)
	{
		printf("double summ is working clearly\n");
	}
	else
	{
		printf("double summ is not working properly\n");
	}

	if (testForBoolToTen)
	{
		printf("bool to ten is working clearly\n");
	}
	else
	{
		printf("bool to ten is not working properly\n");
	}
}
