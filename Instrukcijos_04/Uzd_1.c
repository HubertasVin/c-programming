#include <stdio.h>
#include <math.h>

#define x1(a, b, c) ((-b - sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a))
#define x2(a, b, c) ((-b + sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a))

int main()
{
    int a, b, c;
    int D;
    double x1, x2;

    printf("Programa apskaiciuoja kvadratine lygti");

    printf("Iveskite a, b ir c skaicius: ");
    scanf("%d%d%d", &a, &b, &c); // Ivedami trys skaiciai
    
    printf("Spausdinami rezultatai\n");
    if (pow(b, 2) - 4 * a * c < 0) // Tikrinama ar diskriminantas yra maziau nei nulis, nes tada lygtis neturi sprendiniu
    {
        printf("Nera sprendiniu\n");
    }
    else if (pow(b, 2) - 4 * a * c == 0) // Jei diskriminantas lygus nuliui, tai reiskias, jog yra vienas atsakymas x
    {
        printf("Vienas sprendinys, x = %.2lf\n", x1(a, b, c));
    }
    else // Visais kitais atvejais yra du lygties sprendiniai
    {
        printf("Du sprendiniai, x1 = %.2lf, x2 = %.2lf\n", x1(a, b, c), x2(a, b, c));
    }

    return 0;
}