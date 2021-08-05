#include <stdio.h>

int main()
{
    int year;
    scanf("%d", &year);
    if (year % 4 == 0)
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }
    return 0;
}
