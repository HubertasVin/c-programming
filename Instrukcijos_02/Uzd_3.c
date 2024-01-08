#include <stdio.h>

int main()
{
    int sk;
    printf("Iveskite skaiciu: ");
    scanf("%d", &sk);
    char *rez = sk % 2 == 0 ? "lyginis" : "nelyginis";
    printf("Skaicius yra %s\n", rez);
    return 0;
}