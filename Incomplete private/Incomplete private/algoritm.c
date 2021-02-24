#include <stdio.h>
#include <stdbool.h>

int taskHelp(int a, int const b)
{
	if (a > 0 && b > 0)
	{
		return quotientBothPositive(a, b);
	}

	if (a < 0 && b < 0)
	{
		return quotientBothNegative(a, b);
	}
	
	if (a < 0 && b > 0)
	{
		return quotientNegPos(a, b);
	}

	if (a > 0 && b < 0)
	{
		return quotientPosNeg(a, b);
	}
}

int algoritm(int dividend, int const divider)
{
	if (divider == 0)
	{
		printf("data is incorrect\n");
		return -999;
	}

	if (dividend == 0)
	{
		return 0;
	}

	return taskHelp(dividend, divider);
}

int quotientBothPositive(int a, int b)
{
	if (a < b)
	{
		return 0;
	}

	int q = 0;

	while (a >= b)
	{
		++q;
		a -= b;
	}

	return q;
}

int quotientBothNegative(int a, int b)
{
	return quotientBothPositive(-a, -b) + 1;
}

int quotientPosNeg(int a, int b)
{
	return -quotientBothPositive(a, -b) - 1;
}

int quotientNegPos(int a, int b)
{
	return -quotientBothPositive(-a, b) - 1;
}
