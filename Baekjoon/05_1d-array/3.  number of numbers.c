#include <stdio.h>

int main()
{
    int input, value, num = 1;

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &input);
        num *= input;
    }

    int num_list[10] = {
        0,
    };

    while (num > 0)
    {
        value = num % 10;
        num_list[value] += 1;
        num /= 10;
    }

    // �����͸� ���� �ʾƵ� �۵� �� ��
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", num_list[i]);
    }

    // ������ �̿� ��(�׷��� �����͸� �̿����� �ʴ� ���� �� ����)
    // int *num_list_ptr;

    // num_list_ptr = &num_list[0];

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d\n", *(num_list_ptr + i));
    // }

    return 0;
}