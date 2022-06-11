/**
 * @file 07. Climb Stairs.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ���� ��ġ�� ������ ��´ٴ� ���� �Ͽ� ���
 * @date 2021-06-12 19:50:10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int num;
int stairs[301];
int dp[301]; // �� ��ġ�� ��´ٰ� ������ ��, ���� ū ����

int max(int a, int b) // ũ�⸦ �����ϴ� �Լ�
{
	if (a > b)
		return a;
	else if (b > a)
		return b;
}

int scores()
{
	dp[0] = stairs[0];									   // ù ����� ������ �� ������ �ִ� ����
	dp[1] = stairs[0] + stairs[1];						   // �� ��° ����� ���� ��, �� ���� �� ��°� �ִ� ����
	dp[2] = max(dp[0] + stairs[2], stairs[1] + stairs[2]); // �� ��° ����� ���� ��, ù ��ܰ� �� ��° ��� �� �ϳ��� ��ƾ� �Ѵ�

	for (int i = 3; i < num; i++) // �� ��° ���� ���� ���� ��� ���� ���� ���� ���� �ʴ� �� �� ū ������ ��������
		dp[i] = max(stairs[i - 1] + stairs[i] + dp[i - 3], dp[i - 2] + stairs[i]);

	return dp[num - 1]; // ������ ����� ������ ��ƾ� �ϱ⿡ �������� ����
}

int main()
{
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &stairs[i]);

	printf("%d\n", scores());

	return 0;
}