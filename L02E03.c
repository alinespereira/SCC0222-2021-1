#include <stdio.h>

#define TARGETLOSS 30
#define BALLLOSS 5
#define FOODGAIN 3

int weightLoss(int, int);

int main()
{
    int ball, food;
    int loss;

    scanf("%d %d", &ball, &food);
    loss = weightLoss(ball, food);

    if (loss > TARGETLOSS)
    {
        printf("P\n");
    }
    else if (loss < 0)
    {
        printf("R\n");
    }
    else
    {
        printf("B\n");
    }

    return 0;
}

int weightLoss(int ball, int food)
{
    return ball * BALLLOSS - food * FOODGAIN;
}
