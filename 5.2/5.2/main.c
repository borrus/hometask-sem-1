#include <stdio.h>
#include <stdlib.h>
#include "brackets.h"
#include "stack.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		return 0;
	}

	char* string = (char*)malloc(sizeof(char) * 100);
	printf("input expression:\n");
	scanf("%s", string);
	printf("%d", bracketsBalance(string));

	return 0;
}