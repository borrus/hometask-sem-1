#pragma once

void pushDataToFile(char* const path, char* const name, char* const number);

void printDataFromFile(char* const path);

char* findNumberByName(char const* name, char* const path);

char* findNameByNumber(char const* number, char* const path);

void saveDataToFile(char* const path, char* const pathToSave);

void output();