#include <stdio.h>
#include <assert.h>

int strncmp(char *str1, char *str2, size_t num);
void test_strncmp(char *str1, char *str2, size_t num, int value);

int main()
{
    test_strncmp("", "", 0, 0);
    test_strncmp("\t", "\t", 1, 0);
    test_strncmp("123", "22", 2, -1);
    test_strncmp("Sveikas", "Sveika", 6, 0);

    printf("All the tests were successful\n");

    return 0;
}

int strncmp(char *str1, char *str2, size_t num)
{
    for (int i = 0; str1[i] != 0 && i < str2[i] != 0 && i < num; ++i)
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

void test_strncmp(char *str1, char *str2, size_t num, int value)
{
    assert(strncmp(str1, str2, num) == value);
}