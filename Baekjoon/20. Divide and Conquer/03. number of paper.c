/**
 * @file 03. number of paper.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-21 23:01:21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int paper[2188][2188];
int minus_one, zero, plus_one;

void DnC(int n, int x, int y)
{
    int flag = 1;

    if (n == 1) // 종이 크기가 1칸이면 종이 개수 추가
    {
        if (paper[y][x] == 1)
            plus_one++;
        else if (paper[y][x] == 0)
            zero++;
        else
            minus_one++;

        return;
    }

    for (int i = y; i < n + y; i++)
    {
        if (flag == 0) // 다른 것이 있으면 반복문 종료
            break;
        for (int j = x; j < n + x; j++)
        {
            if (paper[y][x] != paper[i][j]) // 왼쪽상단과 나머지 범위를 비교해 다른 것이 있으면
            {
                flag = 0; // 다른 것이 있다고 표시하고
                break;    // 반복문 종료
            }
        }
    }

    if (flag) // 다른 것이 없었다면 종이 개수 추가
    {
        if (paper[y][x] == 1)
            plus_one++;
        else if (paper[y][x] == 0)
            zero++;
        else
            minus_one++;

        return;
    }
    else // 다른 것이 있다면
    {
        n /= 3;                       // 9분할
        DnC(n, x, y);                 // 왼쪽 상단
        DnC(n, x + n, y);             // 중앙 상단
        DnC(n, x + 2 * n, y);         // 오른쪽 상단
        DnC(n, x, y + n);             // 왼쪽 중단
        DnC(n, x + n, y + n);         // 중앙 중단
        DnC(n, x + 2 * n, y + n);     // 오른쪽 중단
        DnC(n, x, y + 2 * n);         // 왼쪽 하단
        DnC(n, x + n, y + 2 * n);     // 중앙 하단
        DnC(n, x + 2 * n, y + 2 * n); // 오른쪽 하단
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &paper[i][j]);
    }

    DnC(n, 0, 0);
    printf("%d\n%d\n%d", minus_one, zero, plus_one);

    return 0;
}