#include <stdio.h>

int main()
{
    int players, rounds, pinguPlay;
    const int cycleSize = 3;

    scanf("%d %d %d", &rounds, &players, &pinguPlay);

    int remainingRounds = rounds;
    int currentRound;
    int currentCycle = 1;
    while (remainingRounds > 0)
    {
        for (int i = 1; i <= cycleSize && remainingRounds > 0; i++)
        {
            for (int j = 0; j < currentCycle && remainingRounds > 0; j++)
            {
                currentRound = rounds - remainingRounds;
                if (currentRound % players == pinguPlay - 1)
                    switch (i)
                    {
                    case 1:
                        if (currentCycle > 1)
                            printf("%d pinguins\n", currentCycle);
                        else
                            printf("%d pinguim\n", currentCycle);
                        break;
                    case 2:
                        printf("no gelo\n");
                        break;
                    case 3:
                        printf("uhuu!\n");
                        break;
                    default:
                        break;
                    }
                remainingRounds--;
            }
        }
        currentCycle++;
    }

    return 0;
}
