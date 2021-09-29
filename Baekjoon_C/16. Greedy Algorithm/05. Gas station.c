/**
 * @file 05. Gas station.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief int 최대 범위에 주의할 것
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
    min_price = price[0];  // 지금까지 지나간 주유소 중 가장 싼 기름 가격
    driven_dist = dist[0]; // min_price에서 충전한 기름으로 가야하는 거리

    while (i < num - 1) // 마지막 주유소는 확인 안해도 됨
    {
        if (price[i] < min_price) // 더 싼 주유소가 나오면 거기까지만 기름을 넣고 그 다음 거리는 더 싸게 기름을 넣는다
        {
            total_price += min_price * driven_dist;
            min_price = price[i];
            driven_dist = 0;
        }

        driven_dist += dist[i];
        i++;
    }

    total_price += min_price * driven_dist; // 마지막 도시까지 오는 기름을 충전

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