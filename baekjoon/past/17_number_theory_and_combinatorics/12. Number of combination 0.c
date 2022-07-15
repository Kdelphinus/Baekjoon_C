/**
 * @file 12. Number of combination 0.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 2, 5를 한 번에 구하지 말고 따로 구하여 비교해야 함
 * @date 2021-06-23 19:38:44
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long min(long long a, long long b) // 작은 값을 리턴하는 함수
{
    if (a < b)
        return a;
    return b;
}

long long check_num(long long num, long long check) // check가 factorial(num)에 얼마나 곱해졌는지 확인하는 함수
{
    long long tmp, anw = 0;
    tmp = check;

    while (num >= tmp) // num을 check의 제곱수로 나눈 것들의 합
    {
        anw += num / tmp;
        tmp *= check;
    }

    return anw;
}

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);

    long long count_five, count_two;
    count_five = check_num(n, 5) - check_num(k, 5) - check_num(n - k, 5); // 5가 곱해진 개수
    count_two = check_num(n, 2) - check_num(k, 2) - check_num(n - k, 2);  // 2가 곱해진 개수

    printf("%lld", min(count_five, count_two)); // 5와 2가 곱해져야 0이 생기기에 둘 중 작은 값을 가져옴
    return 0;
}