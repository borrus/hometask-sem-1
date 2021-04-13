#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool isOperation(char const symbol)
{
	return symbol == '*' || symbol == '/' || symbol == '-' || symbol == '+';
}

int charToInt(char const value)
{
	return (int)value - (int)'0';
}