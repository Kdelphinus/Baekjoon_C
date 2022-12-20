/**
 * @file 04. Padovan sequence.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief int ������ long long ��� �����ϱ�
 * @date 2021-06-12 16:59:07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long dp[102] = {
	0,
	1,
	1,
	1,
}; // �ʱⰪ ����, int ������ �Ѿ�� ���� �����⿡ long long���� ����

long long padovan(int num)
{
	if (dp[num] == 0) // ���� ���� �� �� ������ ���� ���ϰ� ����
	{
		dp[num] = padovan(num - 2) + padovan(num - 3);
		return dp[num];
	}

	return dp[num]; // ���� ������ �ٷ� ����
}
int main()
{
	int test;
	scanf("%d", &test);

	for (int i = 0; i < test; i++)
	{
		int num;
		scanf("%d", &num);
		printf("%lld\n", padovan(num));
	}
	return 0;
}