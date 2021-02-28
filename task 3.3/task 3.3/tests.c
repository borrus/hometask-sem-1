#include <stdio.h>
#include <stdbool.h>
#include "task.h"

bool test1()
{
	int array[3] = { 1,2,2 };
	
	return task(array, 3) == 2;
}

bool test2()
{
	int array[4] = { 1,1,2,2 };
	
	return task(array, 4) == 1;
}

bool test3()
{
	int array[14] = { 9,1,9,2,3,7,6,5,4,9, 1, 2, 12, 15 };

	return task(array, 14) == 9;
}

bool tests()
{
	return test1() && test2() && test3();
} 