#pragma once

typedef struct Table Table;

// initialize table
struct Table* initTable();

// add element to table
void addElementToTable(char* element, struct Table* table);

// prints all information about table
void printTable(Table* table);

// print frequencies
void printFrequencies(Table* table);

// print fill factor of table
int fillFactor(Table* table);