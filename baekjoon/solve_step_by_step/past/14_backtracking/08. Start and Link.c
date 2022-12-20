#include <stdio.h>

int num, mid, start, link, diff = 1000000, temp;
int stat[20][20];
int team[20];
int result[20];
int checklist[20];

void DFS(int l)
{
    if (l == num / 2)
    {
        mid = num / 2; // ���� �� ���� ����
        for (int i = 0; i < num; i++)
        {
            for (int j = i; j < num; j++)
            {
                if (checklist[i] == 1 && checklist[j] == 1) // start team
                {
                    start += stat[i][j]; // i�� j�� ������ ����
                    start += stat[j][i]; // j�� i�� ������ ����
                }
                else if (checklist[i] == 0 && checklist[j] == 0) // link team
                {
                    link += stat[i][j]; // i�� j�� ������ ����
                    link += stat[j][i]; // j�� i�� ������ ����
                }
            }
        }

        temp = link - start; // ���� ���
        if (temp < 0)        // ���̰� ������ ����� ��ȯ
            temp *= -1;

        if (diff > temp) // ���̰� �� ������ ���� ����
            diff = temp;

        start = 0;
        link = 0;
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            if (checklist[i] == 0)
            {
                if (l == 0) // ù ���� ��
                {
                    checklist[i] = 1;
                    result[l] = i;
                    DFS(l + 1);
                    checklist[i] = 0;
                }
                else if (result[l - 1] <= i) // �ߺ��� ����
                {
                    checklist[i] = 1;
                    result[l] = i;
                    DFS(l + 1);
                    checklist[i] = 0;
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            scanf("%d", &stat[i][j]);
    }

    DFS(0);
    printf("%d", diff);

    return 0;
}