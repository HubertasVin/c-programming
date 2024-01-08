#include <stdio.h>

int f(int x);
int g(int x);
void a(int, char, char[]);

int main()
{
    // printf("%d\n", f(3));
    a(7.0, 7, "7.0");

    return 0;
}

int f(int x)
{
    if (x % 5 == 0)
        f(x - 2);
    else
        g(x - 1);
}

int g(int x)
{
    if (x > 0)
        f(x);
    x += 5;
    return x;
}

void a(int a, char b, char c[])
{

}