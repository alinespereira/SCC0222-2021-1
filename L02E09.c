#include <stdio.h>

typedef enum Bool
{
    FALSE = 0,
    TRUE = 1
} Bool;

typedef struct Point
{
    long int x;
    long int y;
} Point;

typedef struct Rectangle
{
    Point origin;
    long int width;
    long int height;
} Rectangle;

Point translate(const Point p, const long int dx, const long int dy);
Bool hit(const Rectangle r1, const Rectangle r2);
Rectangle hitBox(const Rectangle r1, const Rectangle r2);
long int min(const long int a, const long int b);
long int max(const long int a, const long int b);

int main()
{
    Rectangle r1, r2, box;

    scanf("%ld %ld %ld %ld", &(r1.origin.x), &(r1.origin.y), &(r1.width), &(r1.height));
    scanf("%ld %ld %ld %ld", &(r2.origin.x), &(r2.origin.y), &(r2.width), &(r2.height));

    if (hit(r1, r2))
    {
        box = hitBox(r1, r2);
        printf("HIT: %ld %ld %ld %ld\n", box.origin.x, box.origin.y, box.width, box.height);
    }
    else
    {
        printf("MISS\n");
    }

    return 0;
}

Point translate(const Point p, const long int dx, const long int dy)
{
    Point translated = {p.x + dx,
                        p.y + dy};
    return translated;
}

Bool hit(const Rectangle r1, const Rectangle r2)
{
    Point leftCorner1, rightCorner1, leftCorner2, rightCorner2;
    leftCorner1 = r1.origin;
    rightCorner1 = translate(r1.origin, r1.width, r1.height);
    leftCorner2 = r2.origin;
    rightCorner2 = translate(r2.origin, r2.width, r2.height);

    if (leftCorner1.x > rightCorner2.x || leftCorner2.x > rightCorner1.x || leftCorner1.y > rightCorner2.y || leftCorner2.y > rightCorner1.y)
        return FALSE;

    return TRUE;
}

Rectangle hitBox(const Rectangle r1, const Rectangle r2)
{
    int x1, x2, y1, y2;
    x1 = max(r1.origin.x, r2.origin.x);
    x2 = min(r1.origin.x + r1.width, r2.origin.x + r2.width);
    y1 = max(r1.origin.y, r2.origin.y);
    y2 = min(r1.origin.y + r1.height, r2.origin.y + r2.height);
    Rectangle box = {{x1, y1},
                     x2 - x1,
                     y2 - y1};

    return box;
}

long int min(const long int a, const long int b)
{
    return a < b ? a : b;
}

long int max(const long int a, const long int b)
{
    return a > b ? a : b;
}
