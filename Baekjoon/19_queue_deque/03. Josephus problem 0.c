/**
 * @file 03. Josephus problem 0.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-02 19:46:14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int solution[1001];
int num[1000001];    // 1000���� ���� 1000�� �ڷ� ������ �ͱ��� �Ǿ� ��
int start, end, idx; // ť�� ���� �ε���, �� �ε���, solution �ε���

int pop()
{
    int tmp;
    tmp = num[start++]; // �� ���� ���� tmp�� �����ϰ� start�� 1�� ����

    return tmp;
}

void back()
{
    num[end++] = num[start++]; //�� ���� ���ڸ� �� �ڷ� �ű�� start�� end�� 1�� ����
}

void josephus(int n, int k)
{
    // �ʱ� ����
    end = n;
    for (int i = 0; i < n; i++)
        num[i] = i + 1;

    while (idx < n) // solution�� �� �� ������
    {
        int tmp;
        for (int i = 0; i < k - 1; i++) // k - 1������ ���ڸ� �ڷ� �ѱ��
            back();

        solution[idx++] = pop(); // k��° ���ڸ� ���� solution�� �ִ´�
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    josephus(n, k);

    printf("<");
    for (int i = 0; i < idx; i++)
    {
        if (i == idx - 1)
            printf("%d>", solution[i]);
        else
            printf("%d, ", solution[i]);
    }

    return 0;
}