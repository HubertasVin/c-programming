#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;
    printf("Iveskite x: ");
    scanf("%lf", &x);
    printf("Iveskite y: ");
    scanf("%lf", &y);
    printf("Iveskite z: ");
    scanf("%lf", &z);

    printf("a) %f\n", x + 4 * y + pow(z, 3.0));

    printf("b) %f\n", (x + sqrt(y)) * (pow(z, 4.0) - fabs(z) + 46.3));
    return 0;
}