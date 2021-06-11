#include <stdio.h>

int num, count;
int result[1000];
int checklist[1000];

void DFS(int L)
{
    int i;

    if (L == count) // ���ϰ��� �ϴ� ���̿� ���� ��
    {
        for (i = 0; i < count; i++)
            printf("%d ", result[i]);
        printf("\n");
    }
    else
    {
        for (i = 1; i <= num; i++) // 1���� num���� ������ ����
        {
            if (checklist[i] == 0) // ���� ���ڰ� ���� �ʾҴٸ�
            {
                result[L] = i;    // ����� �� ���ڸ� �߰��ϰ�
                checklist[i] = 1; // ���ڰ� ���ٰ� ǥ��
                DFS(L + 1);       // ���� ���ڸ� ã�ƺ�
                checklist[i] = 0; // ã�� ���ƿ��� �� ���ڸ� ����
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &num, &count);
    DFS(0);
}
