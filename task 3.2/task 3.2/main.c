#include <stdio.h>
#include "task.h"

int main()
{
	int n = 0;
	int k = 0;
	printf("input size:\n");
	scanf("%d", &n);
	printf("input quantity of numbers:\n");
	scanf("%d", &k);

	task(n, k);
}