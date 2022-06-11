/**
 * @file 02. card 2.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-01 23:44:07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int queue[1000001]; // ť, ������ġ�� �ű�� ����̱⿡ �ִ� ũ���� �ι谡 �ʿ���
int tmp_index;      // ���� ��ġ

void pop()
{
    tmp_index++; // ���� ��ġ�� �Ű� �� ���� ���� ����
}

void back(int index)
{
    queue[index] = queue[tmp_index]; // �� ���� ���� �� �ڷ� �ű��
    tmp_index++;                     // ���� ��ġ�� �Ű� �� ���� ���� ����
}

int card(int num)
{
    int flag = 0, index;
    index = num;                  // �迭 ��
    for (int i = 0; i < num; i++) // ���� �ֱ�
        queue[i] = i + 1;

    while (index - tmp_index > 1) // �迭�� �ϳ��� ���� ������ �ݺ�
    {
        if (flag) // flag�� 1�̸� �� ���� ī�带 �� �ڷ� �ű��
        {
            back(index);
            flag = 0; // ������ ī�带 ����� ����
            index++;  // �� �ڿ� ī�� �� �� �߰�
        }
        else // flag�� 0�̸� �� ���� ī�带 ����
        {
            pop();
            flag = 1; // ������ ī�带 �ڷ� �ű��� ����
        }
    }

    return queue[tmp_index]; // ���� ��ġ�� ī�尡 ���� ī��
}

int main()
{
    int num;
    scanf("%d", &num);

    printf("%d", card(num));

    return 0;
}