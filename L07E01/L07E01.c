#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum operator_
{
    PLUS = '+',
    MINUS = '-',
    TIMES = '*',
    DIVIDE = '/'
} operator_t;

double evaluate_expression(bool *is_eof);
bool is_digit(char ch);

int main()
{
    bool is_eof = false;

    while (!is_eof)
    {
        double result = evaluate_expression(&is_eof);
        if (!is_eof)
            printf("%.6lf\n", result);
    }

    return EXIT_SUCCESS;
}

double evaluate_expression(bool *is_eof)
{
    char current_char;
    double number = 0;

    do
    {
        current_char = getc(stdin);

        if (current_char == EOF)
        {
            *is_eof = true;
        }
        else if (is_digit(current_char))
        {
            ungetc(current_char, stdin);
            scanf("%lf", &number);
            return number;
        }
        else if (current_char == '(')
        {
            char op = getc(stdin);
            double left_operand = evaluate_expression(is_eof);
            double right_operand = evaluate_expression(is_eof);

            switch ((operator_t)op)
            {
            case PLUS:
                return left_operand + right_operand;

            case MINUS:
                return left_operand - right_operand;

            case TIMES:
                return left_operand * right_operand;

            case DIVIDE:
                return left_operand / right_operand;

            default:
                exit(EXIT_FAILURE);
            }
        }
        printf("%d\n", (int)current_char);

    } while (current_char != EOF && current_char != '\n');

    printf("I'm out! %d\n", (int)current_char);
}

bool is_digit(char ch)
{
    return !(ch < '0' || ch > '9');
}
