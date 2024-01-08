#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(char *argv[]);
int getFileSize(FILE *f);
void findNumberInMiddle(char *input);
void removeWord(char input[], int startPos, int wordLength);
int getWordLength(char input[], int startPos);

int main(int argc, char *argv[])
{
    readFile(argv);

    return 0;
}

void readFile(char *argv[])
{
    int fileSize;
    char *input = malloc(255 * sizeof(char));
    size_t lineSize;

    FILE *fr = fopen(argv[1], "r");
    FILE *fw = fopen(argv[2], "w");

    if (fw == NULL)
    {
        printf("Nepavyko sukurti isvesties failo\n");
        return;
    }

    if (fr != NULL)
    {
        while (feof(fr) != 1)
        {
            getline(&input, &lineSize, fr);
            findNumberInMiddle(input);
            fprintf(fw, "%s", input);
        }
        free(input);
        fclose(fr);
    }
    else
        printf("Nepavyko atidaryti failo\n");

}

void findNumberInMiddle(char *input)
{
    char word[100];
    int i, j;
    int lineLength = strlen(input);
    int wordLength;

    for (i = 0; i < strlen(input); ++i)
    {
        wordLength = getWordLength(input, i);
        if (wordLength % 2 == 1)
        {
            if (isdigit(input[i + wordLength / 2]))
            {
                removeWord(input, i, wordLength);
            }
            else
                i += wordLength;
        }
        else
        {
            if (isdigit(input[i + wordLength / 2 - 1]) && isdigit(input[i + wordLength / 2]))
            {
                removeWord(input, i, wordLength);
            }
            else
                i += wordLength;
        }
    }
}

void removeWord(char input[], int startPos, int wordLength)
{
    int i;

    for (i = startPos; i < strlen(input); ++i)
    {
        input[i] = input[i + wordLength];
    }
}

int getWordLength(char input[], int startPos)
{
    int length = 0;
    while (input[startPos + length] != ' ' && input[startPos + length] != '\n' && startPos + length < strlen(input))
        ++length;

    return length;
}