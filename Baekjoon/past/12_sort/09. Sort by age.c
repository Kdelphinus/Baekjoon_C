#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int age;        //나이
    char name[101]; // 이름
    int order;      //가입순서
} point;

point sort[100001];

void merge(point *info, int start, int mid, int end)
{
    int i, j, k;
    i = start;
    j = mid + 1;
    k = start;

    while (i <= mid && j <= end)
    {
        if (info[i].age < info[j].age) // 나이순 정렬
            sort[k++] = info[i++];
        else if (info[i].age > info[j].age)
            sort[k++] = info[j++];
        else
        {
            if (info[i].order < info[j].order) // 가입순서
                sort[k++] = info[i++];
            else
                sort[k++] = info[j++];
        }
    }

    if (i <= mid)
    {
        while (i <= mid)
            sort[k++] = info[i++];
    }
    if (j <= end)
    {
        while (j <= end)
            sort[k++] = info[j++];
    }

    for (k = start; k <= end; k++)
        info[k] = sort[k];
}

void mergeSort(point *info, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(info, start, mid);
        mergeSort(info, mid + 1, end);
        merge(info, start, mid, end);
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    point *info = (point *)malloc(sizeof(point) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %s", &info[i].age, &info[i].name);
        info[i].order = i;
    }

    mergeSort(info, 0, num - 1);
    // printf("\n"); //출력 보기 쉽게하려고
    for (int i = 0; i < num; i++)
        printf("%d %s\n", info[i].age, info[i].name);

    return 0;
}