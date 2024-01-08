#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main()
{
    int numRows = 5;
    int returnSize;
    int **returnColumnSizes = generate(numRows, &returnSize, returnColumnSizes);

    printf("%d\n", returnColumnSizes[0][0]);

    return 0;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    returnColumnSizes = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; ++i) {
        returnColumnSizes[i] = (int*)malloc(numRows * sizeof(int));
    }
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
            {
                returnColumnSizes[i][j] = 1;
            }
            else
            {
                returnColumnSizes[i][j] = returnColumnSizes[i - 1][j] + returnColumnSizes[i - 1][j - 1];
            }
        }
    }
    return returnColumnSizes;
}