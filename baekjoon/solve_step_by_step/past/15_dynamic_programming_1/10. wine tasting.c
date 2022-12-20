/**
 * @file 10. wine tasting.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief �� ���ô� ���� �� �ִ밪�� �� �� ������ ������ ��
 * @date 2021-06-15 15:30:22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int num, drink;	 // �������� ����, ���� �� �ִ� �ִ� ��
int wine[10001]; // �����ܿ� ���� ������ ��
int dp[10001];	 // �� ���� ������ �� ���� ���� ���� �� �ִ� ��

int max(int a, int b) // �� ���� ũ�⸦ ���ϴ� �Լ�
{
	if (a > b)
		return a;
	return b;
}

int wine_tasting()
{
	// �ʱⰪ
	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];
	dp[2] = max(dp[1], max(wine[0] + wine[2], wine[1] + wine[2]));

	drink = max(dp[1], dp[2]); // �ִ��� ���� �� �ִ� ���� �ʱⰪ

	for (int i = 3; i < num; i++)
	{ // �� ���� ���ô� �Ͱ� ���� ���� ���ô� ��, �� ���ô� �� �� �� ���� ���� �� �ִ� ���� ����
		dp[i] = max(dp[i - 1], max(dp[i - 2] + wine[i], wine[i] + wine[i - 1] + dp[i - 3]));
		drink = max(dp[i], drink); // �ִ��� ���� ���� �� �ִ� ��� ���� ���� ���� ���Ͽ� �� ū ���� �ִ������ ����
	}
	return drink;
}

int main()
{
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &wine[i]);

	printf("%d", wine_tasting());
	return 0;
}