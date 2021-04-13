#include "Lexer.h"
#include <stdio.h>
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf("tests failed\n");

		return 0;
	}

	printf("tests completed\n\n");

	char temp[100]; 
	printf("input string:\n");
	scanf("%s", temp);

	if (numberLexer(temp))
	{
		printf("string matches regular expression\n");
	}
	else
	{
		printf("string doesnt match regular expression\n");
	}
}