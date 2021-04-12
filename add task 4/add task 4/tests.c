#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

void test()
{
	void* p = (void*)malloc(sizeof(char) + sizeof(int) + 4 * sizeof(char) + sizeof(int*));

	char* symbol = (char*)p;
	*symbol = 'a';
	int* number = (int*)(symbol + 1);
	*number = -7895;
	char* s = (char*)(number + 1);
	s[0] = 'a';
	s[1] = 'b';
	s[2] = 'c';
	s[3] = '\0';
	int x = 0;
	int** intP = (int**)(s + 4);
	*intP = &x;

	printf("%s", myPrintf("test char: %c; test integer: %i; test string: %s; test pointer: %*i", p, 4));
}