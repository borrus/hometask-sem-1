#pragma once

struct CycleList;

struct CycleList* initializeList();

void addElement(struct CycleList* cycleListPointer, int const value);

void printList(struct CycleList const* cycleListPointer);

void popHead(struct CycleList* cycleListPointer);

void deleteElement(struct CycleList* cycleListPointer, int const position);

int joseph(struct CycleList* cycleListPointer, int const position);