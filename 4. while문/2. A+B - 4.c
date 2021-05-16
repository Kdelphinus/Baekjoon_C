#include <stdio.h>

int main()
{
    int a, b;

    while (scanf("%d %d", &a, &b) != EOF)
    {
        printf("%d\n", a + b);
    }
    return 0;
}

// EOF(end of file): 파일의 끝을 표현하기 위해 -1로 정의된 상수
// 즉, scanf("%d %d", &a, &b) != EOF은 파일이 끝날 때까지 반복문을 진행한다는 의미