#include <stdio.h>
#include <assert.h>

int strcmp(char *str1, char *str2);
void test_strcmp(char *str1, char *str2, int value);

int main()
{
    test_strcmp("", "", 0);
    test_strcmp("\n", "\n", 0);
    test_strcmp("123", "22", -1);
    test_strcmp("add", "abb", 2);

    printf("All the tests were successful\n");

    return 0;
}

int strcmp(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i)
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

void test_strcmp(char *str1, char *str2, int value)
{
    assert(strcmp(str1, str2) == value);
}