#include <stdio.h>

int main()
{

    int num, limit, temp, anw = 0;
    scanf("%d %d", &num, &limit);

    int cards[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &cards[i]);
    }

    for (int i = 0; i < num - 2; i++)
    {
        for (int j = i + 1; j < num - 1; j++)
        {
            for (int k = j + 1; k < num; k++)
            {
                temp = cards[i] + cards[j] + cards[k];
                if (limit > temp && anw < temp)
                {
                    anw = temp;
                }
                else if (limit == temp)
                {
                    anw = temp;
                    break;
                }
            }
        }
    }

    printf("%d", anw);

    return 0;
}