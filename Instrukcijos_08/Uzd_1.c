#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int size);

int main()
{
    int *ptr;
    int size = 10;

    ptr = createArray(size);

    for (int i = 0; i < size; ++i)
    {
        printf("%d\n", *(ptr + i));
    }

    return 0;
}

int *createArray(int size)
{
    int *ptr;
    int low = -20, high = 20;
    ptr = (int *)malloc(size * sizeof(int));

    if (ptr == NULL)
    {
        printf("Nepavyko paskirti atminties\n");
        exit(0);
    }
    else
    {
        if (low < high)
        {
            srand(time(NULL));

            for (int i = 0; i < size; ++i)
            {
                *(ptr + i) = rand() % (high - low + 1) + low;
            }
        }
    }

    return ptr;
}