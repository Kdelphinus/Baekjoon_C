/**
 * @file 05. check.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 수들의 차이의 최대공약수를 구하는 방법
 * @date 2021-06-23 01:20:14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
풀이 방법
A = aM + r, B = bM + r, C = cM + r (M: 나머지가 모두 같게 되는 수의 집합, r: 나머지)

-> |A - B| = (a - b)M, |B - C| = (b - c)M

-> gcd(|A - B|, |B - C|) = M
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) // 정렬을 위한 함수
{
    long long num1 = *(long long *)a;
    long long num2 = *(long long *)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;

    return 0;
}

long long GCD(long long x, long long y) // 최대공약수를 구하는 함수(y > x면 x > y인 상태로 만들고 진행됨)
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

    for (int i = 2; i < num; i++) // 인접한 두 수의 차이들의 최대공약수를 구한다
        min = GCD(min, numbers[i] - numbers[i - 1]);

    root_min = pow(min, 0.5);

    for (int i = 2; i <= root_min; i++) // 구한 최대공약수의 약수들을 구한다
    {
        if (min % i == 0)
        {
            printf("%d ", i);
            if (min / i != i) // 몫이 다르면 임시 배열에 저장한다(오름차순으로 출력하기 위해)
                tmp[a++] = min / i;
        }
    }
    if (a > 0) // 임시 배열에 값이 저장되었다면
    {
        for (int i = ((int)a - 1); i >= 0; i--) // 뒤에서부터 출력한다
            printf("%lld ", tmp[i]);
    }
    printf("%lld", min); // 마지막으로 구한 최대공약수를 출력한다
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