#include <stdio.h>
#include "hashTable.h"

void readFromFile(Table* table, char const* path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		return;
	}

	while (!feof(file))
	{
		char word[100];
		fscanf(file, "%s", word);
		addElementToTable(copyStr(word), table);
	}
}