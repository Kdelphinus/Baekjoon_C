#include <stdio.h>

int main()
{
    int up, down, len; //snail: 달팽이
    scanf("%d %d %d", &up, &down, &len);

    // len <= up + (up - down) * day
    if ((len - up) % (up - down) == 0)
        printf("%d", (len - up) / (up - down) + 1);
    else // 나머지를 버리기에 보정
        printf("%d", (len - up) / (up - down) + 2);

    return 0;
}