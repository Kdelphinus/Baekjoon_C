#include <stdio.h>
#include <string.h>

char bracket[51];

char pop() // �� �ڿ� �ִ� ��ȣ�� ���� �����ϴ� �Լ�
{
    int len;
    char tmp;
    len = strlen(bracket);
    tmp = bracket[len - 1];
    bracket[len - 1] = '\0';

    return tmp;
}

void reset() // �迭�� �ʱ�ȭ�ϴ� �Լ�
{
    int len;
    len = strlen(bracket);

    for (int i = 0; i < len; i++)
        bracket[i] = '\0';
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int size, flag = 0;
        scanf("%s", bracket);
        size = strlen(bracket); // ���̸�ŭ�� ���ֱ� ���Ͽ�
        for (int j = 0; j < size; j++)
        {
            char tmp;
            tmp = pop();

            if (tmp == ')') // ���� ���� �ݴ� ��ȣ�� +1
                flag++;
            else // ���� ���� ���� ��ȣ�� -1
                flag--;

            if (flag < 0) // ���� ��ȣ�� ���� ������ ���� ���ϱ⿡ �ٷ� ����
                break;
        }

        if (flag) // 0�� �ƴϸ� ¦�� �ȸ´� ��
            printf("NO\n");
        else // 0�̿��� ¦�� �´´�
            printf("YES\n");

        reset(); // �迭 �ʱ�ȭ
    }
    return 0;
}