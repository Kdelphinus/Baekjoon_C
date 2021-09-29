/**
 * @file 04. multiplication.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-22 21:41:45
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long multiplication(long long a, long long b, long long c)
{
    // 10^10을 10^5 * 10^5로 나누어 계산하는 방식의 함수
    // 지수가 1이 될 때까지 나누고 다시 올라오면서 계속해서 나눠주는 방식
    long long tmp;
    if (b == 1)
        return a % c;
    else
    {
        tmp = multiplication(a, b / 2, c);
        if (b % 2)
            return (((tmp * tmp) % c) * a) % c; // tmp * tmp가 long long 범위를 벗어날 수 있기에 c로 나눠준다
        else
            return (tmp * tmp) % c;
    }
}

int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", multiplication(a, b, c));
    return 0;
}