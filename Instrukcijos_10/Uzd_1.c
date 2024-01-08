#include <stdio.h>
#include <assert.h>

size_t strlen(char *string);

int main()
{
    assert(strlen("123") == 3);
    assert(strlen("123\n\n\t") == 6);
    assert(strlen("&$*£^*@") == 8);
    assert(strlen("") == 0);

    printf("All the tests were successful\n");

    return 0;
}

size_t strlen(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        ++length;
    }

    return length;
}