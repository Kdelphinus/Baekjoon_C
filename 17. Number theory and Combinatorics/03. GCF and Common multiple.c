/**
 * @file 03. GCF and Common multiple.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ��Ŭ���� ȣ������ �ּ� ������� �ִ� ����� ������ ���踦 �̿�
 * @date 2021-06-21 16:13:36
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int GCF(int a, int b) // �ִ������� ���ϴ� �Լ�
{
    if (a == b)
        return a;

    int a_tmp, b_tmp;
    a_tmp = a;
    b_tmp = b;

    while (a_tmp > 0) // ��Ŭ���� ȣ���� �̿�
    {
        int remain;
        remain = b_tmp % a_tmp;
        b_tmp = a_tmp;
        a_tmp = remain;
    }

    return b_tmp;
}

int common_multiple(int a, int b) // �ּ� ������� ���ϴ� �Լ�
{
    if (a == b)
        return a;

    int min, tmp;
    min = GCF(a, b);
    tmp = a * b;
    if (tmp < 0)
        tmp *= -1;

    return tmp / min; // �ּ� ������� �ִ� ����� ���� ���踦 �̿�
}

int main()
{
    int num1, num2, min;
    scanf("%d %d", &num1, &num2);
    if (num2 < num1)
    {
        int temp;
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printf("%d\n", GCF(num1, num2));
    printf("%d", common_multiple(num1, num2));

    return 0;
}