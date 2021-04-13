#pragma once

typedef struct Node Node;

typedef struct Tree Tree;

// creates tree from a current file, opened with path
void createTree(Tree* tree, char* path);

// calculates current tree
int calculateTree(Tree* tree);

// deletes tree
void freeTree(Tree* tree);

// prints tree
void printTree(Tree* tree);