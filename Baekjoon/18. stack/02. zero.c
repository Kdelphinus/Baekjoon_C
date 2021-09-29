/**
 * @file 02. zero.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 스택을 이용
 * @date 2021-06-24 15:14:58
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int anw, len, arr[100001];

void push(int num)
{
    arr[len++] = num;
}

void pop()
{
    arr[len - 1] = '\0';
    len--;
}

int sum()
{
    for (int i = 0; i < len; i++)
        anw += arr[i];
    return anw;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int num;
        scanf("%d", &num);

        if (num)
            push(num);
        else
            pop();
    }

    printf("%d", sum());

    return 0;
}