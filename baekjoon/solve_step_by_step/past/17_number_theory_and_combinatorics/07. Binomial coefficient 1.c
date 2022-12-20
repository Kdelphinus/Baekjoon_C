/**
 * @file 07. Binomial coefficient 1.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 이항계수의 정의를 이용하여 답을 구하는 방식
 * @date 2021-06-23 02:14:53
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int factorial(int num) // 팩토리얼 함수
{
    if (num == 1)
        return 1;

    int value = 1;
    for (int i = 2; i <= num; i++)
        value *= i;
    return value;
}

int binomial_coefficient(int n, int k) // 이항계수 함수
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d", binomial_coefficient(n, k));

    return 0;
}