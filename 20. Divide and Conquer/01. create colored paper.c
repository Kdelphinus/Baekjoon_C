#include <stdio.h>

int num, blue, white; // ù ������ ũ��, �Ķ� ������ ��, �Ͼ� ������ ��
int paper[128][128];  // ������ ����

void divide(int n, int x, int y)
{
    if (n == 1) // ���� ũ�Ⱑ 1 x 1�̶��
    {
        if (paper[y][x] == 1) // �Ķ��� ��
            blue++;
        else // �Ͼ��� ��
            white++;

        return;
    }

    int flag = 0; // ���̰� ���� �����θ� �̷���� �ִ��� Ȯ���ϴ� ����
    for (int i = y; i < y + n; i++)
    {
        if (flag) // ���� �ٸ� ĭ�� ���� ��
            break;
        for (int j = x; j < x + n; j++)
        {
            if (paper[y][x] != paper[i][j]) // ���� �ٸ� ĭ�� ���� ��
            {
                flag = 1; // ���� �ٸ� ���� �ִٰ� ǥ��
                break;
            }
        }
    }

    if (flag) // �ٸ� �� ĭ�� �����ϸ�
    {
        // ���̸� 4�����Ͽ� Ž��
        n /= 2;
        divide(n, x, y);
        divide(n, x, y + n);
        divide(n, x + n, y);
        divide(n, x + n, y + n);
    }
    else // ���� ���� �ִٸ�
    {
        if (paper[y][x] == 1) // �Ķ��� ���
            blue++;
        else // �Ͼ��� ���
            white++;
    }
}

int main()
{
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            scanf("%d", &paper[i][j]);
    }

    divide(num, 0, 0);
    printf("%d\n%d", white, blue);

    return 0;
}