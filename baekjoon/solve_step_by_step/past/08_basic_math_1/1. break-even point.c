#include <stdio.h>

int main()
{
    // ���� ���, �� �� ����µ� ��� ���, �� �� �Ǹ� ����
    int fix, make, sell, num = -1;
    scanf("%d %d %d", &fix, &make, &sell);

    if (sell <= make)
        printf("%d", num);
    else
    {
        num = fix / (sell - make);
        printf("%d", num + 1);
    }

    return 0;
}