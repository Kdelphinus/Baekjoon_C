/**
 * @file 01. queue 2.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 빼는 숫자를 인덱스를 통해 무시하는 방향으로 진행
 * @date 2021-07-01 21:57:56
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

int queue[2000001];
int idx, tmp_idx; // 저장해야 할 인덱스 위치, 현재 큐 시작 위치

void push(int n)
{
    queue[idx] = n; // idx - tmp_idx(현재 큐 내의 숫자 개수) + tmp_idx(큐 시작 위치)
    idx++;          // 인덱스 이동
}

int pop()
{
    int tmp;

    if (idx - tmp_idx) // 큐에 숫자가 들어있다면
    {
        tmp = queue[tmp_idx]; // 맨 앞의 숫자를 tmp에 저장하고
        tmp_idx++;            // 시작 위치를 한 칸 뒤로 미룬다
        return tmp;
    }
    return -1;
}

int size()
{
    return idx - tmp_idx; // 현재 위치 - 시작 위치 = 들어있는 수의 개수
}

int empty()
{
    if (idx - tmp_idx)
        return 0;
    return 1;
}

int front()
{
    if (idx - tmp_idx)
        return queue[tmp_idx]; // 현재 큐의 시작 위치
    return -1;
}

int back()
{
    if (idx - tmp_idx)
        return queue[idx - 1];
    return -1;
}

int main()
{
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        char order[6] = {0};
        scanf("%s", order);
        if (strcmp(order, "push"))
        {
            if (strcmp(order, "pop") == 0)
                printf("%d\n", pop());
            else if (strcmp(order, "size") == 0)
                printf("%d\n", size());
            else if (strcmp(order, "empty") == 0)
                printf("%d\n", empty());
            else if (strcmp(order, "front") == 0)
                printf("%d\n", front());
            else if (strcmp(order, "back") == 0)
                printf("%d\n", back());
            else
                printf("error: %s\n", order);
        }
        else
        {
            int n;
            scanf("%d", &n);
            push(n);
        }
    }
    return 0;
}