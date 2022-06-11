#include <stdio.h>

int main()
{

    int num[10000] = {
        0,
    };
    int *num_ptr;
    int han = 0, tem, number = 1;
    num_ptr = &num[0];

    while (number < 10000)
    {
        han = 0;
        tem = number;
        while (tem > 0)
        {
            han += tem % 10;
            tem /= 10;
        }
        han = han + number;
        if (han < 10000)
        {
            *(num_ptr + han) = 1;
        }
        number++;
    }

    for (int i = 1; i < 10000; i++)
    {
        if (*(num_ptr + i) == 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}