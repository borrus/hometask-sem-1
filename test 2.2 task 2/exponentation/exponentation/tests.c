#include "algoritms.h"
#include <stdbool.h>

bool testsLinear()
{
	if (!exponentationLinearTime(2, 5) == 32)
	{
		return false;
	}

	if (!exponentationLinearTime(2, -1) == 0.5)
	{
		return false;
	}

	return true;
}

bool testsLog()
{
	if (!exponentationLogTime(2, 5) == 32)
	{
		return false;
	}

	if (!exponentationLogTime(2, -1) == 0.5)
	{
		return false;
	}

	return true;
}

bool tests()
{
	if (!testsLinear() || !testsLog())
	{
		return false;
	}

	return true;
}