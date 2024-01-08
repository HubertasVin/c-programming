#include <stdio.h>

int main()
{
    int n;
    int sum, min, max;
    int temp;

    printf("Iveskite skaiciu n: ");
    scanf("%d", &n); // Ivedamas skaicius n

    int sk = 0;

    // Ivedamas pirmasis skaicius 
    scanf("%d", &temp);
    sum = temp;
    min = temp;
    max = temp;

    for (int i = 1; i < n; ++i) // Toliau ivedinejami sekantys skaiciai
    {
        scanf("%d", &temp);
        sum += temp;
        if (min > temp) // Tikrinama ar skaicius mazesnis uz minimuma
            min = temp;
        if (max < temp) // Tikrinama ar skaicius didesnis uz maksimuma
            max = temp;
    }

    printf("\nSuma: %d\n", sum);
    printf("Vidurkis: %.2lf\n", (double)(sum / n));
    printf("Minimumas: %d\n", min);
    printf("Maksimumas: %d\n", max);

    return 0;
}