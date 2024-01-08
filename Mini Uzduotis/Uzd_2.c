#include <stdio.h>

void suma(int a, int b, int* sum);

int main()
{
    int a, b, sum;
    
    printf("Iveskite du skaicius\n");
    scanf("%d%d", &a, &b);

    suma(a, b, &sum);
    printf("Suma = %d\n", sum);

    return 0;
}

void suma(int a, int b, int* sum)
{
    *sum = a + b;
}