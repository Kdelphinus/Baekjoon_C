#include <stdio.h>

int num, count;
int result[9];
int checklist[9];

void DFS(int L)
{
    if (L == count) // ������ �� ä���� ��
    {
        for (int i = 0; i < count; i++)
            printf("%d ", result[i]);
        printf("\n");
    }

    else
    {
        for (int i = 1; i <= num; i++) // 1���� num����
        {
            if (checklist[i] == 0) // ���� ���� ���� ������ ��
            {
                if (L == 0) // ù ��° ���ڸ� �߰�
                {
                    result[L] = i;
                    DFS(L + 1);
                }
                else if (result[L - 1] <= i) // �� ��° ���ں��� ���� ���ں��� ���ų� Ŭ���� �߰�
                {
                    result[L] = i;
                    DFS(L + 1);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &num, &count);
    DFS(0);
    return 0;
}