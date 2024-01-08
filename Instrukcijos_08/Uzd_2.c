#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringShortener2000(int argc, char *argv[]);
char *longestFileName(int argc, char *argv[]);

void main(int argc, char *argv[] )
{
    stringShortener2000(argc, argv);
    printf("%s\n", longestFileName(argc - 1, argv));
}

char *longestFileName(int argc, char *argv[])
{
    char longestIndex = 0;
    int longestSize = 0;
    FILE *f;
    for (int i = 0; i < argc; ++i)
    {
        f = fopen(argv[i], "r");
        if (f == NULL)
            continue;
        fseek(f, 0L, SEEK_END);
        if (longestSize < ftell(f))
        {
            longestIndex = i;
            longestSize = ftell(f);
        }
        fclose(f);
    }
    
    return argv[longestIndex];
}

void stringShortener2000(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        argv[i - 1] = argv[i];
    }
}
