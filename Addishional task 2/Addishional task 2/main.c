#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf("tests failed\n");

		return 0;
	}

	printf("tests are completed\n");
	char* number = (char*)malloc(sizeof(char) * 101);
	printf("intput number:\n");
	scanf("%s", number);
	task(number);
	printf("%s", number);

	free(number);

	return 0;
}