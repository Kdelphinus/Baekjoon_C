#include <stdio.h>

int main()
{
    // 고정 비용, 한 대 만드는데 드는 비용, 한 대 판매 가격
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