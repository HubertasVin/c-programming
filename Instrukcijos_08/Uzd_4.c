#include <stdio.h>
#include <stdlib.h>

void splitData(int rawData[], int size, int splitPos, int **pos1, int **pos2);
void answerPrint(int rawData[], int size, int splitPos, int *pos1, int *pos2);

int main()
{
    int data[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int size = 11;
    int splitPos = 5;
    int *pos1, *pos2;

    splitData(data, size, splitPos, &pos1, &pos2);
    answerPrint(data, size, splitPos, pos1, pos2);

    return 0;
}

void splitData(int rawData[], int size, int splitPos, int **pos1, int **pos2)
{
    if (splitPos > size)
    {
        printf("Pirmosios dalies ilgis negali buti ilgesnis uz masyvo dydi\n");
    }
    
    *pos1 = (int *)malloc(splitPos * sizeof(int));
    if (*pos1 == NULL)
    {
        printf("Nepavyko paskirti atminties\n");
        exit(0);
    }
    else
    {
        for (int i = 0; i < splitPos; ++i)
        {
            (*pos1)[i] = rawData[i];
        }
    }
    
    *pos2 = (int *)malloc((size - splitPos) * sizeof(int));
    if (*pos1 == NULL)
    {
        printf("Nepavyko paskirti atminties\n");
        exit(0);
    }
    else
    {
        for (int i = splitPos; i < size; ++i)
        {
            (*pos2)[i - splitPos] = rawData[i];
        }
    }
}

void answerPrint(int rawData[], int size, int splitPos, int *pos1, int *pos2)
{
    printf("Pirmoji puse: ");
    for (int i = 0; i < splitPos; ++i)
    {
        printf("%d ", *(pos1 + i));
    }
    printf("\n");
    printf("Antroji puse: ");
    for (int i = 0; i < size - splitPos; ++i)
    {
        printf("%d ", *(pos2 + i));
    }
    printf("\n");
}