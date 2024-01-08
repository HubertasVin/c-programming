#include <stdio.h>

int main()
{
    int i;
    int nr = 0;
    int suma = 0;
    printf("Iveskite skaiciu: ");
    scanf("%d", &nr);
    
    for (i = 1; i < nr+1; i++)
    {
        suma += i*i;
    }
    printf("%d", suma);
}