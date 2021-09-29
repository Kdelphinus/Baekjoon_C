#include <stdio.h>
#include <stdlib.h>
// 6번을 응용하면 금방 풀 수 있음

typedef struct
{
    int x, y;
} point;

point sort[100001];

void merge(point *arr, int start, int mid, int end)
{
    int i, j, k;
    i = start;
    j = mid + 1;
    k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i].y < arr[j].y)
            sort[k++] = arr[i++];
        else if (arr[i].y > arr[j].y)
            sort[k++] = arr[j++];
        else
        {
            if (arr[i].x < arr[j].x)
                sort[k++] = arr[i++];
            else if (arr[i].x > arr[j].x)
                sort[k++] = arr[j++];
            else
            {
                sort[k++] = arr[i++];
                sort[k++] = arr[j++];
            }
        }
    }

    if (i <= mid)
    {
        while (i <= mid)
            sort[k++] = arr[i++];
    }
    if (j <= end)
    {
        while (k <= end)
            sort[k++] = arr[j++];
    }

    for (k = start; k <= end; k++)
        arr[k] = sort[k];
}

void mergeSort(point *arr, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    point *arr = (point *)malloc(sizeof(point) * num);
    for (int i = 0; i < num; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);

    mergeSort(arr, 0, num - 1);
    // printf("\n");
    for (int i = 0; i < num; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);

    return 0;
}