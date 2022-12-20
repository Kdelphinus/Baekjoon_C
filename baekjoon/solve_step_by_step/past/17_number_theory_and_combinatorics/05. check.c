/**
 * @file 05. check.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ������ ������ �ִ������� ���ϴ� ���
 * @date 2021-06-23 01:20:14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
Ǯ�� ���
A = aM + r, B = bM + r, C = cM + r (M: �������� ��� ���� �Ǵ� ���� ����, r: ������)

-> |A - B| = (a - b)M, |B - C| = (b - c)M

-> gcd(|A - B|, |B - C|) = M
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) // ������ ���� �Լ�
{
    long long num1 = *(long long *)a;
    long long num2 = *(long long *)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;

    return 0;
}

long long GCD(long long x, long long y) // �ִ������� ���ϴ� �Լ�(y > x�� x > y�� ���·� ����� �����)
{
    if (y == 0)
        return x;
    return GCD(y, x % y);
}

void check(int num, long long numbers[])
{
    long long min = 0, root_min = 0, a = 0;
    long long tmp[100000];

    min = numbers[1] - numbers[0];

    for (int i = 2; i < num; i++) // ������ �� ���� ���̵��� �ִ������� ���Ѵ�
        min = GCD(min, numbers[i] - numbers[i - 1]);

    root_min = pow(min, 0.5);

    for (int i = 2; i <= root_min; i++) // ���� �ִ������� ������� ���Ѵ�
    {
        if (min % i == 0)
        {
            printf("%d ", i);
            if (min / i != i) // ���� �ٸ��� �ӽ� �迭�� �����Ѵ�(������������ ����ϱ� ����)
                tmp[a++] = min / i;
        }
    }
    if (a > 0) // �ӽ� �迭�� ���� ����Ǿ��ٸ�
    {
        for (int i = ((int)a - 1); i >= 0; i--) // �ڿ������� ����Ѵ�
            printf("%lld ", tmp[i]);
    }
    printf("%lld", min); // ���������� ���� �ִ������� ����Ѵ�
}

int main()
{
    int num;
    scanf("%d", &num);

    long long numbers[num];
    for (long long i = 0; i < num; i++)
        scanf("%lld", &numbers[i]);

    qsort(numbers, sizeof(numbers) / sizeof(long long), sizeof(long long), compare);

    check(num, numbers);

    return 0;
}