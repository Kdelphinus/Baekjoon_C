#include <stdio.h>

int main()
{
    int up, down, len; //snail: ������
    scanf("%d %d %d", &up, &down, &len);

    // len <= up + (up - down) * day
    if ((len - up) % (up - down) == 0)
        printf("%d", (len - up) / (up - down) + 1);
    else // �������� �����⿡ ����
        printf("%d", (len - up) / (up - down) + 2);

    return 0;
}