#include <stdio.h>
#include <math.h>

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int start, end, len, cnt = 0, num, limit;
        scanf("%d %d", &start, &end);

        // ������ �Ÿ�
        len = end - start;

        // 4���� ������ 1���� �̵�����
        if (len < 4)
            printf("%d\n", len);

        /* len�� (num + 1) * (num + 1)�̸��̸� �� ���� �ִ� num������ �̵� ���� */
        /* ���� �� ���� 1,2...num-1���� ���ѵ� */
        else
        {
            num = (int)sqrt(len);
            limit = num * (num - 1);

            len -= limit;

            // ���ѵ� ������� �����ϴ� Ƚ�� + ���̿� �� �� �ִ� Ƚ��
            cnt = 2 * (num - 1) + len / num;

            if (len % num == 0)
                printf("%d\n", cnt);
            else // �������� ���� ��, �װ��� num���� �۱⿡ �� ���� �� �̵��ϸ� �ȴ�
                printf("%d\n", cnt + 1);
        }
    }
    return 0;
}