#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int number; // ����
    int order;  // ��ǥ ������ ����
    int index;  // ���� ��ġ
} point;

point sort[1000001];

void merge(point *arr, int start, int mid, int end, int standard)
{
    int i, j, k;
    i = start;
    j = mid + 1;
    k = start;

    if (standard == 0) // ���� ũ��� ����
    {
        while (i <= mid && j <= end)
        {
            if (arr[i].number < arr[j].number)
                sort[k++] = arr[i++];
            else if (arr[i].number > arr[j].number)
                sort[k++] = arr[j++];
            else
            {
                sort[k++] = arr[i++];
            }
        }

        if (i <= mid)
        {
            while (i <= mid)
                sort[k++] = arr[i++];
        }
        if (j <= end)
            while (j <= end)
                sort[k++] = arr[j++];

        for (k = start; k <= end; k++)
            arr[k] = sort[k];
    }

    else if (standard == 1) // �ε��� ������ ����
    {
        while (i <= mid && j <= end)
        {
            if (arr[i].index < arr[j].index)
                sort[k++] = arr[i++];
            else if (arr[i].index > arr[j].index)
                sort[k++] = arr[j++];
            else
            {
                sort[k++] = arr[i++];
            }
        }

        if (i <= mid)
        {
            while (i <= mid)
                sort[k++] = arr[i++];
        }
        if (j <= end)
            while (j <= end)
                sort[k++] = arr[j++];

        for (k = start; k <= end; k++)
            arr[k] = sort[k];
    }
}

void mergeSort(point *arr, int start, int end, int standard)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid, standard);
        mergeSort(arr, mid + 1, end, standard);
        merge(arr, start, mid, end, standard);
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    point *arr = (point *)malloc(sizeof(point) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i].number);
        arr[i].index = i;
    }

    mergeSort(arr, 0, num - 1, 0); // 0�� ���� ũ���� ����
    for (int i = 0; i < num; i++)
    {
        if (i == 0) // ���� �� ���ڴ� ���� ���� ����
            arr[i].order = 0;
        else if (arr[i].number == arr[i - 1].number) // �� ���ڿ� ���ٸ�
            arr[i].order = arr[i - 1].order;
        else // �� ���ں��� ũ�ٸ�
            arr[i].order = arr[i - 1].order + 1;
    }
    mergeSort(arr, 0, num - 1, 1); // 1�� ���� ������� �ٽ� ����

    for (int i = 0; i < num; i++)
        printf("%d ", arr[i].order);
    return 0;
}