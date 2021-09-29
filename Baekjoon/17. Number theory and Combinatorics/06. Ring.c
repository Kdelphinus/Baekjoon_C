/**
 * @file 06. Ring.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-23 02:09:23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int gcd(int a, int b) // 최대공약수를 구하는 함수
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void ring_rotates(int num, int rings[])
{
    int standard, tmp;
    standard = rings[0]; // 기준이 되는 링

    for (int i = 1; i < num; i++)
    {
        tmp = gcd(standard, rings[i]);                     // 현재 링과 기준이 되는 링의 최대공약수
        printf("%d/%d\n", standard / tmp, rings[i] / tmp); // 각각 최대공약수로 나누면 약분한 분수형태가 된다
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    int rings[num];
    for (int i = 0; i < num; i++)
        scanf("%d", &rings[i]);

    ring_rotates(num, rings);

    return 0;
}