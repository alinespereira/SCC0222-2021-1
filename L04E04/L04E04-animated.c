#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROWS 32
#define COLS 64

#define SAND '#'
#define WATER '~'
#define CEMENT '@'
#define AIR ' '

void calculatePhysics(char[ROWS][COLS], int, int);
void displayFrame(char[ROWS][COLS], int, int);
void copyArray(char[ROWS][COLS], char[ROWS][COLS], int, int);
void swap(char[ROWS][COLS], int, int, int, int);

int main()
{
    char simState[ROWS][COLS];
    int frames;

    scanf("%d", &frames);

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            simState[i][j] = AIR;

    int frame, x, y;
    char particle;
    bool reachEOF = false;
    bool shouldInsertParticle = true;
    for (int i = 0; i < frames; i++)
    {
        // if (!reachEOF)
        scanf("%d: %d %d %c", &frame, &x, &y, &particle);

        system("clear");
        printf("frame: %d\n", i + 1);
        while (frame == i && !reachEOF)
        {
            simState[y][x] = particle;
            reachEOF = scanf("%d: %d %d %c", &frame, &x, &y, &particle) == EOF;
            shouldInsertParticle = frame != i;
        }

        displayFrame(simState, ROWS, COLS);
        calculatePhysics(simState, ROWS, COLS);

        if (shouldInsertParticle)
        {
            simState[y][x] = particle;
        }
    }

    return 0;
}

void calculatePhysics(char simState[ROWS][COLS], int rows, int cols)
{
    char newState[ROWS][COLS];
    copyArray(newState, simState, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            switch (simState[i][j])
            {
            case SAND:
                if (i + 1 < rows)
                {
                    if (simState[i + 1][j] == WATER || simState[i + 1][j] == AIR)
                        swap(newState, i, j, i + 1, j);
                    else if (j - 1 >= 0 && (simState[i + 1][j - 1] == WATER || simState[i + 1][j - 1] == AIR))
                        swap(newState, i, j, i + 1, j - 1);
                    else if (j + 1 < cols && (simState[i + 1][j + 1] == WATER || simState[i + 1][j + 1] == AIR))
                        swap(newState, i, j, i + 1, j + 1);
                }
                break;

            case WATER:
                if (i + 1 < rows)
                {
                    if (simState[i + 1][j] == AIR)
                        swap(newState, i, j, i + 1, j);
                    else if (j - 1 >= 0 && simState[i + 1][j - 1] == AIR)
                        swap(newState, i, j, i + 1, j - 1);
                    else if (j + 1 < cols && simState[i + 1][j + 1] == AIR)
                        swap(newState, i, j, i + 1, j + 1);
                    else if (j - 1 >= 0 && simState[i][j - 1] == AIR)
                        swap(newState, i, j, i, j - 1);
                    else if (j + 1 < cols && simState[i][j + 1] == AIR)
                        swap(newState, i, j, i, j + 1);
                }
                else if (i < rows)
                {
                    if (j - 1 >= 0 && simState[i][j - 1] == AIR)
                        swap(newState, i, j, i, j - 1);
                    else if (j + 1 < cols && simState[i][j + 1] == AIR)
                        swap(newState, i, j, i, j + 1);
                }
                break;
            }
        }
    }
    copyArray(simState, newState, rows, cols);
}

void displayFrame(char simState[ROWS][COLS], int rows, int cols)
{
    for (int i = -1; i < cols + 1; i++)
        printf("\033[2;33m%c\033[0;0m", CEMENT);
    printf("\n");

    for (int i = 0; i < rows; i++)
    {
        printf("\033[2;33m%c\033[0;0m", CEMENT);
        for (int j = 0; j < cols; j++)
        {
            switch (simState[i][j])
            {
            case CEMENT:
                printf("\033[0;33m");
                break;
            case SAND:
                printf("\033[0;37m");
                break;
            case WATER:
                printf("\033[0;34m");
                break;
            case AIR:
                break;
            }
            printf("%c\033[0;0m", simState[i][j]);
        }
        printf("\033[2;33m%c\033[0;0m\n", CEMENT);
    }
    for (int i = -1; i < cols + 1; i++)
        printf("\033[2;33m%c\033[0;0m", CEMENT);
    printf("\n");
    system("sleep 0.5");
}

void copyArray(char dest[ROWS][COLS], char origin[ROWS][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            dest[i][j] = origin[i][j];
}

void swap(char arr[ROWS][COLS], int i1, int j1, int i2, int j2)
{
    char temp = arr[i1][j1];
    arr[i1][j1] = arr[i2][j2];
    arr[i2][j2] = temp;
}
