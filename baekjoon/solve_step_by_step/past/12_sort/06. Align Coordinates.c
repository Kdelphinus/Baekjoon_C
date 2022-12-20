#include <stdio.h>
#include <stdlib.h>

typedef struct // 구조체 지정
{
    int x;
    int y;
} point;

point sort[100001]; // 정렬된 함수를 받을 배열

void merge(point *arr, int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i].x < arr[j].x)
            sort[k++] = arr[i++];
        else if (arr[i].x > arr[j].x)
            sort[k++] = arr[j++];
        else
        {
            if (arr[i].y < arr[j].y)
                sort[k++] = arr[i++];
            else if (arr[i].y > arr[j].y)
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

    if (j <= high)
    {
        while (j <= high)
            sort[k++] = arr[j++];
    }

    for (k = low; k <= high; k++)
        arr[k] = sort[k];
}

void mergeSort(point *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    point *arr = (point *)malloc(sizeof(point) * num); // 포인터에 대한 실체 확보, malloc을 공부해야 함
    for (int i = 0; i < num; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);

    mergeSort(arr, 0, num - 1);

    for (int i = 0; i < num; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);

    return 0;
}

/* 버블정렬은 시간초과
int main()
{
    int num;
    scanf("%d", &num);

    int numbers[num][2], temp[2] = {
                             0,
                         };
    for (int i = 0; i < num; i++)
        scanf("%d %d", &numbers[i][0], &numbers[i][1]);
    printf("\n");

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i != j)
            {
                if (numbers[i][0] < numbers[j][0])
                {
                    temp[0] = numbers[i][0];
                    temp[1] = numbers[i][1];
                    numbers[i][0] = numbers[j][0];
                    numbers[i][1] = numbers[j][1];
                    numbers[j][0] = temp[0];
                    numbers[j][1] = temp[1];
                }

                else if (numbers[i][0] == numbers[j][0])
                {
                    if (numbers[i][1] < numbers[j][1])
                    {
                        temp[1] = numbers[i][1];
                        numbers[i][1] = numbers[j][1];
                        numbers[j][1] = temp[1];
                    }
                }
            }
        }
    }
    for (int i = 0; i < num; i++)
        printf("%d %d\n", numbers[i][0], numbers[i][1]);

    return 0;
}
*/