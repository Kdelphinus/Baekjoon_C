#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    int height[num], weight[num], anw[num];
    for (int i = 0; i < num; i++)
    {
        anw[i] = 1;
    }

    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &weight[i], &height[i]);
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i != j)
            {
                if (weight[i] < weight[j] && height[i] < height[j])
                {
                    anw[i] += 1;
                }
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d ", anw[i]);
    }

    return 0;
}