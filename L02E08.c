#include <stdio.h>
#include <math.h>

double nthTermPG(double, double, double);
double sumPG(double, double, double);

int main()
{
    double a1, q, n;
    double an, sum;

    scanf("%lf %lf %lf", &a1, &q, &n);
    an = nthTermPG(a1, q, n);
    sum = sumPG(a1, q, n);

    printf("%.2lf\n", an);
    printf("%.2lf\n", sum);
    return 0;
}

double nthTermPG(double a1, double q, double n)
{
    return a1 * pow(q, (n - 1));
}

double sumPG(double a1, double q, double n)
{
    return a1 * ((1 - pow(q, n)) / (1 - q));
}
