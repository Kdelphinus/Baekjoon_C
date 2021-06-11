#include <stdio.h>
#include <math.h>
#define size 1000000

int start[size];
int end[size];

int hanoi(int num, int start, int end) // 원판 개수, 시작 위치, 도착위치
{
    int other = 6 - start - end; // 나머지 위치

    if (num == 1) // 원판이 하나이면 출발지점에서 도착지점으로 이동하고 종료
    {
        printf("%d %d\n", start, end);
        return 0;
    }

    hanoi(num - 1, start, other);  // 가장 큰 원판이 종료 지점에 가려면 나머지 원판은 모두 다른 위치로 이동해야 한다
    printf("%d %d\n", start, end); // 가장 큰 원판 이동
    hanoi(num - 1, other, end);    // 나머지 원판도 도착위치로 이동
    return 0;
}

int main()
{

    int num, cnt;
    scanf("%d", &num);

    cnt = pow(2, num) - 1;
    printf("%d\n", cnt);
    hanoi(num, 1, 3);

    return 0;
}