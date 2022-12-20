#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        float distance;
        int x1, y1, r1, x2, y2, r2, r_plus, r_minus;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        distance = (float)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        r_plus = (r2 + r1);
        r_minus = abs(r2 - r1);

        // 같은 원일 때, 내접/외접하는 조건과 같기에 순서가 중요
        if (x1 == x2 && y1 == y2 && r1 == r2)
            printf("%d\n", -1);
        else if (r_plus > distance && r_minus < distance)
            printf("%d\n", 2);
        else if (r_plus == distance || r_minus == distance)
            printf("%d\n", 1);
        else
            printf("%d\n", 0);
    }

    return 0;
}