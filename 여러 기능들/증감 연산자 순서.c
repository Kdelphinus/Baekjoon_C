#include <stdio.h>

int main()
{
    int num1 = 2;
    int num2 = 2;

    printf("%d %d\n", num1++, num2--); // 2 2: num1, num2�� ���� ���� ����� �� ���� ������ ����
    printf("%d %d\n", num1, num2);     // 3 1: ���� �����ڰ� ������ ���

    printf("\n");

    int num3 = 2;
    int num4 = 2;

    printf("%d %d\n", ++num3, --num4); // 3 1: ���� �����ڰ� ���� ������ �� num3, num4�� ���� ���
    printf("%d %d\n", num3, num4);     // 3 1: �հ� ���� ���� ��µ�

    return 0;
}