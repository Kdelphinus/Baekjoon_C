/**
 * @file 03. GCF and Common multiple.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 유클리드 호제법과 최소 공배수와 최대 공약수 사이의 관계를 이용
 * @date 2021-06-21 16:13:36
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int GCF(int a, int b) // 최대공약수를 구하는 함수
{
    if (a == b)
        return a;

    while (a > 0) // 유클리드 호제법 이용
    {
        int remain;
        remain = b % a;
        b = a;
        a = remain;
    }

    return b;
}

int LCM(int a, int b) // 최소 공배수를 구하는 함수
{
    if (a == b)
        return a;

    int min, tmp;
    min = GCF(a, b);
    tmp = a * b;
    if (tmp < 0)
        tmp *= -1;

    return tmp / min; // 최소 공배수와 최대 공약수 사이 관계를 이용
}

int main()
{
    int num1, num2, min;
    scanf("%d %d", &num1, &num2);
    if (num2 < num1)
    {
        int temp;
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printf("%d\n", GCF(num1, num2));
    printf("%d", LCM(num1, num2));

    return 0;
}