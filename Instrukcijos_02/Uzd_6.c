#include <stdio.h>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

int main()
{
    int sk[3];

    printf("Iveskite 3 skaicius: ");
    scanf("%d", &sk[0]);
    scanf("%d", &sk[1]);
    scanf("%d", &sk[2]);

    int rez = MAX(sk[0], sk[1]);
    rez = MAX(rez, sk[2]);

    printf("Maksimalus skaicius yra: %d\n", rez);

    rez = MIN(sk[0], sk[1]);
    rez = MIN(rez, sk[2]);

    printf("Minimalus skaicius yra: %d\n", rez);
    
    return 0;
}