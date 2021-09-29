#include <stdio.h>

int N, cnt;             // N x N 체스판
int height[15];         // 세로
int left_diagonal[30];  // 왼쪽방향으로 내려가는 대각선
int right_diagonal[30]; // 오른쪽방향으로 내려가는 대각선

void N_Queen(int i)
{
    if (N == i) // 퀸을 끝까지 두었을 때
        cnt++;
    else
    {
        for (int j = 0; j < N; j++)
        {
            if (height[j] == 0 && left_diagonal[i + j] == 0 && right_diagonal[i - j + N - 1] == 0)
            { // 세로, 왼쪽 대각선, 오른쪽 대각선에 퀸이 없을 때

                // 둔 위치를 기준으로 세로, 왼쪽 대각선, 오른쪽 대각선의 위치를 표시
                height[j] = 1;
                left_diagonal[i + j] = 1;
                right_diagonal[i - j + N - 1] = 1;

                N_Queen(i + 1); // 다음 행으로 이동

                // 퀸을 되돌림
                height[j] = 0;
                left_diagonal[i + j] = 0;
                right_diagonal[i - j + N - 1] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d", &N); // 체스판의 크기를 받음
    N_Queen(0);      // 첫번째 행부터 시작
    printf("%d", cnt);
    return 0;
}