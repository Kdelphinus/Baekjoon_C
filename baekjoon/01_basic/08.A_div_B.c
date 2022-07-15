#include <stdio.h>

int     main(void)
{
        long double a, b;

        scanf("%Lf %Lf", &a, &b);
        printf("%.11Lf\n", a / b);
        return (0);
}
