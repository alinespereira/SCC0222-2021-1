#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double *push(double, double *, int *);
double *pop(double *, double *, int *);
bool is_operator(char);

int main()
{
    char currentChar;
    double currentNum;
    double *stack = NULL;
    int stack_top = 0;
    double operand1, operand2, result;

    while ((currentChar = getc(stdin)) != EOF)
    {
        // printf("size: %d\n\tchar: %c\n", stack_top, currentChar);
        if (currentChar >= '0' && currentChar <= '9')
        {
            ungetc(currentChar, stdin);
            scanf("%lf", &currentNum);
            stack = push(currentNum, stack, &stack_top);
        }
        else if (is_operator(currentChar))
        {
            stack = pop(&operand2, stack, &stack_top);
            stack = pop(&operand1, stack, &stack_top);
            switch (currentChar)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                break;
            }
            stack = push(result, stack, &stack_top);
        }
        else
        {
            scanf("%*[ ]s");
            continue;
        }
    }

    stack = pop(&result, stack, &stack_top);

    printf("Resultado: %.6lf\n", result);

    free(stack);

    return 0;
}

double *push(double num, double *stack, int *size)
{
    (*size)++;
    stack = realloc(stack, *size * sizeof(double));
    stack[(*size) - 1] = num;

    return stack;
}

double *pop(double *num, double *stack, int *size)
{
    *num = stack[(*size) - 1];
    (*size)--;
    stack = realloc(stack, *size * sizeof(double));

    return stack;
}

bool is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
