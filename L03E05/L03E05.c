#include <stdio.h>
#include <stdbool.h>

bool isWordDelimiter(char);

int main()
{
    char currentChar;
    bool inWord = false;
    int nLines = 0, nWords = 0, nChars = 0;

    while (scanf("%c", &currentChar) != EOF)
    {
        nChars++;

        if (!isWordDelimiter(currentChar) && !inWord)
            nWords++;
        inWord = !isWordDelimiter(currentChar);

        if (currentChar == '\r' || currentChar == '\n')
        {
            nLines++;
            if (currentChar == '\r')
            {
                scanf("%*[\n]c");
                nChars++;
            }
        }
    }

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d\n", nLines, nWords, nChars);

    return 0;
}

bool isWordDelimiter(char currentChar)
{
    return currentChar == ' ' || currentChar == '\t' || currentChar == '\r' || currentChar == '\n';
}
