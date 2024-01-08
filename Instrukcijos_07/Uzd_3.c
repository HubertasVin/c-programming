#include <stdio.h>
#include <ctype.h>
#include <string.h>

int getPositiveNumber(char *msg);

int main()
{
    char msg[] = "Iveskite standartinio ivedimo srauto eilute";
    /* Programa ieskos skaiciaus standartinio ivedimo srauto eiluteje */
    
    printf("%d\n", getPositiveNumber(msg));

    return 0;
}

int getPositiveNumber(char *msg)
{
    char input[100];
    int number;

    printf("%s\n", msg);

    fgets(input, 100, stdin);
    for (int i = 0; i < strlen(input); i++)
    {
        if (isdigit(input[i]))
        {
            sscanf(&input[i], "%d", &number);
            return number;
        }
    }
    return getPositiveNumber(msg);
}