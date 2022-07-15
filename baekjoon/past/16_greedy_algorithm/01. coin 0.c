/**
 * @file 01. coin 0.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-16 20:37:01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int coins[11];

int coin(int num, int price)
{
    int cnt = 0;
    for (int i = num - 1; i > -1; i--) // 큰 값부터 확인
    {
        cnt += price / coins[i]; // 몫은 동전의 개수
        price %= coins[i];       // 나머지는 남은 금액
    }

    return cnt;
}

int main()
{
    int num, price;
    scanf("%d %d", &num, &price);
    for (int i = 0; i < num; i++)
        scanf("%d", &coins[i]);

    printf("%d", coin(num, price));
    return 0;
}