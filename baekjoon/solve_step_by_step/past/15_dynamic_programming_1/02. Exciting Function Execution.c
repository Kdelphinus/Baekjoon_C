#include <stdio.h>

int dp[21][21][21]; // a, b, c

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) // 하나라도 음수면 1
		return 1;
	if (a > 20 || b > 20 || c > 20) // 하나라도 20 이상이면 1048576
		return 1048576;

	if (dp[a][b][c] == 0) // 아직 구하지 않은 입력값이면
	{
		if (a < b && b < c)
		{
			dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); // 구한 값을 저장하고
			return dp[a][b][c];													// 리턴
		}
		else
		{
			dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); // 구한 값을 저장하고
			return dp[a][b][c];																				 // 리턴
		}
	}

	else					// 이미 구한 입력값이면
		return dp[a][b][c]; // 구한 값을 리턴
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