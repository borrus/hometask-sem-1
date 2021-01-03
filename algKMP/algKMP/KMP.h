#pragma once
#include <stdbool.h>

//KMP algoritm. check if substrig exist in the string 
bool algoritm(char* string, char* substring, int* position);

//KMP for tests
bool algoritmTests(char* string, char* substring);