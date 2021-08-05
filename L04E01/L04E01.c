#include <stdio.h>

#define DATA_SIZE 10

int min(int *, int);
int max(int *, int);
float mean(int *, int);
int mode(int *, int);

int main()
{
    int data[DATA_SIZE];

    for (int i = 0; i < DATA_SIZE; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("%d ", max(data, DATA_SIZE));
    printf("%d ", min(data, DATA_SIZE));
    printf("%.2f ", mean(data, DATA_SIZE));
    printf("%d", mode(data, DATA_SIZE));

    return 0;
}

int min(int *values, int size)
{
    int result = values[0];
    for (int i = 1; i < size; i++)
        if (values[i] < result)
            result = values[i];
    return result;
}

int max(int *values, int size)
{
    int result = values[0];
    for (int i = 1; i < size; i++)
        if (values[i] > result)
            result = values[i];
    return result;
}

float mean(int *values, int size)
{
    float sum = 0.0f;
    for (int i = 0; i < size; i++)
        sum += values[i];
    return sum / size;
}

int mode(int *values, int size)
{
    int counts[size];
    int result, maxCount;

    for (int i = 0; i < size; i++)
    {
        counts[i] = 0;
        for (int j = 0; j < size; j++)
            if (values[j] == values[i])
                counts[i]++;
    }
    maxCount = max(counts, size);

    for (int i = 0; i < size; i++)
        if (counts[i] == maxCount)
            result = values[i];

    return result;
}
