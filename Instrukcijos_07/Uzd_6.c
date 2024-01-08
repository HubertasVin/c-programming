#include <stdio.h>
#include <stdbool.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main()
{
    char menuTitle[100] = "Meniu pavadinimas";
    char *menuOptions[100] = 
    {
        "Pirmas",
        "Antras",
        "Trecias"
    };
    char inputMsg[100] = "Iveskite savo pasirinkimo numeri";
    int menuSize = 3;

    printf("%d\n", showMenu(menuTitle, (char **)menuOptions, menuSize, inputMsg));

    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{
    int input;
    bool isIncorrectInput = true;
    do
    {
        printf("%s\n", menuTitle);
        for (int i = 0; i < menuSize; ++i)
        {
            printf("%d. %s", i + 1, menuOptions[i]);
            if (i != menuSize - 1)
            {
                printf(" | ");
            }
        }
        printf("\n");
        printf("%s\n", inputMsg);

        isIncorrectInput = ((scanf("%d", &input) != 1) || (getchar() != '\n')) ? true : false;
        if (isIncorrectInput == true)
        {
            while (getchar() != '\n')
                ;
        }
        
    } while (isIncorrectInput || input > menuSize || input < 1);

    return input;
}