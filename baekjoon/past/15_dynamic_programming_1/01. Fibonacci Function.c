#include <stdio.h>

int dp[41][2];

int main()
{
	int test;
	scanf("%d", &test);

	dp[0][0]++; // 0�� 0�� �� �� ȣ��
	dp[1][1]++; // 1�� 1�� �� �� ȣ��

	for (int i = 0; i < test; i++)
	{
		int num;
		scanf("%d", &num);

		if (dp[num][0] == 0 && dp[num][1] == 0) // ���� ���� ������� ���� ���ڶ��
			for (int j = 2; j <= num; j++)
			{
				dp[j][0] = dp[j - 2][0] + dp[j - 1][0]; // �� ���ڿ� ���� ������ 0 ȣ�� ���� ��
				dp[j][1] = dp[j - 2][1] + dp[j - 1][1]; // �� ���ڿ� ���� ������ 1 ȣ�� ���� ��
			}

		printf("%d %d\n", dp[num][0], dp[num][1]);
	}
	return 0;
}
