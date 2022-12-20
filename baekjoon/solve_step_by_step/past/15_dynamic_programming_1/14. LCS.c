/**
 * @file 14. LCS.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief LCS.png ����
 * @date 2021-06-15 17:26:10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

int num;
int dp[1001][1001];
char arr1[1001];
char arr2[1001];

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int LCS()
{
	int len1, len2;
	len1 = strlen(arr1);
	len2 = strlen(arr2);

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (arr1[i] == arr2[j]) // ���� ������ �� ���� ���� Ƚ���� 1�� ���Ѵ�
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else // �ٸ� �����̸� �����̳� ���� ���� �� �� ���̸� �����´�
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}

	return dp[len1][len2];
}

int main()
{
	scanf("%d", &num);
	scanf("%s", arr1);
	scanf("%s", arr2);

	printf("%d", LCS());
	return 0;
}