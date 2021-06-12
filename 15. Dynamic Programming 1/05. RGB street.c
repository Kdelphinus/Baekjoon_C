/**
 * @file 04. RGB street.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-12 17:17:41
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>

int prices[1001][3];
int dp[1001][3];

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}
int RGB_street(int num)
{
	// �ʱⰪ ����, ó���� ���� �� ��ĥ
	dp[0][0] = prices[0][0];
	dp[0][1] = prices[0][1];
	dp[0][2] = prices[0][2];

	for (int i = 1; i < num; i++) // �̹��� ��ĥ�� ���� ������ ������ �� �� ���� ���� ��Ʈ�� ����
	{
		dp[i][0] = prices[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = prices[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = prices[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	// ���� �� ���� ���� ��Ʈ�� ����
	if (dp[num - 1][0] < dp[num - 1][1] && dp[num - 1][0] < dp[num - 1][2])
		return dp[num - 1][0];
	if (dp[num - 1][1] < dp[num - 1][0] && dp[num - 1][1] < dp[num - 1][2])
		return dp[num - 1][1];
	if (dp[num - 1][2] < dp[num - 1][1] && dp[num - 1][2] < dp[num - 1][0])
		return dp[num - 1][2];
}

int main()
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		prices[i][0] = a;
		prices[i][1] = b;
		prices[i][2] = c;
	}

	printf("%d", RGB_street(num));
	return 0;
}