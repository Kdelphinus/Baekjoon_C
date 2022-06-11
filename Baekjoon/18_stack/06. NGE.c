/**
 * @file 06. NGE.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief Ǯ�� ��ó: https://cocoon1787.tistory.com/347
 * @date 2021-07-01 21:28:12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int stack[1000001]; // ����
int anw[1000001];   // ��ū���� ���� �迭

void NGE(int n, int arr[])
{
    int idx = 0; // ���� �ε���

    for (int i = n - 1; i >= 0; i--) // �ڿ������� Ž�� ����
    {
        while (idx > 0 && stack[idx - 1] <= arr[i]) // ������ ���ų� ���� Ȯ���ϴ� ������ ���ÿ� �ִ� ���� ū ��찡 ���� ������ ������ ���� ���ش�
            stack[--idx] = 0;

        if (idx == 0)                // ������ ����ִٸ�
            anw[i] = -1;             // ��ū���� ���� ���̰�
        else                         // ���ÿ� ���� �ִٸ�
            anw[i] = stack[idx - 1]; // ���� ���� �ִ� ���� ��ū���̴�

        stack[idx++] = arr[i]; // ���� ���ڴ� ���ÿ� �߰��Ѵ�
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    NGE(n, arr);

    for (int i = 0; i < n; i++)
        printf("%d ", anw[i]);

    return 0;
}