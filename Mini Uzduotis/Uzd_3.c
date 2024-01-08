#include <stdio.h>
#include <stdlib.h>

void generateSquareArray(int n, int A[]);

int main()
{
    int n;
    int *A;
    int i;
    printf("Iveskite skaiciu n: ");
    scanf("%d", &n);

    A = (int *)malloc(n * sizeof(int));
    generateSquareArray(n, A);

    for (i = 0; i < n; ++i)
    {
        printf("%d\n", A[i]);
    }

    return 0;
}

void generateSquareArray(int n, int A[])
{
    int i;
    for (i = 1; i <= n; ++i)
    {
        (A)[i - 1] = i * i;
    }
}