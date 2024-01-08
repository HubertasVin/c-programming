#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "file.h"

void fillArray(int size, int Arr[]);
void printArray(int size, int Arr[]);

int main()
{
    int n = 10;
    int m1[10];
    int m2[10];
    char *fileName = "saved.bin";

    fillArray(n, m1);
    saveToFile(n, m1, fileName);
    printf("m1 ");
    printArray(n, m1);
    loadFromFile(n, m2, fileName) == -1 ? printf("File contents do not fit in the provided array\n") : printf("The loading from file operation was successful\n");
    printf("\nm2 ");
    printArray(n, m2);

    bool equalArrays = true;
    for (int i = 0; i < n; ++i)
    {
        if (m1[i] != m2[i])
        {
            equalArrays = false;
        }
    }
    if (equalArrays == true)
        printf("All good\n");
    else
        printf("Something's wrong\n");

    return 0;
}

void fillArray(int size, int Arr[])
{
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
    {
        Arr[i] = rand() % 100 + 1;
    }
}

void printArray(int size, int Arr[])
{
    printf("array contents are:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}