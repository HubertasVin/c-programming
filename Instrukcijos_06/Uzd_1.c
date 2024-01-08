#include <stdio.h>

void factorial(int x, int *ans);

int main()
{
    int input;
    int ans = 1;
    FILE *f = fopen("out.txt", "w+");
    if (f == NULL)
    {
        printf("Nepavyko atidaryti failo\n");
        return 1;
    }
    printf("Programa atspausdins ivesto skaiciaus faktoriala terminale ir faile out.txt\n");

    printf("Iveskite teigiama skaiciu\n");
    if ((scanf("%d", &input) != 1))
    {
        printf("Netinkama ivestis\n");
        return 1;
    }
    else if (input <= 0)
    {
        printf("Ivestyje negali buti neteigiamas skaicius\n");
    }

    factorial(input, &ans);

    printf("%d faktorialas yra %d\n", input, ans);
    fprintf(f, "%d\n", ans);

    fclose(f);
    return 0;
}

void factorial(int x, int *ans)
{
    if (x > 0)
    {
        *ans *= x--;
        factorial(x, ans);
    }
}