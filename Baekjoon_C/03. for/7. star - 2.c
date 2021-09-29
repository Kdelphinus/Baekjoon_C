#include <stdio.h>

int main()
{
    int num, i, j, k;

    scanf("%d", &num);

    for (i = 1; i <= num; i++)
    {
        for (j = num; j > i; j--)
        {
            printf(" ");
        }

        for (k = 1; k <= i; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}