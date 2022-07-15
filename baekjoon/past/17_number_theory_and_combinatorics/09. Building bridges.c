/**
 * @file 09. Building bridges.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief end C start�� ����� ��
 * @date 2021-06-23 16:34:13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long dp[1001][1000], mod = 10007;

void binomial_coefficient(int n, int k) // ���װ�� �Լ�
{
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i > j && j > 0)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else if (i == j || j == 0) // ���� �� �ϳ��� 0!�̸� ���� 1�̴�
                dp[i][j] = 1;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    binomial_coefficient(30, 30);

    for (int i = 0; i < t; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%lld\n", dp[m][n]);
    }
    return 0;
}