#include <stdio.h>
#include <string.h>

int charCount(char A[], char query);

int main()
{
    char input[100];
    int atIndex, dotIndex;
    FILE *f;

    printf("Programa patikrins jusu ivesta elektroninio pasto adresa ir irasys ji i emails.txt faila\n");

    printf("Iveskite elektroninio pasto adresa\n");
    scanf("%s", &input);

    atIndex = (int)(strchr(input, '@') - input);
    dotIndex = (int)(strchr(strchr(input, '@'), '.') - input);

    f = fopen("emails.txt", "a+");
    if (f != NULL)
    {
        if(charCount(input, '@') == 1 && charCount(strchr(input, '@'), '.') > 0)
        {
            if (atIndex > 0 && dotIndex - atIndex > 1 && strlen(input) - dotIndex > 1)
            {
                printf("Elektroninis pasto adresas irasomas i emails.txt\n");
                fprintf(f, "%s\n", input);
            }
            else
            {
                printf("Netinkama ivestis, @ negali buti pirmas elektroninio pasto adreso simbolis, arba tarp @ ir . turi buti bent vienas simbolis, arba . negali buti elektroninio pasto paskutinis simbolis\n");
            }
        }
        else
        {
            printf("Netinkama ivestis, elektroninio pasto adrese gali buti tik vienas @ zenklas ir po jo bent vienas taskas\n");
        }
    }
    
    return 0;
}

int charCount(char A[], char query)
{
    int count = 0;
    for (int i = 0; i < strlen(A); ++i)
    {
        if (A[i] == query)
        {
            ++count;
        }
    }
    return count;
}