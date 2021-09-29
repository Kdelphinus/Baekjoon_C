#include <stdio.h>

int main()
{
    int num[9];
    int max, index, i;
    for (i = 0; i < 9; i++)
    {
        scanf("%d\n", &num[i]);
    }

    int *num_ptr;
    num_ptr = &num[0];
    max = *num_ptr;
    index = 1;

    for (i = 1; i < 9; i++)
    {
        if (max < *(num_ptr + i))
        {
            max = *(num_ptr + i);
            index = i + 1;
        }
    }
    printf("%d\n", max);
    printf("%d", index);

    return 0;
}