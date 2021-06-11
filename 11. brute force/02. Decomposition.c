#include <stdio.h>

int main()
{
    int num, i = 10, i_copy, temp;
    scanf("%d", &num);

    if (num < 10)
    {
        printf("%d", 0);
    }
    else
    {
        while (1)
        {
            temp = i;
            i_copy = i;
            while (temp > 0)
            {
                i_copy += temp % 10;
                temp /= 10;
            }

            if (i_copy == num)
            {
                printf("%d", i);
                break;
            }
            else
            {
                i++;
                if (i == num)
                {
                    printf("%d", 0);
                    break;
                }
            }
        }
    }

    return 0;
}