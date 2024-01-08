#include <stdio.h>
#include "file.h"

void saveToFile(int n, int Arr[], char *fileName)
{
    FILE *fr = fopen(fileName, "wb");

    fprintf(fr, "%d\n", n);
    for (int i = 0; i < n; ++i)
    {
        fprintf(fr, "%d ", Arr[i]);
    }
    fprintf(fr, "\n");
    fclose(fr);
}

int loadFromFile(int arraySize, int Arr[], char *fileName)
{
    int n;
    FILE *fw = fopen(fileName, "rb");

    fscanf(fw, "%d", &n);
    if (arraySize >= n)
    {
        for (int i = 0; i < n; ++i)
        {
            fscanf(fw, "%d", &Arr[i]);
        }
        return 0;
    }
    else
        return -1;
}