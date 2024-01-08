#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Programa pirmuju dvieju ivestuju skaiciu (a ir b) intervale atranda skaicius, kurie dalijant is treciojo ivesto skaicio (c) liekana lygi 1");

    printf("Iveskite 3 skaicius (a, b ir c): ");
    scanf("%d%d%d", &a, &b, &c); // Ivedami trys skaiciai

    printf("Spausdinami rezultatai");
    if (c != 0) // Tikrinama ar c nera lygu nuliui, nes dalyba is nulio negalima
    {
        for (int i = a + 1; i <= b; i++)
        {
            if (i >= 0 && i % c == 1) // Atliekamas tikrinimas pagal uzduoti
            {
                printf("%d\n", i);
            }
        }
    }
    else
    {
        printf("c negali buti lygus nuliui\n");
    }


    return 0;
}