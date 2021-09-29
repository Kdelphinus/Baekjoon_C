#include <stdio.h>

int main()
{

    int n, value, num, count = 0;
    scanf("%d", &n);
    value = n;

    while (1)
    {
        // 두 자리의 숫자를 더한 값
        num = n / 10 + n % 10;

        // num이 두 자리 수이면 일의 자리만 가져간다
        if (num >= 10)
        {
            num %= 10;
        }

        // 새로운 수를 만듬
        n = ((n % 10) * 10) + num;

        // 횟수를 더함
        count++;

        // 처음 값과 일치하면 횟수를 출력하고 종료
        if (value == n)
        {
            printf("%d", count);
            break;
        }
    }

    return 0;
}