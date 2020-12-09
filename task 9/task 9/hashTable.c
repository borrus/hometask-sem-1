#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

int hash(char* value, int hashSize)
{
	int result = 0;

	for (int i = 0; value[i] != '\0'; ++i)
		result = (result + value[i]) % hashSize;

	return result;
}

Table* initTable()
{
	Table* table = (Table*)malloc(sizeof(Table));
	table->maxSize = 100;
	table->size = 0;
	table->array = (struct List**)malloc(sizeof(struct List*) * table->maxSize);
	
	for (int i = 0; i < table->maxSize; ++i)
	{
		table->array[i] = initializeList();
	}

	return table;
}

void resize(Table* table)
{
	struct List** array = (struct List**)malloc(sizeof(struct List*) * 2 * table->maxSize);

	for (int i = table->maxSize; i < table->maxSize * 2; ++i)
	{
		table->array[i] = NULL;
	}

	for (int i = 0; i < table->maxSize * 2; ++i)
	{
		array[i] = table->array[i];
	}

	table->maxSize *= 2;
	table->array = array;
}

void addElementToTable(char* element, Table* table)
{
	if (table->size == table->maxSize)
	{
		resize(table);
	}

	++table->size;

	int currentHash = hash(element, table->maxSize);
	push(table->array[currentHash], element);
}

void printTable(Table* table)
{
	for (int i = 0; i < table->maxSize; ++i)
	{
		if (table->array[i]->root != NULL)
		{
			printf("hash = %d\n", i);
			printList(table->array[i]);
		}
	}
}

void readFromFile(Table* table)
{
	FILE* file = fopen("table.txt", "r");

	while (!feof(file))
	{
		char word[100];
		fscanf(file, "%s", word);
		addElementToTable(copyStr(word), table);
	}
}

void printFrequencies(Table* table)
{
	for (int i = 0; i < table->maxSize; ++i)
	{
		if (table->array[i]->root != NULL)
		{
			printf("word = %s; frequency = %d\n", table->array[i]->root->value, table->array[i]->size);
		}
	}
}