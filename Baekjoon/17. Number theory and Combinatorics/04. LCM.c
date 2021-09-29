/**
 * @file 04. LCM.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-21 18:20:12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int GCF(int x, int y)
{
    while (x > 0) // ��Ʋ���� ȣ������ �̿��Ͽ� �ִ������� ���ϴ� �Լ�
    {
        int remain;
        remain = y % x;
        y = x;
        x = remain;
    }

    return y;
}

int LCM(int x, int y) // �ִ��������� ���踦 �̿��Ͽ� �ּҰ������ ���ϴ� �Լ�
{
    int gcf;
    gcf = GCF(x, y);

    return (x * y) / gcf;
}

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test;
         i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) // x�� y���� ũ�� x�� y�� �ٲ۴�
        {
            int tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
        printf("%d\n", LCM(x, y));
    }
}