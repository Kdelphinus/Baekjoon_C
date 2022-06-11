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
    int start, end, sum = 0, min = -1;
    scanf("%d\n%d", &start, &end);

    for (int i = start; i <= end; i++)
    {
        if (isPrime(i))
        {
            sum += i;

            if (min == -1)
                min = i;
        }
    }

    if (sum == 0)
        printf("%d", min);
    else
        printf("%d\n%d", sum, min);

    return 0;
}