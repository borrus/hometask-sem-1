#include <stdio.h>
#include "task.h"
#include "list.h"
#include "tests.h"

void choose()
{
	printf("choose what do you want to do:\n");
	int temp = -1;
	printf("1 - tests\n");
	printf("2 - task from file\n");
	printf("0 - exit\n");
	scanf("%d", &temp);

	while (temp != 0)
	{
		if (temp == 1)
		{
			tests();
		}

		if (temp == 2)
		{
			List* list = initializeList();
			readFromFile(list, "input.txt");
			printf("%d\n", isSymmetric(list));
		}

		scanf("%d", &temp);
	}

	if (temp == 0)
	{
		printf("Bye! Thank you for using prog :)\n");
	}
}

int main()
{
	choose();
}