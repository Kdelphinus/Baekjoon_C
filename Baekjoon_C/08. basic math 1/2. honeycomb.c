#include <stdio.h>

int main()
{
    int num, start = 2, end = 7, cnt = 2, plus = 0;
    scanf("%d", &num);

    while (1)
    {
        if (num == 1)
        {
            printf("%d", 1);
            break;
        }

        if (start <= num && end >= num)
        {
            printf("%d", cnt);
            break;
        }

        cnt++;
        plus += 6;
        start += plus;
        end += plus + 6;
    }

    return 0;
}