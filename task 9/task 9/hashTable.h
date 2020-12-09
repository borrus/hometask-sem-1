#pragma once

typedef struct Table
{
	struct List** array;
	int size;
	int maxSize;
} Table;


struct Table* initTable();

void addElementToTable(char* element, struct Table* table);

void printTable(Table* table);

void testik(Table* table);

void printFrequencies(Table* table);