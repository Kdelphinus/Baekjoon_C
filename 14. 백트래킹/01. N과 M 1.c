#include <stdio.h>

int num, count;
int result[1000];
int checklist[1000];

void DFS(int L)
{
    int i;

    if (L == count) // 구하고자 하는 길이와 같을 때
    {
        for (i = 0; i < count; i++)
            printf("%d ", result[i]);
        printf("\n");
    }
    else
    {
        for (i = 1; i <= num; i++) // 1부터 num까지 수열을 구함
        {
            if (checklist[i] == 0) // 아직 숫자가 들어가지 않았다면
            {
                result[L] = i;    // 결과에 그 숫자를 추가하고
                checklist[i] = 1; // 숫자가 들어갔다고 표시
                DFS(L + 1);       // 다음 숫자를 찾아봄
                checklist[i] = 0; // 찾고 돌아오면 그 숫자를 빼줌
            }
        }
    }
}

int main(void)
{
    scanf("%d %d", &num, &count);
    DFS(0);
}
