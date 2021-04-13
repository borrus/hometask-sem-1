#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

bool stringCompare(char const* string1, char const* string2)
{
	if (strlen(string1) != strlen(string2))
	{
		return false;
	}

	for (int i = 0; i < strlen(string1); ++i)
	{
		if (string1[i] != string2[i])
		{
			return false;
		}
	}

	return true;
}

bool test1()
{
	void** p = (void**)malloc(sizeof(void*) * 6);
	int i = 576;
	int widthI = 5;
	int widthC = 3;
	int widthS = 6;
	char c = 'a';
	char* s = (char*)malloc(sizeof(char) * 5);

	if (s == NULL)
	{
		return false;
	}

	if (p == NULL)
	{
		return false;
	}

	s[0] = '1';
	s[1] = 'q';
	s[2] = 'w';
	s[3] = 'e';
	s[4] = '\0';
	p[0] = &widthI;
	p[1] = &i;
	p[2] = &widthC;
	p[3] = &c;
	p[4] = &widthS;
	p[5] = s;

	return stringCompare(myPrintf("%*i%*c%*s", p, 6),"  576  a  1qwe");
}