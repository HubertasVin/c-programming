#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void *memset(void *str, int c, size_t n);
void test_memset(void *str, int c, size_t n, void *res);

int main()
{
    int A[] = {1, 2, 3, 4};
    int A2[] = {0, 0, 3, 4};
    int A3[] = {0, 0, 0, 0};
    char input[8] = "Sveikas";
    char *output = "   ikas";

    test_memset(A, 0, 2 * sizeof(int), A2);
    test_memset(A, 0, 4 * sizeof(int), A3);
    test_memset(input, ' ', 3 * sizeof(char), output);

    printf("All the tests were successful\n");

    return 0;
}

void *memset(void *str, int c, size_t n)
{
    unsigned char *ptr = str;
    for (int i = 0; i < n / sizeof(str[0]); ++i)
    {
        *(ptr + i) = (unsigned char)c;
    }
    return str;
}

void test_memset(void *str, int c, size_t n, void *res)
{
    memset(str, c, n);
    for (int i = 0; i < n / sizeof(str); ++i)
    {
        assert(((int *)str)[i] == ((int *)res)[i]);
    }
}