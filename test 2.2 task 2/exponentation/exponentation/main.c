#include <stdio.h>
#include "algoritms.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf("fail");
		return -999;
	}

	int number = 0;
	int degree = 0;
	printf("input number:\n");
	scanf("%d", &number);
	printf("input degree:\n");
	scanf("%d", &degree);

	printf("%g", exponentationLogTime(number, degree));
}