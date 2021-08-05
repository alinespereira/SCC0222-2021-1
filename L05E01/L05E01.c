#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NOT_FOUND -1

char *read_line(int *, bool *);
int last_char_position(char *, char);
int line_size(char *);
char *last_name(char *);

int main()
{
    char **names = NULL;
    int names_size = 0;
    int size = 0;
    bool last_line;

    names = (char **)malloc(sizeof(char *));

    do
    {
        names_size++;
        names = (char **)realloc(names, names_size * sizeof(char *));
        names[names_size - 1] = read_line(&size, &last_line);
    } while (!last_line);

    for (int i = 0; i < names_size; i++)
    {
        printf("%s", names[i]);
        if (i % 2 != 0)
        {
            char *last = last_name(names[i - 1]);
            printf(" %s", last);
            free(last);
        }
        printf("\n");
    }

    for (int i = 0; i < names_size; i++)
        free(names[i]);
    free(names);

    return 0;
}

char *read_line(int *size, bool *last_line)
{
    char *line = NULL;
    *size = 0;
    char buffer;

    do
    {
        scanf("%c", &buffer);
        (*size)++;
        line = (char *)realloc(line, (*size) * sizeof(char));
        line[(*size) - 1] = buffer;
    } while (buffer != '\n' && buffer != '$');

    line[(*size) - 1] = '\0';
    (*size)--;
    *last_line = buffer == '$';

    return line;
}

int last_char_position(char *line, char ch)
{
    int pos = NOT_FOUND;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == ch)
            pos = i;

    return pos;
}

int line_size(char *line)
{
    int size;
    for (size = 0; line[size] != '\0'; size++)
        ;
    return size;
}

char *last_name(char *line)
{
    int start = last_char_position(line, ' ') + 1;
    int end = line_size(line);

    char *name = (char *)malloc((end - start + 1) * sizeof(char));
    for (int i = 0; i < end - start; i++)
        name[i] = line[start + i];
    name[end - start] = '\0';

    return name;
}
