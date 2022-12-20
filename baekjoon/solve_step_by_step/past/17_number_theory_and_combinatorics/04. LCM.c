/**
 * @file 04. LCM.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-21 18:20:12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int GCF(int x, int y)
{
    while (x > 0) // 유틀리드 호제법을 이용하여 최대공약수를 구하는 함수
    {
        int remain;
        remain = y % x;
        y = x;
        x = remain;
    }

    return y;
}

int LCM(int x, int y) // 최대공약수와의 관계를 이용하여 최소공배수를 구하는 함수
{
    int gcf;
    gcf = GCF(x, y);

    return (x * y) / gcf;
}

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test;
         i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) // x가 y보다 크면 x와 y를 바꾼다
        {
            int tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
        printf("%d\n", LCM(x, y));
    }
}