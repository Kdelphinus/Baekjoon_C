#include <stdio.h>

int main()
{
    char num[101];
    int n, i, value;
    scanf("%d", &n);
    scanf("%s", &num);

    value = 0;

    for (i = 0; i < n; i++)
    {
        value += num[i] % 48; // �ƽ�Ű �ڵ��� '0'�� 48��
    }

    // ���� ����̳� �ƽ�Ű �ڵ带 ���� Ǯ �� ����
    // for (i = 0; i<n; i++)
    // {
    //     sum += num[i] - '0';
    // }
    // printf("%d", sum);

    printf("%d\n", value);

    return 0;
}