#include <stdio.h>
#include "task1.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf("tests are incorrect");

		return 0;
	}

	printf("%s", postfixCalculator(inputStringFromConsole()));

	return 0;
}