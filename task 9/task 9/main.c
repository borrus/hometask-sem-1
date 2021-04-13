#include <stdlib.h>
#include <stdio.h>
#include "hashTable.h"
#include "file.h"

int main()
{
	if (!test())
	{
		return 0;
	}

	printf("test completed\n");
	Table* table = initTable();
	readFromFile(table, "test1.txt");
	printTable(table);
	printFrequencies(table);

	free(table);

}