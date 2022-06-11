/**
 * @file 14. LCS.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief LCS.png 참고
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
			if (arr1[i] == arr2[j]) // 같은 글자일 땐 이전 글자 횟수에 1을 더한다
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else // 다른 글자이면 위쪽이나 왼쪽 길이 중 긴 길이를 가져온다
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