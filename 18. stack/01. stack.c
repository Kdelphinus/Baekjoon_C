/**
 * @file 01. stack.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ���̸� ���ϱ� ���� len�� ���� ����
 * @date 2021-06-24 15:03:03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

int len, arr[10001];

void push(int num) // �迭�� ���ڸ� �ִ� �Լ�
{
    arr[len++] = num;
}

int pop() // �� ��(�� ��)�� �ִ� ���� ���� ����ϴ� �Լ�
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

int size() // �迭�� �� ������ ������ ����ϴ� �Լ�
{
    return len;
}

int empty() // ����ִ��� Ȯ���ϴ� �Լ�
{
    if (len)
        return 0;
    return 1;
}

int top() // ���� ���� �ִ� ���� ����ϴ� �Լ�
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