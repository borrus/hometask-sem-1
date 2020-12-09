#include "file.h"
#include <stdio.h>
#include "hashTable.h"
#include "node.h"

typedef struct aa
{
	char* value;
}aa;

void test1(aa* a)
{
	char word[100];
	word[0] = 'a';
	word[1] = 'b';
	word[2] = 'c';
	word[3] = '\0';

	a->value = copyStr(word);
}

int main()
{
	Table* table = initTable();
	readFromFile(table);
	printTable(table);
	printFrequencies(table);
}