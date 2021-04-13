#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashTable.h"
#include "file.h"

bool test()
{
	Table* table = initTable();
	readFromFile(table, "test1.txt");

	if (fillFactor(table) != 11)
	{
		printf("test1 failed\n");
		free(table);

		return false;
	}
	free(table);

	return true;
}
