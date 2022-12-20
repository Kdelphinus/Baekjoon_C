/**
 * @file 05. deque.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-03 10:33:22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

int deque[20001];
int start = 10001, end = 10001; // 앞에도 숫자가 들어가는 것을 감안해 시작 인덱스를 중간부터

void push_front(int num)
{
    deque[--start] = num;
}

void push_back(int num)
{
    deque[end++] = num;
}

int pop_front()
{
    if (end - start == 0)
        return -1;

    int tmp;
    tmp = deque[start++];

    return tmp;
}

int pop_back()
{
    if (end - start == 0)
        return -1;

    int tmp;
    tmp = deque[end - 1];
    end--;

    return tmp;
}

int size()
{
    return end - start;
}

int empty()
{
    if (end - start)
        return 0;
    return 1;
}

int front()
{
    if (end - start)
        return deque[start];
    return -1;
}

int back()
{
    if (end - start)
        return deque[end - 1];
    return -1;
}

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        char order[11] = {0};
        int num;

        scanf("%s", order);

        if (strcmp(order, "push_front") == 0)
        {
            scanf("%d", &num);
            push_front(num);
        }
        else if (strcmp(order, "push_back") == 0)
        {
            scanf("%d", &num);
            push_back(num);
        }
        else
        {
            if (strcmp(order, "pop_front") == 0)
                printf("%d\n", pop_front());
            else if (strcmp(order, "pop_back") == 0)
                printf("%d\n", pop_back());
            else if (strcmp(order, "size") == 0)
                printf("%d\n", size());
            else if (strcmp(order, "empty") == 0)
                printf("%d\n", empty());
            else if (strcmp(order, "front") == 0)
                printf("%d\n", front());
            else if (strcmp(order, "back") == 0)
                printf("%d\n", back());
        }
    }
    return 0;
}