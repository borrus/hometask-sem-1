#include <stdio.h>

double exponentationLinearTime(int number, int const degree)
{
	int result = 1;

	if (degree > 0)
	{
		for (int i = 0; i < degree; ++i)
		{
			result *= number;
		}

		return result;
	}
	
	if (degree < 0)
	{
		for (int i = 0; i < -degree; ++i)
		{
			result *= number;
		}

		double temp = 1 / result;
		return temp;
	}
}

double exponentationLogTimeRecPos(int number, int degree)
{
	if (degree == 0)
	{
		return 1;
	}

	if (degree % 2 == 1)
	{
		return exponentationLogTimeRecPos(number, degree - 1) * number;
	}
	else
	{
		double temp = exponentationLogTimeRecPos(number, degree / 2);
		return temp * temp;
	}
}

double exponentationLogTime(int number, int const degree)
{
	double result = 1;

	if (degree >= 0)
	{
		return exponentationLogTimeRecPos(number, degree);
	}

	if (degree < 0)
	{
		int deg = -degree;
		double temp = 1 / exponentationLogTimeRecPos(number, deg);
		return temp;
	}
}