#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROW_LENGTH 76
#define MAX_READ_LENGTH 1000
#define MAX_SPAM_WORDS 2

bool isWordDelimiter(char);
int countListedWords(char *line, const char *wordList[], const int listLen);

int main()
{
    const char *spamWords[] = {
        "gratuito",
        "atencao",
        "urgente",
        "imediato",
        "zoombie",
        "oferta",
        "dinheiro",
        "renda",
        "fundo",
        "limitado",
        "ajuda",
        "SOS"};
    const int spamWordsLength = 12;

    char currentLine[MAX_READ_LENGTH];
    int countSpamWords = 0;
    bool spam = false;

    while (scanf("%[^\n\r]s", currentLine) != EOF)
    {
        countSpamWords += countListedWords(currentLine, spamWords, spamWordsLength);
        if (strlen(currentLine) > MAX_ROW_LENGTH || countSpamWords >= MAX_SPAM_WORDS)
        {
            spam = true;
            break;
        }

        scanf("%*[\n\r]s");
    }

    if (spam)
        printf("Spam\n");
    else
        printf("Inbox\n");

    return 0;
}

bool isWordDelimiter(char currentChar)
{
    return currentChar == ' ' || currentChar == '\t' || currentChar == '\r' || currentChar == '\n';
}

int countListedWords(char *str, const char *wordList[], const int listLen)
{
    int listedWords = 0;

    for (int i = 0; i < listLen; i++)
    {
        if (strstr(str, wordList[i]) != NULL)
            listedWords++;
    }
    return listedWords;
}
