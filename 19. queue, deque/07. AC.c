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
        if (numbers[end - 3] == ',') // �� �ڸ� ������ ��
        {
            end -= 2;               // �ڿ� ���� �����Ѵ�(']'�� ����)
            numbers[end - 1] = ']'; // ','�� ']'�� �ٲ۴�
        }
        else if (numbers[end - 4] == ',') // �� �ڸ� ������ ��
        {
            end -= 3;               // �ڿ� ���� �����Ѵ�(']'�� ����)
            numbers[end - 1] = ']'; // ','�� ']'�� �ٲ۴�
        }
        else if (numbers[end - 5] == ',') // �� �ڸ� ������ ��
        {
            end -= 4;               // �ڿ� ���� �����Ѵ�(']'�� ����)
            numbers[end - 1] = ']'; // ','�� ']'�� �ٲ۴�
        }
    }
    else // ������ ���°� �ƴ� ��
    {
        if (numbers[start + 2] == ',') // �� �ڸ� ������ ��
        {
            start += 2;           // �տ� ���� �����Ѵ�('['�� ����)
            numbers[start] = '['; // ','�� '['�� �ٲ۴�
        }
        else if (numbers[start + 3] == ',') // �� �ڸ� ������ ��
        {
            start += 3;           // �տ� ���� �����Ѵ�('['�� ����)
            numbers[start] = '['; // ','�� '['�� �ٲ۴�
        }
        else if (numbers[start + 4] == ',') // �� �ڸ� ������ ��
        {
            start += 4;           // �տ� ���� �����Ѵ�('['�� ����)
            numbers[start] = '['; // ','�� '['�� �ٲ۴�
        }
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
            if (n == 0) // ���ڰ� ���µ� ���ڸ� ������ �ϸ� ����
            {
                printf("error\n");
                return;
            }
            D(flag, orders, numbers);
            n--;
        }
    }

    if (flag) // �Ųٷ� ����ؾ� �� ��
    {
        int i = end - 2;  // ��ȣ�� ������� �ʰ� �ٷ� ���ڷ� �ε��� �̵�
        printf("[");      // ���� ��ȣ ���� ���
        while (i > start) // ��ȣ�� ������ ��������
        {
            if (numbers[i] == ',') // ��ǥ�� �ٷ� ���
            {
                printf("%c", numbers[i]);
                i--;
            }
            else // ������ ��(���ȣ�� ������ ���ڸ� ���Ͽ� ���� �߰�)
            {
                if (numbers[i - 1] == ',' || numbers[i - 1] == '[') // �� �ڸ��� ��
                {
                    printf("%c", numbers[i]);
                    i--;
                }
                else if (numbers[i - 2] == ',' || numbers[i - 2] == '[') // �� �ڸ��� ��
                {
                    printf("%c%c", numbers[i - 1], numbers[i]);
                    i -= 2;
                }
                else if (numbers[i - 3] == ',' || numbers[i - 3] == '[') // �� �ڸ� �϶�
                {
                    printf("%c%c%C", numbers[i - 2], numbers[i - 1], numbers[i]);
                    i -= 3;
                }
            }
        }
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
        char numbers[100000000] = {0};
        char orders[100000000] = {0};
        scanf("%s", orders);
        scanf("%d", &n);
        scanf("%s", numbers);

        AC(n, orders, numbers);
    }
    return 0;
}