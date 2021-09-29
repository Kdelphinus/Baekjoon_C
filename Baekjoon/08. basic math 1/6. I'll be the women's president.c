#include <stdio.h>

int solution(int floor, int room_num)
{
    if (floor == 0)
        return room_num;
    else if (room_num == 1)
        return 1;

    return solution(floor - 1, room_num) + solution(floor, room_num - 1);
}

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int k, n, anw;
        scanf("%d\n%d", &k, &n);

        anw = solution(k, n);
        printf("%d\n", anw);
    }
    return 0;
}