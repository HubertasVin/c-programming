#include <stdio.h>

void dataScan(int *N, int A[][100]);
int isMagicSquare(int N, int A[][100]);
void printSquare(int N, int A[][100]);

int main()
{
    int N;
    int A[100][100];
    int i, j;
    int magicSquare;

    dataScan(&N, A);

    if (isMagicSquare(N, A) == 1)
    {
        printf("Turime magiska kvadrata\n");
    }

    printSquare(N, A);
    
    return 0;
}

void dataScan(int *N, int A[][100])
{
    int i, j, count = 0;

    printf("Iveskite N: ");
    scanf("%d", &*N);

    printf("Iveskite %d skaicius\n", (*N) * (*N));
    for (i = 0; i < *N; ++i)
    {
        for (j = 0; j < *N; ++j)
        {
            ++count;
            printf("%d x %d ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
}

int isMagicSquare(int N, int A[][100])
{
    int i, j;
    int sum1 = 0, sum2 = 0;

    /* Stulpeliai */
    for (i = 0; i < N; ++i)
    {
        sum1 += A[i][0];
    }
    
    for (i = 1; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            sum2 += A[j][i];
        }
        if (sum1 != sum2)
            return 0;
        sum2 = 0;
    }

    /* Eilutes */
    
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            sum2 += A[i][j];
        }

        if (sum1 != sum2)
            return 0;
        sum2 = 0;
    }

    /* Istrizaines */
    /* Pagrindine */
    for (i = 0, j = 0; i < N, j < N; ++i, ++j)
    {
        sum2 += A[i][j];
    }
    
    if (sum1 != sum2)
        return 0;
    sum2 = 0;

    /* Salutine */
    for (i = 0, j = N - 1; i < N, j >= 0; ++i, --j)
    {
        sum2 += A[i][j];
    }
    
    if (sum1 != sum2)
        return 0;
    sum2 = 0;
    /* 2 7 6 9 5 1 4 3 8 */
    return 1;
}

void printSquare(int N, int A[][100])
{
    int i, j;
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}