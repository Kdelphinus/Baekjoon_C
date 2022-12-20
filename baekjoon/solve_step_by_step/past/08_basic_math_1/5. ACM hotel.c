#include <stdio.h>

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int height, width, num, room_num, room_floor;
        scanf("%d %d %d", &height, &width, &num);

        room_num = num / height + 1;
        room_floor = num % height;

        if (room_floor == 0) //최상층은 높이의 배수들이기에 보정
            printf("%d%02d\n", room_floor + height, room_num - 1);
        else
            printf("%d%02d\n", room_floor, room_num);
    }
    return 0;
}