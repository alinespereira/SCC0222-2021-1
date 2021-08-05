#include <stdio.h>
#include <stdbool.h>

#include "board.h"

int main()
{
    char board[BOARDSIZE][BOARDSIZE];

    for (int i = 0; i < BOARDSIZE; i++)
    {
        for (int j = 0; j < BOARDSIZE; j++)
        {
            scanf("%c", &board[i][j]);
            if (j < BOARDSIZE - 1)
                scanf("%*[ ]s");
        }
        scanf("%*[\r\n]s");
    }

    char winner = checkWinner(board);

    switch (winner)
    {
    case TIE:
        printf("empate\n");
        break;

    case EMPTY:
        printf("em jogo\n");
        break;

    default:
        printf("%c ganhou\n", winner);
        break;
    }

    return 0;
}
