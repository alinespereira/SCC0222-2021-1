#include <stdio.h>

int main()
{
    int base, exponent, power;

    scanf("%d %d", &base, &exponent);
    power = 1;

    while (exponent-- > 0)
    {
        power *= base;
    }
    printf("%d\n", power);
    return 0;
}
