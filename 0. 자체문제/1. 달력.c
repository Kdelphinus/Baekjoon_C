// 1�� 1���� �������̶� ���� ��, ������ ���ϴ� ���α׷�

#include <stdio.h>

int main()
{
    char day[] = "�Ͽ�ȭ�������"; // "�Ͽ�ȭ�������"; "SMTWtFs";
    char *day_ptr;

    day_ptr = &day[0];

    int m, d, i, days, value;
    scanf("%d %d", &m, &d);

    days = 0; // �� �ϼ�
    days += d;

    for (i = 0; i < m; i++)
    {
        if (m != 1)
        {
            if (m == 2)
            {
                days += 28;
            }
            else if ((m % 2 == 0 && m < 7) || (m % 2 == 1 && m > 7))
            {
                days += 30;
            }
            else if ((m % 2 == 0 && m > 7) || (m % 2 == 1 && m < 7))
            {
                days += 31;
            }
        }
        m -= 1;
    }
    value = days % 7;

    printf("%c", *day_ptr + value);
    //printf("%c", *day_ptr);

    return 0;
}