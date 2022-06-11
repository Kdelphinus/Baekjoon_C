#include <stdio.h>

int main()
{
    int temp = 666, temp_2, num, cnt = 0, check = 0;
    scanf("%d", &num);
    num -= 1;

    while (num > cnt)
    {
        temp++;
        temp_2 = temp;
        check = 0;
        while (temp_2 > 0)
        {
            if (check == 3)
            {
                break;
            }

            if (temp_2 % 10 == 6)
            {
                check++;
            }
            else
            {
                check = 0;
            }

            temp_2 /= 10;
        }
        if (check == 3)
        {
            cnt++;
        }
    }
    printf("%d", temp);

    return 0;
}