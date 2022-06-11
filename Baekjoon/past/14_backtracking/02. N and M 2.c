#include <stdio.h>

int num, count;
int result[9];
int checklist[9];

void DFS(int L)
{
    if (L == count) // 수열을 다 채웠을 때
    {
        for (int i = 0; i < count; i++)
            printf("%d ", result[i]);
        printf("\n");
    }

    else
    {
        for (int i = 1; i <= num; i++) // 1부터 num까지
        {
            if (checklist[i] == 0) // 아직 쓰지 않은 숫자일 때
            {
                if (L == 0) // 첫 번째 숫자면 추가
                {
                    result[L] = i;
                    DFS(L + 1);
                }
                else if (result[L - 1] <= i) // 두 번째 숫자부턴 이전 숫자보다 같거나 클때만 추가
                {
                    result[L] = i;
                    DFS(L + 1);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &num, &count);
    DFS(0);
    return 0;
}