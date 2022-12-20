/**
 * @file 01. queue 2.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ���� ���ڸ� �ε����� ���� �����ϴ� �������� ����
 * @date 2021-07-01 21:57:56
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

int queue[2000001];
int idx, tmp_idx; // �����ؾ� �� �ε��� ��ġ, ���� ť ���� ��ġ

void push(int n)
{
    queue[idx] = n; // idx - tmp_idx(���� ť ���� ���� ����) + tmp_idx(ť ���� ��ġ)
    idx++;          // �ε��� �̵�
}

int pop()
{
    int tmp;

    if (idx - tmp_idx) // ť�� ���ڰ� ����ִٸ�
    {
        tmp = queue[tmp_idx]; // �� ���� ���ڸ� tmp�� �����ϰ�
        tmp_idx++;            // ���� ��ġ�� �� ĭ �ڷ� �̷��
        return tmp;
    }
    return -1;
}

int size()
{
    return idx - tmp_idx; // ���� ��ġ - ���� ��ġ = ����ִ� ���� ����
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
        return queue[tmp_idx]; // ���� ť�� ���� ��ġ
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