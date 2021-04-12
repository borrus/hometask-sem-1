#pragma once
#include <stdbool.h>

//string length
int strlen(char const* s);

//adds symbol to string
void strPlusSymbol(char** strPointer, char const symbol);

//adds string to string
void strPlusStr(char** toPointer, char const* from);

//creates an empty sring
char* emptyStr();

//returns numbers length
int numberLength(int number);

// convers int to string
char* intToStr(int number);

//
int numberLength16(int number);

//10 to 16
char* int10To16(int number);

//checks if symbol consists in array
bool inArray(char const* array, int const size, char symbol);

//priiiiiintfff:)
char* myPrintf(char const* format, void* args, int const size);