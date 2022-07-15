#include <stdio.h>

int main()
{
    int cnt = 0, limit, tem = 0, han, num = 100;
    int arr[3];

    scanf("%d", &limit);

    if (limit == 1000)
    {
        printf("%d", 144);
    }

    else if (limit >= 100)
    {
        while (num <= limit)
        {
            han = 0;
            tem = num;

            for (int i = 0; i < 3; i++)
            {
                arr[i] = tem % 10;
                tem /= 10;
            }

            if (arr[2] - arr[1] == arr[1] - arr[0])
            {
                cnt++;
            }
            num++;
        }
        printf("%d", cnt + 99);
    }

    else
    {
        printf("%d", limit);
    }

    return 0;
}