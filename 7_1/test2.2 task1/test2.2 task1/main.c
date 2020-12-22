#include <stdio.h>
#include "task.h"


void tests()
{
	printf("%s\n", task("test1.txt"));
	printf("%s\n", task("test2.txt"));
	printf("%s\n", task("test3.txt"));
}

int main()
{
	tests();
}