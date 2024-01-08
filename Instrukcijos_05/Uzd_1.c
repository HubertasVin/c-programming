#include <stdio.h>

int main()
{
    int A[10] = { 0 };
    int size = 10;
    int x, y;

    printf("Programa atlieka salinimo ir iterpimo operacijas\n\n");
    // Masyvo spausdinimas i ekrana
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    A[0] = 1;
    A[3] = 2;
    A[9] = 3;
    // Elemento salinimas
    for (int i = 2; i < size; ++i)
    {
        A[i] = A[i + 1];
    }
    --size;

    // Elemento iterpimas
    for (int i = size + 1; i > 5; --i)
    {
        A[i] = A[i - 1];
    }
    A[6] = 4;
    ++size;

    // Masyvo spausdinimas i ekrana
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Iveskite du skaicius (x ir y), bus pakeista masyvo narys indeksu x reiksme y\n");
    scanf("%d%d", &x, &y);

    // Tikrinama ar ivestis tinkama
    if (x < 0 || x >= 100)
    {
        printf("x turi buti intervale [0; 99]\n");
        return 0;
    }

    A[x] = y;

    printf("Iveskite skaiciu x, bus istrintas masyvo narys indeksu x\n");
    scanf("%d", &x);
    // Elemento salinimas
    for (int i = x; i < size; ++i)
    {
        A[i] = A[i + 1];
    }
    --size;

    printf("Iveskite du skaicius (x ir y), bus iterptas naujas masyvo narys y indeksu x\n");
    scanf("%d%d", &x, &y);
    // Elemento iterpimas
    for (int i = size + 1; i > x; --i)
    {
        A[i] = A[i - 1];
    }
    A[x] = y;
    ++size;

    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}