#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A[1000] = { 0 };
    int a, b, c;

    printf("Programa sugeneruos atsitiktinas reiksmes jusu nurodytame intervale\n\n");

    printf("Iveskite tris reiksmes (a, b ir c), bus sugeneruota c atsitiktiniu reiksmiu intervale [a; b]\n");
    scanf("%d%d%d", &a, &b, &c);

    printf("Duomenys nuskaityti sekmingai\n");
    
    // Tikrinama ar ivestis tinkama
    if (c <= 0 || c > 1000)
    {
        printf("c turi buti intervale [1; 1000]\n");
    }

    // Generuojami atsitiktiniai duomenys
    srand(time(NULL));
    for (int i = 0; i < c; ++i)
    {
        A[i] = rand() % (b + abs(a) + 1) + a;
    }

    // Rezultatu spausdinimas i ekrana
    printf("Spausdinami rezultatai\n");
    for (int i = 0; i < c; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}