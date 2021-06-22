/**
 * @file 07. Binomial coefficient 1.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ���װ���� ���Ǹ� �̿��Ͽ� ���� ���ϴ� ���
 * @date 2021-06-23 02:14:53
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int factorial(int num) // ���丮�� �Լ�
{
    if (num == 1)
        return 1;

    int value = 1;
    for (int i = 2; i <= num; i++)
        value *= i;
    return value;
}

int binomial_coefficient(int n, int k) // ���װ�� �Լ�
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