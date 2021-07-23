/**
 * @file 05.  binomial coefficient 3.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ���װ���� �и� �丣���� �������� �̿��Ͽ� ���ϰ� �̸� �̿��Ͽ� ���װ���� ���Ѵ�
 * @date 2021-07-23 11:47:52
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// ���װ��(n, k) = n! / (k!(n - k)!)
// �丣���� ������: ((p - 1)! a^(p - 1)) % p = (p - 1)! % p
//                 (a^(p - 1)) % p = 1 % p
//                 (a^p) % p = a % p
//                 (a^(p - 2)) % p = (1 / a) % p

#include <stdio.h>

long long p = 1000000007;
long long fac[4000001];

void factorial(long long n) // ���丮���� ���ϴ� �Լ�
{
    fac[0] = 1;
    fac[1] = 1;

    for (long long i = 2; i <= n; i++)
        fac[i] = fac[i - 1] * i % p; // long long�� �Ѿ �� �ֱ⿡ p�� ���� ������ ���
}

long long multiplication(long long a, long long b) //  a^b�� ���ϴ� �Լ�, 20-4�� ���� ����
{
    long long tmp;
    if (b == 1)
        return a;
    tmp = multiplication(a, b / 2);
    if (b % 2)
        return (((tmp * tmp) % p) * a) % p;
    else
        return (tmp * tmp) % p;
}

long long binomial_coefficient(long long n, long long k)
{
    long long denominator, numerator;      // �и�� ����
    factorial(n);                          // n!���� ���ϰ�
    denominator = fac[n - k] * fac[k] % p; // �и� ����, long long�� ��� �� �ֱ⿡ p�� ���� ������ ���
    numerator = fac[n];                    // ���ڸ� ����

    return (numerator * multiplication(denominator, p - 2) % p) % p; // (a^(p - 2)) % p = (1 / a) % p, ���⼱ a�� denominator
}

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    printf("%lld", binomial_coefficient(n, k));
    return 0;
}