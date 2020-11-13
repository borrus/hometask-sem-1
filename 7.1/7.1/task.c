#include "tree.h"
#include <stdio.h>

void task()
{
	Tree* tree;
	initialize(&tree);
	int temp = 1;
	printf("1 - add value by key\n2 - get value by key\n3 - checking for key existence\n4 - delete key and value by key\n");
	while (temp != 0)
	{
		if (!scanf("%d", &temp))
		{
			return;
		}

		if (temp == 1)
		{
			printf("enter key\n");
			int key = 0;

			if (!scanf("%d", &key))
			{
				return;
			}

			printf("enter value\n");
			int value = 0;

			if (!scanf("%d", &value))
			{
				return;
			}

			addValueByKey(&tree, key, value);
			printf("value added\n");
		}

		if (temp == 2)
		{
			printf("enter key\n");
			int key = 0;

			if (!scanf("%d", &key))
			{
				return;
			}

			printf("%d\n", getValueByKey(&tree, key));
		}

		if (temp == 3)
		{
			printf("enter key\n");
			int key = 0;

			if (!scanf("%d", &key))
			{
				return;
			}

			if (keyExist(&tree, key) == 0)
			{
				printf("key doesnt exist\n");
			}
			else
			{
				printf("key exists\n");
			}
		}

		if (temp == 4)
		{
			printf("enter key\n");
			int key = 0;

			if (!scanf("%d", &key))
			{
				return;
			}

			deleteElementByKey(&tree, key);
		}
	}
}