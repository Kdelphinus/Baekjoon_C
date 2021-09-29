#include <stdio.h>

int num, limit;		// ������ ����, �ִ� ����
int object[101][2]; // ������ ���Կ� ��ġ
int dp[100001];		// �� ����(�ε���)���� ���� ��ġ�ִ� ��

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int packing()
{
	for (int i = 0; i < num; i++)
	{
		for (int j = limit; j > 0; j--)
		{
			if (object[i][0] <= j)										 // ������ ���� �� �ִٸ�
				dp[j] = max(dp[j], dp[j - object[i][0]] + object[i][1]); //�־��� ���� ���� �ʾ��� �� �� ū ��ġ�� ����
		}
	}

	return dp[limit];
}

int main()
{
	scanf("%d %d", &num, &limit);
	for (int i = 0; i < num; i++)
		scanf("%d %d", &object[i][0], &object[i][1]);

	printf("%d", packing());
	return 0;
}