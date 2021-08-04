#include <stdio.h>

long long len, hist[100001], stack[100001];

void push(long long num)
{
    stack[len++] = num;
}

long long max(long long a, long long b)
{
    if (a > b)
        return a;
    return b;
}

long long largest_rectangle(int num)
{
    long long max_area = num;

    return max_area;
}

int main()
{
    while (1)
    {
        int num;
        scanf("%d", &num);

        if (num == 0)
            break;

        for (int i = 0; i < num; i++)
            scanf("%d", &hist[i]);

        printf("%lld\n", largest_rectangle(num));

        len = 0;
        for (int i = 0; i < num; i++)
            hist[i] = '\0';
    }
    return 0;
}