#include <stdio.h>
#include "list.h"
#include <stdbool.h>

void readFromFile(List const* list, char const* path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		printf("file is empty");
		return;
	}

	while (!feof(file))
	{
		int temp = 0;
		fscanf(file, "%d", &temp);
		pushBack(list, temp);
	}
}

bool isSymmetric(List const* list)
{
	int size = list->size / 2;
	Node* begin = list->root;
	Node* end = list->tail;

	for (int i = 0; i < size; ++i)
	{
		if (begin->value != end->value)
		{
			return false;
		}

		begin = begin->next;
		end = end->previous;
	}

	return true;
}
