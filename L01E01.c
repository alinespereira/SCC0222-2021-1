#include <stdio.h>

int main()
{
    int input;
    char output[5];
    output[4] = '\0';
    scanf("%d", &input);
    for (int i = 0; i < 4; i++)
    {
        output[i] = (input >> (32 - (i + 1) * 8)) & 255;
    }

    printf("%s\n", output);
    return 0;
}