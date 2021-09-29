/**
 * @file 08. Make One.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief
 * @date 2021-06-12 20:16:53
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long dp[1000001];

long long make_one(long long x)
{
	for (int i = 2; i <= x; i++)
	{
		dp[i] = dp[i - 1] + 1; // 들어갈 수 있는 가장 큰 값은 전의 수보다 1많은 것이다

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) // 2의 배수이고 현재 값보다 작다면
			dp[i] = dp[i / 2] + 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) // 3의 배수이고 현재 값보다 작다면
			dp[i] = dp[i / 3] + 1;
	}

	return dp[x];
}

int main()
{
	long long x;
	scanf("%lld", &x);

	printf("%lld\n", make_one(x));
	return 0;
}