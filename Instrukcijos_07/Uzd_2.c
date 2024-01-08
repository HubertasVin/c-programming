#include <stdio.h>

int getFactorial(int number);

int main()
{
    int number;

    scanf("%d", &number);
    printf("%d\n", getFactorial(number));

    return 0;
}

int getFactorial(int number)
{
    if (number < 0)
        return 0;
    if (number == 0)
        return 1;
    if (number > 0)
        return (number * getFactorial(number - 1));
}