#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
//
//int main()
//{
//	Tree* tree = initialize();
//	int temp = 1;
//	printf("1 - add value by key\n");
//	printf("2 - get value by key\n");
//	printf("3 - checking for key existence\n");
//	printf("4 - delete key and value by key\n");
//
//	while (temp != 0)
//	{
//		scanf("%d", &temp);
//
//		if (temp == 1)
//		{
//			printf("enter key\n");
//			int key = 0;
//			scanf("%d", &key);
//			printf("enter value\n");
//			char value[100];
//			scanf("%s", &value);
//			addValueByKey(tree, key, value);
//			printf("value added\n");
//		}
//		else if (temp == 2)
//		{
//			printf("enter key\n");
//			int key = 0;
//			scanf("%d", &key);
//			printf("%s\n", getValueByKey(tree, key));
//		}
//		else if (temp == 3)
//		{
//			printf("enter key\n");
//			int key = 0;
//			scanf("%d", &key);
//
//			if (keyExist(tree, key) == 0)
//			{
//				printf("key doesnt exist\n");
//			}
//			else
//			{
//				printf("key exists\n");
//			}
//		}
//		else if (temp == 4)
//		{
//			printf("enter key\n");
//			int key = 0;
//			scanf("%d", &key);
//			deleteElementByKey(tree, key);
//		}
//	}
//
//	free(tree);
//
//	return 0;
//}

int main()
{
	Tree* tree = initialize();
	addValueByKey(tree, 123, "abc");
	addValueByKey(tree, 123, "qwer");
}

