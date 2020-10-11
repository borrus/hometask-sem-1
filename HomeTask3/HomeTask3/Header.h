#pragma once
#include "tests.h"

bool testForSorts(int* array, int const length);

void testsForSorts();

void testForFindingMostCommonElementInArray(int* array, int const length, int testNumber);

void testsForFindingMostCommonElementInArray();

void allTests();

void printArray(int* array, int const length);

void insertionSort(int* array, int const length);

void qsortRecursive(int* array, int const length);

bool binarySearch(int const* array, int length, int const elementToFind);

void existElementsInArray();

int theMostCommonArrayElement(int* array, int const length);