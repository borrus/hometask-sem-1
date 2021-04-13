#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "list.h"
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
	
	free(string);
	return 0;
}