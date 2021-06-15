/**
 * @file 11. LIS.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-15 15:50:39
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int num, max_len;
int arr[1001];
int dp[1001];

int LIS()
{
	dp[0] = 1;	 // 첫 값은 무조건 1개의 수열을 만듬
	max_len = 1; // 따라서 길이는 1

	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j]) // 이전 위치 중 값이 작고 길이가 긴 수열이 있다면
				dp[i] = dp[j];					  // 길이를 변경
		}

		dp[i]++; // 자신을 수열에 추가

		if (dp[i] > max_len) // 지금까지 구한 LIS보다 더 길다면 변경
			max_len = dp[i];
	}

	return max_len;
}

int main()
{
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	printf("%d", LIS());
	return 0;
}