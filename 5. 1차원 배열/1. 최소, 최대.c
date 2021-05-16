#include <stdio.h>

int main()
{
    int n, i, max, min;
    scanf("%d", &n);

    int num[n];
    int *num_ptr;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    num_ptr = &num[0];

    max = *num_ptr;
    min = *num_ptr;

    for (i = 1; i < n; i++)
    {
        if (*(num_ptr + i) > max)
        {
            max = *(num_ptr + i);
        }
        else if (*(num_ptr + i) < min)
        {
            min = *(num_ptr + i);
        }
    }

    printf("%d %d", min, max);
    return 0;
}