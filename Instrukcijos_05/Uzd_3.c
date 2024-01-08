#include <stdio.h>

int main()
{
    int s, n;
    int X[1000];

    printf("Programa suras skaiciu, kuriuos jus ivesite, sandaugas, kurios yra lygios tam tikrai reiksmei kuria jus ivesite veliau\n");

    printf("Iveskite du skaicius (s, n). s yra sandauga, kurios programa ieskos tarp poru ivestoje sekoje, kuria ivesite veliau. n yra kiek sekos skaiciu norite ivesti\n");
    scanf("%d%d", &s, &n);
    if (s < 0)
    {
        printf("s negali buti neigiamas skaicius\n");
    }
    if (n <= 0)
    {
        printf("n negali buti neigiamas skaicius ar nulis\n");
    }

    printf("Iveskite skaiciu seka\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &X[i]);
        if (X[i] < 0)
        {
            printf("Sekos nariai negali buti neigiami\n");
            --i;
        }
        
    }
    printf("Duomenys nuskaityti sekmingai\n");
    
    // Skaiciavimai ir spausdinimas
    printf("Spausdinami rezultatai\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (X[i] * X[j] == s)
            {
                printf("%d ir %d\n", X[i], X[j]);
            }
        }
    }
    

    return 0;
}