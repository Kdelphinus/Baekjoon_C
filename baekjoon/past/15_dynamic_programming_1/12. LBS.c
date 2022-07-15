/**
 * @file 12. LBS.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-15 16:19:01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int num, max_len;
int arr[1001];
int dp[1001][2]; // [i][0]: i번째에서 증가수열로 가장 크게 얻을 수 있는 길이
				 // [i][1]: i번째에서 바이토닉 수열로 가장 크게 얻을 수 있는 길이

int max(int a, int b) // 크기를 비교하는 함수
{
	if (a > b)
		return a;
	return b;
}

int LBS()
{
	// 초기값 설정
	dp[0][0] = 1;
	dp[0][1] = 1;
	max_len = 1;

	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i][0] < dp[j][0]) // 증가수열과 같음
				dp[i][0] = dp[j][0];
			if (arr[j] > arr[i] && (dp[i][1] < dp[j][1] || dp[i][1] < dp[j][0])) // 감소중인 수열이나 이제 감소를 시작해도 될 때
				dp[i][1] = max(dp[j][0], dp[j][1]);
		}

		// 자기 자신을 더해줌
		dp[i][0]++;
		dp[i][1]++;

		if (max_len < dp[i][0])
			max_len = dp[i][0];
		if (max_len < dp[i][1])
			max_len = dp[i][1];
	}

	return max_len;
}

int main()
{
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	printf("%d", LBS());
	return 0;
}