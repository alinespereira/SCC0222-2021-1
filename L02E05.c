#include <stdio.h>

#define MOVES 6

int main()
{
    char moves[MOVES + 1];
    moves[6] = '\0';
    int x = 0, y = 0;

    scanf("%s", moves);

    for (int i = 0; i < MOVES; i++)
    {
        switch (moves[i])
        {
        case 'W':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'D':
            x++;
            break;
        case 'A':
            x--;
            break;
        }
    }
    printf("%d %d\n", x, y);

    return 0;
}
