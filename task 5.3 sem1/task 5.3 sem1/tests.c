#include <stdbool.h>
#include <stdio.h>
#include "task.h"

bool test1()
{
	if (infixToPostfix("(1+1)*2") != "11+2*")
	{
		printf("test1 failed\n");
		
		return false;
	}

	return true;
}

bool test2()
{
	if (infixToPostfix("(1+2)*3+(2+4)*2") != "12+3*24++2*")
	{
		printf("test2 failed\n");

		return false;
	}

	return true;
}

bool test3()
{
	if (infixToPostfix("5*5*6+2") == "556**2+")
	{
		printf("test3 failed\n");

		return false;
	}

	return true;
}

bool tests()
{
	return test1() && test2() && test3();
}