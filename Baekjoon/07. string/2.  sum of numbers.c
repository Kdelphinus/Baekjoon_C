#include <stdio.h>

int main()
{
    char num[101];
    int n, i, value;
    scanf("%d", &n);
    scanf("%s", &num);

    value = 0;

    for (i = 0; i < n; i++)
    {
        value += num[i] % 48; // 아스키 코드의 '0'이 48임
    }

    // 같은 방식이나 아스키 코드를 몰라도 풀 수 있음
    // for (i = 0; i<n; i++)
    // {
    //     sum += num[i] - '0';
    // }
    // printf("%d", sum);

    printf("%d\n", value);

    return 0;
}