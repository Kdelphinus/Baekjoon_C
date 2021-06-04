#include <stdio.h>

int num, sum, min = 1000000000, max = -1000000000;
int number[101];   // ���ڸ� ������ �迭
int operator[101]; // �����ڸ� ������ �迭
int result[101];   // �������� ������ ������ �迭
int temp[4];       // �������� ������ ������ �迭
int check[4];      // ������ ���� �ߺ��� �����ϱ� ���� �迭

int DFS(int l)
{
    if (l == num - 1) // ������ ������ �� �ߴٸ�
    {
        sum = number[0]; // ù ���ڷ� ����
        for (int i = 1; i < num; i++)
        {
            if (result[i - 1] == 0) // +
                sum += number[i];
            else if (result[i - 1] == 1) // -
                sum -= number[i];
            else if (result[i - 1] == 2) // x
                sum *= number[i];
            else if (result[i - 1] == 3) // /
            {
                if (sum < 0)
                { // ������ ����� ���� ��, ������ ����� �ٲٰ� ���� ��, ���� ������ �ٲ�
                    sum = -sum;
                    sum /= number[i];
                    sum = -sum;
                }
                else
                    sum /= number[i];
            }
        }
        if (min > sum) // �ּڰ�
            min = sum;
        if (max < sum) // �ִ�
            max = sum;
    }
    else
    {
        for (int i = 0; i < num - 1; i++)
        {
            if (check[operator[i]] < temp[operator[i]]) // ���� ������ŭ�� ���
            {
                check[operator[i]]++;
                result[l] = operator[i];
                DFS(l + 1);
                check[operator[i]]--;
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
        scanf("%d", &temp[i]);

    int oper, j = 0;
    for (int i = 0; i < 4; i++) // +: 0, -: 1, *: 2, /: 3
    {
        oper = i;

        for (int k = 0; k < temp[i]; k++) // ������ ������ŭ �߰�
            operator[j++] = oper;
    }
    DFS(0);

    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}