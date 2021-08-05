#include <stdio.h>
#include <time.h>

int days_in_month(int, int);

int main()
{
    time_t today;
    struct tm todayinfo;

    time_t rawtime;
    struct tm timeinfo;
    // int year, month, day;
    char *months[] = {"Jan",
                      "Fev",
                      "Mar",
                      "Abr",
                      "Mai",
                      "Jun",
                      "Jul",
                      "Ago",
                      "Set",
                      "Out",
                      "Nov",
                      "Dez"};

    time(&rawtime);
    timeinfo = *localtime(&rawtime);
    timeinfo.tm_mday = 1;
    mktime(&timeinfo);

    time(&today);
    todayinfo = *localtime(&today);
    mktime(&todayinfo);

    printf("          %s %4d          \n", months[timeinfo.tm_mon], timeinfo.tm_year + 1900);
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");

    for (int i = 0; i < timeinfo.tm_wday; i++)
    {
        printf("    ");
    }

    for (int i = 1; i <= days_in_month(timeinfo.tm_mon + 1, timeinfo.tm_year + 1900); i++)
    {
        timeinfo.tm_mday = i;
        mktime(&timeinfo);
        if (i != todayinfo.tm_mday)
            printf(" %2d ", timeinfo.tm_mday);
        else
            printf(" \033[0;30m\033[47m%2d\033[0m ", timeinfo.tm_mday);
        if (timeinfo.tm_wday == 6)
            printf("\n");
    }
    printf("\n");

    return 0;
}

int days_in_month(int month, int year)
{
    if (year < 1582)
        return 0; /* Before this year the Gregorian Calendar was not define */
    if (month > 12 || month < 1)
        return 0;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        return (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28);
    return 31;
}
