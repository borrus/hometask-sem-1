#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "task.h"

bool test1()
{
	Node* node = initializeNode(100);

	if (node == NULL)
	{
		printf("test1 failed\n");

		return false;
	}

	if (getNodeValue(node) != 100)
	{
		printf("test1 failed\n");
		free(node);

		return false;
	}

	printf("test1 = true\n");
	free(node);

	return true;
 }

bool test2()
{
	List* list = initializeList();

	if (list == NULL)
	{
		printf("test2 failed\n");
		free(list);

		return false;
	}

	printf("test2 = true\n");
	free(list);

	return true;
}

bool test3()
{
	List* list = initializeList();

	if (list == NULL)
	{
		printf("test3 failed\n");
		free(list);

		return false;
	}

	pushBack(list, 1);

	if (getNodeValue(getListRoot(list)) != 1)
	{
		printf("test3 failed\n");
		free(list);

		return false;
	}

	printf("test3 = true\n");
	free(list);

	return true;
}

bool test4()
{
	List* list = initializeList();

	if (list == NULL)
	{
		printf("test4 failed\n");
		free(list);

		return false;
	}

	pushBack(list, 1);
	pushBack(list, 1);
	popBack(list);

	if (getNodeValue(getListRoot(list)) != 1 || getNextNode(getListRoot(list)) != NULL)
	{
		printf("test4 failed\n");
		free(list);

		return false;
	}

	printf("test4 = true\n");
	free(list);

	return true;
}

bool test5()
{
	List* list = initializeList();

	if (list == NULL)
	{
		printf("test5 failed\n");
		free(list);

		return false;
	}

	pushBack(list, 1);
	pushBack(list, 1);
	popFront(list);

	if (getNodeValue(getListRoot(list)) != 1 || getNextNode(getListRoot(list)) != NULL)
	{
		printf("tes5 failed\n");
		free(list);

		return false;
	}

	printf("test5 = true\n");
	free(list);

	return true;
}

bool test6()
{
	List* list = initializeList();

	if (list == NULL)
	{
		printf("test6 failed\n");
		free(list);

		return false;
	}

	pushBack(list, 1);
	pushBack(list, 2);
	pushBack(list, 3);

	if (getNodeByValue(list, 2) != getNextNode(getListRoot(list)))
	{
		printf("test6 failed\n");
		free(list);

		return false;
	}

	printf("test6 = true\n");
	free(list);

	return true;
}

bool test7()
{
	List* list = initializeList();

	if (list == NULL)
	{
		printf("test7 failed\n");
		free(list);

		return false;
	}

	pushBack(list, 1);
	pushBack(list, 2);
	pushBack(list, 3);

	if (!valueExists(list, 3))
	{
		printf("test7 failed\n");
		free(list);

		return false;
	}

	printf("test7 = true\n");
	free(list);

	return true;
}

bool test8()
{
	List* list = initializeList();

	if (list == NULL)
	{
		printf("test8 failed\n");
		free(list);

		return false;
	}

	pushBack(list, 1);
	pushBack(list, 1);
	deleteNodeByValue(list, 1);

	if (getNodeValue(getListRoot(list)) != 1 || getNextNode(getListRoot(list)) != NULL)
	{
		printf("test8 failed\n");
		free(list);

		return false;
	}

	printf("test8 = true\n");
	free(list);

	return true;
}


bool tests()
{
	return test1() && test2() && test3() && test4() && test5() && test6() && test7() && test8();
}