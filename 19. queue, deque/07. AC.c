/**
 * @file 07. AC.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-03 21:52:53
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

int start, end; // �־��� ���� �迭�� ���۰� �� �ε���

void D(int flag, char orders[], char numbers[]) // ���� ���� ���ڸ� �����ϴ� �Լ�
{
    if (flag) // ������ ������ ��
    {
        end -= 2;               // �ڿ� ���� �����Ѵ�(']'�� ����)
        numbers[end - 1] = ']'; // ','�� ']'�� �ٲ۴�
    }
    else // ������ ���°� �ƴ� ��
    {
        start += 2;           // �տ� ���� �����Ѵ�('['�� ����)
        numbers[start] = '['; // ','�� '['�� �ٲ۴�
    }
}

void AC(int n, char orders[], char numbers[])
{
    int size, flag = 0; // ����� ����, ������ ����(1�� ������ ����)

    size = strlen(orders); // ����� ����
    start = 0;             // �迭�� ���� �ε���
    end = strlen(numbers); // �迭�� �� �ε���

    for (int i = 0; i < size; i++)
    {
        if (orders[i] == 'R') // ����� �������̸�
        {
            if (flag)
                flag = 0;
            else
                flag = 1;
        }
        else
        {
            if (end - start < 3) // ���̰� 4���� ������ ���ڰ� �� �� ����
            {
                printf("error\n");
                return;
            }
            D(flag, orders, numbers);
        }
    }

    if (flag)
    {
        printf("[");
        for (int i = end - 2; i > start; i--)
            printf("%c", numbers[i]);
        printf("]");
    }
    else
    {
        for (int i = start; i < end; i++)
            printf("%c", numbers[i]);
    }
    printf("\n");
}

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int n;
        char numbers[300000] = {0};
        char orders[100001] = {0};
        scanf("%s", orders);
        scanf("%d", &n);
        scanf("%s", numbers);

        AC(n, orders, numbers);
    }
    return 0;
}