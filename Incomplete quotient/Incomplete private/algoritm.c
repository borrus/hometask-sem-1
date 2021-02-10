#include <stdio.h>

int positive(int a, int const b)
{
	int counter = 0;

	while (a >= b)
	{
		++counter;
		a -= b;
	}

	return counter;
}

int positiveNegative(int a, int const b)
{
	int counter = 0;

	while (a >= -b)
	{
		a += b;
		--counter;
	}

	return counter;
}

int negativePositive(int a, int const b)
{
	int counter = 0;

	while (-a >= b)
	{
		a += b;
		--counter;
	}

	return counter;
}

int negative(int a, int const b)
{
	int counter = 0;

	while (-a >= -b)
	{
		a -= b;
		++counter;
	}

	return counter;
}

int algoritm()
{
	int a = 0;
	int b = 0;
	printf("input dividend: \n");
	scanf("%d", &a);
	printf("input divider: \n");

	scanf("%d", &b);

	if (b == 0)
	{
		printf("data is incorrect\n");
		return -999;
	}

	if (a == 0)
	{
		return 0;
	}

	if (a > 0 && b > 0)
	{
		return positive(a, b);
	}

	if (a > 0 && b < 0)
	{
		return positiveNegative(a, b);
	}

	if (a < 0 && b > 0)
	{
		return negativePositive(a, b);
	}

	if (a <0 && b < 0)
	{
		return negative(a, b);
	}
}