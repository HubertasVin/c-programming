#include <stdio.h>

int calculateWeekDay(int y, int m, int d);

int main()
{
    int y, m, d;
    FILE *f;
    char weekDay[7][100];

    printf("Programa atspausdins savaites diena pagal jusu ivesta data\n");

    f = fopen("week.txt", "r");
    if (f != NULL)
    {
        for (int i = 0; i < 7; ++i)
        {
            fscanf(f, "%s", weekDay[i]);
        }
        fclose(f);
    }
    else
    {
        printf("Nepavyko atidaryti failo\n");
    }

    printf("Iveskite data formatu YYYY-MM-DD\n");
    if (scanf("%d-%d-%d", &y, &m, &d) == 3 && m <= 12 && m > 0 && d <= 31 && d > 0)
    {
        printf("Spausdinamas rezultatas:\n");
        printf("%s\n", weekDay[calculateWeekDay(y, m, d)]);
    }
    else
    {
        printf("Netinkama ivestis, menuo gali buti tik rezyje [1;12] bei diena gali buti tik rezyje [1;31]\n");
    }

    return 0;
}

int calculateWeekDay(int y, int m, int d)
{
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + d + 5) % 7;
}