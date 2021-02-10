#include <stdio.h>
#include "algoritm.h"

int main()
{
	int a = 0;
	int b = 0;
	printf("input dividend: \n");
	scanf("%d", &a);
	printf("input divider: \n");
	scanf("%d", &b);

	printf("%d", algoritm(a, b));
}