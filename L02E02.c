#include <stdio.h>

int main()
{
    float a, b;
    char op;

    scanf("%f %c %f", &a, &op, &b);

    switch (op)
    {
    case '+':
        printf("%f\n", a + b);
        break;
    case '-':
        printf("%f\n", a - b);
        break;
    case '*':
        printf("%f\n", a * b);
        break;
    case '/':
        printf("%f\n", a / b);
        break;
    case '%':
        printf("%f\n", a * 100.0f / b);
        break;
    }
    return 0;
}
