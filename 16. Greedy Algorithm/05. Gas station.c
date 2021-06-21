/**
 * @file 05. Gas station.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief int �ִ� ������ ������ ��
 * @date 2021-06-21 15:26:18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long gas_station(long long num, long long dist[], long long price[])
{
    long long total_price = 0, min_price = 0, driven_dist = 0;
    int i = 1;
    min_price = price[0];  // ���ݱ��� ������ ������ �� ���� �� �⸧ ����
    driven_dist = dist[0]; // min_price���� ������ �⸧���� �����ϴ� �Ÿ�

    while (i < num - 1) // ������ �����Ҵ� Ȯ�� ���ص� ��
    {
        if (price[i] < min_price) // �� �� �����Ұ� ������ �ű������ �⸧�� �ְ� �� ���� �Ÿ��� �� �ΰ� �⸧�� �ִ´�
        {
            total_price += min_price * driven_dist;
            min_price = price[i];
            driven_dist = 0;
        }

        driven_dist += dist[i];
        i++;
    }

    total_price += min_price * driven_dist; // ������ ���ñ��� ���� �⸧�� ����

    return total_price;
}

int main()
{
    long long num;
    scanf("%lld", &num);

    long long dist[num - 1];
    for (long long i = 0; i < num - 1; i++)
        scanf("%lld", &dist[i]);

    long long price[num];
    for (long long i = 0; i < num; i++)
        scanf("%lld", &price[i]);

    printf("%lld", gas_station(num, dist, price));

    return 0;
}