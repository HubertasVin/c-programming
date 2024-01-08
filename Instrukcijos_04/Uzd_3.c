#include <stdio.h>

int fib(int n, int a, int b);

int main()
{
    int a, b, c;

    printf("Programa apskaiciuoja Fibonacio sekos c-aji (trecias ivestas skaicius) nari\n");

    printf("Iveskite tris skaicius (a, b ir c): ");
    scanf("%d%d%d", &a, &b, &c); // Ivedami trys skaiciai

    if (a >= 0 && b >= 0 && c >= 0) // Tikrinama ar ivestyje yra neigiamu skaiciu
    {
        printf("\nSpausdinami rezultatai\n");
        printf("fc = %d\n", fib(c, a, b)); // Rasomas atsakymas
    }
    else
    {
        printf("\nSkaiciai negali buti neigiami\n"); 
    }

    return 0;
}

int fib(int n, int a, int b)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fib(n - 1, a, b) + fib(n - 2, a, b);
}