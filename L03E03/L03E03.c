#include <stdio.h>
#include <stdbool.h>

#define BOARDSIZE 3
#define X 'x'
#define O 'o'
#define EMPTY '-'
#define TIE 'e'

bool gameEnded(char board[][BOARDSIZE]);
char checkWinner(char board[][BOARDSIZE]);
char checkDiagonal(char board[][BOARDSIZE], int diag);
char checkRow(char board[][BOARDSIZE], int row);
char checkCol(char board[][BOARDSIZE], int col);

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

bool gameEnded(char board[][BOARDSIZE])
{
    for (int i = 0; i < BOARDSIZE; i++)
        for (int j = 0; j < BOARDSIZE; j++)
        {
            if (board[i][j] == EMPTY)
                return false;
        }

    return true;
}

char checkWinner(char board[][BOARDSIZE])
{
    char winner = checkDiagonal(board, 0);

    if (winner == TIE || winner == EMPTY)
    {
        winner = checkDiagonal(board, 1);
        for (int i = 0; i < BOARDSIZE && (winner == TIE || winner == EMPTY); i++)
        {
            winner = checkRow(board, i);
        }
        for (int j = 0; j < BOARDSIZE && (winner == TIE || winner == EMPTY); j++)
        {
            winner = checkCol(board, j);
        }
    }

    if ((winner == TIE || winner == EMPTY) && gameEnded(board))
        winner = TIE;
    if ((winner == TIE || winner == EMPTY) && !gameEnded(board))
        winner = EMPTY;
    return winner;
}

char checkDiagonal(char board[][BOARDSIZE], int diag)
{
    char winner = board[0][0];

    switch (diag)
    {
    case 0:
        for (int i = 1; i < BOARDSIZE; i++)
        {
            if (board[i][i] != winner)
                winner = TIE;
        }
        break;

    case 1:
        winner = board[0][BOARDSIZE - 1];
        for (int i = 1; i < BOARDSIZE; i++)
        {
            if (board[i][BOARDSIZE - (i + 1)] != winner)
                winner = TIE;
        }
        break;
    }
    return winner;
}

char checkRow(char board[][BOARDSIZE], int row)
{
    char winner = board[row][0];
    for (int j = 1; j < BOARDSIZE; j++)
        if (board[row][j] != winner)
        {
            winner = TIE;
            break;
        }
    return winner;
}

char checkCol(char board[][BOARDSIZE], int col)
{
    char winner = board[0][col];
    for (int i = 1; i < BOARDSIZE; i++)
        if (board[i][col] != winner)
        {
            winner = TIE;
            break;
        }
    return winner;
}
