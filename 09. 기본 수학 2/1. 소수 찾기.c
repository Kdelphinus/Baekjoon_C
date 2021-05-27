#include <stdio.h>
#include <stdbool.h> // bool, true, false가 정의던 헤더 파일

bool isPrime(int number)
{
    if (number <= 1)
        return false;
    else if (number <= 3)
        return true;
    else
    {
        int i = 2;

        while (i * i <= number)
        {
            if (number % i == 0)
                return false;
            i++;
        }
        return true;
    }
}

int main()
{
    int n, tem, cnt = 0;
    scanf("%d", &n);

    int num[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    for (int i = 0; i < n; i++)
    {
        if (isPrime(num[i]))
            cnt++;
    }

    printf("%d", cnt);

    return 0;
}