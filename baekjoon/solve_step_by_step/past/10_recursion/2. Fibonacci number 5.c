#include <stdio.h>

int fib(int n)
{
    int prev = 0, curr = 1, temp;

    if (n == 0)
        return 0;

    for (int i = 1; i < n; i++)
    {
        temp = curr;
        curr = prev + curr;
        prev = temp;
    }

    return curr;
}

int main()
{
    int num;
    scanf("%d", &num);

    printf("%d", fib(num));
}