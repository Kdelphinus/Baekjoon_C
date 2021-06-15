#include <stdio.h>

int num, limit;		// 물건의 개수, 최대 무게
int object[101][2]; // 물건의 무게와 가치
int dp[100001];		// 그 무게(인덱스)에서 가장 가치있는 것

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
			if (object[i][0] <= j)										 // 물건을 넣을 수 있다면
				dp[j] = max(dp[j], dp[j - object[i][0]] + object[i][1]); //넣었을 때와 넣지 않았을 때 중 큰 가치를 고른다
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