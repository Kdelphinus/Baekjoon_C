#include <stdio.h>
#include <stdlib.h>

void    quick_sort(int *arr, int left, int right)
{
    int tmp;
    int l = left, r = right;
    int pivot  = arr[(l + r) / 2];

    while (l <= r)
    {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l <= r)
        {
            tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }
    if (left < r)
        quick_sort(arr, left, r);
    if (l < right)
        quick_sort(arr, l, right);
}

int	main(void)
{
	int n;
    int *arr;

    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quick_sort(arr, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
        printf("%d\n", arr[i]);
    return (0);
}