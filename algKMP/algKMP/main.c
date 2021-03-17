#include <stdio.h>
#include <string.h>
#include "tests.h"
#include "task.h"

int main()
{	
	int temp = 0;
	printf("1 - run KMP tests\n");
	printf("2 - own check from file\n");
	scanf("%d", &temp);

	if (temp == 1)
	{
		algTests();
	}
	if (temp == 2)
	{
		printf("input substring\n");
		printf("%d", task());
	}
	
}