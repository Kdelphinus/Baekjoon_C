/**
 * @file 07. square matrix.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-04 17:19:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int mod = 1000;
long long a[6][6];
long long origin[6][6];

void matrix_multiplication(int n)
{
    long long tmp[6][6] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = 0;
            for (int k = 0; k < n; k++)
                num += (a[i][k] * a[k][j]) % mod;
            tmp[i][j] = num % mod;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = tmp[i][j];
    }
}

void square_matrix(long long n, long long b)
{
    if (b == 1)
        return;

    if (b == 2)
        return matrix_multiplication(n);

    square_matrix(n, b / 2);
    matrix_multiplication(n);

    if (b % 2)
    {
        long long tmp[6][6] = {0};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num = 0;
                for (int k = 0; k < n; k++)
                    num += (a[i][k] * origin[k][j]) % mod;
                tmp[i][j] = num % mod;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                a[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    long long n, b;
    scanf("%lld %lld", &n, &b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &a[i][j]);
            origin[i][j] = a[i][j];
        }
    }

    square_matrix(n, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%lld ", a[i][j] % mod); // 행렬 내 원소 최댓값이 1000이기에 나눠줘야 함
        printf("\n");
    }

    return 0;
}