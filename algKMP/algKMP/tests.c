#include <stdio.h>
#include <string.h>
#include "KMP.h"

void test1()
{
	printf("test 1 = ");

	if (algoritmTests("abcabc", "abc") == 1)
	{
		printf("true\n");
		return;
	}

	printf("false\n");
}

void test2()
{
	printf("test 2 = ");

	if (algoritmTests("abedbc", "abc") == 0)
	{
		printf("true\n");
		return;
	}

	printf("false\n");
}

void test3()
{
	printf("test 3 = ");

	if (algoritmTests("ab", "qwerty") == 0)
	{
		printf("true\n");
		return;
	}

	printf("false\n");
}

void algTests()
{
	test1();
	test2();
	test3();
}
