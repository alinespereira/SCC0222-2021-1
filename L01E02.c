#include <stdio.h>
#include <math.h>

int main()
{
    double base, exponent;
    scanf("%lf", &base);
    scanf("%lf", &exponent);

    printf("%.4lf\n", pow(base, exponent));
    return 0;
}
