/**
 * @file 04. Padovan sequence.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief int 범위와 long long 출력 생각하기
 * @date 2021-06-12 16:59:07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long dp[102] = {
	0,
	1,
	1,
	1,
}; // 초기값 설정, int 범위를 넘어가는 값이 나오기에 long long으로 설정

long long padovan(int num)
{
	if (dp[num] == 0) // 값이 아직 안 들어가 있으면 값을 구하고 저장
	{
		dp[num] = padovan(num - 2) + padovan(num - 3);
		return dp[num];
	}

	return dp[num]; // 값이 있으면 바로 리턴
}
int main()
{
	int test;
	scanf("%d", &test);

	for (int i = 0; i < test; i++)
	{
		int num;
		scanf("%d", &num);
		printf("%lld\n", padovan(num));
	}
	return 0;
}