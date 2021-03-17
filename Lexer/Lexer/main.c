#include "Lexer.h"
#include <stdio.h>
#include "tests.h"

int main()
{
	int temp = 0;
	printf("1 - tests\n");
	printf("2 - console\n");
	scanf("%d", &temp);

	if (temp == 1)
	{
		tests();
	}

	if (temp == 2)
	{
		char temp[100];
		printf("input string\n");
		scanf("%s", temp);
		printf("%d", numberLexer(temp));
	}
}