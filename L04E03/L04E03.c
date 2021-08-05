#include <stdio.h>

void calculateChange(const int *, int, int *, const int);

int main()
{
    const int coinValues[] = {100, 50, 25, 10, 5, 1};
    const int nCoins = sizeof(coinValues) / sizeof(coinValues[0]);
    int coinAmount[6];
    int changeValue;

    scanf("%d\n", &changeValue);
    calculateChange(coinValues, changeValue, coinAmount, nCoins);

    for (int i = 0; i < nCoins; i++)
    {
        printf("O valor consiste em %d moedas de ", coinAmount[i]);
        switch (coinValues[i])
        {
        case 100:
            printf("1 real");
            break;

        case 1:
            printf("1 centavo");
            break;

        default:
            printf("%d centavos", coinValues[i]);
            break;
        }
        printf("\n");
    }

    return 0;
}

void calculateChange(const int *coinValues, int changeAmount, int *coinAmount, const int nCoins)
{
    for (int i = 0; i < nCoins; i++)
    {
        coinAmount[i] = changeAmount / coinValues[i];
        changeAmount %= coinValues[i];
    }
}
