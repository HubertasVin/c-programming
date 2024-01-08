#include <stdio.h>

int isInRange(int number, int low, int high);

int main()
{
    int number, low, high;

    scanf("%d%d%d", &number, &low, &high);

    printf(isInRange(number, low, high) == 1 ? "true\n" : "false\n");

    return 0;
}

int isInRange(int number, int low, int high)
{
    if (low <= high && number >= low && number <= high)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}