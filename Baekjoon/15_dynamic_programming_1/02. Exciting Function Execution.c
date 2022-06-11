#include <stdio.h>

int dp[21][21][21]; // a, b, c

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) // �ϳ��� ������ 1
		return 1;
	if (a > 20 || b > 20 || c > 20) // �ϳ��� 20 �̻��̸� 1048576
		return 1048576;

	if (dp[a][b][c] == 0) // ���� ������ ���� �Է°��̸�
	{
		if (a < b && b < c)
		{
			dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); // ���� ���� �����ϰ�
			return dp[a][b][c];													// ����
		}
		else
		{
			dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); // ���� ���� �����ϰ�
			return dp[a][b][c];																				 // ����
		}
	}

	else					// �̹� ���� �Է°��̸�
		return dp[a][b][c]; // ���� ���� ����
}

int main()
{
	while (1)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
	return 0;
}