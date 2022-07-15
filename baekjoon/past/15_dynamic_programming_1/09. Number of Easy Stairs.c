/**
 * @file 09. Number of Easy Stairs.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief �������� ���� �� �ִ� �ִ�ũ�⸦ ���� �ʵ��� ����
 * @date 2021-06-15 15:11:30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int num;
long mod = 1000000000;						  // ���� ��
int tmp[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 0~9���� ���ʴ�� ���ڸ� ������ ����
int tmp2[10] = {
	0,
}; // tmp �ӽ� �����
int dp[102] = {
	9,
	0,
}; // �ʱⰪ

int stair_number(int num)
{
	for (int i = 1; i <= num - 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 9) // �ڿ��� 9�϶� 8�ۿ� ���´�
			{
				dp[i] += tmp[j] % mod;
				tmp2[8] += tmp[j] % mod;
			}
			else if (j == 0) // �ڿ��� 0�϶� 1�ۿ� ���´�
			{
				dp[i] += tmp[j] % mod;
				tmp2[1] += tmp[j] % mod;
			}
			else // ������ ���ڴ� �� ���� ���ڰ� �� �� �ִ�
			{
				dp[i] += (tmp[j] * 2) % mod;
				tmp2[j - 1] += tmp[j] % mod;
				tmp2[j + 1] += tmp[j] % mod;
			}
			dp[i] %= mod; // dp�� �� ���� ������ �ִ밪���� ���� �ʵ��� ��� ������
		}
		for (int j = 0; j < 10; j++) // tmp ������Ʈ �� tmp2 �ʱ�ȭ
		{
			tmp[j] = tmp2[j] % mod;
			tmp2[j] = 0;
		}
	}

	return dp[num - 1] % mod;
}

int main()
{
	scanf("%d", &num);
	printf("%d", stair_number(num));

	return 0;
}
