#include <stdio.h>

int main()
{
    int num, five, three;
    scanf("%d", &num);

    five = num / 5;

    if (num % 5 == 0)
        printf("%d", five);
    else
    {
        while (1)
        {
            if ((num - 5 * five) % 3 == 0)
            {
                three = (num - 5 * five) / 3;
                printf("%d", five + three);
                break;
            }

            if (five <= 0)
            {
                printf("%d", -1);
                break;
            }

            five--;
        }
    }

    return 0;
}