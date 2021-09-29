#include <stdio.h>
#define size 3000

char stars[size][size];

int blank_star(int num, int n_num)
{
    if (num == n_num)
    {
        stars[1][1] = ' ';
        return 0;
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i % 3 == 1 && j % 3 == 1)
            // 패턴의 가운데를 비워줌
            {
                stars[i][j] = ' ';
            }
            if ((i >= (num / 3) && i < ((num / 3) * 2)) && (j >= (num / 3) && j < ((num / 3) * 2)))
            // 전체의 가운데를 비워줌
            {
                stars[i][j] = ' ';
            }
            else
            {
                if ((i >= (n_num / 3) && i < ((n_num / 3) * 2)) && (j >= (n_num / 3) && j < ((n_num / 3) * 2)))
                // 전체의 가운데를 비워줌
                {
                    stars[i][j] = ' ';
                }
                else
                {
                    stars[i][j] = stars[i % n_num][j % n_num];
                }
            }
        }
    }
    blank_star(num, n_num * 3);
}

int main()
{
    int num;
    scanf("%d", &num);

    // 모든 곳을 별로 채운다
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            stars[i][j] = '*';
        }
    }

    blank_star(num, 3);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("%c", stars[i][j]);
        }
        printf("\n");
    }

    return 0;
}