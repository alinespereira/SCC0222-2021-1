#include <stdio.h>

int main()
{
    char track[32][64];
    int xPos, yPos, dx, dy;
    char currentPos;

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            scanf("%c", &track[i][j]);
            if (track[i][j] == '[')
            {
                xPos = i;
                yPos = j + 2;
            }
        }
        scanf("%*[\r\n]s");
    }

    // printf("Start position: (%d, %d)\n", xPos, yPos);
    // for (int i = 0; i < 32; i++)
    // {
    //     for (int j = 0; j < 64; j++)
    //     {
    //         printf("%c", track[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    do
    {
        currentPos = track[xPos][yPos];

        if (track[xPos][yPos] != '#' && track[xPos][yPos] != ']' && currentPos != ' ')
            track[xPos][yPos] = '.';

        switch (currentPos)
        {
        case '>':
            dx = 0;
            dy = 2;
            break;

        case '<':
            dx = 0;
            dy = -2;
            break;

        case 'v':
            dx = 1;
            dy = 0;
            break;

        case '^':
            dx = -1;
            dy = 0;
            break;

        default:
            break;
        }

        xPos += dx;
        yPos += dy;
    } while (currentPos != '.' && currentPos != ']' && currentPos != ' ');

    switch (currentPos)
    {
    case '.':
        printf("Loop infinito.\n");
        break;

    case ']':
        printf("Ok.\n");
        break;

    case ' ':
        printf("Falha na esteira.\n");
        break;
    }

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            printf("%c", track[i][j]);
        }
        printf("\n");
    }

    return 0;
}
