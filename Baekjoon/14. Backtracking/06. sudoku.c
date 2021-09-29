#include <stdio.h>
#include <stdlib.h>

typedef struct // 빈 칸의 좌표를 저장할 구조체
{
    int x, y;
} zeros;

zeros zero[81];

int sudoku[9][9]; // 스도쿠를 받을 배열
int flag;         // 답을 출력했는지 확인할 변수

void sudoku_solution(int index, int zero_cnt) // 채울 칸의 인덱스, 빈 칸의 수
{
    if (flag) // 이미 답을 출력했다면 다른 것을 진행하지 않고 함수 종료
        return;
    else if (index == zero_cnt) // 모든 빈 칸을 채웠을 때
    {
        for (int a = 0; a < 9; a++)
        {
            for (int b = 0; b < 9; b++)
                printf("%d ", sudoku[a][b]);
            printf("\n");
        }
        flag++; // 이미 출력했음을 알려주기 위해
    }
    else
    {
        int i, j, si, sj;
        int possible[10] = {
            0,
        };

        i = zero[index].x; // 빈 칸의 x좌표
        j = zero[index].y; // 빈 칸의 y좌표

        for (int k = 0; k < 9; k++)
        {
            if (possible[sudoku[i][k]] == 0) // 가로 확인
                possible[sudoku[i][k]]++;

            if (possible[sudoku[k][j]] == 0) // 세로 확인
                possible[sudoku[k][j]]++;
        }

        si = i / 3 * 3; // 박스 가로 시작 인덱스
        sj = j / 3 * 3; // 박스 세로 시작 인덱스

        for (int p = si; p < si + 3; p++)
        {
            for (int q = sj; q < sj + 3; q++)
            {
                if (possible[sudoku[p][q]] == 0) // 박스 안 확인
                    possible[sudoku[p][q]]++;
            }
        }

        for (int k = 1; k < 10; k++)
        {
            if (possible[k] == 0) // 들어갈 수 있는 수일 때
            {
                sudoku[i][j] = k;                     // 수를 넣고
                sudoku_solution(index + 1, zero_cnt); // 다음 칸으로 이동
                sudoku[i][j] = 0;                     // 더 이상 넣을 것이 없으면 다른 수를 넣음
            }
        }
    }
}

int main()
{
    int zero_cnt = 0; // 빈 칸의 개수를 저장할 변수

    // zeros *zero = (zeros *)malloc(sizeof(zeros) * 81); // 빈 칸의 좌표를 저장할 구조체
    for (int i = 0; i < 9; i++)
    { // 현재 스도쿠를 받고 빈 칸의 개수를 세고 빈 칸의 좌표를 구조체에 저장
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] == 0)
            {
                zero[zero_cnt].x = i;
                zero[zero_cnt].y = j;
                zero_cnt++;
            }
        }
    }

    sudoku_solution(0, zero_cnt); // 빈 칸의 좌표가 들어간 구조체, 채울 칸의 인덱스, 빈 칸의 개수

    return 0;
}

/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/