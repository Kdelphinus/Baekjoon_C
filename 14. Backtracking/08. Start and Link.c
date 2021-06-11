#include <stdio.h>

int num, mid, start, link, diff = 1000000, temp;
int stat[20][20];
int team[20];
int result[20];
int checklist[20];

void DFS(int l)
{
    if (l == num / 2)
    {
        mid = num / 2; // 팀을 두 개로 나눔
        for (int i = 0; i < num; i++)
        {
            for (int j = i; j < num; j++)
            {
                if (checklist[i] == 1 && checklist[j] == 1) // start team
                {
                    start += stat[i][j]; // i가 j의 영향을 받음
                    start += stat[j][i]; // j가 i의 영향을 받음
                }
                else if (checklist[i] == 0 && checklist[j] == 0) // link team
                {
                    link += stat[i][j]; // i가 j의 영향을 받음
                    link += stat[j][i]; // j가 i의 영향을 받음
                }
            }
        }

        temp = link - start; // 차이 계산
        if (temp < 0)        // 차이가 음수면 양수로 변환
            temp *= -1;

        if (diff > temp) // 차이가 더 작으면 차이 변경
            diff = temp;

        start = 0;
        link = 0;
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            if (checklist[i] == 0)
            {
                if (l == 0) // 첫 값일 때
                {
                    checklist[i] = 1;
                    result[l] = i;
                    DFS(l + 1);
                    checklist[i] = 0;
                }
                else if (result[l - 1] <= i) // 중복팀 방지
                {
                    checklist[i] = 1;
                    result[l] = i;
                    DFS(l + 1);
                    checklist[i] = 0;
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            scanf("%d", &stat[i][j]);
    }

    DFS(0);
    printf("%d", diff);

    return 0;
}