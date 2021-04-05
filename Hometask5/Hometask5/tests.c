#include "task1.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool test1()
{
	return strcmp(postfixCalculator("12+"), "3") == 0;
}

bool test2()
{
	return strcmp(postfixCalculator("12+45*+"), "23") == 0;
}

bool test3()
{
	return strcmp(postfixCalculator("15*2+"), "7") == 0;
}

bool test4()
{
	return strcmp(postfixCalculator("12+5*1+"), "16") == 0;
}

bool tests()
{
	bool flag = true;

	if (test1() == false)
	{
		printf("test1 is incorrect\n");
		flag = false;
	}

	if (test2() == false)
	{
		printf("test2 is incorrect\n");
		flag = false;
	}

	if (test3() == false)
	{
		printf("test3 is incorrect\n");
		flag = false;
	}

	if (test4() == false)
	{
		printf("test4 is incorrect\n");
		flag = false;
	}

	if (flag)
	{
		printf("tests are correct\n");
	}
}