#include <stdio.h>

int main()
{
    int num, index = 0;
    scanf("%d", &num);

    int number[num], anw[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &number[i]);
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (number[i] > number[j])
            {
                index++;
            }
        }
        anw[index] = number[i];
        index = 0;
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d\n", anw[i]);
    }

    return 0;
}