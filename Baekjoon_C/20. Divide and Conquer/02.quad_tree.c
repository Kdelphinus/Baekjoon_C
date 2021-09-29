/**
 * @file 02.quad_tree.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-12 23:30:29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

char video[65][65];

void compression(int num, int x, int y) // 압축할 비디오 크기, 기준 좌표(왼쪽 위)
{
    if (num == 1) // 크기가 1이면 바로 압축
    {
        printf("%c", video[y][x]);
        return;
    }

    int flag = 0; // 다른 숫자가 있는지 확인하는 변수
    for (int i = y; i < y + num; i++)
    {
        if (flag)  // 만약 다른 숫자가 있다면
            break; // 바로 종료
        for (int j = x; j < x + num; j++)
        {
            if (video[y][x] != video[i][j]) // 숫자가 기준좌표와 다르다면
            {
                flag = 1; // 다른 숫자가 있음을 표시하고
                break;    // 종료
            }
        }
    }

    if (flag) // 다른 숫자가 있다면
    {
        printf("("); // 괄호 열고
        num /= 2;
        compression(num, x, y);             // 왼쪽 위
        compression(num, x + num, y);       // 오른쪽 위
        compression(num, x, y + num);       // 왼쪽 아래
        compression(num, x + num, y + num); // 오른쪽 아래
        printf(")");                        // 괄호 닫고
    }
    else                           // 다른 숫자가 없다면
        printf("%c", video[y][x]); // 압축
}

int main()
{
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
        scanf("%s", &video[i]);

    if (num == 1) // 크기가 한 칸이면 괄호를 직접 써줘야 함
        printf("(%c)", video[0][0]);
    else // 한 칸이 아니라면 괄호를 써주지 않아도 됨
        compression(num, 0, 0);

    return 0;
}