#include <stdio.h>

int main()
{
    const char *stations[10] = {
        "Morumbi",
        "Butanta",
        "Pinheiros",
        "Faria Lima",
        "Fradique Coutinho",
        "Oscar Freire",
        "Paulista",
        "Higienopolis-Mackenzie",
        "Republica",
        "Luz"};

    int inStation;

    scanf("%d", &inStation);

    if (inStation <= 5)
    {
        for (int i = inStation; i <= 5; i++)
        {
            printf("* %s\n", stations[i]);
            if (i < 5)
                printf("|\n");
        }
    }
    else
    {
        for (int i = inStation; i < 10; i++)
        {
            printf("* %s\n", stations[i]);
            if (i < 9)
                printf("|\n");
        }
    }
    return 0;
}
