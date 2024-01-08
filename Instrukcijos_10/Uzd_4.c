#include <stdio.h>
#include <assert.h>

char *strchr(const char *str, int c);
void test_strchr(const char *str, int c, const char *res);

int strcmp(const char *str1, const char *str2);

int main()
{
    test_strchr("Sveikas", 'i', "ikas");
    test_strchr("", '\n', NULL);
    test_strchr("123", '2', "23");
    test_strchr("Cia yra sakinys", 'z', NULL);

    printf("All the tests were successful\n");

    return 0;
}

char *strchr(const char *str, int c)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == c)
        {
            return (char *)str + i;
        }
    }
    return NULL;
}

void test_strchr(const char *str, int c, const char *res)
{
    if (res != NULL)
    {
        assert(strcmp(strchr(str, c), res) == 0);
    }
    else
    {
        assert(strchr(str, c) == NULL);
    }
}

int strcmp(const char *str1, const char *str2)
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