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
    for (int i = num - 1; i > -1; i--) // ū ������ Ȯ��
    {
        cnt += price / coins[i]; // ���� ������ ����
        price %= coins[i];       // �������� ���� �ݾ�
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