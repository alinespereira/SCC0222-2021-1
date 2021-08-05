#include <stdio.h>
#include <math.h>

double min(double, double, double, double);
double averageDiscard(double, double, double, double);

int main()
{
    double a, b, c, d;
    double mean;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    mean = averageDiscard(a, b, c, d);
    printf("%.4f\n", mean);
    return 0;
}

double min(double a, double b, double c, double d)
{
    double numbers[] = {a, b, c, d};
    double smallest, nextSmallest;

    smallest = numbers[0];
    for (int i = 1; i < 4; i++)
    {
        nextSmallest = numbers[i];
        smallest = nextSmallest < smallest ? nextSmallest : smallest;
    }

    return smallest;
}

double averageDiscard(double a, double b, double c, double d)
{
    double numbers[] = {a, b, c, d};
    double discard, sum;

    sum = 0.0f;

    for (int i = 0; i < 4; i++)
    {
        sum += numbers[i];
    }

    discard = min(a, b, c, d);

    return (sum - discard) / 3;
}
