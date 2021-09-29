#include <stdio.h>

int main()
{
    char temp;
    int width, height, anw = 64, white_cnt = 0, black_cnt = 0;
    scanf("%d %d", &height, &width);

    char board[height][width + 1];

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i <= width; i++)
        {
            scanf("%c", &temp);
            board[j][i - 1] = temp;
        }
    }

    for (int j = 0; j < height - 7; j++)
    {
        for (int i = 0; i < width - 7; i++)
        {

            for (int k = j; k < j + 8; k++)
            {
                for (int m = i; m < i + 8; m++)
                {
                    if ((m + k) % 2 == 0 && board[k][m] == 'B')
                    { // ¿ÞÂÊ ¸Ç À­Ä­°ú Â¦¼ö ÀÎµ¦½º´Â °°¾Æ¾ß ÇÑ´Ù
                        white_cnt++;
                    }
                    if ((m + k) % 2 != 0 && board[k][m] == 'W')
                    {
                        white_cnt++;
                    }
                }
            }

            for (int k = j; k < j + 8; k++)
            {
                for (int m = i; m < i + 8; m++)
                {
                    if ((m + k) % 2 == 0 && board[k][m] == 'W')
                    {
                        black_cnt++;
                    }
                    if ((m + k) % 2 != 0 && board[k][m] == 'B')
                    {
                        black_cnt++;
                    }
                }
            }

            if (black_cnt > white_cnt)
            {
                if (anw > white_cnt)
                {
                    anw = white_cnt;
                }
            }
            else
            {
                if (anw > black_cnt)
                {
                    anw = black_cnt;
                }
            }
            black_cnt = 0;
            white_cnt = 0;
        }
    }

    printf("%d\n", anw);

    return 0;
}

// È®ÀÎ¿ë
// for (int i = 0; i < height; i++)
// {
//     for (int j = 0; j < width; j++)
//     {
//         printf("%c", board[i][j]);
//     }
//     printf("\n");
// }

// printf("\n");
// for (int i = 0; i < height; i++)
// {
//     for (int j = 0; j < width; j++)
//     {
//         printf("%d ", board[i][j]);
//     }
//     printf("\n");
// }