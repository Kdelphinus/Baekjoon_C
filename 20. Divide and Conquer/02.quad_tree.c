/**
 * @file 02.quad_tree.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-12 23:30:29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

char video[65][65];

void compression(int num, int x, int y) // ������ ���� ũ��, ���� ��ǥ(���� ��)
{
    if (num == 1) // ũ�Ⱑ 1�̸� �ٷ� ����
    {
        printf("%c", video[y][x]);
        return;
    }

    int flag = 0; // �ٸ� ���ڰ� �ִ��� Ȯ���ϴ� ����
    for (int i = y; i < y + num; i++)
    {
        if (flag)  // ���� �ٸ� ���ڰ� �ִٸ�
            break; // �ٷ� ����
        for (int j = x; j < x + num; j++)
        {
            if (video[y][x] != video[i][j]) // ���ڰ� ������ǥ�� �ٸ��ٸ�
            {
                flag = 1; // �ٸ� ���ڰ� ������ ǥ���ϰ�
                break;    // ����
            }
        }
    }

    if (flag) // �ٸ� ���ڰ� �ִٸ�
    {
        printf("("); // ��ȣ ����
        num /= 2;
        compression(num, x, y);             // ���� ��
        compression(num, x + num, y);       // ������ ��
        compression(num, x, y + num);       // ���� �Ʒ�
        compression(num, x + num, y + num); // ������ �Ʒ�
        printf(")");                        // ��ȣ �ݰ�
    }
    else                           // �ٸ� ���ڰ� ���ٸ�
        printf("%c", video[y][x]); // ����
}

int main()
{
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
        scanf("%s", &video[i]);

    if (num == 1) // ũ�Ⱑ �� ĭ�̸� ��ȣ�� ���� ����� ��
        printf("(%c)", video[0][0]);
    else // �� ĭ�� �ƴ϶�� ��ȣ�� ������ �ʾƵ� ��
        compression(num, 0, 0);

    return 0;
}