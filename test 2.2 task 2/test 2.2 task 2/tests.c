#include "task.h"
#include "list.h"
#include <stdio.h>

void test1()
{
	List* list = initializeList();
	pushBack(list, 10);
	pushBack(list, 20);
	pushBack(list, 30);
	pushBack(list, 20);
	pushBack(list, 10);

	if (isSymmetric(list))
	{
		printf("test1 = true\n");
		return;
	}

	printf("test1 = false\n");
}

void test2()
{
	List* list = initializeList();
	pushBack(list, 10);
	pushBack(list, 20);
	pushBack(list, 30);
	pushBack(list, 20);
	pushBack(list, 15);

	if (isSymmetric(list))
	{
		printf("test2 = false\n");
		return;
	}

	printf("test2 = true\n");
}

void test3()
{
	List* list = initializeList();
	pushBack(list, 10);
	pushBack(list, 20);
	pushBack(list, 30);
	pushBack(list, 40);
	pushBack(list, 50);
	pushBack(list, 40);
	pushBack(list, 30);
	pushBack(list, 20);
	pushBack(list, 10);

	if (isSymmetric(list))
	{
		printf("test3 = true\n");
		return;
	}

	printf("test3 = false\n");
}

void test4()
{
	List* list = initializeList();
	pushBack(list, 10);
	pushBack(list, 20);
	pushBack(list, 30);
	pushBack(list, 45);
	pushBack(list, 50);
	pushBack(list, 40);
	pushBack(list, 35);
	pushBack(list, 20);
	pushBack(list, 10);

	if (isSymmetric(list))
	{
		printf("test4 = false\n");
		return;
	}

	printf("test4 = true\n");
}

void tests()
{
	test1();
	test2();
	test3();
	test4();
}
