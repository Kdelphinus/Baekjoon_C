/**
 * @file 06. matrix multiplication.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-04 16:42:07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

/* 
1 2   -1 -2 0
3 1    0  0 3
5 6
*/
int a[101][101], b[101][101];

void matrix_multiplication(int a_n, int a_m, int b_m)
{
    for (int i = 0; i < a_n; i++)
    {
        for (int j = 0; j < b_m; j++)
        {
            int num = 0;
            for (int k = 0; k < a_m; k++)
                num += a[i][k] * b[k][j]; // a´Â nÀ» Â÷·Ê´ë·Î, b´Â mÀ» Â÷·Ê´ë·Î °öÇÔ
            printf("%d ", num);
        }
        printf("\n");
    }
}

int main()
{
    int a_n, a_m, b_n, b_m;

    scanf("%d %d", &a_n, &a_m);

    for (int i = 0; i < a_n; i++)
    {
        for (int j = 0; j < a_m; j++)
            scanf("%d", &a[i][j]);
    }

    scanf("%d %d", &b_n, &b_m);
    for (int i = 0; i < b_n; i++)
    {
        for (int j = 0; j < b_m; j++)
            scanf("%d", &b[i][j]);
    }

    matrix_multiplication(a_n, a_m, b_m);

    return 0;
}