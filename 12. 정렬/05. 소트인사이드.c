#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    int num1 = *(char *)a;
    int num2 = *(char *)b;

    if (num1 < num2)
        return 1;

    if (num1 > num2)
        return -1;

    return 0;
}

int main()
{
    char num[11]; // ���� ���̰� �ִ� 10���̹Ƿ�
    int len;

    scanf("%s", num);
    len = strlen(num); // ���� ������ ����

    int number[len];
    for (int i = 0; i < len; i++) // ���� ����Ʈ�� ��ȯ
        number[i] = num[i] - '0';

    qsort(number, len, sizeof(int), compare); // �������� ����

    for (int i = 0; i < len; i++)
        printf("%d", number[i]);

    return 0;
}