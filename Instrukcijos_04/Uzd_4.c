#include <stdio.h>

#define MIN(a, b) (a < b ? a : b)

int main()
{
    int a, b, c;
    int dbd, mbk;
    int maziausias;

    printf("Iveskite tris skaicius (a, b ir c): ");
    scanf("%d%d%d", &a, &b, &c); // Ivedami trys skaiciai

    maziausias = MIN(MIN(a, b), c); // Surandamas maziausias skaicius tarp ivestuju trieju skaiciu

    // Ieskoma didziausio bendro daliklio
    for (int i = 1; i <= a && i <= b && i <= c; ++i) // Ciklas sukasi tol, kol i nera didesnis uz a ar b ar c
    {
        if (a % i == 0 && b % i == 0 && c % i == 0) // Tikrinama ar i yra a, b ir c bendras daliklis
            dbd = i;
    }

    // Ieskoma maziausio bendro kartotinio
    for (int i = maziausias; i <= a * b * c; i += maziausias) // Ciklas sukasi kol i nedaugiau uz a, b ir c sandauga
    {
        if (i % a == 0 && i % b == 0 && i % c == 0) // Tikrinama ar i yra bendras kartotinis
        {
            mbk = i;
            break;
        }
    }

    printf("\nSpausdinami rezultatai\n"); // Spausdinami rezultatai
    printf("Didziausias bendras daliklis: %d\n", dbd);
    printf("Maziausias bendras kartotinis: %d\n", mbk);

    return 0;
}