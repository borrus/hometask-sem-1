#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* array, int size)
{
    for (int i = 1; i < size; ++i) 
    {
        for (int j = 1; j < size - i + 1; ++j) 
        {
            if (array[j] > array[j - 1]) 
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

void countingSort(int* array, int size)
{
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < size; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }

        if (array[i] < min)
        {
            min = array[i];
        }
    }

    int len = max - min + 1;

    int* c = (int*)calloc(len, sizeof(int));

    for (int i = 0; i < size; ++i)
    {
        ++c[array[i] - min];
    }

    int b = 0;

    for (int i = 0; i < len; ++i)
    {
        if (c[i] != 0)
        {
            array[b] = min + i;
            ++b;
        }
    }
}