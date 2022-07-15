/**
 * @file 03. ATM.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 걸리는 시간이 적은 사람부터 뽑는 것이 대기 시간이 가장 적다
 * @date 2021-06-16 21:26:59
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

void merge(int num, int arr[], int start, int mid, int end)
{
    int sort[num];
    int i, j, k;
    i = start;
    j = mid + 1;
    k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
            sort[k++] = arr[i++];
        else if (arr[i] > arr[j])
            sort[k++] = arr[j++];
        else
        {
            sort[k++] = arr[i++];
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

    for (int k = start; k <= end; k++)
        arr[k] = sort[k];
}

void mergeSort(int num, int arr[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergeSort(num, arr, start, mid);
        mergeSort(num, arr, mid + 1, end);
        merge(num, arr, start, mid, end);
    }
}

int ATM(int num, int wait[])
{
    int cnt = 0;
    mergeSort(num, wait, 0, num - 1); // 오름차순 정렬

    for (int i = 0; i < num; i++)
    {
        cnt += wait[i]; // 현재 사람이 돈을 뽑는 시간을 더하고
        for (int j = 0; j < i; j++)
            cnt += wait[j]; // 대기했던 시간들도 더한다
    }

    return cnt;
}

int main()
{
    int num;
    scanf("%d", &num);

    int wait[num];
    for (int i = 0; i < num; i++)
        scanf("%d", &wait[i]);

    printf("%d", ATM(num, wait));

    return 0;
}