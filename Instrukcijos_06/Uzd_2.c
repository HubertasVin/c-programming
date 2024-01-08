#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[100];
    int count = 0, fractionCount = 0; // Skaitmenu skaicius
    int number, fraction = 0;
    char fileName[100];
    FILE *f;

    printf("Programa apskaiciuos skaiciaus ilgi esanciame sraute\n");
    
    f = fopen("in.txt", "r");
    if (f != NULL)
    {
        fscanf(f, "%s", &input);
        printf("Duomenys nuskaityti sekmingai\n");
    }
    fclose(f);
    
    sscanf(input, "%d,%d", &number, &fraction);
    count = sprintf(input, "%d%d", number, fraction);
    fractionCount = sprintf(input, "%d", fraction);
    if (number < 10 || number > 1000 || fractionCount > 3)
    {
        number = 0;
        fraction = 0;

        printf("Netinkama ivestis, skaicius arba netelpa i rezi [10, 1000] arba po kablelio skaitmenu yra daugiau nei 3.\n");
        printf("Iveskite naujo failo pavadinima\n");
        scanf("%s", &fileName);

        f = fopen(fileName, "r");
        if (f != NULL)
        {
            fscanf(f, "%s", &input);
            printf("Duomenys nuskaityti sekmingai\n");
        }
        fclose(f);
        
        sscanf(input, "%d,%d", &number, &fraction);
        count = sprintf(input, "%d%d", number, fraction);
        fractionCount = sprintf(input, "%d", fraction);
        
        if (number < 10 || number > 1000 || fractionCount > 3)
        {
            printf("Netinkama ivestis, skaicius arba netelpa i rezi [10, 1000] arba po kablelio skaitmenu yra daugiau nei 3.\n");
        }
        else
        {
            printf("Spausdinami rezultatai\n");
            printf("Skaiciaus ilgis: %d\n", count);
        }
    }
    else
    {
        printf("Spausdinami rezultatai\n");
        printf("Skaiciaus ilgis: %d\n", count);
    }

    return 0;
}