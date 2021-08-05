#include <stdio.h>

long int nthTermPA(long int, long int, long int);
long int sumPA(long int, long int, long int);

int main()
{
    long int a1, r, n;
    long int an, sum;

    scanf("%ld %ld %ld", &a1, &r, &n);
    an = nthTermPA(a1, r, n);
    sum = sumPA(a1, r, n);

    printf("%ld\n", an);
    printf("%ld\n", sum);
    return 0;
}

long int nthTermPA(long int a1, long int r, long int n)
{
    return a1 + (n - 1) * r;
}

long int sumPA(long int a1, long int r, long int n)
{
    long int an = nthTermPA(a1, r, n);
    return (a1 + an) * n / 2;
}
