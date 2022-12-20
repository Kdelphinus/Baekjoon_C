/**
 * @file 10. wine tasting.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 안 마시는 것이 더 최대값이 될 수 있음을 주의할 것
 * @date 2021-06-15 15:30:22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int num, drink;	 // 와인잔의 개수, 마실 수 있는 최대 양
int wine[10001]; // 와인잔에 들은 와인의 양
int dp[10001];	 // 그 잔의 차례일 때 가장 많이 마실 수 있는 양

int max(int a, int b) // 두 수의 크기를 비교하는 함수
{
	if (a > b)
		return a;
	return b;
}

int wine_tasting()
{
	// 초기값
	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];
	dp[2] = max(dp[1], max(wine[0] + wine[2], wine[1] + wine[2]));

	drink = max(dp[1], dp[2]); // 최대한 마실 수 있는 양의 초기값

	for (int i = 3; i < num; i++)
	{ // 전 것을 마시는 것과 전전 것을 마시는 것, 안 마시는 것 중 더 많이 마실 수 있는 것을 택함
		dp[i] = max(dp[i - 1], max(dp[i - 2] + wine[i], wine[i] + wine[i - 1] + dp[i - 3]));
		drink = max(dp[i], drink); // 최대한 많이 마실 수 있는 양과 현재 마신 양을 비교하여 더 큰 것을 최대양으로 변경
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