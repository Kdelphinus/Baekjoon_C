/**
 * @file 12. Number of combination 0.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 2, 5�� �� ���� ������ ���� ���� ���Ͽ� ���ؾ� ��
 * @date 2021-06-23 19:38:44
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long min(long long a, long long b) // ���� ���� �����ϴ� �Լ�
{
    if (a < b)
        return a;
    return b;
}

long long check_num(long long num, long long check) // check�� factorial(num)�� �󸶳� ���������� Ȯ���ϴ� �Լ�
{
    long long tmp, anw = 0;
    tmp = check;

    while (num >= tmp) // num�� check�� �������� ���� �͵��� ��
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
    count_five = check_num(n, 5) - check_num(k, 5) - check_num(n - k, 5); // 5�� ������ ����
    count_two = check_num(n, 2) - check_num(k, 2) - check_num(n - k, 2);  // 2�� ������ ����

    printf("%lld", min(count_five, count_two)); // 5�� 2�� �������� 0�� ����⿡ �� �� ���� ���� ������
    return 0;
}