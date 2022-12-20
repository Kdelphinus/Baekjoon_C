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
	dp[0] = 1;	 // ù ���� ������ 1���� ������ ����
	max_len = 1; // ���� ���̴� 1

	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j]) // ���� ��ġ �� ���� �۰� ���̰� �� ������ �ִٸ�
				dp[i] = dp[j];					  // ���̸� ����
		}

		dp[i]++; // �ڽ��� ������ �߰�

		if (dp[i] > max_len) // ���ݱ��� ���� LIS���� �� ��ٸ� ����
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