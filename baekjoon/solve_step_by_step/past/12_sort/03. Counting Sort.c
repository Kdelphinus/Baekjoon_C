#include <stdio.h>

int main()
{
    int num, temp;
    int numbers[10001] = {
        0,
    };

    scanf("%d", &num);

    for (int i = 0; i < num; i++) // ������ ������ �� �ε����� �����Ѵ�
    {
        scanf("%d", &temp);
        numbers[temp] += 1;
    }

    for (int i = 1; i < 10001; i++)
    {
        if (numbers[i] >= 1) // ���� �� ���ڰ� ������
        {
            for (int j = 0; j < numbers[i]; j++) // �� ���ڸ�ŭ ���
                printf("%d\n", i);
        }
    }

    return 0;
}