#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int strlen(char const* s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		++i;
	}

	return i;
}

void strPlusSymbol(char** strPointer, char const symbol)
{
	char* str = *strPointer;

	int const length = strlen(str);
	char* res = (char*)malloc(sizeof(char) * (length + 2));

	for (int i = 0; i < length; i++)
	{
		res[i] = str[i];
	}

	res[length] = symbol;
	res[length + 1] = '\0';

	free(*strPointer);
	*strPointer = res;
}

void strPlusStr(char** toPointer, char const* from)
{
	char* to = *toPointer;
	int const length1 = strlen(to);
	int const length2 = strlen(from);
	char* res = (char*)malloc(sizeof(char) * (length1 + length2 + 1));

	for (int i = 0; i < length1; i++)
	{
		res[i] = to[i];
	}

	for (int i = length1; i < length1 + length2; i++)
	{
		res[i] = from[i - length1];
	}

	res[length1 + length2] = '\0';

	free(*toPointer);
	*toPointer = res;
}

char* emptyStr()
{
	char* res = (char*)malloc(sizeof(char));
	res[0] = '\0';

	return res;
}

int numberLength(int number)
{
	int length = 0;

	while (number != 0)
	{
		++length;
		number /= 10;
	}

	return length;
}

char* intToStr(int number)
{
	int flag = 0;
	if (number < 0)
	{
		number *= -1;
		flag = 1;
	}

	int length = numberLength(number) + flag;

	char* res = (char*)malloc(sizeof(char) * (length + 1));
	res[length] = '\0';

	for (int i = length - 1; i >= 0 + flag; i--)
	{
		res[i] = (number % 10) + '0';
		number /= 10;
	}

	if (flag == 1)
	{
		res[0] = '-';
	}

	return res;
}

int numberLength16(int number)
{
	int length = 0;
	while (number != 0)
	{
		++length;
		number /= 16;
	}

	return length;
}

char* int10To16(int number)
{
	char bigDigits[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	int const length = numberLength16(number);
	char* res = (char*)malloc(sizeof(char) * (length + 1));
	res[length] = '\0';

	for (int i = length - 1; i >= 0; i--)
	{
		res[i] = bigDigits[number % 16];
		number /= 16;
	}

	return res;
}

bool inArray(char const* array, int const size, char symbol)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == symbol)
		{
			return true;
		}
	}

	return false;
}

char* myPrintf(char const* format, void* args, int const size)
{
	int const length = strlen(format);
	char* output = emptyStr();

	int amountOfArguments = 0;

	char legalTypes[3] = { 'i', 'c', 's' };

	for (int i = 0; i < length; i++)
	{
		while (i < length && format[i] != '%')
		{
			strPlusSymbol(&output, format[i]);
			++i;
		}

		if (i == length)
		{
			if (amountOfArguments < size)
			{
				return "incorrect expression";
			}

			return output;
		}

		int amountOfPercents = 0;

		while (i < length && format[i] == '%')
		{
			++amountOfPercents;
			++i;
		}

		int amountOfExtraPercents = amountOfPercents - (amountOfPercents % 2);
		amountOfExtraPercents /= 2;

		for (int k = 0; k < amountOfExtraPercents; k++)
		{
			strPlusSymbol(&output, '%');
		}

		if (i == length)
		{
			if (amountOfPercents % 2 == 1)
			{
				return "incorrect expression";
			}

			if (amountOfArguments < size)
			{
				return "incorrect expression";
			}

			return output;
		}

		if (amountOfPercents % 2 == 0)
		{
			--i;
			continue;
		}

		++amountOfArguments;

		char const type = format[i];

		if (inArray(legalTypes, 3, type) && amountOfArguments > size)
		{
			return "incorrect expression";
		}

		if (type == 'i')
		{
			int* intPointer = (int*)args;
			strPlusStr(&output, intToStr(*intPointer));
			args = (void*)(intPointer + 1);
		}
		else if (type == 'c')
		{
			char* charPointer = (char*)args;
			strPlusSymbol(&output, *charPointer);
			args = (void*)(charPointer + 1);
		}
		else if (type == 's')
		{
			char* str = (char*)args;
			strPlusStr(&output, str);
			args = (void*)(str + strlen(str) + 1);
		}
		else if (type == '*')
		{
			++i;
			char pointerType = format[i];

			if (!inArray(legalTypes, 3, pointerType))
			{
				return "incorrect expression";
			}

			int** intPPointer = (int**)args;
			strPlusStr(&output, intToStr(*intPPointer));
			args = (void*)(intPPointer + 1);
		}
		else
		{
			return "incorrect expression";
		}
	}

	if (amountOfArguments < size)
	{
		return "incorrect expression";
	}

	return output;
}
