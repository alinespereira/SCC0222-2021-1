#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20
#define DAY_SECONDS 86400
#define HOUR_SECONDS 3600
#define MINUTE_SECONDS 60

typedef struct
{
    char name[MAX_LENGTH];
    int days;
    int hours;
    int minutes;
    int seconds;
} Planet;

void convertDHMS(long int, Planet, long int *, long int *, long int *, long int *);
long int secondsInDay(Planet);

int main()
{
    long int time;
    char planetName[MAX_LENGTH];
    long int days, hours, minutes, seconds;

    Planet earth = {.name = "Terra",
                    .days = 0,
                    .hours = 24,
                    .minutes = 0,
                    .seconds = 0};

    Planet venus = {.name = "Venus",
                    .days = 243,
                    .hours = 0,
                    .minutes = 0,
                    .seconds = 0};

    Planet mercury = {.name = "Mercurio",
                      .days = 58,
                      .hours = 16,
                      .minutes = 0,
                      .seconds = 0};

    Planet jupiter = {.name = "Jupiter",
                      .days = 0,
                      .hours = 9,
                      .minutes = 56,
                      .seconds = 0};

    scanf("%ld %s", &time, planetName);

    printf("%ld segundos no planeta %s equivalem a:\n", time, planetName);
    if (strcmp(planetName, "Mercurio") == 0)
        convertDHMS(time, mercury, &days, &hours, &minutes, &seconds);
    if (strcmp(planetName, "Venus") == 0)
        convertDHMS(time, venus, &days, &hours, &minutes, &seconds);
    if (strcmp(planetName, "Terra") == 0)
        convertDHMS(time, earth, &days, &hours, &minutes, &seconds);
    if (strcmp(planetName, "Jupiter") == 0)
        convertDHMS(time, jupiter, &days, &hours, &minutes, &seconds);

    printf("%ld dias, %ld horas, %ld minutos e %ld segundos\n", days, hours, minutes, seconds);

    return 0;
}

void convertDHMS(long int time, Planet planet,
                 long int *days, long int *hours,
                 long int *minutes, long int *seconds)
{
    long int planetDay = secondsInDay(planet);
    *days = time / planetDay;
    time %= planetDay;
    *hours = time / HOUR_SECONDS;
    time %= HOUR_SECONDS;
    *minutes = time / MINUTE_SECONDS;
    time %= MINUTE_SECONDS;
    *seconds = time;
}

long int secondsInDay(Planet planet)
{
    long int totalSeconds = 0;
    totalSeconds += planet.days * DAY_SECONDS;
    totalSeconds += planet.hours * HOUR_SECONDS;
    totalSeconds += planet.minutes * MINUTE_SECONDS;
    totalSeconds += planet.seconds;

    return totalSeconds;
}
