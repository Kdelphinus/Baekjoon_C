/**
 * @file practice.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ������ ��ó: https://wtg-study.tistory.com/53
 * @date 2021-06-28 22:45:49
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#define SIZE 1000000
int arr[SIZE];
int stack[SIZE];
char result[SIZE * 2];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int num = 1, top = -1;
    int idx = 0, result_idx = 0;
    while (1)
    {
        if (top == -1 || stack[top] < arr[idx]) // ���ÿ� �ִ� ���� ��ǥ������ ���� ���
        {
            stack[++top] = num++;       // ���ÿ� ���ڸ� ����ְ�
            result[result_idx++] = '+'; // push �α�
        }
        else if (stack[top] == arr[idx]) // ���ÿ� �ִ� ���� ��ǥ���� ���
        {
            top--;                      // ���ÿ� �ִ� ���� ����(�ε����� �ű� �� ���߿� ����� ������)
            result[result_idx++] = '-'; // pop �α�
            idx++;                      // ��ǥ���� ���� �迭�� �ε��� �̵�
        }
        else // ������ ������ ���� ��ǥ������ ũ�� ���ϴ� ������ ���� �� ����
        {
            printf("NO\n"); // �Ұ����� ����ϰ�
            return 0;       // main�Լ��� ����
        }

        if (result_idx == 2 * n)
            break;
    }

    for (int i = 0; i < result_idx; i++)
        printf("%c\n", result[i]);

    return 0;
}