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
    int k = INT_MIN;

    for (int i = 0; i < size; ++i)
    {
        if (array[i] > k)
        {
            k = array[i];
        }
    }

    int* c = (int*)calloc(k + 1, sizeof(int));

    for (int i = 0; i < size; ++i)
    {
        ++c[array[i]];
    }

    int b = 0;

    for (int i = 0; i < k + 1; ++i)
    {
        for (int j = 0; j < c[i]; ++j) 
        {
            array[b] = i;
            ++b;
        }
    }
}