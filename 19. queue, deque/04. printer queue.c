/**
 * @file 04. printer queue.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief �迭 ������ ����ó���� �ǳ� ���� �������� ã�� ����
 * @date 2021-07-02 23:26:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int importance[100000001][2]; // [�߿䵵, �ε���]�� ������ �迭
int tmp_arr[101];             // �߿䵵�� �����Ͽ� ���������� �迭(���� ���� ������ �߿䵵�� �� �տ� �ִ�)

int compare(const void *a, const void *b) // ������ ���� �Լ�
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return 1;
    if (num2 < num1)
        return -1;
    return 0;
}

int printer(int num, int order)
{
    int start = 0, end = 0, tmp_idx = 0; // ���� �ε���, �� �ε���, ���������� �迭�� �ε���
    int check = 0;                       // ������ ���°�� �̾Ҵ��� ������ ����
    end = num;                           // �ʱ� �� �ε����� ������ ������ ����

    while (1)
    {
        if ((tmp_arr[tmp_idx] == importance[start][0]) && (order == importance[start][1])) // ���� �̾ƾ� �ϰ� �˰� ���� �������
            return check + 1;                                                              // ���� �̴� ������ �����Ͽ� ����

        if (tmp_arr[tmp_idx] == importance[start][0]) // ���� �̾ƾ� �� �������� �˰� ���� ������ �ƴ϶��
        {
            check++;   // ���� Ƚ�� �߰�
            tmp_idx++; // ���� �߿䵵 ������ �̵�
            start++;   // �� �� ������ �̾ƹ���
        }
        else // ������ ���� ���� �ƴϸ�
        {
            // ������ �� �ڷ� �ű��
            importance[end][0] = importance[start][0];
            importance[end][1] = importance[start][1];
            start++;
            end++;
        }
    }
}

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int num, order;
        scanf("%d %d", &num, &order);

        for (int j = 0; j < num; j++)
        {
            // ������ �߿䵵�� �ε��� ����
            scanf("%d", &importance[j][0]);
            importance[j][1] = j;

            // ������ �߿䵵�� ����
            tmp_arr[j] = importance[j][0];
        }

        // ������ �߿䵵�� ������ �迭�� ��������
        qsort(tmp_arr, sizeof(tmp_arr) / sizeof(int), sizeof(int), compare);

        printf("%d\n", printer(num, order));
    }

    return 0;
}