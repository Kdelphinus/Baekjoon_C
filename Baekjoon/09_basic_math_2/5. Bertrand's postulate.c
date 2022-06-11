#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    else if (num <= 3)
        return true;
    else
    {
        int i = 2;

        while (i * i <= num)
        {
            if (num % i == 0)
                return false;
            i++;
        }
        return true;
    }
}

int main()
{
    int n = 1;

    while (1)
    {
        int cnt = 0;
        scanf("%d", &n);

        if (n == 0)
            break;

        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (isPrime(i))
                cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}