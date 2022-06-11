#include <stdio.h>

int num, count;
int result[8]; // 중복 가능이기에 checklist가 필요없음

void DFS(int L)
{
    if (count == L)
    {
        for (int i = 0; i < count; i++)
            printf("%d ", result[i]);
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= num; i++)
        {
            result[L] = i;
            DFS(L + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &num, &count);
    DFS(0);

    return 0;
}