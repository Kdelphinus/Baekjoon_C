/**
 * @file 03. number of paper.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-21 23:01:21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int paper[2188][2188];
int minus_one, zero, plus_one;

void DnC(int n, int x, int y)
{
    int flag = 1;

    if (n == 1) // ���� ũ�Ⱑ 1ĭ�̸� ���� ���� �߰�
    {
        if (paper[y][x] == 1)
            plus_one++;
        else if (paper[y][x] == 0)
            zero++;
        else
            minus_one++;

        return;
    }

    for (int i = y; i < n + y; i++)
    {
        if (flag == 0) // �ٸ� ���� ������ �ݺ��� ����
            break;
        for (int j = x; j < n + x; j++)
        {
            if (paper[y][x] != paper[i][j]) // ���ʻ�ܰ� ������ ������ ���� �ٸ� ���� ������
            {
                flag = 0; // �ٸ� ���� �ִٰ� ǥ���ϰ�
                break;    // �ݺ��� ����
            }
        }
    }

    if (flag) // �ٸ� ���� �����ٸ� ���� ���� �߰�
    {
        if (paper[y][x] == 1)
            plus_one++;
        else if (paper[y][x] == 0)
            zero++;
        else
            minus_one++;

        return;
    }
    else // �ٸ� ���� �ִٸ�
    {
        n /= 3;                       // 9����
        DnC(n, x, y);                 // ���� ���
        DnC(n, x + n, y);             // �߾� ���
        DnC(n, x + 2 * n, y);         // ������ ���
        DnC(n, x, y + n);             // ���� �ߴ�
        DnC(n, x + n, y + n);         // �߾� �ߴ�
        DnC(n, x + 2 * n, y + n);     // ������ �ߴ�
        DnC(n, x, y + 2 * n);         // ���� �ϴ�
        DnC(n, x + n, y + 2 * n);     // �߾� �ϴ�
        DnC(n, x + 2 * n, y + 2 * n); // ������ �ϴ�
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &paper[i][j]);
    }

    DnC(n, 0, 0);
    printf("%d\n%d\n%d", minus_one, zero, plus_one);

    return 0;
}