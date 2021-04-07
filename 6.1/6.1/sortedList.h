#pragma once
#include <stdbool.h>

//init list
void initializeList(struct SortedList* sortedListPointer);

//push element to list
void addToList(struct SortedList* sortedListPointer, int const value);

//print list
void printList(struct SortedList const sortedList);

//pop front side
void popFront(struct SortedList* sortedList);

//pop back
void popBack(struct SortedList* sortedList);

//deletes element
void deleteElement(struct SortedList* sortedList, int const value);

//task 
void task();

bool testPopBack();