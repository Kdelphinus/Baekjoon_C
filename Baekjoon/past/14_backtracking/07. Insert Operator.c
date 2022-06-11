#include <stdio.h>

int num, sum, min = 1000000000, max = -1000000000;
int number[101]; // ���ڸ� ������ �迭
int operator[4]; // �������� ������ ������ �迭

int DFS(int l)
{
    if (l == num - 1) // ������ ������ �� �ߴٸ�
    {
        if (min > sum) // �ּڰ�
            min = sum;
        if (max < sum) // �ִ�
            max = sum;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (l == 0) // ���� ������ŭ�� ���
                sum = number[l];
            if (operator[i]> 0) // �����ڰ� ���� ����������
            {
                int tmp = sum; // ������ �����ϰ�
                if (i == 0)    // +
                    sum += number[l + 1];
                else if (i == 1) // -
                    sum -= number[l + 1];
                else if (i == 2) // *
                    sum *= number[l + 1];
                else // /
                    sum /= number[l + 1];
                operator[i]--; // ����� �������� ������ ����
                DFS(l + 1);    // ���� ��ġ �����ڷ� �̵�
                operator[i]++; // ���ƿ� ������ �߰�
                sum = tmp;     // ���� �� ��������� ����
            }
        }
    }
}

int main()
{
    scanf("%d", &num); // ������ ����

    for (int i = 0; i < num; i++) // ���ڸ� ����
        scanf("%d", &number[i]);

    for (int i = 0; i < 4; i++) // �������� �������� ����
        scanf("%d", &operator[i]);

    DFS(0);

    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}