#include <stdio.h>

int dp[41][2];

int main()
{
	int test;
	scanf("%d", &test);

	dp[0][0]++; // 0은 0을 한 번 호출
	dp[1][1]++; // 1은 1을 한 번 호출

	for (int i = 0; i < test; i++)
	{
		int num;
		scanf("%d", &num);

		if (dp[num][0] == 0 && dp[num][1] == 0) // 만약 아직 계산하지 않은 숫자라면
			for (int j = 2; j <= num; j++)
			{
				dp[j][0] = dp[j - 2][0] + dp[j - 1][0]; // 전 숫자와 전전 숫자의 0 호출 수의 합
				dp[j][1] = dp[j - 2][1] + dp[j - 1][1]; // 전 숫자와 전전 숫자의 1 호출 수의 합
			}

		printf("%d %d\n", dp[num][0], dp[num][1]);
	}
	return 0;
}
