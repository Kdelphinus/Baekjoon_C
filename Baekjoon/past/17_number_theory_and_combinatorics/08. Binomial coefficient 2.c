/**
 * @file 08. Binomial coefficient 2.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 이항계수의 성질을 이용
 * @date 2021-06-23 15:31:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long dp[1001][1000], mod = 10007;

void binomial_coefficient(int n, int k) // 이항계수 함수
{
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i > j && j > 0)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            else if (i == j || j == 0) // 분자 중 하나라도 0!이면 값은 1이다
                dp[i][j] = 1;
        }
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    binomial_coefficient(n, k);

    printf("%lld", dp[n][k]);

    return 0;
}