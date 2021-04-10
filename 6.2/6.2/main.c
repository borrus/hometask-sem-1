#include <stdio.h>
#include "cycleList.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf("tests failed\n");

		return 0;
	}
	
	struct CycleList* list = initializeList();
	addElement(list, 1);
	addElement(list, 2);
	addElement(list, 3);
	addElement(list, 4);
	addElement(list, 5);
	printf("result:\n");
	printf("%d\n", joseph(list, 1));
}