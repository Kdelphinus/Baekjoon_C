#include <stdio.h>

int main()
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    if (x >= w / 2 && y > h / 2)
    {
        if (w - x > h - y)
            printf("%d", h - y);
        else
            printf("%d", w - x);
    }
    else if (x > w / 2 && y < h / 2)
    {
        if (w - x > y)
            printf("%d", y);
        else
            printf("%d", w - x);
    }
    else if (x < w / 2 && y > h / 2)
    {
        if (x < h - y)
            printf("%d", x);
        else
            printf("%d", h - y);
    }
    else
    {
        if (x > y)
            printf("%d", y);
        else
            printf("%d", x);
    }

    return 0;
}