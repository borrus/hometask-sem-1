#include <stdio.h>
#include <stdbool.h>

bool isEqualSign(int const a, int const b)
{
	if (a > 0 && b > 0 || a < 0 && b < 0)
	{
		return true;
	}

	return false;
}

int taskHelp(int a, int const b)
{
	int counter = 0;

	if (isEqualSign(a, b))
	{
		if (a >= b)
		{
			while (a >= b)
			{
				++counter;
				a -= b;
			}
		}
		else
		{
			while (-a >= -b)
			{
				++counter;
				a -= b;
			}
		}
	}
	else
	{
		while (a >= -b)
		{
			a += b;
			--counter;
		}
	}

	return counter;
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