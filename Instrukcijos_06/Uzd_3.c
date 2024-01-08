#include <stdio.h>
#include <string.h>

void sort(int A[]);

int main()
{
    int A[3];
    char input[100];
    FILE *f;
    
    printf("Programa irasys i faila vidurini skaiciu tarp jusu ivestu 3 skaiciu\n");

    printf("Iveskite tris skaicius atskirtus kabliataskiais\n");
    if (scanf("%d;%d;%d", &A[0], &A[1], &A[2]) == 3)
    {
        sort(A);
        printf("Iveskite failo pavadinima\n");
        scanf("%s", &input);
        while (strcmp(strrchr(input, '.'), ".txt"))
        {
            printf("Jusu ivesto failo formatas nera .txt, iveskite failo pavadinima is naujo\n");
            scanf("%s", &input);
        }
        f = fopen(input, "w+");
        if (f != NULL)
        {
            printf("Spausdinami rezultatai\n");
            fprintf(f, "%d\n", A[1]);
            fclose(f);
        }
        else
        {
            printf("Nepavyko atidaryti failo\n");
        }
    }
    else
    {
        printf("Netinkama ivestis, skaiciai turi buti atskirti kabletaskiais\n");
    }

    return 0;
}

void sort(int A[])
{
    int temp;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (A[i] < A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}