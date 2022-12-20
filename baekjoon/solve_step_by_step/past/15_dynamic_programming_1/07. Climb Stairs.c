/**
 * @file 07. Climb Stairs.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 현재 위치는 무조건 밟는다는 가정 하에 계산
 * @date 2021-06-12 19:50:10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int num;
int stairs[301];
int dp[301]; // 현 위치를 밟는다고 가정할 때, 가장 큰 점수

int max(int a, int b) // 크기를 구분하는 함수
{
	if (a > b)
		return a;
	else if (b > a)
		return b;
}

int scores()
{
	dp[0] = stairs[0];									   // 첫 계단을 밟으면 그 점수가 최대 점수
	dp[1] = stairs[0] + stairs[1];						   // 두 번째 계단을 밟을 때, 두 개를 다 밟는게 최대 점수
	dp[2] = max(dp[0] + stairs[2], stairs[1] + stairs[2]); // 세 번째 계단을 밟을 때, 첫 계단과 두 번째 계단 중 하나만 밟아야 한다

	for (int i = 3; i < num; i++) // 네 번째 부턴 이전 것을 밟는 경우와 이전 것을 밟지 않는 것 중 큰 점수를 가져간다
		dp[i] = max(stairs[i - 1] + stairs[i] + dp[i - 3], dp[i - 2] + stairs[i]);

	return dp[num - 1]; // 마지막 계단은 무조건 밟아야 하기에 마지막값 리턴
}

int main()
{
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &stairs[i]);

	printf("%d\n", scores());

	return 0;
}