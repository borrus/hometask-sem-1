#pragma once
#include <stdbool.h>

struct SortedList;

//init list
struct SortedList* initializeList();

//push element to list
void addToList(struct SortedList* sortedListPointer, int const value);

//print list
void printList(struct SortedList const* sortedList);

//pop front side
void popFront(struct SortedList* sortedList);

//pop back
void popBack(struct SortedList* sortedList);

//push back
void pushBack(struct SortedList* sortedListPointer, int const value);

//deletes element
void deleteElement(struct SortedList* sortedList, int const value);

//task 
void task();

char* toString(struct SortedList const* list);