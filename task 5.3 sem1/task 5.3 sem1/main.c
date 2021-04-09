#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "stack.h"
#include "tests.h"

int main()
{
	if (!tests)
	{
		printf("tests failed\n");
		
		return 0;
	}

	printf("input string without spaces:\n");
	char* string = (char*)malloc(sizeof(char) * 100);
	scanf("%s", string);
	printf("%s", infixToPostfix(string));
	
	return 0;
}