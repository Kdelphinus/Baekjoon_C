/**
 * @file 01. stack.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 길이를 구하기 위해 len을 따로 설정
 * @date 2021-06-24 15:03:03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

int len, arr[10001];

void push(int num) // 배열에 숫자를 넣는 함수
{
    arr[len++] = num;
}

int pop() // 맨 위(맨 뒤)에 있는 수를 빼고 출력하는 함수
{
    int tmp;
    if (len)
    {
        tmp = arr[len - 1];
        arr[len - 1] = '\0';
        len--;
        return tmp;
    }
    return -1;
}

int size() // 배열에 들어간 숫자의 개수를 출력하는 함수
{
    return len;
}

int empty() // 비어있는지 확인하는 함수
{
    if (len)
        return 0;
    return 1;
}

int top() // 가장 위에 있는 수를 출력하는 함수
{
    if (len)
        return arr[len - 1];
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        char order[6] = {0};
        int num;
        scanf("%s", order);
        if (strcmp(order, "push"))
        {
            if (strcmp(order, "pop") == 0)
                printf("%d\n", pop());
            if (strcmp(order, "size") == 0)
                printf("%d\n", size());
            if (strcmp(order, "empty") == 0)
                printf("%d\n", empty());
            if (strcmp(order, "top") == 0)
                printf("%d\n", top());
        }
        else
        {
            scanf("%d", &num);
            push(num);
        }
    }

    return 0;
}