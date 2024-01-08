#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"

void fillArray(int size, int Arr[]);
void printArray(int size, int Arr[]);

int main()
{
    int n = 10;
    int m1[10];
    int m2[10];
    int m3[10];

    fillArray(n, m1);
    fillArray(n, m2);
    fillArray(n, m3);

    saveToFile(n, m1, "saved1.bin");
    saveToFile(n, m3, "saved1.bin");

    loadFromFile(n, m1, "saved1.bin");

    saveToFile(n, m2, "saved2.bin");

    loadFromFile(n, m3, "saved2.bin");
    loadFromFile(n, m2, "saved1.bin");

    if(saveCount == 3 && loadCount == 3)
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