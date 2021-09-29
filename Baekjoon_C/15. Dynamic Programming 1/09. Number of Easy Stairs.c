/**
 * @file 09. Number of Easy Stairs.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 정수형이 담을 수 있는 최대크기를 넘지 않도록 유의
 * @date 2021-06-15 15:11:30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int num;
long mod = 1000000000;						  // 나눌 값
int tmp[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 0~9까지 차례대로 끝자리 숫자의 개수
int tmp2[10] = {
	0,
}; // tmp 임시 저장소
int dp[102] = {
	9,
	0,
}; // 초기값

int stair_number(int num)
{
	for (int i = 1; i <= num - 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 9) // 뒤에가 9일땐 8밖에 못온다
			{
				dp[i] += tmp[j] % mod;
				tmp2[8] += tmp[j] % mod;
			}
			else if (j == 0) // 뒤에가 0일땐 1밖에 못온다
			{
				dp[i] += tmp[j] % mod;
				tmp2[1] += tmp[j] % mod;
			}
			else // 나머지 숫자는 두 개의 숫자가 올 수 있다
			{
				dp[i] += (tmp[j] * 2) % mod;
				tmp2[j - 1] += tmp[j] % mod;
				tmp2[j + 1] += tmp[j] % mod;
			}
			dp[i] %= mod; // dp에 들어간 값이 정수형 최대값보다 넘지 않도록 계속 나눠줌
		}
		for (int j = 0; j < 10; j++) // tmp 업데이트 및 tmp2 초기화
		{
			tmp[j] = tmp2[j] % mod;
			tmp2[j] = 0;
		}
	}

	return dp[num - 1] % mod;
}

int main()
{
	scanf("%d", &num);
	printf("%d", stair_number(num));

	return 0;
}
