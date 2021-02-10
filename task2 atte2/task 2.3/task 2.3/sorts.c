#include <stdio.h>

void bubbleSort(int* array, int size)
{
    int temp = 0;

    for (int i = 1; i < size; ++i) 
    {
        for (int j = 1; j < size; ++j) 
        {
            if (array[j] > array[j - 1]) 
            {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

void sortCalculation(int* array, int n, int* sortedArray)
{
    int k;

    for (int i = 0; i < n; ++i)
    {
        k = 0;
        for (int j = 0; j < n; ++j)
        {
            if (array[i] > array[j])
            ++k;
        }

        sortedArray[k] = array[i];
    }
}