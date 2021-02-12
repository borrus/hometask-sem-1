#include <stdio.h>

void insertSort(int* array, int const size)
{
    int counter = 0;

    for (int i = 1; i < size; ++i)
    {
        for (int j = i; j > 0 && array[j - 1] > array[j]; --j)
        {
            ++counter;
            int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
        }
    }
}

void qsortRec(int* array, int const size) 
{
    if (size < 10 )
    {
        insertSort(array, size);
        return;
    }

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


