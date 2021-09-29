/**
 * @file 05.  binomial coefficient 3.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 이항계수의 분모를 페르마의 소정리를 이용하여 구하고 이를 이용하여 이항계수를 구한다
 * @date 2021-07-23 11:47:52
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// 이항계수(n, k) = n! / (k!(n - k)!)
// 페르마의 소정리: ((p - 1)! a^(p - 1)) % p = (p - 1)! % p
//                 (a^(p - 1)) % p = 1 % p
//                 (a^p) % p = a % p
//                 (a^(p - 2)) % p = (1 / a) % p

#include <stdio.h>

long long p = 1000000007;
long long fac[4000001];

void factorial(long long n) // 펙토리얼을 구하는 함수
{
    fac[0] = 1;
    fac[1] = 1;

    for (long long i = 2; i <= n; i++)
        fac[i] = fac[i - 1] * i % p; // long long을 넘어갈 수 있기에 p로 나눈 나머지 사용
}

long long multiplication(long long a, long long b) //  a^b를 구하는 함수, 20-4번 문제 참고
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
    long long denominator, numerator;      // 분모와 분자
    factorial(n);                          // n!까지 구하고
    denominator = fac[n - k] * fac[k] % p; // 분모를 구함, long long을 벗어날 수 있기에 p로 나눈 나머지 사용
    numerator = fac[n];                    // 분자를 구함

    return (numerator * multiplication(denominator, p - 2) % p) % p; // (a^(p - 2)) % p = (1 / a) % p, 여기선 a가 denominator
}

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    printf("%lld", binomial_coefficient(n, k));
    return 0;
}