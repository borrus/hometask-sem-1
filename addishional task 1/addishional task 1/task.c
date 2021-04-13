#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberLength(int number)
{
	if (number == 0)
	{
		return 1;
	}

	int counter = 0;

	while (number > 0)
	{
		++counter;
		number /= 10;
	}

	return counter;
}

char* intToStr(int number)
{
	int const length = numberLength(number);

	char* res = (char*)malloc(sizeof(char)* (length + 1));

	if (res == NULL)
	{
		return NULL;
	}

	res[length] = '\0';

	for (int i = length - 1; i >= 0; --i)
	{
		res[i] = (number % 10) + '0';
		number /= 10;
	}

	return res;
}

char* intArrayToStr(int const* array, int const size)
{
	char* result = (char*)malloc(sizeof(char) * 100);

	if (result == NULL)
	{
		return NULL;
	}

	result[0] = '\0';

	if (result == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < size; ++i)
	{
		strcat(result, intToStr(array[i]));
		strcat(result, " ");
	}
	
	return result;
}

void printArray(int const* array, int const size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}

void gen(int const index, int* permutation, int const size, char* output)
{
	if (index == size)
	{	
		strcat(output, intArrayToStr(permutation, size));
		strcat(output, "\n");

		return;
	}

	for (int number = 0; number < size; ++number)
	{
		permutation[index] = number;
		gen(index + 1, permutation, size, output);
	}
}

char* task(int size)
{
	char* res = (char*)malloc(sizeof(char));

	if (res == NULL)
	{
		return NULL;
	}

	res[0] = '\0';

	int* permutation = (int*)malloc(sizeof(int) * (size + 1));

	gen(0, permutation, size + 1, res);
	
	return res;
}