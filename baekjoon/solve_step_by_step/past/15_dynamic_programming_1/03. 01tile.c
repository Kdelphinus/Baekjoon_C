/**
 * @file 03. 01tile.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 01타일의 개수는 피보나치 수열과 같은 형태를 보인다
 * @date 2021-06-12 16:55:57
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int fib(int len)
{
	int current = 1, previous = 0, temp;

	for (int i = 1; i <= len; i++)
	{
		temp = current % 15746;					// 현재값을 임시로 저장
		current = (current + previous) % 15746; // 이전값과 현재값을 더한 값을 현재값으로 최신화
		previous = temp;						// 직전 현재값을 이전값으로 최신화
	}

	return current;
}

int main()
{
	int len;
	scanf("%d", &len);

	printf("%d\n", fib(len));

	return 0;
}