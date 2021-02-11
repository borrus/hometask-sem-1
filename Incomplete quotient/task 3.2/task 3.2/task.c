#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void qsortRec(int* array, int const size)
{
    int i = 0;
    int j = size - 1;
    int middleElement = array[size / 2];

    do {

        while (array[i] < middleElement)
        {
            ++i;
        }

        while (array[j] > middleElement)
        {
            --j;
        }

        if (i <= j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            ++i;
            --j;
        }
    } while (i <= j);

    if (j > 0)
    {
        qsortRec(array, j + 1);
    }

    if (i < size)
    {
        qsortRec(&array[i], size - i);
    }
}

int task(int const n, int const k)
{
	int* array = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; ++i)
	{
		array[i] = rand() % 100;
	}

    qsortRec(array, n);

	for (int i = 0; i < k; ++i)
	{
        int currentNumber = rand() % 100;

        for (int j = 0; j < n; ++j)
        {
            if (array[j] == currentNumber)
            {
                printf("Number ");
                printf("%d ", currentNumber);
                printf("exists\n");
                break;
            }
        }
	}

    free(array);
}
