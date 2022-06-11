/**
 * @file 06. Ring.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-23 02:09:23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int gcd(int a, int b) // �ִ������� ���ϴ� �Լ�
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void ring_rotates(int num, int rings[])
{
    int standard, tmp;
    standard = rings[0]; // ������ �Ǵ� ��

    for (int i = 1; i < num; i++)
    {
        tmp = gcd(standard, rings[i]);                     // ���� ���� ������ �Ǵ� ���� �ִ�����
        printf("%d/%d\n", standard / tmp, rings[i] / tmp); // ���� �ִ������� ������ ����� �м����°� �ȴ�
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    int rings[num];
    for (int i = 0; i < num; i++)
        scanf("%d", &rings[i]);

    ring_rotates(num, rings);

    return 0;
}