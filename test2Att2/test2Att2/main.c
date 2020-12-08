#include <stdio.h>
#include "task.h"
#include "list.h"

int main()
{
	FILE* fileToPrint = fopen("coutFile.txt", "w");

	List* list = initializeList();
	List* listHelper1 = initializeList();
	List* listHelper2 = initializeList();

	readFromFile("text.txt", list);
	
	printf("input a & b");
	int a = 0;
	int b = 0;
	scanf("%d", &a);
	scanf("%d", &b);

	while (list->root != NULL)
	{
		if (list->root->value < a)
		{
			fprintf(fileToPrint, "%d ", list->root->value);
		}

		if (list->root->value <= b && list->root->value >= a)
		{
			push(listHelper1, list->root->value);
		}

		if (list->root->value > b)
		{
			push(listHelper2, list->root->value);
		}

		list->root = list->root->next;
	}

	while (listHelper1->root != NULL)
	{
		fprintf(fileToPrint, "%d ", listHelper1->root->value);
		listHelper1->root = listHelper1->root->next;
	}

	while (listHelper2->root != NULL)
	{
		fprintf(fileToPrint, "%d ", listHelper2->root->value);
		listHelper2->root = listHelper2->root->next;
	}
}
