#include "sortedList.h"
#include <stdio.h>
#include <stdbool.h>

int task()
{
	printf("Hello, these are your options: \n");
	printf("0 - exit\n1 - add a value to the list\n2 - delete value from a list\n3 - printf list\n");
	SortedList list;
	initializeList(&list);
	
	int menuItem = -1;
	while (true)
	{
		scanf("%d", &menuItem);
		if (menuItem == 0)
		{
			printf("bye :)");
			break;
		}

		if (menuItem == 1)
		{
			int value = 0;
			printf("input value: ");
			scanf("%d", &value);
			addToList(&list, value);
			continue;
		}

		if (menuItem == 2)
		{
			int value = 0;
			printf("input value: ");
			scanf("%d", &value);
			deleteElement(&list, value);
			continue;
		}

		if (menuItem == 3)
		{
			printList(list);
			continue;
		}
	}
}