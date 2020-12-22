#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void readFromFile(List* list, char const* path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		printf("file is not found");
		return;
	}

	while (!feof(file))
	{
		char temp[10000];
		fscanf(file, "%s", temp);

		if (!valueExists(list, copyStr(temp)))
		{
			pushBack(list, copyStr(temp));
		}
	}
}

void writeToFile(List const* list, char const* path)
{
	FILE* file = fopen(path, "w+");

	if (file == NULL)
	{
		printf("file is not found");
		return;
	}
	
	Node* node = list->root;

	while (node != NULL)
	{
		fprintf(file, "%s\n", node->value);
		node = node->next;
	}
}

void task1()
{
	List* list = initializeList();

	readFromFile(list, "text.txt");

	sortList(list);

	writeToFile(list, "output.txt");
}