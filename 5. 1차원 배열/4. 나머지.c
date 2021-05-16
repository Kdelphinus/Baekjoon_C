#include <stdio.h>

int main()
{

    int value[42] = {
        0,
    };

    int input, cnt = 0, num[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &input);
        num[i] = input % 42;
    }

    for (int i = 0; i < 10; i++)
    {
        if (value[num[i]] == 0)
        {
            cnt++;
            value[num[i]] = 1;
        }
    }
    printf("%d", cnt);

    return 0;
}