#include <stdio.h>

int main()
{

    int n, value, num, count = 0;
    scanf("%d", &n);
    value = n;

    while (1)
    {
        // �� �ڸ��� ���ڸ� ���� ��
        num = n / 10 + n % 10;

        // num�� �� �ڸ� ���̸� ���� �ڸ��� ��������
        if (num >= 10)
        {
            num %= 10;
        }

        // ���ο� ���� ����
        n = ((n % 10) * 10) + num;

        // Ƚ���� ����
        count++;

        // ó�� ���� ��ġ�ϸ� Ƚ���� ����ϰ� ����
        if (value == n)
        {
            printf("%d", count);
            break;
        }
    }

    return 0;
}