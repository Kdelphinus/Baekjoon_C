/**
 * @file 01. find a number.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief C���� ��ʹ� ����̻����� ȿ���� ���� �ʴ�
 * @date 2021-08-07 18:16:05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 > num2)
        return 1;

    if (num1 < num2)
        return -1;

    return 0;
}

int binary_search(int num, int n_arr[], int size)
{ // ���� Ž��
    // ã�� ����� �������� �������� ���� ã�� ���

    int start, mid, end;
    start = 0;
    end = size - 1;
    while (1)
    {
        mid = (start + end) / 2;

        if (n_arr[start] == num)
            return 1;
        if (n_arr[mid] == num)
            return 1;
        if (n_arr[end] == num)
            return 1;

        if (n_arr[mid] < num)
            start = mid + 1;
        else
            end = mid - 1;

        if (start >= end)
            return 0;
    }
}

int main()
{
    int n_num, m_num;
    scanf("%d", &n_num);

    int n[n_num];
    for (int i = 0; i < n_num; i++)
        scanf("%d", &n[i]);
    qsort(n, n_num, sizeof(int), compare); // ã�� ���� ������ �Ǿ��־�� �Ѵ�

    scanf("%d", &m_num);
    int m[m_num];
    for (int i = 0; i < m_num; i++)
        scanf("%d", &m[i]);

    for (int i = 0; i < m_num; i++)
        printf("%d\n", binary_search(m[i], n, n_num));

    return 0;
}