#include "user.h"

int main()
{
	struct List* list = listInitialize();

	listPushBack(list, "ab", "100");
	listPushBack(list, "abcde", "400");
	listPushBack(list, "a", "200");
	listPushBack(list, "abcd", "300");
	
	

	mergeSort(list, "number");

	listPrint(list);

	listFree(list);

	return 0;
}