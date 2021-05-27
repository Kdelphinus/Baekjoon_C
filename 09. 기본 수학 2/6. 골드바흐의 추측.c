#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number)
{
    if (number <= 1)
        return false;

    int i = 2;

    while (i * i <= number)
    {
        if (number % i == 0)
            return false;
        i++;
    }
    return true;
}

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int num;
        scanf("%d", &num);

        for (int j = num / 2; j > 1; j--)
        {
            if (isPrime(j) == true && isPrime(num - j) == true)
            {
                printf("%d %d\n", j, num - j);
                break;
            }
        }
    }
    return 0;
}