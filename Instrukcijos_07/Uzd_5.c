#include <stdio.h>

long getFileSize(char *fileName);

int main()
{
    char input[100];

    scanf("%s", &input);
    printf("%ld\n", getFileSize(input));

    return 0;
}

long getFileSize(char *fileName)
{
    FILE *f;

    f = fopen(fileName, "rb");

    if (f != NULL)
    {
        fseek(f, 0, SEEK_END);
        return ftell(f);
    }
    else
    {
        return -1;
    }
}