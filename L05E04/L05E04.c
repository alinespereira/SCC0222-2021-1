#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABOO_SIZE 21

char *readLineUntil(const char);
char *removeFromString(char *, char *);

int main()
{
    char tabooWord[TABOO_SIZE];
    int countTaboo = 0;
    char *text;
    const char endChar = '$';
    scanf("%s\n", tabooWord);
    text = readLineUntil(endChar);

    char *currentFind;
    do
    {
        currentFind = strstr(text, tabooWord);
        if (currentFind != NULL)
        {
            countTaboo++;
            text = removeFromString(text, tabooWord);
        }
    } while (currentFind != NULL);

    printf("A palavra tabu foi encontrada %d vezes\n", countTaboo);
    printf("Frase: %s", text);

    free(text);

    return 0;
}

char *readLineUntil(const char endChar)
{
    char *line = NULL;
    int size = 0;
    char current;

    do
    {
        scanf("%c", &current);
        size++;
        line = (char *)realloc(line, size * sizeof(char));
        line[size - 1] = current;
    } while (current != endChar);
    line[size - 1] = '\0';

    return line;
}

char *removeFromString(char *text, char *textToRemove)
{
    int textLength = strlen(text);
    int removeLength = strlen(textToRemove);

    char *posPtr;
    posPtr = strstr(text, textToRemove);
    if (posPtr != NULL)
    {
        int moveSize = textLength - removeLength - (posPtr - text);
        memmove(posPtr, posPtr + removeLength, moveSize);
        text = (char *)realloc(text, textLength - removeLength);
        text[textLength - removeLength] = '\0';
    }

    return text;
}
