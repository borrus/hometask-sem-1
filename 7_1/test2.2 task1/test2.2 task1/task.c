#include <stdio.h>
#include <stdbool.h>

char* copyStr(char const* from)
{
	char* result = (char*)malloc((strlen(from) + 1) * sizeof(char));
	strcpy(result, from);
	return result;
}

int charToDigit(char const symbol)
{
	return (int)symbol - (int)'0';
}

bool firstIsBiggerThanSecond(char const* first, char const* second)
{
	int year1 = 0;
	int year2 = 0;
	int tenPower = 1;
	for (int i = 9; i >= 6; --i)
	{
		year1 += tenPower * charToDigit(first[i]);
		year2 += tenPower * charToDigit(second[i]);
		tenPower *= 10;
	}

	tenPower = 1;
	int month1 = 0;
	int month2 = 0;
	for (int i = 4; i >= 3; --i)
	{
		month1 += tenPower * charToDigit(first[i]);
		month2 += tenPower * charToDigit(second[i]);
		tenPower *= 10;
	}

	tenPower = 1;
	int day1 = 0;
	int day2 = 0;
	for (int i = 1; i >= 0; --i)
	{
		day1 += tenPower * charToDigit(first[i]);
		day2 += tenPower * charToDigit(second[i]);
		tenPower *= 10;
	}

	if (year1 > year2)
	{
		return true;
	}

	if (month1 > month2 && year1 == year2)
	{
		return true;
	}

	if (day1 > day2 && year1 == year2 && month1 == month2)
	{
		return true;
	}

	return false;
}

char* task(char const* path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		return;
	}

	char* max = copyStr("00.00.0000");

	while (!feof(file))
	{
		char date[11];

		fscanf(file, "%s", date);

		if (firstIsBiggerThanSecond(date, max))
		{
			max = copyStr(date);
		}
	}

	return copyStr(max);
}
