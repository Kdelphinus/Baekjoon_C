#include <stdio.h>
#include <math.h>   // floor �Լ�
#include <stdlib.h> // qsort �Լ�

int compare(const void *a, const void *b) // ���������� ���� �Լ�
{
    int num1 = *(int *)a; // void �����͸� int �����ͷ� ��ȯ�� ��, �� �����Ͽ� ���� ������
    int num2 = *(int *)b; // void �����͸� int �����ͷ� ��ȯ�� ��, �� �����Ͽ� ���� ������

    if (num1 < num2) // a < b�� �� -1 ��ȯ
        return -1;

    if (num1 > num2) // a > b�� �� 1 ��ȯ
        return 1;

    return 0; // a = b�� �� 0 ��ȯ
}

int main()
{
    int num, mean, median, mode_cnt = 0, mode, repeat = 0;
    int check[8001] = {
        0,
    };
    double sum = 0.0;

    // ���� �ް� �迭 ����
    scanf("%d", &num);

    int numbers[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // c�� ����� �� ����
    // ������ �迭, ��� ����(sizeof(numbers) / sizeof(int)), ��� ũ��, �� �Լ�
    qsort(numbers, num, sizeof(int), compare);

    // ��� ���
    for (int i = 0; i < num; i++)
    {
        sum += numbers[i];
    }
    mean = floor(sum / num + 0.5); // floor�� �����Լ�, 0.5�� ���Ͽ� ������ �ݿø��� ���� ����� ���´�
    printf("%d\n", mean);

    // �߾Ӱ�
    median = num / 2;
    printf("%d\n", numbers[median]);

    // �ֺ�
    for (int i = 0; i < num; i++)
    {
        check[4000 + numbers[i]] += 1; // -4000 ~ 4000�� 0 ~ 8000�� ������� �ֱ� ���Ͽ�
    }

    for (int i = 0; i < 8001; i++)
    {
        if (mode_cnt < check[i]) // �󵵼��� �� ū ���ڸ� ã���� ��
        {
            mode = i - 4000;
            mode_cnt = check[i];
            repeat = 1;
        }
        else if (mode_cnt == check[i] && repeat == 1) // �ִ񰪰� ���� ���� �� ã���� ��, �� ���� �� ��°�� ���� �Ȱ��� �����
        {
            mode = i - 4000;
            mode_cnt = check[i];
            repeat++;
        }
    }

    printf("%d\n", mode);

    // ����
    printf("%d\n", numbers[num - 1] - numbers[0]);

    return 0;
}