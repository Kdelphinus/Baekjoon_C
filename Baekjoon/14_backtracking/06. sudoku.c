#include <stdio.h>
#include <stdlib.h>

typedef struct // �� ĭ�� ��ǥ�� ������ ����ü
{
    int x, y;
} zeros;

zeros zero[81];

int sudoku[9][9]; // ������ ���� �迭
int flag;         // ���� ����ߴ��� Ȯ���� ����

void sudoku_solution(int index, int zero_cnt) // ä�� ĭ�� �ε���, �� ĭ�� ��
{
    if (flag) // �̹� ���� ����ߴٸ� �ٸ� ���� �������� �ʰ� �Լ� ����
        return;
    else if (index == zero_cnt) // ��� �� ĭ�� ä���� ��
    {
        for (int a = 0; a < 9; a++)
        {
            for (int b = 0; b < 9; b++)
                printf("%d ", sudoku[a][b]);
            printf("\n");
        }
        flag++; // �̹� ��������� �˷��ֱ� ����
    }
    else
    {
        int i, j, si, sj;
        int possible[10] = {
            0,
        };

        i = zero[index].x; // �� ĭ�� x��ǥ
        j = zero[index].y; // �� ĭ�� y��ǥ

        for (int k = 0; k < 9; k++)
        {
            if (possible[sudoku[i][k]] == 0) // ���� Ȯ��
                possible[sudoku[i][k]]++;

            if (possible[sudoku[k][j]] == 0) // ���� Ȯ��
                possible[sudoku[k][j]]++;
        }

        si = i / 3 * 3; // �ڽ� ���� ���� �ε���
        sj = j / 3 * 3; // �ڽ� ���� ���� �ε���

        for (int p = si; p < si + 3; p++)
        {
            for (int q = sj; q < sj + 3; q++)
            {
                if (possible[sudoku[p][q]] == 0) // �ڽ� �� Ȯ��
                    possible[sudoku[p][q]]++;
            }
        }

        for (int k = 1; k < 10; k++)
        {
            if (possible[k] == 0) // �� �� �ִ� ���� ��
            {
                sudoku[i][j] = k;                     // ���� �ְ�
                sudoku_solution(index + 1, zero_cnt); // ���� ĭ���� �̵�
                sudoku[i][j] = 0;                     // �� �̻� ���� ���� ������ �ٸ� ���� ����
            }
        }
    }
}

int main()
{
    int zero_cnt = 0; // �� ĭ�� ������ ������ ����

    // zeros *zero = (zeros *)malloc(sizeof(zeros) * 81); // �� ĭ�� ��ǥ�� ������ ����ü
    for (int i = 0; i < 9; i++)
    { // ���� ������ �ް� �� ĭ�� ������ ���� �� ĭ�� ��ǥ�� ����ü�� ����
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

    sudoku_solution(0, zero_cnt); // �� ĭ�� ��ǥ�� �� ����ü, ä�� ĭ�� �ε���, �� ĭ�� ����

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