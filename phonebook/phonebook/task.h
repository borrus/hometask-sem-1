#pragma once

// push data to fie
void pushDataToFile(char* const path, char* const name, char* const number);

// print data from file
void printDataFromFile(char* const path);

// find number by name
char* findNumberByName(char const* name, char* const path);

// find name by number
char* findNameByNumber(char const* number, char* const path);

// save data to current file 
void saveDataToFile(char* const path, char* const pathToSave);

// output information
void output();