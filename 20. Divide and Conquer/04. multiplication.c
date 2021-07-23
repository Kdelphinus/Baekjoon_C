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
    // 10^10�� 10^5 * 10^5�� ������ ����ϴ� ����� �Լ�
    // ������ 1�� �� ������ ������ �ٽ� �ö���鼭 ����ؼ� �����ִ� ���
    long long tmp;
    if (b == 1)
        return a % c;
    else
    {
        tmp = multiplication(a, b / 2, c);
        if (b % 2)
            return (((tmp * tmp) % c) * a) % c; // tmp * tmp�� long long ������ ��� �� �ֱ⿡ c�� �����ش�
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