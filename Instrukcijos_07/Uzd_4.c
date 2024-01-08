#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generateArray(int data[], int size, int low, int high);

int main()
{
    int data[100];
    int size, low, high;

    scanf("%d%d%d", &size, &low, &high);

    generateArray(data, size, low, high);
    for (int i = 0; i < size; ++i)
    {
        printf("%d\n", data[i]);
    }

    return 0;
}

void generateArray(int data[], int size, int low, int high)
{
    if (low < high)
    {
        srand(time(NULL));

        for (int i = 0; i < size; ++i)
        {
            data[i] = rand() % (high - low + 1) + low;
        }
    }
}