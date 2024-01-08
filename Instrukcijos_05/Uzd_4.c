#include <stdio.h>

int main()
{
    int A[1000];
    int size = 0;
    int input;
    int cnt = 0;

    printf("Programa suras pirminius skaicius jusu ivestoje sekoje\n");

    printf("Iveskite skaiciu seka, kurios pabaiga yra neteigiamas skaicius\n");
    do
    {
        scanf("%d", &input);
        if (input <= 0)
        {
            continue;
        }
        A[size] = input;
        ++size;
    } while (input > 0);
    printf("Seka ivesta sekmingai\n");

    // Salinimas vienodu masyvo nariu
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (A[i] == A[j])
            {
                for (int k = j; k < size; ++k)
                {
                    A[k] = A[k + 1];
                }
                --size;
                --i;
                --j;
            }
        }
    }

    printf("Spausdinami rezultatai\n");

    // Ieskoma pirminiu skaiciu
    printf("Pirminiai skaiciai:\n");
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j <= A[i]; ++j)
        {
            if (A[i] % j == 0)
            {
                ++cnt;
            }
        }
        if (cnt == 1 || cnt == 2)
        {
            printf("%d ", A[i]);
        }
        cnt = 0;
    }
    printf("\n");
    
    return 0;
}