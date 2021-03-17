#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Lexer.h"

void test1()
{
	printf("test1 = ");
	if (numberLexer("54"))
	{
		printf("true\n");
		return;
	}

	printf("false\n");
}

void test2()
{
	printf("test2 = ");
	if (numberLexer("54.34"))
	{
		printf("true\n");
		return;
	}

	printf("false\n");
}

void test3()
{
	printf("test3 = ");
	if (numberLexer("54.34E10"))
	{
		printf("true\n");
		return;
	}

	printf("false\n");
}

void test4()
{
	printf("test4 = ");
	if (numberLexer("54..14"))
	{
		printf("false\n");
		return;
	}

	printf("true\n");
}

void test5()
{
	printf("test5 = ");
	if (numberLexer("e54.14"))
	{
		printf("false\n");
		return;
	}

	printf("true\n");
}

void tests()
{
	test1();
	test2();
	test3();
	test4();
	test5();
}
