#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char word[50];
    int len;
} point;

point sort[20001];

void merge(point *arr, int start, int mid, int end)
{
    int i, j, k, index = 0;
    i = start;
    j = mid + 1;
    k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i].len < arr[j].len) // 길이로 먼저 정렬
            sort[k++] = arr[i++];
        else if (arr[i].len > arr[j].len)
            sort[k++] = arr[j++];
        else // 길이가 같을 때
        {
            if (strcmp(arr[i].word, arr[j].word) < 0) // 앞 단어가 더 빠를 때
                sort[k++] = arr[i++];
            else // 같거나 뒷 단어가 더 빠를 때
                sort[k++] = arr[j++];
        }
    }

    if (i <= mid)
    {
        while (i <= mid)
            sort[k++] = arr[i++];
    }
    if (j <= end)
    {
        while (j <= end)
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
    {
        scanf("%s", &arr[i].word);
        arr[i].len = strlen(arr[i].word);
    }

    mergeSort(arr, 0, num - 1);

    printf("%s\n", arr[0].word);
    for (int i = 1; i < num; i++)
    {
        if (strcmp(arr[i].word, arr[i - 1].word) != 0) // 앞 단어와 같지 않다면
            printf("%s\n", arr[i].word);
    }
    return 0;
}