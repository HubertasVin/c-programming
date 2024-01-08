#include <stdio.h>
#include <stdlib.h>
int splitData(int n, int array[], int a, int **array_ptr1, int **array_ptr2)
{
    if (a >= n)
    {
        return -1;
    }
    *array_ptr1 = (int *)malloc(a * sizeof(int));
    if (*array_ptr1 == NULL)
    {
        printf("Memory not allocated.\n");
        return -1;
    }
    else
    {
        int i;
        for (i = 0; i < a; ++i)
        {
            (*array_ptr1)[i] = array[i];
        }
    }
    *array_ptr2 = (int *)malloc((n - a) * sizeof(int));
    if (*array_ptr2 == NULL)
    {
        printf("Memory not allocated.\n");
        return -1;
    }
    else
    {
        int i;
        for (i = a; i < n; ++i)
        {
            (*array_ptr2)[i] = array[i];
        }
    }
    return 0;
}
int main()
{
    int n = 18;
    int array[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 7, 8};
    int a = 3;
    int *array_ptr1, *array_ptr2;
    int success = splitData(n, array, a, &array_ptr1, &array_ptr2);
    printf("%d\n", success);

    return 0;
}