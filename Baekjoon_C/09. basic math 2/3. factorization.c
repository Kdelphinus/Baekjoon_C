#include <stdio.h>

int main()
{
    int num, i = 2;
    scanf("%d", &num);

    while (num > 1)
        if (num % i == 0)
        {
            printf("%d\n", i);
            num /= i;
        }
        else
            i++;

    return 0;
}