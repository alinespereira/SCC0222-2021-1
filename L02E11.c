#include <stdio.h>
#include <time.h>

int main()
{
    time_t rawtime;
    struct tm *timeinfo;
    int year = 2021, month = 4;
    int day;

    scanf("%d", &day);

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = 1;

    mktime(timeinfo);

    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");

    for (int i = 0; i < timeinfo->tm_wday; i++)
    {
        printf("    ");
    }

    for (int i = 1; i <= 30; i++)
    {
        timeinfo->tm_mday = i;
        mktime(timeinfo);
        if (i != day)
            printf(" %2d ", timeinfo->tm_mday);
        else
            printf("(%2d)", timeinfo->tm_mday);
        if (timeinfo->tm_wday == 6)
            printf("\n");
    }
    printf("\n");

    return 0;
}
