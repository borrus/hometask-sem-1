#include <stdio.h>
#include <stdbool.h>

bool* doubleConvert(int number)
{
	bool* array = (bool*)malloc(sizeof(int) * 8);
	for (int i = 31; i >= 0; --i)
	{
		array[i] = 0;
	}
	int digit = 31;
	while (number != 0)
	{
		array[digit] = number % 2;
		number /= 2;
		--digit;
	}

	return array;
}

bool* doubleSumm(bool* array1, bool* array2)
{
	int length = sizeof(int) * 8;
	bool* arrayOfSumm = (bool*)malloc(length);
	for (int i = 0; i < length; ++i)
	{
		arrayOfSumm[i] = 0;
	}
	int one = 0;
	for (int i = length - 1; i >= 0; --i)
	{
		int sum = array1[i] + array2[i] + one;
		if (sum == 1)
		{
			arrayOfSumm[i] = 1;
			one = 0;
		}

		if (sum == 2)
		{
			arrayOfSumm[i] = 0;
			one = 1;
		}

		if (sum == 3)
		{
			arrayOfSumm[i] = 1;
			one = 1;
		}
	}

	return arrayOfSumm;
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
	int dvoika = 1;
	int sum = 0;
	for (int i = 31; i >= 0; --i)
	{
		if (array[i] == 1)
		{
			sum += dvoika;
		}
		dvoika *= 2;
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

	return true;
}

bool testForDoubleSumm()
{
	bool* array1 = doubleConvert(7);
	bool* array2 = doubleConvert(8);
	bool* array3 = doubleSumm(array1, array2);
	for (int i = 0; i < 4; ++i)
	{
		if (array3[i] != 1)
		{
			return false;
		}
	}

	return true;
}

bool testForBoolToTen()
{
	bool* array1 = doubleConvert(7);
	bool* array2 = doubleConvert(8);
	bool* array3 = doubleSumm(array1, array2);
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

	if (testForDoubleSumm)
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
