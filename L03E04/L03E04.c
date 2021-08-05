#include <stdio.h>

#define IMAGESIZE 25
#define COLORS 5

int main()
{
    int colors[IMAGESIZE], histogram[COLORS];
    int mostFrequentColor = 0;

    for (int i = 0; i < IMAGESIZE; i++)
    {
        scanf("%d", &colors[i]);
    }

    for (int i = 0; i < COLORS; i++)
    {
        histogram[i] = 0;
        for (int j = 0; j < IMAGESIZE; j++)
            histogram[i] += colors[j] == i;
    }

    for (int i = 0; i < IMAGESIZE; i++)
    {
        histogram[colors[i]]++;
    }

    for (int i = 0; i < COLORS; i++)
    {
        if (histogram[i] > histogram[mostFrequentColor])
            mostFrequentColor = i;

        printf("%d: |", i);
        for (int j = 0; j < histogram[i]; j++)
            printf("#");
        printf("\n");
    }

    for (int i = 0; i < IMAGESIZE; i++)
        if (colors[i] == mostFrequentColor)
            printf("%d\n", i);

    return 0;
}
