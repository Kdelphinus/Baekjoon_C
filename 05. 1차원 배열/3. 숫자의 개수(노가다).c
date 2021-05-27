#include <stdio.h>

int main()
{
    int num1, num2, num3, num, size, i, value;
    int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
    num = num1 * num2 * num3;
    if (num >= 100000000)
    {
        size = 9;
    }
    else if (num >= 10000000)
    {
        size = 8;
    }
    else
    {
        size = 7;
    }

    for (i = 0; i < size; i++)
    {
        value = num % 10;
        if (value < 5)
        {
            if (value == 0)
            {
                zero++;
            }
            else if (value == 1)
            {
                one++;
            }
            else if (value == 2)
            {
                two++;
            }
            else if (value == 3)
            {
                three++;
            }
            else
            {
                four++;
            }
        }
        else
        {
            if (value == 5)
            {
                five++;
            }
            else if (value == 6)
            {
                six++;
            }
            else if (value == 7)
            {
                seven++;
            }
            else if (value == 8)
            {
                eight++;
            }
            else
            {
                nine++;
            }
        }
        num /= 10;
    }

    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", zero, one, two, three, four, five, six, seven, eight, nine);

    return 0;
}