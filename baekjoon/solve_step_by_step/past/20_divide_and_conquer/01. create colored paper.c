#include <stdio.h>

int num, blue, white; // 첫 종이의 크기, 파랑 종이의 수, 하얀 종이의 수
int paper[128][128];  // 종이의 상태

void divide(int n, int x, int y)
{
    if (n == 1) // 종이 크기가 1 x 1이라면
    {
        if (paper[y][x] == 1) // 파랑일 때
            blue++;
        else // 하양일 때
            white++;

        return;
    }

    int flag = 0; // 종이가 같은 색으로만 이루어져 있는지 확인하는 변수
    for (int i = y; i < y + n; i++)
    {
        if (flag) // 색이 다른 칸이 있을 때
            break;
        for (int j = x; j < x + n; j++)
        {
            if (paper[y][x] != paper[i][j]) // 색이 다른 칸이 있을 때
            {
                flag = 1; // 색이 다른 것이 있다고 표시
                break;
            }
        }
    }

    if (flag) // 다른 색 칸도 존재하면
    {
        // 종이를 4분할하여 탐색
        n /= 2;
        divide(n, x, y);
        divide(n, x, y + n);
        divide(n, x + n, y);
        divide(n, x + n, y + n);
    }
    else // 같은 색만 있다면
    {
        if (paper[y][x] == 1) // 파랑일 경우
            blue++;
        else // 하양일 경우
            white++;
    }
}

int main()
{
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            scanf("%d", &paper[i][j]);
    }

    divide(num, 0, 0);
    printf("%d\n%d", white, blue);

    return 0;
}