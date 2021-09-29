/**
 * @file 15. Continuous sum.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-15 17:37:17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int num, max_total;
int arr[100001];
int dp[100001];

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int continuous_sum()
{
	// 초기값
	max_total = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < num; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]); // 연속합을 하는 것과 자신부터 다시 시작하는 것 중 큰 것을 선택

		if (max_total < dp[i])
			max_total = dp[i];
	}

	return max_total;
}

int main()
{
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	printf("%d", continuous_sum());
	return 0;
}