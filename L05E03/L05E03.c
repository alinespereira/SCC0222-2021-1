#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height, padding;
    int **image, **padded_image;

    scanf("%d", &width);
    scanf("%d", &height);

    image = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
        image[i] = (int *)malloc(width * sizeof(int));

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            scanf("%d", &image[i][j]);

    scanf("%d", &padding);

    padded_image = (int **)malloc((height + 2 * padding) * sizeof(int *));
    for (int i = 0; i < height + 2 * padding; i++)
        padded_image[i] = (int *)malloc((width + 2 * padding) * sizeof(int));

    for (int i = 0; i < height + 2 * padding; i++)
        for (int j = 0; j < width + 2 * padding; j++)
            if (i < padding || i >= height + padding || j < padding || j >= width + padding)
                padded_image[i][j] = 0;
            else
                padded_image[i][j] = image[i - padding][j - padding];

    for (int i = 0; i < height + 2 * padding; i++)
    {
        for (int j = 0; j < width + 2 * padding; j++)
            printf("%d ", padded_image[i][j]);
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            printf("%d ", image[i][j]);
        printf("\n");
    }

    for (int i = 0; i < height + 2 * padding; i++)
        free(padded_image[i]);
    free(padded_image);

    for (int i = 0; i < height; i++)
        free(image[i]);
    free(image);

    return 0;
}
