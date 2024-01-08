#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int N[1000];
    int n;
    int *A;
} struct1;

void square(struct1 S);

int main()
{
    struct1 S;
    S.n = 5;
    S.A = (int *)malloc((sizeof(int) * S.n));

    if (S.A == NULL)
    {
        printf("Failed to allocate memory\n");
        return 0;
    }

    int i;
    for (i = 0; i < S.n; ++i)
    {
        S.N[i] = i;
        S.A[i] = i;
    }

    for (i = 0; i < S.n; ++i)
    {
        printf("before  Statinis11: %d\n", S.N[i]);
        printf("before Dinaminis: %d\n", S.A[i]);
    }
    square(S);

    for (i = 0; i < S.n; ++i)
    {
        printf("Statinis11: %d\n", S.N[i]);
        printf("Dinaminis: %d\n", S.A[i]);
    }

    return 0;
}

void square(struct1 S)
{
    int i;
    for (i = 0; i < S.n; ++i)
    {
        S.N[i] *= S.N[i];
        S.A[i] *= S.A[i];
    }
}