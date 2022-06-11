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
	// �ʱⰪ
	max_total = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < num; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]); // �������� �ϴ� �Ͱ� �ڽź��� �ٽ� �����ϴ� �� �� ū ���� ����

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