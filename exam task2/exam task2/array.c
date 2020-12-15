#include <stdio.h>

void points()
{
    int rows = 0;
    int cols = 0;
    int i = 0;
    int j = 0;

    scanf("%d", &rows);
    scanf("%d", &cols);

    int m[2][10] = { 0 };

    for (i = 0; i < rows; ++i)
    {
        for (j = 0; j < cols; ++j)
        {
            scanf("%d", &m[i][j]);
        }
    }

    int minIndex[10] = { 0 };
    for (i = 0; i < rows; ++i)
    {
        int minCol = m[i][0];

        for (j = 1; j < cols; ++j)
        {
            if (m[i][j] < minCol) minCol = m[i][j];
            {
                minIndex[i] = minCol;
            }
        }
    }

    int maxIndex[10] = { 0 };
    for (j = 0; j < cols; ++j) 
    {
        int maxRow = m[0][j];
        for (i = 1; i < rows; i++)
        {
            if (m[j][i] > maxRow) 
            {
                maxRow = m[i][j];
            }

            maxIndex[j] = maxRow;
        }
    }

    int k = 0;
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++)
        {
            if ((m[i][j] == maxIndex[j]) && (m[i][j] == minIndex[i]))
            {
                printf("%d %d", i, j);
                ++k;
            }
        }
    }

    if (k == 0)
    {
        printf("0");
        return 0;
    }
}