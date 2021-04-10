#include <stdbool.h>
#include <stdio.h>
#include "brackets.h"

bool test1()
{
	return bracketsBalance("(())") == 1;
}

bool test2()
{
	return bracketsBalance("(()") == 0;
}

bool test3()
{
	return bracketsBalance("(([]))") == 1;
}

bool test4()
{
	return bracketsBalance("(wef(abcdef)scd)") == 1;
}

bool test5()
{
	return bracketsBalance("(({))}") == 0;
}

bool test6()
{
	return bracketsBalance("((") == 0;
}

bool test7()
{
	return bracketsBalance("())") == 0;
}

bool tests()
{
	if (!test1())
	{
		printf("test1 is failed\n");

		return false;
	}

	if (!test2())
	{
		printf("test2 is failed\n");

		return false;
	}

	if (!test3())
	{
		printf("test3 is failed\n");

		return false;
	}

	if (!test4())
	{
		printf("test4 is failed\n");

		return false;
	}

	if (!test5())
	{
		printf("test5 is failed\n");

		return false;
	}

	if (!test6())
	{
		printf("test6 is failed\n");

		return false;
	}

	if (!test7())
	{
		printf("test7 is failed\n");

		return false;
	}

	printf("completed tests. No issues.\n");
}