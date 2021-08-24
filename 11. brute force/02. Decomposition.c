/**
 * @file 02. Decomposition.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 재채점 결과 오답으로 나와 수정
 * @date 2021-08-24 11:53:55
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int decomp(int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = i, value = i;
        while (tmp > 0)
        {
            value += tmp % 10;
            tmp /= 10;
        }

        if (value == n)
            return i;
    }

    return 0;
}

int main()
{
    int num, i = 10, i_copy, temp;
    scanf("%d", &num);
    printf("%d", decomp(num));
    return 0;
}